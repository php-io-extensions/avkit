/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: d9a5bf0486e355c61c0c88fa5aa713ab3231ea17 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_CMTimeMake, 0, 2, CMTime, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, timescale, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_CMTimeMakeWithSeconds, 0, 2, CMTime, 0)
	ZEND_ARG_TYPE_INFO(0, seconds, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, preferredTimescale, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CMTimeGetSeconds, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, time, CMTime, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CMTimeCompare, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, time1, CMTime, 0)
	ZEND_ARG_OBJ_INFO(0, time2, CMTime, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_CMTimeRangeMake, 0, 2, CMTimeRange, 0)
	ZEND_ARG_OBJ_INFO(0, start, CMTime, 0)
	ZEND_ARG_OBJ_INFO(0, duration, CMTime, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_CMTimeRangeGetEnd, 0, 1, CMTime, 0)
	ZEND_ARG_OBJ_INFO(0, range, CMTimeRange, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_CMSampleBufferGetImageBuffer, 0, 1, CVImageBuffer, 1)
	ZEND_ARG_OBJ_INFO(0, sbuf, CMSampleBuffer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_CMSampleBufferGetDataBuffer, 0, 1, CMBlockBuffer, 1)
	ZEND_ARG_OBJ_INFO(0, sbuf, CMSampleBuffer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_CMSampleBufferGetFormatDescription, 0, 1, CMFormatDescription, 1)
	ZEND_ARG_OBJ_INFO(0, sbuf, CMSampleBuffer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_CMSampleBufferGetPresentationTimeStamp, 0, 1, CMTime, 0)
	ZEND_ARG_OBJ_INFO(0, sbuf, CMSampleBuffer, 0)
ZEND_END_ARG_INFO()

#define arginfo_CMSampleBufferGetDuration arginfo_CMSampleBufferGetPresentationTimeStamp

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CMSampleBufferGetNumSamples, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, sbuf, CMSampleBuffer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CMBlockBufferGetDataLength, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, theBuffer, CMBlockBuffer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CMBlockBufferCopyDataBytes, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, theSourceBuffer, CMBlockBuffer, 0)
	ZEND_ARG_TYPE_INFO(0, offsetToData, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dataLength, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, destination, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CMFormatDescriptionGetMediaType, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, desc, CMFormatDescription, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_CMVideoFormatDescriptionGetDimensions, 0, 1, CMVideoDimensions, 0)
	ZEND_ARG_OBJ_INFO(0, videoDesc, CMVideoFormatDescription, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_CMAudioFormatDescriptionGetStreamBasicDescription, 0, 1, AudioStreamBasicDescription, 1)
	ZEND_ARG_OBJ_INFO(0, desc, CMAudioFormatDescription, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_CMTime___construct, 0, 0, 4)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, timescale, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, epoch, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_CMTimeRange___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, start, CMTime, 0)
	ZEND_ARG_OBJ_INFO(0, duration, CMTime, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_CMVideoDimensions___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_AudioStreamBasicDescription___construct, 0, 0, 9)
	ZEND_ARG_TYPE_INFO(0, mSampleRate, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, mFormatID, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mFormatFlags, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mBytesPerPacket, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mFramesPerPacket, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mBytesPerFrame, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mChannelsPerFrame, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mBitsPerChannel, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mReserved, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_FUNCTION(CMTimeMake);
ZEND_FUNCTION(CMTimeMakeWithSeconds);
ZEND_FUNCTION(CMTimeGetSeconds);
ZEND_FUNCTION(CMTimeCompare);
ZEND_FUNCTION(CMTimeRangeMake);
ZEND_FUNCTION(CMTimeRangeGetEnd);
ZEND_FUNCTION(CMSampleBufferGetImageBuffer);
ZEND_FUNCTION(CMSampleBufferGetDataBuffer);
ZEND_FUNCTION(CMSampleBufferGetFormatDescription);
ZEND_FUNCTION(CMSampleBufferGetPresentationTimeStamp);
ZEND_FUNCTION(CMSampleBufferGetDuration);
ZEND_FUNCTION(CMSampleBufferGetNumSamples);
ZEND_FUNCTION(CMBlockBufferGetDataLength);
ZEND_FUNCTION(CMBlockBufferCopyDataBytes);
ZEND_FUNCTION(CMFormatDescriptionGetMediaType);
ZEND_FUNCTION(CMVideoFormatDescriptionGetDimensions);
ZEND_FUNCTION(CMAudioFormatDescriptionGetStreamBasicDescription);
ZEND_METHOD(CMTime, __construct);
ZEND_METHOD(CMTimeRange, __construct);
ZEND_METHOD(CMVideoDimensions, __construct);
ZEND_METHOD(AudioStreamBasicDescription, __construct);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(CMTimeMake, arginfo_CMTimeMake)
	ZEND_FE(CMTimeMakeWithSeconds, arginfo_CMTimeMakeWithSeconds)
	ZEND_FE(CMTimeGetSeconds, arginfo_CMTimeGetSeconds)
	ZEND_FE(CMTimeCompare, arginfo_CMTimeCompare)
	ZEND_FE(CMTimeRangeMake, arginfo_CMTimeRangeMake)
	ZEND_FE(CMTimeRangeGetEnd, arginfo_CMTimeRangeGetEnd)
	ZEND_FE(CMSampleBufferGetImageBuffer, arginfo_CMSampleBufferGetImageBuffer)
	ZEND_FE(CMSampleBufferGetDataBuffer, arginfo_CMSampleBufferGetDataBuffer)
	ZEND_FE(CMSampleBufferGetFormatDescription, arginfo_CMSampleBufferGetFormatDescription)
	ZEND_FE(CMSampleBufferGetPresentationTimeStamp, arginfo_CMSampleBufferGetPresentationTimeStamp)
	ZEND_FE(CMSampleBufferGetDuration, arginfo_CMSampleBufferGetDuration)
	ZEND_FE(CMSampleBufferGetNumSamples, arginfo_CMSampleBufferGetNumSamples)
	ZEND_FE(CMBlockBufferGetDataLength, arginfo_CMBlockBufferGetDataLength)
	ZEND_FE(CMBlockBufferCopyDataBytes, arginfo_CMBlockBufferCopyDataBytes)
	ZEND_FE(CMFormatDescriptionGetMediaType, arginfo_CMFormatDescriptionGetMediaType)
	ZEND_FE(CMVideoFormatDescriptionGetDimensions, arginfo_CMVideoFormatDescriptionGetDimensions)
	ZEND_FE(CMAudioFormatDescriptionGetStreamBasicDescription, arginfo_CMAudioFormatDescriptionGetStreamBasicDescription)
	ZEND_FE_END
};

