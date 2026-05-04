#ifndef AMG__PP_ALU_PREPEND_INCLUDED
#define AMG__PP_ALU_PREPEND_INCLUDED

#ifndef AMG__PP_ALU_PREPEND_H
#define AMG__PP_ALU_PREPEND_H "amg/pp/alu/prepend.h"
#endif

#define amg__i8_prepend_as_hdigit0( e,id,pred)   pred(,0##id
#define amg__i8_prepend_as_hdigit1( e,id,pred)   pred(,1##id
#define amg__i8_prepend_as_hdigit2( e,id,pred)   pred(,2##id
#define amg__i8_prepend_as_hdigit3( e,id,pred)   pred(,3##id
#define amg__i8_prepend_as_hdigit4( e,id,pred)   pred(,4##id
#define amg__i8_prepend_as_hdigit5( e,id,pred)   pred(,5##id
#define amg__i8_prepend_as_hdigit6( e,id,pred)   pred(,6##id
#define amg__i8_prepend_as_hdigit7( e,id,pred)   pred(,7##id
#define amg__i8_prepend_as_hdigit8( e,id,pred)   pred(,8##id
#define amg__i8_prepend_as_hdigit9( e,id,pred)   pred(,9##id
#define amg__i8_prepend_as_hdigit10(e,id,pred)   pred(,A##id
#define amg__i8_prepend_as_hdigit11(e,id,pred)   pred(,B##id
#define amg__i8_prepend_as_hdigit12(e,id,pred)   pred(,C##id
#define amg__i8_prepend_as_hdigit13(e,id,pred)   pred(,D##id
#define amg__i8_prepend_as_hdigit14(e,id,pred)   pred(,E##id
#define amg__i8_prepend_as_hdigit15(e,id,pred)   pred(,F##id
#define amg__i8_prepend_as_hdigit16(e,id,pred)   pred(,G##id
#define amg__i8_prepend_as_hdigit17(e,id,pred)   pred(,H##id
#define amg__i8_prepend_as_hdigit18(e,id,pred)   pred(,I##id
#define amg__i8_prepend_as_hdigit19(e,id,pred)   pred(,J##id
#define amg__i8_prepend_as_hdigit20(e,id,pred)   pred(,K##id
#define amg__i8_prepend_as_hdigit21(e,id,pred)   pred(,L##id
#define amg__i8_prepend_as_hdigit22(e,id,pred)   pred(,M##id
#define amg__i8_prepend_as_hdigit23(e,id,pred)   pred(,N##id
#define amg__i8_prepend_as_hdigit24(e,id,pred)   pred(,O##id
#define amg__i8_prepend_as_hdigit25(e,id,pred)   pred(,P##id
#define amg__i8_prepend_as_hdigit26(e,id,pred)   pred(,Q##id
#define amg__i8_prepend_as_hdigit27(e,id,pred)   pred(,R##id
#define amg__i8_prepend_as_hdigit28(e,id,pred)   pred(,S##id
#define amg__i8_prepend_as_hdigit29(e,id,pred)   pred(,T##id
#define amg__i8_prepend_as_hdigit30(e,id,pred)   pred(,U##id
#define amg__i8_prepend_as_hdigit31(e,id,pred)   pred(,V##id
#define amg__i8_prepend_as_hdigit32(e,id,pred)   pred(,W##id
#define amg__i8_prepend_as_hdigit33(e,id,pred)   pred(,X##id
#define amg__i8_prepend_as_hdigit34(e,id,pred)   pred(,Y##id
#define amg__i8_prepend_as_hdigit35(e,id,pred)   pred(,Z##id

#define amg__prepend_as_hdigit(e,id,n,pred)  amg__prepend_as_hdigit##n(,e##id,e##pred)

#define amg__i8_prepend_as_hex_s2(e,id)           id
#define amg__i8_prepend_as_hex_s1(e,id,d2)        amg__i8_prepend_as_hdigit##d2(,e##id,amg__i8_prepend_as_hex_s2))
#define amg__i8_prepend_as_hex_s0(e,id,d2,d1)     amg__i8_prepend_as_hdigit##d1(,e##id,amg__i8_prepend_as_hex_s1),d2)
#define amg__i8t_prepend_as_hex(e,id,expand)      amg__i8_prepend_as_hex_s0(,e##id,expand)
//#define amg__i8a_prepend_as_hex(e,id,d2,d1)       amg__i8_prepend_as_hex_s0(,e##id,d2,d1)

#define amg_i8_prepend_as_hex( e,id,tuple)        amg__i8t_prepend_as_hex(,e##id,amg_expand2(,tuple))
#define amg_i8t_prepend_as_hex(e,id,tuple)        amg__i8t_prepend_as_hex(,e##id,amg_expand2(,tuple))
#define amg_i8h_prepend_as_hex(e,id,args)         amg__i8t_prepend_as_hex(,e##id,amg__h(,amg_i4h##args))

#define amg__i12_prepend_as_hex_s3(e,id)          id
#define amg__i12_prepend_as_hex_s2(e,id,d1)       amg__i12_prepend_as_hdigit##d3(,e##id,amg__i12_prepend_as_hex_s3))
#define amg__i12_prepend_as_hex_s1(e,id,d2,d1)    amg__i12_prepend_as_hdigit##d2(,e##id,amg__i12_prepend_as_hex_s2),d2)
#define amg__i12_prepend_as_hex_s0(e,id,d3,d2,d1) amg__i12_prepend_as_hdigit##d1(,e##id,amg__i12_prepend_as_hex_s1),d3,d2)
#define amg__i12t_prepend_as_hex(e,id,expand)     amg__i12_prepend_as_hex_s0(,e##id,expand)
//#define amg__i12a_prepend_as_hex(e,id,d3,d2,d1)      amg__i12_prepend_as_hex_s0(,e##id,d3,d2,d1)

#define amg_i12_prepend_as_hex( e,id,tuple)       amg__i12t_prepend_as_hex(,e##id,amg_expand3(,tuple))
#define amg_i12t_prepend_as_hex(e,id,tuple)       amg__i12t_prepend_as_hex(,e##id,amg_expand3(,tuple))
#define amg_i12h_prepend_as_hex(e,id,args)        amg__i12t_prepend_as_hex(,e##id,amg__h(,amg_i4h##args))

#endif
