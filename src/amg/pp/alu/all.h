
#ifndef AMG_PP_ALU_ALL_H
#define AMG_PP_ALU_ALL_H "amg/pp/alu/math.h"
#endif

#ifndef  AMG_PP_ALU_HTODD_H
#define  AMG_PP_ALU_HTODD_H "amg/pp/alu/htodd.h"
#endif
#ifndef  AMG__PP_ALU_HTODD_INCLUDED
#include AMG_PP_ALU_HTODD_H
#endif

#ifndef  AMG_PP_ALU_I4_H
#define  AMG_PP_ALU_I4_H "amg/pp/alu/i4.h"
#endif
#ifndef  AMG__PP_ALU_I4_INCLUDED
#include AMG_PP_ALU_I4_H
#endif

#ifndef  AMG_PP_ALU_I8_H
#define  AMG_PP_ALU_I8_H "amg/pp/alu/i8.h"
#endif
#ifndef  AMG__PP_ALU_I8_INCLUDED
#include AMG_PP_ALU_I8_H
#endif

#ifndef  AMG_PP_ALU_I12_H
#define  AMG_PP_ALU_I12_H "amg/pp/alu/i12.h"
#endif
#ifndef  AMG__PP_ALU_I12_INCLUDED
#include AMG_PP_ALU_I12_H
#endif

#ifndef  AMG_PP_ALU_I16_H
#define  AMG_PP_ALU_I16_H "amg/pp/alu/i16.h"
#endif
#ifndef  AMG__PP_ALU_I16_INCLUDED
//#include AMG_PP_ALU_I16_H
#endif

#ifndef  AMG_PP_ALU_APPEND_H
#define  AMG_PP_ALU_APPEND_H "amg/pp/alu/append.h"
#endif
#ifndef  AMG__PP_ALU_APPEND_INCLUDED
#include AMG_PP_ALU_APPEND_H
#endif

#ifndef  AMG_PP_ALU_PREPEND_H
#define  AMG_PP_ALU_PREPEND_H "amg/pp/alu/prepend.h"
#endif
#ifndef  AMG__PP_ALU_PREPEND_INCLUDED
#include AMG_PP_ALU_PREPEND_H
#endif

#ifndef  AMG_PP_ALU_ABBREV_H
#define  AMG_PP_ALU_ABBREV_H "amg/pp/alu/abbrev.h"
#endif
#ifndef  AMG__PP_ALU_ABBREV_INCLUDED
#include AMG_PP_ALU_ABBREV_H
#endif


// TODO: Things that should be moved to their proper files.
#define amg__n16a3__noop(d3,d2,d1)    d3,d2,d1
#define amg__n16a4__noop(d4,d3,d2,d1) d4,d3,d2,d1


