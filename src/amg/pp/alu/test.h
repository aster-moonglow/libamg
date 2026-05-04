
/* Format: (S,1,2)(3,4)
// S is "size", number of following bytes.
// It's 2 in this example.
// Another example:
//  (7,1,2)(3,4)(5,6)(7,0)
*/
#if 0
#define AMG_iget4(d0,d1)      d0,d1,AMG_iget2
#define AMG_iget2(d0,d1)      d0,d1,
#define AMG_isz(sz,d0,d1)  sz,d0,d1,
#endif

#if 0
/* Format: (S,1)(2)(3)(4) */
/* S is "size", number of nybbles, including the one in the first parens. */
#define amg__iget1(h) h,
#define AMG_iget2(h) h,amg__iget1
#define AMG_isz(sz,h) sz,h,
#endif

#if 0
/* Format: (S,1,(2,(3,(4,)))) */
/* S is "size", number of nybbles in the tree, including the one to the right of `S`. */
#define amg__iget1(h,t) h,t
#define AMG_iget2(h,t) h,amg__iget1 t
#define AMG_isz(sz,h,t) sz,h,t
#endif

#if 0
#define amgf(front,list) front, amgf list

#define take(elem) elem,
#define expand(l) l
#define foonum 1,(2,(3,(4,
#define barnum ((((,4),3),2),1
#define quxnum 1,)(2,)(3,)(4,
#define quuxnum (1)(2)(3)(4)(5)(6
#define nonononooo 1,(3,(5,),2),0
#if 0
#define wlw(v,q)  #v q
#define quux(w,p) #w wlw p
#define qux(z,w)  #z quux w
#define baz(y,z)  #y qux z
#define bar(x,y)  #x baz y
#define foo(b)    #b bar b )

foo(foonum)
#endif

#define print(...) #__VA_ARGS__

#define amg__rparen )
#define head(head,tail) #head
#define tail(head,tail) tail
//#define wind0(tt,list)  tt(,wind1,tail list)
//#define wind1(tt,list)  tt(,wind0,tail list)
#define amg_wind1(pfx,tt,list)  print(pfx##tt(pfx,wind0,list)) (pfx,wind0,list
#define amg_wind0(pfx,tt,list)  print(pfx##tt(pfx,wind1,list)) (pfx,wind1,list
#define amg_wind(pfx,tt,list)   print(pfx##tt(pfx,wind,list))  (pfx,wind,list


#define amg_tock(pfx,fn,d,list) print(d: pfx##fn(pfx,tick,list))) pfx##tick amg_wind1(pfx,tick,take list))
#define amg_tick(pfx,fn,d,list) print(d: pfx##fn(pfx,tock,list))) pfx##tock amg_wind0(pfx,tock,take list))
//#define inittt(e,val) wind(tick,tail e##val))
//#define inittt(e,val) wind(,0,e##val,tick))))
#define inittt(e,val) print(amg_wind0(amg_,tick,0,take val))) amg_wind0(amg_,tick,take val)))))

//foonum))))
inittt(,quuxnum)
#endif

#define mynum 1)2)3)4)00)

#define amg_rm1
#define amg_rm2
#define amg_rm3
#define amg_rm4

#define amg_id1 1
#define amg_id2 2
#define amg_id3 3
#define amg_id4 4

#define print(...) #__VA_ARGS__

#if 0
#define upulseB(accum,digit,inum)  print(ubeat(A,accum,digit,inum)) \
	ubeat(A, accum,digit,inum)
#define upulseA(accum,digit,inum)  print(ubeat(B,accum,digit,inum)) \
	ubeat(B, accum,digit,inum)

#define ubeat(ab,accum,c,d)   print(upulse##ab(accum##d,d)) \
	c##d) upulse##ab(accum##d,d,

#define uop(inum)             print(ubeat(A,0,0,inum)) \
	ubeat(A,0,0,inum))

expand uop(mynum)a
#endif
#if 0
#define upulseA(accum,x,y,d)  print(ubeat(A,accum##d,x,d,...)) \
	y##d) ubeat(A, accum##d,x,d,

#define ubeat(ab,accum,y,x,d)   print(upulse##ab(accum##d,d,y,...)) \
	x##d) upulse##ab(accum##d,d,y,

#define uop(inum)             print(ubeat(A,0,0,inum)) \
	ubeat(A,0,0,,inum))

