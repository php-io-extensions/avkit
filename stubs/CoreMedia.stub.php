<?php

/** @generate-class-entries */

/**
 * @var int
 * @cvalue kCMTimeFlags_Valid
 */
const kCMTimeFlags_Valid = UNKNOWN;

/**
 * @var int
 * @cvalue kCMTimeFlags_HasBeenRounded
 */
const kCMTimeFlags_HasBeenRounded = UNKNOWN;

/**
 * @var int
 * @cvalue kCMTimeFlags_PositiveInfinity
 */
const kCMTimeFlags_PositiveInfinity = UNKNOWN;

/**
 * @var int
 * @cvalue kCMTimeFlags_NegativeInfinity
 */
const kCMTimeFlags_NegativeInfinity = UNKNOWN;

/**
 * @var int
 * @cvalue kCMTimeFlags_Indefinite
 */
const kCMTimeFlags_Indefinite = UNKNOWN;

/**
 * @var int
 * @cvalue kCMMediaType_Video
 */
const kCMMediaType_Video = UNKNOWN;

/**
 * @var int
 * @cvalue kCMMediaType_Audio
 */
const kCMMediaType_Audio = UNKNOWN;

/** CMTime as a value, field for field. */
final class CMTime
{
    public int $value;

    public int $timescale;

    public int $flags;

    public int $epoch;

    public function __construct(int $value, int $timescale, int $flags, int $epoch) {}
}

/** CMTimeRange as a value, field for field. */
final class CMTimeRange
{
    public CMTime $start;

    public CMTime $duration;

    public function __construct(CMTime $start, CMTime $duration) {}
}

/** CMVideoDimensions as a value, field for field. */
final class CMVideoDimensions
{
    public int $width;

    public int $height;

    public function __construct(int $width, int $height) {}
}

/** AudioStreamBasicDescription as a value, field for field. */
final class AudioStreamBasicDescription
{
    public float $mSampleRate;

    public int $mFormatID;

    public int $mFormatFlags;

    public int $mBytesPerPacket;

    public int $mFramesPerPacket;

    public int $mBytesPerFrame;

    public int $mChannelsPerFrame;

    public int $mBitsPerChannel;

    public int $mReserved;

    public function __construct(float $mSampleRate, int $mFormatID, int $mFormatFlags, int $mBytesPerPacket, int $mFramesPerPacket, int $mBytesPerFrame, int $mChannelsPerFrame, int $mBitsPerChannel, int $mReserved) {}
}

/**
 * @not-serializable
 */
final class CMSampleBuffer extends CFType
{
}

/**
 * @not-serializable
 */
final class CMBlockBuffer extends CFType
{
}

/**
 * @not-serializable
 */
class CMFormatDescription extends CFType
{
}

/**
 * @not-serializable
 */
final class CMVideoFormatDescription extends CMFormatDescription
{
}

/**
 * @not-serializable
 */
final class CMAudioFormatDescription extends CMFormatDescription
{
}

function CMTimeMake(int $value, int $timescale): CMTime {}

function CMTimeMakeWithSeconds(float $seconds, int $preferredTimescale): CMTime {}

function CMTimeGetSeconds(CMTime $time): float {}

function CMTimeCompare(CMTime $time1, CMTime $time2): int {}

function CMTimeRangeMake(CMTime $start, CMTime $duration): CMTimeRange {}

function CMTimeRangeGetEnd(CMTimeRange $range): CMTime {}

function CMSampleBufferGetImageBuffer(CMSampleBuffer $sbuf): ?CVImageBuffer {}

function CMSampleBufferGetDataBuffer(CMSampleBuffer $sbuf): ?CMBlockBuffer {}

function CMSampleBufferGetFormatDescription(CMSampleBuffer $sbuf): ?CMFormatDescription {}

function CMSampleBufferGetPresentationTimeStamp(CMSampleBuffer $sbuf): CMTime {}

function CMSampleBufferGetDuration(CMSampleBuffer $sbuf): CMTime {}

function CMSampleBufferGetNumSamples(CMSampleBuffer $sbuf): int {}

function CMBlockBufferGetDataLength(CMBlockBuffer $theBuffer): int {}

/** $destination becomes the copied bytes when the status is 0. */
function CMBlockBufferCopyDataBytes(CMBlockBuffer $theSourceBuffer, int $offsetToData, int $dataLength, string &$destination): int {}

function CMFormatDescriptionGetMediaType(CMFormatDescription $desc): int {}

function CMVideoFormatDescriptionGetDimensions(CMVideoFormatDescription $videoDesc): CMVideoDimensions {}

function CMAudioFormatDescriptionGetStreamBasicDescription(CMAudioFormatDescription $desc): ?AudioStreamBasicDescription {}
