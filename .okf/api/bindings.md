---
type: API
title: Bindings
description: Every class and function avkit binds, by framework.
resource: stubs/
tags: [avkit, api]
status: draft
generated: { by: claude-opus/5.5, at: 2026-11-11T20:00:00-05:00 }
sources:
  - id: stubs
    resource: stubs/
    title: AVFoundation, AVKit, CoreMedia, CoreVideo stubs
---

# Overview

The stubs in `stubs/` are the declaration; the README's "What is bound" table lists them by framework.[^stubs]

* Playback (AVFoundation, AVKit): `AVPlayerItem`, `AVPlayer`, `AVPlayerView extends NSView`, their enums, `AVPlayerItemDidPlayToEndTimeNotification`. Observe the end of play with appkit's `NSNotificationCenter` on `NSOperationQueue::mainQueue()`: AVPlayerItem may post on any thread.
* Assets and readers (AVFoundation): `AVAsset`, `AVURLAsset`, `AVAssetTrack`, `AVAssetReader`, `AVAssetReaderOutput`, `AVAssetReaderTrackOutput`, `AVAssetReaderStatus`; media-type and output-settings constants, `kAudioFormatLinearPCM`.
* Buffers (CoreMedia, CoreVideo): `CMSampleBuffer`, `CMBlockBuffer`, `CMFormatDescription` → `CMVideoFormatDescription` / `CMAudioFormatDescription`, `CVBuffer` → `CVImageBuffer` → `CVPixelBuffer`, and their C functions under their C names.
* Item outputs (AVFoundation): `AVPlayerItemOutput`, `AVPlayerItemVideoOutput` added to an item with `addOutput()`. Ask `itemTimeForMachAbsoluteTime()` (or `itemTimeForHostTime()`) for the item time now, then `hasNewPixelBufferForItemTime()` / `copyPixelBufferForItemTimeItemTimeForDisplay()` for the `CVPixelBuffer` due; `setSuppressesPlayerRendering(true)` when PHP draws the picture. `AVPlayer::volume()` / `setVolume()`.
* Audio output (AVFAudio): `AVAudioEngine`, `AVAudioNode` → `AVAudioIONode` → `AVAudioOutputNode`, `AVAudioMixerNode`, `AVAudioPlayerNode`, `AVAudioFormat`, `AVAudioBuffer` → `AVAudioPCMBuffer`, `AVAudioTime`, `AVAudioCommonFormat`, the `AVAudioPlayerNodeBuffer*` options and the `kAudioFormatFlag*` flags. A PCM buffer's `floatChannelData()` / `int16ChannelData()` / `int32ChannelData()` are addresses, one per channel or one when interleaved. The player clock is `playerTimeForNodeTime($node->lastRenderTime())->sampleTime()`. Not bound yet: the `scheduleBuffer…` selectors, whose completion handler is the block typedef `AVAudioNodeCompletionHandler`.
* Values: `CMTime`, `CMTimeRange`, `CMVideoDimensions`, `AudioStreamBasicDescription` — `final`, public properties named as the C fields, every field a constructor argument.

Guard notes (`bindings.json`): `CMVideoDimensions` is under `glue` (an anonymous-struct typedef the guard's index does not read); `typemap` maps `CMMediaType` and `OSType` to `int` (they resolve through `MacTypes.h`'s `FourCharCode`).

[^stubs]: AVFoundation, AVKit, CoreMedia, CoreVideo stubs