expand uop(mynum)
#endif
#if 0
#define bpulseB(e,accum,c,anum,bnum)  print(bbeat(A,accum,c,e##anum,e##bnum)) \
	bbeat(,A, accum,c,e##anum,e##bnum,bnum)
#define bpulseA(e,accum,c,anum,bnum)  print(bbeat(B,accum,c,e##anum,e##bnum)) \
	bbeat(,B, accum,c,e##anum,e##bnum,bnum)

#define bbeat0(e,ab,accum,c,anum,bnum,bd)   print(bbeat1(,ab,accum##bd,bd,e##anum,...)) \
	bbeat1(,ab,accum##bd,c,bd,e##bnum,anum,

#define bbeat1(e,ab,accum,c,bd,bnum,ad)   print(bpulse##ab(accum##ad,ad,e##bnum) \
	ab##bd##c) bpulse##ab(,accum##ad##bd##c,ad##bd,

#define bop(e,anum,bnum)             print(bbeat0(A,0,0,e##anum,e##bnum)) \
	bbeat(,A,0,0,e##anum,e##bnum,bnum))

expand bop(,mynum,mynum)
#endif

#if 0
#define amg__rparen16 )))) )))) )))) ))))
#define amg__rparen15 )))) )))) )))) )))
#define amg__rparen14 )))) )))) )))) ))
#define amg__rparen13 )))) )))) )))) )
#define amg__rparen12 )))) )))) ))))
#define amg__rparen11 )))) )))) )))
#define amg__rparen10 )))) )))) ))
#define amg__rparen9  )))) )))) )
#define amg__rparen8  )))) ))))
#define amg__rparen7  )))) )))
#define amg__rparen6  )))) ))
#define amg__rparen5  )))) )
#define amg__rparen4  ))))
#define amg__rparen3  )))
#define amg__rparen2  ))
#define amg__rparen1  )
#endif

#if 0
// This is where I fixed something that wasn't broken.
// (But it could have been important for correctly naming args when using paren-trains.)
// (And it did kinda show that intentional strat matches the accidental strat.)
// In other words: we learned that the (sz,1)(2)(3) format has the same traversal code as the (sz,1,(2,(3,))) code.
// And the former seems to take fewer tokens to represent, so that's what I'll go with.
// Also, the linear form might expand faster, because the amg__iget1 function doens't
// need to copy the entire list around in its argument list. It only needs to operate
// on the head itself. (The stepping function still has to copy everything, but
// doing this at least once seems to be unavoidable. Well, except for if things
// were stored OUTSIDE the active macro, as with the "1)2)3)00)" form, but it is
// VERY difficult to control such a thing when binary operations are involved!
// Still, that might be an interesting challenge at some point.)
// But this is really great.
// Because if the linear form proves difficult to handle (hard to keep trailing bits in an argument),
// then it is very easy to just switch back to the fallen-tree form/representation.
#define amg__bop0(c,a0,e1a,e2a,b0,e1b,e2b,fn,fnc)			      fn(c,a0,b0)
#define amg__bop1(c,a0,a1,ex_anum,b0,b1,ex_bnum,fn,fnc)           amg__bop0(c,a0,a1,ex_anum,b0,b1,ex_bnum,fn,fnc)
#define amg__bop2(c,a0,a1,anum,ex2_anum,b0,b1,bnum,ex2_bnum,fn,fnc) fn(c,a0,b0) amg__bop1(fnc(c,a0,b0),ex2_anum,amg__iget1 anum,ex2_bnum,amg__iget1 bnum,fn,fnc)
#define amg__bop3(c,a0,a1,anum,ex2_anum,b0,b1,bnum,ex2_bnum,fn,fnc) fn(c,a0,b0) amg__bop2(fnc(c,a0,b0),ex2_anum,AMG_iget2 anum,ex2_bnum,AMG_iget2 bnum,fn,fnc)
#define amg__bop4(c,a0,a1,anum,ex2_anum,b0,b1,bnum,ex2_bnum,fn,fnc) fn(c,a0,b0) amg__bop3(fnc(c,a0,b0),ex2_anum,AMG_iget2 anum,ex2_bnum,AMG_iget2 bnum,fn,fnc)
#define amg__bop5(c,a0,a1,anum,ex2_anum,b0,b1,bnum,ex2_bnum,fn,fnc) fn(c,a0,b0) amg__bop4(fnc(c,a0,b0),ex2_anum,AMG_iget2 anum,ex2_bnum,AMG_iget2 bnum,fn,fnc)
#define amg__bop6(c,a0,a1,anum,ex2_anum,b0,b1,bnum,ex2_bnum,fn,fnc) fn(c,a0,b0) amg__bop5(fnc(c,a0,b0),ex2_anum,AMG_iget2 anum,ex2_bnum,AMG_iget2 bnum,fn,fnc)
#define amg__bop7(c,a0,a1,anum,ex2_anum,b0,b1,bnum,ex2_bnum,fn,fnc) fn(c,a0,b0) amg__bop6(fnc(c,a0,b0),ex2_anum,AMG_iget2 anum,ex2_bnum,AMG_iget2 bnum,fn,fnc)
#define amg__bop8(c,a0,a1,anum,ex2_anum,b0,b1,bnum,ex2_bnum,fn,fnc) fn(c,a0,b0) amg__bop7(fnc(c,a0,b0),ex2_anum,AMG_iget2 anum,ex2_bnum,AMG_iget2 bnum,fn,fnc)

#define amg__bop_init2(asz,bsz,c,a0,anum1,a1,anum2,b0,bnum1,b1,bnum2,fn,fnc) \
	amg__bop##asz(c,a0,a1,anum2,AMG_iget2 anum1,b0,b1,bnum2,AMG_iget2 bnum1,fn,fnc)
//	amg__bop_init3(asz,bsz,c,a0,a1,anum1,anum2,amg__iget1 anum2,b0,b1,bnum1,bnum2,amg__iget1 bnum2,fn,fnc)
#endif
#if 0
#define amg__bopi1(asz,bsz,c,a0,anum1,ex_anum1,b0,bnum1,ex_bnum1,fn,fnc)  fn(c,a0,b0)
#define amg__bopi2(asz,bsz,c,a0,anum1,ex_anum1,b0,bnum1,ex_bnum1,fn,fnc)  fn(c,a0,b0) amg__bop0(fnc(c,a0,b0),ex_anum1,,ex_bnum1,,fn,fnc)
#define amg__bopi3(asz,bsz,c,a0,anum1,ex_anum1,b0,bnum1,ex_bnum1,fn,fnc)  amg__bop_init2(asz,bsz,c,a0,anum1,ex_anum1,b0,bnum1,ex_bnum1,fn,fnc)
#define amg__bopi4(asz,bsz,c,a0,anum1,ex_anum1,b0,bnum1,ex_bnum1,fn,fnc)  amg__bop_init2(asz,bsz,c,a0,anum1,ex_anum1,b0,bnum1,ex_bnum1,fn,fnc)
#define amg__bopi5(asz,bsz,c,a0,anum1,ex_anum1,b0,bnum1,ex_bnum1,fn,fnc)  amg__bop_init2(asz,bsz,c,a0,anum1,ex_anum1,b0,bnum1,ex_bnum1,fn,fnc)
#define amg__bopi6(asz,bsz,c,a0,anum1,ex_anum1,b0,bnum1,ex_bnum1,fn,fnc)  amg__bop_init2(asz,bsz,c,a0,anum1,ex_anum1,b0,bnum1,ex_bnum1,fn,fnc)
#define amg__bopi7(asz,bsz,c,a0,anum1,ex_anum1,b0,bnum1,ex_bnum1,fn,fnc)  amg__bop_init2(asz,bsz,c,a0,anum1,ex_anum1,b0,bnum1,ex_bnum1,fn,fnc)
#define amg__bopi8(asz,bsz,c,a0,anum1,ex_anum1,b0,bnum1,ex_bnum1,fn,fnc)  amg__bop_init2(asz,bsz,c,a0,anum1,ex_anum1,b0,bnum1,ex_bnum1,fn,fnc)
#define amg__bopi9(asz,bsz,c,a0,anum1,ex_anum1,b0,bnum1,ex_bnum1,fn,fnc)  amg__bop_init2(asz,bsz,c,a0,anum1,ex_anum1,b0,bnum1,ex_bnum1,fn,fnc)

#define amg__bop0(c,a0,e1a,e2a,b0,e1b,e2b,fn,fnc)			      fn(c,a0,b0)
#define amg__bop1(c,a0,a1,ex_anum,b0,b1,ex_bnum,fn,fnc)           amg__bop0(c,a0,a1,ex_anum,b0,b1,ex_bnum,fn,fnc)
#define amg__bop2(c,a0,a1,anum,ex_anum,b0,b1,bnum,ex_bnum,fn,fnc) fn(c,a0,b0) amg__bop1(fnc(c,a0,b0),ex_anum,amg__iget1 anum,ex_bnum,amg__iget1 bnum,fn,fnc)
#define amg__bop3(c,a0,a1,anum,ex_anum,b0,b1,bnum,ex_bnum,fn,fnc) fn(c,a0,b0) amg__bop2(fnc(c,a0,b0),ex_anum,AMG_iget2 anum,ex_bnum,AMG_iget2 bnum,fn,fnc)
#define amg__bop4(c,a0,a1,anum,ex_anum,b0,b1,bnum,ex_bnum,fn,fnc) fn(c,a0,b0) amg__bop3(fnc(c,a0,b0),ex_anum,AMG_iget2 anum,ex_bnum,AMG_iget2 bnum,fn,fnc)
#define amg__bop5(c,a0,a1,anum,ex_anum,b0,b1,bnum,ex_bnum,fn,fnc) fn(c,a0,b0) amg__bop4(fnc(c,a0,b0),ex_anum,AMG_iget2 anum,ex_bnum,AMG_iget2 bnum,fn,fnc)
#define amg__bop6(c,a0,a1,anum,ex_anum,b0,b1,bnum,ex_bnum,fn,fnc) fn(c,a0,b0) amg__bop5(fnc(c,a0,b0),ex_anum,AMG_iget2 anum,ex_bnum,AMG_iget2 bnum,fn,fnc)
#define amg__bop7(c,a0,a1,anum,ex_anum,b0,b1,bnum,ex_bnum,fn,fnc) fn(c,a0,b0) amg__bop6(fnc(c,a0,b0),ex_anum,AMG_iget2 anum,ex_bnum,AMG_iget2 bnum,fn,fnc)
#define amg__bop8(c,a0,a1,anum,ex_anum,b0,b1,bnum,ex_bnum,fn,fnc) fn(c,a0,b0) amg__bop7(fnc(c,a0,b0),ex_anum,AMG_iget2 anum,ex_bnum,AMG_iget2 bnum,fn,fnc)

#define amg__bop_init2(asz,bsz,c,a0,anum1,a1,anum2,b0,bnum1,b1,bnum2,fn,fnc) \
	amg__bop##asz(c,a0,a1,anum2,AMG_iget2 anum1,b0,b1,bnum2,AMG_iget2 bnum1,fn,fnc)

#define amg__bop_init1(c,asz,a0,anum1,bsz,b0,bnum1,fn,fnc) \
	amg__bopi##asz(asz,bsz,c,a0,anum1,amg__iget1 anum1,b0,bnum1,amg__iget1 bnum1,fn,fnc)

#define amg__bop_init0(c,ex_anum,ex_bnum,fn,fnc) \
	amg__bop_init1(c,ex_anum,ex_bnum,fn,fnc)
#endif

#define AMG_bopi1(asz,bsz,c,a0,a1,anum2,ex_anum2,b0,b1,bnum2,ex_bnum2,fn)  fn(c,a0,a1,b0,b1)
#define AMG_bopi2(asz,bsz,c,a0,a1,anum2,ex_anum2,b0,b1,bnum2,ex_bnum2,fn)  AMG_bop2(fnc(c,a0,a1,b0,b1),a0,a1,ex_anum2,,b0,b1,ex_bnum2,,fn)
#define AMG_bopi3(asz,bsz,c,a0,a1,anum2,ex_anum2,b0,b1,bnum2,ex_bnum2,fn)  AMG_bop_init2(asz,bsz,c,a0,a1,anum2,ex_anum2,b0,b1,bnum2,ex_bnum2,fn)
#define AMG_bopi4(asz,bsz,c,a0,a1,anum2,ex_anum2,b0,b1,bnum2,ex_bnum2,fn)  AMG_bop_init2(asz,bsz,c,a0,a1,anum2,ex_anum2,b0,b1,bnum2,ex_bnum2,fn)
#define AMG_bopi5(asz,bsz,c,a0,a1,anum2,ex_anum2,b0,b1,bnum2,ex_bnum2,fn)  AMG_bop_init2(asz,bsz,c,a0,a1,anum2,ex_anum2,b0,b1,bnum2,ex_bnum2,fn)
#define AMG_bopi6(asz,bsz,c,a0,a1,anum2,ex_anum2,b0,b1,bnum2,ex_bnum2,fn)  AMG_bop_init2(asz,bsz,c,a0,a1,anum2,ex_anum2,b0,b1,bnum2,ex_bnum2,fn)
#define AMG_bopi7(asz,bsz,c,a0,a1,anum2,ex_anum2,b0,b1,bnum2,ex_bnum2,fn)  AMG_bop_init2(asz,bsz,c,a0,a1,anum2,ex_anum2,b0,b1,bnum2,ex_bnum2,fn)
#define AMG_bopi8(asz,bsz,c,a0,a1,anum2,ex_anum2,b0,b1,bnum2,ex_bnum2,fn)  AMG_bop_init2(asz,bsz,c,a0,a1,anum2,ex_anum2,b0,b1,bnum2,ex_bnum2,fn)
#define AMG_bopi9(asz,bsz,c,a0,a1,anum2,ex_anum2,b0,b1,bnum2,ex_bnum2,fn)  AMG_bop_init2(asz,bsz,c,a0,a1,anum2,ex_anum2,b0,b1,bnum2,ex_bnum2,fn)
#define AMG_bopi10(asz,bsz,c,a0,a1,anum2,ex_anum2,b0,b1,bnum2,ex_bnum2,fn)  AMG_bop_init2(asz,bsz,c,a0,a1,anum2,ex_anum2,b0,b1,bnum2,ex_bnum2,fn)

#define AMG_bop_next0(n)
#define AMG_bop_next1(n)  AMG_bop##n
#define AMG_bop_next(c,n) AMG_bop_next##c

#define AMG_bop_end(cont,output)  output
#if 0
#define AMG_bop0(c,o,e0,e1,e2,e3,e4, e5,      e6,e7,e8,e9,e10,e11,    e12) o
#define AMG_bop1(c,o,a0,a1,                   b0,b1,                   fn) AMG_bop_end(fn(c,a0,a1,b0,b1))
#define AMG_bop2(c,o,a0,a1,a2,a3,a4e,a5e,     b0,b1,b2,b3,b4e,b5e,     fn) /*AMG_bop1(*/ AMG_bop_dispatch(fn,1,c,ex_anum,ex_bnum),a2,a3,b2,b3,fn)
#define AMG_bop3(c,o,a0,a1,a2,a3,anum,ex_anum,b0,b1,b2,b3,bnum,ex_bnum,fn) /*AMG_bop2(*/ AMG_bop_dispatch(fn,2,c,ex_anum,ex_bnum),ex_anum,AMG_iget2 anum,ex_bnum,AMG_iget2 bnum,fn)
#define AMG_bop4(c,o,a0,a1,a2,a3,anum,ex_anum,b0,b1,b2,b3,bnum,ex_bnum,fn) /*AMG_bop3(*/ AMG_bop_dispatch(fn,3,c,ex_anum,ex_bnum),ex_anum,AMG_iget4 anum,ex_bnum,AMG_iget4 bnum,fn)
#define AMG_bop5(c,o,a0,a1,a2,a3,anum,ex_anum,b0,b1,b2,b3,bnum,ex_bnum,fn) /*AMG_bop4(*/ AMG_bop_dispatch(fn,4,c,ex_anum,ex_bnum),ex_anum,AMG_iget4 anum,ex_bnum,AMG_iget4 bnum,fn)
#define AMG_bop6(c,o,a0,a1,a2,a3,anum,ex_anum,b0,b1,b2,b3,bnum,ex_bnum,fn) /*AMG_bop5(*/ AMG_bop_dispatch(fn,5,c,ex_anum,ex_bnum),ex_anum,AMG_iget4 anum,ex_bnum,AMG_iget4 bnum,fn)
#define AMG_bop7(c,o,a0,a1,a2,a3,anum,ex_anum,b0,b1,b2,b3,bnum,ex_bnum,fn) /*AMG_bop6(*/ AMG_bop_dispatch(fn,6,c,ex_anum,ex_bnum),ex_anum,AMG_iget4 anum,ex_bnum,AMG_iget4 bnum,fn)
#define AMG_bop8(c,o,a0,a1,a2,a3,anum,ex_anum,b0,b1,b2,b3,bnum,ex_bnum,fn) /*AMG_bop7(*/ AMG_bop_dispatch(fn,7,c,ex_anum,ex_bnum),ex_anum,AMG_iget4 anum,ex_bnum,AMG_iget4 bnum,fn)
#define AMG_bop9(c,o,a0,a1,a2,a3,anum,ex_anum,b0,b1,b2,b3,bnum,ex_bnum,fn) /*AMG_bop8(*/ AMG_bop_dispatch(fn,8,c,ex_anum,ex_bnum),ex_anum,AMG_iget4 anum,ex_bnum,AMG_iget4 bnum,fn)
#endif

#define AMG_iget2l(d0,d1)  (d0,d1,
#define AMG_iget2r(d0,d1)  d0,d1),

#if 0
#define AMG_bop0(c,o,e0,e1,e2,e3,e4,e5,e6)             o
#define AMG_bop1(c,o,ex_anum,ex_bnum,fn)               AMG_bop_dispatch(fn,0,c,o,ex_anum,ex_bnum),,,,,)
#define AMG_bop2(c,o,ex_anum,ex_bnum,fn) /*AMG_bop1(*/ AMG_bop_dispatch(fn,1,c,o,ex_anum,ex_bnum),fn)
#define AMG_bop3(c,o,ex_anum,ex_bnum,fn) /*AMG_bop2(*/ AMG_bop_dispatch(fn,2,c,o,ex_anum,ex_bnum),fn)
#define AMG_bop4(c,o,ex_anum,ex_bnum,fn) /*AMG_bop3(*/ AMG_bop_dispatch(fn,3,c,o,ex_anum,ex_bnum),fn)
#define AMG_bop5(c,o,ex_anum,ex_bnum,fn) /*AMG_bop4(*/ AMG_bop_dispatch(fn,4,c,o,ex_anum,ex_bnum),fn)
#define AMG_bop6(c,o,ex_anum,ex_bnum,fn) /*AMG_bop5(*/ AMG_bop_dispatch(fn,5,c,o,ex_anum,ex_bnum),fn)
#define AMG_bop7(c,o,ex_anum,ex_bnum,fn) /*AMG_bop6(*/ AMG_bop_dispatch(fn,6,c,o,ex_anum,ex_bnum),fn)
#define AMG_bop8(c,o,ex_anum,ex_bnum,fn) /*AMG_bop7(*/ AMG_bop_dispatch(fn,7,c,o,ex_anum,ex_bnum),fn)
#define AMG_bop9(c,o,ex_anum,ex_bnum,fn) /*AMG_bop8(*/ AMG_bop_dispatch(fn,8,c,o,ex_anum,ex_bnum),fn)

#define AMG_bop3init(c,anum,bnum,fn) AMG_bop3(c,,AMG_iget2 anum,AMG_iget2 bnum,fn)

#define AMG_bop_dispatch(fn,n,c,o,a0,a1,anum,b0,b1,bnum) \
	o fn(n,c,a0,a1,b0,b1),AMG_iget2 anum,AMG_iget2 bnum
#endif
#if 0
// WORKING
//#define h(d0,d1)    d0,d1
//#define g(d0,d1,rest) rest,d0,d1
#define AMG_e
#define AMG_iget2a(d0,d1)     d0,d1,AMG_iget2b AMG_e
#define AMG_iget2b(d0,d1)     d0,d1,AMG_iget2a AMG_e
#define AMG_igetsz(sz,d0,d1)  sz,d0,d1,AMG_iget2a AMG_e
//#define gg2          g2(

//#define AMG_bop00(cont,carry,e0,e1,e2,e3,e4,e5,e6)
//#define AMG_bop0(cont,carry,e0,e1,e2)
#define AMG_bop00(cont,carry)
#define AMG_bop0(cont,carry,e0,e1,e2)
//#define AMG_bop0(cont,carry,e0,e1,e2)
#define AMG_bop1(cont,carry,a0,a1,anum,b0,b1,bnum,fn)               fn##cont(00,carry,a0,a1,b0,b1))
#define AMG_bop2(cont,carry,a0,a1,anum,b0,b1,bnum,fn) /*AMG_bop1(*/ fn##cont(1,carry,a0,a1,b0,b1),anum,bnum,fn)
#define AMG_bop3(cont,carry,a0,a1,anum,b0,b1,bnum,fn) /*AMG_bop2(*/ fn##cont(2,carry,a0,a1,b0,b1),anum,bnum,fn)
#define AMG_bop4(cont,carry,a0,a1,anum,b0,b1,bnum,fn) /*AMG_bop3(*/ fn##cont(3,carry,a0,a1,b0,b1),anum,bnum,fn)
#define AMG_bop5(cont,carry,a0,a1,anum,b0,b1,bnum,fn) /*AMG_bop4(*/ fn##cont(4,carry,a0,a1,b0,b1),anum,bnum,fn)
#define AMG_bop6(cont,carry,a0,a1,anum,b0,b1,bnum,fn) /*AMG_bop5(*/ fn##cont(5,carry,a0,a1,b0,b1),anum,bnum,fn)
#define AMG_bop7(cont,carry,a0,a1,anum,b0,b1,bnum,fn) /*AMG_bop6(*/ fn##cont(6,carry,a0,a1,b0,b1),anum,bnum,fn)
#define AMG_bop8(cont,carry,a0,a1,anum,b0,b1,bnum,fn) /*AMG_bop7(*/ fn##cont(7,carry,a0,a1,b0,b1),anum,bnum,fn)
#define AMG_bop9(cont,carry,a0,a1,anum,b0,b1,bnum,fn) /*AMG_bop8(*/ fn##cont(8,carry,a0,a1,b0,b1),anum,bnum,fn)

//#define AMG_bop3init1(cont,ex_anum,ex_bnum,fn) AMG_bop3(cont,,ex_anum,ex_bnum,fn)
//#define AMG_bop3init0(cont,anum,bnum,fn)       AMG_bop3init1(cont,AMG_iget2a anum,AMG_iget2a bnum,fn)

#define AMG_bop_init1(carry,asz,a0,a1,anum,bsz,b0,b1,bnum,fn)  fn##1(asz,carry,a0,a1,b0,b1),anum,bnum,fn)
#define AMG_bop_init0(carry,ex_anum,ex_bnum,fn)                AMG_bop_init1(carry,ex_anum,ex_bnum,fn)
#define amg_mybop(carry,anum,bnum)                             AMG_bop_init0(carry,AMG_igetsz anum,AMG_igetsz bnum,AMG_continue)
#endif



#define AMG_stringize(token)  token
#define AMG_stringize0(token) #token

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
	#define amgpp_error(msg) AMG_error(__FILE__ "(" AMG_stringize(__LINE__) "): error: " msg)
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

#if 0
#define AMG_int_width_incr0   1
#define AMG_int_width_incr1   2
#define AMG_int_width_incr2   3
#define AMG_int_width_incr3   4
#define AMG_int_width_incr4   5
#define AMG_int_width_incr5   6
#define AMG_int_width_incr6   7
#define AMG_int_width_incr7   8
#define AMG_int_width_incr8   9
#define AMG_int_width_incr9  10
#define AMG_int_width_incr10 11
#define AMG_int_width_incr11 12
#define AMG_int_width_incr12 13
#define AMG_int_width_incr13 14
#define AMG_int_width_incr14 15
#define AMG_int_width_incr15 16
#define AMG_int_width_incr16 17

#define AMG_int_width_is_zero0   1
#define AMG_int_width_is_zero1   0
#define AMG_int_width_is_zero2   0
#define AMG_int_width_is_zero3   0
#define AMG_int_width_is_zero4   0
#define AMG_int_width_is_zero5   0
#define AMG_int_width_is_zero6   0
#define AMG_int_width_is_zero7   0
#define AMG_int_width_is_zero8   0
#define AMG_int_width_is_zero9   0
#define AMG_int_width_is_zero10  0
#define AMG_int_width_is_zero11  0
#define AMG_int_width_is_zero12  0
#define AMG_int_width_is_zero13  0
#define AMG_int_width_is_zero14  0
#define AMG_int_width_is_zero15  0
#endif

#if 0
#define AMG_bufsz(n) n
#define AMG_bufsz_incr(n) AMG_int_width_incr##n
#endif

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

#if 0
#define AMG_is_zero0   1
#define AMG_is_zero1   0
#define AMG_is_zero2   0
#define AMG_is_zero3   0
#define AMG_is_zero4   0
#define AMG_is_zero5   0
#define AMG_is_zero6   0
#define AMG_is_zero7   0
#define AMG_is_zero8   0
#define AMG_is_zero9   0
#define AMG_is_zero10  0
#define AMG_is_zero11  0
#define AMG_is_zero12  0
#define AMG_is_zero13  0
#define AMG_is_zero14  0
#define AMG_is_zero15  0
#endif

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

#if 0
#define AMG_i4decr1(c,a0)    AMG_call(AMG_i4decr2##c,(AMG_indecr##a0))
#define AMG_i4decr20(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs)  AMG_i4decr3##no(nres)
#define AMG_i4decr21(br,nr,cr, bc,nc,cc, bo,no,co, b0,n0,c0, bF,nF,cF, bs,ns,cs)  AMG_i4decr3##co(cres)
#define AMG_i4decr30(res)    0(res)
#define AMG_i4decr31(res)    1(res,15)
#endif

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
//#define AMG_PP_OPSTATE_ENDSIDE_MSB  3
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
	//(a0 a1) AMG_uop##n(1,carry,sign,buffer

#if 0
/* AMG_PP_OPSTATE_ENDSIDE_MSB */
#define AMG_vincr_state3(n,carry,sign,buffer,bufsz,ecount,vcount,msb_lo,msb_hi) \
	n_bytes_remaining, \
	carry, sign, buffer, \
	n_bytes_emitted, \
	n_bytes_visited, \
	a0,a1)     \
	AMG_vincr0( \
		n_bytes_remaining, AMG_PP_OPSTATE_ENDSIDE_MSB,  \
		buffer, n_bytes_emitted, n_bytes_visited, n_bytes_remaining, \
		AMG_vincr2##sign##carry, \
		(AMG_indecr##a0)(AMG_indecr##a1)) \
	)
	/* AMG_vincr1##carry(AMG_PP_OPSTATE_ENDSIDE_MSB, buffer, AMG_vincr2##sign##carry,(AMG_indecr##a0)(AMG_indecr##a1)) */

/* AMG_PP_OPSTATE_HEADER_GEN */
#define AMG_vincr_state4( \
	tail, grow, sign, buffer, \
	new_msb0,  new_msb1,  \
	orig_msb0, orig_msb1, \
	is_early_finish,   \
	n_bytes_emitted,   \
	n_bytes_visited,   \
	n_bytes_remaining, \
	n_bytes_total)     \
	AMG_vincr_header0##is_early_finish( \
		tail, grow, sign, buffer, \
		new_msb0,  new_msb1,  \
		orig_msb0, orig_msb1, \
		AMG_is_zero##n_bytes_emitted, \
		n_bytes_emitted, \
		n_bytes_total)
#endif


#if 0
n_bytes_total = n_bytes_remaining + n_bytes_buffered + n_bytes_emitted
n_bytes_emitted = nbytes_processed - n_bytes_buffered

n_bytes_buffered = axiomatic

n_bytes_emitted = n_bytes_total - (n_bytes_remaining + n_bytes_buffered)
n_bytes_emitted = n_bytes_total - n_bytes_remaining - n_bytes_buffered
#endif


/*
#define AMG_vincr10(state,buf,fn,args)  AMG_vincr4(state, buf, 15, fn args)
#define AMG_vincr11(state,buf,fn,args)  AMG_vincr4(state, buf,  0, fn args)
#define AMG_vincr12(state,buf,fn,args)  AMG_vincr4(state, buf,  0, fn args)
*/

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

#if 0 /* No longer true after splitting the state macros. */
/* `maybe_sz` is only defined when we're in the AMG_PP_OPSTATE_HEADER_GEN state.
// And it is defined as the size of the original number.
// It is useful further on if we need to expand
// a correct header after an early finish.
*/
#endif

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

#if 0
/* State 2 == AMG_PP_OPSTATE_ITERATION */
/* This implies that we are in the middle of the number.
// That makes it significant when the `carry` flag is set,
// and insignificant when the `overflow`/`grow` flag is set.
*/
#endif

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

#if 0
/* Carry 0 == decrement next byte */
#define AMG_vincr300(n,buf,ecount,vcount,res0,res1,ispad0,ispad1,carry,sign) \
	AMG_vincr4##ispad0##ispad1(n,buf,ecount,vcount,res0,res1,carry,sign)

/* Carry 1 == rest of bytes are unaffected */
/* (Common case) */
#define AMG_vincr301(n,buf,ecount,vcount,res0,res1,ispad0,ispad1,carry,sign) \
	buf(res0,res1) AMG_uop_passthrough(carry,sign,buf,vcount,vcount

/* Carry 2 == increment next byte */
#define AMG_vincr302(n,buf,ecount,vcount,res0,res1,ispad0,ispad1,carry,sign) \
	AMG_vincr4##ispad0##ispad1(n,buf,ecount,vcount,res0,res1,carry,sign)

/* TODO: This might never happen actually.
// If a number is already minimized, then only an operation
// that changes the sign of its byte can create the sign-and-following-bytes
// alignment necessary to make a shrink possible.
// Anything else won't _directly_ do that, and will,
// at best, cause a ripple that makes another byte change sign.
*/
/* No-shrink-possibility cases for increment/decrement */
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
#define AMG_vincr400(n,buf,ecount,vcount,res0,res1,carry,sign) \
	buf(res0,res1) AMG_uop##n(carry,sign,,vcount,vcount

#define AMG_vincr401(n,buf,ecount,vcount,res0,res1,carry,sign) \
	buf(res0,res1) AMG_uop##n(carry,sign,,vcount,vcount

#define AMG_vincr410(n,buf,ecount,vcount,res0,res1,carry,sign) \
	buf(res0,res1) AMG_uop##n(carry,sign,,vcount,vcount

/* Shrinkage might be possible. Buffer until we're sure.
// Things implicitly happening here:
// * (res0,res1) is added to the buffer.
//     If the buffer was empty, this will now be its value.
// * Nothing is emitted into the result. (yet?)
// * We remember the value of `n_bytes_emitted`/`ecount`
//     from the last time that we actually emitted a byte.
*/
#define AMG_vincr411(n,buf,ecount,vcount,res0,res1,carry,sign) \
	AMG_uop##n(carry,sign,buf(res0,res1),ecount,vcount
#endif

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

#if 0
/* TODO: What if there is more than one byte buffered?
//   How to emit the right ones while finding the MSB?
//   This might be a "If you call `truncate`, you must
//   put the new MSB at the _beginning_ of the buffer,
//   even if that seems backwards.
//   For now, I don't think I need truncation?
*/
/* Early finish: Truncation */
/*
// In this case, we don't emit anything beyond
// the tail, and we retrieve our MSB from the buffer.
//
// (Any code calling AMG_uop_truncate should
// place the MSB into the buffer rather than
// emitting it at the end of the tail. This
// allows us to place the post-truncation
// MSB into the correct position: the header.)
*/
#define AMG_vincr_header02( \
	tail, buffer, msb0, msb1, \
	n_bytes_emitted, n_bytes_total, fn, args) \
	AMG_vincr_truncate3(tail, AMG_ipop2 buffer)

#define AMG_vincr_truncate4(tail, msb_and_buffer) \
	AMG_vincr_truncate5(tail, msb_and_buffer)

#define AMG_vincr_truncate5(tail, msb0, msb1, buffer) \
	/* TODO: Shrinking? Detect SBR/SNR? */
#endif

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

#if 0
/* Dispatch to the generator for the appropriate SBR/SNR. See table below. */
#define AMG_vincr_shrink6(lo,hi,  lo_sign, hi_padclass) \
	AMG_vincr_shrink6##lo_sign##hi_padclass(lo,hi)

/* AMG_vincr_shrink600 -> 0b XXX0 0000 -> 0(XXX0)       e.g. `hi` is unnecessary (pos) sign extension
// AMG_vincr_shrink601 -> 0b XXX0 XXXX -> 1(XXX0,XXXX)  e.g. `hi` is not sign extension
// AMG_vincr_shrink602 -> 0b XXX0 1111 -> 1(XXX0,1111)  e.g. `hi` looks like sign extend, but isn't
// AMG_vincr_shrink610 -> 0b XXX1 0000 -> 1(XXX1,0000)  e.g. `hi` looks like sign extend, but isn't
// AMG_vincr_shrink611 -> 0b XXX1 XXXX -> 1(XXX1,XXXX)  e.g. `hi` is not sign extension
// AMG_vincr_shrink612 -> 0b XXX1 1111 -> 0(XXX1)       e.g. `hi` is unnecessary (neg) sign extension
*/
#define AMG_vincr_shrink600(lo,hi)  0(lo)
#define AMG_vincr_shrink601(lo,hi)  1(lo,hi)
#define AMG_vincr_shrink602(lo,hi)  1(lo,hi)
#define AMG_vincr_shrink610(lo,hi)  1(lo,hi)
#define AMG_vincr_shrink611(lo,hi)  1(lo,hi)
#define AMG_vincr_shrink612(lo,hi)  0(lo)
#endif

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

#if 0
/* State 3 == AMG_PP_OPSTATE_ENDSIDE_MSB */
#endif
#if 0
/* State 3 == AMG_PP_OPSTATE_HEADER_GEN */
/* This implies that we are at the end of the number.
// This makes it significant when the `overflow`/`grow` flag
// is set, and insignificant when the `carry` flag is set.
//
// Notably, these all do the same dispatch.
// But it saves us on expansion depth for the common
// case of `AMG_vincr621`, so it should be worth it.
// (Without this arrangement, the common case would
// would require us to expand on the state code and
// _then_ expand again on carry. For the less common
// `63*` cases, we'll need to expand on state code
// regardless, so it doesn't increase expansion
// depth here. All it does is add a couple redundant
// macro definitions, which should be fine.)
*/
#define AMG_vincr_header630(n,buf,tail,is_early,ecount,vcount,sz,res0,res1,ispad0,ispad1,grow,carry,sign) \
	AMG_vincr_header7##ispad0##ispad1(n,buf,is_early,ecount,vcount,sz,res0,res1,grow,sign)

#define AMG_vincr_header631(n,buf,tail,is_early,ecount,vcount,sz,res0,res1,ispad0,ispad1,grow,carry,sign) \
	AMG_vincr_header7##ispad0##ispad1(n,buf,is_early,ecount,vcount,sz,res0,res1,grow,sign)

#define AMG_vincr_header632(n,buf,tail,is_early,ecount,vcount,sz,res0,res1,ispad0,ispad1,grow,carry,sign) \
	AMG_vincr_header7##ispad0##ispad1(n,buf,is_early,ecount,vcount,sz,res0,res1,grow,sign)
#endif

#if 0
#define AMG_vincr4(state, buf, pad, expr) AMG_vincr5(state, buf, pad, AMG_bool##n, expr)
#define AMG_vincr5(state, buf, pad, res0, ispad0, res1, ispad1, grow, carry, sign) \
	AMG_vincr6##ispad0##ispad1(state,buf,pad,res0,res1,grow,carry,sign)
#endif
#define AMG_vincr_header700(n,buf,ecount,vcount,res0,res1,grow,sign) AMG_vincr80##grow(n,buf,ecount,vcount,res0,res1,sign)
#define AMG_vincr_header701(n,buf,ecount,vcount,res0,res1,grow,sign) AMG_vincr80##grow(n,buf,ecount,vcount,res0,res1,sign)
#define AMG_vincr_header710(n,buf,ecount,vcount,res0,res1,grow,sign) AMG_vincr80##grow(n,buf,ecount,vcount,res0,res1,sign)
#define AMG_vincr_header711(n,buf,ecount,vcount,res0,res1,grow,sign) AMG_vincr81##grow(n,buf,ecount,vcount,res0,res1,sign)


/* AMG_vincr8 conditions:
// First 0|1:
//     (Prev-byte's sign is 0 && this-byte is all 0s)
//  || (Prev-byte's sign is 1 && this-byte is all Fs)
//     A.K.A. "we should shrink by removing redundant sign bits"
//
// Second 0|1:
//     signed overflow A.K.A. "we should grow by 1 byte"
*/

/* TODO: Manage buffer size. */
/* (By convention, the buffer should begin with an integer token (edit: begin with a parenthesized integer token)
// to indicate its size to the header-writing-code. In the meantime,
// we have to place that integer there when we initially detect
// a padding pattern, then increment it whenever that pattern continues.
*/

/* TODO: passthrough detection */
/* buffer AMG_uop_passthrough( */


/* AMG_vincr800 means we don't shrink (e.g. to remove runs of unused sign bits)
// or expand (e.g. because we had signed overflow and need to add a new
// sign bit to keep the sign-byte correct).
//
// We emit the buffer, because if we encounter anything that doesn't match
// the "all-bits-equal-previous-sign", then we know that any preceding bytes
// that match that pattern were not _actually_ sign bits. They were just an
// ordinary part of the number. They will have been buffered due to the
// suspicion, so we'll emit that buffer to make sure they are included
// in the result number. If there is no buffer, then this won't have any
// negative effects. For this non-shrink case, this can only do good things.
//
// Notably, we don't emit (res0,res1) because this is
// in the context of AMG_PP_OPSTATE_ENDSIDE_MSB.
// Since we're not growing, we need to put the
// MSB into the header of the result number,
// which happens in the next iteration.
*/
#define AMG_vincr800(n,buf,ecount,vcount,res0,res1,sign) \
	buf  AMG_uop##n(0,sign,buffer,vcount,vcount

/* TODO: How do we send the updated MSB to the iterator?? */

/* AMG_vincr801 means we don't shrink but we DO expand (grow).
//
//
*/
#define AMG_vincr801(n,buf,ecount,vcount,res0,res1,sign) \


0(res0)
#define AMG_vincr810(n,buf,pad,res0,res1,c,s)  2(1,res0,res1)(pad,pad)
#define AMG_vincr811(n,buf,pad,res0,res1,c,s) \
	AMG_error("AMG_i8indecr811: Reached an unreachable branch in macro arithmatic increment-carry/decrement-borrow code.")
	/* Notably, in add/subtract, the above case IS reachable. */
	/* In that situation, it's another growth case. */

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

/* Rippled all the way! */
/* In this case, we use the updated MSB.
// The original MSB will be out-of-date.
*/
#define AMG_vincr_header00( \
	tail, carry, sign, buffer, msb0, msb1, \
	emitted_no_bytes, \
	n_bytes_emitted,  \
	n_bytes_total)    \
	AMG_vincr_header1##grow( \
		tail, AMG_sign_to_pad##sign, \
		buffer, msb_lo, msb_hi, \
		emitted_no_bytes, \
		n_bytes_emitted, \
		n_bytes_total)

