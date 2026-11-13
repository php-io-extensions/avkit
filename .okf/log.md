# Log

## 2026-11-12

* Item video output and audio output for a player that draws its own pictures: `AVPlayerItemOutput`, `AVPlayerItemVideoOutput`, `AVPlayerItem` outputs, `AVPlayer` volume (AVFoundation); `AVAudioEngine`, nodes, `AVAudioFormat`, `AVAudioPCMBuffer`, `AVAudioTime` from the new `stubs/AVFAudio.stub.php` (`src/AVFAudio.m`). `tests/{VideoOutput,AudioEngine}Test.php`; 38 passed on php@8.4, php@8.4-zts and zhp. The engine test plays silence with the main mixer at 0. `AVAudioPlayerNode` `scheduleBuffer…` waits on a typemap entry for `AVAudioNodeCompletionHandler`. [bindings](api/bindings.md)

## 2026-11-11

* 0.11.2: repository, guarded as `objc`. Built on ext-appkit's object model through its installed `php_appkit_api.h`; requires appkit 0.11.2. [on appkit](architecture/appkit.md)
* Playback classes moved from ext-appkit: `AVPlayerItem`, `AVPlayer`, `AVPlayerView`, their enums, `AVPlayerItemDidPlayToEndTimeNotification`, `CMTime` with `CMTimeMake`, `CMTimeMakeWithSeconds`, `CMTimeGetSeconds`, `CMTimeCompare` (appkit's `CMTime::make()`, `makeWithSeconds()`, `getSeconds()` and `FLAG_*` are now the C names). `tests/PlaybackTest.php`.
* Decode path: assets, readers, sample, block and pixel buffers, format descriptions, `CMTimeRange`, `CMVideoDimensions`, `AudioStreamBasicDescription`. The fixture decodes to 10 BGRA frames and 44100 PCM samples. `tests/{TimeRange,Asset,Reader,Decode}Test.php`: 25 passed on php@8.4 and php@8.4-zts. [decode path](architecture/decode-path.md), [errors](architecture/errors.md), [bindings](api/bindings.md)
