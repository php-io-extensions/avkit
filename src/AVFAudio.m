#include "runtime.h"
#include "../stubs/AVFAudio_arginfo.h"

_Static_assert(AVAudioOtherFormat == 0 && AVAudioPCMFormatFloat32 == 1 && AVAudioPCMFormatFloat64 == 2
	&& AVAudioPCMFormatInt16 == 3 && AVAudioPCMFormatInt32 == 4, "AVAudioCommonFormat values moved");

zend_class_entry *avkit_ce_AVAudioCommonFormat;
zend_class_entry *avkit_ce_AVAudioFormat;
zend_class_entry *avkit_ce_AVAudioBuffer;
zend_class_entry *avkit_ce_AVAudioPCMBuffer;
zend_class_entry *avkit_ce_AVAudioTime;
zend_class_entry *avkit_ce_AVAudioNode;
zend_class_entry *avkit_ce_AVAudioIONode;
zend_class_entry *avkit_ce_AVAudioOutputNode;
zend_class_entry *avkit_ce_AVAudioMixerNode;
zend_class_entry *avkit_ce_AVAudioPlayerNode;
zend_class_entry *avkit_ce_AVAudioEngine;

void avkit_register_AVFAudio(int module_number)
{
	register_AVFAudio_symbols(module_number);

	avkit_ce_AVAudioCommonFormat = register_class_AVAudioCommonFormat();
	AVKIT_MAP(AVAudioFormat, appkit_ce_NSObject);
	AVKIT_MAP(AVAudioBuffer, appkit_ce_NSObject);
	AVKIT_MAP(AVAudioPCMBuffer, avkit_ce_AVAudioBuffer);
	AVKIT_MAP(AVAudioTime, appkit_ce_NSObject);
	AVKIT_MAP(AVAudioNode, appkit_ce_NSObject);
	AVKIT_MAP(AVAudioIONode, avkit_ce_AVAudioNode);
	AVKIT_MAP(AVAudioOutputNode, avkit_ce_AVAudioIONode);
	AVKIT_MAP(AVAudioMixerNode, avkit_ce_AVAudioNode);
	AVKIT_MAP(AVAudioPlayerNode, avkit_ce_AVAudioNode);
	AVKIT_MAP(AVAudioEngine, appkit_ce_NSObject);
}

/* AVAudioFormat */
ZEND_METHOD(AVAudioFormat, initStandardFormatWithSampleRateChannels)
{
	double rate;
	zend_long channels;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_DOUBLE(rate)
		Z_PARAM_LONG(channels)
	ZEND_PARSE_PARAMETERS_END();

	APPKIT_BEGIN
		AVAudioFormat *made = [[CALLED alloc] initStandardFormatWithSampleRate:rate channels:(AVAudioChannelCount) channels];
		appkit_box_objc(return_value, made);
		[made release];
	APPKIT_END
}
ZEND_METHOD(AVAudioFormat, initWithCommonFormatSampleRateChannelsInterleaved)
{
	zend_object *format;
	double rate;
	zend_long channels;
	bool interleaved;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJ_OF_CLASS(format, avkit_ce_AVAudioCommonFormat)
		Z_PARAM_DOUBLE(rate)
		Z_PARAM_LONG(channels)
		Z_PARAM_BOOL(interleaved)
	ZEND_PARSE_PARAMETERS_END();

	APPKIT_BEGIN
		AVAudioFormat *made = [[CALLED alloc] initWithCommonFormat:(AVAudioCommonFormat) appkit_enum_value(format, 0)
			sampleRate:rate channels:(AVAudioChannelCount) channels interleaved:interleaved];
		appkit_box_objc(return_value, made);
		[made release];
	APPKIT_END
}
ZEND_METHOD(AVAudioFormat, initWithCMAudioFormatDescription)
{
	zend_object *desc;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(desc, avkit_ce_CMAudioFormatDescription)
	ZEND_PARSE_PARAMETERS_END();

	APPKIT_BEGIN
		AVAudioFormat *made = [[CALLED alloc] initWithCMAudioFormatDescription:(CMAudioFormatDescriptionRef) APPKIT_CF(desc)];
		appkit_box_objc(return_value, made);
		[made release];
	APPKIT_END
}
ANY_BOOL_GET(AVAudioFormat, AVAudioFormat, isStandard, isStandard)
ANY_ENUM_GET(AVAudioFormat, AVAudioFormat, commonFormat, commonFormat, avkit_ce_AVAudioCommonFormat, false)
ANY_LONG_GET(AVAudioFormat, AVAudioFormat, channelCount, channelCount)
ANY_DOUBLE_GET(AVAudioFormat, AVAudioFormat, sampleRate, sampleRate)
ANY_BOOL_GET(AVAudioFormat, AVAudioFormat, isInterleaved, isInterleaved)
ZEND_METHOD(AVAudioFormat, streamDescription)
{
	ZEND_PARSE_PARAMETERS_NONE();

	APPKIT_BEGIN
		const AudioStreamBasicDescription *asbd = [SELF(AVAudioFormat) streamDescription];

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
	APPKIT_END
}
ANY_METHOD(AVAudioFormat, formatDescription, PARSE_NONE, appkit_box_cf_as(return_value, [SELF(AVAudioFormat) formatDescription], avkit_ce_CMAudioFormatDescription);)

