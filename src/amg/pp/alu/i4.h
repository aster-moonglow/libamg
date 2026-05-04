#ifndef AMG__PP_ALU_I4_INCLUDED
#define AMG__PP_ALU_I4_INCLUDED

#ifndef AMG_PP_ALU_I4_H
#define AMG_PP_ALU_I4_H "amg/pp/alu/i4.h"
#endif

#ifndef  AMG_PP_ALU_HTODD_H
#define  AMG_PP_ALU_HTODD_H "amg/pp/alu/htodd.h"
#endif
#ifndef  AMG__PP_ALU_HTODD_INCLUDED
#include AMG_PP_ALU_HTODD_H
#endif

#ifdef AMG_PP_LEAK_TESTING_ENABLED
#define A "Leak detected! Macro name: A"
#define B "Leak detected! Macro name: B"
#define C "Leak detected! Macro name: C"
#define D "Leak detected! Macro name: D"
#define E "Leak detected! Macro name: E"
#define F "Leak detected! Macro name: F"
#endif

/* Currently not part of the public API because it's not
// a NOOP if it changes the format of the argument, is it?
*/
/*#define amg_i4a1_noop(h1)  amg__i4h##h1*/
#define amg__i4noop(d1)        d1

// TODO: Expansion is a more generalized PP feature; it should probably live elsewhere.
#define amg__expand1(a0)                          a0
#define amg__expand2(a0,a1)                       a0,a1
#define amg__expand3(a0,a1,a2)                    a0,a1,a2
#define amg__expand4(a0,a1,a2,a3)                 a0,a1,a2,a3
#define amg__expand5(a0,a1,a2,a3,a4)              a0,a1,a2,a3,a4
#define amg__expand6(a0,a1,a2,a3,a4,a5)           a0,a1,a2,a3,a4,a5
#define amg__expand7(a0,a1,a2,a3,a4,a5,a6)        a0,a1,a2,a3,a4,a5,a6
#define amg__expand8(a0,a1,a2,a3,a4,a5,a6,a7)     a0,a1,a2,a3,a4,a5,a6,a7
#define amg__expand9(a0,a1,a2,a3,a4,a5,a6,a7,a8)  a0,a1,a2,a3,a4,a5,a6,a7,a8
#define amg__expand10(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9) \
	a0,a1,a2,a3,a4,a5,a6,a7,a8,a9
#define amg__expand11(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA) \
	a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA
#define amg__expand12(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB) \
	a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB
#define amg__expand13(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC) \
	a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC
#define amg__expand14(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD) \
	a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD
#define amg__expand15(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE) \
	a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE
#define amg__expand16(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) \
	a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF

#define amg_expand1(e,tuple1)   e##amg__expand1  tuple1
#define amg_expand2(e,tuple2)   e##amg__expand2  tuple2
#define amg_expand3(e,tuple3)   e##amg__expand3  tuple3
#define amg_expand4(e,tuple4)   e##amg__expand4  tuple4
#define amg_expand5(e,tuple5)   e##amg__expand5  tuple5
#define amg_expand6(e,tuple6)   e##amg__expand6  tuple6
#define amg_expand7(e,tuple7)   e##amg__expand7  tuple7
#define amg_expand8(e,tuple8)   e##amg__expand8  tuple8
#define amg_expand9(e,tuple9)   e##amg__expand9  tuple9
#define amg_expand10(e,tuple10) e##amg__expand10 tuple10
#define amg_expand11(e,tuple11) e##amg__expand11 tuple11
#define amg_expand12(e,tuple12) e##amg__expand12 tuple12
#define amg_expand13(e,tuple13) e##amg__expand13 tuple13
#define amg_expand14(e,tuple14) e##amg__expand14 tuple14
#define amg_expand15(e,tuple15) e##amg__expand15 tuple15
#define amg_expand16(e,tuple16) e##amg__expand16 tuple16

// TODO: Selection is a more generalized PP feature; it should probably live elsewhere.
#define amg__select_2d0(a0,a1)  a0
#define amg__select_2d1(a0,a1)  a1
#define amg_select_2n(n,a0,a1)  amg__select_2d##n(a0,a1)
#define amg_select_2t(n,tuple2) amg_select_2n(n,tuple2)
#define amg_select_2(n,a0,a1)   amg_select_2n(n,a0,a1)

#define amg__select_3d0(a0,a1,a2) a0
#define amg__select_3d1(a0,a1,a2) a1
#define amg__select_3d2(a0,a1,a2) a2
#define amg_select_3n(n,a0,a1,a2) amg__select_3d##n(a0,a1,a2)
#define amg_select_3t(n,tuple3)   amg_select_3n(n,tuple3)
#define amg_select_3(n,a0,a1,a2)  amg_select_3n(n,a0,a1,a2)

#define amg__select_4d0(a0,a1,a2,a3) a0
#define amg__select_4d1(a0,a1,a2,a3) a1
#define amg__select_4d2(a0,a1,a2,a3) a2
#define amg__select_4d3(a0,a1,a2,a3) a3
#define amg_select_4n(n,a0,a1,a2,a3) amg__select_4d##n(a0,a1,a2,a3)
#define amg_select_4t(n,tuple4)      amg_select_4n(n,tuple4)
#define amg_select_4(n,a0,a1,a2,a3)  amg_select_4n(n,a0,a1,a2,a3)

