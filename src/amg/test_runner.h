#ifndef AMG_dummy_guard
#ifndef AMG_test_runner_included
#define AMG_test_runner_included 1

#ifndef  AMG_TEST_RUNNER_H
#define  AMG_TEST_RUNNER_H "amg/test_runner.h"
#endif

#include <stddef.h>
#include <stdint.h>

/* #define AMG_T(type)     AMG_T_##type */

#define AMG_BOOL uint8_t

#if (-128 <= CHAR_MIN) && (CHAR_MAX <= 255)
#define AMG_CHAR unsigned char
#else
#define AMG_CHAR uint8_t
#endif

#define AMG_I8   int8_t
#define AMG_I16  int16_t
#define AMG_I32  int32_t
#ifdef int64_t
#define AMG_I64  int64_t
#endif

#define AMG_U8   uint8_t
#define AMG_U16  uint16_t
#define AMG_U32  uint32_t
#ifdef uint64_t
#define AMG_U64  uint64_t
#endif

#define AMG_I8_FAST   int_fast8_t
#define AMG_I16_FAST  int_fast16_t
#define AMG_I32_FAST  int_fast32_t
#ifdef int_fast64_t
#define AMG_I64_FAST  int_fast64_t
#endif

#define AMG_U8_FAST   uint_fast8_t
#define AMG_U16_FAST  uint_fast16_t
#define AMG_U32_FAST  uint_fast32_t
#ifdef uint_fast64_t
#define AMG_U64_FAST  uint_fast64_t
#endif

/* TODO: What SHOULD this be? How do we know? */
#define AMG_ERROR_CODE AMG_I16

/* TODO: Stuff should probably go in a types.h file, or maybe something else? */
#define amgpp_sizeof_string_literal(lit) (sizeof(lit) + amg__fix_sizeof_cstr)

typedef enum amg_enum__fix_sizeof_cstr
{
	/* This constant exists because some compilers can be bugger and
	// return the incorrect value for the `sizeof` expression
	// when taking the size of a string literal (e.g., it won't
	// include the terminating NUL byte in its size calculation).
	// Source:
	// https://stackoverflow.com/a/77820395
	*/
	amg__fix_sizeof_cstr = (sizeof("_") == 2 ? 0 : 1)
}
amg_enum__fix_sizeof_cstr;



/* Optimization: We use AMG_U16_FAST for integers
// make things go faster on systems that lack
// fast 32-bit integer math
// (e.g. smaller microcontrollers and vintage computers).
//
// This is done with the understanding that we probably won't
// end up with more than 65535 tests-per-feature or
// 65535 features-per-module.
*/

typedef struct AMG_TEST_RUNNER
{
	AMG_CHAR*     buffer;
	AMG_U16_FAST  buffer_sz;
	AMG_U16_FAST  n_modules_tested;
	AMG_U16_FAST  n_modules_passed;
	AMG_U16_FAST  n_features_tested;
	AMG_U16_FAST  n_features_passed;
	AMG_U16_FAST  n_tests;
	AMG_U16_FAST  n_passed;
}
AMG_TEST_RUNNER;

void amg_init_test_runner(AMG_TEST_RUNNER *runner);

AMG_CHAR* amg__test_runner_ensure_buffer_size(
	AMG_TEST_RUNNER *runner,  AMG_U16_FAST bytes_needed);

void amg_module_tests_begin(
	AMG_TEST_RUNNER *runner, const char *module_name);

void amg_module_tests_end(
	AMG_TEST_RUNNER *runner, const char *module_name);

void amg_feature_tests_begin(
	AMG_TEST_RUNNER *runner,  const char *feature_name);

void amg_feature_tests_end(
	AMG_TEST_RUNNER *runner, const char *feature_name);

#ifdef AMG_INCLUDE_UNITTESTS
AMG_ERROR_CODE amg_unittest_all(AMG_TEST_RUNNER *runner);
#endif


