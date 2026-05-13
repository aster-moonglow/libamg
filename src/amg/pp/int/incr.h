#ifndef AMG_dummy_guard
#ifndef AMG_pp_int_incr_included
#define AMG_pp_int_incr_included 1

#ifndef AMG_pp_int_incr_h
#define AMG_pp_int_incr_h "amg/pp/int/incr.h"
#endif

#define AMG_stringize(x) #x
#define amgpp_stringize(x) AMG_stringize(x)

/* TODO: Mess with Compiler Explorer (godbolt.org) and see what we can get away with. */
#if defined(__INTEL_COMPILER) || defined(_MSC_VER) || AMG_USE_MSVC_ERROR_PRAGMA
	#define AMG_error(msg) __pragma(message(#msg))
	#define AMG__ADD_LOC_TO_PP_ERRORS
#elif defined(__GNUC__) || defined(__clang__) || AMG_USE_GCC_ERROR_PRAGMA
	#define AMG_errorgcc(pragma_tokens) _Pragma(#pragma_tokens)
	#define AMG_error(msg) AMG_errorgcc(GCC error msg)
#else
	#define AMG_error(msg) ~##msg
#endif

#ifdef AMG__ADD_LOC_TO_PP_ERRORS
	#define amgpp_error(msg) AMG_error(__FILE__ "(" amgpp_stringize(__LINE__) "): error: " msg)
#else
	#define amgpp_error(msg) AMG_error(msg)
#endif


#define AMG_call(fn,args) fn args


#define AMG_e
#define AMG_iget2a(d0,d1)     d0,d1,AMG_iget2b AMG_e
#define AMG_iget2b(d0,d1)     d0,d1,AMG_iget2a AMG_e
#define AMG_igetsz(sz,d0,d1)  sz,d0,d1,AMG_iget2a AMG_e
#define AMG_unget_AMG_iget2a
#define AMG_unget_AMG_iget2b
#define AMG_unget_

/* The largest variable-width integer possible, in bytes.
//
// This is constrained by the number of entries in certain tables:
// * `AMG_int_width_incr`
// * `AMG_int_width_is_zero`
// * `AMG_uop`
// * `AMG_bop`
//
// So this number can be increased by adding more entries to those tables.
// This is a trade-off between integer range and the number of macro
// definitions that we are requiring the preprocessor to remember.
//
// Notably, ISO C only guarantees so many macro definitions:
// C89 §2.2.4.1 "Translation limits": "1024 macro identifiers simultaneously defined in one translation unit"
// C99 §5.2.4.1 "Translation limits": "4095 macro identifiers simultaneously defined in one preprocessing translation unit"
//
// In practice, compilers will probably allow many more.
// But to offer (true!) C89 compatibility, it is necessary to provide
// ways to scale down the number of macro definitions in the library
// to under `1024`. That is... a small number!
//
// So we are incentivized to be stingy.
//
// On the kinds of systems where C89 is the only level of C compiler available
// (e.g. vintage systems, and possibly some proprietary legacy systems),
// then it may be reasonable to limit oneself to 32-bit (or less) wide
// macro integers.
//
// But on other systems, where more modern compilers are available,
// it makes more sense to use lotsa macro definitions (big flat tables)
// to provide faster arithmetic and wider integer ranges.
*/
#define AMG_int_width_max    16

/* This is 3 different tables rolled into 1 to save on macro definitions. */
/* The results for a lookup are:
// (0) increment result
// (1) decrement result
// (2) "Borrowing" Zero Flag  / b0: 1 if number is 0 after decrement, otherwise returns 0
// (3) Nominal Zero Flag      / n0: 1 if original number was 0, otherwise returns 0
//
// There isn't any particular math to the results provided.
// These outputs were chosen because they are important
// in some part of the code for variable-width-integers.
//
// Notably, we have avoided requiring any of these operations:
// * Add
// * Subtract
// * Compare (eq, less-than, greater-than)
// * And any other binary operation
//
// Because binary operations require O(n^2) macro definitions to represent,
// or alternatively require n-wide tables to represent (which requires O(n)
// macro definitions, but is potentially quite slower to expand).
*/
#define AMG_int_width_indecr0    1, 0,1,1
#define AMG_int_width_indecr1    2, 0,1,0
#define AMG_int_width_indecr2    3, 1,0,0
#define AMG_int_width_indecr3    4, 2,0,0
#define AMG_int_width_indecr4    5, 3,0,0
#define AMG_int_width_indecr5    6, 4,0,0
#define AMG_int_width_indecr6    7, 5,0,0
#define AMG_int_width_indecr7    8, 6,0,0
#define AMG_int_width_indecr8    9, 7,0,0
#define AMG_int_width_indecr9   10, 8,0,0
#define AMG_int_width_indecr10  11, 9,0,0
#define AMG_int_width_indecr11  12,10,0,0
#define AMG_int_width_indecr12  13,11,0,0
#define AMG_int_width_indecr13  14,12,0,0
#define AMG_int_width_indecr14  15,13,0,0
#define AMG_int_width_indecr15  16,14,0,0
#define AMG_int_width_indecr16  17,15,0,0

#define AMG_bool0   0
#define AMG_bool1   1
#define AMG_bool2   1
#define AMG_bool3   1
#define AMG_bool4   1
#define AMG_bool5   1
#define AMG_bool6   1
#define AMG_bool7   1
#define AMG_bool8   1
#define AMG_bool9   1
#define AMG_bool10  1
#define AMG_bool11  1
#define AMG_bool12  1
#define AMG_bool13  1
#define AMG_bool14  1
#define AMG_bool15  1

#define AMG_sign0      0
#define AMG_sign1      0
#define AMG_sign2      0
#define AMG_sign3      0
#define AMG_sign4      0
#define AMG_sign5      0
#define AMG_sign6      0
#define AMG_sign7      0
#define AMG_sign8      1
#define AMG_sign9      1
#define AMG_sign10     1
#define AMG_sign11     1
#define AMG_sign12     1
#define AMG_sign13     1
#define AMG_sign14     1
#define AMG_sign15     1

#define AMG_classify_pad0     0
#define AMG_classify_pad1     1
#define AMG_classify_pad2     1
#define AMG_classify_pad3     1
#define AMG_classify_pad4     1
#define AMG_classify_pad5     1
#define AMG_classify_pad6     1
#define AMG_classify_pad7     1
#define AMG_classify_pad8     1
#define AMG_classify_pad9     1
#define AMG_classify_pad10    1
#define AMG_classify_pad11    1
#define AMG_classify_pad12    1
#define AMG_classify_pad13    1
#define AMG_classify_pad14    1
#define AMG_classify_pad15    2

