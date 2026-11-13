<?php

/** @generate-class-entries */

/**
 * @var int
 * @cvalue AVAudioPlayerNodeBufferLoops
 */
const AVAudioPlayerNodeBufferLoops = UNKNOWN;

/**
 * @var int
 * @cvalue AVAudioPlayerNodeBufferInterrupts
 */
const AVAudioPlayerNodeBufferInterrupts = UNKNOWN;

/**
 * @var int
 * @cvalue AVAudioPlayerNodeBufferInterruptsAtLoop
 */
const AVAudioPlayerNodeBufferInterruptsAtLoop = UNKNOWN;

enum AVAudioCommonFormat: int
{
    case OTHER_FORMAT = 0;
    case PCM_FORMAT_FLOAT32 = 1;
    case PCM_FORMAT_FLOAT64 = 2;
    case PCM_FORMAT_INT16 = 3;
    case PCM_FORMAT_INT32 = 4;
}

/**
 * @not-serializable
 */
class AVAudioFormat extends NSObject
{
    public static function initStandardFormatWithSampleRateChannels(float $sampleRate, int $channels): ?static {}

    public static function initWithCommonFormatSampleRateChannelsInterleaved(AVAudioCommonFormat $format, float $sampleRate, int $channels, bool $interleaved): ?static {}

    public static function initWithCMAudioFormatDescription(CMAudioFormatDescription $formatDescription): static {}

    public function isStandard(): bool {}

    public function commonFormat(): AVAudioCommonFormat {}

    public function channelCount(): int {}

    public function sampleRate(): float {}

    public function isInterleaved(): bool {}

    public function streamDescription(): AudioStreamBasicDescription {}

    public function formatDescription(): CMAudioFormatDescription {}
}

/**
 * @not-serializable
 */
class AVAudioBuffer extends NSObject
{
    public function format(): AVAudioFormat {}
}

/**
 * @not-serializable
 */
class AVAudioPCMBuffer extends AVAudioBuffer
{
    public static function initWithPCMFormatFrameCapacity(AVAudioFormat $format, int $frameCapacity): ?static {}

    public function frameCapacity(): int {}

    public function frameLength(): int {}

    public function setFrameLength(int $frameLength): void {}

    public function stride(): int {}

    /** One address per channel (one in all when interleaved), or null when the format is not 32-bit float. */
    public function floatChannelData(): ?array {}

    /** One address per channel (one in all when interleaved), or null when the format is not 16-bit integer. */
    public function int16ChannelData(): ?array {}

    /** One address per channel (one in all when interleaved), or null when the format is not 32-bit integer. */
    public function int32ChannelData(): ?array {}
}

/**
 * @not-serializable
 */
class AVAudioTime extends NSObject
{
    public static function timeWithHostTime(int $hostTime): static {}

    public static function timeWithSampleTimeAtRate(int $sampleTime, float $sampleRate): static {}

    public static function timeWithHostTimeSampleTimeAtRate(int $hostTime, int $sampleTime, float $sampleRate): static {}

    public static function hostTimeForSeconds(float $seconds): int {}

    public static function secondsForHostTime(int $hostTime): float {}

    public function extrapolateTimeFromAnchor(AVAudioTime $anchorTime): ?AVAudioTime {}

    public function isHostTimeValid(): bool {}

    public function hostTime(): int {}

    public function isSampleTimeValid(): bool {}

    public function sampleTime(): int {}

    public function sampleRate(): float {}
}

/**
 * @not-serializable
 */
class AVAudioNode extends NSObject
{
    public function reset(): void {}

    public function inputFormatForBus(int $bus): AVAudioFormat {}

    public function outputFormatForBus(int $bus): AVAudioFormat {}

    public function engine(): ?AVAudioEngine {}

    public function numberOfInputs(): int {}

    public function numberOfOutputs(): int {}

    public function lastRenderTime(): ?AVAudioTime {}

    public function latency(): float {}

    public function outputPresentationLatency(): float {}
}

/**
 * @not-serializable
 */
class AVAudioIONode extends AVAudioNode
{
    public function presentationLatency(): float {}
}

/**
 * @not-serializable
 */
class AVAudioOutputNode extends AVAudioIONode
{
}

/**
 * @not-serializable
 */
class AVAudioMixerNode extends AVAudioNode
{
    public static function init(): static {}

    public function outputVolume(): float {}

    public function setOutputVolume(float $outputVolume): void {}

    public function nextAvailableInputBus(): int {}

    public function volume(): float {}

    public function setVolume(float $volume): void {}

    public function pan(): float {}

    public function setPan(float $pan): void {}
}

/**
 * @not-serializable
 */
class AVAudioPlayerNode extends AVAudioNode
{
    public static function init(): static {}

    public function stop(): void {}

    public function prepareWithFrameCount(int $frameCount): void {}

    public function play(): void {}

    public function playAtTime(?AVAudioTime $when): void {}

    public function pause(): void {}

    public function nodeTimeForPlayerTime(AVAudioTime $playerTime): ?AVAudioTime {}

    public function playerTimeForNodeTime(AVAudioTime $nodeTime): ?AVAudioTime {}

    public function isPlaying(): bool {}

    public function volume(): float {}

    public function setVolume(float $volume): void {}

    public function pan(): float {}

    public function setPan(float $pan): void {}
}

/**
 * @not-serializable
 */
class AVAudioEngine extends NSObject
{
    public static function init(): static {}

    public function attachNode(AVAudioNode $node): void {}

    public function detachNode(AVAudioNode $node): void {}

    public function connectToFromBusToBusFormat(AVAudioNode $node1, AVAudioNode $node2, int $bus1, int $bus2, ?AVAudioFormat $format): void {}

    public function connectToFormat(AVAudioNode $node1, AVAudioNode $node2, ?AVAudioFormat $format): void {}

    public function disconnectNodeInputBus(AVAudioNode $node, int $bus): void {}

    public function disconnectNodeInput(AVAudioNode $node): void {}

    public function disconnectNodeOutputBus(AVAudioNode $node, int $bus): void {}

    public function disconnectNodeOutput(AVAudioNode $node): void {}

    public function prepare(): void {}

    public function startAndReturnError(?NSError &$outError = null): bool {}

    public function pause(): void {}

    public function reset(): void {}

    public function stop(): void {}

    public function outputNode(): AVAudioOutputNode {}

    public function mainMixerNode(): AVAudioMixerNode {}

    public function isRunning(): bool {}

    public function isAutoShutdownEnabled(): bool {}

    public function setAutoShutdownEnabled(bool $autoShutdownEnabled): void {}
}
