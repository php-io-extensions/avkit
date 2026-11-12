#include "runtime.h"
#include "../stubs/CoreMedia_arginfo.h"

zend_class_entry *avkit_ce_CMTime;
zend_class_entry *avkit_ce_CMTimeRange;
zend_class_entry *avkit_ce_CMVideoDimensions;
zend_class_entry *avkit_ce_AudioStreamBasicDescription;
zend_class_entry *avkit_ce_CMSampleBuffer;
zend_class_entry *avkit_ce_CMBlockBuffer;
zend_class_entry *avkit_ce_CMFormatDescription;
zend_class_entry *avkit_ce_CMVideoFormatDescription;
zend_class_entry *avkit_ce_CMAudioFormatDescription;

void avkit_register_CoreMedia(int module_number)
{
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);
	register_CoreMedia_symbols(module_number);
	avkit_ce_CMTime = register_class_CMTime();
	avkit_ce_CMTimeRange = register_class_CMTimeRange();
	avkit_ce_CMVideoDimensions = register_class_CMVideoDimensions();
	avkit_ce_AudioStreamBasicDescription = register_class_AudioStreamBasicDescription();
	AVKIT_CF(CMSampleBuffer, appkit_ce_CFType);
	AVKIT_CF(CMBlockBuffer, appkit_ce_CFType);
	AVKIT_CF(CMFormatDescription, appkit_ce_CFType);
	AVKIT_CF(CMVideoFormatDescription, avkit_ce_CMFormatDescription);
	AVKIT_CF(CMAudioFormatDescription, avkit_ce_CMFormatDescription);
}

void avkit_box_format_description(zval *rv, CMFormatDescriptionRef desc)
{
	zend_class_entry *ce = avkit_ce_CMFormatDescription;

	if (desc != NULL) {
		CMMediaType type = CMFormatDescriptionGetMediaType(desc);

		if (type == kCMMediaType_Video) {
			ce = avkit_ce_CMVideoFormatDescription;
		} else if (type == kCMMediaType_Audio) {
			ce = avkit_ce_CMAudioFormatDescription;
		}
	}
	appkit_box_cf_as(rv, desc, ce);
}

bool avkit_cmtimerange_from(zend_object *range, uint32_t arg_num, CMTimeRange *out)
{
	zval *start = OBJ_PROP_NUM(range, 0);
	zval *duration = OBJ_PROP_NUM(range, 1);

	if (Z_TYPE_P(start) != IS_OBJECT || Z_TYPE_P(duration) != IS_OBJECT) {
		if (arg_num == 0) {
			zend_throw_error(NULL, "CMTimeRange must have every property initialized");
		} else {
			zend_argument_value_error(arg_num, "must have every property initialized");
		}
		return false;
	}
	return avkit_cmtime_from(Z_OBJ_P(start), arg_num, &out->start) && avkit_cmtime_from(Z_OBJ_P(duration), arg_num, &out->duration);
}

void avkit_cmtimerange_new(zval *rv, CMTimeRange range)
{
	zval start, duration;

	avkit_cmtime_new(&start, range.start);
	avkit_cmtime_new(&duration, range.duration);
	object_init_ex(rv, avkit_ce_CMTimeRange);
	ZVAL_COPY_VALUE(OBJ_PROP_NUM(Z_OBJ_P(rv), 0), &start);
	ZVAL_COPY_VALUE(OBJ_PROP_NUM(Z_OBJ_P(rv), 1), &duration);
}

ZEND_METHOD(CMTimeRange, __construct)
{
	zend_object *start, *duration;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(start, avkit_ce_CMTime)
		Z_PARAM_OBJ_OF_CLASS(duration, avkit_ce_CMTime)
	ZEND_PARSE_PARAMETERS_END();

	ZVAL_OBJ_COPY(OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), 0), start);
	ZVAL_OBJ_COPY(OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), 1), duration);
}

ZEND_METHOD(CMVideoDimensions, __construct)
{
	zend_long width, height;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), 0), width);
	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), 1), height);
}

ZEND_METHOD(AudioStreamBasicDescription, __construct)
{
	double rate;
	zend_long v[8];

	ZEND_PARSE_PARAMETERS_START(9, 9)
		Z_PARAM_DOUBLE(rate)
		Z_PARAM_LONG(v[0])
		Z_PARAM_LONG(v[1])
		Z_PARAM_LONG(v[2])
		Z_PARAM_LONG(v[3])
		Z_PARAM_LONG(v[4])
		Z_PARAM_LONG(v[5])
		Z_PARAM_LONG(v[6])
		Z_PARAM_LONG(v[7])
	ZEND_PARSE_PARAMETERS_END();

	ZVAL_DOUBLE(OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), 0), rate);
	for (int i = 0; i < 8; i++) {
		ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), i + 1), v[i]);
	}
}

