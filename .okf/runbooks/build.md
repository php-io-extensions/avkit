---
type: Runbook
title: Build, install, test
description: appkit first, then install-macos.sh into php84 and zhp; Pest on both; the guard's tree check.
resource: install-macos.sh
tags: [avkit, build, test]
status: draft
generated: { by: claude-opus/5.5, at: 2026-11-11T20:00:00-05:00 }
sources:
  - id: install
    resource: install-macos.sh
    title: installer
  - id: config
    resource: config.m4
    title: sources and frameworks
---

# Steps

1. Install ext-appkit 0.11.2 into the same PHPs (`../appkit/install-macos.sh`): avkit compiles against its installed headers and the installer stops when appkit is not loaded.[^install]
2. Regenerate arginfo after a stub change: `php84 /opt/homebrew/opt/php@8.4/lib/php/build/gen_stub.php stubs`.
3. `./install-macos.sh`: builds in a temporary copy for Homebrew `php@8.4` and `php@8.4-zts`, ad-hoc signs, writes `30-avkit.ini`. `AVKIT_CONFIGURE=--enable-avkit-probes` builds the probe switch.
4. `composer install`, then `php84 -d memory_limit=128M vendor/bin/pest` and `zhp -d memory_limit=128M vendor/bin/pest`; remove `vendor/` and `composer.lock` after.
5. `/opt/homebrew/bin/python3 ~/.agent-guards/ext-guard.py tree .` prints `clean` when the pre-commit hook will pass.

`config.m4` links `AVKIT_FRAMEWORKS` except CoreAudioTypes, which has headers and no library; it stays in the list so the guard reads `kAudioFormatLinearPCM`'s header. Every source is Objective-C, compiled `-fno-objc-arc`.[^config]

[^install]: installer
[^config]: sources and frameworks
