#include "runtime.h"
#include "../stubs/AVFoundation_arginfo.h"

_Static_assert(AVPlayerItemStatusUnknown == 0 && AVPlayerItemStatusReadyToPlay == 1 && AVPlayerItemStatusFailed == 2, "AVPlayerItemStatus values moved");
_Static_assert(AVPlayerTimeControlStatusPaused == 0 && AVPlayerTimeControlStatusWaitingToPlayAtSpecifiedRate == 1 && AVPlayerTimeControlStatusPlaying == 2, "AVPlayerTimeControlStatus values moved");
_Static_assert(AVPlayerActionAtItemEndAdvance == 0 && AVPlayerActionAtItemEndPause == 1 && AVPlayerActionAtItemEndNone == 2, "AVPlayerActionAtItemEnd values moved");

zend_class_entry *avkit_ce_AVPlayerItemStatus;
zend_class_entry *avkit_ce_AVPlayerItem;
zend_class_entry *avkit_ce_AVPlayerTimeControlStatus;
zend_class_entry *avkit_ce_AVPlayerActionAtItemEnd;
zend_class_entry *avkit_ce_AVPlayer;

void avkit_register_AVFoundation(int module_number)
{
	register_AVFoundation_symbols(module_number);

	avkit_ce_AVPlayerItemStatus = register_class_AVPlayerItemStatus();
	avkit_ce_AVPlayerTimeControlStatus = register_class_AVPlayerTimeControlStatus();
	avkit_ce_AVPlayerActionAtItemEnd = register_class_AVPlayerActionAtItemEnd();

	AVKIT_MAP(AVPlayerItem, appkit_ce_NSObject);
	AVKIT_MAP(AVPlayer, appkit_ce_NSObject);

	avkit_ce_AVAssetReaderStatus = register_class_AVAssetReaderStatus();
	AVKIT_MAP(AVAsset, appkit_ce_NSObject);
	AVKIT_MAP(AVURLAsset, avkit_ce_AVAsset);
	AVKIT_MAP(AVAssetTrack, appkit_ce_NSObject);
	AVKIT_MAP(AVAssetReaderOutput, appkit_ce_NSObject);
	AVKIT_MAP(AVAssetReaderTrackOutput, avkit_ce_AVAssetReaderOutput);
	AVKIT_MAP(AVAssetReader, appkit_ce_NSObject);
}

_Static_assert(AVAssetReaderStatusUnknown == 0 && AVAssetReaderStatusReading == 1 && AVAssetReaderStatusCompleted == 2
	&& AVAssetReaderStatusFailed == 3 && AVAssetReaderStatusCancelled == 4, "AVAssetReaderStatus values moved");

zend_class_entry *avkit_ce_AVAsset;
zend_class_entry *avkit_ce_AVURLAsset;
zend_class_entry *avkit_ce_AVAssetTrack;
zend_class_entry *avkit_ce_AVAssetReaderStatus;
zend_class_entry *avkit_ce_AVAssetReaderOutput;
zend_class_entry *avkit_ce_AVAssetReaderTrackOutput;
zend_class_entry *avkit_ce_AVAssetReader;

static void avkit_return_objects(zval *rv, NSArray *objects)
{
	array_init(rv);
	for (id object in objects) {
		zval boxed;
		appkit_box_objc(&boxed, object);
		add_next_index_zval(rv, &boxed);
	}
}

/* AVAsset */
ANY_METHOD(AVAsset, duration, PARSE_NONE, avkit_cmtime_new(return_value, [SELF(AVAsset) duration]);)
ANY_METHOD(AVAsset, tracks, PARSE_NONE, avkit_return_objects(return_value, [SELF(AVAsset) tracks]);)
ANY_METHOD(AVAsset, tracksWithMediaType, PARSE_STR, avkit_return_objects(return_value, [SELF(AVAsset) tracksWithMediaType:appkit_nsstring(v)]);)

/* AVURLAsset */
ZEND_METHOD(AVURLAsset, URLAssetWithURLOptions)
{
	zend_object *url;
	HashTable *options = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(url, appkit_ce_NSURL)
		Z_PARAM_ARRAY_HT_OR_NULL(options)
	ZEND_PARSE_PARAMETERS_END();

	APPKIT_BEGIN
		NSDictionary *dictionary = nil;

		if (options != NULL && (dictionary = appkit_nsdictionary(options, 2)) == nil) {
			RETURN_THROWS();
		}
		appkit_box_objc(return_value, [CALLED URLAssetWithURL:(NSURL *) APPKIT_ID(url) options:dictionary]);
	APPKIT_END
}
ANY_OBJ_GET(AVURLAsset, AVURLAsset, URL, URL)

