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

const PROBE_SIGSEGV = 11;

const PROBE_SIGBUS = 10;

function requireProbeBuild(): void
{
    if (! defined('AVKIT_PROBES')) {
        test()->markTestSkipped('ext-avkit is not a probe build (AVKIT_CONFIGURE=--enable-avkit-probes ./install-macos.sh): AVKIT_PROBES is undefined');
    }
}

/** An extension's .so: env AVKIT_PROBE_<NAME>, else the loaded PHP's extension_dir. */
function probeExtension(string $name): string
{
    $given = getenv('AVKIT_PROBE_'.strtoupper($name));

    return is_string($given) && $given !== '' ? $given : ini_get('extension_dir').'/'.$name.'.so';
}

/**
 * Runs $code in a child of this PHP with only appkit and the probe build of avkit loaded.
 * $siteOff names the kept site AVKIT_PROBE_OFF turns off; null keeps every site.
 *
 * @return array{signal: ?int, exit: ?int, stdout: string, stderr: string}
 */
function probeRun(string $code, ?string $siteOff): array
{
    $script = tempnam(sys_get_temp_dir(), 'avkit-probe').'.php';
    $out = tempnam(sys_get_temp_dir(), 'avkit-probe-out');
    $err = tempnam(sys_get_temp_dir(), 'avkit-probe-err');
    file_put_contents($script, "<?php\ndeclare(strict_types=1);\ntry {\n".$code
        ."\n} catch (Throwable \$t) {\n    echo 'REFUSED ', get_class(\$t), ': ', \$t->getMessage(), \"\\n\";\n}\necho \"SURVIVED\\n\";\n");

    $env = getenv();
    unset($env['AVKIT_PROBE_OFF']);
    $env['XDEBUG_MODE'] = 'off';
    if ($siteOff !== null) {
        $env['AVKIT_PROBE_OFF'] = $siteOff;
    }
    $command = [PHP_BINARY, '-n', '-d', 'memory_limit=128M', '-d', 'extension='.probeExtension('appkit'), '-d', 'extension='.probeExtension('avkit'), $script];
    $process = proc_open($command, [0 => ['file', '/dev/null', 'r'], 1 => ['file', $out, 'w'], 2 => ['file', $err, 'w']], $pipes, null, $env);
    $deadline = microtime(true) + 30.0;
    do {
        $status = proc_get_status($process);
        if ($status['running'] && microtime(true) > $deadline) {
            proc_terminate($process, 9);
        }
        if ($status['running']) {
            usleep(20_000);
        }
    } while ($status['running']);
    proc_close($process);

    $result = [
        'signal' => $status['signaled'] ? $status['termsig'] : null,
        'exit' => $status['signaled'] ? null : $status['exitcode'],
        'stdout' => (string) file_get_contents($out),
        'stderr' => (string) file_get_contents($err),
    ];
    @unlink($script);
    @unlink($out);
    @unlink($err);

    return $result;
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
