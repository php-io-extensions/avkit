<?php

declare(strict_types=1);

it('registers the AVFAudio classes itself', function (): void {
    foreach ([AVAudioFormat::class, AVAudioBuffer::class, AVAudioPCMBuffer::class, AVAudioTime::class, AVAudioNode::class,
        AVAudioIONode::class, AVAudioOutputNode::class, AVAudioMixerNode::class, AVAudioPlayerNode::class, AVAudioEngine::class,
        AVAudioCommonFormat::class] as $class) {
        expect((new ReflectionClass($class))->getExtensionName())->toBe('avkit');
    }
    expect(is_subclass_of(AVAudioPCMBuffer::class, AVAudioBuffer::class))->toBeTrue()
        ->and(is_subclass_of(AVAudioOutputNode::class, AVAudioIONode::class))->toBeTrue()
        ->and(is_subclass_of(AVAudioPlayerNode::class, AVAudioNode::class))->toBeTrue()
        ->and([AVAudioPlayerNodeBufferLoops, AVAudioPlayerNodeBufferInterrupts, AVAudioPlayerNodeBufferInterruptsAtLoop])->toBe([1, 2, 4]);
});

it('describes formats', function (): void {
    $standard = AVAudioFormat::initStandardFormatWithSampleRateChannels(48000.0, 2);
    expect($standard->isStandard())->toBeTrue()
        ->and($standard->commonFormat())->toBe(AVAudioCommonFormat::PCM_FORMAT_FLOAT32)
        ->and($standard->channelCount())->toBe(2)
        ->and($standard->sampleRate())->toBe(48000.0)
        ->and($standard->isInterleaved())->toBeFalse();

    $int16 = AVAudioFormat::initWithCommonFormatSampleRateChannelsInterleaved(AVAudioCommonFormat::PCM_FORMAT_INT16, 44100.0, 2, true);
    $asbd = $int16->streamDescription();
    expect($int16->isInterleaved())->toBeTrue()
        ->and($asbd)->toBeInstanceOf(AudioStreamBasicDescription::class)
        ->and($asbd->mFormatID)->toBe(kAudioFormatLinearPCM)
        ->and($asbd->mBitsPerChannel)->toBe(16)
        ->and($asbd->mBytesPerFrame)->toBe(4)
        ->and($asbd->mChannelsPerFrame)->toBe(2)
        ->and($asbd->mFormatFlags & kAudioFormatFlagIsSignedInteger)->toBe(kAudioFormatFlagIsSignedInteger);

    $description = $int16->formatDescription();
    $round = AVAudioFormat::initWithCMAudioFormatDescription($description);
    expect($description)->toBeInstanceOf(CMAudioFormatDescription::class)
        ->and(CMAudioFormatDescriptionGetStreamBasicDescription($description)->mSampleRate)->toBe(44100.0)
        ->and($round->commonFormat())->toBe(AVAudioCommonFormat::PCM_FORMAT_INT16)
        ->and($round->channelCount())->toBe(2);
});

it('takes the format of a decoded audio track', function (): void {
    [$reader, $output] = readerFor(AVMediaTypeAudio, pcm16Settings());
    $reader->startReading();
    $sample = $output->copyNextSampleBuffer();
    $format = AVAudioFormat::initWithCMAudioFormatDescription(CMSampleBufferGetFormatDescription($sample));
    $reader->cancelReading();

    expect($format->sampleRate())->toBe(44100.0)
        ->and($format->channelCount())->toBe(1)
        ->and($format->commonFormat())->toBe(AVAudioCommonFormat::PCM_FORMAT_INT16);
});

it('gives a PCM buffer one channel address per channel, or one when interleaved', function (): void {
    $planar = AVAudioPCMBuffer::initWithPCMFormatFrameCapacity(AVAudioFormat::initStandardFormatWithSampleRateChannels(48000.0, 2), 512);
    $channels = $planar->floatChannelData();
    expect($planar->frameCapacity())->toBe(512)
        ->and($planar->frameLength())->toBe(0)
        ->and($planar->stride())->toBe(1)
        ->and($planar->format()->channelCount())->toBe(2)
        ->and($channels)->toHaveCount(2)
        ->and($channels[0])->toBeGreaterThan(0)
        ->and($channels[1])->not->toBe($channels[0])
        ->and($planar->int16ChannelData())->toBeNull()
        ->and($planar->int32ChannelData())->toBeNull();
    $planar->setFrameLength(256);
    expect($planar->frameLength())->toBe(256);

    $interleaved = AVAudioPCMBuffer::initWithPCMFormatFrameCapacity(
        AVAudioFormat::initWithCommonFormatSampleRateChannelsInterleaved(AVAudioCommonFormat::PCM_FORMAT_INT16, 44100.0, 2, true), 64);
    expect($interleaved->int16ChannelData())->toHaveCount(1)
        ->and($interleaved->stride())->toBe(2)
        ->and($interleaved->floatChannelData())->toBeNull();
});