#define amg__select_16d0( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) a0
#define amg__select_16d1( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) a1
#define amg__select_16d2( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) a2
#define amg__select_16d3( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) a3
#define amg__select_16d4( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) a4
#define amg__select_16d5( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) a5
#define amg__select_16d6( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) a6
#define amg__select_16d7( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) a7
#define amg__select_16d8( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) a8
#define amg__select_16d9( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) a9
#define amg__select_16d10(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) aA
#define amg__select_16d11(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) aB
#define amg__select_16d12(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) aC
#define amg__select_16d13(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) aD
#define amg__select_16d14(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) aE
#define amg__select_16d15(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) aF

#define amg_select_16n(n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) \
	amg__select_16d##n(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF)

#define amg_select_16(n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) \
	amg_select_16n(n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF)

#define amg__select3_18d0( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH) a0,a1,a2
#define amg__select3_18d1( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH) a1,a2,a3
#define amg__select3_18d2( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH) a2,a3,a4
#define amg__select3_18d3( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH) a3,a4,a5
#define amg__select3_18d4( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH) a4,a5,a6
#define amg__select3_18d5( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH) a5,a6,a7
#define amg__select3_18d6( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH) a6,a7,a8
#define amg__select3_18d7( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH) a7,a8,a9
#define amg__select3_18d8( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH) a8,a9,aA
#define amg__select3_18d9( a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH) a9,aA,aB
#define amg__select3_18d10(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH) aA,aB,aC
#define amg__select3_18d11(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH) aB,aC,aD
#define amg__select3_18d12(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH) aC,aD,aE
#define amg__select3_18d13(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH) aD,aE,aF
#define amg__select3_18d14(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH) aE,aF,aG
#define amg__select3_18d15(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH) aF,aG,aH

#define amg__select3_18n(n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH) \
	amg__select3_18d##n(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH)

#define amg__select3_18(n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH) \
	amg__select3_18n(n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF,aG,aH)


#if 0
// Probably not useful because we'll never write our tables in hex.
// (Because it exposes the A, B, C, D, E, F to macro hijacking.)
// Also, it seems wasteful of CPU cycles to do all of those
// concatenations and expansions when only one is going to get used.
#define amg_select_16h(n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aA,aB,aC,aD,aE,aF) \
	amg__select_16N(n, \
		amg__i4h##a0,amg__i4h##a1,amg__i4h##a2,amg__i4h##a3,\
		amg__i4h##a4,amg__i4h##a5,amg__i4h##a6,amg__i4h##a7,\
		amg__i4h##a8,amg__i4h##a9,amg__i4h##aA,amg__i4h##aB,\
		amg__i4h##aC,amg__i4h##aD,amg__i4h##aE,amg__i4h##aF)
#endif


#define amg__i4_to_bool_table  0,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1

//#define amg__i4incr_table   1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
//#define amg__i4incr_ripple  0,1,2,3,4,5,6,7,8, 9,10,11,12,13,14,15,16
//#define amg__14incr_wrap    0,1,2,3,4,5,6,7,8, 9,10,11,12,13,14,15, 0
#define amg__i4_ripple1_table  15,0,1,2,3,4,5,6,7,8, 9,10,11,12,13,14,15,0
#define amg__i4_ripple1_carry  0, 1,1,1,1,1,1,1,1,1, 1, 1, 1, 1, 1, 1, 1,2

#define amg__i4_ripple_lookup1(carry_in, tuple3) \
	amg__select_3d##carry_in(tuple3

#define amg__i4_ripple_lookup0(c, digit, table) \
	amg__i4_ripple_lookup1(c,amg__select3_18n(digit,table)))

#if 0
/* This one gets called if `table` only needs 1 macro expansion
// to be substituted/reified into the argument list that it yields.
*/
#define amg__i4_ripple_lookup0(c, digit, table) \
	amg__i4_ripple_lookup1(c,amg__select3_18n(digit,table)))

/* This one gets called if `table` is the result of token pasting
// and needs an extra macro expansion to allow it to fully turn
// into an argument list (as opposed to text representing
// a yet-to-be-made macro call).
// EDIT: That didn't turn out to be the problem?
*/
#define amg__i4_ripple_lookup0(c, digit, table) \
	amg__i4_ripple_lookup0(c,digit,table)
#endif