/* TODO: There's a possible trade-off here to use even larger tables to expand to smaller lists. */
/*      AMG_indecrN  br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs */
#define AMG_indecr0  15, 0, 1,  0, 1, 1,  0, 0, 0,  0, 1, 0,  1, 0, 0,  1, 0, 0
#define AMG_indecr1   0, 1, 2,  1, 1, 1,  0, 0, 0,  1, 0, 0,  0, 0, 0,  0, 0, 0
#define AMG_indecr2   1, 2, 3,  1, 1, 1,  0, 0, 0,  0, 0, 0,  0, 0, 0,  0, 0, 0
#define AMG_indecr3   2, 3, 4,  1, 1, 1,  0, 0, 0,  0, 0, 0,  0, 0, 0,  0, 0, 0
#define AMG_indecr4   3, 4, 5,  1, 1, 1,  0, 0, 0,  0, 0, 0,  0, 0, 0,  0, 0, 0
#define AMG_indecr5   4, 5, 6,  1, 1, 1,  0, 0, 0,  0, 0, 0,  0, 0, 0,  0, 0, 0
#define AMG_indecr6   5, 6, 7,  1, 1, 1,  0, 0, 0,  0, 0, 0,  0, 0, 0,  0, 0, 0
#define AMG_indecr7   6, 7, 8,  1, 1, 1,  0, 0, 1,  0, 0, 0,  0, 0, 0,  0, 0, 1
#define AMG_indecr8   7, 8, 9,  1, 1, 1,  1, 0, 0,  0, 0, 0,  0, 0, 0,  0, 1, 1
#define AMG_indecr9   8, 9,10,  1, 1, 1,  0, 0, 0,  0, 0, 0,  0, 0, 0,  1, 1, 1
#define AMG_indecr10  9,10,11,  1, 1, 1,  0, 0, 0,  0, 0, 0,  0, 0, 0,  1, 1, 1
#define AMG_indecr11 10,11,12,  1, 1, 1,  0, 0, 0,  0, 0, 0,  0, 0, 0,  1, 1, 1
#define AMG_indecr12 11,12,13,  1, 1, 1,  0, 0, 0,  0, 0, 0,  0, 0, 0,  1, 1, 1
#define AMG_indecr13 12,13,14,  1, 1, 1,  0, 0, 0,  0, 0, 0,  0, 0, 0,  1, 1, 1
#define AMG_indecr14 13,14,15,  1, 1, 1,  0, 0, 0,  0, 0, 0,  0, 0, 1,  1, 1, 1
#define AMG_indecr15 14,15, 0,  1, 1, 2,  0, 0, 0,  0, 0, 1,  0, 1, 0,  1, 1, 0


#define AMG_i4incr0(c,a0)     AMG_call(AMG_i4incr1##c,(AMG_indecr##a0))
#define AMG_i4incr10(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs)  AMG_i4incr2##bo(br,bs)
#define AMG_i4incr11(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs)  AMG_i4incr2##no(nr,ns)
#define AMG_i4incr12(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs)  AMG_i4incr2##co(cr,cs)
#define AMG_i4incr20(res,sign)     0(res)
#define AMG_i4incr21(res,sign)     1(res, AMG_sign_to_pad##sign)

#define AMG_i8incr0(carry,a0,a1) AMG_i8indecr1##carry(AMG_i8indecr2##carry,(AMG_indecr##a0)(AMG_indecr##a1))
#define AMG_i8indecr10(fn,args)  AMG_i8indecr4(15, fn args)
#define AMG_i8indecr11(fn,args)  AMG_i8indecr4(0,  fn args)
#define AMG_i8indecr12(fn,args)  AMG_i8indecr4(0,  fn args)

#define AMG_i8indecr20( br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) br, AMG_i8indecr3##bs##bc
#define AMG_i8indecr21( br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) nr, AMG_i8indecr3##ns##nc
#define AMG_i8indecr22( br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) cr, AMG_i8indecr3##cs##cc
#define AMG_i8indecr300(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) br, bo, b0
#define AMG_i8indecr301(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) nr, no, n0
#define AMG_i8indecr302(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) cr, co, c0
#define AMG_i8indecr310(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) br, bo, bF
#define AMG_i8indecr311(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) nr, no, nF
#define AMG_i8indecr312(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) cr, co, cF

#define AMG_i8indecr4(pad, expr) AMG_i8indecr5(pad, expr)
#define AMG_i8indecr5(pad, res0, res1, grow, shrink) \
	AMG_i8indecr6##grow##shrink(pad, res0, res1)
#define AMG_i8indecr600(pad, res0, res1)  1(res0,res1)
#define AMG_i8indecr601(pad, res0, res1)  0(res0)
#define AMG_i8indecr610(pad, res0, res1)  2(1,pad,pad)(res0,res1)
#define AMG_i8indecr611(pad, res0, res1) \
	AMG_error("AMG_i8indecr811: Reached an unreachable branch in macro arithmatic increment-carry/decrement-borrow code.")
	/* Notably, in add/subtract, the above case IS reachable. */
	/* In that situation, it's another growth case. */

