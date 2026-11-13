---
okf_version: "0.2"
---

# ext-avkit

1:1 PHP bindings of AVFoundation, AVFAudio, AVKit, CoreMedia and CoreVideo, on ext-appkit's object model. Version 0.11.2. macOS only.

# API

* [Bindings](api/bindings.md) — Classes and functions by framework: playback, assets and readers, sample, block and pixel buffers, values.

# Architecture

* [On appkit](architecture/appkit.md) — Headers, load order, symbol resolution, `AVKIT_MAP` / `AVKIT_CF`, `appkit_box_cf_as`.
* [Decode path](architecture/decode-path.md) — URL → asset → reader → output → sample buffer → pixels or PCM; the fixture's numbers.
* [Errors](architecture/errors.md) — `NSError` by reference, `AppKitException`, statuses as ints, no kept refusal.

# Runbooks

* [Build, install, test](runbooks/build.md) — appkit first, `install-macos.sh`, Pest on both PHPs, the guard's tree check.