/* AVAudioBuffer */
ANY_OBJ_GET(AVAudioBuffer, AVAudioBuffer, format, format)

/* AVAudioPCMBuffer */
ZEND_METHOD(AVAudioPCMBuffer, initWithPCMFormatFrameCapacity)
{
	zend_object *format;
	zend_long capacity;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(format, avkit_ce_AVAudioFormat)
		Z_PARAM_LONG(capacity)
	ZEND_PARSE_PARAMETERS_END();

	APPKIT_BEGIN
		AVAudioPCMBuffer *made = [[CALLED alloc] initWithPCMFormat:(AVAudioFormat *) APPKIT_ID(format) frameCapacity:(AVAudioFrameCount) capacity];
		appkit_box_objc(return_value, made);
		[made release];
	APPKIT_END
}
ANY_LONG_GET(AVAudioPCMBuffer, AVAudioPCMBuffer, frameCapacity, frameCapacity)
ANY_LONG_GET(AVAudioPCMBuffer, AVAudioPCMBuffer, frameLength, frameLength)
ANY_LONG_SET(AVAudioPCMBuffer, AVAudioPCMBuffer, setFrameLength, setFrameLength, AVAudioFrameCount)
ANY_LONG_GET(AVAudioPCMBuffer, AVAudioPCMBuffer, stride, stride)

/* The channel pointers as addresses: one per channel, or one in all for an interleaved buffer. */
static void avkit_return_channels(zval *rv, AVAudioPCMBuffer *buffer, void *const *channels)
{
	if (channels == NULL) {
		ZVAL_NULL(rv);
		return;
	}
	AVAudioFormat *format = [buffer format];
	AVAudioChannelCount count = [format isInterleaved] ? 1 : [format channelCount];

	array_init_size(rv, count);
	for (AVAudioChannelCount i = 0; i < count; i++) {
		add_next_index_long(rv, (zend_long) (uintptr_t) channels[i]);
	}
}
ANY_METHOD(AVAudioPCMBuffer, floatChannelData, PARSE_NONE, avkit_return_channels(return_value, SELF(AVAudioPCMBuffer), (void *const *) [SELF(AVAudioPCMBuffer) floatChannelData]);)
ANY_METHOD(AVAudioPCMBuffer, int16ChannelData, PARSE_NONE, avkit_return_channels(return_value, SELF(AVAudioPCMBuffer), (void *const *) [SELF(AVAudioPCMBuffer) int16ChannelData]);)
ANY_METHOD(AVAudioPCMBuffer, int32ChannelData, PARSE_NONE, avkit_return_channels(return_value, SELF(AVAudioPCMBuffer), (void *const *) [SELF(AVAudioPCMBuffer) int32ChannelData]);)