/* TODO: rename `n` parameter in below text. It's actually a state code. */
/* The `n` parameter is NOT a state code. It's the number of tuples left. They're different. */
/* Operation evaluation/expansion is accomplished with a state machine.
//
// (Exception: smaller numbers using narrow representations, such as
// the 0:single-nybble-representation and 1:single-byte-representation,
// will not need iteration, and thus do not involve the state machine.)
//
// The states are numbered according to the sequence in which the occur.
// (If we ever have a state 0, that may be an exception.)
//
// The states are as follows:
//
// State 1, AMG_PP_OPSTATE_EARLY_MSB:
//
//    Early MSB inspection.
//
//    Entry (1st) state for operations that
//    have a state 1.
//
//    During this state, the op function can
//    examine the MSB from source numbers' header(s).
//
//    In principle, the op function can also
//    emit content between the result header
//    and result tail, though that often isn't
//    very useful.
//
//    In the case of some opportunistically
//    evaluated operations (ex: `cmp`),
//    this state might just directly emit
//    the result and then halt.
//
//    During this state, the integer token passed
//    into the op function macro's `n` parameter
//    will be the size of the input number(s).
//
//
// State 2, AMG_PP_OPSTATE_ITERATION:
//
//    State when processing the 2nd though
//    last tuple (inclusive) in the number.
//
//    Does not include MSB.
//
//    Entry state for operations that
//    do NOT have a state 1.
//
//    This state transitions to either
//    state 3 or state 4.
//
//    Transition to state 3 is the default.
//
//    Transition to state 4 can happen
//    if an operation can terminate early
//    (ex: an increment where there is
//    no carry in to the subsequent bytes).
//    To perform this transition, have the
//    iterator macro expand into a partial
//    invocation of one of these:
//    AMG_Xop_abort/AMG_Xop_truncate/AMG_Xop_passthrough
//
//    During this state, the integer token passed
//    into the op function macro's `n` parameter
//    will be the number of bytes left to process
//    in state 2. (Initially, this is also the
//    "size" of the input number(s).)
//
// TODO: This state is being removed.
// (Adding the MSB to the end of the train was
// a BAD IDEA because it prevented early-finish
// from working correctly: nothing would remove the endside MSB!)
//
// State 3, AMG_PP_OPSTATE_ENDSIDE_MSB:
//
//    Distal expansion of the MSB from the number's header tuple.
//
//    Although the MSB header appears at the
//    left side of the number, this state will
//    expands to the _right_ of the previous tuples.
//    (That being the "distal" end of the number.)
//
//    This is helpful in some situations, like
//    when the result has carry-out that requires
//    growing the number. In such cases, the old
//    MSB will become part of the result's tail
//    (and thus expand in state 3), while the
//    carry will become the new MSB
//    (and expand in state 4).
//
//    During this state, the integer token passed
//    into the op function macro's `n` parameter
//    will be `0`.
//
//
// State 4, AMG_PP_OPSTATE_HEADER_GEN:
//
//    Same as state 3, but it expands in "outer" context.
//
//    What this means is that the op function macro will
//    be passed the previously generated token sequence
//    as its first argument instead of the usual `n`
//    parameter.
//
//    (Also, there are parameters for MSB digits.)
//
//    This allows the op function to place tokens
//    before (or after) the rest of the output,
//    after all other digits have been evaluated.
//
//    This is (usually) the state in which the operation
//    will emit the resulting number's header tuple
//    and representation type. Exceptions _might_ happen
//    when the result isn't a number train / tuple train
//    (e.g. the operation returns 0/1 or a code of
//    some kind) and/or when it was possible to
//    emit a complete result in an earlier state.
//
//
// The machine can be started in either state 1 or state 2
// by passing an `istate` of 2 to the `AMG_uop` macro.
//
// Most operations can probably start in state 2, and this is
// an efficient way to do things: it avoids a couple unnecessary
// macro expansions.
//
// Some operations, however, need to start in state 1 to
// be expanded efficiently. An example would be the compare
// operation (`cmp`). In such cases, knowing the values in
// the MSB allow the operation to often complete without
// needing to scan the number. (In the case of `cmp`, it
// allows the op to know the number's sign, which along with
// the number's width, allows most comparisons to be
// completed without scan. And if the numbers are equal in
// width, then there's also a reasonable chance that they
// will differ in the MSB: and again, `cmp` can complete
// without requiring a scan.)
//
// To abort, (TODO!)
// TODO: Either we abort by transitioning to state 0,
// or we abort by having the function calling something
// like AMG_Xop_abort/AMG_Xop_truncate/AMG_Xop_passthrough
// so that the backbone code knows when early termination
// of iteration is occuring (and can then gather tokens
// and transition to state 4 or something).
//
// TODO: Binary operators need to be able to transition
//   into unary operators to finish operations when there
//   are operands of differing widths.
//
// Design note:
//
//     All states must be non-identifiers!
//
//     If we try to make a state named "A", then `A`
//     might be expanded as a macro somewhere before it
//     gets the opportunity to be concatenated to something.
//     (And being able to place states into the expansion
//     of a macro is _probably_ very important, as it allows
//     this information to be easily passed to the "outer"
//     context of the iterator, and to do so without
//     repeatedly copying iterators' results as an argument.)
*/
#define AMG_PP_OPSTATE_EARLY_MSB    1
#define AMG_PP_OPSTATE_ITERATION    2
#define AMG_PP_OPSTATE_HEADER_GEN   3

/* AMG_PP_OPSTATE_EARLY_MSB */
/* #define AMG_vincr01(n,carry,sign,buffer,msb_lo,msb_hi)  AMG_uop##n(1,carry,sign,buffer */

/* AMG_PP_OPSTATE_ITERATION */
#define AMG_vincr_state2( \
	n_bytes_remaining, \
	stopsz, carry, sign, buffer, \
	n_bytes_emitted, \
	n_bytes_visited, \
	a0,a1)     \
	AMG_vincr0( \
		n_bytes_remaining, buffer, n_bytes_emitted, \
		AMG_int_width_indecr##stopsz, \
		AMG_int_width_indecr##n_bytes_visited, \
		AMG_vincr_calc0##sign##carry, \
		(AMG_indecr##a0)(AMG_indecr##a1) \
	)

#define AMG_vincr_calc000(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) br, b0, AMG_vincr_calc1##0##bc
#define AMG_vincr_calc001(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) nr, n0, AMG_vincr_calc1##0##nc
#define AMG_vincr_calc002(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) cr, c0, AMG_vincr_calc1##0##cc
#define AMG_vincr_calc010(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) br, bF, AMG_vincr_calc1##1##bc
#define AMG_vincr_calc011(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) nr, nF, AMG_vincr_calc1##1##nc
#define AMG_vincr_calc012(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) cr, cF, AMG_vincr_calc1##1##cc
#define AMG_vincr_calc100(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) br, b0, bo, bc, bs
#define AMG_vincr_calc101(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) nr, n0, no, nc, ns
#define AMG_vincr_calc102(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) cr, c0, co, cc, cs
#define AMG_vincr_calc110(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) br, bF, bo, bc, bs
#define AMG_vincr_calc111(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) nr, nF, no, nc, ns
#define AMG_vincr_calc112(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs) cr, cF, co, cc, cs

/* AMG_vincr0 does two things:
// * Begins the expansion of (fn args) = AMG_vincr2##sign##carry(AMG_indecr##a0)(AMG_indecr##a1)
//     (Which gives us the result and a bunch of important flags.)
// * Expands the expression that increments vcount/n_bytes_visited.
//     (It's important to do that as soon as possible.
//     Just being here means we've "visited" a byte.)
*/
#define AMG_vincr0( \
	n, buffer, n_bytes_emitted, stopsz_expr, n_bytes_visited_expr, fn, args) \
	AMG_vincr1( \
		n, buffer, n_bytes_emitted, \
		stopsz_expr, n_bytes_visited_expr, fn args)

/* This macro just allows the expressions from the previous macro to fully expand. */
#define AMG_vincr1( \
	n, buffer, n_bytes_emitted, \
	stopsz_incr_discard, stopsz_decr, stopsz_is_zero, stopsz_was_zero_discard, \
	nbv_incr, nbv_decr_discard, nbv_is_zero_discard, nbv_was_zero_discard, expr) \
	AMG_vincr2( \
		n, stopsz_decr, stopsz_is_zero, buffer, n_bytes_emitted, nbv_incr, expr)

/* TODO: Compare previous and current sign. If different, flush buffer. */
/* TODO: Remove above TODO if things work out. Why? We can calculate flush from whether the sign-extend pattern continues or not. */
/* (So the state of the previous sign is essentially encoded into `ispad0` and `ispad1`.) */

/* TODO: I think we need to handle ispad0 and ispad1 right after this. The AMG_PP_OPSTATE_ITERATION case needs to do buffer management! */

#define AMG_vincr2(n, stopsz, muststop, buf, ecount, vcount, res0, ispad0, res1, ispad1, oflow, carry, sign) \
	AMG_vincr3##oflow##carry(n,stopsz,muststop,buf,ecount,vcount,res0,res1,ispad0,ispad1,carry,sign)

/* Carry 0 == decrement next byte */
#define AMG_vincr300(n,stopsz,muststop,buf,ecount,vcount,res0,res1,ispad0,ispad1,carry,sign) \
	AMG_vincr4a##muststop(n,stopsz,buf,res0,res1,carry,sign,vcount)