/* AVAssetTrack */
ANY_LONG_GET(AVAssetTrack, AVAssetTrack, trackID, trackID)
ANY_STR_GET(AVAssetTrack, AVAssetTrack, mediaType, mediaType)
ANY_SIZE_GET(AVAssetTrack, AVAssetTrack, naturalSize, naturalSize)
ANY_DOUBLE_GET(AVAssetTrack, AVAssetTrack, nominalFrameRate, nominalFrameRate)
ANY_METHOD(AVAssetTrack, timeRange, PARSE_NONE, avkit_cmtimerange_new(return_value, [SELF(AVAssetTrack) timeRange]);)
ZEND_METHOD(AVAssetTrack, formatDescriptions)
{
	ZEND_PARSE_PARAMETERS_NONE();

	APPKIT_BEGIN
		array_init(return_value);
		for (id desc in [SELF(AVAssetTrack) formatDescriptions]) {
			zval boxed;
			avkit_box_format_description(&boxed, (CMFormatDescriptionRef) desc);
			add_next_index_zval(return_value, &boxed);
		}
	APPKIT_END
}

/* AVAssetReaderOutput */
ANY_STR_GET(AVAssetReaderOutput, AVAssetReaderOutput, mediaType, mediaType)
ANY_BOOL_GET(AVAssetReaderOutput, AVAssetReaderOutput, alwaysCopiesSampleData, alwaysCopiesSampleData)
ANY_BOOL_SET(AVAssetReaderOutput, AVAssetReaderOutput, setAlwaysCopiesSampleData, setAlwaysCopiesSampleData)
ZEND_METHOD(AVAssetReaderOutput, copyNextSampleBuffer)
{
	ZEND_PARSE_PARAMETERS_NONE();

	APPKIT_BEGIN
		CMSampleBufferRef sample = [SELF(AVAssetReaderOutput) copyNextSampleBuffer];

		appkit_box_cf_as(return_value, sample, avkit_ce_CMSampleBuffer);
		if (sample != NULL) {
			CFRelease(sample);
		}
	APPKIT_END
}

/* AVAssetReaderTrackOutput */
ZEND_METHOD(AVAssetReaderTrackOutput, assetReaderTrackOutputWithTrackOutputSettings)
{
	zend_object *track;
	HashTable *settings = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(track, avkit_ce_AVAssetTrack)
		Z_PARAM_ARRAY_HT_OR_NULL(settings)
	ZEND_PARSE_PARAMETERS_END();

	APPKIT_BEGIN
		NSDictionary *dictionary = nil;

		if (settings != NULL && (dictionary = appkit_nsdictionary(settings, 2)) == nil) {
			RETURN_THROWS();
		}
		appkit_box_objc(return_value, [CALLED assetReaderTrackOutputWithTrack:(AVAssetTrack *) APPKIT_ID(track) outputSettings:dictionary]);
	APPKIT_END
}
ANY_OBJ_GET(AVAssetReaderTrackOutput, AVAssetReaderTrackOutput, track, track)

