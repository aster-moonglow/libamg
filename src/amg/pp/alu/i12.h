#ifndef AMG__PP_ALU_I12_INCLUDED
#define AMG__PP_ALU_I12_INCLUDED

#ifndef AMG_PP_ALU_I12_H
#define AMG_PP_ALU_I12_H "amg/pp/alu/i12.h"
#endif

#ifndef  AMG_PP_ALU_I4_H
#define  AMG_PP_ALU_I4_H "amg/pp/alu/i4.h"
#endif
#ifndef  AMG__PP_ALU_I4_INCLUDED
#include AMG_PP_ALU_I4_H
#endif

#define amg__i12noop(d3,d2,d1)       d3,d2,d1

//#define amg__i8nibrev(d3,d2,d1)   d1,d2,d3
#define amg__i12nibrevt(d3,d2,d1) (d1,d2,d3)
#define amg__i12nibrevtt(tuple) amg__i12nibrevt tuple

#define amg_i12_incr(tuple)     amg__i12incr0 tuple
#define amg_i12t3_incr(tuple)   amg__i12incr0 tuple

/** Adds 1 to a 12-bit integer directly written as hex digits.
///
/// Specifically:
/// It converts 3 hexadecimal digit arguments into an 12-bit integer,
/// then increments that 12-bit integer number by 1.
///
/// The result is an 12-bit integer represented
/// by a 3-tuple of 4-bit integers.
///
/// The math assumes a two's-complement representation.
///
/// This function does not have carry-in or carry-out functionality.
**/
#define amg_i12h3_incr(h3,h2,h1) amg__i12incr0(amg_i4h1_##h3, amg_i4h1_##h2, amg_i4h1_##h1)
#define amg__i12incr0(d3,d2,d1)  amg__i12nibrevtt((amg__i12incr1(d1,d2,d3)))
#define amg__i12incr1(d1,d2,d3)  amg__i4_ripple1(2,d1,amg__i12incr2),d2,d3)
#define amg__i12incr2(c,d2,d3)   amg__i4_ripple1(c,d2,amg__i4_ripple1_half),d3)

#define amg_i12_decr(tuple)   amg__i12decr0 tuple
#define amg_i12t3_decr(tuple) amg__i12decr0 tuple

#define amg_i12h3_decr(h3,h2,h1) amg__i12decr0(amg_i4h1_##h3, amg_i4h1_##h2, amg_i4h1_##h1)
#define amg__i12decr0(d3,d2,d1)  amg__i12nibrevtt((amg__i12decr1(d1,d2,d3)))
#define amg__i12decr1(d1,d2,d3)  amg__i4_ripple1(0,d1,amg__i12decr2),d2,d3)
#define amg__i12decr2(c,d2,d3)   amg__i4_ripple1(c,d2,amg__i4_ripple1_half),d3)

/*
#define amg_i12h2_incr(h2,h1,h0) \
	(amg__i12incr(amg_i4h1_##h3,amg_i4h1_##h2, amg_i4h1_##h1,0))
#define amg__i12incr(d3,d2,d1,c) \
	amg__i4inci(d2,amg__i4incc(d1,c)), \
	amg__i4incr(d1,c)
#define amg__i12incc(d3,d2,d1,c) \
	amg__i4incc(d2,amg__i4incc(d1,c))
*/
#endif