/* Carry 1 == rest of bytes are unaffected */
/* (Common case) */
#define AMG_vincr301(n,stopsz,muststop,buf,ecount,vcount,res0,res1,ispad0,ispad1,carry,sign) \
	AMG_vincr4b##ispad0##ispad1(n,stopsz,muststop,buf,ecount,vcount,res0,res1,carry,sign)

/* Carry 2 == increment next byte */
#define AMG_vincr302(n,stopsz,muststop,buf,ecount,vcount,res0,res1,ispad0,ispad1,carry,sign) \
	AMG_vincr4a##muststop(n,stopsz,buf,res0,res1,carry,sign,vcount)

/* We didn't reach max int width; just iterate as usual. */
#define AMG_vincr4a0(n,stopsz,buf,res0,res1,carry,sign,vcount) \
	buf(res0,res1) AMG_uop##n(stopsz,carry,sign,,vcount,vcount

/* Iteration-must-stop case (reached max int width) */
/*
// We still need to scan remaining bytes, in case we can truncate.
//
// All we're doing here is setting `carry` to the `neutral` option,
// so that we don't ripple any more changes through the number.
*/
#define AMG_vincr4a1(n,stopsz,buf,res0,res1,carry,sign,vcount) \
	buf(res0,res1) AMG_uop##n(0,1,sign,,vcount,vcount

/* No-shrink-possibility cases */
/* Several things happen here:
// * The buffer is written out (because we know those are interior bytes now, and not sign extension).
// * The buffer is erased (now that it's been placed into the result)
// * The `n_bytes_emitted`/`ecount` value is set to `n_bytes_visited`/`vcount` (consistent with buffer flushing)
// * We emit the current byte
//
// In most cases, `buf` will actually be empty. And that's OK.
// Then we aren't harming anything: we'll just emit a byte and move on.
// The update to `ecount` will be important too, because we ARE emitting a byte.
*/
#define AMG_vincr4b00(n,stopsz,muststop,buf,ecount,vcount,res0,res1,carry,sign) \
	buf(res0,res1) AMG_uop_passthrough(stopsz,carry,sign,,vcount,vcount

#define AMG_vincr4b01(n,stopsz,muststop,buf,ecount,vcount,res0,res1,carry,sign) \
	buf(res0,res1) AMG_uop_passthrough(stopsz,carry,sign,,vcount,vcount

#define AMG_vincr4b10(n,stopsz,muststop,buf,ecount,vcount,res0,res1,carry,sign) \
	buf(res0,res1) AMG_uop_passthrough(stopsz,carry,sign,,vcount,vcount

/* Shrinkage might be possible. Buffer until we're sure.
// Things implicitly happening here:
// * (res0,res1) is added to the buffer.
//     If the buffer was empty, this will now be its value.
// * Nothing is emitted into the result. (yet?)
// * We remember the value of `n_bytes_emitted`/`ecount`
//     from the last time that we actually emitted a byte.
*/
#define AMG_vincr4b11(n,stopsz,muststop,buf,ecount,vcount,res0,res1,carry,sign) \
	AMG_vincr5b##muststop(n,stopsz,buf(res0,res1),ecount,vcount,carry,sign)

/* No-stop: Just proceed as usual. */
#define AMG_vincr5b0(n,stopsz,buf,ecount,vcount,carry,sign) \
	AMG_uop##n(stopsz,carry,sign,buf,ecount,vcount

/* TODO: How does the generator code know if we halted due to stop-size?
//   Even moreso, how will it know the carry and overflow flags?
//   It's important because that's how saturated ops would work:
//   they'd emit a different value depending on what overflowed.
// Thoughts?
// * Add another "return" method, like, AMG_uop_signed_oflow and AMG_uop_unsigned_oflow,
//     then these are given the `n` parameter and may return to iteration if non-saturating and non-erring.
//     (Caveat: if we're operating on part of a larger number; naive saturation logic will truncate incorrectly!)
// * Implement things like AMG_i32_add as a separate integer type, 4(a0,a1,a2,a3).
//     Pro: Less complicated vwi code. "Only pay for what you use."
//     Pro: `stopsz` is just `n` but for an iterator that starts at `AMG_int_width_max`.
//       This might be crucial, because I think binary ops will need to generalize on this!
//       (It's the only way I can think of to avoid implementing NxN comparison ops.)
//     Con: still no way to do ops bounded to first N bits of large number.
//     Con: Lots more code to support those. If you use both int types,
//            you don't just "pay for what you use", you pay much more.
//
*/
/* Must-stop: Halt any rippling at this point,
//   but continue scanning for sign bits to minimize. */
#define AMG_vincr5b1(n,stopsz,buf,ecount,vcount,carry,sign) \
	AMG_uop##n(0,1,sign,buf,ecount,vcount


/* Shrinking case:
//
// If we had signed overflow, and given that this is
// happening in the number's interior (not the MSB),
// then we might be able to shrink the number.
//
// The shrinking will happen when a byte's sign is
// congruent with the number's sign, and all of the
// more significant bits are also just sign bits.
// In such a case, there is no need for the additional
// sign bits, so we can truncate them without changing
// the meaning of the number. This also produces
// a canonical/minimized form for variable-width
// integers, so we _always_ do this, because it is
// important for having predictable output.
//
// Example shrinking:
// |  number (0x)  |    number (var-w)     |  shrunk (0x) | shrunk (var-w)   |
// :---------------:-----------------------:--------------:------------------:
// :    0xFF8000   : 2(2,15,15)(0,0)(0,8)  :    0x8000    : 2(1,0,8)(0,0)    :
// :    0x007FFF   : 2(2,0,0)(15,15)(15,7) :    0x7FFF    : 2(1,15,7)(15,15) :
//
// In the above table, this step would be
// expanding on the middle byte in either case.
//
// This means that we _might_ shrink, but whether
// we actually do, depends on the contents of
// the more significant bytes. Shrinking will
// only _actually_ happen if all more sig bytes
// are uniformly full of sign bits.
//
// That's why we buffer the current byte, and leave
// later expansions to either output the buffer or
// dispose of the buffer (except the first byte,
// which contains the sign bit and new MSB).
//
// By doing this when we see the overflow flag,
// we are catching this situation the moment it
// happens,so that no other operations can see
// an intermediate/inconsistent state.
*/

/* Carry 0 == decrement next byte */
#define AMG_vincr310(n,stopsz,muststop,buf,ecount,vcount,res0,res1,ispad0,ispad1,carry,sign) \
	AMG_vincr4c##muststop(n,stopsz,buf,ecount,vcount,res0,res1,ispad0,ispad1,carry,sign)

/* Carry 1 == rest of bytes are unaffected */
/* (Common case) */
/* We still need to scan remaining bytes, in case we can truncate. */
#define AMG_vincr311(n,stopsz,muststop,buf,ecount,vcount,res0,res1,ispad0,ispad1,carry,sign) \
	AMG_vincr4c##muststop(n,stopsz,buf,ecount,vcount,res0,res1,ispad0,ispad1,carry,sign)

/* Carry 2 == increment next byte */
#define AMG_vincr312(n,stopsz,muststop,buf,ecount,vcount,res0,res1,ispad0,ispad1,carry,sign) \
	AMG_vincr4c##muststop(n,stopsz,buf,ecount,vcount,res0,res1,ispad0,ispad1,carry,sign)

/* Common case: we didn't reach max int width; just iterate as usual. */
#define AMG_vincr4c0(n,stopsz,buf,ecount,vcount,res0,res1,ispad0,ispad1,carry,sign) \
	AMG_uop##n(stopsz,carry,sign,buf(res0,res1),ecount,vcount

/* Iteration-must-stop case (reached max int width) */
/*
// We still need to scan remaining bytes, in case we can truncate.
//
// That might seem dangerous if we're already at the max int width,
// but this is more for bounded integer operations like `AMG_add_i32`:
// the real maximum int width is much wider than what we just hit.
//
// If we DID hit the global maximum, then there won't be any more
// bytes, because generation phase is required to stop emitting
// new bytes when a number reaches global maximum.
//
// All we're doing here is setting `carry` to the `neutral` option,
// so that we don't ripple any more changes through the number.
*/
#define AMG_vincr4c1(n,stopsz,buf,ecount,vcount,res0,res1,ispad0,ispad1,carry,sign) \
	AMG_uop##n(stopsz,1,sign,buf(res0,res1),ecount,vcount

/* `AMG_sign_to_pad` lookup
//
// These might be unintuitive, but here's how it works:
//
// The number concatenated onto `AMG_sign_to_pad` is the sign of the
// _result_ of the add/increment/subtract/decrement/whatever operation.
//
// This table assumes that the (signed) overflow flag was 1,
// which is the trigger for growing a variable-width-integer.
//
// To grow, we need to put two new nybbles into the new MSB.
// This table returns the nybble to use for both of those.
// (E.g. 0 for positive integers, F or 15 for negative integers.)
//
// Because there was signed overflow, it means that the sign
// appended to `AMG_sign_to_pad` will be the WRONG sign:
// it's the result of a signed overflow!
//
// Thus, the results returned from this will be the opposing sign.
// This reversal is what allows numbers to have the correct sign
// bit after they grow: the new MSB is full of sign extension
// bits of the sign that the number would have if it didn't overflow.
*/
#define AMG_sign_to_pad0  15
#define AMG_sign_to_pad1   0
#define AMG_sign_to_pad2   0


/* AMG_PP_OPSTATE_HEADER_GEN */
#define AMG_vincr_state3( \
	tail, stopsz, carry, sign, buffer, msb0, msb1, \
	is_early_finish, \
	n_bytes_emitted, \
	n_bytes_total) \
	AMG_vincr_header0##is_early_finish( \
		tail, stopsz, buffer, msb0, msb1, \
		n_bytes_emitted, n_bytes_total, \
		AMG_vincr_calc0##sign##carry, \
		(AMG_indecr##msb0)(AMG_indecr##msb1) \
	)

/* Rippled all the way! */
/* In this case, we will need to calculate an updated MSB.
// This will take a few extra steps compared to the "early finish" branch.
// (Here, we discard the old MSB. It has already been fed into `fn args`.)
*/
#define AMG_vincr_header00( \
	tail, stopsz, buffer, msb0, msb1, \
	n_bytes_emitted, n_bytes_total, fn, args) \
	AMG_vincr_header1( \
		tail, buffer, AMG_int_width_indecr##n_bytes_emitted, \
		n_bytes_emitted, n_bytes_total, fn args)

/* Early finish: Passthrough */
/* (Actually the common case for incrementation.)
// In this case, we never grow, and sign doesn't matter.
// Also, anything buffered (bytes suspected of being sign extension)
// can be emitted, because we're still in the interior of the number,
// so they WILL be significant and meaningful.
*/
#define AMG_vincr_header01( \
	tail, stopsz, buffer, msb0, msb1, \
	n_bytes_emitted, n_bytes_total, fn, args) \
	\
	2(n_bytes_total,msb0,msb1) tail buffer
	/* The iterator will expand pass-through bytes to the right of this expansion. */

