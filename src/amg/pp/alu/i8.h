#ifndef AMG__PP_ALU_I8_INCLUDED
#define AMG__PP_ALU_I8_INCLUDED

#ifndef AMG_PP_ALU_I8_H
#define AMG_PP_ALU_I8_H "amg/pp/alu/i8.h"
#endif

#ifndef  AMG_PP_ALU_I4_H
#define  AMG_PP_ALU_I4_H "amg/pp/alu/i8.h"
#endif
#ifndef  AMG__PP_ALU_I4_INCLUDED
#include AMG_PP_ALU_I4_H
#endif

#define amg__i8noop(d2,d1)       d2,d1

/* TODO: Argument checking in C99+ compilers. (Or anything with variadic support? Pre-C99 support?) */
#if 0
/* Ugh this might be doable but it's hard to figure out. */
/* Notable difficulty: token pasting (##) doesn't work if they pass a tuple! */
#if AMG__C99_OR_GREATER
#define amg_i8h2_incr( h2,...)  amg__i8h2_argcheck (amg__i8incr, __VA_ARGS__)(amg_i4h1_##h2,amg_i4h1_##__VA_ARGS__)
#define amg_i8h2_incc( h2,...)  amg__i8h2_argcheck (amg__i8incc, __VA_ARGS__)
#define amg_i8h2c_inci(h2,...)  amg__i8h2c_argcheck(amg__i8inci, __VA_ARGS__)
#define amg_i8t2_incr( h2,...)  amg__i8t2_argcheck (amg__i8incr0,__VA_ARGS__)

#define amg_i8h2_decr( h2,...)  amg__i8h2_argcheck (amg__i8decr, __VA_ARGS__)
#define amg_i8h2_decc( h2,...)  amg__i8h2_argcheck (amg__i8decc, __VA_ARGS__)
#define amg_i8h2c_deci(h2,...)  amg__i8h2c_argcheck(amg__i8deci, __VA_ARGS__)
#define amg_i8t2_decr( h2,...)  amg__i8t2_argcheck (amg__i8decr0,__VA_ARGS__)

#define amg_i8h2_add( ...)      amg__i8h2h2_argcheck (amg__i8add,  __VA_ARGS__)
#define amg_i8h2_addc(...)      amg__i8h2h2_argcheck (amg__i8addc, __VA_ARGS__)
#define amg_i8h2_addi(...)      amg__i8h2h2c_argcheck(amg__i8addi, __VA_ARGS__)
#define amg_i8t2_add( at2,...)  amg__i8t2t2_argcheck (amg__i8add0, __VA_ARGS__)

#define amg_i8h2_sub(...)   amg__i8h2h2_argcheck (amg__i8sub,  __VA_ARGS__)
#define amg_i8h2_subc(...)  amg__i8h2h2_argcheck (amg__i8subc, __VA_ARGS__)
#define amg_i8h2_subi(...)  amg__i8h2h2c_argcheck(amg__i8subi, __VA_ARGS__)
#define amg_i8t2_sub(...)   amg__i8t2t2_argcheck (amg__i8sub0, __VA_ARGS__)

#else

#define amg_i8h2_incr( h2,h1)   amg__i8h2_argcheck (amg__i8incr, amg_i4h1_##h2, amg_i4h1_##h1)
#define amg_i8h2_incc( h2,h1)   amg__i8h2_argcheck (amg__i8incc, amg_i4h1_##h2, amg_i4h1_##h1)
#define amg_i8h2c_inci(h2,h1,c) amg__i8h2c_argcheck(amg__i8inci, amg_i4h1_##h2, amg_i4h1_##h1,c)
#define amg_i8t2_incr( tuple)  amg__i8t2_argcheck (amg__i8incr0,tuple)

#define amg_i8h2_decr( h2,h1)   amg__i8h2_argcheck (amg__i8decr, amg_i4h1_##h2, amg_i4h1_##h1)
#define amg_i8h2_decc( h2,h1)   amg__i8h2_argcheck (amg__i8decc, amg_i4h1_##h2, amg_i4h1_##h1)
#define amg_i8h2c_deci(h2,h1,c) amg__i8h2c_argcheck(amg__i8deci, amg_i4h1_##h2, amg_i4h1_##h1,c)
#define amg_i8t2_decr( tuple)  amg__i8t2_argcheck (amg__i8decr0,tuple)

