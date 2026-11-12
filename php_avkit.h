#ifndef PHP_AVKIT_H
#define PHP_AVKIT_H

extern zend_module_entry avkit_module_entry;
#define phpext_avkit_ptr &avkit_module_entry

#define PHP_AVKIT_VERSION "0.11.2"

#if defined(ZTS) && defined(COMPILE_DL_AVKIT)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif
