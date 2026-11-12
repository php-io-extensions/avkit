PHP_ARG_ENABLE([avkit],
  [whether to enable avkit support],
  [AS_HELP_STRING([--enable-avkit], [Enable AVFoundation, AVKit, CoreMedia and CoreVideo bindings])],
  [no])

PHP_ARG_ENABLE([avkit-probes],
  [whether to build the avkit probe switch],
  [AS_HELP_STRING([--enable-avkit-probes],
    [Build the AVKIT_PROBE_OFF switch that tests/Probes drives: env AVKIT_PROBE_OFF=<site id> turns that kept refusal off. Never for a release build])],
  [no],
  [no])

if test "$PHP_AVKIT" != "no"; then
  case $host_os in
    darwin*) ;;
    *) AC_MSG_ERROR([avkit binds AVFoundation, which only macOS provides]) ;;
  esac

  if test "$PHP_AVKIT_PROBES" != "no"; then
    AC_DEFINE([AVKIT_PROBES], [1], [Kept refusal sites can be turned off through env AVKIT_PROBE_OFF])
  fi

  dnl avkit's classes are ext-appkit objects: it compiles against appkit's installed headers.
  if test -n "$PHP_CONFIG"; then
    avkit_appkit_inc="`$PHP_CONFIG --include-dir`/ext/appkit"
  else
    avkit_appkit_inc="$phpincludedir/ext/appkit"
  fi
  if test ! -f "$avkit_appkit_inc/php_appkit_api.h"; then
    AC_MSG_ERROR([avkit needs ext-appkit installed first: $avkit_appkit_inc/php_appkit_api.h not found])
  fi

  AVKIT_SOURCES="src/avkit.m src/CoreVideo.m src/CoreMedia.m src/AVFoundation.m src/AVPlayerView.m"

  dnl No C sources: every translation unit is Objective-C, compiled by the rules below.
  PHP_NEW_EXTENSION([avkit], [], [$ext_shared],, [-DZEND_ENABLE_STATIC_TSRMLS_CACHE=1])
  PHP_ADD_BUILD_DIR([$ext_builddir/src])

  dnl PHP_ADD_SOURCES only knows .c/.s/.S/.cpp, so the .m rules are written the way
  dnl PHP_ADD_SOURCES_X writes a .c rule, with the ObjC flags added: shared objects for a
  dnl phpize build, PHP's own objects when compiled into PHP. -fno-objc-arc: retain/release
  dnl are explicit.
  case $ext_dir in
    "") avkit_srcdir="$abs_srcdir/"; avkit_bdir=""; avkit_inc="-I. -I$abs_srcdir -I$avkit_appkit_inc" ;;
    *) avkit_srcdir="$abs_srcdir/$ext_dir/"; avkit_bdir="$ext_dir/"; avkit_inc="-I$avkit_bdir -I$avkit_srcdir -I$avkit_appkit_inc" ;;
  esac
  if test "$ext_shared" = "yes"; then
    avkit_cc="$shared_c_pre $avkit_inc $shared_c_meta -DZEND_COMPILE_DL_EXT=1"
    avkit_post=$shared_c_post
  else
    avkit_cc="$php_c_pre $avkit_inc $php_c_meta"
    avkit_post=$php_c_post
  fi
  for avkit_src in $AVKIT_SOURCES; do
    avkit_obj=$avkit_bdir$(echo "$avkit_src" | $SED -e 's/\.m$//')
    if test "$ext_shared" = "yes"; then
      shared_objects_avkit="$shared_objects_avkit $avkit_obj.lo"
    else
      PHP_GLOBAL_OBJS="$PHP_GLOBAL_OBJS $avkit_obj.lo"
    fi
    cat >>Makefile.objects<<EOF
-include $avkit_obj.dep
$avkit_obj.lo: $avkit_srcdir$avkit_src
	$avkit_cc -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1 -x objective-c -fno-objc-arc -fobjc-exceptions -Wno-unused-parameter -c $avkit_srcdir$avkit_src -o $avkit_obj.lo $avkit_post -MMD -MF $avkit_obj.dep -MT $avkit_obj.lo
EOF
  done

  dnl Shared, the frameworks go to the .so; compiled in, to PHP's own link line.
  dnl CoreAudioTypes (kAudioFormatLinearPCM) has headers and no library: it is not linked.
  AVKIT_FRAMEWORKS="Foundation AppKit AVFoundation AVFAudio AVKit CoreAudioTypes CoreMedia CoreVideo"
  AVKIT_LINKED=`echo "$AVKIT_FRAMEWORKS" | $SED -e 's/CoreAudioTypes//'`
  if test "$ext_shared" = "yes"; then
    for avkit_framework in $AVKIT_LINKED; do
      AVKIT_SHARED_LIBADD="$AVKIT_SHARED_LIBADD -framework $avkit_framework"
    done
    AVKIT_SHARED_LIBADD="$AVKIT_SHARED_LIBADD -lobjc"
    PHP_SUBST([AVKIT_SHARED_LIBADD])
  else
    for avkit_framework in $AVKIT_LINKED; do
      PHP_ADD_FRAMEWORK([$avkit_framework])
    done
    PHP_ADD_LIBRARY([objc])
  fi
fi