#define AMG_vincr_header1( \
	tail, buffer, emitted_no_bytes_expr, n_bytes_emitted, n_bytes_total, expr) \
	AMG_vincr_header2( \
		tail, buffer, emitted_no_bytes_expr, n_bytes_emitted, n_bytes_total, expr)

#define AMG_vincr_header2( \
	tail, buffer, \
	enb_incr, enb_decr, enb_is_zero, enb_was_zero, \
	n_bytes_emitted, n_bytes_total, \
	res0, ispad0, res1, ispad1, grow, carry, sign) \
	AMG_vincr_header3##grow( \
		tail, AMG_sign_to_pad##sign, \
		buffer, res0, res1,  \
		ispad0, ispad1,      \
		enb_is_zero,         \
		n_bytes_emitted,     \
		n_bytes_total)

/* No growth; possibly even shrinking. */
/*
// In there's no resizing, we emit the buffer.
// If there IS resizing, then it's shrinking,
// and we shrink by discarding the buffer.
//
// We also toss out the `pad` parameter, because
// it's not useful for same-width and shrinking cases.
//
// Notably, because we may be shrinking,
// there are EVEN MORE corner-cases.
// This happens because the number could shrink into
// single-byte-representation (SBR) or even single-nybble-representation (SNR).
//
// Note that when we've so far "emitted" zero bytes, this refers
// to the bytes that trail the header. The header is a byte.
// So if we've emitted zero bytes, then this is a 1-byte number.
// Both SBR and SNR are representations for 1-byte numbers,
// with SNR being a more specific case for even smaller numbers.
// Thus, we can use the `emitted_no_bytes` argument to decide
// whether we are downsizing or not.
*/
#define AMG_vincr_header30( \
	tail, pad, buffer, msb0,msb1, ispad0,ispad1, \
	emitted_no_bytes, n_bytes_emitted, n_bytes_total) \
	AMG_vincr_shrink4##ispad0##ispad1( \
		tail, buffer, msb0,msb1, emitted_no_bytes, n_bytes_emitted, n_bytes_total)

/* Non-shrinking cases. */
#define AMG_vincr_shrink400(tail,buf,msb0,msb1,sbr,ecount,sz) 2(sz,msb0,msb1) tail buf
#define AMG_vincr_shrink401(tail,buf,msb0,msb1,sbr,ecount,sz) 2(sz,msb0,msb1) tail buf
#define AMG_vincr_shrink410(tail,buf,msb0,msb1,sbr,ecount,sz) 2(sz,msb0,msb1) tail buf

/* Shrinking cases. */
/* Discard `sz`.
// `tail` and `ecount` are necessary for the variable-width-output case.
// `buf` is important for the SBR/SNR cases, because the 1st byte is the output.
// To save steps in the SBR/SNR case, we'll start retrieving the first byte right now.
*/
#define AMG_vincr_shrink411(tail,buf,msb0,msb1,sbr,ecount,sz) \
	AMG_vincr_shrink5##sbr(tail, AMG_iget2a buf, ecount)

