/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 87c7c2b397618b8eac98f95a686f1db5cb493947 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CVPixelBufferLockBaseAddress, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, pixelBuffer, CVPixelBuffer, 0)
	ZEND_ARG_TYPE_INFO(0, lockFlags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CVPixelBufferUnlockBaseAddress, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, pixelBuffer, CVPixelBuffer, 0)
	ZEND_ARG_TYPE_INFO(0, unlockFlags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CVPixelBufferGetBaseAddress, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, pixelBuffer, CVPixelBuffer, 0)
ZEND_END_ARG_INFO()

#define arginfo_CVPixelBufferGetBytesPerRow arginfo_CVPixelBufferGetBaseAddress

#define arginfo_CVPixelBufferGetWidth arginfo_CVPixelBufferGetBaseAddress

#define arginfo_CVPixelBufferGetHeight arginfo_CVPixelBufferGetBaseAddress

#define arginfo_CVPixelBufferGetPixelFormatType arginfo_CVPixelBufferGetBaseAddress

#define arginfo_CVPixelBufferGetDataSize arginfo_CVPixelBufferGetBaseAddress

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CVPixelBufferIsPlanar, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, pixelBuffer, CVPixelBuffer, 0)
ZEND_END_ARG_INFO()

#define arginfo_CVPixelBufferGetPlaneCount arginfo_CVPixelBufferGetBaseAddress

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CVPixelBufferGetBaseAddressOfPlane, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, pixelBuffer, CVPixelBuffer, 0)
	ZEND_ARG_TYPE_INFO(0, planeIndex, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_CVPixelBufferGetBytesPerRowOfPlane arginfo_CVPixelBufferGetBaseAddressOfPlane

#define arginfo_CVPixelBufferGetWidthOfPlane arginfo_CVPixelBufferGetBaseAddressOfPlane

#define arginfo_CVPixelBufferGetHeightOfPlane arginfo_CVPixelBufferGetBaseAddressOfPlane

ZEND_FUNCTION(CVPixelBufferLockBaseAddress);
ZEND_FUNCTION(CVPixelBufferUnlockBaseAddress);
ZEND_FUNCTION(CVPixelBufferGetBaseAddress);
ZEND_FUNCTION(CVPixelBufferGetBytesPerRow);
ZEND_FUNCTION(CVPixelBufferGetWidth);
ZEND_FUNCTION(CVPixelBufferGetHeight);
ZEND_FUNCTION(CVPixelBufferGetPixelFormatType);
ZEND_FUNCTION(CVPixelBufferGetDataSize);
ZEND_FUNCTION(CVPixelBufferIsPlanar);
ZEND_FUNCTION(CVPixelBufferGetPlaneCount);
ZEND_FUNCTION(CVPixelBufferGetBaseAddressOfPlane);
ZEND_FUNCTION(CVPixelBufferGetBytesPerRowOfPlane);
ZEND_FUNCTION(CVPixelBufferGetWidthOfPlane);
ZEND_FUNCTION(CVPixelBufferGetHeightOfPlane);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(CVPixelBufferLockBaseAddress, arginfo_CVPixelBufferLockBaseAddress)
	ZEND_FE(CVPixelBufferUnlockBaseAddress, arginfo_CVPixelBufferUnlockBaseAddress)
	ZEND_FE(CVPixelBufferGetBaseAddress, arginfo_CVPixelBufferGetBaseAddress)
	ZEND_FE(CVPixelBufferGetBytesPerRow, arginfo_CVPixelBufferGetBytesPerRow)
	ZEND_FE(CVPixelBufferGetWidth, arginfo_CVPixelBufferGetWidth)
	ZEND_FE(CVPixelBufferGetHeight, arginfo_CVPixelBufferGetHeight)
	ZEND_FE(CVPixelBufferGetPixelFormatType, arginfo_CVPixelBufferGetPixelFormatType)
	ZEND_FE(CVPixelBufferGetDataSize, arginfo_CVPixelBufferGetDataSize)
	ZEND_FE(CVPixelBufferIsPlanar, arginfo_CVPixelBufferIsPlanar)
	ZEND_FE(CVPixelBufferGetPlaneCount, arginfo_CVPixelBufferGetPlaneCount)
	ZEND_FE(CVPixelBufferGetBaseAddressOfPlane, arginfo_CVPixelBufferGetBaseAddressOfPlane)
	ZEND_FE(CVPixelBufferGetBytesPerRowOfPlane, arginfo_CVPixelBufferGetBytesPerRowOfPlane)
	ZEND_FE(CVPixelBufferGetWidthOfPlane, arginfo_CVPixelBufferGetWidthOfPlane)
	ZEND_FE(CVPixelBufferGetHeightOfPlane, arginfo_CVPixelBufferGetHeightOfPlane)
	ZEND_FE_END
};

static void register_CoreVideo_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("kCVPixelBufferLock_ReadOnly", kCVPixelBufferLock_ReadOnly, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kCVPixelFormatType_32BGRA", kCVPixelFormatType_32BGRA, CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("kCVPixelBufferPixelFormatTypeKey", appkit_cfstring_constant(kCVPixelBufferPixelFormatTypeKey), CONST_PERSISTENT);
}

static zend_class_entry *register_class_CVBuffer(zend_class_entry *class_entry_CFType)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "CVBuffer", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_CFType, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_CVImageBuffer(zend_class_entry *class_entry_CVBuffer)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "CVImageBuffer", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_CVBuffer, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_CVPixelBuffer(zend_class_entry *class_entry_CVImageBuffer)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "CVPixelBuffer", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_CVImageBuffer, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
