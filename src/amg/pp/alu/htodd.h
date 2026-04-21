#ifndef AMG__PP_ALU_HTODD_INCLUDED
#define AMG__PP_ALU_HTODD_INCLUDED

#ifndef AMG_PP_ALU_HTODD_H
#define AMG_PP_ALU_HTODD_H "amg/pp/alu/htodd.h"
#endif

#ifndef AMG_PP_ALU_HTODD_OCTETS_H
#define AMG_PP_ALU_HTODD_OCTETS_H "amg/pp/alu/htodd_octets.h"
#endif

#define amg_i4h1_0 0
#define amg_i4h1_1 1
#define amg_i4h1_2 2
#define amg_i4h1_3 3
#define amg_i4h1_4 4
#define amg_i4h1_5 5
#define amg_i4h1_6 6
#define amg_i4h1_7 7
#define amg_i4h1_8 8
#define amg_i4h1_9 9

#define amg_i4h1_A 10
#define amg_i4h1_B 11
#define amg_i4h1_C 12
#define amg_i4h1_D 13
#define amg_i4h1_E 14
#define amg_i4h1_F 15
#define amg_i4h1_G 16
#define amg_i4h1_H 17
#define amg_i4h1_I 18
#define amg_i4h1_J 19
#define amg_i4h1_K 20
#define amg_i4h1_L 21
#define amg_i4h1_M 22
#define amg_i4h1_N 23
#define amg_i4h1_O 24
#define amg_i4h1_P 25
#define amg_i4h1_Q 26
#define amg_i4h1_R 27
#define amg_i4h1_S 28
#define amg_i4h1_T 29
#define amg_i4h1_U 30
#define amg_i4h1_V 31
#define amg_i4h1_W 32
#define amg_i4h1_X 33
#define amg_i4h1_Y 34
#define amg_i4h1_Z 35

#define amg_i4h1_a 10
#define amg_i4h1_b 11
#define amg_i4h1_c 12
#define amg_i4h1_d 13
#define amg_i4h1_e 14
#define amg_i4h1_f 15
#define amg_i4h1_g 16
#define amg_i4h1_h 17
#define amg_i4h1_i 18
#define amg_i4h1_j 19
#define amg_i4h1_k 20
#define amg_i4h1_l 21
#define amg_i4h1_m 22
#define amg_i4h1_n 23
#define amg_i4h1_o 24
#define amg_i4h1_p 25
#define amg_i4h1_q 26
#define amg_i4h1_r 27
#define amg_i4h1_s 28
#define amg_i4h1_t 29
#define amg_i4h1_u 30
#define amg_i4h1_v 31
#define amg_i4h1_w 32
#define amg_i4h1_x 33
#define amg_i4h1_y 34
#define amg_i4h1_z 35

#define amg_i4h1_10 10
#define amg_i4h1_11 11
#define amg_i4h1_12 12
#define amg_i4h1_13 13
#define amg_i4h1_14 14
#define amg_i4h1_15 15
#define amg_i4h1_16 16
#define amg_i4h1_17 17
#define amg_i4h1_18 18
#define amg_i4h1_19 19
#define amg_i4h1_20 20
#define amg_i4h1_21 21
#define amg_i4h1_22 22
#define amg_i4h1_23 23
#define amg_i4h1_24 24
#define amg_i4h1_25 25
#define amg_i4h1_26 26
#define amg_i4h1_27 27
#define amg_i4h1_28 28
#define amg_i4h1_29 29
#define amg_i4h1_30 30
#define amg_i4h1_31 31
#define amg_i4h1_32 32
#define amg_i4h1_33 33
#define amg_i4h1_34 34
#define amg_i4h1_35 35

// Disable-able because it adds a lot of macro definitions.
#ifndef  AMG_PP_HEX_OCTETS_DISABLED
#ifndef  AMG__PP_ALU_HTODD_OCTETS_INCLUDED
#include AMG_PP_ALU_HTODD_OCTETS_H
#endif
#endif

/** Constructs a 4-bit integer (as a 1-tuple) from a hexadecimal digit. */
#define amg_i4(h1)    (amg_i4h1_##h1)

/** Constructs an 8-bit integer (as a 2-tuple) from 2 hexadecimal digits. */
#define amg_i8(h2,h1) (amg_i4h1_##h2,amg_i4h1_##h1)

/** Constructs a 12-bit integer (as a 3-tuple) from 3 hexadecimal digits. */
#define amg_i12(h3,h2,h1) (amg_i4h1_##h3,amg_i4h1_##h2,amg_i4h1_##h1)

/** Constructs a 16-bit integer (as a 4-tuple) from 4 hexadecimal digits. */
#define amg_i16(h4,h3,h2,h1) (amg_i4h1_##h4,amg_i4h1_##h3,amg_i4h1_##h2,amg_i4h1_##h1)

#endif