#define amg__i4_to_bool(c,d,next) \
	next(amg__i4_ripple_lookup0(c,d,amg__i4_to_bool_table)

#define amg__i4_to_bool_half(c,d) \
	amg__i4_ripple_lookup0(c,d,amg__i4_to_bool_table)

/** Returns 0 if the given hex digit is 0. Returns 1 otherwise. */
#define amg_i4h_to_bool(h) amg__i4_to_bool(0,amg__i4h##h)

/** Returns 0 if the given 4-bit number is 0. Returns 1 otherwise. */
#define amg_i4_to_bool(tuple)   (amg__i4_ripple1_half(2,amg_expand1(,tuple)))
#define amg_i4t_to_bool(tuple)  (amg__i4_ripple1_half(2,amg_expand1(,tuple)))

/** Compute the 4-bit number that results from incrementing the given hex digit by 1. */
#define amg_i4h_incr(h1)     (amg__i4_ripple1_half(2,amg__i4h##h1))

/** Compute the 4-bit number that results from incrementing the 4-bit number by 1. */
#define amg_i4_incr(tuple)   (amg__i4_ripple1_half(2,amg_expand1(,tuple)))
#define amg_i4t_incr(tuple)  (amg__i4_ripple1_half(2,amg_expand1(,tuple)))

/** Compute the 4-bit number that results from decrementing the given hex digit. */
#define amg_i4h_decr(h1)     (amg__i4_ripple1_half(0,amg__i4h##h1))

/** Compute the 4-bit number that results from decrementing the 4-bit number by 1. */
#define amg_i4_decr(tuple)   (amg__i4_ripple1_half(0,amg_expand1(,tuple)))
#define amg_i4t_decr(tuple)  (amg__i4_ripple1_half(0,amg_expand1(,tuple)))

/* Behavior:
// carry_in=0 -> decrement by 1
// carry_in=1 -> do nothing (identity op / no-op)
// carry_in=2 -> increment by 1
*/
#define amg__i4_ripple1(c,d,next) \
	amg__i4_ripple_lookup0(c,d,amg__i4_ripple1_table), \
	next(amg__i4_ripple_lookup0(c,d,amg__i4_ripple1_carry)

#define amg__i4_ripple1_half(c,d) \
	amg__i4_ripple_lookup0(c,d,amg__i4_ripple1_table)

#if 0
#define amg__i4_ripple16_lookup1(carry_in, tuple3) \
	amg__select_3d##carry_in( tuple3

#define amg__i4_ripple16_lookup0(c,a, table) \
	amg__i4_ripple16_lookup1(c,amg__select3_18n(a,table)))
#endif

#if 0
#define amg__i4_ripple16(c,a,b,next) \
	amg__i4_ripple_lookup0(c,a,amg__i4_ripple16_table##b), \
	next(amg__i4_ripple_lookup0(c,a,amg__i4_ripple16_carry##b)

#define amg__i4_ripple16_half(c,a,b) \
	amg__i4_ripple_lookup0(c,a,amg__i4_ripple16_carry##b)
#endif

#if 0
//#define amg__i4decr_table  16,0,1,2,3,4,5,6,7, 8, 9,10,11,12,13,14
#define amg__i4decr_ripple 16,0,1,2,3,4,5,6,7, 8, 9,10,11,12,13,14,15
#define amg__i4decr_wrap   15,0,1,2,3,4,5,6,7, 8, 9,10,11,12,13,14,15
#endif

#if 0
#define amg__i4incr_table0  1,2,3,4,5,6,7,8, 9,10,11,12,13,14,15, 0
#define amg__i4incr_table1  2,3,4,5,6,7,8,9,10,11,12,13,14,15, 0, 1
#define amg__i4incc_table0  0,0,0,0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 1
#define amg__i4incc_table1  0,0,0,0,0,0,0,0, 0, 0, 0, 0, 0, 0, 1, 1
#define amg__i4inci_table0  0,1,2,3,4,5,6,7, 8, 9,10,11,12,13,14,15
#define amg__i4inci_table1  amg__i4incr_table0
#endif

#if defined(AMG_PP_UNITTESTS_ENABLED) || \
	!defined(AMG_PP_MACRO_COUNT_CONSERVATION_LEVEL) || \
	AMG_PP_MACRO_COUNT_CONSERVATION_LEVEL <= 2 \

/* Below are tables that implement common ALU operations
// while being mostly-not-redundant in nature.
//
// This means that it is always possible to implement
// other basic ALU operations in terms of these with
// no more than 1-2 additional operations/instructions;
//
// Example:
//   NAND(x) can be composed using NOT(AND(x)),
//   so we don't NEED a table for it. Though if we
//   aren't conserving macro count, we would WANT
//   to have fast tables for it (and everything else)
//   and always do it in 1 instruction.
//
// This also applies to table symmetry.
//
// Example:
//   `amg_i4_sub` can use the same table
//   as `amg_i4_add` due to symmetry properties
//   in the table and modular arithmetic, though
//   it does take some extra macro logic to actually
//   mirror values in a way that exploits the symmetry.
//
// When we want to spend more macros on having
// table lookups for EVERYTHING, then we define
// those in a different section.
*/

#define amg__i4add_ripple0   15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15, 0
#define amg__i4add_ripple1    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15, 0, 1
#define amg__i4add_ripple2    1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15, 0, 1, 2
#define amg__i4add_ripple3    2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15, 0, 1, 2, 3
#define amg__i4add_ripple4    3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4
#define amg__i4add_ripple5    4, 5, 6, 7, 8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5
#define amg__i4add_ripple6    5, 6, 7, 8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6
#define amg__i4add_ripple7    6, 7, 8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7
#define amg__i4add_ripple8    7, 8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8
#define amg__i4add_ripple9    8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
#define amg__i4add_ripple10   9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10
#define amg__i4add_ripple11  10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11
#define amg__i4add_ripple12  11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12
#define amg__i4add_ripple13  12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13
#define amg__i4add_ripple14  13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14
#define amg__i4add_ripple15  14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15

#define amg__i4add_carry0   0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2
#define amg__i4add_carry1   1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2
#define amg__i4add_carry2   1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2
#define amg__i4add_carry3   1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2
#define amg__i4add_carry4   1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2
#define amg__i4add_carry5   1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2
#define amg__i4add_carry6   1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2
#define amg__i4add_carry7   1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2
#define amg__i4add_carry8   1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2
#define amg__i4add_carry9   1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2
#define amg__i4add_carry10  1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2
#define amg__i4add_carry11  1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2
#define amg__i4add_carry12  1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2
#define amg__i4add_carry13  1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2
#define amg__i4add_carry14  1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
#define amg__i4add_carry15  1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2

#endif

#if !defined(AMG_PP_MACRO_COUNT_CONSERVATION_LEVEL) || \
	AMG_PP_MACRO_COUNT_CONSERVATION_LEVEL <= 1 || \
	defined(AMG_PP_UNITTESTS_ENABLED)

// a-b = amg__i4sub_ripple##b[a]
#define amg__i4sub_ripple0   15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15, 0
#define amg__i4sub_ripple1   14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15
#define amg__i4sub_ripple2   13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14
#define amg__i4sub_ripple3   12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13
#define amg__i4sub_ripple4   11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12
#define amg__i4sub_ripple5   10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11
#define amg__i4sub_ripple6    9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10
#define amg__i4sub_ripple7    8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
#define amg__i4sub_ripple8    7, 8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8
#define amg__i4sub_ripple9    6, 7, 8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7
#define amg__i4sub_ripple10   5, 6, 7, 7, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6
#define amg__i4sub_ripple11   4, 5, 6, 7, 7, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5
#define amg__i4sub_ripple12   3, 4, 5, 6, 7, 7, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4
#define amg__i4sub_ripple13   2, 3, 4, 5, 6, 7, 7, 9,10,11,12,13,14,15, 0, 1, 2, 3
#define amg__i4sub_ripple14   1, 2, 3, 4, 5, 6, 7, 7, 9,10,11,12,13,14,15, 0, 1, 2
#define amg__i4sub_ripple15   0, 1, 2, 3, 4, 5, 6, 7, 7, 9,10,11,12,13,14,15, 0, 1

// carry(a-b) = amg__i4sub_carry##b[a]
#define amg__i4sub_carry0     0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2
#define amg__i4sub_carry1     0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
#define amg__i4sub_carry2     0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
#define amg__i4sub_carry3     0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1
#define amg__i4sub_carry4     0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1
#define amg__i4sub_carry5     0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1
#define amg__i4sub_carry6     0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1
#define amg__i4sub_carry7     0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1
#define amg__i4sub_carry8     0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1
#define amg__i4sub_carry9     0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1
#define amg__i4sub_carry10    0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1
#define amg__i4sub_carry11    0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1
#define amg__i4sub_carry12    0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1
#define amg__i4sub_carry13    0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1
#define amg__i4sub_carry14    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1
#define amg__i4sub_carry15    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1

#define amg__i4add_fast(c,a,b,next) \
	amg__i4_ripple_lookup0(c,a,amg__i4add_ripple##b), \
	next(amg__i4_ripple_lookup0(c,a,amg__i4add_carry##b)

#define amg__i4add_half_fast(c,a,b) \
	amg__i4_ripple_lookup0(c,a,amg__i4add_ripple##b)

#define amg__i4sub_fast(c,a,b,next) \
	amg__i4_ripple_lookup0(c,a,amg__i4sub_ripple##b), \
	next(amg__i4_ripple_lookup0(c,a,amg__i4sub_carry##b)

#define amg__i4sub_half_fast(c,a,b) \
	amg__i4_ripple_lookup0(c,a,amg__i4sub_ripple##b)


/* TODO: Implement bitshifts. */
/* These might be their own optimization section:
// Conservation Level 0-1: Full 16-wide shift-in/shift-out tables?
// Conservation Level 2:   The below tables. A middle-ground.
// Conservation Level 3:   The below tables, but in single-macro 2D tables.
*/
#define amg__i4_shl_out0  0,1,2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15, 0, 0
#define amg__i4_shl_out1  0,2,4, 6, 8,10,12,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define amg__i4_shl_out2  0,4,8,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define amg__i4_shl_out3  0,8,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

#define amg__i4_shl_in0   0,1,2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15, 0, 0
#define amg__i4_shl_in1   0,0,0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
#define amg__i4_shl_in2   0,0,0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4
#define amg__i4_shl_in3   0,0,1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8

#define amg__i4_shr_out0  0,1,2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15, 0, 0
#define amg__i4_shr_out1  0,0,1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8
#define amg__i4_shr_out2  0,0,0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4
#define amg__i4_shr_out3  0,0,0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1

#define amg__i4_shr_in0   0,1,2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15, 0, 0
#define amg__i4_shr_in1   0,8,0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8
#define amg__i4_shr_in2   0,4,8,12, 0, 4, 8,12, 0, 4, 8,12, 0, 4, 8,12, 0, 4
#define amg__i4_shr_in3   0,2,4, 6, 8,10,12,14, 0, 2, 4, 6, 8,10,12,14, 0, 2

#define amg__i4_or_table0    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,0,0
#define amg__i4_or_table1    1, 1, 3, 3, 5, 5, 7, 7, 9, 9,11,11,13,13,15,15,0,0
#define amg__i4_or_table2    2, 3, 2, 3, 6, 7, 6, 7,10,11,12,11,14,15,14,15,0,0
#define amg__i4_or_table3    3, 3, 3, 3, 7, 7, 7, 7,11,11,11,11,15,15,15,15,0,0
#define amg__i4_or_table4    4, 5, 6, 7, 4, 5, 6, 7,12,13,14,15,12,13,14,15,0,0
#define amg__i4_or_table5    5, 5, 7, 7, 5, 5, 7, 7,13,13,15,15,13,13,15,15,0,0
#define amg__i4_or_table6    6, 7, 6, 7, 6, 7, 6, 7,14,15,14,15,14,15,14,15,0,0
#define amg__i4_or_table7    7, 7, 7, 7, 7, 7, 7, 7,15,15,15,15,15,15,15,15,0,0
#define amg__i4_or_table8    8, 9,10,11,12,13,14,15, 8, 9,10,11,12,13,14,15,0,0
#define amg__i4_or_table9    9, 9,11,11,13,13,15,15, 9, 9,11,11,13,13,15,15,0,0
#define amg__i4_or_table10  10,11,12,11,14,15,14,15,10,11,10,11,14,15,14,15,0,0
#define amg__i4_or_table11  11,11,11,11,15,15,15,15,11,11,11,11,15,15,15,15,0,0
#define amg__i4_or_table12  12,13,14,15,12,13,14,15,12,13,14,15,12,13,14,15,0,0
#define amg__i4_or_table13  13,13,15,15,13,13,15,15,13,13,15,15,13,13,15,15,0,0
#define amg__i4_or_table14  14,15,14,15,14,15,14,15,14,15,14,15,14,15,14,15,0,0
#define amg__i4_or_table15  15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0

#define amg__i4_and_table0   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0
#define amg__i4_and_table1   0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,0,0
#define amg__i4_and_table2   0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 2, 2,0,0
#define amg__i4_and_table3   0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3,0,0
#define amg__i4_and_table4   0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 4, 4, 4, 4,0,0
#define amg__i4_and_table5   0, 1, 0, 1, 4, 5, 4, 5, 0, 1, 0, 1, 4, 5, 4, 5,0,0
#define amg__i4_and_table6   0, 0, 2, 2, 4, 4, 6, 6, 0, 0, 2, 2, 4, 4, 6, 6,0,0
#define amg__i4_and_table7   0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7,0,0
#define amg__i4_and_table8   0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8,0,0
#define amg__i4_and_table9   0, 1, 0, 1, 0, 1, 0, 1, 8, 9, 8, 9, 8, 9, 8, 9,0,0
#define amg__i4_and_table10  0, 0, 2, 2, 0, 0, 2, 2, 8, 8,10,10, 8, 8,10,10,0,0
#define amg__i4_and_table11  0, 1, 2, 3, 0, 1, 2, 3, 8, 9,10,11, 8, 9,10,11,0,0
#define amg__i4_and_table12  0, 0, 0, 0, 4, 4, 4, 4, 8, 8, 8, 8,12,12,12,12,0,0
#define amg__i4_and_table13  0, 1, 0, 1, 4, 5, 4, 5, 8, 9, 8, 9,12,13,12,13,0,0
#define amg__i4_and_table14  0, 0, 2, 2, 4, 4, 6, 6, 8, 8,10,10,12,12,14,14,0,0
#define amg__i4_and_table15  0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,0,0

#define amg__i4_xor_table0   0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,0,0
#define amg__i4_xor_table1   1, 0, 3, 2, 5, 4, 7, 6, 9, 8,11,10,13,12,15,14,0,0
#define amg__i4_xor_table2   2, 3, 0, 1, 6, 7, 4, 5,10,11, 8, 9,14,15,12,13,0,0
#define amg__i4_xor_table3   3, 2, 1, 0, 7, 6, 5, 4,11,10, 9, 8,15,14,13,12,0,0
#define amg__i4_xor_table4   4, 5, 6, 7, 0, 1, 2, 3,12,13,14,15, 8, 9,10,11,0,0
#define amg__i4_xor_table5   5, 4, 7, 6, 1, 0, 3, 2,13,12,15,14, 9, 8,11,10,0,0
#define amg__i4_xor_table6   6, 7, 4, 5, 2, 3, 0, 1,14,15,12,13,10,11, 8, 9,0,0
#define amg__i4_xor_table7   7, 6, 5, 4, 3, 2, 1, 0,15,14,13,12,11,10, 9, 8,0,0
#define amg__i4_xor_table8   8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7,0,0
#define amg__i4_xor_table9   9, 8,11,10,12,12,15,14, 1, 0, 3, 2, 5, 4, 7, 6,0,0
#define amg__i4_xor_table10 10,11, 8, 9,14,15,12,13, 2, 3, 0, 1, 6, 7, 4, 5,0,0
#define amg__i4_xor_table11 11,10, 9, 8,15,14,13,12, 3, 2, 1, 0, 7, 6, 5, 4,0,0
#define amg__i4_xor_table12 12,13,14,15, 8, 9,10,11, 4, 5, 6, 7, 0, 1, 2, 3,0,0
#define amg__i4_xor_table13 13,12,15,14, 9, 8,11,10, 5, 4, 7, 6, 1, 0, 3, 2,0,0
#define amg__i4_xor_table14 14,15,12,13,10,11, 8, 9, 6, 7, 4, 5, 2, 3, 0, 1,0,0
#define amg__i4_xor_table15 15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,0,0

#define amg__i4or_fast(a,b) \
	amg__i4_ripple_lookup0(0,a,amg__i4_or_table##b)

#define amg__i4and_fast(a,b) \
	amg__i4_ripple_lookup0(0,a,amg__i4_and_table##b)

#define amg__i4xor_fast(a,b) \
	amg__i4_ripple_lookup0(0,a,amg__i4_or_table##b)

#endif //if !defined(AMG_PP_MACRO_COUNT_CONSERVATION_LEVEL) || defined(AMG_PP_UNITTESTS_ENABLED)
#if defined(AMG_PP_UNITTESTS_ENABLED) || ( \
	defined(AMG_PP_MACRO_COUNT_CONSERVATION_LEVEL) && \
	AMG_PP_MACRO_COUNT_CONSERVATION_LEVEL == 2 \
)

/* We can avoid defining the subtraction tables if we exploit
// modular arithmatic and the symmetries of the add/carry tables.
// The trade-off is that it requires more macro expansions
// to perform each subtraction. And a couple of them involve
// table expansion. So it might have a non-negligable cost.
// We only do this if we're really trying to keep macro
// definition count low.
*/


/* TODO: BUG: This subtractor implementation is BROKEN.
// It does at least expand fully and yield numbers.
// It just yields incorrect numbers.
// This is entirely fixable, but my brain is mush rn,
// and if this algo is important, it'd be better to
// finish tuning it in a more awake and functioning state.
// Basically it needs `amg__3sub_table` and `amg__16sub_table`
// adjusted, with a possibility of adjusting `a` instead of `b`.
*/
#define amg__i4sub_unadd0(c,a,b,next,table_16sub,table_3sub) \
	amg__i4sub_unadd1( \
		amg_select_3n(c,table_3sub),   a, \
		amg_select_16n(b,table_16sub), next)

#define amg__i4sub_unadd1(c,a,b,next) amg__i4sub_unadd2(c,a,b,next)
#define amg__i4sub_unadd2(c,a,b,next) \
	amg__i4_ripple_lookup0(c,a,amg__i4add_ripple##b), \
	next(amg__i4_ripple_lookup0(c,a,amg__i4add_carry##b)

#define amg__i4sub_unadd_half0(c,a,b,table_16sub,table_3sub) \
	amg__i4sub_unadd_half1( \
		amg_select_3n(c,table_3sub),   a, \
		amg_select_16n(b,table_16sub))

#define amg__i4sub_unadd_half1(c,a,b) amg__i4sub_unadd_half2(c,a,b)
#define amg__i4sub_unadd_half2(c,a,b) \
	amg__i4_ripple_lookup0(c,a,amg__i4add_ripple##b)

#define amg__3sub_table    2,1,0
#define amg__16sub_table   0,15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 1

/* if defined(AMG_PP_UNITTESTS_ENABLED) || ( \
//     defined(AMG_PP_MACRO_COUNT_CONSERVATION_LEVEL) && \
//     AMG_PP_MACRO_COUNT_CONSERVATION_LEVEL < 3 \
// )
*/
#endif
#if defined(AMG_PP_UNITTESTS_ENABLED) || ( \
	defined(AMG_PP_MACRO_COUNT_CONSERVATION_LEVEL) && \
	AMG_PP_MACRO_COUNT_CONSERVATION_LEVEL >= 3 \
)

/* The addition tables can be folded such that
// each becomes a single macro definition.
//
// The downside is that this requires extra macro expansions
// to do (table+row) lookup instead of just (table) lookup.
// This may also be more taxing on the preprocessor, as the
// outer expansion must copy/analyse much larger macro bodies
// (those of the tables) during each operation.
*/

#define amg__i4add_ripple \
	(15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15, 0),\
	( 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15, 0, 1),\
	( 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15, 0, 1, 2),\
	( 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15, 0, 1, 2, 3),\
	( 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4),\
	( 4, 5, 6, 7, 8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5),\
	( 5, 6, 7, 8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6),\
	( 6, 7, 8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7),\
	( 7, 8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8),\
	( 8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9),\
	( 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10),\
	(10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11),\
	(11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12),\
	(12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13),\
	(13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14),\
	(14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15)

#define amg__i4add_carry \
	(0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2),\
	(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2),\
	(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2),\
	(1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2),\
	(1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2),\
	(1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2),\
	(1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2),\
	(1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2),\
	(1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2),\
	(1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2),\
	(1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2),\
	(1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2),\
	(1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2),\
	(1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2),\
	(1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2),\
	(1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2)

// a-b = amg__i4sub_ripple##b[a]
#define amg__i4sub_ripple \
	(15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15, 0),\
	(14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15),\
	(13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14),\
	(12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13),\
	(11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12),\
	(10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11),\
	( 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10),\
	( 8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9),\
	( 7, 8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7, 8),\
	( 6, 7, 8, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6, 7),\
	( 5, 6, 7, 7, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5, 6),\
	( 4, 5, 6, 7, 7, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4, 5),\
	( 3, 4, 5, 6, 7, 7, 9,10,11,12,13,14,15, 0, 1, 2, 3, 4),\
	( 2, 3, 4, 5, 6, 7, 7, 9,10,11,12,13,14,15, 0, 1, 2, 3),\
	( 1, 2, 3, 4, 5, 6, 7, 7, 9,10,11,12,13,14,15, 0, 1, 2),\
	( 0, 1, 2, 3, 4, 5, 6, 7, 7, 9,10,11,12,13,14,15, 0, 1)

// carry(a-b) = amg__i4sub_carry##b[a]
#define amg__i4sub_carry \
	(0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2),\
	(0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),\
	(0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),\
	(0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1),\
	(0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1),\
	(0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1),\
	(0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1),\
	(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1),\
	(0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1),\
	(0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1),\
	(0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1),\
	(0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1),\
	(0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1),\
	(0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1),\
	(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1),\
	(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1)

/* TODO: upgrade these to 3-windowed 18-wide table thingies */
#define amg__i4_unary_op(a,optable) amg_select_16n(a,optable)

#define amg__i4_binary_op_step2(a,oprow) amg_select_16n(a,oprow)
#define amg__i4_binary_op(a,b,optable) \
	amg__i4_binary_op_step2(a,amg_expand16(,amg_select_16(b,optable)))


#endif

/* -----===== Adder/Subtractor Entry Points =====---- */
/* We adjust these to use different implementations
// based on how frugal we are being with macro #define counts.
*/
#if !defined(AMG_PP_MACRO_COUNT_CONSERVATION_LEVEL) || \
	AMG_PP_MACRO_COUNT_CONSERVATION_LEVEL <= 1

/* There is no macro conservation in effect:
// So use the fastest macros we have.
// (These will be shallower and avoid large expansions,
// but require extra macro definitions to populate
// the tables that they use.)
//
// Currently, most of these are equivalent to the `_fast` versions
// defined earlier in this file.
//
// For example: `amg__i4add` is the same contents as `amg__i4add_fast`,
// and `amg__i4add_half` is the same contents as `amg__i4add_half_fast`.
//
// The macros here have been pre-expanded (e.g. manual inlining)
// just to be paranoid about wasting the preprocessor's CPU cycles.
*/

#if 0
#define amg__i4add(c,a,b,next)  amg__i4add_fast(c,a,b,next)
#define amg__i4add_half(c,a,b)  amg__i4add_half_fast(c,a,b)
//#define amg__i4sub(c,a,b,next)  amg__i4sub_fast(c,a,b,next)
//#define amg__i4sub_half(c,a,b)  amg__i4sub_half_fast(c,a,b)

#define amg__i4sub(c,a,b,next) \
	amg__i4sub_unadd0(c,a,b,next,amg__16sub_table,amg__3sub_table)
#define amg__i4sub_half(c,a,b) \
	amg__i4sub_unadd_half0(c,a,b,amg__16sub_table,amg__3sub_table)

#define amg__i4add(c,a,b,next)  amg__i4add_fast(c,a,b,next)
#define amg__i4add_half(c,a,b)  amg__i4add_half_fast(c,a,b)
#define amg__i4sub(c,a,b,next)  amg__i4sub_fast(c,a,b,next)
#define amg__i4sub_half(c,a,b)  amg__i4sub_half_fast(c,a,b)
#endif


#define amg__i4or(a,b) \
	amg__i4_ripple_lookup0(0,a,amg__i4_or_table##b)

#define amg__i4and(a,b) \
	amg__i4_ripple_lookup0(0,a,amg__i4_and_table##b)

#define amg__i4xor(a,b) \
	amg__i4_ripple_lookup0(0,a,amg__i4_or_table##b)

#define amg__i4add(c,a,b,next) \
	amg__i4_ripple_lookup0(c,a,amg__i4add_ripple##b), \
	next(amg__i4_ripple_lookup0(c,a,amg__i4add_carry##b)

#define amg__i4add_half(c,a,b) \
	amg__i4_ripple_lookup0(c,a,amg__i4add_ripple##b)

#define amg__i4sub(c,a,b,next) \
	amg__i4_ripple_lookup0(c,a,amg__i4sub_ripple##b), \
	next(amg__i4_ripple_lookup0(c,a,amg__i4sub_carry##b)

#define amg__i4sub_half(c,a,b) \
	amg__i4_ripple_lookup0(c,a,amg__i4sub_ripple##b)

/* -------======== Macro Count Conservation Level 2 ========------- */
#elif AMG_PP_MACRO_COUNT_CONSERVATION_LEVEL == 2

/* At macro conservation level 2, we start trying to
// eliminate redundant tables.
// This comse at the expense of somewhat deeper macro expansions.
*/

/* Addition itself is unchanged. */
#define amg__i4add(c,a,b,next) \
	amg__i4add_fast(c,a,b,next)

#define amg__i4add_half(c,a,b,next) \
	amg__i4add_half_fast(c,a,b,next)

/* Subtraction re-uses the addition table to save a table's worth of defines. */
/* But the subtraction could be slower, as it requires more expansions. */
#define amg__i4sub(c,a,b,next) \
	amg__i4sub_unadd0(c,a,b,next,amg__16sub_table,amg__3sub_table)
#define amg__i4sub_half(c,a,b) \
	amg__i4sub_unadd_half0(c,a,b,amg__16sub_table,amg__3sub_table)

/* -------======== Macro Count Conservation >= 3 ========------- */
#else /* AMG_PP_MACRO_COUNT_CONSERVATION_LEVEL >= 3 */

#define amg__i4sub(c,a,b,next) \
	amg__i4sub_2dim0(c,a,b,next,amg__16sub_table,amg__3sub_table)

#define amg__i4sub_half(c,a,b) \
	amg__i4sub_half_2dim0(c,a,b,amg__16sub_table,amg__3sub_table)

/* TODO */

#endif //defined(AMG_PP_MACRO_COUNT_CONSERVATION_LEVEL) || defined(AMG_PP_UNITTESTS_ENABLED)

#if 0
#define amg__i4addc_table0 \
	(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),\
	(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1),\
	(0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1),\
	(0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1),\
	(0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1),\
	(0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1),\
	(0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1),\
	(0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1),\
	(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1),\
	(0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1),\
	(0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1),\
	(0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1),\
	(0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1),\
	(0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1),\
	(0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1),\
	(0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1)

#define amg__i4addc_table1 \
	(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1),\
	(0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1),\
	(0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1),\
	(0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1),\
	(0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1),\
	(0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1),\
	(0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1),\
	(0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1),\
	(0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1),\
	(0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1),\
	(0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1),\
	(0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1),\
	(0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1),\
	(0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1),\
	(0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1),\
	(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1)

#endif

/** Compute the digit that results from incrementing the given 1-argument number. */
//#define amg_i4h_incr(h1)      (amg__i4_ripple1_half(2,amg__i4h##h1))
//#define amg__i4incr(d1,c)      amg__i4incr2(d1,c)
//#define amg__i4incr2(d1,c)     amg__i4_unary_op(d1,amg__i4incr_table##c)

#if 0
/** Compute the digit that results from conditionally incrementing the given 1-argument number.
///
/// This can used for carry-in calculations.
**/
#define amg__i4hinci(h1,c)    (amg__i4inci(amg__i4h##h1,0))
#define amg__i4inci(d1,c)      amg__i4inci2(d1,c)
#define amg__i4inci2(d1,c)     amg__i4_unary_op(d1,amg__i4inci_table##c)

/** Compute the carry digit from incrementing the given 1-argument number. */
#define amg__i4hincc(h1)      (amg__i4incc(amg__i4h##h1,0))
#define amg__i4incc(d1,c)      amg__i4incc2(d1,c)
#define amg__i4incc2(d1,c)     amg__i4_unary_op(d1,amg__i4incc_table##c)
#endif


#if 0
/** Compute the result of adding two 1-argument numbers. **/
#define amg_i4a1_add(ah1,bh1)   (amg__i4add(amg__i4h##ah1, amg__i4h##bh1, 0))
#define amg__i4add(ah1,bh1,c)   amg__i4add2(ah1,bh1,c)
#define amg__i4add2(ah1,bh1,c)  amg__i4_binary_op(ah1,bh1,amg__i4add_table##c)

/** Compute the carry digit from adding two 1-argument numbers. **/
#define amg_i4a1_addc(ah1,bh1)  (amg__i4addc(amg__i4h##ah1, amg__i4h##bh1, 0))
#define amg__i4addc(ah1,bh1,c)  amg__i4addc2(ah1,bh1,c)
#define amg__i4addc2(ah1,bh1,c) amg__i4_binary_op(ah1,bh1,amg__i4addc_table##c)

/** Adds the two base-16 1-tuple numbers together. **/
#define amg_i4_add(at1,at2)     (amg__i4add(amg_expand1(,at1),amg_expand1(,at2),0))
#define amg_i4t1_add(at1,at2)   (amg__i4add(amg_expand1(,at1),amg_expand1(,at2),0))
#endif

#endif