/* Output-is-variable-width-rep case */
#define AMG_vincr_shrink50(tail, first_byte_and_buf, n_bytes_emitted) \
	AMG_vincr_shrink6v(tail, first_byte_and_buf, n_bytes_emitted)

#define AMG_vincr_shrink6v(tail, n0,n1,  rest_buf,  n_bytes_emitted) \
	2(n_bytes_emitted,n0,n1) tail

/* Output-is-SBR-or-SNR case */
/*
// This case notably contains a lot of extra macro expansions.
// It's probably not very fast, at least compared to the other cases.
// However, it should, _in principle_, be very rare. Like, probability less than 1/256.
// And only for 2-byte variable-width integers.
// There are only two integer values in the entire number line that can lead to this case!
// (And only one for incrementation, and one for decrementation.)
// So it might be possible to optimize this further, but it's not a priority right now.
//
// This particular macro is notably an intermediate macro
// used to ensure that `first_byte_and_buf` is expanded
// into digits and the rest of the buffer.
*/
#define AMG_vincr_shrink51(tail, first_byte_and_buf, n_bytes_emitted) \
	AMG_vincr_shrink6(first_byte_and_buf)

/* Now that we have the appropriate byte extracted,
// we need to know its "shape" so we can decide if
// we want to use SBR or SNR to represent it.
//
// Here is where we start cooking those table lookups.
*/
#define AMG_vincr_shrink6(lo,hi,  rest_buf) \
	AMG_vincr_shrink7(lo,hi, AMG_sign##lo, AMG_classify_pad##hi)

/* Intermediate macro to ensure `lo_sign` and `hi_padclass` are expanded. */
#define AMG_vincr_shrink7(lo,hi,  lo_sign, hi_padclass) \
	AMG_vincr_shrink8(lo,hi, lo_sign, hi_padclass)

/* Dispatch to the generator for the appropriate SBR/SNR. See table below. */
#define AMG_vincr_shrink8(lo,hi, lo_sign, hi_padclass) \
	AMG_vincr_shrink8##lo_sign##hi_padclass(lo,hi)

/* AMG_vincr_shrink800 -> 0b XXX0 0000 -> 0(XXX0)       e.g. `hi` is unnecessary (pos) sign extension
// AMG_vincr_shrink801 -> 0b XXX0 XXXX -> 1(XXX0,XXXX)  e.g. `hi` is not sign extension
// AMG_vincr_shrink802 -> 0b XXX0 1111 -> 1(XXX0,1111)  e.g. `hi` looks like sign extend, but isn't
// AMG_vincr_shrink810 -> 0b XXX1 0000 -> 1(XXX1,0000)  e.g. `hi` looks like sign extend, but isn't
// AMG_vincr_shrink811 -> 0b XXX1 XXXX -> 1(XXX1,XXXX)  e.g. `hi` is not sign extension
// AMG_vincr_shrink812 -> 0b XXX1 1111 -> 0(XXX1)       e.g. `hi` is unnecessary (neg) sign extension
*/
#define AMG_vincr_shrink800(lo,hi)  0(lo)
#define AMG_vincr_shrink801(lo,hi)  1(lo,hi)
#define AMG_vincr_shrink802(lo,hi)  1(lo,hi)
#define AMG_vincr_shrink810(lo,hi)  1(lo,hi)
#define AMG_vincr_shrink811(lo,hi)  1(lo,hi)
#define AMG_vincr_shrink812(lo,hi)  0(lo)

/* Growth case */
/* Things happening here:
// * Emit the buffer (or nothing if it's empty)
// * Emit the former MSB as the new last-byte-in-the-tail
// * Generate header with width number of `n_bytes_total+1`
// * Generated header is made of sign-extension bits (the `pad` value)
//
// TODO: This is where we would branch to handle overgrowth,
//   e.g. when we can only represent 128-bit numbers and we need to grow still.
//   In that case we should offer several behaviors:
//   * Wrap-on-overflow
//   * Saturation (will probably yield SNR actually)
//   * Error (and, hopefully, a _proper_ error)
//   These should also help implementing width-bounded ops like 16-bit, 32-bit, 64-bit etc.
//   (ex: amgpp_i32_incr(...) and amgpp_i32_sat_incr(...))
// For now, the below code will get us testing!
*/
#define AMG_vincr_header31( \
	tail, pad, buffer, msb0,msb1, ispad0,ispad1, \
	emitted_no_bytes, n_bytes_emitted, n_bytes_total) \
	\
	2(AMG_int_width_incr##n_bytes_total, pad, pad) tail buffer(msb0,msb1)
	/*AMG_vincr_grow4##ispad0##ispad1( \
		tail, buffer, msb0,msb1, emitted_no_bytes, n_bytes_emitted, n_bytes_total)*/

#if 0
/* TOOD:
// sooooo...
// growth precludes shrinking, and shrinking is _complicated_
// We check for growth first.
// If growth, emit buffer and incr result at END of tail.
//   Then emit header full of pad nybbles, and use size of `n_bytes_total+1`.
// If no growth, do the ##ispad0##ispad1 dispatch.
// Noshrink? emit the buffer after the tail, then emit a header with the new MSB and size of `n_bytes_total`
// Shrink?
// Discard buffer.
// Dispatch on `emitted_no_bytes` to branch on representation shifts.
// If it's still variable-width: Emit a header with the new MSB and size of `n_bytes_emitted`.
// If it's SBR/SNR:
// Follow prior logic for determining which of those, then emit new MSB in given format.
// You got this.
*/
/* Further TODO:
// How to handle overflow? (Don't grow. Notably, shrinking becomes possible on growth flag.)
// The same mechanism that would give us, say, 128-bit overflow, could
// also be used to provide us with operations like amgpp_add_i32(...).
// How about saturated operations?
// This would be the same overflow detect mechanism I think, but
// instead of simply halting, it would replace the entire result
// with the threshold value that the operation "saturates" to. (Note: canonical forms of saturated values will probably be in SNR!)
// As it is, you will probably get weird preprocessor errors if you go too far...
// (Also, it might be valid to have an "error on overflow" model,
// just in case the other, more traditional, behaviors are too unpredictable
// for some use-cases.)
*/

/* AMG_vincr8 conditions:
// First 0|1:
//     (Prev-byte's sign is 0 && this-byte is all 0s)
//  || (Prev-byte's sign is 1 && this-byte is all Fs)
//     A.K.A. "we should shrink by removing redundant sign bits"
//
// Second 0|1:
//     signed overflow A.K.A. "we should grow by 1 byte"
*/
#endif

/*
// TODO: Implement add+subtract
//
// Implementing subtraction:
//
// Suppose our adder is designed so that `(a+b)` assumes `a` is wider.
// Whenever we encounter `(a+B)`, we rewrite to `(B+a)` and proceed,
// because property of commutativity is handy like that.
//
// If we need to evaluate `(a-b)`, but `b` is _wider_, how do we do this?
//
// Proof:
// 0. (a-b)
// 1.   = a + (-b)     // Definitional: "subtraction is addition by a negative number"
// 2.   = a + (~b + 1) // Two's complement: `-x = (~x)+1`.
// 3.   = a + ~b + 1   // Distribute the implicit 1 through the parens
// 4.   = ~b + a + 1   // Commutative property. (Place `~b` in lhs position.)
//
// We perform step 2 (and on) because  we don't want to calculate
// `amgpp_incr(b)` first: that requires scanning `b` an extra time
// to perform the incrementation. (This is extra insulting because
// `b` is even the wider number!)
//
// Now we have a form that can be computed more easily:
// `~b` can be moved to the preferred side such that the adder
// can always have the wider number on that preferred side.
//
// We will need to compute the complementation. However, this
// can be done per-digit with a small table lookup (and no flags necessary),
// so we could probably even sneak it into the iterator so that
// it is performed ahead of other operations and doesn't increase
// expansion depth.
//
// (This also makes me realize that I could probably reduce the expansion
// depth of the iterator by pre-expanding the tabular calcs within
// iterator code. This is, of course, terrible for readability/maintainability,
// so maybe we won't do this one right now. Maybe an optimizing
// pre-preprocessor could handle it someday. But w/e.)
//
// The incrementation by 1 is simple enough to handle:
// Just "carry in" a 1.
//
// (Possible implementation detail: We might need to sign-extend `b`
// before doing this operation, otherwise the raw complementation might
// affect the sign/magnitude of the result. But I'm not sure yet.)
*/

#define AMG_iget1(d0)    d0
#define AMG_iget2(d0,d1) d0,d1
#define AMG_ipop2(d0,d1) d0,d1,

#define AMG_uop(istate,maxsz,carry_in,fn4,fn8,fnN,num) AMG_uop_T##num ,istate,maxsz,carry_in,fn4,fn8,fnN)
#define AMG_uop_T0  AMG_uop_snr(AMG_iget1
#define AMG_uop_T1  AMG_uop_sbr(AMG_iget2
#define AMG_uop_T2  AMG_uop_var(AMG_igetsz
#define AMG_uop_snr(ex_anum,istate,maxsz,carry_in,fn_nybble,fn_byte,fn_var)  fn_nybble(carry_in,ex_anum)
#define AMG_uop_sbr(ex_anum,istate,maxsz,carry_in,fn_nybble,fn_byte,fn_var)  fn_byte(carry_in,ex_anum)
#define AMG_uop_var(ex_anum,istate,maxsz,carry_in,fn_nybble,fn_byte,fn_var)  AMG_uop_var0(,istate,maxsz,carry_in,ex_anum,fn_var)

/* TODO: TODO: TODO: TODO: REALIZATION: Putting the MSB at the end of the train is BAD. It fails in the early-end case, because nothing will clean it up! */

/* Notably, `AMG_uop_var1` only works if there is ALWAYS a non-MSB byte
// present in the tuple-train. This invariant is held true because of
// our short-form representations: single-byte-rep (especially) and single-nybble-rep.
// The only way for there to be a situation where the ONLY tuple trailing
// the header is the MSB, is if we had a 1-byte variable-sized integer,
// in which case it would start with 0 trailing tuples, then have the
// MSB added by the `e##anum(msb0,msb1)` expression. THAT would
// require AMG_PP_OPSTATE_ENDSIDE_MSB to be passed for the state
// argument instead of AMG_PP_OPSTATE_ITERATION. However, this will
// (or at least _should_) never happen, because all 1-byte numbers should
// canonically be stored in single-byte-representation (SBR). If a 1-byte
// number is stored in variable form, then it is an error in the macro
// that generated that number. So we always get 2-byte or greater numbers
// for our variably-sized-integers, which means there is ALWAYS one tuple
// before the injected MSB tuple That then means we can unconditionally
// use AMG_PP_OPSTATE_ITERATION when we begin iteration.
*/
/* TODO: Place the `maxsz` parameter correctly. Intent: it gets counted down at each iteration. When it's 0, then iteration stops and either: wraps, saturates, or errors. */
/* TODO: Probably also need a parameter for telling it how to handle overgrowth. */
#define AMG_uop_var0(e,istate,maxsz,carry,sz,msb0,msb1,anum,fn)  AMG_uop_var_final0(AMG_uop_var1##istate(,istate,maxsz,carry,sz,msb0,msb1,e##anum,fn),msb0,msb1,sz,fn)
#define AMG_uop_var11(e,istate,maxsz,carry,sz,msb0,msb1,anum,fn) fn##istate(sz,maxsz,carry,0,,0,0,msb0,msb1),0,anum,2,fn)
#define AMG_uop_var12(e,istate,maxsz,carry,sz,msb0,msb1,anum,fn) AMG_uop##sz(maxsz,carry,0,,0,0,,anum,2,fn)
#define AMG_uop_var_final0(result_as_args,msb0,msb1,sz,fn)       AMG_uop_var_final1(result_as_args,msb0,msb1,sz,fn)
#define AMG_uop_var_final1( \
	result, stopsz, carry, sign, buffer, \
	n_bytes_emitted,    \
	is_early_finish,    \
	anum, fstate,       \
	msb0, msb1, \
	n_bytes_total,fn) \
	fn##fstate( \
		result, stopsz, carry, sign, buffer, msb0,msb1, \
		is_early_finish,   \
		n_bytes_emitted,   \
		n_bytes_total      \
	) anum

	// ??? = is_early_finish
