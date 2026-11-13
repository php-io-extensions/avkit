/*
 * avkit's classes are ext-appkit objects: appkit_object_setup gives them appkit's
 * object model (one PHP object per native object, retained while PHP holds it),
 * appkit_map_objc_class lets appkit's boxing find them, and APPKIT_BEGIN /
 * APPKIT_END turn an NSException into AppKitException.
 */

#ifndef AVKIT_RUNTIME_H
#define AVKIT_RUNTIME_H

#include "php_appkit_api.h"
#include "php_avkit.h"

#import <AVFoundation/AVFoundation.h>
#import <AVKit/AVKit.h>
#import <CoreMedia/CoreMedia.h>
#import <CoreVideo/CoreVideo.h>

/* Registers an avkit class on its appkit parent and lets appkit's boxing find it by its Objective-C class. */
#define AVKIT_MAP(name, parent) \
	avkit_ce_##name = register_class_##name(parent); \
	appkit_object_setup(avkit_ce_##name); \
	appkit_map_objc_class(#name, avkit_ce_##name)

extern zend_class_entry *avkit_ce_CMTime;
extern zend_class_entry *avkit_ce_AVPlayerItemStatus;
extern zend_class_entry *avkit_ce_AVPlayerItem;
extern zend_class_entry *avkit_ce_AVPlayerItemOutput;
extern zend_class_entry *avkit_ce_AVPlayerItemVideoOutput;
extern zend_class_entry *avkit_ce_AVPlayerTimeControlStatus;
extern zend_class_entry *avkit_ce_AVPlayerActionAtItemEnd;
extern zend_class_entry *avkit_ce_AVPlayer;
extern zend_class_entry *avkit_ce_AVPlayerViewControlsStyle;
extern zend_class_entry *avkit_ce_AVPlayerView;

extern zend_class_entry *avkit_ce_CMTimeRange;
extern zend_class_entry *avkit_ce_CMVideoDimensions;
extern zend_class_entry *avkit_ce_AudioStreamBasicDescription;
extern zend_class_entry *avkit_ce_CMSampleBuffer;
extern zend_class_entry *avkit_ce_CMBlockBuffer;
extern zend_class_entry *avkit_ce_CMFormatDescription;
extern zend_class_entry *avkit_ce_CMVideoFormatDescription;
extern zend_class_entry *avkit_ce_CMAudioFormatDescription;
extern zend_class_entry *avkit_ce_CVBuffer;
extern zend_class_entry *avkit_ce_CVImageBuffer;
extern zend_class_entry *avkit_ce_CVPixelBuffer;
extern zend_class_entry *avkit_ce_AVAsset;
extern zend_class_entry *avkit_ce_AVURLAsset;
extern zend_class_entry *avkit_ce_AVAssetTrack;
extern zend_class_entry *avkit_ce_AVAssetReaderStatus;
extern zend_class_entry *avkit_ce_AVAssetReaderOutput;
extern zend_class_entry *avkit_ce_AVAssetReaderTrackOutput;
extern zend_class_entry *avkit_ce_AVAssetReader;

void avkit_register_CoreVideo(int module_number);
void avkit_register_CoreMedia(int module_number);
void avkit_register_AVFoundation(int module_number);
void avkit_register_AVFAudio(int module_number);
void avkit_register_AVKit(int module_number);

/* Registers a CF type's class on its parent with appkit's object model; appkit_box_cf_as boxes it. */
#define AVKIT_CF(name, parent) \
	avkit_ce_##name = register_class_##name(parent); \
	appkit_object_setup(avkit_ce_##name)

/* CMTime value class: properties 0 = value, 1 = timescale, 2 = flags, 3 = epoch, as the struct. */
bool avkit_cmtime_from(zend_object *time, uint32_t arg_num, CMTime *out);
void avkit_cmtime_new(zval *rv, CMTime time);

/* CMTimeRange value class: properties 0 = start, 1 = duration, CMTime objects. */
bool avkit_cmtimerange_from(zend_object *range, uint32_t arg_num, CMTimeRange *out);
void avkit_cmtimerange_new(zval *rv, CMTimeRange range);

/* A CMFormatDescription boxed as CMVideoFormatDescription or CMAudioFormatDescription by its media type. */
void avkit_box_format_description(zval *rv, CMFormatDescriptionRef desc);
/* A CVImageBuffer boxed as CVPixelBuffer when it is one. */
void avkit_box_image_buffer(zval *rv, CVImageBufferRef buffer);

/*
 * The probe switch. A kept refusal site reads `if (!AVKIT_PROBE_OFF("<id>") && (<check>))`.
 * A build configured with --enable-avkit-probes lets env AVKIT_PROBE_OFF=<id> turn that one
 * site off, so tests/Probes can show the crash the site prevents; any other build compiles
 * the switch out.
 */
#ifdef AVKIT_PROBES
bool avkit_probe_off(const char *id);
# define AVKIT_PROBE_OFF(id) avkit_probe_off(id)
#else
# define AVKIT_PROBE_OFF(id) 0
#endif

#endif