/* AVAssetReader */
ZEND_METHOD(AVAssetReader, assetReaderWithAssetError)
{
	zend_object *asset;
	zval *error_ref = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJ_OF_CLASS(asset, avkit_ce_AVAsset)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(error_ref)
	ZEND_PARSE_PARAMETERS_END();

	APPKIT_BEGIN
		NSError *error = nil;

		appkit_box_objc(return_value, [CALLED assetReaderWithAsset:(AVAsset *) APPKIT_ID(asset) error:&error]);
		if (error_ref != NULL) {
			zval boxed;
			appkit_box_objc(&boxed, error);
			ZEND_TRY_ASSIGN_REF_TMP(error_ref, &boxed);
		}
	APPKIT_END
}
ANY_OBJ_GET(AVAssetReader, AVAssetReader, asset, asset)
ANY_ENUM_GET(AVAssetReader, AVAssetReader, status, status, avkit_ce_AVAssetReaderStatus, false)
ANY_OBJ_GET(AVAssetReader, AVAssetReader, error, error)
ANY_METHOD(AVAssetReader, timeRange, PARSE_NONE, avkit_cmtimerange_new(return_value, [SELF(AVAssetReader) timeRange]);)
ZEND_METHOD(AVAssetReader, setTimeRange)
{
	zend_object *object;
	CMTimeRange range;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(object, avkit_ce_CMTimeRange)
	ZEND_PARSE_PARAMETERS_END();
	if (!avkit_cmtimerange_from(object, 1, &range)) {
		RETURN_THROWS();
	}

	APPKIT_BEGIN
		[SELF(AVAssetReader) setTimeRange:range];
	APPKIT_END
}
ANY_METHOD(AVAssetReader, canAddOutput, PARSE_OBJ(avkit_ce_AVAssetReaderOutput), RETURN_BOOL([SELF(AVAssetReader) canAddOutput:(AVAssetReaderOutput *) APPKIT_ID(v)]);)
ANY_OBJ_SET(AVAssetReader, AVAssetReader, addOutput, addOutput, avkit_ce_AVAssetReaderOutput, AVAssetReaderOutput *)
ANY_METHOD(AVAssetReader, startReading, PARSE_NONE, RETURN_BOOL([SELF(AVAssetReader) startReading]);)
ANY_VOID_METHOD(AVAssetReader, AVAssetReader, cancelReading, cancelReading)

/* AVPlayerItem */
ANY_METHOD(AVPlayerItem, playerItemWithURL, PARSE_OBJ(appkit_ce_NSURL), appkit_box_objc(return_value, [CALLED playerItemWithURL:(NSURL *) APPKIT_ID(v)]);)
ANY_ENUM_GET(AVPlayerItem, AVPlayerItem, status, status, avkit_ce_AVPlayerItemStatus, false)
ANY_METHOD(AVPlayerItem, duration, PARSE_NONE, avkit_cmtime_new(return_value, [SELF(AVPlayerItem) duration]);)
ANY_OBJ_GET(AVPlayerItem, AVPlayerItem, error, error)

/* AVPlayer */
ANY_METHOD(AVPlayer, playerWithPlayerItem, PARSE_OBJ_OR_NULL(avkit_ce_AVPlayerItem), appkit_box_objc(return_value, [CALLED playerWithPlayerItem:(AVPlayerItem *) OPTIONAL_ID(v)]);)
ANY_VOID_METHOD(AVPlayer, AVPlayer, play, play)
ANY_VOID_METHOD(AVPlayer, AVPlayer, pause, pause)
ANY_DOUBLE_GET(AVPlayer, AVPlayer, rate, rate)
ANY_METHOD(AVPlayer, setRate, PARSE_DOUBLE, [SELF(AVPlayer) setRate:(float) v];)
ANY_METHOD(AVPlayer, currentTime, PARSE_NONE, avkit_cmtime_new(return_value, [SELF(AVPlayer) currentTime]);)
ZEND_METHOD(AVPlayer, seekToTime)
{
	zend_object *time;
	CMTime value;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(time, avkit_ce_CMTime)
	ZEND_PARSE_PARAMETERS_END();
	if (!avkit_cmtime_from(time, 1, &value)) {
		RETURN_THROWS();
	}

	APPKIT_BEGIN
		[SELF(AVPlayer) seekToTime:value];
	APPKIT_END
}
ANY_BOOL_GET(AVPlayer, AVPlayer, isMuted, isMuted)
ANY_BOOL_SET(AVPlayer, AVPlayer, setMuted, setMuted)
ANY_ENUM_GET(AVPlayer, AVPlayer, timeControlStatus, timeControlStatus, avkit_ce_AVPlayerTimeControlStatus, false)
ANY_ENUM_GET(AVPlayer, AVPlayer, actionAtItemEnd, actionAtItemEnd, avkit_ce_AVPlayerActionAtItemEnd, false)
ANY_ENUM_SET(AVPlayer, AVPlayer, setActionAtItemEnd, setActionAtItemEnd, avkit_ce_AVPlayerActionAtItemEnd, AVPlayerActionAtItemEnd)
ANY_OBJ_GET(AVPlayer, AVPlayer, currentItem, currentItem)
ANY_OBJ_SET_OR_NULL(AVPlayer, AVPlayer, replaceCurrentItemWithPlayerItem, replaceCurrentItemWithPlayerItem, avkit_ce_AVPlayerItem, AVPlayerItem *)
