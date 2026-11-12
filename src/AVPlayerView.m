#include "runtime.h"
#include "../stubs/AVKit_arginfo.h"

_Static_assert(AVPlayerViewControlsStyleNone == 0 && AVPlayerViewControlsStyleInline == 1 && AVPlayerViewControlsStyleFloating == 2
	&& AVPlayerViewControlsStyleMinimal == 3 && AVPlayerViewControlsStyleDefault == 1, "AVPlayerViewControlsStyle values moved");

zend_class_entry *avkit_ce_AVPlayerViewControlsStyle;
zend_class_entry *avkit_ce_AVPlayerView;

void avkit_register_AVKit(int module_number)
{
	avkit_ce_AVPlayerViewControlsStyle = register_class_AVPlayerViewControlsStyle();
	AVKIT_MAP(AVPlayerView, appkit_ce_NSView);
}

OBJ_GET(AVPlayerView, AVPlayerView, player, player)
OBJ_SET_OR_NULL(AVPlayerView, AVPlayerView, setPlayer, setPlayer, avkit_ce_AVPlayer, AVPlayer *)
ENUM_GET(AVPlayerView, AVPlayerView, controlsStyle, controlsStyle, avkit_ce_AVPlayerViewControlsStyle, false)
ENUM_SET(AVPlayerView, AVPlayerView, setControlsStyle, setControlsStyle, avkit_ce_AVPlayerViewControlsStyle, AVPlayerViewControlsStyle)