/* AVAudioTime */
ANY_METHOD(AVAudioTime, timeWithHostTime, PARSE_LONG, appkit_box_objc(return_value, [CALLED timeWithHostTime:(uint64_t) v]);)
ZEND_METHOD(AVAudioTime, timeWithSampleTimeAtRate)
{
	zend_long sample_time;
	double rate;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(sample_time)
		Z_PARAM_DOUBLE(rate)
	ZEND_PARSE_PARAMETERS_END();

	APPKIT_BEGIN
		appkit_box_objc(return_value, [CALLED timeWithSampleTime:(AVAudioFramePosition) sample_time atRate:rate]);
	APPKIT_END
}
ZEND_METHOD(AVAudioTime, timeWithHostTimeSampleTimeAtRate)
{
	zend_long host_time, sample_time;
	double rate;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(host_time)
		Z_PARAM_LONG(sample_time)
		Z_PARAM_DOUBLE(rate)
	ZEND_PARSE_PARAMETERS_END();

	APPKIT_BEGIN
		appkit_box_objc(return_value, [CALLED timeWithHostTime:(uint64_t) host_time sampleTime:(AVAudioFramePosition) sample_time atRate:rate]);
	APPKIT_END
}
ANY_METHOD(AVAudioTime, hostTimeForSeconds, PARSE_DOUBLE, RETURN_LONG((zend_long) [CALLED hostTimeForSeconds:v]);)
ANY_METHOD(AVAudioTime, secondsForHostTime, PARSE_LONG, RETURN_DOUBLE([CALLED secondsForHostTime:(uint64_t) v]);)
ANY_METHOD(AVAudioTime, extrapolateTimeFromAnchor, PARSE_OBJ(avkit_ce_AVAudioTime), appkit_box_objc(return_value, [SELF(AVAudioTime) extrapolateTimeFromAnchor:(AVAudioTime *) APPKIT_ID(v)]);)
ANY_BOOL_GET(AVAudioTime, AVAudioTime, isHostTimeValid, isHostTimeValid)
ANY_LONG_GET(AVAudioTime, AVAudioTime, hostTime, hostTime)
ANY_BOOL_GET(AVAudioTime, AVAudioTime, isSampleTimeValid, isSampleTimeValid)
ANY_LONG_GET(AVAudioTime, AVAudioTime, sampleTime, sampleTime)
ANY_DOUBLE_GET(AVAudioTime, AVAudioTime, sampleRate, sampleRate)

/* AVAudioNode */
ANY_VOID_METHOD(AVAudioNode, AVAudioNode, reset, reset)
ANY_METHOD(AVAudioNode, inputFormatForBus, PARSE_LONG, appkit_box_objc(return_value, [SELF(AVAudioNode) inputFormatForBus:(AVAudioNodeBus) v]);)
ANY_METHOD(AVAudioNode, outputFormatForBus, PARSE_LONG, appkit_box_objc(return_value, [SELF(AVAudioNode) outputFormatForBus:(AVAudioNodeBus) v]);)
ANY_OBJ_GET(AVAudioNode, AVAudioNode, engine, engine)
ANY_LONG_GET(AVAudioNode, AVAudioNode, numberOfInputs, numberOfInputs)
ANY_LONG_GET(AVAudioNode, AVAudioNode, numberOfOutputs, numberOfOutputs)
ANY_OBJ_GET(AVAudioNode, AVAudioNode, lastRenderTime, lastRenderTime)
ANY_DOUBLE_GET(AVAudioNode, AVAudioNode, latency, latency)
ANY_DOUBLE_GET(AVAudioNode, AVAudioNode, outputPresentationLatency, outputPresentationLatency)

/* AVAudioIONode */
ANY_DOUBLE_GET(AVAudioIONode, AVAudioIONode, presentationLatency, presentationLatency)