/*
//
// Optimization:
// Note that this function is expected to be called from within a macro
// that is testing pre-processor-time expressions, so we rely on the
// macro to provide us with string sizes using the `sizeof` operator.
// This is more efficient at runtime than scanning the strings with `strlen`
// at runtime. Does it realistically matter? dunno. But it CAN be.
*/
void amg__expect_ppval_eq(
	AMG_TEST_RUNNER *runner,
	const char *file, size_t line,
	const char *spacing_after_expr,
	const char *expr_before_expansion,
	const char *expr_after_expansion,
	const char *spacing_after_expect,
	const char *expectval_before_expansion,
	const char *expectval_after_expansion,
	AMG_U16 sz_spacing_after_expr,
	AMG_U16 sz_expr_before_expansion,
	AMG_U16 sz_expr_after_expansion,
	AMG_U16 sz_spacing_after_expect,
	AMG_U16 sz_expectval_before_expansion,
	AMG_U16 sz_expectval_after_expansion
);


#define amgpp_expect_eq(runner,expr,spc0,expect,spc1) \
	(amg__expect_ppval_eq((runner), __FILE__, __LINE__, \
		#spc0,                   \
		#expr,                   \
		amgpp_stringize(expr),   \
		#spc1,                   \
		#expect,                 \
		amgpp_stringize(expect), \
		amgpp_sizeof_string_literal(#spc0), \
		amgpp_sizeof_string_literal(#expr), \
		amgpp_sizeof_string_literal(amgpp_stringize(expr)), \
		amgpp_sizeof_string_literal(#spc1), \
		amgpp_sizeof_string_literal(#expect), \
		amgpp_sizeof_string_literal(amgpp_stringize(expect))))

void amg__assert(
	AMG_TEST_RUNNER *runner,
	const char *file, size_t line,
	const char *expr, AMG_U16 sz_expr,
	AMG_BOOL   result
);

#define amg_assert(runner,expr) \
	(amg__assert((runner), __FILE__, __LINE__, \
		#expr, amgpp_sizeof_string_literal(#expr), (expr)))

#endif /* AMG_test_runner_included */


#ifdef AMG_INCLUDE_IMPLEMENTATION
#ifndef AMG_test_runner_implemented
#define AMG_test_runner_implemented 1

#include <stdio.h>
#include <stdlib.h>
/* TODO: Replace `stdlib.h` `malloc` with our own abstraction.
// This is actually important for allowing tests to run in-situ
// on systems/platforms without `malloc` (ex: microcontrollers).
*/

#include <string.h>

#if 0
#ifdef AMG_INCLUDE_UNITTESTS
// We normally implement our own,
// but in this module we need to test the functions
// that are used to implement our own assertions.
#include <assert.h>
#endif
#endif

static AMG_I8 amg__cstrcmp(const char* s1, const char* s2)
{
	return (AMG_I8)strcmp(s1,s2);
}

static AMG_I8 amg__strcmp(const AMG_CHAR* s1, const AMG_CHAR* s2)
{
	return (AMG_I8)strcmp((const char*)s1, (const char*)s2);
}
//#define amg__strcmp(s1,s2)  (strcmp(s1,s2))


static AMG_CHAR*  amg__rm_spaces(AMG_CHAR** buffer, const char *str)
{
	AMG_CHAR* result_front = *buffer;
	AMG_CHAR* result_back = result_front;
	while(1) {
		char ch = *str;
		str++;

		if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n') {
			continue;
		}
		*result_back = ch;
		result_back++;

		if (ch == '\0') {
			*buffer = result_back;
			return result_front;
		}
	}
}

#ifdef AMG_INCLUDE_UNITTESTS
static void amg__test_runner_unittest_rm_spaces(AMG_TEST_RUNNER *runner)
{
	AMG_U8 bufsz = 255;
	AMG_CHAR buffer_array[255];
	AMG_CHAR *buffer = buffer_array;
	AMG_CHAR *buffer_start = buffer;
	AMG_U8 i;

	/* Ensure we have a deterministic starting buffer. */
	for(i = 0; i < bufsz; i++) {
		buffer_array[i] = '\0';
	}

	/* Actual tests. */
	const char *feature_name = "amg__rm_spaces";
	amg_feature_tests_begin(runner, feature_name);
	amg_assert(runner, 0 == amg__cstrcmp((const char*)amg__rm_spaces(&buffer, ""),""));
	amg_assert(runner, 0 == amg__cstrcmp((const char*)amg__rm_spaces(&buffer, "1"),"1"));
	amg_assert(runner, 0 == amg__cstrcmp((char*)(buffer_start+0), ""));
	amg_assert(runner, 0 == amg__cstrcmp((char*)(buffer_start+1), "1"));
	amg_assert(runner, 0 == amg__cstrcmp((const char*)amg__rm_spaces(&buffer, " "),""));
	amg_assert(runner, 0 == amg__cstrcmp((const char*)amg__rm_spaces(&buffer, " a"),"a"));
	amg_assert(runner, 0 == amg__cstrcmp((const char*)amg__rm_spaces(&buffer, "a "),"a"));
	amg_assert(runner, 0 == amg__cstrcmp((const char*)amg__rm_spaces(&buffer, "aa"),"aa"));
	amg_assert(runner, 0 == amg__cstrcmp((const char*)amg__rm_spaces(&buffer, "a a"),"aa"));
	amg_assert(runner, 0 == amg__cstrcmp((const char*)amg__rm_spaces(&buffer, " a a "),"aa"));
	amg_assert(runner, 0 == amg__cstrcmp((char*)(buffer_start+0), ""));
	amg_assert(runner, 0 == amg__cstrcmp((char*)(buffer_start+1), "1"));
	amg_assert(runner, 0 == amg__cstrcmp((char*)(buffer_start+3), ""));
	amg_assert(runner, 0 == amg__cstrcmp((char*)(buffer_start+4), "a"));
	amg_assert(runner, 0 == amg__cstrcmp((char*)(buffer_start+6), "a"));
	amg_assert(runner, 0 == amg__cstrcmp((char*)(buffer_start+8), "aa"));
	amg_assert(runner, 0 == amg__cstrcmp((char*)(buffer_start+11), "aa"));
	amg_assert(runner, 0 == amg__cstrcmp((char*)(buffer_start+14), "aa"));
	amg_feature_tests_end(runner, feature_name);
}
#endif

void amg_init_test_runner(AMG_TEST_RUNNER *runner)
{
	runner->buffer = NULL;
	runner->buffer_sz = 0;
	runner->n_modules_tested = 0;
	runner->n_modules_passed = 0;
	runner->n_features_tested = 0;
	runner->n_features_passed = 0;
	runner->n_tests = 0;
	runner->n_passed = 0;
}

/* Currently private because I'm not totally satisfied with this interface. */
/* It's an allocation function. But it's NOT malloc. It only allocates a single region. Hard to find a way to express this! */
AMG_CHAR* amg__test_runner_ensure_buffer_size(
	AMG_TEST_RUNNER *runner,   AMG_U16_FAST bytes_needed)
{
	if (NULL == runner->buffer) {
		runner->buffer = (AMG_CHAR*)malloc(bytes_needed);
		runner->buffer_sz = bytes_needed;
	} else
	if (runner->buffer_sz < bytes_needed ) {
		runner->buffer = (AMG_CHAR*)realloc(runner->buffer, bytes_needed);
		runner->buffer_sz = bytes_needed;
	}
	return runner->buffer;
}

void amg_module_tests_begin(
	AMG_TEST_RUNNER *runner, const char *module_name)
{
	printf("Testing in `%s`:\n", module_name);
	runner->n_features_tested = 0;
	runner->n_features_passed = 0;
	runner->n_modules_tested++;
}

void amg_module_tests_end(
	AMG_TEST_RUNNER *runner, const char *module_name)
{
	if (runner->n_features_passed == runner->n_features_tested) {
		runner->n_modules_passed++;
		printf("  Module PASSED: `%s`; (%lu feature(s) tested)\n\n",
			module_name, (unsigned long)runner->n_features_tested);
	} else {
		unsigned long  n_errors =
			runner->n_features_tested - runner->n_features_passed;

		printf("  Module FAILED: `%s`; Errors in %lu/%lu feature(s).\n\n",
			module_name, n_errors, (unsigned long)runner->n_features_tested);
	}

	/*
	printf(" Score: %lu/%lu\n\n",
		(unsigned long)runner->n_features_passed,
		(unsigned long)runner->n_features_tested);
	*/
}

void amg_feature_tests_begin(
	AMG_TEST_RUNNER *runner,  const char *feature_name)
{
	printf("  %s ...", feature_name);
	runner->n_tests = 0;
	runner->n_passed = 0;
}

void amg_feature_tests_end(
	AMG_TEST_RUNNER *runner, const char *feature_name)
{
	(void)feature_name;

	runner->n_features_tested++;
	if (runner->n_passed == runner->n_tests) {
		runner->n_features_passed++;
		printf(" passed! (%lu test(s))\n", (unsigned long)runner->n_tests);
	} else {
		unsigned long n_errors =
			runner->n_tests - runner->n_passed;

		printf("\n    ...failed! Errors in %lu/%lu test(s).\n",
			n_errors, (unsigned long)runner->n_tests);
	}
}

#ifdef AMG_INCLUDE_UNITTESTS
void amg__expect_ppval_eq(
	AMG_TEST_RUNNER *runner,
	const char *file, size_t line,
	const char *spacing_after_expr,
	const char *expr_before_expansion,
	const char *expr_after_expansion,
	const char *spacing_after_expect,
	const char *expectval_before_expansion,
	const char *expectval_after_expansion,
	AMG_U16 sz_spacing_after_expr,
	AMG_U16 sz_expr_before_expansion,
	AMG_U16 sz_expr_after_expansion,
	AMG_U16 sz_spacing_after_expect,
	AMG_U16 sz_expectval_before_expansion,
	AMG_U16 sz_expectval_after_expansion
)
{
	(void)expectval_before_expansion;
	(void)sz_spacing_after_expr;
	(void)sz_spacing_after_expect;
	(void)sz_expectval_before_expansion;

	AMG_CHAR *buffer =
		amg__test_runner_ensure_buffer_size(
			runner,
			sz_expr_before_expansion +
			sz_expr_after_expansion +
			sz_expectval_after_expansion);

	AMG_CHAR *expr_as_str  = amg__rm_spaces(&buffer, expr_before_expansion);
	AMG_CHAR *expr_as_val  = amg__rm_spaces(&buffer, expr_after_expansion);
	AMG_CHAR *expected_val = amg__rm_spaces(&buffer, expectval_after_expansion);

	runner->n_tests++;
	if(0 == amg__strcmp(expr_as_val, expected_val)) {
		runner->n_passed++;
	} else {
		/* TODO: We can probably use `puts` or something, then it'll be easier to port. */
		printf("\n%s, %lu: Unittest failed for expression `%s` %s Expected `%s` %s Got `%s`",
			file, (unsigned long)line,
			expr_as_str,  /* expression */
			spacing_after_expr,
			expected_val, /* expected result */
			spacing_after_expect,
			expr_as_val   /* got */
		);
	}
}

void amg__assert(
	AMG_TEST_RUNNER *runner,
	const char *file, size_t line,
	const char *expr, AMG_U16 sz_expr,
	AMG_BOOL   result
)
{
	(void)sz_expr;

	runner->n_tests++;
	if(result) {
		runner->n_passed++;
	} else {
		/* TODO: We can probably use `puts` or something, then it'll be easier to port. */
		printf("\n%s, %lu: Unittest failed: `%s` was false.",
			file, (unsigned long)line, expr);
	}
}

#ifndef AMG_pp_int_incr_h
#define AMG_pp_int_incr_h "amg/pp/int/incr.h"
#endif
#include AMG_pp_int_incr_h

AMG_ERROR_CODE amg_unittest_all(AMG_TEST_RUNNER *runner)
{
	const char *module;

	module = "amg/test_runner.h";
	amg_module_tests_begin(runner, module);
	amg__test_runner_unittest_rm_spaces(runner);
	amg_module_tests_end(runner, module);

	module = "Preprocessor-based Integer Math";
	amg_module_tests_begin(runner, module);
	amg__unittest_amgpp_incr(runner);
	amg_module_tests_end(runner, module);

	return (runner->n_modules_tested != runner->n_modules_passed);
}
#endif /* AMG_INCLUDE_UNITTESTS */

#endif /* AMG_test_runner_implemented */
#endif /* AMG_INCLUDE_IMPLEMENTATION */
#endif /* AMG_dummy_guard */