//#define AMG_uop_var_final(tail,carry,sign,buffer,msb_lo,msb_hi)
//	fn##

/* TODO: How to get AMG_uop0 to expand the `fn` in outer context?
//       It needs to be able to put the size and MSB in the header.
// TODO: What about growth case? Then the sum of MSBs will not be
//       the new MSB, it will actually go at the end of the train.
//       BUT. We'll still need to emit the proper MSB in the
//       result's header (and increment size by 1). This will
//       be necessary for placing a new sign bit.
*/
/*
// The first two hardcoded integers are just the number of bytes remaining.
// Placing them here is an optimization; it saves us from needing to expand
// the increment/decrement table for this variable at every step.
//
// The second hardcoded integer is the next state in the state-machine.
// Most of these represent iteration states that will lead into another
// iteration state. However, the last state will lead into the
// header generation state, hence that will be a different number.
// So far, I have no way to replace these with more descriptive names,
// because the macros for the state numbers would not expand in time.
// (This has been attempted.)
//
// The hardcoded integer in `AMG_uop0` is the `is_early_finish` flag.
// It is used to indicate whether we stopped before reaching the
// header itself or not. The header generator will need to handle
// such cases differently. In this case, we pass `0`, because this
// is NOT an early finish: iteration actually went all the way to the end.
*/
#define AMG_uop7(stopsz,carry,sign,buffer,ecount,vcount,n,a0,a1,anum,next_state,fn)  fn##next_state( 6,stopsz,carry,sign,buffer,ecount,vcount,a0,a1),6,anum,2,fn)
#define AMG_uop6(stopsz,carry,sign,buffer,ecount,vcount,n,a0,a1,anum,next_state,fn)  fn##next_state( 5,stopsz,carry,sign,buffer,ecount,vcount,a0,a1),5,anum,2,fn)
#define AMG_uop5(stopsz,carry,sign,buffer,ecount,vcount,n,a0,a1,anum,next_state,fn)  fn##next_state( 4,stopsz,carry,sign,buffer,ecount,vcount,a0,a1),4,anum,2,fn)
#define AMG_uop4(stopsz,carry,sign,buffer,ecount,vcount,n,a0,a1,anum,next_state,fn)  fn##next_state( 3,stopsz,carry,sign,buffer,ecount,vcount,a0,a1),3,anum,2,fn)
#define AMG_uop3(stopsz,carry,sign,buffer,ecount,vcount,n,a0,a1,anum,next_state,fn)  fn##next_state( 2,stopsz,carry,sign,buffer,ecount,vcount,a0,a1),2,anum,2,fn)
#define AMG_uop2(stopsz,carry,sign,buffer,ecount,vcount,n,a0,a1,anum,next_state,fn)  fn##next_state( 1,stopsz,carry,sign,buffer,ecount,vcount,a0,a1),1,anum,2,fn)
#define AMG_uop1(stopsz,carry,sign,buffer,ecount,vcount,n,a0,a1,anum,next_state,fn)  fn##next_state( 0,stopsz,carry,sign,buffer,ecount,vcount,a0,a1),0,anum,3,fn)
#define AMG_uop0(stopsz,carry,sign,buffer,ecount,vcount,n,e0,  next_state,fn)        ,stopsz,carry,sign,buffer,ecount,0,,next_state

