<?php

declare(strict_types=1);

it('opens the fixture and lists one video and one audio track', function (): void {
    $asset = fixtureAsset();
    $video = $asset->tracksWithMediaType(AVMediaTypeVideo);
    $audio = $asset->tracksWithMediaType(AVMediaTypeAudio);

    expect($asset)->toBeInstanceOf(AVAsset::class)
        ->and(round(CMTimeGetSeconds($asset->duration()), 2))->toBe(1.0)
        ->and($video)->toHaveCount(1)
        ->and($audio)->toHaveCount(1)
        ->and(count($asset->tracks()))->toBe(2)
        ->and($video[0])->toBeInstanceOf(AVAssetTrack::class)
        ->and($video[0]->mediaType())->toBe(AVMediaTypeVideo)
        ->and($audio[0]->mediaType())->toBe(AVMediaTypeAudio);
});

it('reads a video track\'s size, rate, range and format', function (): void {
    $track = fixtureAsset()->tracksWithMediaType(AVMediaTypeVideo)[0];
    $size = $track->naturalSize();
    $formats = $track->formatDescriptions();

    expect([$size->width, $size->height])->toBe([64.0, 48.0])
        ->and($track->nominalFrameRate())->toBe(10.0)
        ->and(round(CMTimeGetSeconds($track->timeRange()->duration), 2))->toBe(1.0)
        ->and($formats)->toHaveCount(1)
        ->and($formats[0])->toBeInstanceOf(CMVideoFormatDescription::class)
        ->and(CMFormatDescriptionGetMediaType($formats[0]))->toBe(kCMMediaType_Video)
        ->and(CMVideoFormatDescriptionGetDimensions($formats[0])->width)->toBe(64)
        ->and(CMVideoFormatDescriptionGetDimensions($formats[0])->height)->toBe(48);
});

it('reads an audio track\'s stream description', function (): void {
    $format = fixtureAsset()->tracksWithMediaType(AVMediaTypeAudio)[0]->formatDescriptions()[0];
    $asbd = CMAudioFormatDescriptionGetStreamBasicDescription($format);

    expect($format)->toBeInstanceOf(CMAudioFormatDescription::class)
        ->and(CMFormatDescriptionGetMediaType($format))->toBe(kCMMediaType_Audio)
        ->and($asbd)->toBeInstanceOf(AudioStreamBasicDescription::class)
        ->and($asbd->mSampleRate)->toBe(44100.0)
        ->and($asbd->mChannelsPerFrame)->toBe(1);
});

it('lists no tracks for a file that is not there', function (): void {
    $asset = AVURLAsset::URLAssetWithURLOptions(NSURL::fileURLWithPath('/nope/clip.mp4'), null);

    expect($asset->tracksWithMediaType(AVMediaTypeVideo))->toBe([]);
});