static const zend_function_entry class_CMTime_methods[] = {
	ZEND_ME(CMTime, __construct, arginfo_class_CMTime___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_CMTimeRange_methods[] = {
	ZEND_ME(CMTimeRange, __construct, arginfo_class_CMTimeRange___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_CMVideoDimensions_methods[] = {
	ZEND_ME(CMVideoDimensions, __construct, arginfo_class_CMVideoDimensions___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_AudioStreamBasicDescription_methods[] = {
	ZEND_ME(AudioStreamBasicDescription, __construct, arginfo_class_AudioStreamBasicDescription___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static void register_CoreMedia_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("kCMTimeFlags_Valid", kCMTimeFlags_Valid, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kCMTimeFlags_HasBeenRounded", kCMTimeFlags_HasBeenRounded, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kCMTimeFlags_PositiveInfinity", kCMTimeFlags_PositiveInfinity, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kCMTimeFlags_NegativeInfinity", kCMTimeFlags_NegativeInfinity, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kCMTimeFlags_Indefinite", kCMTimeFlags_Indefinite, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kCMMediaType_Video", kCMMediaType_Video, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kCMMediaType_Audio", kCMMediaType_Audio, CONST_PERSISTENT);
}

static zend_class_entry *register_class_CMTime(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "CMTime", class_CMTime_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_value_default_value;
	ZVAL_UNDEF(&property_value_default_value);
	zend_string *property_value_name = zend_string_init("value", sizeof("value") - 1, 1);
	zend_declare_typed_property(class_entry, property_value_name, &property_value_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_value_name);

	zval property_timescale_default_value;
	ZVAL_UNDEF(&property_timescale_default_value);
	zend_string *property_timescale_name = zend_string_init("timescale", sizeof("timescale") - 1, 1);
	zend_declare_typed_property(class_entry, property_timescale_name, &property_timescale_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_timescale_name);

	zval property_flags_default_value;
	ZVAL_UNDEF(&property_flags_default_value);
	zend_string *property_flags_name = zend_string_init("flags", sizeof("flags") - 1, 1);
	zend_declare_typed_property(class_entry, property_flags_name, &property_flags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_flags_name);

	zval property_epoch_default_value;
	ZVAL_UNDEF(&property_epoch_default_value);
	zend_string *property_epoch_name = zend_string_init("epoch", sizeof("epoch") - 1, 1);
	zend_declare_typed_property(class_entry, property_epoch_name, &property_epoch_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_epoch_name);

	return class_entry;
}

static zend_class_entry *register_class_CMTimeRange(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "CMTimeRange", class_CMTimeRange_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_start_default_value;
	ZVAL_UNDEF(&property_start_default_value);
	zend_string *property_start_name = zend_string_init("start", sizeof("start") - 1, 1);
	zend_string *property_start_class_CMTime = zend_string_init("CMTime", sizeof("CMTime")-1, 1);
	zend_declare_typed_property(class_entry, property_start_name, &property_start_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_start_class_CMTime, 0, 0));
	zend_string_release(property_start_name);

	zval property_duration_default_value;
	ZVAL_UNDEF(&property_duration_default_value);
	zend_string *property_duration_name = zend_string_init("duration", sizeof("duration") - 1, 1);
	zend_string *property_duration_class_CMTime = zend_string_init("CMTime", sizeof("CMTime")-1, 1);
	zend_declare_typed_property(class_entry, property_duration_name, &property_duration_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_duration_class_CMTime, 0, 0));
	zend_string_release(property_duration_name);

	return class_entry;
}

static zend_class_entry *register_class_CMVideoDimensions(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "CMVideoDimensions", class_CMVideoDimensions_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_width_default_value;
	ZVAL_UNDEF(&property_width_default_value);
	zend_string *property_width_name = zend_string_init("width", sizeof("width") - 1, 1);
	zend_declare_typed_property(class_entry, property_width_name, &property_width_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_width_name);

	zval property_height_default_value;
	ZVAL_UNDEF(&property_height_default_value);
	zend_string *property_height_name = zend_string_init("height", sizeof("height") - 1, 1);
	zend_declare_typed_property(class_entry, property_height_name, &property_height_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_height_name);

	return class_entry;
}

static zend_class_entry *register_class_AudioStreamBasicDescription(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AudioStreamBasicDescription", class_AudioStreamBasicDescription_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_mSampleRate_default_value;
	ZVAL_UNDEF(&property_mSampleRate_default_value);
	zend_string *property_mSampleRate_name = zend_string_init("mSampleRate", sizeof("mSampleRate") - 1, 1);
	zend_declare_typed_property(class_entry, property_mSampleRate_name, &property_mSampleRate_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_mSampleRate_name);

	zval property_mFormatID_default_value;
	ZVAL_UNDEF(&property_mFormatID_default_value);
	zend_string *property_mFormatID_name = zend_string_init("mFormatID", sizeof("mFormatID") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFormatID_name, &property_mFormatID_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mFormatID_name);

	zval property_mFormatFlags_default_value;
	ZVAL_UNDEF(&property_mFormatFlags_default_value);
	zend_string *property_mFormatFlags_name = zend_string_init("mFormatFlags", sizeof("mFormatFlags") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFormatFlags_name, &property_mFormatFlags_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mFormatFlags_name);

	zval property_mBytesPerPacket_default_value;
	ZVAL_UNDEF(&property_mBytesPerPacket_default_value);
	zend_string *property_mBytesPerPacket_name = zend_string_init("mBytesPerPacket", sizeof("mBytesPerPacket") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBytesPerPacket_name, &property_mBytesPerPacket_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mBytesPerPacket_name);

	zval property_mFramesPerPacket_default_value;
	ZVAL_UNDEF(&property_mFramesPerPacket_default_value);
	zend_string *property_mFramesPerPacket_name = zend_string_init("mFramesPerPacket", sizeof("mFramesPerPacket") - 1, 1);
	zend_declare_typed_property(class_entry, property_mFramesPerPacket_name, &property_mFramesPerPacket_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mFramesPerPacket_name);

	zval property_mBytesPerFrame_default_value;
	ZVAL_UNDEF(&property_mBytesPerFrame_default_value);
	zend_string *property_mBytesPerFrame_name = zend_string_init("mBytesPerFrame", sizeof("mBytesPerFrame") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBytesPerFrame_name, &property_mBytesPerFrame_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mBytesPerFrame_name);

	zval property_mChannelsPerFrame_default_value;
	ZVAL_UNDEF(&property_mChannelsPerFrame_default_value);
	zend_string *property_mChannelsPerFrame_name = zend_string_init("mChannelsPerFrame", sizeof("mChannelsPerFrame") - 1, 1);
	zend_declare_typed_property(class_entry, property_mChannelsPerFrame_name, &property_mChannelsPerFrame_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mChannelsPerFrame_name);

	zval property_mBitsPerChannel_default_value;
	ZVAL_UNDEF(&property_mBitsPerChannel_default_value);
	zend_string *property_mBitsPerChannel_name = zend_string_init("mBitsPerChannel", sizeof("mBitsPerChannel") - 1, 1);
	zend_declare_typed_property(class_entry, property_mBitsPerChannel_name, &property_mBitsPerChannel_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mBitsPerChannel_name);

	zval property_mReserved_default_value;
	ZVAL_UNDEF(&property_mReserved_default_value);
	zend_string *property_mReserved_name = zend_string_init("mReserved", sizeof("mReserved") - 1, 1);
	zend_declare_typed_property(class_entry, property_mReserved_name, &property_mReserved_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_mReserved_name);

	return class_entry;
}

static zend_class_entry *register_class_CMSampleBuffer(zend_class_entry *class_entry_CFType)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "CMSampleBuffer", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_CFType, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_CMBlockBuffer(zend_class_entry *class_entry_CFType)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "CMBlockBuffer", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_CFType, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_CMFormatDescription(zend_class_entry *class_entry_CFType)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "CMFormatDescription", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_CFType, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_CMVideoFormatDescription(zend_class_entry *class_entry_CMFormatDescription)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "CMVideoFormatDescription", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_CMFormatDescription, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_CMAudioFormatDescription(zend_class_entry *class_entry_CMFormatDescription)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "CMAudioFormatDescription", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_CMFormatDescription, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