/* Early finish. */
/* (Actually the common case for incrementation.)
// In this case, we never grow, and sign doesn't matter.
// Also, anything buffered (bytes suspected of being sign extension)
// can be emitted, because we're still in the interior of the number,
// so they WILL be significant and meaningful.
//
// Also, we will use the original MSB instead of the "new" one.
// In fact, we won't _have_ a "new" msb, because the iterator never
// "reached" the MSB.
*/
#define AMG_vincr_header01( \
	tail, carry, sign, buffer, msb0, msb1, \
	emitted_no_bytes, \
	n_bytes_emitted, \
	n_bytes_total) \
	\
	2(n_bytes_total,msb_lo,msb_hi) tail buffer
	/* The iterator will expand pass-through bytes to the right of this expansion. */

/* No growth; possibly even shrinking. */
/*
// In either case, we toss out the buffer.
// If there's no resizing, then the buffer is empty.
// If there IS resizing, then it's shrinking,
// and we shrink by discarding the buffer.
//
// We also toss out the `sign` parameter, because
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
#define AMG_vincr_header10( \
	tail, pad, buffer, \
	msb_lo, msb_hi, \
	emitted_no_bytes, \
	n_bytes_emitted, \
	n_bytes_total) \
	AMG_vincr_header2##emitted_no_bytes( \
		tail, msb_lo, msb_hi, \
		n_bytes_emitted, \
		n_bytes_total)

/* Growth case */
/* Optimization: We don't emit the buffer.
// That's because the buffer will just contain sign bits,
// which is what we're pattern-matching when filling the buffer.
// If it were all sign bits right up to the end, then we
// wouldn't be growing: we'd be shrinking.
// So a non-empty buffer should never happen in the growth case.
*/
#define AMG_vincr_header11( \
	tail, pad, buffer, \
	msb_lo, msb_hi, \
	emitted_no_bytes, \
	n_bytes_emitted, \
	n_bytes_total) \
	\
	2(AMG_int_width_incr##n_bytes_total, pad, pad) tail

/* Output-is-variable-width-rep case */
#define AMG_vincr_header20(tail, msb_lo, msb_hi, n_bytes_emitted) \
	2(n_bytes_emitted, msb_lo, msb_hi) tail

/* Output-is-SBR-or-SNR case */
/*
// This case notably contains a lot of extra macro expansions.
// It's probably not very fast, at least compared to the other cases.
// However, it should, _in principle_, be very rare. Like, probability less than 1/256.
// And only for 2-byte variable-width integers.
// There are only two integer values in the entire number line that can lead to this case!
// (And only one for incrementation, and one for decrementation.)
// So it might be possible to optimize this further, but it's not a priority right now.
*/
#define AMG_vincr_header21(tail, msb_lo, msb_hi, n_bytes_emitted) \
	AMG_vincr_header3(msb_lo, msb_hi, AMG_sign##msb_lo, AMG_classify_pad##msb_hi)

/* Intermediate macro used to ensure that `lo_sign` and `hi_padclass` are expanded. */
#define AMG_vincr_header3(msb_lo, msb_hi, lo_sign, hi_padclass) \
	AMG_vincr_header4(msb_lo, msb_hi, lo_sign, hi_padclass)

/* Dispatch to the generator for the appropriate SBR/SNR. See table below. */
#define AMG_vincr_header4(msb_lo, msb_hi, lo_sign, hi_padclass) \
	AMG_vincr_header4##lo_sign##hi_padclass(msb_lo, msb_hi)

/* AMG_vincr_header400 -> 0b XXX0 0000 -> 0(XXX0)       e.g. `hi` is unnecessary (pos) sign extension
// AMG_vincr_header401 -> 0b XXX0 XXXX -> 1(XXX0,XXXX)  e.g. `hi` is not sign extension
// AMG_vincr_header402 -> 0b XXX0 1111 -> 1(XXX0,1111)  e.g. `hi` looks like sign extend, but isn't
// AMG_vincr_header410 -> 0b XXX1 0000 -> 1(XXX1,0000)  e.g. `hi` looks like sign extend, but isn't
// AMG_vincr_header411 -> 0b XXX1 XXXX -> 1(XXX1,XXXX)  e.g. `hi` is not sign extension
// AMG_vincr_header412 -> 0b XXX1 1111 -> 0(XXX1)       e.g. `hi` is unnecessary (neg) sign extension
*/
#define AMG_vincr_header400(lo,hi)  0(lo)
#define AMG_vincr_header401(lo,hi)  1(lo,hi)
#define AMG_vincr_header402(lo,hi)  1(lo,hi)
#define AMG_vincr_header410(lo,hi)  1(lo,hi)
#define AMG_vincr_header411(lo,hi)  1(lo,hi)
#define AMG_vincr_header412(lo,hi)  0(lo)
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

/*
#define AMG_uop(carry_in,fn_nyb,fn_byte,num) AMG_uop_sel num ,carry_in,fn_nyb,fn_byte)
#define AMG_uop_sel(t) AMG_uop##t
#define AMG_uop0  AMG_uop_snr(AMG_iget1
#define AMG_uop1  AMG_uop_sbr(AMG_iget2
#define AMG_uop2  AMG_uop_var(AMG_igetsz
#define AMG_uop_snr(a0,carry_in,fn_nyb,fn_byte)       fn_nyb(carry_in,a0)
#define AMG_uop_sbr(ex_anum,carry_in,fn_nyb,fn_byte)  fn_byte##1(carry_in,a0,a1)
#define AMG_uop_var(ex_anum,carry_in,fn_nyb,fn_byte)
*/

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
// #define AMG_uop1(carry,sign,buffer,ecount,vcount,n,a0,a1,anum,next_state,fn)  fn##next_state( 0,carry,sign,buffer,ecount,vcount,a0,a1),AMG_int_width_incr##vcount,0,,AMG_PP_OPSTATE_HEADER_GEN,fn)
//#define AMG_uop0(carry,sign,buffer,msb0,msb1,ecount,vcount,n,next_state,fn)   ,carry,sign,buffer,ecount,0,,next_state
/*
#define AMG_uop11(cont,carry,sign,buffer,a0,a1,anum,fn)               fn##cont(10,carry,sign,buffer,a0,a1),,,)
#define AMG_uop10(cont,carry,sign,buffer,e0,e1,e2,  e3)
#define AMG_uop0( cont,carry,sign,buffer,ex_anum,fn)                  AMG_vuop01(carry,sign,ex_anum,fn)
#define AMG_uop01(carry,sign,a0,a1,ajunk,fn)                          fn##1(00,carry,sign,,a0,a1))
#define AMG_uop00(cont,carry,buffer,sign)
*/
#define AMG_uop_aborted(e0,e1,e2,e3,e4)

//#define AMG_AMG_iget2a
//#define AMG_AMG_iget2b
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

/* We don't have assertions rn. They are going to be tricky. But we can at least write down our intentions. */
#define amgpp_testcase(expr,spc0,expect,spc1) testcase  #expr spc0 expected: expect spc1 got: expr
AMG_uop(AMG_PP_OPSTATE_ITERATION,AMG_int_width_max,0,AMG_i4incr0,AMG_i8incr0,AMG_vincr0,0(5)) /* decr 5 -> 4 */
AMG_uop(AMG_PP_OPSTATE_ITERATION,AMG_int_width_max,1,AMG_i4incr0,AMG_i8incr0,AMG_vincr0,0(5)) /* noop 5 -> 5 */
AMG_uop(AMG_PP_OPSTATE_ITERATION,AMG_int_width_max,2,AMG_i4incr0,AMG_i8incr0,AMG_vincr0,0(5)) /* incr 5 -> 6 */
amgpp_testcase(amgpp_incr(1(3,6)),...........,1(4,6),...........) /* expect 1(4,6) */
amgpp_testcase(amgpp_decr(1(3,6)),...........,1(2,6),...........) /* expect 1(2,6) */
amgpp_testcase(amgpp_incr(1(15,7)),..........,2(1,0,0)(0,8),....) /* expect 2(1,0,0)(0,8) */
amgpp_testcase(amgpp_decr(1(0,8)),...........,2(1,15,15)(15,7),.) /* expect 2(1,15,15)(15,7) */
amgpp_testcase(amgpp_incr(2(1,1,2)(3,4)),....,2(1,1,2)(4,4),....) /* expect 2(1,1,2)(4,4) */
amgpp_testcase(amgpp_incr(2(1,15,15)(15,7)),.,1(0,8),...........) /* expect 1(0,8) */
amgpp_testcase(amgpp_decr(2(1,0,0)(0,8)),....,1(15,7),..........) /* expect 1(15,7) */

amgpp_testcase(amgpp_incr(2(3,15,15)(15,15)(15,7)(15,15)),, 2(1,0,8)(0,0),)
amgpp_testcase(amgpp_decr(2(1,0,8)(0,0)),, 2(2,15,15)(15,15)(15,7),)
amgpp_testcase(amgpp_decr(2(2,15,15)(0,0)(0,0)),, 2(2,14,15)(15,15)(15,15),)

amgpp_testcase(amgpp_incr(0(0)),...........,0(1),...........)
amgpp_testcase(amgpp_decr(0(0)),...........,0(15),..........)
amgpp_testcase(amgpp_incr(0(15)),..........,0(0),...........)
amgpp_testcase(amgpp_decr(0(15)),..........,0(14),..........)

amgpp_testcase(amgpp_incr(0(7)),...........,1(8,0),.........)
amgpp_testcase(amgpp_decr(0(8)),...........,1(7,15),........)
amgpp_testcase(amgpp_incr(1(7,15)),........,0(8),...........)
amgpp_testcase(amgpp_decr(1(8,0)),.........,0(7),...........)

amgpp_testcase(amgpp_i16_incr(2(3,15,7)(15,15)(15,15)(15,15)),..,2(3,15,7)(0,0)(0,0)(15,15),...)
amgpp_testcase(amgpp_i16_decr(2(3,0,8)(0,0)(0,0)(0,0)),.........,2(3,0,8)(15,15)(15,15)(0,0),..)



/* A=0  AMG_AplusB  nr,cr, nc,cc, no,co, n0,c0, nF,cF, ns,cs */
#define AMG_0plus0   0, 1,  0, 0,  0, 0,  1, 0,  0, 0,  0, 0
#define AMG_0plus1   1, 2,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_0plus2   2, 3,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_0plus3   3, 4,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_0plus4   4, 5,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_0plus5   5, 6,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_0plus6   6, 7,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_0plus7   7, 8,  0, 0,  0, 1,  0, 0,  0, 0,  0, 1
#define AMG_0plus8   8, 9,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_0plus9   9,10,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_0plus10 10,11,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_0plus11 11,12,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_0plus12 12,13,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_0plus13 13,14,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_0plus14 14,15,  0, 0,  0, 0,  0, 0,  0, 1,  1, 1
#define AMG_0plus15 15, 0,  0, 1,  0, 0,  0, 1,  1, 0,  1, 0

/* A=1  AMG_AplusB  nr,cr, nc,cc, no,co, n0,c0, nF,cF, ns,cs */
#define AMG_1plus0   1, 2,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_1plus1   2, 3,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_1plus2   3, 4,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_1plus3   4, 5,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_1plus4   5, 6,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_1plus5   6, 7,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_1plus6   7, 8,  0, 0,  0, 1,  0, 0,  0, 0,  0, 1
#define AMG_1plus7   8, 9,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_1plus8   9,10,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_1plus9  10,11,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_1plus10 11,12,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_1plus11 12,13,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_1plus12 13,14,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_1plus13 14,15,  0, 0,  0, 0,  0, 0,  0, 1,  1, 1
#define AMG_1plus14 15, 0,  0, 1,  0, 0,  0, 1,  1, 0,  1, 0
#define AMG_1plus15  0, 1,  1, 1,  0, 0,  1, 0,  0, 0,  0, 0

/* A=2  AMG_AplusB  nr,cr, nc,cc, no,co, n0,c0, nF,cF, ns,cs */
#define AMG_2plus0   2, 3,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_2plus1   3, 4,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_2plus2   4, 5,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_2plus3   5, 6,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_2plus4   6, 7,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_2plus5   7, 8,  0, 0,  0, 1,  0, 0,  0, 0,  0, 1
#define AMG_2plus6   8, 9,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_2plus7   9,10,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_2plus8  10,11,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_2plus9  11,12,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_2plus10 12,13,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_2plus11 13,14,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_2plus12 14,15,  0, 0,  0, 0,  0, 0,  0, 1,  1, 1
#define AMG_2plus13 15, 0,  0, 1,  0, 0,  0, 1,  1, 0,  1, 0
#define AMG_2plus14  0, 1,  1, 1,  0, 0,  1, 0,  0, 0,  0, 0
#define AMG_2plus15  1, 2,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0

/* A=3  AMG_AplusB  nr,cr, nc,cc, no,co, n0,c0, nF,cF, ns,cs */
#define AMG_3plus0   3, 4,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_3plus1   4, 5,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_3plus2   5, 6,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_3plus3   6, 7,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_3plus4   7, 8,  0, 0,  0, 1,  0, 0,  0, 0,  0, 1
#define AMG_3plus5   8, 9,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_3plus6   9,10,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_3plus7  10,11,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_3plus8  11,12,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_3plus9  12,13,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_3plus10 13,14,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_3plus11 14,15,  0, 0,  0, 0,  0, 0,  0, 1,  1, 1
#define AMG_3plus12 15, 0,  0, 1,  0, 0,  0, 1,  1, 0,  1, 0
#define AMG_3plus13  0, 1,  1, 1,  0, 0,  1, 0,  0, 0,  0, 0
#define AMG_3plus14  1, 2,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_3plus15  2, 3,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0

/* A=4  AMG_AplusB  nr,cr, nc,cc, no,co, n0,c0, nF,cF, ns,cs */
#define AMG_4plus0   4, 5,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_4plus1   5, 6,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_4plus2   6, 7,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_4plus3   7, 8,  0, 0,  0, 1,  0, 0,  0, 0,  0, 1
#define AMG_4plus4   8, 9,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_4plus5   9,10,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_4plus6  10,11,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_4plus7  11,12,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_4plus8  12,13,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_4plus9  13,14,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_4plus10 14,15,  0, 0,  0, 0,  0, 0,  0, 1,  1, 1
#define AMG_4plus11 15, 0,  0, 1,  0, 0,  0, 1,  1, 0,  1, 0
#define AMG_4plus12  0, 1,  1, 1,  0, 0,  1, 0,  0, 0,  0, 0
#define AMG_4plus13  1, 2,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_4plus14  2, 3,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_4plus15  3, 4,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0

/* A=5  AMG_AplusB  nr,cr, nc,cc, no,co, n0,c0, nF,cF, ns,cs */
#define AMG_5plus0   5, 6,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_5plus1   6, 7,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_5plus2   7, 8,  0, 0,  0, 1,  0, 0,  0, 0,  0, 1
#define AMG_5plus3   8, 9,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_5plus4   9,10,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_5plus5  10,11,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_5plus6  11,12,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_5plus7  12,13,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_5plus8  13,14,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_5plus9  14,15,  0, 0,  0, 0,  0, 0,  0, 1,  1, 1
#define AMG_5plus10 15, 0,  0, 1,  0, 0,  0, 1,  1, 0,  1, 0
#define AMG_5plus11  0, 1,  1, 1,  0, 0,  1, 0,  0, 0,  0, 0
#define AMG_5plus12  1, 2,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_5plus13  2, 3,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_5plus14  3, 4,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_5plus15  4, 5,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0

/* A=6  AMG_AplusB  nr,cr, nc,cc, no,co, n0,c0, nF,cF, ns,cs */
#define AMG_6plus0   6, 7,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_6plus1   7, 8,  0, 0,  0, 1,  0, 0,  0, 0,  0, 1
#define AMG_6plus2   8, 9,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_6plus3   9,10,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_6plus4  10,11,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_6plus5  11,12,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_6plus6  12,13,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_6plus7  13,14,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_6plus8  14,15,  0, 0,  0, 0,  0, 0,  0, 1,  1, 1
#define AMG_6plus9  15, 0,  0, 1,  0, 0,  0, 1,  1, 0,  1, 0
#define AMG_6plus10  0, 1,  1, 1,  0, 0,  1, 0,  0, 0,  0, 0
#define AMG_6plus11  1, 2,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_6plus12  2, 3,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_6plus13  3, 4,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_6plus14  4, 5,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_6plus15  5, 6,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0

/* A=7  AMG_AplusB  nr,cr, nc,cc, no,co, n0,c0, nF,cF, ns,cs */
#define AMG_7plus0   7, 8,  0, 0,  0, 1,  0, 0,  0, 0,  0, 1
#define AMG_7plus1   8, 9,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_7plus2   9,10,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_7plus3  10,11,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_7plus4  11,12,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_7plus5  12,13,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_7plus6  13,14,  0, 0,  1, 1,  0, 0,  0, 0,  1, 1
#define AMG_7plus7  14,15,  0, 0,  1, 1,  0, 0,  0, 1,  1, 1
#define AMG_7plus8  15, 0,  0, 1,  0, 0,  0, 1,  1, 0,  1, 0
#define AMG_7plus9   0, 1,  1, 1,  0, 0,  1, 0,  0, 0,  0, 0
#define AMG_7plus10  1, 2,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_7plus11  2, 3,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_7plus12  3, 4,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_7plus13  4, 5,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_7plus14  5, 6,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_7plus15  6, 7,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0

/* A=8  AMG_AplusB  nr,cr, nc,cc, no,co, n0,c0, nF,cF, ns,cs */
#define AMG_8plus0   8, 9,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_8plus1   9,10,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_8plus2  10,11,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_8plus3  11,12,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_8plus4  12,13,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_8plus5  13,14,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_8plus6  14,15,  0, 0,  0, 0,  0, 0,  0, 1,  1, 1
#define AMG_8plus7  15, 0,  0, 1,  0, 0,  0, 1,  1, 0,  1, 0
#define AMG_8plus8   0, 1,  1, 1,  1, 1,  1, 0,  0, 0,  0, 0
#define AMG_8plus9   1, 2,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_8plus10  2, 3,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_8plus11  3, 4,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_8plus12  4, 5,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_8plus13  5, 6,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_8plus14  6, 7,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_8plus15  7, 8,  1, 1,  1, 0,  0, 0,  0, 0,  0, 1

/* A=9  AMG_AplusB  nr,cr, nc,cc, no,co, n0,c0, nF,cF, ns,cs */
#define AMG_9plus0   9,10,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_9plus1  10,11,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_9plus2  11,12,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_9plus3  12,13,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_9plus4  13,14,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_9plus5  14,15,  0, 0,  0, 0,  0, 0,  0, 1,  1, 1
#define AMG_9plus6  15, 0,  0, 1,  0, 0,  0, 1,  1, 0,  1, 0
#define AMG_9plus7   0, 1,  1, 1,  0, 0,  1, 0,  0, 0,  0, 0
#define AMG_9plus8   1, 2,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_9plus9   2, 3,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_9plus10  3, 4,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_9plus11  4, 5,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_9plus12  5, 6,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_9plus13  6, 7,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_9plus14  7, 8,  1, 1,  1, 0,  0, 0,  0, 0,  0, 1
#define AMG_9plus15  8, 9,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1

/* A=10 AMG_AplusB   nr,cr, nc,cc, no,co, n0,c0, nF,cF, ns,cs */
#define AMG_10plus0  10,11,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_10plus1  11,12,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_10plus2  12,13,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_10plus3  13,14,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_10plus4  14,15,  0, 0,  0, 0,  0, 0,  0, 1,  1, 1
#define AMG_10plus5  15, 0,  0, 1,  0, 0,  0, 1,  1, 0,  1, 0
#define AMG_10plus6   0, 1,  1, 1,  0, 0,  1, 0,  0, 0,  0, 0
#define AMG_10plus7   1, 2,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_10plus8   2, 3,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_10plus9   3, 4,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_10plus10  4, 5,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_10plus11  5, 6,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_10plus12  6, 7,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_10plus13  7, 8,  1, 1,  1, 0,  0, 0,  0, 0,  0, 1
#define AMG_10plus14  8, 9,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_10plus15  9,10,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1

/* A=11 AMG_AplusB   nr,cr, nc,cc, no,co, n0,c0, nF,cF, ns,cs */
#define AMG_11plus0  11,12,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_11plus1  12,13,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_11plus2  13,14,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_11plus3  14,15,  0, 0,  0, 0,  0, 0,  0, 1,  1, 1
#define AMG_11plus4  15, 0,  0, 1,  0, 0,  0, 1,  1, 0,  1, 0
#define AMG_11plus5   0, 1,  1, 1,  0, 0,  1, 0,  0, 0,  0, 0
#define AMG_11plus6   1, 2,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_11plus7   2, 3,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_11plus8   3, 4,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_11plus9   4, 5,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_11plus10  5, 6,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_11plus11  6, 7,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_11plus12  7, 8,  1, 1,  1, 0,  0, 0,  0, 0,  0, 1
#define AMG_11plus13  8, 9,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_11plus14  9,10,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_11plus15 10,11,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1

/* A=12 AMG_AplusB   nr,cr, nc,cc, no,co, n0,c0, nF,cF, ns,cs */
#define AMG_12plus0  12,13,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_12plus1  13,14,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_12plus2  14,15,  0, 0,  0, 0,  0, 0,  0, 1,  1, 1
#define AMG_12plus3  15, 0,  0, 1,  0, 0,  0, 1,  1, 0,  1, 0
#define AMG_12plus4   0, 1,  1, 1,  0, 0,  1, 0,  0, 0,  0, 0
#define AMG_12plus5   1, 2,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_12plus6   2, 3,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_12plus7   3, 4,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_12plus8   4, 5,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_12plus9   5, 6,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_12plus10  6, 7,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_12plus11  7, 8,  1, 1,  1, 0,  0, 0,  0, 0,  0, 1
#define AMG_12plus12  8, 9,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_12plus13  9,10,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_12plus14 10,11,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_12plus15 11,12,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1

/* A=13 AMG_AplusB   nr,cr, nc,cc, no,co, n0,c0, nF,cF, ns,cs */
#define AMG_13plus0  13,14,  0, 0,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_13plus1  14,15,  0, 0,  0, 0,  0, 0,  0, 1,  1, 1
#define AMG_13plus2  15, 0,  0, 1,  0, 0,  0, 1,  1, 0,  1, 0
#define AMG_13plus3   0, 1,  1, 1,  0, 0,  1, 0,  0, 0,  0, 0
#define AMG_13plus4   1, 2,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_13plus5   2, 3,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_13plus6   3, 4,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_13plus7   4, 5,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_13plus8   5, 6,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_13plus9   6, 7,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_13plus10  7, 8,  1, 1,  1, 0,  0, 0,  0, 0,  0, 1
#define AMG_13plus11  8, 9,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_13plus12  9,10,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_13plus13 10,11,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_13plus14 11,12,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_13plus15 12,13,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1

/* A=14 AMG_AplusB   nr,cr, nc,cc, no,co, n0,c0, nF,cF, ns,cs */
#define AMG_14plus0  14,15,  0, 0,  0, 0,  0, 0,  0, 1,  1, 1
#define AMG_14plus1  15, 0,  0, 1,  0, 0,  0, 1,  1, 0,  1, 0
#define AMG_14plus2   0, 1,  1, 1,  0, 0,  1, 0,  0, 0,  0, 0
#define AMG_14plus3   1, 2,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_14plus4   2, 3,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_14plus5   3, 4,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_14plus6   4, 5,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_14plus7   5, 6,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_14plus8   6, 7,  1, 1,  1, 1,  0, 0,  0, 0,  0, 0
#define AMG_14plus9   7, 8,  1, 1,  1, 0,  0, 0,  0, 0,  0, 1
#define AMG_14plus10  8, 9,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_14plus11  9,10,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_14plus12 10,11,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_14plus13 11,12,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_14plus14 12,13,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_14plus15 13,14,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1

/* TODO: Table layouts for trade-off selection; then have deduplication measures for overlapping thingies like this one.
(Because AMG_15plusB is not just an adder table, it's a decrementer table too!)
#ifndef AMG_PP_ALU_TABLES_BASE16_INCR_INCLUDED */
/* A=15 AMG_AplusB   nr,cr, nc,cc, no,co, n0,c0, nF,cF, ns,cs */
#define AMG_15plus0  15, 0,  0, 1,  0, 0,  0, 1,  1, 0,  1, 0
#define AMG_15plus1   0, 1,  1, 1,  0, 0,  1, 0,  0, 0,  0, 0
#define AMG_15plus2   1, 2,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_15plus3   2, 3,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_15plus4   3, 4,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_15plus5   4, 5,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_15plus6   5, 6,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_15plus7   6, 7,  1, 1,  0, 0,  0, 0,  0, 0,  0, 0
#define AMG_15plus8   7, 8,  1, 1,  1, 0,  0, 0,  0, 0,  0, 1
#define AMG_15plus9   8, 9,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_15plus10  9,10,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_15plus11 10,11,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_15plus12 11,12,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_15plus13 12,13,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_15plus14 13,14,  1, 1,  0, 0,  0, 0,  0, 0,  1, 1
#define AMG_15plus15 14,15,  1, 1,  0, 0,  0, 0,  0, 1,  1, 1
/* #endif */


#define AMG_bop_init0(carry,ex_anum,ex_bnum,fn)                AMG_bop_init1(carry,ex_anum,ex_bnum,fn)
#define AMG_bop_init1(carry,asz,a0,a1,anum,bsz,b0,b1,bnum,fn)  fn##0(asz,carry,,a0,a1,b0,b1),anum(a0,a1),bnum(b0,b1),fn)
//#define AMG_bop_init1(carry,asz,a0,a1,anum,bsz,b0,b1,bnum,fn)  AMG_bop##asz(1,carry,,anum(a0,a1),bnum(b0,b1),fn)
/*
// The last couple cases (AMG_bop1 and AMG_bop0) are special, because
// they are called from `AMG_bop_init1` while `anum` and `bnum` are in
// states that don't yield the usual number of arguments.
*/
#define AMG_bop8( cont,carry,buffer,a0,a1,anum,b0,b1,bnum,fn) /*AMG_bop7(*/ fn##cont( 7,carry,buffer,a0,a1,b0,b1),anum,bnum,fn)
#define AMG_bop7( cont,carry,buffer,a0,a1,anum,b0,b1,bnum,fn) /*AMG_bop6(*/ fn##cont( 6,carry,buffer,a0,a1,b0,b1),anum,bnum,fn)
#define AMG_bop6( cont,carry,buffer,a0,a1,anum,b0,b1,bnum,fn) /*AMG_bop5(*/ fn##cont( 5,carry,buffer,a0,a1,b0,b1),anum,bnum,fn)
#define AMG_bop5( cont,carry,buffer,a0,a1,anum,b0,b1,bnum,fn) /*AMG_bop4(*/ fn##cont( 4,carry,buffer,a0,a1,b0,b1),anum,bnum,fn)
#define AMG_bop4( cont,carry,buffer,a0,a1,anum,b0,b1,bnum,fn) /*AMG_bop3(*/ fn##cont( 3,carry,buffer,a0,a1,b0,b1),anum,bnum,fn)
#define AMG_bop3( cont,carry,buffer,a0,a1,anum,b0,b1,bnum,fn) /*AMG_bop2(*/ fn##cont( 2,carry,buffer,a0,a1,b0,b1),anum,bnum,fn)
#define AMG_bop2( cont,carry,buffer,a0,a1,anum,b0,b1,bnum,fn) /*AMG_bop1(*/ fn##cont( 1,carry,buffer,a0,a1,b0,b1),anum,bnum,fn)
#define AMG_bop1( cont,carry,buffer,a0,a1,anum,b0,b1,bnum,fn)               fn##cont(11,carry,buffer,a0,a1,b0,b1),anum,bnum,fn)
#define AMG_bop11(cont,carry,buffer,a0,a1,anum,b0,b1,bnum,fn)               fn##cont(10,carry,buffer,a0,a1,b0,b1),anum,bnum,,,,,)
#define AMG_bop10(cont,carry,buffer,e0,e1,e2,  e3,e4,e5,  e6)
#define AMG_bop0( cont,carry,buffer,ex_anum,ex_bnum,fn)                     AMG_bop01(carry,ex_anum,ex_bnum,fn)
#define AMG_bop01(carry,a0,a1,ajunk,b0,b1,bjunk,fn)                         fn##1(00,carry,,a0,a1,b0,b1))
#define AMG_bop00(cont,carry,buffer)

#define AMG_bop_aborted(e0,e1,e2,e3,e4,e5,e6,e7)

#define AMG_bop(carry,anum,bnum,fn) AMG_bop##anum
#define amg_mybop(carry,anum,bnum)                             AMG_bop_init0(carry,AMG_igetsz anum,AMG_igetsz bnum,AMG_continue)
#define AMG_continue0(n,carry,buffer,aN,aM,bN,bM) AMG_bop##n(1,carry,buffer
#define AMG_continue1(n,carry,buffer,a0,a1,b0,b1) (a0 b0, a1 b1) AMG_bop##n(2,carry,buffer
#define AMG_continue2(n,carry,buffer,e0,e1,e2,e3) AMG_bop_aborted(

amg_mybop(0,(0,15,3),(0,1,3))
amg_mybop(0,(2,10,10)(2,2)(3,3),(2,8,8)(9,9)(1,1))
//AMG_bop3init0(0,(1,1,(2,2,(3,3))),(8,8,(9,9,(10,10))),AMG_continue)
#if 0
#define AMG_bop_init2(asz,bsz,c,a0,a1,anum2,a2,a3,anum4,b0,b1,bnum2,b2,b3,bnum4,fn) \
	AMG_bop##asz(c,a0,a1,a2,a3,anum4,AMG_iget4 anum2,b0,b1,b2,b3,bnum4,AMG_iget4 bnum2,fn)

#define AMG_bop_init1(c,asz,a0,a1,anum2,bsz,b0,b1,bnum2,fn) \
	AMG_bopi##asz(asz,bsz,c,a0,a1,anum2,AMG_iget2 anum2,b0,b1,bnum2,AMG_iget2 bnum2,fn))

#define AMG_bop_init0(c,ex_anum,ex_bnum,fn) \
	AMG_bop_init1(c,ex_anum,ex_bnum,fn)

#if 0
#define amg__bop_init4(asz,bsz,c,a0,a1,anum1,anum2,a2,anum3,b0,b1,bnum1,bnum2,b2,bnum3,fn,fnc) \
	amg__bop##asz(c,a0,a1,anum2,AMG_iget2(a1,anum2),b0,b1,bnum2,AMG_iget2(b1,bnum2),fn,fnc)

#define amg__bop_init3(asz,bsz,c,a0,a1,anum1,anum2,ex_anum2,b0,b1,bnum1,bnum2,ex_bnum2,fn,fnc) \
	amg__bop_init4(asz,bsz,c,a0,a1,anum1,anum2,ex_anum2,b0,b1,bnum1,bnum2,ex_bnum2,fn,fnc)
#endif

#endif


//#define AMG_xcat_op_result(c,a0,a1,b0,b1) c(a0 b0, a1 b1)
//#define AMG_xcat_op_carry(c,a0,a1,b0,b1)  a0##a1##x##b0##b1
#define AMG_xcat_ripple0(n,carry,buffer,a0,a1,b0,b1) AMG_bop##n(1,a0##a1##x##b0##b1,buffer
#define AMG_xcat_ripple1(n,carry,buffer,a0,a1,b0,b1) carry(a0 b0, a1 b1) AMG_bop##n(1,a0##a1##x##b0##b1,buffer
#define AMG_xcat_ripple2(n,carry,buffer,a0,a1,b0,b1) AMG_bop_aborted(
#define amg_xcat(anum,bnum) \
	AMG_bop_init0(0, AMG_igetsz anum, AMG_igetsz bnum, AMG_xcat_ripple)

#define num1 (1,1,2)(3,4)
#define num2 (1,4,6)(7,8)
amg_xcat(num1,num2)
amg_xcat((0,1,0), (0,8,0))
amg_xcat((0,1,1), (0,8,8))
amg_xcat((1,1,1)(2,0), (1,8,8)(9,0))
amg_xcat((1,1,1)(2,2), (1,8,8)(9,9))
amg_xcat((2,1,1)(2,2)(3,0), (2,8,8)(9,9)(10,0))
amg_xcat((2,1,1)(2,2)(3,3), (2,8,8)(9,9)(10,10))
amg_xcat((3,1,1)(2,2)(3,3)(4,0), (3,8,8)(9,9)(10,10)(11,0))
amg_xcat((3,1,1)(2,2)(3,3)(4,4), (3,8,8)(9,9)(10,10)(11,11))
amg_xcat((4,1,1)(2,2)(3,3)(4,4)(5,0), (4,8,8)(9,9)(10,10)(11,11)(12,0))
amg_xcat((4,1,1)(2,2)(3,3)(4,4)(5,5), (4,8,8)(9,9)(10,10)(11,11)(12,12))
amg_xcat((5,1,1)(2,2)(3,3)(4,4)(5,5)(6,0), (5,8,8)(9,9)(10,10)(11,11)(12,12)(13,0))
amg_xcat((5,1,1)(2,2)(3,3)(4,4)(5,5)(6,6), (5,8,8)(9,9)(10,10)(11,11)(12,12)(13,13))


//#define num1 (4,1)(2)(3)(4)
//#define num2 (4,5)(6)(7)(8)
//amg_xcat(num1,num2)
//amg_xcat((1,0), (1,8))
//amg_xcat((2,0)(1), (2,8)(9))
//amg_xcat((3,0)(1)(2), (3,8)(9)(10))
//amg_xcat((4,0)(1)(2)(3), (4,8)(9)(10)(11))
//amg_xcat((5,0)(1)(2)(3)(4), (5,8)(9)(10)(11)(12))
//amg_xcat((6,0)(1)(2)(3)(4)(5), (6,8)(9)(10)(11)(12)(13))
//amg_xcat((7,0)(1)(2)(3)(4)(5)(6), (7,8)(9)(10)(11)(12)(13)(14))
//amg_xcat((8,0)(1)(2)(3)(4)(5)(6)(7), (8,8)(9)(10)(11)(12)(13)(14)(15))


//#define num1 (4,1,(2,(3,(4,))))
//#define num2 (4,5,(6,(7,(8,))))
//amg_xcat((1,0,), (1,8,))
//amg_xcat((2,0,(1,)), (2,8,(9,)))
//amg_xcat((3,0,(1,(2,))), (3,8,(9,(10,))))
//amg_xcat(num1,num2)
//amg_xcat((4,0,(1,(2,(3,)))), (4,8,(9,(10,(11,)))))
//amg_xcat((5,0,(1,(2,(3,(4,))))), (5,8,(9,(10,(11,(12,))))))
//amg_xcat((6,0,(1,(2,(3,(4,(5,)))))), (6,8,(9,(10,(11,(12,(13,)))))))
//amg_xcat((7,0,(1,(2,(3,(4,(5,(6,))))))), (7,8,(9,(10,(11,(12,(13,(14,))))))))
//amg_xcat((8,0,(1,(2,(3,(4,(5,(6,(7,)))))))), (8,8,(9,(10,(11,(12,(13,(14,(15,)))))))))


#define AMG_dtornyp0  0,0
#define AMG_dtornyp1  1,0
#define AMG_dtornyp2  2,0
#define AMG_dtornyp3  3,0
#define AMG_dtornyp4  0,1
#define AMG_dtornyp5  1,1
#define AMG_dtornyp6  2,1
#define AMG_dtornyp7  3,1
#define AMG_dtornyp8  0,2
#define AMG_dtornyp9  1,2
#define AMG_dtornyp10 2,2
#define AMG_dtornyp11 3,2
#define AMG_dtornyp12 0,3
#define AMG_dtornyp13 1,3
#define AMG_dtornyp14 2,3
#define AMG_dtornyp15 3,3

#define AMG_dtonyp0  0,0
#define AMG_dtonyp1  0,1
#define AMG_dtonyp2  0,2
#define AMG_dtonyp3  0,3
#define AMG_dtonyp4  1,0
#define AMG_dtonyp5  1,1
#define AMG_dtonyp6  1,2
#define AMG_dtonyp7  1,3
#define AMG_dtonyp8  2,0
#define AMG_dtonyp9  2,1
#define AMG_dtonyp10 2,2
#define AMG_dtonyp11 2,3
#define AMG_dtonyp12 3,0
#define AMG_dtonyp13 3,1
#define AMG_dtonyp14 3,2
#define AMG_dtonyp15 3,3

#define AMG_nyptord00  0
#define AMG_nyptord10  1
#define AMG_nyptord20  2
#define AMG_nyptord30  3
#define AMG_nyptord01  4
#define AMG_nyptord11  5
#define AMG_nyptord21  6
#define AMG_nyptord31  7
#define AMG_nyptord02  8
#define AMG_nyptord12  9
#define AMG_nyptord22 10
#define AMG_nyptord32 11
#define AMG_nyptord03 12
#define AMG_nyptord13 13
#define AMG_nyptord23 14
#define AMG_nyptord33 15

#define AMG_nyptod00  0
#define AMG_nyptod01  1
#define AMG_nyptod02  2
#define AMG_nyptod03  3
#define AMG_nyptod10  4
#define AMG_nyptod11  5
#define AMG_nyptod12  6
#define AMG_nyptod13  7
#define AMG_nyptod20  8
#define AMG_nyptod21  9
#define AMG_nyptod22 10
#define AMG_nyptod23 11
#define AMG_nyptod30 12
#define AMG_nyptod31 13
#define AMG_nyptod32 14
#define AMG_nyptod33 15

/*
//
// Note that the overflow is SIGNED overflow.
// It is SET whenever the sign bit becomes set,
// or when there is carry-out.
// (If you need unsigned overflow, note
// that this is what the carry-out is.)
// Ex:
// H(4) + H(4) = H(8) // Overflow
// H(4) + H(3) = H(7) // No overflow
//
// For positive numbers, signed overflow is a growth condition/trigger.
// For negative numbers, signed overflow is a shrink condition/trigger.
// (In either case, only if it's the most-significant
// nybble of the entire number being added.)
// (Wait... neg numbers might use a different measure entirely.
// Maybe it's carry-out? Maybe it depends on both carry-out and s-overflow?)
//
// H(7) + H(F) = H(6)
// LHS is MSB && RHS is MSB: equivalent to a large positive number minus
//     a smaller number (plus a smaller negative number)
// (LHS is MSB && RHS not MSB) || (LHS not MSB && RHS is MSB):
//     Any growth/shrinking will be calculated later in the ripple.
//     Addition in two's complement is sign-agnostic, so we'll be fine,
//     because sign only matters for sign extension or shrinking,
//     which are things that can't happen now (later instead!).
// LHS not MSB && RHS not MSB: We're in the middle of both numbers.
//     Any growth/shrinking will be calculated later in the ripple.
//     This will also benefit from two's complement's sign agnostic nature.
//
// So we can tell that the only time we really need to worry about enlarge/shrink
// is when both operands are the most significant byte. At that point, if one
// number is negative and the other isn't, then the result is the difference
// of the two numbers.
*/
#if 0
/*
//     RHS has much higher magnitude.
//     Any growth/shrinking will be calculated later.
//     If RHS turns out to be positive, then it's two pos numbers added. Easy.
//     If RHS turns out to be negative, then two's complement will make
//         it reduce the magnitude of the negative number. Maybe not obvious,
//         but still nothing to worry about.
// LHS not MSB && RHS is MSB:
//     LHS has much higher magnitude.
//     Any growth/shrinking will be calculated later.
//     If LHS turns out to be negative, result is negative value with larger magnitude.
//     If LHS turns out to be positive,
//  -> Left side: Positive number grows. (put 00 byte at end)
//  -> Right side: Negative number shrinks.
//
//  ->
*/
#endif
#if 0
/*
// Columns in this table, left to right:
// 0: Addition result with no carry-in
// 1: Addition result WITH carry-in
// 2: Carry-out with no carry-in
// 3: Carry-out WITH carry-in
// 4: Overflow with no carry-in
// 5: Overflow WITH carry-in
// 6: Sign bit with no carry-in
// 7: Sign bit WITH carry-in
// 8: AllSign flag with no carry-in (All bits equal prior sign bit)
// 9: AllSign flag WITH carry-in    (ditto)
*/
#define /* 0 */ AMG_i2add00 0,1,0,0,0,0,0,0,1,0
#define /* 1 */ AMG_i2add01 1,2,0,0,0,1,0,0,0,0
#define /* 2 */ AMG_i2add02 2,3,0,0,1,1,0,1,0,0
#define /* 3 */ AMG_i2add03 3,0,0,1,1,1,1,0,0,1
#define /* 1 */ AMG_i2add10 1,2,0,0,0,1,0,0,0,0
#define /* 2 */ AMG_i2add11 2,3,0,0,1,1,0,1,0,0
#define /* 3 */ AMG_i2add12 3,0,0,1,1,1,1,0,0,1
#define /* 4 */ AMG_i2add13 0,1,1,1,1,1,0,0,1,0
#define /* 2 */ AMG_i2add20 2,3,0,0,1,1,0,1,0,0
#define /* 3 */ AMG_i2add21 3,0,0,1,1,1,1,0,0,1
#define /* 4 */ AMG_i2add22 0,1,1,1,1,1,0,0,1,0
#define /* 5 */ AMG_i2add23 1,2,1,1,1,1,0,0,0,0
#define /* 3 */ AMG_i2add30 3,0,0,1,1,1,1,0,0,1
#define /* 4 */ AMG_i2add31 0,1,1,1,1,1,0,0,1,0
#define /* 5 */ AMG_i2add32 1,2,1,1,1,1,0,0,0,0
#define /* 6 */ AMG_i2add33 2,3,1,1,1,1,0,1,0,0
#endif
/*
// Columns in this table, left to right:
// 0: Addition result with no carry-in
// 1: Addition result WITH carry-in
// 2: Carry-out with no carry-in
// 3: Carry-out WITH carry-in
// 4: Overflow with no carry-in
// 5: Overflow WITH carry-in
*/
#define /* 0 */ AMG_i2add00 0,1,0,0,0,0
#define /* 1 */ AMG_i2add01 1,2,0,0,0,1
#define /* 2 */ AMG_i2add02 2,3,0,0,1,1
#define /* 3 */ AMG_i2add03 3,0,0,1,1,1
#define /* 1 */ AMG_i2add10 1,2,0,0,0,1
#define /* 2 */ AMG_i2add11 2,3,0,0,1,1
#define /* 3 */ AMG_i2add12 3,0,0,1,1,1
#define /* 4 */ AMG_i2add13 0,1,1,1,1,1
#define /* 2 */ AMG_i2add20 2,3,0,0,1,1
#define /* 3 */ AMG_i2add21 3,0,0,1,1,1
#define /* 4 */ AMG_i2add22 0,1,1,1,1,1
#define /* 5 */ AMG_i2add23 1,2,1,1,1,1
#define /* 3 */ AMG_i2add30 3,0,0,1,1,1
#define /* 4 */ AMG_i2add31 0,1,1,1,1,1
#define /* 5 */ AMG_i2add32 1,2,1,1,1,1
#define /* 6 */ AMG_i2add33 2,3,1,1,1,1

/*
// Columns in this table, left to right:
// 0:  Addition result with no carry-in
// 1:  Addition result WITH carry-in
// 2:  Carry-out with no carry-in
// 3:  Carry-out WITH carry-in
// 4:  Overflow with no carry-in
// 5:  Overflow WITH carry-in
// 6:  Sign bit with no carry-in
// 7:  Sign bit WITH carry-in
// 8:  Zero flag with no carry-in (All bits 0)
// 9:  Zero flag WITH carry-in    (ditto)
// 10: Max flag with no carry-in  (All bits 1)
// 11: Max flag WITH carry-in     (ditto)
*/
#define /* 0 */ AMG_0add0   0, 1, 0,0,0,0,0,0,1,0,0,0
#define /* 1 */ AMG_0add1   1, 2, 0,0,0,0,0,0,0,0,0,0
#define /* 2 */ AMG_0add2   2, 3, 0,0,0,0,0,0,0,0,0,0
#define /* 3 */ AMG_0add3   3, 4, 0,0,0,0,0,0,0,0,0,0
#define /* 4 */ AMG_0add4   4, 5, 0,0,0,0,0,0,0,0,0,0
#define /* 5 */ AMG_0add5   5, 6, 0,0,0,0,0,0,0,0,0,0
#define /* 6 */ AMG_0add6   6, 7, 0,0,0,0,0,0,0,0,0,0
#define /* 7 */ AMG_0add7   7, 8, 0,0,0,1,0,1,0,0,0,0
#define /* 8 */ AMG_0add8   8, 9, 0,0,0,0,1,1,0,0,0,0
#define /* 9 */ AMG_0add9   9,10, 0,0,0,0,1,1,0,0,0,0
#define /* A */ AMG_0add10 10,11, 0,0,0,0,1,1,0,0,0,0
#define /* B */ AMG_0add11 11,12, 0,0,0,0,1,1,0,0,0,0
#define /* C */ AMG_0add12 12,13, 0,0,0,0,1,1,0,0,0,0
#define /* D */ AMG_0add13 13,14, 0,0,0,0,1,1,0,0,0,0
#define /* E */ AMG_0add14 14,15, 0,0,0,0,1,1,0,0,0,1
#define /* F */ AMG_0add15 15, 0, 0,1,0,1,1,0,0,1,1,0


#define AMG_i2add000 0
#define AMG_i2add001 1
#define AMG_i2add002 2
#define AMG_i2add003 3
#define AMG_i2add010 1
#define AMG_i2add011 2
#define AMG_i2add012 3
#define AMG_i2add013 0
#define AMG_i2add020 2
#define AMG_i2add021 3
#define AMG_i2add022 0
#define AMG_i2add023 1
#define AMG_i2add030 3
#define AMG_i2add031 0
#define AMG_i2add032 1
#define AMG_i2add033 2

#define AMG_i2add100 1
#define AMG_i2add101 2
#define AMG_i2add102 3
#define AMG_i2add103 0
#define AMG_i2add110 2
#define AMG_i2add111 3
#define AMG_i2add112 0
#define AMG_i2add113 1
#define AMG_i2add120 3
#define AMG_i2add121 0
#define AMG_i2add122 1
#define AMG_i2add123 2
#define AMG_i2add130 0
#define AMG_i2add131 1
#define AMG_i2add132 2
#define AMG_i2add133 3

#if 0
/* Ripple behavior
// 0 = unconditionally doesn't ripple
// 1 = conditionally ripples (ripple on carry-in or borrow-out)
// 2 = unconditionally ripples
*/
#define /* 0 */ AMG_i2addr000 0
#define /* 1 */ AMG_i2addr001 0
#define /* 2 */ AMG_i2addr002 0
#define /* 3 */ AMG_i2addr003 1
#define /* 1 */ AMG_i2addr010 0
#define /* 2 */ AMG_i2addr011 0
#define /* 3 */ AMG_i2addr012 1
#define /* 4 */ AMG_i2addr013 2
#define /* 2 */ AMG_i2addr020 0
#define /* 3 */ AMG_i2addr021 1
#define /* 4 */ AMG_i2addr022 2
#define /* 5 */ AMG_i2addr023 2
#define /* 3 */ AMG_i2addr030 1
#define /* 4 */ AMG_i2addr031 2
#define /* 5 */ AMG_i2addr032 2
#define /* 6 */ AMG_i2addr033 2

#define AMG_i2ripple0000 0,0,0
#define AMG_i2ripple0001 0,0,0
#define AMG_i2ripple0010 0,0,0
#define AMG_i2ripple0011 0,0,1
#define AMG_i2ripple0020 0,0,1
#define AMG_i2ripple0021 0,0,1
#define AMG_i2ripple0100 0,0,0
#define AMG_i2ripple0101 0,0,0
#define AMG_i2ripple0110 0,0,0
#define AMG_i2ripple0111 0,1,1
#define AMG_i2ripple0120 0,1,1
#define AMG_i2ripple0121 0,1,1
#define AMG_i2ripple0200 0,1,0
#define AMG_i2ripple0201 0,1,0
#define AMG_i2ripple0210 0,1,0
#define AMG_i2ripple0211 0,1,1
#define AMG_i2ripple0220 0,1,1
#define AMG_i2ripple0221 0,1,1

#define AMG_i2ripple1000 0,0,0
#define AMG_i2ripple1001 0,0,0
#define AMG_i2ripple1010 0,0,0
#define AMG_i2ripple1011 0,0,1
#define AMG_i2ripple1020 0,0,1
#define AMG_i2ripple1021 0,0,1
#define AMG_i2ripple1100 0,0,0
#define AMG_i2ripple1101 0,0,0
#define AMG_i2ripple1110 0,0,0
#define AMG_i2ripple1111 1,1,1
#define AMG_i2ripple1120 1,1,1
#define AMG_i2ripple1121 1,1,1
#define AMG_i2ripple1200 1,1,0
#define AMG_i2ripple1201 1,1,0
#define AMG_i2ripple1210 1,1,0
#define AMG_i2ripple1211 1,1,1
#define AMG_i2ripple1220 1,1,1
#define AMG_i2ripple1221 1,1,1

#define AMG_i2ripple2000 1,0,0
#define AMG_i2ripple2001 1,0,0
#define AMG_i2ripple2010 1,0,0
#define AMG_i2ripple2011 1,0,1
#define AMG_i2ripple2020 1,0,1
#define AMG_i2ripple2021 1,0,1
#define AMG_i2ripple2100 1,0,0
#define AMG_i2ripple2101 1,0,0
#define AMG_i2ripple2110 1,0,0
#define AMG_i2ripple2111 1,1,1
#define AMG_i2ripple2120 1,1,1
#define AMG_i2ripple2121 1,1,1
#define AMG_i2ripple2200 1,1,0
#define AMG_i2ripple2201 1,1,0
#define AMG_i2ripple2210 1,1,0
#define AMG_i2ripple2211 1,1,1
#define AMG_i2ripple2220 1,1,1
#define AMG_i2ripple2221 1,1,1
#endif

#if 0
#define /* 0 */ AMG_i2addc000 0
#define /* 1 */ AMG_i2addc001 0
#define /* 2 */ AMG_i2addc002 0
#define /* 3 */ AMG_i2addc003 0
#define /* 1 */ AMG_i2addc010 0
#define /* 2 */ AMG_i2addc011 0
#define /* 3 */ AMG_i2addc012 0
#define /* 4 */ AMG_i2addc013 1
#define /* 2 */ AMG_i2addc020 0
#define /* 3 */ AMG_i2addc021 0
#define /* 4 */ AMG_i2addc022 1
#define /* 5 */ AMG_i2addc023 1
#define /* 3 */ AMG_i2addc030 0
#define /* 4 */ AMG_i2addc031 1
#define /* 5 */ AMG_i2addc032 1
#define /* 6 */ AMG_i2addc033 1

#define /* 1 */ AMG_i2addc100 0
#define /* 2 */ AMG_i2addc101 0
#define /* 3 */ AMG_i2addc102 0
#define /* 4 */ AMG_i2addc103 1
#define /* 2 */ AMG_i2addc110 0
#define /* 3 */ AMG_i2addc111 0
#define /* 4 */ AMG_i2addc112 1
#define /* 5 */ AMG_i2addc113 1
#define /* 3 */ AMG_i2addc120 0
#define /* 4 */ AMG_i2addc121 1
#define /* 5 */ AMG_i2addc122 1
#define /* 6 */ AMG_i2addc123 1
#define /* 4 */ AMG_i2addc130 1
#define /* 5 */ AMG_i2addc131 1
#define /* 6 */ AMG_i2addc132 1
#define /* 7 */ AMG_i2addc133 1
#endif


#define AMG_i2incr00 0
#define AMG_i2incr01 1
#define AMG_i2incr02 2
#define AMG_i2incr03 3
#define AMG_i2incr10 1
#define AMG_i2incr11 2
#define AMG_i2incr12 3
#define AMG_i2incr13 0

#define AMG_i2incrc00 0
#define AMG_i2incrc01 0
#define AMG_i2incrc02 0
#define AMG_i2incrc03 0
#define AMG_i2incrc10 0
#define AMG_i2incrc11 0
#define AMG_i2incrc12 0
#define AMG_i2incrc13 1

#define AMG_i8add0c0(n,carry,buffer,aN,aM,bN,bM) AMG_bop##n(1,carry,buffer
#define AMG_i8add0c1(n,carry,buffer,a0,a1,b0,b1)  \
	AMG_i8add0(n,carry, \
		AMG_dtornyp##a0, AMG_dtornyp##a1,\
		AMG_dtornyp##b0, AMG_dtornyp##b1)

#define AMG_i8add0c2(n,carry,buffer,e0,e1,e2,e3) AMG_bop_aborted(

#define AMG_i8add0(n,c, a0,a1, b0,b1) \
	AMG_i8add4(n,AMG_i8add3_0##c,AMG_i8add2(c, a0,a1,b0,b1))
	//AMG_i8add2(n,c,a0,a1,b0,b1)

//#define AMG_i8add1(n,c, a0,a1, b0,b1) \
//	AMG_i8add4(n,AMG_i8add3_0##c,AMG_i8add2(c, a0,a1,b0,b1))

#define AMG_i8add2(c, \
	nypa0, nypa1, nypa2, nypa3, \
	nypb0, nypb1, nypb2, nypb3 \
) \
		(AMG_i2add##nypa0##nypb0)(AMG_i2add##nypa1##nypb1) \
		(AMG_i2add##nypa2##nypb2)(AMG_i2add##nypa3##nypb3)
//	AMG_i8add4(n,AMG_i8add3_0(c,nypa0,nypb0)(nypa1,nypb1)(nypa2,nypb2)(nypa3,nypb3))
/*	AMG_i8add3a(n,AMG_i2addc##c##nypa3##nypb3,\
		AMG_i2add0##nypa0##nypb0, \
		AMG_i2add0##nypa1##nypb1, \
		AMG_i2add0##nypa2##nypb2, \
		AMG_i2add0##nypa3##nypb3)
*/
#if 0
#define AMG_reify(id) id
#define AMG_i8add3_00(nypn,nypc,nc,cc,no,co) nypn, AMG_i8add3_1(nc,
#define AMG_i8add3_01(nypn,nypc,nc,cc,no,co) nypc, AMG_i8add3_1(cc,
#define AMG_i8add3_10(nypn,nypc,nc,cc,no,co) nypn, AMG_i8add3_2(nc,
#define AMG_i8add3_11(nypn,nypc,nc,cc,no,co) nypc, AMG_i8add3_2(cc,
#define AMG_i8add3_20(nypn,nypc,nc,cc,no,co) nypn, AMG_i8add3_3(nc,
#define AMG_i8add3_21(nypn,nypc,nc,cc,no,co) nypc, AMG_i8add3_3(cc,
#define AMG_i8add3_30(nypn,nypc,nc,cc,no,co) nypn, nc, no
#define AMG_i8add3_31(nypn,nypc,nc,cc,no,co) nypc, cc, co
#endif

#define AMG_i8add3_00(nypn,nypc,nc,cc,no,co) nypn, AMG_i8add3_1##nc
#define AMG_i8add3_01(nypn,nypc,nc,cc,no,co) nypc, AMG_i8add3_1##cc
#define AMG_i8add3_10(nypn,nypc,nc,cc,no,co) nypn, AMG_i8add3_2##nc
#define AMG_i8add3_11(nypn,nypc,nc,cc,no,co) nypc, AMG_i8add3_2##cc
#define AMG_i8add3_20(nypn,nypc,nc,cc,no,co) nypn, AMG_i8add3_3##nc
#define AMG_i8add3_21(nypn,nypc,nc,cc,no,co) nypc, AMG_i8add3_3##cc
#define AMG_i8add3_30(nypn,nypc,nc,cc,no,co) nypn, nc, no
#define AMG_i8add3_31(nypn,nypc,nc,cc,no,co) nypc, cc, co

#define AMG_i8add4(n,fn,expr)  AMG_i8add5(n,fn expr)
#define AMG_i8add5(n,expr)     AMG_i8add6(n,expr)
#define AMG_i8add6(n,nyp0,nyp1,nyp2,nyp3,c,o) \
	(AMG_nyptord##nyp0##nyp1,AMG_nyptord##nyp2##nyp3) \
	/*AMG_i8add_overflow##o(nyp0,nyp1,nyp2,nyp3)*/ \
	AMG_bop##n(c,c, /* TODO: pass output in buffer if possible sign extension */

/* The 4 cases of signed overflow:
// 00: This isn't the MSB (or the numbers being added are different widths),
//         and there is no signed overflow -> no growth
// 01: This isn't the MSB, and there is signed overflow -> no growth
// 02: This is the MSB, and there isn't signed overflow -> no growth
// 03: This is the MSB, and there is signed overflow -> growth
// TODO: SHRINKING (probably need encoding for overflow in other direction?)
*/
#define AMG_i8add_overflow00(nyp0,nyp1,nyp2,nyp3)
#define AMG_i8add_overflow01(nyp0,nyp1,nyp2,nyp3)
#define AMG_i8add_overflow10(nyp0,nyp1,nyp2,nyp3)
#define AMG_i8add_overflow11(nyp0,nyp1,nyp2,nyp3) \


//#define AMG_i8add3a(n,c, nyp0,nyp1,nyp2,nyp3) AMG_i8add3b(n,c, nyp0,nyp1,nyp2,nyp3)
//#define AMG_i8add3b(n,c, nyp0,nyp1,nyp3,nyp3) AMG_i8add4a(n,AMG_i2addc##c##nyp0
	//AMG_i2addc##c##nypa0##nypb0, AMG_i2add##c##nypa0##nypb0

#define AMG_i8add3_fn0(fn,c) fn##c
#define AMG_i8add3_fn(fn,c) AMG_i8add3_fn0(fn,c)
#if 0
// TODO: Don't forget to bit-reverse (whole-system) inputs! (and outputs)
#define AMG_i8add3_0(c,nypa0,nypb0) AMG_i2add##c##nypa0##nypb0,AMG_i8add3_fn(AMG_i8add3_1,AMG_i2addc##c##nypa0##nypb0)
#define AMG_i8add3_10(nypa1,nypb1)  AMG_i2add##0##nypa1##nypb1,AMG_i8add3_fn(AMG_i8add3_2,AMG_i2addc##0##nypa1##nypb1)
#define AMG_i8add3_11(nypa1,nypb1)  AMG_i2add##1##nypa1##nypb1,AMG_i8add3_fn(AMG_i8add3_2,AMG_i2addc##1##nypa1##nypb1)
#define AMG_i8add3_20(nypa2,nypb2)  AMG_i2add##0##nypa2##nypb2,AMG_i8add3_fn(AMG_i8add3_3,AMG_i2addc##0##nypa2##nypb2)
#define AMG_i8add3_21(nypa2,nypb2)  AMG_i2add##1##nypa2##nypb2,AMG_i8add3_fn(AMG_i8add3_3,AMG_i2addc##1##nypa2##nypb2)
#define AMG_i8add3_30(nypa3,nypb3)  AMG_i2add##0##nypa3##nypb3,AMG_i2addc##0##nypa3##nypb3
#define AMG_i8add3_31(nypa3,nypb3)  AMG_i2add##1##nypa3##nypb3,AMG_i2addc##1##nypa3##nypb3
#endif
/*
#define AMG_i8add3_0(c,nypa0,nypb0) AMG_i2add##c##nypa0##nypb0,AMG_i8add3_fn(AMG_i8add3_1,AMG_i2addc##c##nypa0##nypb0)
#define AMG_i8add3_10(nypa1,nypb1)  AMG_i2add##0##nypa1##nypb1,AMG_i8add3_fn(AMG_i8add3_2,AMG_i2addc##0##nypa1##nypb1)
#define AMG_i8add3_11(nypa1,nypb1)  AMG_i2add##1##nypa1##nypb1,AMG_i8add3_fn(AMG_i8add3_2,AMG_i2addc##1##nypa1##nypb1)
#define AMG_i8add3_20(nypa2,nypb2)  AMG_i2add##0##nypa2##nypb2,AMG_i8add3_fn(AMG_i8add3_3,AMG_i2addc##0##nypa2##nypb2)
#define AMG_i8add3_21(nypa2,nypb2)  AMG_i2add##1##nypa2##nypb2,AMG_i8add3_fn(AMG_i8add3_3,AMG_i2addc##1##nypa2##nypb2)
#define AMG_i8add3_30(nypa3,nypb3)  AMG_i2add##0##nypa3##nypb3,AMG_i2addc##0##nypa3##nypb3
#define AMG_i8add3_31(nypa3,nypb3)  AMG_i2add##1##nypa3##nypb3,AMG_i2addc##1##nypa3##nypb3
*/
//#define AMG_i8add3_0(nypa0,nypb0,c) AMG_i2add##c##nypa0##nypb0

#if 0
#define amg_eval(x) eval2(eval2(eval2(x)))
#define eval2(y)    eval3(eval3(eval3(y)))
#define eval3(z)    z
#define AMG_i8add2i(n,c, \
	nypa0, nypa1, nypa2, nypa3, \
	nypb0, nypb1, nypb2, nypb3 \
) \
	amg_eval(AMG_i8add2(n,c, \
		nypa0, nypa1, nypa2, nypa3, \
		nypb0, nypb1, nypb2, nypb3))))))))))
