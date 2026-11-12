<?php

/** @generate-class-entries */

/** AVPlayerViewControlsStyleDefault is INLINE. */
enum AVPlayerViewControlsStyle: int
{
    case NONE = 0;
    case INLINE = 1;
    case FLOATING = 2;
    case MINIMAL = 3;
}

/**
 * @not-serializable
 */
class AVPlayerView extends NSView
{
    public function player(): ?AVPlayer {}

    public function setPlayer(?AVPlayer $player): void {}

    public function controlsStyle(): AVPlayerViewControlsStyle {}

    public function setControlsStyle(AVPlayerViewControlsStyle $controlsStyle): void {}
}
