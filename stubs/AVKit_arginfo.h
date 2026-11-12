/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 781913d63cc0054e37321d392fc8c5cb9b320c03 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVPlayerView_player, 0, 0, AVPlayer, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVPlayerView_setPlayer, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, player, AVPlayer, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVPlayerView_controlsStyle, 0, 0, AVPlayerViewControlsStyle, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVPlayerView_setControlsStyle, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, controlsStyle, AVPlayerViewControlsStyle, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(AVPlayerView, player);
ZEND_METHOD(AVPlayerView, setPlayer);
ZEND_METHOD(AVPlayerView, controlsStyle);
ZEND_METHOD(AVPlayerView, setControlsStyle);

static const zend_function_entry class_AVPlayerView_methods[] = {
	ZEND_ME(AVPlayerView, player, arginfo_class_AVPlayerView_player, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayerView, setPlayer, arginfo_class_AVPlayerView_setPlayer, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayerView, controlsStyle, arginfo_class_AVPlayerView_controlsStyle, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayerView, setControlsStyle, arginfo_class_AVPlayerView_setControlsStyle, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_AVPlayerViewControlsStyle(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("AVPlayerViewControlsStyle", IS_LONG, NULL);

	zval enum_case_NONE_value;
	ZVAL_LONG(&enum_case_NONE_value, 0);
	zend_enum_add_case_cstr(class_entry, "NONE", &enum_case_NONE_value);

	zval enum_case_INLINE_value;
	ZVAL_LONG(&enum_case_INLINE_value, 1);
	zend_enum_add_case_cstr(class_entry, "INLINE", &enum_case_INLINE_value);

	zval enum_case_FLOATING_value;
	ZVAL_LONG(&enum_case_FLOATING_value, 2);
	zend_enum_add_case_cstr(class_entry, "FLOATING", &enum_case_FLOATING_value);

	zval enum_case_MINIMAL_value;
	ZVAL_LONG(&enum_case_MINIMAL_value, 3);
	zend_enum_add_case_cstr(class_entry, "MINIMAL", &enum_case_MINIMAL_value);

	return class_entry;
}

static zend_class_entry *register_class_AVPlayerView(zend_class_entry *class_entry_NSView)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVPlayerView", class_AVPlayerView_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_NSView, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
