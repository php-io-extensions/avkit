#include "runtime.h"
#include "../stubs/CoreVideo_arginfo.h"

zend_class_entry *avkit_ce_CVBuffer;
zend_class_entry *avkit_ce_CVImageBuffer;
zend_class_entry *avkit_ce_CVPixelBuffer;

void avkit_register_CoreVideo(int module_number)
{
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);
	register_CoreVideo_symbols(module_number);
	AVKIT_CF(CVBuffer, appkit_ce_CFType);
	AVKIT_CF(CVImageBuffer, avkit_ce_CVBuffer);
	AVKIT_CF(CVPixelBuffer, avkit_ce_CVImageBuffer);
}

void avkit_box_image_buffer(zval *rv, CVImageBufferRef buffer)
{
	zend_class_entry *ce = buffer != NULL && CFGetTypeID(buffer) == CVPixelBufferGetTypeID() ? avkit_ce_CVPixelBuffer : avkit_ce_CVImageBuffer;

	appkit_box_cf_as(rv, buffer, ce);
}

#define PIXEL_BUFFER(obj) ((CVPixelBufferRef) APPKIT_CF(obj))

#define PARSE_PIXEL_BUFFER \
	zend_object *buffer; \
	ZEND_PARSE_PARAMETERS_START(1, 1) \
		Z_PARAM_OBJ_OF_CLASS(buffer, avkit_ce_CVPixelBuffer) \
	ZEND_PARSE_PARAMETERS_END();

#define PARSE_PIXEL_BUFFER_AND_LONG \
	zend_object *buffer; \
	zend_long n; \
	ZEND_PARSE_PARAMETERS_START(2, 2) \
		Z_PARAM_OBJ_OF_CLASS(buffer, avkit_ce_CVPixelBuffer) \
		Z_PARAM_LONG(n) \
	ZEND_PARSE_PARAMETERS_END();

ZEND_FUNCTION(CVPixelBufferLockBaseAddress)
{
	PARSE_PIXEL_BUFFER_AND_LONG
	RETURN_LONG((zend_long) CVPixelBufferLockBaseAddress(PIXEL_BUFFER(buffer), (CVPixelBufferLockFlags) n));
}

ZEND_FUNCTION(CVPixelBufferUnlockBaseAddress)
{
	PARSE_PIXEL_BUFFER_AND_LONG
	RETURN_LONG((zend_long) CVPixelBufferUnlockBaseAddress(PIXEL_BUFFER(buffer), (CVPixelBufferLockFlags) n));
}

ZEND_FUNCTION(CVPixelBufferGetBaseAddress)
{
	PARSE_PIXEL_BUFFER
	RETURN_LONG((zend_long) (uintptr_t) CVPixelBufferGetBaseAddress(PIXEL_BUFFER(buffer)));
}

ZEND_FUNCTION(CVPixelBufferGetBytesPerRow)
{
	PARSE_PIXEL_BUFFER
	RETURN_LONG((zend_long) CVPixelBufferGetBytesPerRow(PIXEL_BUFFER(buffer)));
}

ZEND_FUNCTION(CVPixelBufferGetWidth)
{
	PARSE_PIXEL_BUFFER
	RETURN_LONG((zend_long) CVPixelBufferGetWidth(PIXEL_BUFFER(buffer)));
}

ZEND_FUNCTION(CVPixelBufferGetHeight)
{
	PARSE_PIXEL_BUFFER
	RETURN_LONG((zend_long) CVPixelBufferGetHeight(PIXEL_BUFFER(buffer)));
}

ZEND_FUNCTION(CVPixelBufferGetPixelFormatType)
{
	PARSE_PIXEL_BUFFER
	RETURN_LONG((zend_long) CVPixelBufferGetPixelFormatType(PIXEL_BUFFER(buffer)));
}

ZEND_FUNCTION(CVPixelBufferGetDataSize)
{
	PARSE_PIXEL_BUFFER
	RETURN_LONG((zend_long) CVPixelBufferGetDataSize(PIXEL_BUFFER(buffer)));
}

ZEND_FUNCTION(CVPixelBufferIsPlanar)
{
	PARSE_PIXEL_BUFFER
	RETURN_BOOL(CVPixelBufferIsPlanar(PIXEL_BUFFER(buffer)));
}

ZEND_FUNCTION(CVPixelBufferGetPlaneCount)
{
	PARSE_PIXEL_BUFFER
	RETURN_LONG((zend_long) CVPixelBufferGetPlaneCount(PIXEL_BUFFER(buffer)));
}

ZEND_FUNCTION(CVPixelBufferGetBaseAddressOfPlane)
{
	PARSE_PIXEL_BUFFER_AND_LONG
	RETURN_LONG((zend_long) (uintptr_t) CVPixelBufferGetBaseAddressOfPlane(PIXEL_BUFFER(buffer), (size_t) n));
}

ZEND_FUNCTION(CVPixelBufferGetBytesPerRowOfPlane)
{
	PARSE_PIXEL_BUFFER_AND_LONG
	RETURN_LONG((zend_long) CVPixelBufferGetBytesPerRowOfPlane(PIXEL_BUFFER(buffer), (size_t) n));
}

ZEND_FUNCTION(CVPixelBufferGetWidthOfPlane)
{
	PARSE_PIXEL_BUFFER_AND_LONG
	RETURN_LONG((zend_long) CVPixelBufferGetWidthOfPlane(PIXEL_BUFFER(buffer), (size_t) n));
}

ZEND_FUNCTION(CVPixelBufferGetHeightOfPlane)
{
	PARSE_PIXEL_BUFFER_AND_LONG
	RETURN_LONG((zend_long) CVPixelBufferGetHeightOfPlane(PIXEL_BUFFER(buffer), (size_t) n));
}
