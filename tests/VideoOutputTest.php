<?php

declare(strict_types=1);

beforeEach(function (): void {
    $this->app = NSApplication::sharedApplication();
});

it('registers the item output classes itself', function (): void {
    foreach ([AVPlayerItemOutput::class, AVPlayerItemVideoOutput::class] as $class) {
        expect((new ReflectionClass($class))->getExtensionName())->toBe('avkit');
    }
    expect(is_subclass_of(AVPlayerItemVideoOutput::class, AVPlayerItemOutput::class))->toBeTrue();
});

it('sets and reads the player volume', function (): void {
    $player = AVPlayer::playerWithPlayerItem(null);
    expect($player->volume())->toBe(1.0);
    $player->setVolume(0.25);
    expect($player->volume())->toBe(0.25);
});

it('attaches a video output to an item and copies the picture due while the player plays', function (): void {
    $item = AVPlayerItem::playerItemWithURL(NSURL::fileURLWithPath(videoFixture()));
    $output = AVPlayerItemVideoOutput::initWithPixelBufferAttributes(BGRA_SETTINGS);
    $output->setSuppressesPlayerRendering(true);
    expect($output->suppressesPlayerRendering())->toBeTrue()
        ->and($item->outputs())->toBe([]);

    $item->addOutput($output);
    expect($item->outputs())->toHaveCount(1)
        ->and($item->outputs()[0])->toBe($output);

    $player = AVPlayer::playerWithPlayerItem($item);
    $player->setMuted(true);
    $player->play();
    $pixels = null;
    $shown = null;
    $copied = pumpUntil($this->app, function () use ($output, &$pixels, &$shown): bool {
        // hrtime() counts mach_absolute_time in nanoseconds; AVAudioTime turns seconds back into host ticks.
        $time = $output->itemTimeForMachAbsoluteTime(AVAudioTime::hostTimeForSeconds(hrtime(true) / 1e9));
        if (! $output->hasNewPixelBufferForItemTime($time)) {
            return false;
        }
        $pixels = $output->copyPixelBufferForItemTimeItemTimeForDisplay($time, $shown);

        return $pixels !== null;
    }, 5.0);
    $player->pause();

    expect($copied)->toBeTrue()
        ->and($pixels)->toBeInstanceOf(CVPixelBuffer::class)
        ->and(CVPixelBufferGetWidth($pixels))->toBe(64)
        ->and(CVPixelBufferGetHeight($pixels))->toBe(48)
        ->and(CVPixelBufferGetPixelFormatType($pixels))->toBe(kCVPixelFormatType_32BGRA)
        ->and($shown)->toBeInstanceOf(CMTime::class)
        ->and($shown->flags & kCMTimeFlags_Valid)->toBe(kCMTimeFlags_Valid);

    $item->removeOutput($output);
    expect($item->outputs())->toBe([]);
});

it('maps host and mach times onto the item timeline', function (): void {
    $output = AVPlayerItemVideoOutput::initWithOutputSettings(null);
    expect($output->itemTimeForHostTime(0.0))->toBeInstanceOf(CMTime::class)
        ->and($output->itemTimeForMachAbsoluteTime(0))->toBeInstanceOf(CMTime::class);
});
