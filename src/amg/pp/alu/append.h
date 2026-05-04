#ifndef AMG__PP_ALU_APPEND_INCLUDED
#define AMG__PP_ALU_APPEND_INCLUDED

#ifndef AMG__PP_ALU_APPEND_H
#define AMG__PP_ALU_APPEND_H "amg/pp/alu/append.h"
#endif

#define amg__append_as_hdigit0( e,id,pred)   pred(,id##0
#define amg__append_as_hdigit1( e,id,pred)   pred(,id##1
#define amg__append_as_hdigit2( e,id,pred)   pred(,id##2
#define amg__append_as_hdigit3( e,id,pred)   pred(,id##3
#define amg__append_as_hdigit4( e,id,pred)   pred(,id##4
#define amg__append_as_hdigit5( e,id,pred)   pred(,id##5
#define amg__append_as_hdigit6( e,id,pred)   pred(,id##6
#define amg__append_as_hdigit7( e,id,pred)   pred(,id##7
#define amg__append_as_hdigit8( e,id,pred)   pred(,id##8
#define amg__append_as_hdigit9( e,id,pred)   pred(,id##9
#define amg__append_as_hdigit10(e,id,pred)   pred(,id##A
#define amg__append_as_hdigit11(e,id,pred)   pred(,id##B
#define amg__append_as_hdigit12(e,id,pred)   pred(,id##C
#define amg__append_as_hdigit13(e,id,pred)   pred(,id##D
#define amg__append_as_hdigit14(e,id,pred)   pred(,id##E
#define amg__append_as_hdigit15(e,id,pred)   pred(,id##F
#define amg__append_as_hdigit16(e,id,pred)   pred(,id##G
#define amg__append_as_hdigit17(e,id,pred)   pred(,id##H
#define amg__append_as_hdigit18(e,id,pred)   pred(,id##I
#define amg__append_as_hdigit19(e,id,pred)   pred(,id##J
#define amg__append_as_hdigit20(e,id,pred)   pred(,id##K
#define amg__append_as_hdigit21(e,id,pred)   pred(,id##L
#define amg__append_as_hdigit22(e,id,pred)   pred(,id##M
#define amg__append_as_hdigit23(e,id,pred)   pred(,id##N
#define amg__append_as_hdigit24(e,id,pred)   pred(,id##O
#define amg__append_as_hdigit25(e,id,pred)   pred(,id##P
#define amg__append_as_hdigit26(e,id,pred)   pred(,id##Q
#define amg__append_as_hdigit27(e,id,pred)   pred(,id##R
#define amg__append_as_hdigit28(e,id,pred)   pred(,id##S
#define amg__append_as_hdigit29(e,id,pred)   pred(,id##T
#define amg__append_as_hdigit30(e,id,pred)   pred(,id##U
#define amg__append_as_hdigit31(e,id,pred)   pred(,id##V
#define amg__append_as_hdigit32(e,id,pred)   pred(,id##W
#define amg__append_as_hdigit33(e,id,pred)   pred(,id##X
#define amg__append_as_hdigit34(e,id,pred)   pred(,id##Y
#define amg__append_as_hdigit35(e,id,pred)   pred(,id##Z


// TODO: Possibly represent numbers as things like "9(0(2(1(0("
// This allows us to easily support N-digit numbers, because we don't need to know how many digits there are.
// It means that we wouldn't have i4.h, i8.h, i12.h, i16.h, i24.h, i32.h, i48.h, i64.h, etc,
// each inducing a ton of maintenance burden. Instead, it's just ONE file that handles EVERYTHING.
// That would be great!
// And it _might_ be really fast, too: you don't need to unpack the number.
// Just concatenate to it, provide a closing paren, and it will start expanding!
//
// Caveat: This representation is not "stable", and if left to expand prematurely,
// my consume the closing parentheses of any macro expansions around it.
// (But then, the cases where that happens seem few? Usually if there's
// a function-like-macro to the left of it, then that macro will begin
// expanding before the number does.)
// Nonetheless, there are ways for it to go wrong.
// So, we'd want to have some kind of encode/decode or pack/unpack functions
// that can store it in a "shelf stable" form like, "9 0 2 1 0".
#define amg__append_as_hdigit(e,id,n,pred)  amg__append_as_hdigit##n(,e##id,e##pred)

#define amg__i8_append_as_hex_s2(e,id)           id
#define amg__i8_append_as_hex_s1(e,id,d1)        amg__append_as_hdigit##d1(,e##id,amg__i8_append_as_hex_s2))
#define amg__i8_append_as_hex_s0(e,id,d2,d1)     amg__append_as_hdigit##d2(,e##id,amg__i8_append_as_hex_s1),d1)
#define amg__i8t_append_as_hex(e,id,expand)      amg__i8_append_as_hex_s0(,e##id,expand)
//#define amg__i8a_append_as_hex(e,id,d2,d1)       amg__i8_append_as_hex_s0(,e##id,d2,d1)

#define amg_i8_append_as_hex(e,id,tuple)         amg__i8t_append_as_hex(,e##id,amg_expand2(,tuple))
#define amg_i8t_append_as_hex(e,id,tuple)        amg__i8t_append_as_hex(,e##id,amg_expand2(,tuple))
#define amg_i8h_append_as_hex(e,id,args)         amg__i8t_append_as_hex(,e##id,amg__h(,amg_i4h##args))

#define amg__i12_append_as_hex_s3(e,id)          id
#define amg__i12_append_as_hex_s2(e,id,d1)       amg__append_as_hdigit##d1(,e##id,amg__i12_append_as_hex_s3))
#define amg__i12_append_as_hex_s1(e,id,d2,d1)    amg__append_as_hdigit##d2(,e##id,amg__i12_append_as_hex_s2),d1)
#define amg__i12_append_as_hex_s0(e,id,d3,d2,d1) amg__append_as_hdigit##d3(,e##id,amg__i12_append_as_hex_s1),d2,d1)
#define amg__i12t_append_as_hex(e,id,expand)     amg__i12_append_as_hex_s0(,e##id,expand)
//#define amg__i12a_append_as_hex(e,id,d3,d2,d1)   amg__i12_append_as_hex_s0(,e##id,d3,d2,d1)

#define amg_i12_append_as_hex( e,id,tuple)       amg__i12t_append_as_hex(,e##id,amg_expand3(,tuple))
#define amg_i12t_append_as_hex(e,id,tuple)       amg__i12t_append_as_hex(,e##id,amg_expand3(,tuple))
#define amg_i12h_append_as_hex(e,id,args)        amg__i12t_append_as_hex(,e##id,amg__h(,amg_i4h##args)

#endif