/*
#define AMG_i8add1(c, a0,a1, b0,b1, n) \
#a0 #a1 #b0 #b1 AMG_i8add2(c, \
		AMG_dtonyp##a0, AMG_dtonyp##a1, \
		AMG_dtonyp##b0, AMG_dtonyp##b1, \
		n
*/
#define AMG_i8add2(n,c, \
	nypa0, nypa1, nypa2, nypa3, \
	nypb0, nypb1, nypb2, nypb3 \
) \
		AMG_i8add3(nypa3, nypb3, \
		AMG_i8add3(nypa2, nypb2, \
		AMG_i8add3(nypa1, nypb1, \
		AMG_i8add3(nypa0, nypb0, c)

#define AMG_i8add3(nypa, nypb, c) \
	AMG_i2addc##c##nypa##nypb), AMG_i2add##c##nypa##nypb

#define AMG_i8add4(n, c, nyp3, nyp2, nyp1, nyp0) \
	(nyp0,nyp1,nyp2,nyp3) AMG_bop##n(c
#endif
#define amg_add(anum,bnum) AMG_bop_init0(0,AMG_igetsz anum,AMG_igetsz bnum,AMG_i8add0c)

/* TODO:
// Keep adding until we've reached the size of the smaller number.
// THEN.
// Incr-carry into the remaining digits of the larger number,
// then concatenate that number onto the end of our number.
// Be sure to grow-on-carry.
*/
amg_add((0,1,0), (0,8,0))
amg_add((0,1,1), (0,8,8))
amg_add((1,1,1)(2,0), (1,8,8)(9,0))
amg_add((1,1,1)(2,2), (1,8,8)(9,9))
amg_add((2,1,1)(2,2)(3,0), (2,8,8)(9,9)(10,0))
amg_add((2,1,1)(2,2)(3,3), (2,8,8)(9,9)(10,10))
amg_add((3,1,1)(2,2)(3,3)(4,0), (3,8,8)(9,9)(10,10)(11,0))
amg_add((3,1,1)(2,2)(3,3)(4,4), (3,8,8)(9,9)(10,10)(11,11))
amg_add((4,1,1)(2,2)(3,3)(4,4)(5,0), (4,8,8)(9,9)(10,10)(11,11)(12,0))
amg_add((4,1,1)(2,2)(3,3)(4,4)(5,5), (4,8,8)(9,9)(10,10)(11,11)(12,12))
amg_add((5,1,1)(2,2)(3,3)(4,4)(5,5)(6,0), (5,8,8)(9,9)(10,10)(11,11)(12,12)(13,0))
amg_add((5,1,1)(2,2)(3,3)(4,4)(5,5)(6,6), (5,8,8)(9,9)(10,10)(11,11)(12,12)(13,13))

amg_add((0,1,3),(0,15,3))
amg_add((2,1,1)(2,2)(3,3),(2,8,8)(9,9)(10,10))
amg_add((2,1,1)(2,7)(3,3),(2,8,15)(9,9)(10,10))
amg_add((2,1,1)(2,7)(3,3),(2,8,15)(9,9)(10,13))

/* TODO: How to store sign on variable-width integers?
// TODO: How to (quickly) compute sign if it's twos-comp? (The sign will be on the _far_ end. Ugh.)
//
// Thoughts so far:
// * Integers are still ambiguously signed, but we maintain metadata for the signed case.
// * Have a single-byte-representation (SBR) for integers 0x00-0xFF; signage is twos-comp.
// * For integers longer than 1 byte, the 2nd tuple is a 3-tuple, with the 1st element being flags.
// * The flags will, for now, just be a sign flag:
//   * 0: Sign bit is set
//   * 1: Sign bit is clear
//   * (I initially thought, "oh, make it ternary, with a 0 value". No.
//       Zero is within the domain of the SBR, so wide integers will NEVER be 0.)
// * Operations that would change the sign bit will instead grow the result.
//    * H(41) + H(41) = H(00 82); the 00 is necessary to signify positivity
//    * H(00) - H(41) = H(FF BF); the FF is necessary to signify negativity
//    * H(00) + H(FF BF) = H(FF BF);
//    * H(BF) is invalid
//    * H(82) is also invalid
//    * H(00) through H(7F) are the valid SBR values. (Essentially, it is a 7-bit positive integer.)
//    * -1 is represented as H(FF FE)
//    * TODO: It might be possible to allow negative SBR values
//            in the H(80) through H(FF) range, but could be tricky to _shrink_.
//            (Or, if we treat it as the MSB, it's actually easy?)
//    * The most-sig byte will always be:
//      * H(00) through H(7F) for positive integers
//      * H(80) through H(FF) for negative integers
// * Advantages:
//     * Fast sign detection.
//     * Good for greater-than/less-than.
//     * Good for multiply/divide ops.
//     * If we disambiguate sign entirely, then we don't need signed-vs-unsigned ops (multiply, divide, cmp, etc)
//     * Then again, we should still have unsigned ops. And possibly bounded ops too.
//     * Signed ops: amg_cmp, amg_mul, amg_div
//     * Unsigned ops: amg_ucmp, amg_umul, amg_udiv
//     * Bounded ops amg_add16, amg_add32, amg_add64, amg_imul32 (or amg_mul32?), amg_umul32
// * Possible disadvantages:
//   * Clumsy entry code (Is it SBR? How wide is this tuple? etc)
//   * Writing the flag down at the end of an op could be complicated.
//     * Probably won't happen much for add/subtract/multiply/divide?
//     * Might be bad for logical ops.
//     * Add/sub: sign flip can happen, but rare
//     * Mul/div: sign flip known immediately by sign of operands
//         (And these will remove the sign, do the op, then use XOR of sign bits as resulting sign.)
//     * AND/OR/XOR: Potential PITA. Then again, we can know it a-prior from the sign bits/flags, right?
//         BUT. Sign changes can happen a lot, and the writing might be expansive.
//         (Perhaps disproportionately so for things like 24-bit and 32-bit integers.)
//     * Shl/shr: won't change sign. (What about SAR? (Or USHR and SHR) (Hmmm, arithmetic shift might be default! That's not bad tho.)
//     * CMPL (complement): Always changes sign
//
// TODO: Fixed point rep? Ever needed? (so useful in normal programming, but in macros? lol)
*/
