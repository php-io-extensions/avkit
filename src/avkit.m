#include "runtime.h"
#include "ext/standard/info.h"

#ifdef AVKIT_PROBES
bool avkit_probe_off(const char *id)
{
	const char *off = getenv("AVKIT_PROBE_OFF");

	return off != NULL && strcmp(off, id) == 0;
}
#endif

PHP_MINIT_FUNCTION(avkit)
{
#ifdef AVKIT_PROBES
	REGISTER_BOOL_CONSTANT("AVKIT_PROBES", true, CONST_PERSISTENT);
#endif
	avkit_register_CoreVideo(module_number);
	avkit_register_CoreMedia(module_number);
	avkit_register_AVFoundation(module_number);
	avkit_register_AVKit(module_number);
	return SUCCESS;
}

PHP_RINIT_FUNCTION(avkit)
{
#if defined(COMPILE_DL_AVKIT) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}

PHP_MINFO_FUNCTION(avkit)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "avkit support", "enabled");
	php_info_print_table_row(2, "Version", PHP_AVKIT_VERSION);
	php_info_print_table_end();
}

/* appkit registers the classes avkit's extend; load order follows from this. */
static const zend_module_dep avkit_deps[] = {
	ZEND_MOD_REQUIRED("appkit")
	ZEND_MOD_END
};

zend_module_entry avkit_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	avkit_deps,
	"avkit",
	NULL,
	PHP_MINIT(avkit),
	NULL,
	PHP_RINIT(avkit),
	NULL,
	PHP_MINFO(avkit),
	PHP_AVKIT_VERSION,
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_AVKIT
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(avkit)
#endif