/* AVAudioMixerNode */
ZEND_METHOD(AVAudioMixerNode, init)
{
	ZEND_PARSE_PARAMETERS_NONE();

	APPKIT_BEGIN
		AVAudioMixerNode *made = [[CALLED alloc] init];
		appkit_box_objc(return_value, made);
		[made release];
	APPKIT_END
}
ANY_DOUBLE_GET(AVAudioMixerNode, AVAudioMixerNode, outputVolume, outputVolume)
ANY_METHOD(AVAudioMixerNode, setOutputVolume, PARSE_DOUBLE, [SELF(AVAudioMixerNode) setOutputVolume:(float) v];)
ANY_LONG_GET(AVAudioMixerNode, AVAudioMixerNode, nextAvailableInputBus, nextAvailableInputBus)
ANY_DOUBLE_GET(AVAudioMixerNode, AVAudioMixerNode, volume, volume)
ANY_METHOD(AVAudioMixerNode, setVolume, PARSE_DOUBLE, [SELF(AVAudioMixerNode) setVolume:(float) v];)
ANY_DOUBLE_GET(AVAudioMixerNode, AVAudioMixerNode, pan, pan)
ANY_METHOD(AVAudioMixerNode, setPan, PARSE_DOUBLE, [SELF(AVAudioMixerNode) setPan:(float) v];)

/* AVAudioPlayerNode */
ZEND_METHOD(AVAudioPlayerNode, init)
{
	ZEND_PARSE_PARAMETERS_NONE();

	APPKIT_BEGIN
		AVAudioPlayerNode *made = [[CALLED alloc] init];
		appkit_box_objc(return_value, made);
		[made release];
	APPKIT_END
}
ANY_VOID_METHOD(AVAudioPlayerNode, AVAudioPlayerNode, stop, stop)
ANY_LONG_SET(AVAudioPlayerNode, AVAudioPlayerNode, prepareWithFrameCount, prepareWithFrameCount, AVAudioFrameCount)
ANY_VOID_METHOD(AVAudioPlayerNode, AVAudioPlayerNode, play, play)
ANY_OBJ_SET_OR_NULL(AVAudioPlayerNode, AVAudioPlayerNode, playAtTime, playAtTime, avkit_ce_AVAudioTime, AVAudioTime *)
ANY_VOID_METHOD(AVAudioPlayerNode, AVAudioPlayerNode, pause, pause)
ANY_METHOD(AVAudioPlayerNode, nodeTimeForPlayerTime, PARSE_OBJ(avkit_ce_AVAudioTime), appkit_box_objc(return_value, [SELF(AVAudioPlayerNode) nodeTimeForPlayerTime:(AVAudioTime *) APPKIT_ID(v)]);)
ANY_METHOD(AVAudioPlayerNode, playerTimeForNodeTime, PARSE_OBJ(avkit_ce_AVAudioTime), appkit_box_objc(return_value, [SELF(AVAudioPlayerNode) playerTimeForNodeTime:(AVAudioTime *) APPKIT_ID(v)]);)
ANY_BOOL_GET(AVAudioPlayerNode, AVAudioPlayerNode, isPlaying, isPlaying)
ANY_DOUBLE_GET(AVAudioPlayerNode, AVAudioPlayerNode, volume, volume)
ANY_METHOD(AVAudioPlayerNode, setVolume, PARSE_DOUBLE, [SELF(AVAudioPlayerNode) setVolume:(float) v];)
ANY_DOUBLE_GET(AVAudioPlayerNode, AVAudioPlayerNode, pan, pan)
ANY_METHOD(AVAudioPlayerNode, setPan, PARSE_DOUBLE, [SELF(AVAudioPlayerNode) setPan:(float) v];)

