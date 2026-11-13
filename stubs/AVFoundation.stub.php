<?php

/** @generate-class-entries */

/**
 * @var string
 * @cvalue appkit_cfstring_constant((CFStringRef) AVPlayerItemDidPlayToEndTimeNotification)
 */
const AVPlayerItemDidPlayToEndTimeNotification = UNKNOWN;

/**
 * @var string
 * @cvalue appkit_cfstring_constant((CFStringRef) AVMediaTypeVideo)
 */
const AVMediaTypeVideo = UNKNOWN;

/**
 * @var string
 * @cvalue appkit_cfstring_constant((CFStringRef) AVMediaTypeAudio)
 */
const AVMediaTypeAudio = UNKNOWN;

/**
 * @var string
 * @cvalue appkit_cfstring_constant((CFStringRef) AVFormatIDKey)
 */
const AVFormatIDKey = UNKNOWN;

/**
 * @var string
 * @cvalue appkit_cfstring_constant((CFStringRef) AVSampleRateKey)
 */
const AVSampleRateKey = UNKNOWN;

/**
 * @var string
 * @cvalue appkit_cfstring_constant((CFStringRef) AVNumberOfChannelsKey)
 */
const AVNumberOfChannelsKey = UNKNOWN;

/**
 * @var string
 * @cvalue appkit_cfstring_constant((CFStringRef) AVLinearPCMBitDepthKey)
 */
const AVLinearPCMBitDepthKey = UNKNOWN;

/**
 * @var string
 * @cvalue appkit_cfstring_constant((CFStringRef) AVLinearPCMIsFloatKey)
 */
const AVLinearPCMIsFloatKey = UNKNOWN;

/**
 * @var string
 * @cvalue appkit_cfstring_constant((CFStringRef) AVLinearPCMIsBigEndianKey)
 */
const AVLinearPCMIsBigEndianKey = UNKNOWN;

/**
 * @var string
 * @cvalue appkit_cfstring_constant((CFStringRef) AVLinearPCMIsNonInterleaved)
 */
const AVLinearPCMIsNonInterleaved = UNKNOWN;

/**
 * @var int
 * @cvalue kAudioFormatLinearPCM
 */
const kAudioFormatLinearPCM = UNKNOWN;

/**
 * @var int
 * @cvalue kAudioFormatFlagIsFloat
 */
const kAudioFormatFlagIsFloat = UNKNOWN;

/**
 * @var int
 * @cvalue kAudioFormatFlagIsSignedInteger
 */
const kAudioFormatFlagIsSignedInteger = UNKNOWN;

/**
 * @var int
 * @cvalue kAudioFormatFlagIsPacked
 */
const kAudioFormatFlagIsPacked = UNKNOWN;

/**
 * @var int
 * @cvalue kAudioFormatFlagIsNonInterleaved
 */
const kAudioFormatFlagIsNonInterleaved = UNKNOWN;

/**
 * @not-serializable
 */
class AVAsset extends NSObject
{
    public function duration(): CMTime {}

    /** @return AVAssetTrack[] */
    public function tracks(): array {}

    /** @return AVAssetTrack[] */
    public function tracksWithMediaType(string $mediaType): array {}
}

/**
 * @not-serializable
 */
class AVURLAsset extends AVAsset
{
    /** $options is an NSDictionary: string keys, string, int, float, bool or NSObject values. */
    public static function URLAssetWithURLOptions(NSURL $URL, ?array $options): static {}

    public function URL(): NSURL {}
}

/**
 * @not-serializable
 */
class AVAssetTrack extends NSObject
{
    public function trackID(): int {}

    public function mediaType(): string {}

    public function naturalSize(): NSSize {}

    public function nominalFrameRate(): float {}

    public function timeRange(): CMTimeRange {}

    /** @return CMFormatDescription[] */
    public function formatDescriptions(): array {}
}

enum AVAssetReaderStatus: int
{
    case UNKNOWN = 0;
    case READING = 1;
    case COMPLETED = 2;
    case FAILED = 3;
    case CANCELLED = 4;
}

/**
 * @not-serializable
 */
class AVAssetReaderOutput extends NSObject
{
    public function mediaType(): string {}

    public function alwaysCopiesSampleData(): bool {}

    public function setAlwaysCopiesSampleData(bool $alwaysCopiesSampleData): void {}

