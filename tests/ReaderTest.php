<?php

declare(strict_types=1);

it('reads every video frame of the fixture, then null', function (): void {
    [$reader, $output] = readerFor(AVMediaTypeVideo, BGRA_SETTINGS);

    expect($reader->status())->toBe(AVAssetReaderStatus::UNKNOWN)
        ->and($reader->startReading())->toBeTrue()
        ->and($reader->status())->toBe(AVAssetReaderStatus::READING);
    $frames = 0;
    while ($output->copyNextSampleBuffer() instanceof CMSampleBuffer) {
        $frames++;
    }

    expect($frames)->toBe(10)
        ->and($reader->status())->toBe(AVAssetReaderStatus::COMPLETED)
        ->and($reader->error())->toBeNull()
        ->and($output->copyNextSampleBuffer())->toBeNull();
});

it('hands out nothing once cancelled', function (): void {
    [$reader, $output] = readerFor(AVMediaTypeAudio, pcm16Settings());
    $reader->startReading();
    $reader->cancelReading();

    expect($reader->status())->toBe(AVAssetReaderStatus::CANCELLED)
        ->and($output->copyNextSampleBuffer())->toBeNull();
});

it('reads only the time range it was given', function (): void {
    [$reader, $output] = readerFor(AVMediaTypeVideo, BGRA_SETTINGS);
    $reader->setTimeRange(CMTimeRangeMake(CMTimeMake(0, 10), CMTimeMake(5, 10)));
    $reader->startReading();
    $frames = 0;
    while ($output->copyNextSampleBuffer() !== null) {
        $frames++;
    }

    expect(CMTimeGetSeconds($reader->timeRange()->duration))->toBe(0.5)
        ->and($frames)->toBeLessThan(10)
        ->and($frames)->toBeGreaterThan(0);
});

it('gives no reader and the NSError for a missing or non-media file', function (): void {
    $junk = sys_get_temp_dir().'/avkit-junk-'.getmypid().'.mp4';
    file_put_contents($junk, "not media\n");

    $missing = AVAssetReader::assetReaderWithAssetError(AVURLAsset::URLAssetWithURLOptions(NSURL::fileURLWithPath('/nope/clip.mp4'), null), $missingError);
    $notMedia = AVAssetReader::assetReaderWithAssetError(AVURLAsset::URLAssetWithURLOptions(NSURL::fileURLWithPath($junk), null), $notMediaError);
    unlink($junk);

    expect($missing)->toBeNull()
        ->and($missingError)->toBeInstanceOf(NSError::class)
        ->and($missingError->code())->toBe(-11800)
        ->and($notMedia)->toBeNull()
        ->and($notMediaError->code())->toBe(-11829);
});

it('copies sample data unless told not to', function (): void {
    [, $output] = readerFor(AVMediaTypeVideo, BGRA_SETTINGS);

    expect($output->alwaysCopiesSampleData())->toBeTrue();
    $output->setAlwaysCopiesSampleData(false);
    expect($output->alwaysCopiesSampleData())->toBeFalse()
        ->and($output->track()->mediaType())->toBe(AVMediaTypeVideo)
        ->and($output->mediaType())->toBe(AVMediaTypeVideo);
});