/* AVAudioEngine */
ZEND_METHOD(AVAudioEngine, init)
{
	ZEND_PARSE_PARAMETERS_NONE();

	APPKIT_BEGIN
		AVAudioEngine *made = [[CALLED alloc] init];
		appkit_box_objc(return_value, made);
		[made release];
	APPKIT_END
}
ANY_OBJ_SET(AVAudioEngine, AVAudioEngine, attachNode, attachNode, avkit_ce_AVAudioNode, AVAudioNode *)
ANY_OBJ_SET(AVAudioEngine, AVAudioEngine, detachNode, detachNode, avkit_ce_AVAudioNode, AVAudioNode *)
ZEND_METHOD(AVAudioEngine, connectToFromBusToBusFormat)
{
	zend_object *node1, *node2, *format = NULL;
	zend_long bus1, bus2;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJ_OF_CLASS(node1, avkit_ce_AVAudioNode)
		Z_PARAM_OBJ_OF_CLASS(node2, avkit_ce_AVAudioNode)
		Z_PARAM_LONG(bus1)
		Z_PARAM_LONG(bus2)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(format, avkit_ce_AVAudioFormat)
	ZEND_PARSE_PARAMETERS_END();

	APPKIT_BEGIN
		[SELF(AVAudioEngine) connect:(AVAudioNode *) APPKIT_ID(node1) to:(AVAudioNode *) APPKIT_ID(node2)
			fromBus:(AVAudioNodeBus) bus1 toBus:(AVAudioNodeBus) bus2 format:(AVAudioFormat *) OPTIONAL_ID(format)];
	APPKIT_END
}
ZEND_METHOD(AVAudioEngine, connectToFormat)
{
	zend_object *node1, *node2, *format = NULL;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(node1, avkit_ce_AVAudioNode)
		Z_PARAM_OBJ_OF_CLASS(node2, avkit_ce_AVAudioNode)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(format, avkit_ce_AVAudioFormat)
	ZEND_PARSE_PARAMETERS_END();

	APPKIT_BEGIN
		[SELF(AVAudioEngine) connect:(AVAudioNode *) APPKIT_ID(node1) to:(AVAudioNode *) APPKIT_ID(node2) format:(AVAudioFormat *) OPTIONAL_ID(format)];
	APPKIT_END
}
ZEND_METHOD(AVAudioEngine, disconnectNodeInputBus)
{
	zend_object *node;
	zend_long bus;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(node, avkit_ce_AVAudioNode)
		Z_PARAM_LONG(bus)
	ZEND_PARSE_PARAMETERS_END();

	APPKIT_BEGIN
		[SELF(AVAudioEngine) disconnectNodeInput:(AVAudioNode *) APPKIT_ID(node) bus:(AVAudioNodeBus) bus];
	APPKIT_END
}
ANY_OBJ_SET(AVAudioEngine, AVAudioEngine, disconnectNodeInput, disconnectNodeInput, avkit_ce_AVAudioNode, AVAudioNode *)
ZEND_METHOD(AVAudioEngine, disconnectNodeOutputBus)
{
	zend_object *node;
	zend_long bus;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(node, avkit_ce_AVAudioNode)
		Z_PARAM_LONG(bus)
	ZEND_PARSE_PARAMETERS_END();

	APPKIT_BEGIN
		[SELF(AVAudioEngine) disconnectNodeOutput:(AVAudioNode *) APPKIT_ID(node) bus:(AVAudioNodeBus) bus];
	APPKIT_END
}
ANY_OBJ_SET(AVAudioEngine, AVAudioEngine, disconnectNodeOutput, disconnectNodeOutput, avkit_ce_AVAudioNode, AVAudioNode *)
ANY_VOID_METHOD(AVAudioEngine, AVAudioEngine, prepare, prepare)
ZEND_METHOD(AVAudioEngine, startAndReturnError)
{
	zval *error_ref = NULL;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(error_ref)
	ZEND_PARSE_PARAMETERS_END();

	APPKIT_BEGIN
		NSError *error = nil;

		RETVAL_BOOL([SELF(AVAudioEngine) startAndReturnError:&error]);
		if (error_ref != NULL) {
			zval boxed;
			appkit_box_objc(&boxed, error);
			ZEND_TRY_ASSIGN_REF_TMP(error_ref, &boxed);
		}
	APPKIT_END
}
ANY_VOID_METHOD(AVAudioEngine, AVAudioEngine, pause, pause)
ANY_VOID_METHOD(AVAudioEngine, AVAudioEngine, reset, reset)
ANY_VOID_METHOD(AVAudioEngine, AVAudioEngine, stop, stop)
ANY_OBJ_GET(AVAudioEngine, AVAudioEngine, outputNode, outputNode)
ANY_OBJ_GET(AVAudioEngine, AVAudioEngine, mainMixerNode, mainMixerNode)
ANY_BOOL_GET(AVAudioEngine, AVAudioEngine, isRunning, isRunning)
ANY_BOOL_GET(AVAudioEngine, AVAudioEngine, isAutoShutdownEnabled, isAutoShutdownEnabled)
ANY_BOOL_SET(AVAudioEngine, AVAudioEngine, setAutoShutdownEnabled, setAutoShutdownEnabled)