    public function copyNextSampleBuffer(): ?CMSampleBuffer {}
}

/**
 * @not-serializable
 */
class AVAssetReaderTrackOutput extends AVAssetReaderOutput
{
    /** $outputSettings is an NSDictionary: string keys, string, int, float, bool or NSObject values. */
    public static function assetReaderTrackOutputWithTrackOutputSettings(AVAssetTrack $track, ?array $outputSettings): static {}

    public function track(): AVAssetTrack {}
}

/**
 * @not-serializable
 */
class AVAssetReader extends NSObject
{
    public static function assetReaderWithAssetError(AVAsset $asset, ?NSError &$outError = null): ?static {}

    public function asset(): AVAsset {}

    public function status(): AVAssetReaderStatus {}

    public function error(): ?NSError {}

    public function timeRange(): CMTimeRange {}

    public function setTimeRange(CMTimeRange $timeRange): void {}

    public function canAddOutput(AVAssetReaderOutput $output): bool {}

    public function addOutput(AVAssetReaderOutput $output): void {}

    public function startReading(): bool {}

    public function cancelReading(): void {}
}

enum AVPlayerItemStatus: int
{
    case UNKNOWN = 0;
    case READY_TO_PLAY = 1;
    case FAILED = 2;
}

/**
 * @not-serializable
 */
class AVPlayerItem extends NSObject
{
    public static function playerItemWithURL(NSURL $URL): static {}

    public function status(): AVPlayerItemStatus {}

    public function duration(): CMTime {}

    /** The NSError when status is FAILED. */
    public function error(): ?NSError {}

    /** @return AVPlayerItemOutput[] */
    public function outputs(): array {}

    public function addOutput(AVPlayerItemOutput $output): void {}

    public function removeOutput(AVPlayerItemOutput $output): void {}
}

/**
 * @not-serializable
 */
class AVPlayerItemOutput extends NSObject
{
    public function itemTimeForHostTime(float $hostTimeInSeconds): CMTime {}

    public function itemTimeForMachAbsoluteTime(int $machAbsoluteTime): CMTime {}

    public function suppressesPlayerRendering(): bool {}

    public function setSuppressesPlayerRendering(bool $suppressesPlayerRendering): void {}
}

/**
 * @not-serializable
 */
class AVPlayerItemVideoOutput extends AVPlayerItemOutput
{
    /** $pixelBufferAttributes is an NSDictionary: string keys, string, int, float, bool or NSObject values. */
    public static function initWithPixelBufferAttributes(?array $pixelBufferAttributes): static {}

    /** $outputSettings is an NSDictionary: string keys, string, int, float, bool or NSObject values. */
    public static function initWithOutputSettings(?array $outputSettings): static {}

    public function hasNewPixelBufferForItemTime(CMTime $itemTime): bool {}

    /** $outItemTimeForDisplay becomes the time the returned picture is for. */
    public function copyPixelBufferForItemTimeItemTimeForDisplay(CMTime $itemTime, ?CMTime &$outItemTimeForDisplay = null): ?CVPixelBuffer {}
}

enum AVPlayerTimeControlStatus: int
{
    case PAUSED = 0;
    case WAITING_TO_PLAY_AT_SPECIFIED_RATE = 1;
    case PLAYING = 2;
}

enum AVPlayerActionAtItemEnd: int
{
    case ADVANCE = 0;
    case PAUSE = 1;
    case NONE = 2;
}

/**
 * @not-serializable
 */
class AVPlayer extends NSObject
{
    public static function playerWithPlayerItem(?AVPlayerItem $item): static {}

    public function play(): void {}

    public function pause(): void {}

    public function rate(): float {}

    public function setRate(float $rate): void {}

    public function currentTime(): CMTime {}

    public function seekToTime(CMTime $time): void {}

    public function isMuted(): bool {}

    public function setMuted(bool $muted): void {}

    public function volume(): float {}

    public function setVolume(float $volume): void {}

    public function timeControlStatus(): AVPlayerTimeControlStatus {}

    public function actionAtItemEnd(): AVPlayerActionAtItemEnd {}

    public function setActionAtItemEnd(AVPlayerActionAtItemEnd $actionAtItemEnd): void {}

    public function currentItem(): ?AVPlayerItem {}

    public function replaceCurrentItemWithPlayerItem(?AVPlayerItem $item): void {}
}