#define AMG_uop_aborted(e0,e1,e2,e3,e4)

/* The hardcoded integer in these macros is the `is_early_finish` flag.
// It is used to indicate whether we stopped before reaching the
// header itself or not. In this case, we pass `1`, because these
// cases do actually represent ways to terminate iteration "early".
// (This often means that the header can just be left alone, and
// the header generator just needs to recreate the original header.)
*/
#define AMG_uop_passthrough(stopsz,carry,sign,buffer,ecount,vcount,n,anum,nonstate,efn) ,stopsz,carry,sign,buffer,ecount,1,AMG_unget_##anum,AMG_PP_OPSTATE_HEADER_GEN
#define AMG_uop_truncate(stopsz,carry,sign,buffer,ecount,vcount,n,anum,nonstate,efn)    ,stopsz,carry,sign,buffer,ecount,1,,AMG_PP_OPSTATE_HEADER_GEN

#define amgpp_decr(num) AMG_uop(AMG_PP_OPSTATE_ITERATION,AMG_int_width_max,0,AMG_i4incr0,AMG_i8incr0,AMG_vincr_state,num)
#define amgpp_incr(num) AMG_uop(AMG_PP_OPSTATE_ITERATION,AMG_int_width_max,2,AMG_i4incr0,AMG_i8incr0,AMG_vincr_state,num)

#define amgpp_i16_decr(num) AMG_uop(AMG_PP_OPSTATE_ITERATION,2,0,AMG_i4incr0,AMG_i8incr0,AMG_vincr_state,num)
#define amgpp_i16_incr(num) AMG_uop(AMG_PP_OPSTATE_ITERATION,2,2,AMG_i4incr0,AMG_i8incr0,AMG_vincr_state,num)

#endif /* AMG_pp_int_incr_included */

#ifdef AMG_INCLUDE_IMPLEMENTATION
#ifndef AMG_pp_int_incr_implemented
#define AMG_pp_int_incr_implemented 1

#ifdef AMG_INCLUDE_UNITTESTS
#ifndef AMG_test_runner_h
#define AMG_test_runner_h "amg/test_runner.h"
#endif
#include AMG_test_runner_h

void amg__unittest_amgpp_incr(AMG_TEST_RUNNER* runner)
{
	const char *feature_name = "amgpp_incr";
	amg_feature_tests_begin(runner, feature_name);

	amgpp_expect_eq(runner, amgpp_incr(1(3,6)),...........,1(4,6),...........);
	amgpp_expect_eq(runner, amgpp_incr(1(3,6)),...........,1(4,6),...........); /* expect 1(4,6) */
	amgpp_expect_eq(runner, amgpp_decr(1(3,6)),...........,1(2,6),...........); /* expect 1(2,6) */
	amgpp_expect_eq(runner, amgpp_incr(1(15,7)),..........,2(1,0,0)(0,8),....); /* expect 2(1,0,0)(0,8) */
	amgpp_expect_eq(runner, amgpp_decr(1(0,8)),...........,2(1,15,15)(15,7),.); /* expect 2(1,15,15)(15,7) */
	amgpp_expect_eq(runner, amgpp_incr(2(1,1,2)(3,4)),....,2(1,1,2)(4,4),....); /* expect 2(1,1,2)(4,4) */
	amgpp_expect_eq(runner, amgpp_incr(2(1,15,15)(15,7)),.,1(0,8),...........); /* expect 1(0,8) */
	amgpp_expect_eq(runner, amgpp_decr(2(1,0,0)(0,8)),....,1(15,7),..........); /* expect 1(15,7) */

	amgpp_expect_eq(runner, amgpp_incr(2(3,15,15)(15,15)(15,7)(15,15)),, 2(1,0,8)(0,0),);
	amgpp_expect_eq(runner, amgpp_decr(2(1,0,8)(0,0)),, 2(2,15,15)(15,15)(15,7),);
	amgpp_expect_eq(runner, amgpp_decr(2(2,15,15)(0,0)(0,0)),, 2(2,14,15)(15,15)(15,15),);

	amgpp_expect_eq(runner, amgpp_incr(0(0)),...........,0(1),...........);
	amgpp_expect_eq(runner, amgpp_decr(0(0)),...........,0(15),..........);
	amgpp_expect_eq(runner, amgpp_incr(0(15)),..........,0(0),...........);
	amgpp_expect_eq(runner, amgpp_decr(0(15)),..........,0(14),..........);

	amgpp_expect_eq(runner, amgpp_incr(0(7)),...........,1(8,0),.........);
	amgpp_expect_eq(runner, amgpp_decr(0(8)),...........,1(7,15),........);
	amgpp_expect_eq(runner, amgpp_incr(1(7,15)),........,0(8),...........);
	amgpp_expect_eq(runner, amgpp_decr(1(8,0)),.........,0(7),...........);

	amgpp_expect_eq(runner, amgpp_i16_incr(2(3,15,7)(15,15)(15,15)(15,15)),..,2(3,15,7)(0,0)(0,0)(15,15),...);
	amgpp_expect_eq(runner, amgpp_i16_decr(2(3,0,8)(0,0)(0,0)(0,0)),.........,2(3,0,8)(15,15)(15,15)(0,0),..);

	amg_feature_tests_end(runner, feature_name);
}
#endif /* AMG_INCLUDE_UNITTESTS */

#endif /* AMG_pp_int_incr_implemented */
#endif /* AMG_INCLUDE_IMPLEMENTATION */
#endif /* AMG_dummy_guard */
