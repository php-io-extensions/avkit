<?php

declare(strict_types=1);

if (! extension_loaded('avkit')) {
    throw new RuntimeException('The avkit extension is not loaded; run ./install-macos.sh');
}

/** The fixture clip (1 s, 64×48 H.264 at 10 fps, 44.1 kHz mono AAC) written to a temporary .mp4, its SHA-256 checked. */
function videoFixture(): string
{
    static $path = null;
    if ($path !== null) {
        return $path;
    }

    $bytes = base64_decode((string) file_get_contents(__DIR__.'/Fixtures/clip.mp4.b64'), true);
    hash('sha256', (string) $bytes) === 'abc0173cd4610dab8234434adaa9c0bfbdfe524281fe692a6b710c94b7019b07'
        || throw new RuntimeException('tests/Fixtures/clip.mp4.b64 does not decode to the fixture');
    $path = sys_get_temp_dir().'/avkit-fixture-'.getmypid().'.mp4';
    file_put_contents($path, $bytes);
    register_shutdown_function(static fn () => @unlink($path));

    return $path;
}

const BGRA_SETTINGS = [kCVPixelBufferPixelFormatTypeKey => kCVPixelFormatType_32BGRA];

/** Reader output settings for 16-bit signed, little-endian, interleaved linear PCM. */
function pcm16Settings(): array
{
    return [AVFormatIDKey => kAudioFormatLinearPCM, AVLinearPCMBitDepthKey => 16, AVLinearPCMIsFloatKey => false,
        AVLinearPCMIsBigEndianKey => false, AVLinearPCMIsNonInterleaved => false];
}

function fixtureAsset(): AVURLAsset
{
    return AVURLAsset::URLAssetWithURLOptions(NSURL::fileURLWithPath(videoFixture()), null);
}

/**
 * A reader over the fixture with one track output for the first track of $mediaType, not started.
 *
 * @return array{AVAssetReader, AVAssetReaderTrackOutput}
 */
function readerFor(string $mediaType, ?array $settings): array
{
    $asset = fixtureAsset();
    $reader = AVAssetReader::assetReaderWithAssetError($asset, $error);
    $output = AVAssetReaderTrackOutput::assetReaderTrackOutputWithTrackOutputSettings($asset->tracksWithMediaType($mediaType)[0], $settings);
    expect($error)->toBeNull()
        ->and($reader->canAddOutput($output))->toBeTrue();
    $reader->addOutput($output);

    return [$reader, $output];
}

/** Runs the main run loop until $until answers true or $seconds pass. */
function pumpUntil(NSApplication $app, callable $until, float $seconds): bool
{
    $limit = microtime(true) + $seconds;
    while (! $until()) {
        if (microtime(true) >= $limit) {
            return false;
        }
        if ($event = $app->nextEventMatchingMaskUntilDateInModeDequeue(NSEventMask::ANY, NSDate::dateWithTimeIntervalSinceNow(0.01), NSDefaultRunLoopMode, true)) {
            $app->sendEvent($event);
        }
    }

    return true;
}
