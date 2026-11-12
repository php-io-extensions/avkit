<?php

/** @generate-class-entries */

/**
 * @var int
 * @cvalue kCVPixelBufferLock_ReadOnly
 */
const kCVPixelBufferLock_ReadOnly = UNKNOWN;

/**
 * @var int
 * @cvalue kCVPixelFormatType_32BGRA
 */
const kCVPixelFormatType_32BGRA = UNKNOWN;

/**
 * @var string
 * @cvalue appkit_cfstring_constant(kCVPixelBufferPixelFormatTypeKey)
 */
const kCVPixelBufferPixelFormatTypeKey = UNKNOWN;

/**
 * @not-serializable
 */
class CVBuffer extends CFType
{
}

/**
 * @not-serializable
 */
class CVImageBuffer extends CVBuffer
{
}

/**
 * @not-serializable
 */
final class CVPixelBuffer extends CVImageBuffer
{
}

function CVPixelBufferLockBaseAddress(CVPixelBuffer $pixelBuffer, int $lockFlags): int {}

function CVPixelBufferUnlockBaseAddress(CVPixelBuffer $pixelBuffer, int $unlockFlags): int {}

/** The address, 0 for NULL. */
function CVPixelBufferGetBaseAddress(CVPixelBuffer $pixelBuffer): int {}

function CVPixelBufferGetBytesPerRow(CVPixelBuffer $pixelBuffer): int {}

function CVPixelBufferGetWidth(CVPixelBuffer $pixelBuffer): int {}

function CVPixelBufferGetHeight(CVPixelBuffer $pixelBuffer): int {}

function CVPixelBufferGetPixelFormatType(CVPixelBuffer $pixelBuffer): int {}

function CVPixelBufferGetDataSize(CVPixelBuffer $pixelBuffer): int {}

function CVPixelBufferIsPlanar(CVPixelBuffer $pixelBuffer): bool {}

function CVPixelBufferGetPlaneCount(CVPixelBuffer $pixelBuffer): int {}

/** The address, 0 for NULL. */
function CVPixelBufferGetBaseAddressOfPlane(CVPixelBuffer $pixelBuffer, int $planeIndex): int {}

function CVPixelBufferGetBytesPerRowOfPlane(CVPixelBuffer $pixelBuffer, int $planeIndex): int {}

function CVPixelBufferGetWidthOfPlane(CVPixelBuffer $pixelBuffer, int $planeIndex): int {}

function CVPixelBufferGetHeightOfPlane(CVPixelBuffer $pixelBuffer, int $planeIndex): int {}