it('converts between host time and seconds and builds sample times', function (): void {
    $host = AVAudioTime::hostTimeForSeconds(2.0);
    $time = AVAudioTime::timeWithSampleTimeAtRate(48000, 48000.0);
    expect(AVAudioTime::secondsForHostTime($host))->toEqualWithDelta(2.0, 1e-6)
        ->and($time->isSampleTimeValid())->toBeTrue()
        ->and($time->isHostTimeValid())->toBeFalse()
        ->and($time->sampleTime())->toBe(48000)
        ->and($time->sampleRate())->toBe(48000.0)
        ->and(AVAudioTime::timeWithHostTime($host)->hostTime())->toBe($host);

    $both = AVAudioTime::timeWithHostTimeSampleTimeAtRate($host, 96000, 48000.0);
    // One second of samples past the anchor extrapolates to one second of host time past it.
    $later = AVAudioTime::timeWithSampleTimeAtRate(144000, 48000.0)->extrapolateTimeFromAnchor($both);
    expect($both->isHostTimeValid() && $both->isSampleTimeValid())->toBeTrue()
        ->and($later)->toBeInstanceOf(AVAudioTime::class)
        ->and(AVAudioTime::secondsForHostTime($later->hostTime()))->toEqualWithDelta(3.0, 1e-6);
});

it('wires a player node to the main mixer, plays silence and advances its clock', function (): void {
    $engine = AVAudioEngine::init();
    $player = AVAudioPlayerNode::init();
    $format = AVAudioFormat::initStandardFormatWithSampleRateChannels(48000.0, 2);
    $mixer = $engine->mainMixerNode();
    // Silence only: the buffer is never written, and the mixer is turned all the way down.
    $mixer->setOutputVolume(0.0);
    $engine->attachNode($player);
    $engine->connectToFormat($player, $mixer, $format);

    expect($player->engine())->toBe($engine)
        ->and($player->numberOfOutputs())->toBe(1)
        ->and($mixer->numberOfInputs())->toBeGreaterThanOrEqual(1)
        ->and($mixer->outputVolume())->toBe(0.0)
        ->and($player->outputFormatForBus(0)->sampleRate())->toBe(48000.0)
        ->and($engine->outputNode())->toBeInstanceOf(AVAudioOutputNode::class)
        ->and($engine->outputNode()->presentationLatency())->toBeGreaterThanOrEqual(0.0)
        ->and($engine->isRunning())->toBeFalse();

    $player->setVolume(0.5);
    $player->setPan(-1.0);
    expect($player->volume())->toBe(0.5)->and($player->pan())->toBe(-1.0);

    $engine->prepare();
    $started = $engine->startAndReturnError($error);
    expect($started)->toBeTrue()->and($error)->toBeNull()->and($engine->isRunning())->toBeTrue();

    $player->play();
    usleep(300_000);
    $node = $player->lastRenderTime();
    $played = $node === null ? null : $player->playerTimeForNodeTime($node);
    expect($player->isPlaying())->toBeTrue()
        ->and($node)->toBeInstanceOf(AVAudioTime::class)
        ->and($played)->toBeInstanceOf(AVAudioTime::class)
        ->and($played->sampleTime())->toBeGreaterThan(0)
        ->and($player->nodeTimeForPlayerTime($played))->toBeInstanceOf(AVAudioTime::class);

    $player->pause();
    expect($player->isPlaying())->toBeFalse();
    $player->stop();
    $engine->stop();
    $engine->disconnectNodeOutput($player);
    $engine->detachNode($player);
    expect($engine->isRunning())->toBeFalse()->and($player->engine())->toBeNull();
});