#define amg_n16a3_incr(h3,h2,h1) \
	(amg__n16a3__incr(amg_HtoDD##h3, amg_HtoDD##h2, amg_HtoDD##h1))
#define amg__n16a3__incr(d3,d2,d1) \
	amg_if01(amg__n16a1__incc(d1), \
		amg__i8h2__incr(d3,d2),amg__i8h2__noop(d3,d2)), \
	amg__n16a1__incr(d1)

// TODO: grow on overflow?
#define amg__n16tN__incr(n,tupleN) (n,(amg_n16t##n##_incr(tupleN)))

/** Increments the base-16 bignum (as a digit-array) by 1.
///
/// Limitations: Currently does not support growth-on-overflow.
**/
#define amg_n16big_incr(number) amg__n16tN__incr(amg__expand2 number)

// TODO: Compile-time assertions.
// TODO: Generate better error messages if caller puts too many parens (or not enough).
amg_i8_append_as_hex(,amg__test_,amg_i8(A,9))
amg_i8_append_as_hex(,amg__test_,amg_i8_incr(amg_i8(0,0)))
amg_i8_append_as_hex(,amg__test_,amg_i8_incr(amg_i8(A,9)))
amg_i8_append_as_hex(,amg__test_,amg_i8_incr(amg_i8(B,F)))
amg_i8_append_as_hex(,amg__test_,amg_i8_incr(amg_i8(F,F)))

amg_i8_append_as_hex(,amg__test_,amg_i8_decr(amg_i8(F,F)))
amg_i8_append_as_hex(,amg__test_,amg_i8_decr(amg_i8(A,0)))
amg_i8_append_as_hex(,amg__test_,amg_i8_decr(amg_i8(0,B)))
amg_i8_append_as_hex(,amg__test_,amg_i8_decr(amg_i8(0,0)))

amg_i8_prepend_as_hex(,_amg__test,amg_i8(A,9))
amg_i8_prepend_as_hex(,_amg__test,amg_i8_incr(amg_i8(0,0)))
amg_i8_prepend_as_hex(,_amg__test,amg_i8_incr(amg_i8(A,9)))
amg_i8_prepend_as_hex(,_amg__test,amg_i8_incr(amg_i8(B,F)))
amg_i8_prepend_as_hex(,_amg__test,amg_i8_incr(amg_i8(F,F)))

amg_i12_append_as_hex(,amg__test_,amg_i12(A,9,5))
amg_i12_append_as_hex(,amg__test_,amg_i12_incr(amg_i12(0,0,0)))
amg_i12_append_as_hex(,amg__test_,amg_i12_incr(amg_i12(A,9,7)))
amg_i12_append_as_hex(,amg__test_,amg_i12_incr(amg_i12(B,F,F)))
amg_i12_append_as_hex(,amg__test_,amg_i12_incr(amg_i12(F,F,F)))

amg_i12_append_as_hex(,amg__test_,amg_i12_decr(amg_i12(F,F,F)))
amg_i12_append_as_hex(,amg__test_,amg_i12_decr(amg_i12(A,9,7)))
amg_i12_append_as_hex(,amg__test_,amg_i12_decr(amg_i12(B,0,0)))
amg_i12_append_as_hex(,amg__test_,amg_i12_decr(amg_i12(0,0,0)))

amg_i8h_append_as_hex(,amg__test_,A,9)
amg_i8_append_as_hex(,amg__test_,amg_i8h_incr(0,0))
amg_i8_append_as_hex(,amg__test_,amg_i8h_incr(A,9))
amg_i8_append_as_hex(,amg__test_,amg_i8h_incr(B,F))
amg_i8_append_as_hex(,amg__test_,amg_i8h_incr(F,F))

amg_i8h_prepend_as_hex(,amg__test_,A,9)
amg_i8_prepend_as_hex(,amg__test_,amg_i8h_incr(0,0))
amg_i8_prepend_as_hex(,amg__test_,amg_i8h_incr(A,9))
amg_i8_prepend_as_hex(,amg__test_,amg_i8h_incr(B,F))
amg_i8_prepend_as_hex(,amg__test_,amg_i8h_incr(F,F))

amg_i8_append_as_hex(,amg__test_,amg_i8h_add(0,0,  0,0))
amg_i8_append_as_hex(,amg__test_,amg_i8h_add(0,0,  F,F))
amg_i8_append_as_hex(,amg__test_,amg_i8h_add(F,F,  0,0))
amg_i8_append_as_hex(,amg__test_,amg_i8h_add(0,1,  8,F))
amg_i8_append_as_hex(,amg__test_,amg_i8h_add(8,F,  0,1))
amg_i8_append_as_hex(,amg__test_,amg_i8h_add(0,1,  F,F))
amg_i8_append_as_hex(,amg__test_,amg_i8h_add(F,F,  0,1))
amg_i8_append_as_hex(,amg__test_,amg_i8h_add(8,F,  8,F))
amg_i8_append_as_hex(,amg__test_,amg_i8h_add(8,F,  8,F))
amg_i8_append_as_hex(,amg__test_,amg_i8h_add(F,F,  F,F))


#ifndef AMG_PP_HEX_OCTETS_DISABLED
amg_i8_append_as_hex(,amg__test_,amg_i8hh_add(00,00))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_add(00,FF))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_add(FF,00))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_add(01,8F))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_add(8F,01))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_add(01,FF))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_add(FF,01))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_add(8F,8F))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_add(8F,8F))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_add(FF,FF))

amg_i8_append_as_hex(,amg__test_,amg_i8hh_sub(00,00))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_sub(00,FF))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_sub(FF,00))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_sub(01,8F))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_sub(8F,01))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_sub(01,FF))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_sub(FF,01))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_sub(8F,8F))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_sub(8F,8F))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_sub(FF,FF))

amg_i8_append_as_hex(,amg__test_,amg_i8hh_and(00,00))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_and(00,FF))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_and(FF,00))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_and(01,8F))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_and(8F,01))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_and(01,FF))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_and(FF,01))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_and(8F,8F))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_and(8F,8F))
amg_i8_append_as_hex(,amg__test_,amg_i8hh_and(FF,FF))

amg_i8hh_to_bool(00) amg_i8h_to_bool(0,0) amg_i8_to_bool(amg_i8(0,0))
amg_i8hh_to_bool(01) amg_i8h_to_bool(0,1) amg_i8_to_bool(amg_i8(0,1))
amg_i8hh_to_bool(7F) amg_i8h_to_bool(7,F) amg_i8_to_bool(amg_i8(7,F))
amg_i8hh_to_bool(10) amg_i8h_to_bool(1,0) amg_i8_to_bool(amg_i8(1,0))
amg_i8hh_to_bool(80) amg_i8h_to_bool(8,0) amg_i8_to_bool(amg_i8(8,0))
amg_i8hh_to_bool(8F) amg_i8h_to_bool(8,F) amg_i8_to_bool(amg_i8(8,F))
amg_i8hh_to_bool(FF) amg_i8h_to_bool(F,F) amg_i8_to_bool(amg_i8(F,F))

#endif