#define amg_i8h2_add( ah2,ah1, bd2,bd1)     amg__i8h2h2_argcheck (amg__i8add,  amg_i4h1_##ah2, amg_i4h1_##ah1,   amg_i4h1_##bd2, amg_i4h1_##bd1)
#define amg_i8h2_addc(ah2,ah1, bd2,bd1)     amg__i8h2h2_argcheck (amg__i8addc, amg_i4h1_##ah2, amg_i4h1_##ah1,   amg_i4h1_##bd2, amg_i4h1_##bd1)
#define amg_i8h2_addi(ah2,ah1, bd2,bd1, c)  amg__i8h2h2c_argcheck(amg__i8addi, amg_i4h1_##ah2, amg_i4h1_##ah1,   amg_i4h1_##bd2, amg_i4h1_##bd1, c)
#define amg_i8t2_add( atuple, btuple)     amg__i8t2t2_argcheck (amg__i8add0, atuple, btuple)

#define amg_i8h2_sub( ah2,ah1, bd2,bd1)     amg__i8h2h2_argcheck (amg__i8sub,  amg_i4h1_##ah2, amg_i4h1_##ah1,   amg_i4h1_##bd2, amg_i4h1_##bd1)
#define amg_i8h2_subc(ah2,ah1, bd2,bd1)     amg__i8h2h2_argcheck (amg__i8subc, amg_i4h1_##ah2, amg_i4h1_##ah1,   amg_i4h1_##bd2, amg_i4h1_##bd1)
#define amg_i8h2_subi(ah2,ah1, bd2,bd1, c)  amg__i8h2h2c_argcheck(amg__i8subi, amg_i4h1_##ah2, amg_i4h1_##ah1,   amg_i4h1_##bd2, amg_i4h1_##bd1, c)
#define amg_i8t2_sub( atuple, btuple)     amg__i8t2t2_argcheck (amg__i8sub0, atuple, btuple)
#endif
#endif

//#define amg__i8nibrev(...)  #__VA_ARGS__
//#define amg__i8nibrev(d2,d1)   d1,d2
#define amg__i8nibrevt(d2,d1) (d1,d2)
#define amg__i8nibrevtt(tuple) amg__i8nibrevt tuple

//#define amg_print0(...) #__VA_ARGS__
//#define amg_print(...) amg_print0(__VA_ARGS__)




#define amg_i8_to_bool(tuple)   amg__i8bool2 tuple )
#define amg_i8t_to_bool(tuple)  amg__i8bool2 tuple )
#define amg_i8h_to_bool(h2,h1)  amg__i8bool2(amg_i4h1_##h2, amg_i4h1_##h1))

