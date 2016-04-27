PHP_ARG_ENABLE(soinc, whether to enable soinc, [ --enable-soinc   Enable Soinc])

if test "$PHP_SOINC" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, SOINC_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_SOINC, 1, [Whether you have Soinc])
	soinc_sources="soinc.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/extended/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c soinc/exception.zep.c
	soinc/logger/processor/abstractprocessor.zep.c
	soinc/abstractdfs.zep.c
	soinc/abstractmodule.zep.c
	soinc/bootstrap.zep.c
	soinc/db/mysql.zep.c
	soinc/dfs/fastdfs.zep.c
	soinc/exception/db.zep.c
	soinc/http/curl/extended.zep.c
	soinc/http/request/extended.zep.c
	soinc/http/response/cookies.zep.c
	soinc/logger/adapter/file.zep.c
	soinc/logger/formatter/line.zep.c
	soinc/logger/processor/trace.zep.c
	soinc/model.zep.c
	soinc/utils.zep.c
	soinc/worker/taskabstract.zep.c
	soinc/worker/worker.zep.c "
	PHP_NEW_EXTENSION(soinc, $soinc_sources, $ext_shared,, )
	PHP_SUBST(SOINC_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([soinc], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([soinc], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/soinc], [php_SOINC.h])

fi