ZEND_FUNCTION(CMTimeRangeMake)
{
	zend_object *a, *b;
	CMTime start, duration;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(a, avkit_ce_CMTime)
		Z_PARAM_OBJ_OF_CLASS(b, avkit_ce_CMTime)
	ZEND_PARSE_PARAMETERS_END();
	if (!avkit_cmtime_from(a, 1, &start) || !avkit_cmtime_from(b, 2, &duration)) {
		RETURN_THROWS();
	}

	avkit_cmtimerange_new(return_value, CMTimeRangeMake(start, duration));
}

ZEND_FUNCTION(CMTimeRangeGetEnd)
{
	zend_object *object;
	CMTimeRange range;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(object, avkit_ce_CMTimeRange)
	ZEND_PARSE_PARAMETERS_END();
	if (!avkit_cmtimerange_from(object, 1, &range)) {
		RETURN_THROWS();
	}

	avkit_cmtime_new(return_value, CMTimeRangeGetEnd(range));
}

#define SAMPLE_BUFFER(obj) ((CMSampleBufferRef) APPKIT_CF(obj))

#define SAMPLE_PARSE \
	zend_object *sbuf; \
	ZEND_PARSE_PARAMETERS_START(1, 1) \
		Z_PARAM_OBJ_OF_CLASS(sbuf, avkit_ce_CMSampleBuffer) \
	ZEND_PARSE_PARAMETERS_END();

ZEND_FUNCTION(CMSampleBufferGetImageBuffer)
{
	SAMPLE_PARSE
	avkit_box_image_buffer(return_value, CMSampleBufferGetImageBuffer(SAMPLE_BUFFER(sbuf)));
}

ZEND_FUNCTION(CMSampleBufferGetDataBuffer)
{
	SAMPLE_PARSE
	appkit_box_cf_as(return_value, CMSampleBufferGetDataBuffer(SAMPLE_BUFFER(sbuf)), avkit_ce_CMBlockBuffer);
}

ZEND_FUNCTION(CMSampleBufferGetFormatDescription)
{
	SAMPLE_PARSE
	avkit_box_format_description(return_value, CMSampleBufferGetFormatDescription(SAMPLE_BUFFER(sbuf)));
}

ZEND_FUNCTION(CMSampleBufferGetPresentationTimeStamp)
{
	SAMPLE_PARSE
	avkit_cmtime_new(return_value, CMSampleBufferGetPresentationTimeStamp(SAMPLE_BUFFER(sbuf)));
}

ZEND_FUNCTION(CMSampleBufferGetDuration)
{
	SAMPLE_PARSE
	avkit_cmtime_new(return_value, CMSampleBufferGetDuration(SAMPLE_BUFFER(sbuf)));
}

ZEND_FUNCTION(CMSampleBufferGetNumSamples)
{
	SAMPLE_PARSE
	RETURN_LONG((zend_long) CMSampleBufferGetNumSamples(SAMPLE_BUFFER(sbuf)));
}

ZEND_FUNCTION(CMBlockBufferGetDataLength)
{
	zend_object *buffer;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(buffer, avkit_ce_CMBlockBuffer)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG((zend_long) CMBlockBufferGetDataLength((CMBlockBufferRef) APPKIT_CF(buffer)));
}

ZEND_FUNCTION(CMBlockBufferCopyDataBytes)
{
	zend_object *buffer;
	zend_long offset, length;
	zval *destination;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJ_OF_CLASS(buffer, avkit_ce_CMBlockBuffer)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(length)
		Z_PARAM_ZVAL(destination)
	ZEND_PARSE_PARAMETERS_END();

	zend_string *bytes = zend_string_safe_alloc(1, (size_t) length, 0, 0);
	OSStatus status = CMBlockBufferCopyDataBytes((CMBlockBufferRef) APPKIT_CF(buffer), (size_t) offset, (size_t) length, ZSTR_VAL(bytes));

	if (status == kCMBlockBufferNoErr) {
		ZSTR_VAL(bytes)[length] = '\0';
		ZEND_TRY_ASSIGN_REF_STR(destination, bytes);
	} else {
		zend_string_efree(bytes);
	}
	RETURN_LONG((zend_long) status);
}

ZEND_FUNCTION(CMFormatDescriptionGetMediaType)
{
	zend_object *desc;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(desc, avkit_ce_CMFormatDescription)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG((zend_long) CMFormatDescriptionGetMediaType((CMFormatDescriptionRef) APPKIT_CF(desc)));
}

ZEND_FUNCTION(CMVideoFormatDescriptionGetDimensions)
{
	zend_object *desc;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(desc, avkit_ce_CMVideoFormatDescription)
	ZEND_PARSE_PARAMETERS_END();

	CMVideoDimensions dimensions = CMVideoFormatDescriptionGetDimensions((CMVideoFormatDescriptionRef) APPKIT_CF(desc));

	object_init_ex(return_value, avkit_ce_CMVideoDimensions);
	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(return_value), 0), (zend_long) dimensions.width);
	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(return_value), 1), (zend_long) dimensions.height);
}