#ifndef AMG_PP_HEX_OCTETS_DISABLED
#define amg_i8hh_to_bool(hh) \
	amg__i8bool0(amg_i8hh_##hh)

#define amg__i8bool0(expand) amg__i8bool1(expand)
#endif

#define amg__i8bool1(d2,d1)  amg__i8bool2(d2,d1))
#define amg__i8bool2(d2,d1)  amg__i4_to_bool(0,d1,amg__i4_to_bool_half),d2

/** Returns an 8-bit integer that is 1 greater than the input.
///
/// The input is a 2-tuple of 4-bit integers.
///
/// The result is an 8-bit integer represented
/// by a 2-tuple of 4-bit integers.
///
/// The math assumes a two's-complement representation.
///
/// This function does not have carry-in or carry-out functionality.
///
/// Incrementing past the integer's range (overflow) will result in
/// (the very common) wrap-around behavior:
/// ```
/// amg_pp_assert(amg_i8_eq((0,0),amg_i8_incr((F,F))))
/// amg_pp_assert(amg_i8_eq((F,F),amg_i8_decr((0,0))))
/// ```
**/
#define amg_i8_incr(tuple)     amg__i8incr0 tuple

/** ditto */
#define amg_i8t_incr(tuple)   amg__i8incr0 tuple

/** Adds 1 to a 8-bit integer directly written as hex digits.
///
/// Specifically:
/// It converts 2 hexadecimal digit arguments into an 8-bit integer,
/// then increments that 8-bit integer number by 1.
///
/// The result is an 8-bit integer represented
/// by a 2-tuple of 4-bit integers.
///
/// The math assumes a two's-complement representation.
///
/// This function does not have carry-in or carry-out functionality.
///
/// Incrementing past the integer's range (overflow) will result in
/// (the very common) wrap-around behavior:
/// ```
/// amg_pp_assert(amg_i8_eq((0,0),amg_i8h2_incr(F,F)))
/// amg_pp_assert(amg_i8_eq((F,F),amg_i8h2_decr(0,0)))
/// ```
///
/// Warning: Do not return hexadecimal digits from other macros
///   (e.g. to use as input for this macro). Any time a macro
///   returns a raw hexadecimal digit, it is possible for that
///   digit to _also_ be a valid macro identifier (at least for
///   the values `A`, `B`, `C`, `D`, `E`, and `F`). If code elsewhere
///   has defined macros with those names, then the hexadecimal
///   digits may expand into something unexpected before being
///   scanned as arguments to this function. It is, however,
///   perfectly safe to write them as arguments to this macro,
///   or use empty-token-pasting to safely transfer them from
///   the caller's list of macro arguments. This macro will
///   use empty-token-pasting to ensure that arguments are not
///   expanded. It just can't prevent them from expanding _before_ that.
///
/// Example dangerous usage:
/// ```
/// #define myhex A
/// #define otherhex(arg) arga
///
/// expand amg_i8hh_incr(0,myhex) // Bad: `A` could expand before `amg_i8hh_incr`
/// expand amg_i8hh_incr(0,otherhex(C)) // Bad: `otherhex`'s return could expand early.
/// ```
///
/// Example safe usage:
/// ```
/// expand amg_i8hh_incr(0,A) // Good: `amg_i8hh_incr` can prevent `A` from expanding.
///
/// // Good: both `my_increment` and `amg_i8hh_incr` are
/// //       preventing `A` from expanding too early.
/// #define my_increment(e,x,y) amg_i8h2_incr(e##x,e##y)
/// expand my_increment(,0,A)
/// ```
**/
#define amg_i8h_incr(h2,h1)  amg__i8incr0(amg_i4h1_##h2, amg_i4h1_##h1)

#ifndef AMG_PP_HEX_OCTETS_DISABLED
#define amg_i8hh_incr(hh) \
	amg__i8incr0(amg_i8hh_##hh)
#endif

#define amg__i8incr0(d2,d1)  amg__i8nibrevtt((amg__i8incr1(d2,d1))))
#define amg__i8incr1(d2,d1)  amg__i4_ripple1(2,d1,amg__i4_ripple1_half),d2

/* -------======== DECR ========------- */
#define amg_i8_decr(tuple)   amg__i8decr0 tuple
#define amg_i8t_decr(tuple)  amg__i8decr0 tuple
#define amg_i8h_decr(h2,h1)  amg__i8decr0(amg_i4h1_##h2, amg_i4h1_##h1)

#ifndef AMG_PP_HEX_OCTETS_DISABLED
#define amg_i8hh_decr(hh) \
	amg__i8decr0(amg_i8hh_##hh)
#endif

#define amg__i8decr0(d2,d1)  amg__i8nibrevtt((amg__i8decr1(d2,d1))))
#define amg__i8decr1(d2,d1)  amg__i4_ripple1(0,d1,amg__i4_ripple1_half),d2

/* -------======== OR ========------- */
#define amg_i8_or(tuple_a, tuple_b) \
	amg__i8or0(amg__expand2 tuple_a, amg__expand2 tuple_b)
#define amg_i8t_or(tuple_a, tuple_b) \
	amg__i8or0(amg__expand2 tuple_a, amg__expand2 tuple_b)
#define amg_i8h_or(ah2,ah1, bh2,bh1) amg__i8or1(amg_i4h1_##h2, amg_i4h1_##h1)

#ifndef AMG_PP_HEX_OCTETS_DISABLED
#define amg_i8hh_or(ahh1,bhh1) \
	amg__i8or0(amg_i8hh_##ahh1,amg_i8hh_##bhh1)
#endif

#define amg__i8or0(tuple_a, tuple_b) amg__i8or1(tuple_a,tuple_b)
#define amg__i8or1(ad2,ad1, bd2,bd1) (\
	amg__i4_ripple_lookup0(0,ad2,amg__i4_or_table##bd2), \
	amg__i4_ripple_lookup0(0,ad1,amg__i4_or_table##bd1)  \
)

/* -------======== AND ========------- */

#define amg_i8_and(tuple_a, tuple_b) \
	amg__i8and0(amg__expand2 tuple_a, amg__expand2 tuple_b)
#define amg_i8t_and(tuple_a, tuple_b) \
	amg__i8and0(amg__expand2 tuple_a, amg__expand2 tuple_b)
#define amg_i8h_and(ah2,ah1, bh2,bh1) amg__i8and1(amg_i4h1_##h2, amg_i4h1_##h1)

#ifndef AMG_PP_HEX_OCTETS_DISABLED
#define amg_i8hh_and(ahh1,bhh1) \
	amg__i8and0(amg_i8hh_##ahh1,amg_i8hh_##bhh1)
#endif

#define amg__i8and0(tuple_a, tuple_b) amg__i8and1(tuple_a,tuple_b)
#define amg__i8and1(ad2,ad1, bd2,bd1) (\
	amg__i4_ripple_lookup0(0,ad2,amg__i4_and_table##bd2), \
	amg__i4_ripple_lookup0(0,ad1,amg__i4_and_table##bd1)  \
)

/* -------======== XOR ========------- */

#define amg__i8xor(a,b) (\
	amg__i4_ripple_lookup0(0,a,amg__i4_or_table##b)

/* -------======== Adders and Subtractors ========------- */

#define amg_i8h_add(ah2,ah1,bh2,bh1) \
	amg__i8add1(amg_i4h1_##ah2, amg_i4h1_##ah1, amg_i4h1_##bh2, amg_i4h1_##bh1)
#define amg_i8_add(tuple_a,tuple_b) \
	amg__i8add0(amg_expand2(,tuple_a),amg_expand2(,tuple_b))
#define amg_i8t_add(tuple_a,tuple_b) \
	amg__i8add0(amg_expand2(,tuple_a),amg_expand2(,tuple_b))

#ifndef AMG_PP_HEX_OCTETS_DISABLED
#define amg_i8hh_add(ahh1,bhh1) \
	amg__i8add0(amg_i8hh_##ahh1,amg_i8hh_##bhh1)
#endif

#define amg__i8add0(tuple_a,tuple_b)  amg__i8add1(tuple_a,tuple_b)
#define amg__i8add1(ad2,ad1, bd2,bd1) amg__i8nibrevtt((amg__i8add2(ad2,ad1, bd2,bd1))))
#define amg__i8add2(ad2,ad1, bd2,bd1) amg__i4add(1,ad1,bd1,amg__i4add_half) ,ad2,bd2

#define amg_i8h_sub(ah2,ah1,bh2,bh1) \
	amg__i8sub1(amg_i4h1_##ah2, amg_i4h1_##ah1, amg_i4h1_##bh2, amg_i4h1_##bh1)
#define amg_i8_sub(tuple_a,tuple_b) \
	amg__i8sub0(amg_expand2(,tuple_a),amg_expand2(,tuple_b))
#define amg_i8t_sub(tuple_a,tuple_b) \
	amg__i8sub0(amg_expand2(,tuple_a),amg_expand2(,tuple_b))

#ifndef AMG_PP_HEX_OCTETS_DISABLED
#define amg_i8hh_sub(ahh1,bhh1) \
	amg__i8sub0(amg_i8hh_##ahh1,amg_i8hh_##bhh1)
#endif

#define amg__i8sub0(tuple_a,tuple_b)  amg__i8sub1(tuple_a,tuple_b)
#define amg__i8sub1(ad2,ad1, bd2,bd1) amg__i8nibrevtt((amg__i8sub2(ad2,ad1, bd2,bd1))))
#define amg__i8sub2(ad2,ad1, bd2,bd1) amg__i4sub(1,ad1,bd1,amg__i4sub_half) ,ad2,bd2

#if 0
#define amg__i8add(ad2,ad1,bd2,bd1,c) \
	amg__i4add(ad2,bd2,amg__i4addc(ad1,bd1,c)), \
	amg__i4add(ad1,bd1,c)
#define amg__i8addc(ad2,ad1,bd2,bd1,c) \
	amg__i4addc(ad2,bd2,amg__i4addc(ad1,bd1,c))
#endif

#if 0
/* Discontinued because it turns out to make more sense
// to just expand pritive i4 macros at every word width.
*/
/** Increments the base-16 2-argument-tuple by 1, with carry.
///
/// Output is a 3-argument-tuple whose left-most digit is the carry digit.
**/
#define amg_i8a2c3_incr(h2,h1)   (amg__i8a2c3__incr(0,amg_i4h1_##h2,amg_i4h1_##h1))
#define amg__i8a2c3__incr(d2,d1) amg_i8a3_incr(0,d2,d1)
#endif

#endif
