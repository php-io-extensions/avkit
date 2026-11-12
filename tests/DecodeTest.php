<?php

declare(strict_types=1);

it('decodes every frame to 64×48 BGRA pixels in presentation order', function (): void {
    [$reader, $output] = readerFor(AVMediaTypeVideo, BGRA_SETTINGS);
    $reader->startReading();
    $frames = 0;
    $last = -1.0;

    while (($sample = $output->copyNextSampleBuffer()) !== null) {
        $pixels = CMSampleBufferGetImageBuffer($sample);
        expect($pixels)->toBeInstanceOf(CVPixelBuffer::class)
            ->and(CVPixelBufferLockBaseAddress($pixels, kCVPixelBufferLock_ReadOnly))->toBe(0)
            ->and(CVPixelBufferGetBaseAddress($pixels))->toBeGreaterThan(0)
            ->and(CVPixelBufferGetWidth($pixels))->toBe(64)
            ->and(CVPixelBufferGetHeight($pixels))->toBe(48)
            ->and(CVPixelBufferGetBytesPerRow($pixels))->toBe(256)
            ->and(CVPixelBufferGetPixelFormatType($pixels))->toBe(kCVPixelFormatType_32BGRA)
            ->and(CVPixelBufferIsPlanar($pixels))->toBeFalse()
            ->and(CVPixelBufferGetDataSize($pixels))->toBeGreaterThanOrEqual(256 * 48)
            ->and(CVPixelBufferUnlockBaseAddress($pixels, kCVPixelBufferLock_ReadOnly))->toBe(0)
            ->and(CMSampleBufferGetNumSamples($sample))->toBe(1)
            ->and(CMSampleBufferGetDataBuffer($sample))->toBeNull();
        $pts = CMTimeGetSeconds(CMSampleBufferGetPresentationTimeStamp($sample));
        if ($frames > 0) {
            expect(round($pts - $last, 2))->toBe(0.1);
        }
        $last = $pts;
        $frames++;
    }

    expect($frames)->toBe(10);
});

it('decodes the audio track to one second of 16-bit mono PCM', function (): void {
    [$reader, $output] = readerFor(AVMediaTypeAudio, pcm16Settings());
    $reader->startReading();
    $samples = 0;
    $pcm = '';

    while (($sample = $output->copyNextSampleBuffer()) !== null) {
        $block = CMSampleBufferGetDataBuffer($sample);
        $length = CMBlockBufferGetDataLength($block);
        $bytes = '';
        expect(CMBlockBufferCopyDataBytes($block, 0, $length, $bytes))->toBe(0)
            ->and(strlen($bytes))->toBe($length)
            ->and(CMSampleBufferGetImageBuffer($sample))->toBeNull();
        $asbd = CMAudioFormatDescriptionGetStreamBasicDescription(CMSampleBufferGetFormatDescription($sample));
        expect($asbd->mSampleRate)->toBe(44100.0)
            ->and($asbd->mBitsPerChannel)->toBe(16)
            ->and($asbd->mChannelsPerFrame)->toBe(1)
            ->and($asbd->mFormatID)->toBe(kAudioFormatLinearPCM);
        $samples += CMSampleBufferGetNumSamples($sample);
        $pcm .= $bytes;
    }

    expect($samples)->toBe(44100)
        ->and(strlen($pcm))->toBe(88200)
        ->and(max(array_map('abs', unpack('s*', $pcm))))->toBeGreaterThan(1000);
});

it('reads video and audio in turn from one reader, as the README does', function (): void {
    $asset = fixtureAsset();
    $reader = AVAssetReader::assetReaderWithAssetError($asset, $error);
    $video = AVAssetReaderTrackOutput::assetReaderTrackOutputWithTrackOutputSettings($asset->tracksWithMediaType(AVMediaTypeVideo)[0], BGRA_SETTINGS);
    $audio = AVAssetReaderTrackOutput::assetReaderTrackOutputWithTrackOutputSettings($asset->tracksWithMediaType(AVMediaTypeAudio)[0], pcm16Settings());
    $reader->addOutput($video);
    $reader->addOutput($audio);
    $reader->startReading();
    $frames = 0;
    $bytes = 0;

    do {
        if (($frame = $video->copyNextSampleBuffer()) !== null) {
            $frames++;
        }
        if (($chunk = $audio->copyNextSampleBuffer()) !== null) {
            $block = CMSampleBufferGetDataBuffer($chunk);
            CMBlockBufferCopyDataBytes($block, 0, CMBlockBufferGetDataLength($block), $pcm);
            $bytes += strlen($pcm);
        }
    } while ($frame !== null || $chunk !== null);

    expect($frames)->toBe(10)
        ->and($bytes)->toBe(88200)
        ->and($reader->status())->toBe(AVAssetReaderStatus::COMPLETED);
});

it('leaves the destination alone when the block buffer refuses the range', function (): void {
    [$reader, $output] = readerFor(AVMediaTypeAudio, pcm16Settings());
    $reader->startReading();
    $block = CMSampleBufferGetDataBuffer($output->copyNextSampleBuffer());
    $bytes = 'untouched';

    expect(CMBlockBufferCopyDataBytes($block, 0, CMBlockBufferGetDataLength($block) + 1, $bytes))->not->toBe(0)
        ->and($bytes)->toBe('untouched');
});

it('keeps a sample buffer\'s pixels after its reader and output are gone', function (): void {
    [$reader, $output] = readerFor(AVMediaTypeVideo, BGRA_SETTINGS);
    $reader->startReading();
    $sample = $output->copyNextSampleBuffer();
    unset($reader, $output);
    gc_collect_cycles();

    expect(CVPixelBufferGetWidth(CMSampleBufferGetImageBuffer($sample)))->toBe(64)
        ->and(CMSampleBufferGetImageBuffer($sample))->toBe(CMSampleBufferGetImageBuffer($sample));
});