ZEND_FUNCTION(CMAudioFormatDescriptionGetStreamBasicDescription)
{
	zend_object *desc;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(desc, avkit_ce_CMAudioFormatDescription)
	ZEND_PARSE_PARAMETERS_END();

	const AudioStreamBasicDescription *asbd = CMAudioFormatDescriptionGetStreamBasicDescription((CMAudioFormatDescriptionRef) APPKIT_CF(desc));

	if (asbd == NULL) {
		RETURN_NULL();
	}
	object_init_ex(return_value, avkit_ce_AudioStreamBasicDescription);
	zend_object *o = Z_OBJ_P(return_value);
	ZVAL_DOUBLE(OBJ_PROP_NUM(o, 0), asbd->mSampleRate);
	ZVAL_LONG(OBJ_PROP_NUM(o, 1), (zend_long) asbd->mFormatID);
	ZVAL_LONG(OBJ_PROP_NUM(o, 2), (zend_long) asbd->mFormatFlags);
	ZVAL_LONG(OBJ_PROP_NUM(o, 3), (zend_long) asbd->mBytesPerPacket);
	ZVAL_LONG(OBJ_PROP_NUM(o, 4), (zend_long) asbd->mFramesPerPacket);
	ZVAL_LONG(OBJ_PROP_NUM(o, 5), (zend_long) asbd->mBytesPerFrame);
	ZVAL_LONG(OBJ_PROP_NUM(o, 6), (zend_long) asbd->mChannelsPerFrame);
	ZVAL_LONG(OBJ_PROP_NUM(o, 7), (zend_long) asbd->mBitsPerChannel);
	ZVAL_LONG(OBJ_PROP_NUM(o, 8), (zend_long) asbd->mReserved);
}

bool avkit_cmtime_from(zend_object *time, uint32_t arg_num, CMTime *out)
{
	zend_long v[4];

	for (int i = 0; i < 4; i++) {
		zval *prop = OBJ_PROP_NUM(time, i);

		if (Z_TYPE_P(prop) != IS_LONG) {
			if (arg_num == 0) {
				zend_throw_error(NULL, "CMTime must have every property initialized");
			} else {
				zend_argument_value_error(arg_num, "must have every property initialized");
			}
			return false;
		}
		v[i] = Z_LVAL_P(prop);
	}
	*out = (CMTime) { .value = (CMTimeValue) v[0], .timescale = (CMTimeScale) v[1], .flags = (CMTimeFlags) v[2], .epoch = (CMTimeEpoch) v[3] };
	return true;
}

void avkit_cmtime_new(zval *rv, CMTime time)
{
	object_init_ex(rv, avkit_ce_CMTime);
	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(rv), 0), (zend_long) time.value);
	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(rv), 1), (zend_long) time.timescale);
	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(rv), 2), (zend_long) time.flags);
	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(rv), 3), (zend_long) time.epoch);
}

ZEND_METHOD(CMTime, __construct)
{
	zend_long value, timescale, flags, epoch;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(value)
		Z_PARAM_LONG(timescale)
		Z_PARAM_LONG(flags)
		Z_PARAM_LONG(epoch)
	ZEND_PARSE_PARAMETERS_END();

	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), 0), value);
	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), 1), timescale);
	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), 2), flags);
	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), 3), epoch);
}

ZEND_FUNCTION(CMTimeMake)
{
	zend_long value, timescale;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(value)
		Z_PARAM_LONG(timescale)
	ZEND_PARSE_PARAMETERS_END();

	avkit_cmtime_new(return_value, CMTimeMake((int64_t) value, (int32_t) timescale));
}

ZEND_FUNCTION(CMTimeMakeWithSeconds)
{
	double seconds;
	zend_long timescale;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_DOUBLE(seconds)
		Z_PARAM_LONG(timescale)
	ZEND_PARSE_PARAMETERS_END();

	avkit_cmtime_new(return_value, CMTimeMakeWithSeconds(seconds, (CMTimeScale) timescale));
}

ZEND_FUNCTION(CMTimeGetSeconds)
{
	zend_object *object;
	CMTime time;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(object, avkit_ce_CMTime)
	ZEND_PARSE_PARAMETERS_END();
	if (!avkit_cmtime_from(object, 1, &time)) {
		RETURN_THROWS();
	}

	RETURN_DOUBLE(CMTimeGetSeconds(time));
}

ZEND_FUNCTION(CMTimeCompare)
{
	zend_object *a, *b;
	CMTime time1, time2;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(a, avkit_ce_CMTime)
		Z_PARAM_OBJ_OF_CLASS(b, avkit_ce_CMTime)
	ZEND_PARSE_PARAMETERS_END();
	if (!avkit_cmtime_from(a, 1, &time1) || !avkit_cmtime_from(b, 2, &time2)) {
		RETURN_THROWS();
	}

	RETURN_LONG((zend_long) CMTimeCompare(time1, time2));
}
