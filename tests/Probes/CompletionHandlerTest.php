<?php

declare(strict_types=1);

// Sites avaudioplayernode-schedule-buffer-completion-handler and
// avaudioplayernode-schedule-buffer-at-time-completion-handler (outcome 3): AVAudioEngine calls a
// scheduleBuffer completion handler on its own render thread, where PHP cannot run.

beforeEach(function (): void {
    requireProbeBuild();
    if (! PHP_ZTS) {
        $this->markTestSkipped('needs a ZTS PHP: there a PHP call on a thread PHP does not own faults at once');
    }
});

/** A started engine playing a silent buffer scheduled by $schedule, the mixer all the way down. */
function completionProbe(string $schedule): string
{
    return <<<PHP
    \$engine = AVAudioEngine::init();
    \$player = AVAudioPlayerNode::init();
    \$format = AVAudioFormat::initStandardFormatWithSampleRateChannels(48000.0, 2);
    \$engine->mainMixerNode()->setOutputVolume(0.0);
    \$engine->attachNode(\$player);
    \$engine->connectToFormat(\$player, \$engine->mainMixerNode(), \$format);
    \$buffer = AVAudioPCMBuffer::initWithPCMFormatFrameCapacity(\$format, 480);
    \$buffer->setFrameLength(480);
    \$engine->startAndReturnError(\$error);
    \$done = function (): void {
        echo "completion ran\\n";
    };
    {$schedule}
    \$player->play();
    usleep(500_000);
    \$player->stop();
    \$engine->stop();
    PHP;
}

it('refuses a scheduleBuffer:completionHandler: closure, which crashes on the render thread without the refusal', function (): void {
    $code = completionProbe('$player->scheduleBufferCompletionHandler($buffer, $done);');

    $kept = probeRun($code, null);
    $off = probeRun($code, 'avaudioplayernode-schedule-buffer-completion-handler');

    expect($kept['signal'])->toBeNull()
        ->and($kept['stdout'])->toContain('REFUSED ValueError')
        ->and($kept['stdout'])->toContain('SURVIVED')
        ->and($off['signal'])->toBeIn([PROBE_SIGSEGV, PROBE_SIGBUS]);
});

it('refuses a scheduleBuffer:atTime:options:completionHandler: closure, which crashes on the render thread without the refusal', function (): void {
    $code = completionProbe('$player->scheduleBufferAtTimeOptionsCompletionHandler($buffer, null, 0, $done);');

    $kept = probeRun($code, null);
    $off = probeRun($code, 'avaudioplayernode-schedule-buffer-at-time-completion-handler');

    expect($kept['signal'])->toBeNull()
        ->and($kept['stdout'])->toContain('REFUSED ValueError')
        ->and($kept['stdout'])->toContain('SURVIVED')
        ->and($off['signal'])->toBeIn([PROBE_SIGSEGV, PROBE_SIGBUS]);
});
