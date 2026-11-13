/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: d7125670959a3aaa98d9bf3e4e23d97b9ec89e0f */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAsset_duration, 0, 0, CMTime, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAsset_tracks, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAsset_tracksWithMediaType, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, mediaType, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVURLAsset_URLAssetWithURLOptions, 0, 2, IS_STATIC, 0)
	ZEND_ARG_OBJ_INFO(0, URL, NSURL, 0)
	ZEND_ARG_TYPE_INFO(0, options, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVURLAsset_URL, 0, 0, NSURL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAssetTrack_trackID, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAssetTrack_mediaType, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAssetTrack_naturalSize, 0, 0, NSSize, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAssetTrack_nominalFrameRate, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAssetTrack_timeRange, 0, 0, CMTimeRange, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAssetTrack_formatDescriptions arginfo_class_AVAsset_tracks

#define arginfo_class_AVAssetReaderOutput_mediaType arginfo_class_AVAssetTrack_mediaType

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAssetReaderOutput_alwaysCopiesSampleData, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAssetReaderOutput_setAlwaysCopiesSampleData, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, alwaysCopiesSampleData, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAssetReaderOutput_copyNextSampleBuffer, 0, 0, CMSampleBuffer, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAssetReaderTrackOutput_assetReaderTrackOutputWithTrackOutputSettings, 0, 2, IS_STATIC, 0)
	ZEND_ARG_OBJ_INFO(0, track, AVAssetTrack, 0)
	ZEND_ARG_TYPE_INFO(0, outputSettings, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAssetReaderTrackOutput_track, 0, 0, AVAssetTrack, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAssetReader_assetReaderWithAssetError, 0, 1, IS_STATIC, 1)
	ZEND_ARG_OBJ_INFO(0, asset, AVAsset, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(1, outError, NSError, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAssetReader_asset, 0, 0, AVAsset, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAssetReader_status, 0, 0, AVAssetReaderStatus, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAssetReader_error, 0, 0, NSError, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAssetReader_timeRange arginfo_class_AVAssetTrack_timeRange

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAssetReader_setTimeRange, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, timeRange, CMTimeRange, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAssetReader_canAddOutput, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, output, AVAssetReaderOutput, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAssetReader_addOutput, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, output, AVAssetReaderOutput, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAssetReader_startReading arginfo_class_AVAssetReaderOutput_alwaysCopiesSampleData

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAssetReader_cancelReading, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVPlayerItem_playerItemWithURL, 0, 1, IS_STATIC, 0)
	ZEND_ARG_OBJ_INFO(0, URL, NSURL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVPlayerItem_status, 0, 0, AVPlayerItemStatus, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVPlayerItem_duration arginfo_class_AVAsset_duration

#define arginfo_class_AVPlayerItem_error arginfo_class_AVAssetReader_error

#define arginfo_class_AVPlayerItem_outputs arginfo_class_AVAsset_tracks

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVPlayerItem_addOutput, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, output, AVPlayerItemOutput, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVPlayerItem_removeOutput arginfo_class_AVPlayerItem_addOutput

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVPlayerItemOutput_itemTimeForHostTime, 0, 1, CMTime, 0)
	ZEND_ARG_TYPE_INFO(0, hostTimeInSeconds, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVPlayerItemOutput_itemTimeForMachAbsoluteTime, 0, 1, CMTime, 0)
	ZEND_ARG_TYPE_INFO(0, machAbsoluteTime, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVPlayerItemOutput_suppressesPlayerRendering arginfo_class_AVAssetReaderOutput_alwaysCopiesSampleData

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVPlayerItemOutput_setSuppressesPlayerRendering, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, suppressesPlayerRendering, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVPlayerItemVideoOutput_initWithPixelBufferAttributes, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, pixelBufferAttributes, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVPlayerItemVideoOutput_initWithOutputSettings, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, outputSettings, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVPlayerItemVideoOutput_hasNewPixelBufferForItemTime, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, itemTime, CMTime, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVPlayerItemVideoOutput_copyPixelBufferForItemTimeItemTimeForDisplay, 0, 1, CVPixelBuffer, 1)
	ZEND_ARG_OBJ_INFO(0, itemTime, CMTime, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(1, outItemTimeForDisplay, CMTime, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVPlayer_playerWithPlayerItem, 0, 1, IS_STATIC, 0)
	ZEND_ARG_OBJ_INFO(0, item, AVPlayerItem, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_AVPlayer_play arginfo_class_AVAssetReader_cancelReading

#define arginfo_class_AVPlayer_pause arginfo_class_AVAssetReader_cancelReading

#define arginfo_class_AVPlayer_rate arginfo_class_AVAssetTrack_nominalFrameRate

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVPlayer_setRate, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, rate, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVPlayer_currentTime arginfo_class_AVAsset_duration

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVPlayer_seekToTime, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, time, CMTime, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVPlayer_isMuted arginfo_class_AVAssetReaderOutput_alwaysCopiesSampleData

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVPlayer_setMuted, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, muted, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVPlayer_volume arginfo_class_AVAssetTrack_nominalFrameRate

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVPlayer_setVolume, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, volume, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVPlayer_timeControlStatus, 0, 0, AVPlayerTimeControlStatus, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVPlayer_actionAtItemEnd, 0, 0, AVPlayerActionAtItemEnd, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVPlayer_setActionAtItemEnd, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, actionAtItemEnd, AVPlayerActionAtItemEnd, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVPlayer_currentItem, 0, 0, AVPlayerItem, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVPlayer_replaceCurrentItemWithPlayerItem, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, item, AVPlayerItem, 1)
ZEND_END_ARG_INFO()

ZEND_METHOD(AVAsset, duration);
ZEND_METHOD(AVAsset, tracks);
ZEND_METHOD(AVAsset, tracksWithMediaType);
ZEND_METHOD(AVURLAsset, URLAssetWithURLOptions);
ZEND_METHOD(AVURLAsset, URL);
ZEND_METHOD(AVAssetTrack, trackID);
ZEND_METHOD(AVAssetTrack, mediaType);
ZEND_METHOD(AVAssetTrack, naturalSize);
ZEND_METHOD(AVAssetTrack, nominalFrameRate);
ZEND_METHOD(AVAssetTrack, timeRange);
ZEND_METHOD(AVAssetTrack, formatDescriptions);
ZEND_METHOD(AVAssetReaderOutput, mediaType);
ZEND_METHOD(AVAssetReaderOutput, alwaysCopiesSampleData);
ZEND_METHOD(AVAssetReaderOutput, setAlwaysCopiesSampleData);
ZEND_METHOD(AVAssetReaderOutput, copyNextSampleBuffer);
ZEND_METHOD(AVAssetReaderTrackOutput, assetReaderTrackOutputWithTrackOutputSettings);
ZEND_METHOD(AVAssetReaderTrackOutput, track);
ZEND_METHOD(AVAssetReader, assetReaderWithAssetError);
ZEND_METHOD(AVAssetReader, asset);
ZEND_METHOD(AVAssetReader, status);
ZEND_METHOD(AVAssetReader, error);
ZEND_METHOD(AVAssetReader, timeRange);
ZEND_METHOD(AVAssetReader, setTimeRange);
ZEND_METHOD(AVAssetReader, canAddOutput);
ZEND_METHOD(AVAssetReader, addOutput);
ZEND_METHOD(AVAssetReader, startReading);
ZEND_METHOD(AVAssetReader, cancelReading);
ZEND_METHOD(AVPlayerItem, playerItemWithURL);
ZEND_METHOD(AVPlayerItem, status);
ZEND_METHOD(AVPlayerItem, duration);
ZEND_METHOD(AVPlayerItem, error);
ZEND_METHOD(AVPlayerItem, outputs);
ZEND_METHOD(AVPlayerItem, addOutput);
ZEND_METHOD(AVPlayerItem, removeOutput);
ZEND_METHOD(AVPlayerItemOutput, itemTimeForHostTime);
ZEND_METHOD(AVPlayerItemOutput, itemTimeForMachAbsoluteTime);
ZEND_METHOD(AVPlayerItemOutput, suppressesPlayerRendering);
ZEND_METHOD(AVPlayerItemOutput, setSuppressesPlayerRendering);
ZEND_METHOD(AVPlayerItemVideoOutput, initWithPixelBufferAttributes);
ZEND_METHOD(AVPlayerItemVideoOutput, initWithOutputSettings);
ZEND_METHOD(AVPlayerItemVideoOutput, hasNewPixelBufferForItemTime);
ZEND_METHOD(AVPlayerItemVideoOutput, copyPixelBufferForItemTimeItemTimeForDisplay);
ZEND_METHOD(AVPlayer, playerWithPlayerItem);
ZEND_METHOD(AVPlayer, play);
ZEND_METHOD(AVPlayer, pause);
ZEND_METHOD(AVPlayer, rate);
ZEND_METHOD(AVPlayer, setRate);
ZEND_METHOD(AVPlayer, currentTime);
ZEND_METHOD(AVPlayer, seekToTime);
ZEND_METHOD(AVPlayer, isMuted);
ZEND_METHOD(AVPlayer, setMuted);
ZEND_METHOD(AVPlayer, volume);
ZEND_METHOD(AVPlayer, setVolume);
ZEND_METHOD(AVPlayer, timeControlStatus);
ZEND_METHOD(AVPlayer, actionAtItemEnd);
ZEND_METHOD(AVPlayer, setActionAtItemEnd);
ZEND_METHOD(AVPlayer, currentItem);
ZEND_METHOD(AVPlayer, replaceCurrentItemWithPlayerItem);

static const zend_function_entry class_AVAsset_methods[] = {
	ZEND_ME(AVAsset, duration, arginfo_class_AVAsset_duration, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAsset, tracks, arginfo_class_AVAsset_tracks, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAsset, tracksWithMediaType, arginfo_class_AVAsset_tracksWithMediaType, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_AVURLAsset_methods[] = {
	ZEND_ME(AVURLAsset, URLAssetWithURLOptions, arginfo_class_AVURLAsset_URLAssetWithURLOptions, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(AVURLAsset, URL, arginfo_class_AVURLAsset_URL, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_AVAssetTrack_methods[] = {
	ZEND_ME(AVAssetTrack, trackID, arginfo_class_AVAssetTrack_trackID, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAssetTrack, mediaType, arginfo_class_AVAssetTrack_mediaType, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAssetTrack, naturalSize, arginfo_class_AVAssetTrack_naturalSize, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAssetTrack, nominalFrameRate, arginfo_class_AVAssetTrack_nominalFrameRate, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAssetTrack, timeRange, arginfo_class_AVAssetTrack_timeRange, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAssetTrack, formatDescriptions, arginfo_class_AVAssetTrack_formatDescriptions, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_AVAssetReaderOutput_methods[] = {
	ZEND_ME(AVAssetReaderOutput, mediaType, arginfo_class_AVAssetReaderOutput_mediaType, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAssetReaderOutput, alwaysCopiesSampleData, arginfo_class_AVAssetReaderOutput_alwaysCopiesSampleData, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAssetReaderOutput, setAlwaysCopiesSampleData, arginfo_class_AVAssetReaderOutput_setAlwaysCopiesSampleData, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAssetReaderOutput, copyNextSampleBuffer, arginfo_class_AVAssetReaderOutput_copyNextSampleBuffer, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_AVAssetReaderTrackOutput_methods[] = {
	ZEND_ME(AVAssetReaderTrackOutput, assetReaderTrackOutputWithTrackOutputSettings, arginfo_class_AVAssetReaderTrackOutput_assetReaderTrackOutputWithTrackOutputSettings, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(AVAssetReaderTrackOutput, track, arginfo_class_AVAssetReaderTrackOutput_track, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_AVAssetReader_methods[] = {
	ZEND_ME(AVAssetReader, assetReaderWithAssetError, arginfo_class_AVAssetReader_assetReaderWithAssetError, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(AVAssetReader, asset, arginfo_class_AVAssetReader_asset, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAssetReader, status, arginfo_class_AVAssetReader_status, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAssetReader, error, arginfo_class_AVAssetReader_error, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAssetReader, timeRange, arginfo_class_AVAssetReader_timeRange, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAssetReader, setTimeRange, arginfo_class_AVAssetReader_setTimeRange, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAssetReader, canAddOutput, arginfo_class_AVAssetReader_canAddOutput, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAssetReader, addOutput, arginfo_class_AVAssetReader_addOutput, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAssetReader, startReading, arginfo_class_AVAssetReader_startReading, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAssetReader, cancelReading, arginfo_class_AVAssetReader_cancelReading, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_AVPlayerItem_methods[] = {
	ZEND_ME(AVPlayerItem, playerItemWithURL, arginfo_class_AVPlayerItem_playerItemWithURL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(AVPlayerItem, status, arginfo_class_AVPlayerItem_status, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayerItem, duration, arginfo_class_AVPlayerItem_duration, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayerItem, error, arginfo_class_AVPlayerItem_error, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayerItem, outputs, arginfo_class_AVPlayerItem_outputs, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayerItem, addOutput, arginfo_class_AVPlayerItem_addOutput, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayerItem, removeOutput, arginfo_class_AVPlayerItem_removeOutput, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_AVPlayerItemOutput_methods[] = {
	ZEND_ME(AVPlayerItemOutput, itemTimeForHostTime, arginfo_class_AVPlayerItemOutput_itemTimeForHostTime, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayerItemOutput, itemTimeForMachAbsoluteTime, arginfo_class_AVPlayerItemOutput_itemTimeForMachAbsoluteTime, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayerItemOutput, suppressesPlayerRendering, arginfo_class_AVPlayerItemOutput_suppressesPlayerRendering, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayerItemOutput, setSuppressesPlayerRendering, arginfo_class_AVPlayerItemOutput_setSuppressesPlayerRendering, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_AVPlayerItemVideoOutput_methods[] = {
	ZEND_ME(AVPlayerItemVideoOutput, initWithPixelBufferAttributes, arginfo_class_AVPlayerItemVideoOutput_initWithPixelBufferAttributes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(AVPlayerItemVideoOutput, initWithOutputSettings, arginfo_class_AVPlayerItemVideoOutput_initWithOutputSettings, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(AVPlayerItemVideoOutput, hasNewPixelBufferForItemTime, arginfo_class_AVPlayerItemVideoOutput_hasNewPixelBufferForItemTime, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayerItemVideoOutput, copyPixelBufferForItemTimeItemTimeForDisplay, arginfo_class_AVPlayerItemVideoOutput_copyPixelBufferForItemTimeItemTimeForDisplay, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_AVPlayer_methods[] = {
	ZEND_ME(AVPlayer, playerWithPlayerItem, arginfo_class_AVPlayer_playerWithPlayerItem, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(AVPlayer, play, arginfo_class_AVPlayer_play, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayer, pause, arginfo_class_AVPlayer_pause, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayer, rate, arginfo_class_AVPlayer_rate, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayer, setRate, arginfo_class_AVPlayer_setRate, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayer, currentTime, arginfo_class_AVPlayer_currentTime, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayer, seekToTime, arginfo_class_AVPlayer_seekToTime, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayer, isMuted, arginfo_class_AVPlayer_isMuted, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayer, setMuted, arginfo_class_AVPlayer_setMuted, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayer, volume, arginfo_class_AVPlayer_volume, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayer, setVolume, arginfo_class_AVPlayer_setVolume, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayer, timeControlStatus, arginfo_class_AVPlayer_timeControlStatus, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayer, actionAtItemEnd, arginfo_class_AVPlayer_actionAtItemEnd, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayer, setActionAtItemEnd, arginfo_class_AVPlayer_setActionAtItemEnd, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayer, currentItem, arginfo_class_AVPlayer_currentItem, ZEND_ACC_PUBLIC)
	ZEND_ME(AVPlayer, replaceCurrentItemWithPlayerItem, arginfo_class_AVPlayer_replaceCurrentItemWithPlayerItem, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static void register_AVFoundation_symbols(int module_number)
{
	REGISTER_STRING_CONSTANT("AVPlayerItemDidPlayToEndTimeNotification", appkit_cfstring_constant((CFStringRef) AVPlayerItemDidPlayToEndTimeNotification), CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("AVMediaTypeVideo", appkit_cfstring_constant((CFStringRef) AVMediaTypeVideo), CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("AVMediaTypeAudio", appkit_cfstring_constant((CFStringRef) AVMediaTypeAudio), CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("AVFormatIDKey", appkit_cfstring_constant((CFStringRef) AVFormatIDKey), CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("AVSampleRateKey", appkit_cfstring_constant((CFStringRef) AVSampleRateKey), CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("AVNumberOfChannelsKey", appkit_cfstring_constant((CFStringRef) AVNumberOfChannelsKey), CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("AVLinearPCMBitDepthKey", appkit_cfstring_constant((CFStringRef) AVLinearPCMBitDepthKey), CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("AVLinearPCMIsFloatKey", appkit_cfstring_constant((CFStringRef) AVLinearPCMIsFloatKey), CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("AVLinearPCMIsBigEndianKey", appkit_cfstring_constant((CFStringRef) AVLinearPCMIsBigEndianKey), CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("AVLinearPCMIsNonInterleaved", appkit_cfstring_constant((CFStringRef) AVLinearPCMIsNonInterleaved), CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kAudioFormatLinearPCM", kAudioFormatLinearPCM, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kAudioFormatFlagIsFloat", kAudioFormatFlagIsFloat, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kAudioFormatFlagIsSignedInteger", kAudioFormatFlagIsSignedInteger, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kAudioFormatFlagIsPacked", kAudioFormatFlagIsPacked, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kAudioFormatFlagIsNonInterleaved", kAudioFormatFlagIsNonInterleaved, CONST_PERSISTENT);
}

static zend_class_entry *register_class_AVAsset(zend_class_entry *class_entry_NSObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVAsset", class_AVAsset_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_NSObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_AVURLAsset(zend_class_entry *class_entry_AVAsset)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVURLAsset", class_AVURLAsset_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_AVAsset, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_AVAssetTrack(zend_class_entry *class_entry_NSObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVAssetTrack", class_AVAssetTrack_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_NSObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_AVAssetReaderStatus(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("AVAssetReaderStatus", IS_LONG, NULL);

	zval enum_case_UNKNOWN_value;
	ZVAL_LONG(&enum_case_UNKNOWN_value, 0);
	zend_enum_add_case_cstr(class_entry, "UNKNOWN", &enum_case_UNKNOWN_value);

	zval enum_case_READING_value;
	ZVAL_LONG(&enum_case_READING_value, 1);
	zend_enum_add_case_cstr(class_entry, "READING", &enum_case_READING_value);

	zval enum_case_COMPLETED_value;
	ZVAL_LONG(&enum_case_COMPLETED_value, 2);
	zend_enum_add_case_cstr(class_entry, "COMPLETED", &enum_case_COMPLETED_value);

	zval enum_case_FAILED_value;
	ZVAL_LONG(&enum_case_FAILED_value, 3);
	zend_enum_add_case_cstr(class_entry, "FAILED", &enum_case_FAILED_value);

	zval enum_case_CANCELLED_value;
	ZVAL_LONG(&enum_case_CANCELLED_value, 4);
	zend_enum_add_case_cstr(class_entry, "CANCELLED", &enum_case_CANCELLED_value);

	return class_entry;
}

static zend_class_entry *register_class_AVAssetReaderOutput(zend_class_entry *class_entry_NSObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVAssetReaderOutput", class_AVAssetReaderOutput_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_NSObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_AVAssetReaderTrackOutput(zend_class_entry *class_entry_AVAssetReaderOutput)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVAssetReaderTrackOutput", class_AVAssetReaderTrackOutput_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_AVAssetReaderOutput, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_AVAssetReader(zend_class_entry *class_entry_NSObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVAssetReader", class_AVAssetReader_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_NSObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_AVPlayerItemStatus(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("AVPlayerItemStatus", IS_LONG, NULL);

	zval enum_case_UNKNOWN_value;
	ZVAL_LONG(&enum_case_UNKNOWN_value, 0);
	zend_enum_add_case_cstr(class_entry, "UNKNOWN", &enum_case_UNKNOWN_value);

	zval enum_case_READY_TO_PLAY_value;
	ZVAL_LONG(&enum_case_READY_TO_PLAY_value, 1);
	zend_enum_add_case_cstr(class_entry, "READY_TO_PLAY", &enum_case_READY_TO_PLAY_value);

	zval enum_case_FAILED_value;
	ZVAL_LONG(&enum_case_FAILED_value, 2);
	zend_enum_add_case_cstr(class_entry, "FAILED", &enum_case_FAILED_value);

	return class_entry;
}

static zend_class_entry *register_class_AVPlayerItem(zend_class_entry *class_entry_NSObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVPlayerItem", class_AVPlayerItem_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_NSObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_AVPlayerItemOutput(zend_class_entry *class_entry_NSObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVPlayerItemOutput", class_AVPlayerItemOutput_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_NSObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_AVPlayerItemVideoOutput(zend_class_entry *class_entry_AVPlayerItemOutput)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVPlayerItemVideoOutput", class_AVPlayerItemVideoOutput_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_AVPlayerItemOutput, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_AVPlayerTimeControlStatus(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("AVPlayerTimeControlStatus", IS_LONG, NULL);

	zval enum_case_PAUSED_value;
	ZVAL_LONG(&enum_case_PAUSED_value, 0);
	zend_enum_add_case_cstr(class_entry, "PAUSED", &enum_case_PAUSED_value);

	zval enum_case_WAITING_TO_PLAY_AT_SPECIFIED_RATE_value;
	ZVAL_LONG(&enum_case_WAITING_TO_PLAY_AT_SPECIFIED_RATE_value, 1);
	zend_enum_add_case_cstr(class_entry, "WAITING_TO_PLAY_AT_SPECIFIED_RATE", &enum_case_WAITING_TO_PLAY_AT_SPECIFIED_RATE_value);

	zval enum_case_PLAYING_value;
	ZVAL_LONG(&enum_case_PLAYING_value, 2);
	zend_enum_add_case_cstr(class_entry, "PLAYING", &enum_case_PLAYING_value);

	return class_entry;
}

static zend_class_entry *register_class_AVPlayerActionAtItemEnd(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("AVPlayerActionAtItemEnd", IS_LONG, NULL);

	zval enum_case_ADVANCE_value;
	ZVAL_LONG(&enum_case_ADVANCE_value, 0);
	zend_enum_add_case_cstr(class_entry, "ADVANCE", &enum_case_ADVANCE_value);

	zval enum_case_PAUSE_value;
	ZVAL_LONG(&enum_case_PAUSE_value, 1);
	zend_enum_add_case_cstr(class_entry, "PAUSE", &enum_case_PAUSE_value);

	zval enum_case_NONE_value;
	ZVAL_LONG(&enum_case_NONE_value, 2);
	zend_enum_add_case_cstr(class_entry, "NONE", &enum_case_NONE_value);

	return class_entry;
}

static zend_class_entry *register_class_AVPlayer(zend_class_entry *class_entry_NSObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVPlayer", class_AVPlayer_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_NSObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
