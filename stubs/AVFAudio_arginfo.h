/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 9d54cc31d25185693eeede99ceaa23a98a431d5f */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioFormat_initStandardFormatWithSampleRateChannels, 0, 2, IS_STATIC, 1)
	ZEND_ARG_TYPE_INFO(0, sampleRate, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, channels, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioFormat_initWithCommonFormatSampleRateChannelsInterleaved, 0, 4, IS_STATIC, 1)
	ZEND_ARG_OBJ_INFO(0, format, AVAudioCommonFormat, 0)
	ZEND_ARG_TYPE_INFO(0, sampleRate, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, channels, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, interleaved, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioFormat_initWithCMAudioFormatDescription, 0, 1, IS_STATIC, 0)
	ZEND_ARG_OBJ_INFO(0, formatDescription, CMAudioFormatDescription, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioFormat_isStandard, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAudioFormat_commonFormat, 0, 0, AVAudioCommonFormat, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioFormat_channelCount, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioFormat_sampleRate, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAudioFormat_isInterleaved arginfo_class_AVAudioFormat_isStandard

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAudioFormat_streamDescription, 0, 0, AudioStreamBasicDescription, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAudioFormat_formatDescription, 0, 0, CMAudioFormatDescription, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAudioBuffer_format, 0, 0, AVAudioFormat, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioPCMBuffer_initWithPCMFormatFrameCapacity, 0, 2, IS_STATIC, 1)
	ZEND_ARG_OBJ_INFO(0, format, AVAudioFormat, 0)
	ZEND_ARG_TYPE_INFO(0, frameCapacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAudioPCMBuffer_frameCapacity arginfo_class_AVAudioFormat_channelCount

#define arginfo_class_AVAudioPCMBuffer_frameLength arginfo_class_AVAudioFormat_channelCount

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioPCMBuffer_setFrameLength, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, frameLength, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAudioPCMBuffer_stride arginfo_class_AVAudioFormat_channelCount

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioPCMBuffer_floatChannelData, 0, 0, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAudioPCMBuffer_int16ChannelData arginfo_class_AVAudioPCMBuffer_floatChannelData

#define arginfo_class_AVAudioPCMBuffer_int32ChannelData arginfo_class_AVAudioPCMBuffer_floatChannelData

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioTime_timeWithHostTime, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, hostTime, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioTime_timeWithSampleTimeAtRate, 0, 2, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, sampleTime, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, sampleRate, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioTime_timeWithHostTimeSampleTimeAtRate, 0, 3, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, hostTime, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, sampleTime, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, sampleRate, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioTime_hostTimeForSeconds, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, seconds, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioTime_secondsForHostTime, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, hostTime, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAudioTime_extrapolateTimeFromAnchor, 0, 1, AVAudioTime, 1)
	ZEND_ARG_OBJ_INFO(0, anchorTime, AVAudioTime, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAudioTime_isHostTimeValid arginfo_class_AVAudioFormat_isStandard

#define arginfo_class_AVAudioTime_hostTime arginfo_class_AVAudioFormat_channelCount

#define arginfo_class_AVAudioTime_isSampleTimeValid arginfo_class_AVAudioFormat_isStandard

#define arginfo_class_AVAudioTime_sampleTime arginfo_class_AVAudioFormat_channelCount

#define arginfo_class_AVAudioTime_sampleRate arginfo_class_AVAudioFormat_sampleRate

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioNode_reset, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAudioNode_inputFormatForBus, 0, 1, AVAudioFormat, 0)
	ZEND_ARG_TYPE_INFO(0, bus, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAudioNode_outputFormatForBus arginfo_class_AVAudioNode_inputFormatForBus

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAudioNode_engine, 0, 0, AVAudioEngine, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAudioNode_numberOfInputs arginfo_class_AVAudioFormat_channelCount

#define arginfo_class_AVAudioNode_numberOfOutputs arginfo_class_AVAudioFormat_channelCount

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAudioNode_lastRenderTime, 0, 0, AVAudioTime, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAudioNode_latency arginfo_class_AVAudioFormat_sampleRate

#define arginfo_class_AVAudioNode_outputPresentationLatency arginfo_class_AVAudioFormat_sampleRate

#define arginfo_class_AVAudioIONode_presentationLatency arginfo_class_AVAudioFormat_sampleRate

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioMixerNode_init, 0, 0, IS_STATIC, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAudioMixerNode_outputVolume arginfo_class_AVAudioFormat_sampleRate

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioMixerNode_setOutputVolume, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, outputVolume, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAudioMixerNode_nextAvailableInputBus arginfo_class_AVAudioFormat_channelCount

#define arginfo_class_AVAudioMixerNode_volume arginfo_class_AVAudioFormat_sampleRate

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioMixerNode_setVolume, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, volume, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAudioMixerNode_pan arginfo_class_AVAudioFormat_sampleRate

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioMixerNode_setPan, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, pan, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAudioPlayerNode_init arginfo_class_AVAudioMixerNode_init

#define arginfo_class_AVAudioPlayerNode_stop arginfo_class_AVAudioNode_reset

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioPlayerNode_prepareWithFrameCount, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, frameCount, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAudioPlayerNode_play arginfo_class_AVAudioNode_reset

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioPlayerNode_playAtTime, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, when, AVAudioTime, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAudioPlayerNode_pause arginfo_class_AVAudioNode_reset

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAudioPlayerNode_nodeTimeForPlayerTime, 0, 1, AVAudioTime, 1)
	ZEND_ARG_OBJ_INFO(0, playerTime, AVAudioTime, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAudioPlayerNode_playerTimeForNodeTime, 0, 1, AVAudioTime, 1)
	ZEND_ARG_OBJ_INFO(0, nodeTime, AVAudioTime, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAudioPlayerNode_isPlaying arginfo_class_AVAudioFormat_isStandard

#define arginfo_class_AVAudioPlayerNode_volume arginfo_class_AVAudioFormat_sampleRate

#define arginfo_class_AVAudioPlayerNode_setVolume arginfo_class_AVAudioMixerNode_setVolume

#define arginfo_class_AVAudioPlayerNode_pan arginfo_class_AVAudioFormat_sampleRate

#define arginfo_class_AVAudioPlayerNode_setPan arginfo_class_AVAudioMixerNode_setPan

#define arginfo_class_AVAudioEngine_init arginfo_class_AVAudioMixerNode_init

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioEngine_attachNode, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, node, AVAudioNode, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAudioEngine_detachNode arginfo_class_AVAudioEngine_attachNode

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioEngine_connectToFromBusToBusFormat, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, node1, AVAudioNode, 0)
	ZEND_ARG_OBJ_INFO(0, node2, AVAudioNode, 0)
	ZEND_ARG_TYPE_INFO(0, bus1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, bus2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, format, AVAudioFormat, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioEngine_connectToFormat, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, node1, AVAudioNode, 0)
	ZEND_ARG_OBJ_INFO(0, node2, AVAudioNode, 0)
	ZEND_ARG_OBJ_INFO(0, format, AVAudioFormat, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioEngine_disconnectNodeInputBus, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, node, AVAudioNode, 0)
	ZEND_ARG_TYPE_INFO(0, bus, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAudioEngine_disconnectNodeInput arginfo_class_AVAudioEngine_attachNode

#define arginfo_class_AVAudioEngine_disconnectNodeOutputBus arginfo_class_AVAudioEngine_disconnectNodeInputBus

#define arginfo_class_AVAudioEngine_disconnectNodeOutput arginfo_class_AVAudioEngine_attachNode

#define arginfo_class_AVAudioEngine_prepare arginfo_class_AVAudioNode_reset

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioEngine_startAndReturnError, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(1, outError, NSError, 1, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_AVAudioEngine_pause arginfo_class_AVAudioNode_reset

#define arginfo_class_AVAudioEngine_reset arginfo_class_AVAudioNode_reset

#define arginfo_class_AVAudioEngine_stop arginfo_class_AVAudioNode_reset

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAudioEngine_outputNode, 0, 0, AVAudioOutputNode, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_AVAudioEngine_mainMixerNode, 0, 0, AVAudioMixerNode, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_AVAudioEngine_isRunning arginfo_class_AVAudioFormat_isStandard

#define arginfo_class_AVAudioEngine_isAutoShutdownEnabled arginfo_class_AVAudioFormat_isStandard

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AVAudioEngine_setAutoShutdownEnabled, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, autoShutdownEnabled, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(AVAudioFormat, initStandardFormatWithSampleRateChannels);
ZEND_METHOD(AVAudioFormat, initWithCommonFormatSampleRateChannelsInterleaved);
ZEND_METHOD(AVAudioFormat, initWithCMAudioFormatDescription);
ZEND_METHOD(AVAudioFormat, isStandard);
ZEND_METHOD(AVAudioFormat, commonFormat);
ZEND_METHOD(AVAudioFormat, channelCount);
ZEND_METHOD(AVAudioFormat, sampleRate);
ZEND_METHOD(AVAudioFormat, isInterleaved);
ZEND_METHOD(AVAudioFormat, streamDescription);
ZEND_METHOD(AVAudioFormat, formatDescription);
ZEND_METHOD(AVAudioBuffer, format);
ZEND_METHOD(AVAudioPCMBuffer, initWithPCMFormatFrameCapacity);
ZEND_METHOD(AVAudioPCMBuffer, frameCapacity);
ZEND_METHOD(AVAudioPCMBuffer, frameLength);
ZEND_METHOD(AVAudioPCMBuffer, setFrameLength);
ZEND_METHOD(AVAudioPCMBuffer, stride);
ZEND_METHOD(AVAudioPCMBuffer, floatChannelData);
ZEND_METHOD(AVAudioPCMBuffer, int16ChannelData);
ZEND_METHOD(AVAudioPCMBuffer, int32ChannelData);
ZEND_METHOD(AVAudioTime, timeWithHostTime);
ZEND_METHOD(AVAudioTime, timeWithSampleTimeAtRate);
ZEND_METHOD(AVAudioTime, timeWithHostTimeSampleTimeAtRate);
ZEND_METHOD(AVAudioTime, hostTimeForSeconds);
ZEND_METHOD(AVAudioTime, secondsForHostTime);
ZEND_METHOD(AVAudioTime, extrapolateTimeFromAnchor);
ZEND_METHOD(AVAudioTime, isHostTimeValid);
ZEND_METHOD(AVAudioTime, hostTime);
ZEND_METHOD(AVAudioTime, isSampleTimeValid);
ZEND_METHOD(AVAudioTime, sampleTime);
ZEND_METHOD(AVAudioTime, sampleRate);
ZEND_METHOD(AVAudioNode, reset);
ZEND_METHOD(AVAudioNode, inputFormatForBus);
ZEND_METHOD(AVAudioNode, outputFormatForBus);
ZEND_METHOD(AVAudioNode, engine);
ZEND_METHOD(AVAudioNode, numberOfInputs);
ZEND_METHOD(AVAudioNode, numberOfOutputs);
ZEND_METHOD(AVAudioNode, lastRenderTime);
ZEND_METHOD(AVAudioNode, latency);
ZEND_METHOD(AVAudioNode, outputPresentationLatency);
ZEND_METHOD(AVAudioIONode, presentationLatency);
ZEND_METHOD(AVAudioMixerNode, init);
ZEND_METHOD(AVAudioMixerNode, outputVolume);
ZEND_METHOD(AVAudioMixerNode, setOutputVolume);
ZEND_METHOD(AVAudioMixerNode, nextAvailableInputBus);
ZEND_METHOD(AVAudioMixerNode, volume);
ZEND_METHOD(AVAudioMixerNode, setVolume);
ZEND_METHOD(AVAudioMixerNode, pan);
ZEND_METHOD(AVAudioMixerNode, setPan);
ZEND_METHOD(AVAudioPlayerNode, init);
ZEND_METHOD(AVAudioPlayerNode, stop);
ZEND_METHOD(AVAudioPlayerNode, prepareWithFrameCount);
ZEND_METHOD(AVAudioPlayerNode, play);
ZEND_METHOD(AVAudioPlayerNode, playAtTime);
ZEND_METHOD(AVAudioPlayerNode, pause);
ZEND_METHOD(AVAudioPlayerNode, nodeTimeForPlayerTime);
ZEND_METHOD(AVAudioPlayerNode, playerTimeForNodeTime);
ZEND_METHOD(AVAudioPlayerNode, isPlaying);
ZEND_METHOD(AVAudioPlayerNode, volume);
ZEND_METHOD(AVAudioPlayerNode, setVolume);
ZEND_METHOD(AVAudioPlayerNode, pan);
ZEND_METHOD(AVAudioPlayerNode, setPan);
ZEND_METHOD(AVAudioEngine, init);
ZEND_METHOD(AVAudioEngine, attachNode);
ZEND_METHOD(AVAudioEngine, detachNode);
ZEND_METHOD(AVAudioEngine, connectToFromBusToBusFormat);
ZEND_METHOD(AVAudioEngine, connectToFormat);
ZEND_METHOD(AVAudioEngine, disconnectNodeInputBus);
ZEND_METHOD(AVAudioEngine, disconnectNodeInput);
ZEND_METHOD(AVAudioEngine, disconnectNodeOutputBus);
ZEND_METHOD(AVAudioEngine, disconnectNodeOutput);
ZEND_METHOD(AVAudioEngine, prepare);
ZEND_METHOD(AVAudioEngine, startAndReturnError);
ZEND_METHOD(AVAudioEngine, pause);
ZEND_METHOD(AVAudioEngine, reset);
ZEND_METHOD(AVAudioEngine, stop);
ZEND_METHOD(AVAudioEngine, outputNode);
ZEND_METHOD(AVAudioEngine, mainMixerNode);
ZEND_METHOD(AVAudioEngine, isRunning);
ZEND_METHOD(AVAudioEngine, isAutoShutdownEnabled);
ZEND_METHOD(AVAudioEngine, setAutoShutdownEnabled);

static const zend_function_entry class_AVAudioFormat_methods[] = {
	ZEND_ME(AVAudioFormat, initStandardFormatWithSampleRateChannels, arginfo_class_AVAudioFormat_initStandardFormatWithSampleRateChannels, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(AVAudioFormat, initWithCommonFormatSampleRateChannelsInterleaved, arginfo_class_AVAudioFormat_initWithCommonFormatSampleRateChannelsInterleaved, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(AVAudioFormat, initWithCMAudioFormatDescription, arginfo_class_AVAudioFormat_initWithCMAudioFormatDescription, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(AVAudioFormat, isStandard, arginfo_class_AVAudioFormat_isStandard, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioFormat, commonFormat, arginfo_class_AVAudioFormat_commonFormat, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioFormat, channelCount, arginfo_class_AVAudioFormat_channelCount, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioFormat, sampleRate, arginfo_class_AVAudioFormat_sampleRate, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioFormat, isInterleaved, arginfo_class_AVAudioFormat_isInterleaved, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioFormat, streamDescription, arginfo_class_AVAudioFormat_streamDescription, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioFormat, formatDescription, arginfo_class_AVAudioFormat_formatDescription, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_AVAudioBuffer_methods[] = {
	ZEND_ME(AVAudioBuffer, format, arginfo_class_AVAudioBuffer_format, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_AVAudioPCMBuffer_methods[] = {
	ZEND_ME(AVAudioPCMBuffer, initWithPCMFormatFrameCapacity, arginfo_class_AVAudioPCMBuffer_initWithPCMFormatFrameCapacity, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(AVAudioPCMBuffer, frameCapacity, arginfo_class_AVAudioPCMBuffer_frameCapacity, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioPCMBuffer, frameLength, arginfo_class_AVAudioPCMBuffer_frameLength, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioPCMBuffer, setFrameLength, arginfo_class_AVAudioPCMBuffer_setFrameLength, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioPCMBuffer, stride, arginfo_class_AVAudioPCMBuffer_stride, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioPCMBuffer, floatChannelData, arginfo_class_AVAudioPCMBuffer_floatChannelData, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioPCMBuffer, int16ChannelData, arginfo_class_AVAudioPCMBuffer_int16ChannelData, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioPCMBuffer, int32ChannelData, arginfo_class_AVAudioPCMBuffer_int32ChannelData, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_AVAudioTime_methods[] = {
	ZEND_ME(AVAudioTime, timeWithHostTime, arginfo_class_AVAudioTime_timeWithHostTime, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(AVAudioTime, timeWithSampleTimeAtRate, arginfo_class_AVAudioTime_timeWithSampleTimeAtRate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(AVAudioTime, timeWithHostTimeSampleTimeAtRate, arginfo_class_AVAudioTime_timeWithHostTimeSampleTimeAtRate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(AVAudioTime, hostTimeForSeconds, arginfo_class_AVAudioTime_hostTimeForSeconds, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(AVAudioTime, secondsForHostTime, arginfo_class_AVAudioTime_secondsForHostTime, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(AVAudioTime, extrapolateTimeFromAnchor, arginfo_class_AVAudioTime_extrapolateTimeFromAnchor, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioTime, isHostTimeValid, arginfo_class_AVAudioTime_isHostTimeValid, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioTime, hostTime, arginfo_class_AVAudioTime_hostTime, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioTime, isSampleTimeValid, arginfo_class_AVAudioTime_isSampleTimeValid, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioTime, sampleTime, arginfo_class_AVAudioTime_sampleTime, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioTime, sampleRate, arginfo_class_AVAudioTime_sampleRate, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_AVAudioNode_methods[] = {
	ZEND_ME(AVAudioNode, reset, arginfo_class_AVAudioNode_reset, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioNode, inputFormatForBus, arginfo_class_AVAudioNode_inputFormatForBus, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioNode, outputFormatForBus, arginfo_class_AVAudioNode_outputFormatForBus, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioNode, engine, arginfo_class_AVAudioNode_engine, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioNode, numberOfInputs, arginfo_class_AVAudioNode_numberOfInputs, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioNode, numberOfOutputs, arginfo_class_AVAudioNode_numberOfOutputs, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioNode, lastRenderTime, arginfo_class_AVAudioNode_lastRenderTime, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioNode, latency, arginfo_class_AVAudioNode_latency, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioNode, outputPresentationLatency, arginfo_class_AVAudioNode_outputPresentationLatency, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_AVAudioIONode_methods[] = {
	ZEND_ME(AVAudioIONode, presentationLatency, arginfo_class_AVAudioIONode_presentationLatency, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_AVAudioMixerNode_methods[] = {
	ZEND_ME(AVAudioMixerNode, init, arginfo_class_AVAudioMixerNode_init, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(AVAudioMixerNode, outputVolume, arginfo_class_AVAudioMixerNode_outputVolume, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioMixerNode, setOutputVolume, arginfo_class_AVAudioMixerNode_setOutputVolume, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioMixerNode, nextAvailableInputBus, arginfo_class_AVAudioMixerNode_nextAvailableInputBus, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioMixerNode, volume, arginfo_class_AVAudioMixerNode_volume, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioMixerNode, setVolume, arginfo_class_AVAudioMixerNode_setVolume, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioMixerNode, pan, arginfo_class_AVAudioMixerNode_pan, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioMixerNode, setPan, arginfo_class_AVAudioMixerNode_setPan, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_AVAudioPlayerNode_methods[] = {
	ZEND_ME(AVAudioPlayerNode, init, arginfo_class_AVAudioPlayerNode_init, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(AVAudioPlayerNode, stop, arginfo_class_AVAudioPlayerNode_stop, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioPlayerNode, prepareWithFrameCount, arginfo_class_AVAudioPlayerNode_prepareWithFrameCount, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioPlayerNode, play, arginfo_class_AVAudioPlayerNode_play, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioPlayerNode, playAtTime, arginfo_class_AVAudioPlayerNode_playAtTime, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioPlayerNode, pause, arginfo_class_AVAudioPlayerNode_pause, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioPlayerNode, nodeTimeForPlayerTime, arginfo_class_AVAudioPlayerNode_nodeTimeForPlayerTime, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioPlayerNode, playerTimeForNodeTime, arginfo_class_AVAudioPlayerNode_playerTimeForNodeTime, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioPlayerNode, isPlaying, arginfo_class_AVAudioPlayerNode_isPlaying, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioPlayerNode, volume, arginfo_class_AVAudioPlayerNode_volume, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioPlayerNode, setVolume, arginfo_class_AVAudioPlayerNode_setVolume, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioPlayerNode, pan, arginfo_class_AVAudioPlayerNode_pan, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioPlayerNode, setPan, arginfo_class_AVAudioPlayerNode_setPan, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_AVAudioEngine_methods[] = {
	ZEND_ME(AVAudioEngine, init, arginfo_class_AVAudioEngine_init, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(AVAudioEngine, attachNode, arginfo_class_AVAudioEngine_attachNode, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioEngine, detachNode, arginfo_class_AVAudioEngine_detachNode, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioEngine, connectToFromBusToBusFormat, arginfo_class_AVAudioEngine_connectToFromBusToBusFormat, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioEngine, connectToFormat, arginfo_class_AVAudioEngine_connectToFormat, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioEngine, disconnectNodeInputBus, arginfo_class_AVAudioEngine_disconnectNodeInputBus, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioEngine, disconnectNodeInput, arginfo_class_AVAudioEngine_disconnectNodeInput, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioEngine, disconnectNodeOutputBus, arginfo_class_AVAudioEngine_disconnectNodeOutputBus, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioEngine, disconnectNodeOutput, arginfo_class_AVAudioEngine_disconnectNodeOutput, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioEngine, prepare, arginfo_class_AVAudioEngine_prepare, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioEngine, startAndReturnError, arginfo_class_AVAudioEngine_startAndReturnError, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioEngine, pause, arginfo_class_AVAudioEngine_pause, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioEngine, reset, arginfo_class_AVAudioEngine_reset, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioEngine, stop, arginfo_class_AVAudioEngine_stop, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioEngine, outputNode, arginfo_class_AVAudioEngine_outputNode, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioEngine, mainMixerNode, arginfo_class_AVAudioEngine_mainMixerNode, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioEngine, isRunning, arginfo_class_AVAudioEngine_isRunning, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioEngine, isAutoShutdownEnabled, arginfo_class_AVAudioEngine_isAutoShutdownEnabled, ZEND_ACC_PUBLIC)
	ZEND_ME(AVAudioEngine, setAutoShutdownEnabled, arginfo_class_AVAudioEngine_setAutoShutdownEnabled, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static void register_AVFAudio_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("AVAudioPlayerNodeBufferLoops", AVAudioPlayerNodeBufferLoops, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("AVAudioPlayerNodeBufferInterrupts", AVAudioPlayerNodeBufferInterrupts, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("AVAudioPlayerNodeBufferInterruptsAtLoop", AVAudioPlayerNodeBufferInterruptsAtLoop, CONST_PERSISTENT);
}

static zend_class_entry *register_class_AVAudioCommonFormat(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("AVAudioCommonFormat", IS_LONG, NULL);

	zval enum_case_OTHER_FORMAT_value;
	ZVAL_LONG(&enum_case_OTHER_FORMAT_value, 0);
	zend_enum_add_case_cstr(class_entry, "OTHER_FORMAT", &enum_case_OTHER_FORMAT_value);

	zval enum_case_PCM_FORMAT_FLOAT32_value;
	ZVAL_LONG(&enum_case_PCM_FORMAT_FLOAT32_value, 1);
	zend_enum_add_case_cstr(class_entry, "PCM_FORMAT_FLOAT32", &enum_case_PCM_FORMAT_FLOAT32_value);

	zval enum_case_PCM_FORMAT_FLOAT64_value;
	ZVAL_LONG(&enum_case_PCM_FORMAT_FLOAT64_value, 2);
	zend_enum_add_case_cstr(class_entry, "PCM_FORMAT_FLOAT64", &enum_case_PCM_FORMAT_FLOAT64_value);

	zval enum_case_PCM_FORMAT_INT16_value;
	ZVAL_LONG(&enum_case_PCM_FORMAT_INT16_value, 3);
	zend_enum_add_case_cstr(class_entry, "PCM_FORMAT_INT16", &enum_case_PCM_FORMAT_INT16_value);

	zval enum_case_PCM_FORMAT_INT32_value;
	ZVAL_LONG(&enum_case_PCM_FORMAT_INT32_value, 4);
	zend_enum_add_case_cstr(class_entry, "PCM_FORMAT_INT32", &enum_case_PCM_FORMAT_INT32_value);

	return class_entry;
}

static zend_class_entry *register_class_AVAudioFormat(zend_class_entry *class_entry_NSObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVAudioFormat", class_AVAudioFormat_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_NSObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_AVAudioBuffer(zend_class_entry *class_entry_NSObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVAudioBuffer", class_AVAudioBuffer_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_NSObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_AVAudioPCMBuffer(zend_class_entry *class_entry_AVAudioBuffer)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVAudioPCMBuffer", class_AVAudioPCMBuffer_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_AVAudioBuffer, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_AVAudioTime(zend_class_entry *class_entry_NSObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVAudioTime", class_AVAudioTime_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_NSObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_AVAudioNode(zend_class_entry *class_entry_NSObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVAudioNode", class_AVAudioNode_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_NSObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_AVAudioIONode(zend_class_entry *class_entry_AVAudioNode)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVAudioIONode", class_AVAudioIONode_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_AVAudioNode, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_AVAudioOutputNode(zend_class_entry *class_entry_AVAudioIONode)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVAudioOutputNode", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_AVAudioIONode, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_AVAudioMixerNode(zend_class_entry *class_entry_AVAudioNode)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVAudioMixerNode", class_AVAudioMixerNode_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_AVAudioNode, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_AVAudioPlayerNode(zend_class_entry *class_entry_AVAudioNode)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVAudioPlayerNode", class_AVAudioPlayerNode_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_AVAudioNode, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_AVAudioEngine(zend_class_entry *class_entry_NSObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "AVAudioEngine", class_AVAudioEngine_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_NSObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
