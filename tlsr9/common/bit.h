/*
 * Copyright (c) 2019, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of TELINK nor the names of its contributors may be used
 *    to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/********************************************************************************************************
 * @file	bit.h
 *
 * @brief	This is the header file for B91
 *
 * @author	Driver Group
 *
 *******************************************************************************************************/
#ifndef BIT_H_
#define BIT_H_

#define BIT(n)                  		( 1<<(n))
#define BIT_MASK_LEN(len)       		(BIT(len)-1)
#define BIT_RNG(s, e)  					(BIT_MASK_LEN((e)-(s)+1) << (s))

#define BM_CLR_MASK_V(x, mask)    ( (x) & ~(mask) )


#define BM_SET(x, mask)         ( (x) |= (mask) )
#define BM_CLR(x, mask)       	( (x) &= ~(mask) )
#define BM_IS_SET(x, mask)   	( (x) & (mask) )
#define BM_IS_CLR(x, mask)   	( (~x) & (mask) )
#define BM_FLIP(x, mask)      	( (x) ^=  (mask) )

/**
 *  define Reg operations
 */

// Return the bit index of the lowest 1 in y.   ex:  0b00110111000  --> 3
#define BIT_LOW_BIT(y)  (((y) & BIT(0))?0:(((y) & BIT(1))?1:(((y) & BIT(2))?2:(((y) & BIT(3))?3:			\
						(((y) & BIT(4))?4:(((y) & BIT(5))?5:(((y) & BIT(6))?6:(((y) & BIT(7))?7:				\
						(((y) & BIT(8))?8:(((y) & BIT(9))?9:(((y) & BIT(10))?10:(((y) & BIT(11))?11:			\
						(((y) & BIT(12))?12:(((y) & BIT(13))?13:(((y) & BIT(14))?14:(((y) & BIT(15))?15:		\
						(((y) & BIT(16))?16:(((y) & BIT(17))?17:(((y) & BIT(18))?18:(((y) & BIT(19))?19:		\
						(((y) & BIT(20))?20:(((y) & BIT(21))?21:(((y) & BIT(22))?22:(((y) & BIT(23))?23:		\
						(((y) & BIT(24))?24:(((y) & BIT(25))?25:(((y) & BIT(26))?26:(((y) & BIT(27))?27:		\
						(((y) & BIT(28))?28:(((y) & BIT(29))?29:(((y) & BIT(30))?30:(((y) & BIT(31))?31:32		\
						))))))))))))))))))))))))))))))))

// Return the bit index of the highest 1 in (y).   ex:  0b00110111000  --> 8
#define BIT_HIGH_BIT(y)  (((y) & BIT(31))?31:(((y) & BIT(30))?30:(((y) & BIT(29))?29:(((y) & BIT(28))?28:	\
						(((y) & BIT(27))?27:(((y) & BIT(26))?26:(((y) & BIT(25))?25:(((y) & BIT(24))?24:		\
						(((y) & BIT(23))?23:(((y) & BIT(22))?22:(((y) & BIT(21))?21:(((y) & BIT(20))?20:		\
						(((y) & BIT(19))?19:(((y) & BIT(18))?18:(((y) & BIT(17))?17:(((y) & BIT(16))?16:		\
						(((y) & BIT(15))?15:(((y) & BIT(14))?14:(((y) & BIT(13))?13:(((y) & BIT(12))?12:		\
						(((y) & BIT(11))?11:(((y) & BIT(10))?10:(((y) & BIT(9))?9:(((y) & BIT(8))?8:			\
						(((y) & BIT(7))?7:(((y) & BIT(6))?6:(((y) & BIT(5))?5:(((y) & BIT(4))?4:				\
						(((y) & BIT(3))?3:(((y) & BIT(2))?2:(((y) & BIT(1))?1:(((y) & BIT(0))?0:32				\
						))))))))))))))))))))))))))))))))

#define COUNT_ARGS_IMPL2(_1, _2, _3, _4, _5, _6, _7, _8 , _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, N, ...) N
#define COUNT_ARGS_IMPL(args)   COUNT_ARGS_IMPL2 args
#define COUNT_ARGS(...)    		COUNT_ARGS_IMPL((__VA_ARGS__, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))

#define MACRO_CHOOSE_HELPER2(base, count) 	base##count
#define MACRO_CHOOSE_HELPER1(base, count) 	MACRO_CHOOSE_HELPER2(base, count)
#define MACRO_CHOOSE_HELPER(base, count) 	MACRO_CHOOSE_HELPER1(base, count)

#define MACRO_GLUE(x, y) x y
#define VARARG(base, ...)					MACRO_GLUE(MACRO_CHOOSE_HELPER(base, COUNT_ARGS(__VA_ARGS__)),(__VA_ARGS__))

#define MV(m, v)											(((v) << BIT_LOW_BIT(m)) & (m))

// warning MASK_VALn  are internal used macro, please use MASK_VAL instead
#define MASK_VAL2(m, v)    									(MV(m,v))
#define MASK_VAL4(m1,v1,m2,v2)    							(MV(m1,v1)|MV(m2,v2))
#define MASK_VAL6(m1,v1,m2,v2,m3,v3)    					(MV(m1,v1)|MV(m2,v2)|MV(m3,v3))
#define MASK_VAL8(m1,v1,m2,v2,m3,v3,m4,v4)    				(MV(m1,v1)|MV(m2,v2)|MV(m3,v3)|MV(m4,v4))
#define MASK_VAL10(m1,v1,m2,v2,m3,v3,m4,v4,m5,v5)    		(MV(m1,v1)|MV(m2,v2)|MV(m3,v3)|MV(m4,v4)|MV(m5,v5))
#define MASK_VAL12(m1,v1,m2,v2,m3,v3,m4,v4,m5,v5,m6,v6)    	(MV(m1,v1)|MV(m2,v2)|MV(m3,v3)|MV(m4,v4)|MV(m5,v5)|MV(m6,v6))
#define MASK_VAL14(m1,v1,m2,v2,m3,v3,m4,v4,m5,v5,m6,v6,m7,v7) (MV(m1,v1)|MV(m2,v2)|MV(m3,v3)|MV(m4,v4)|MV(m5,v5)|MV(m6,v6)|MV(m7,v7))
#define MASK_VAL16(m1,v1,m2,v2,m3,v3,m4,v4,m5,v5,m6,v6,m7,v7,m8,v8) (MV(m1,v1)|MV(m2,v2)|MV(m3,v3)|MV(m4,v4)|MV(m5,v5)|MV(m6,v6)|MV(m7,v7)|MV(m8,v8))

#define MASK_VAL(...) 				VARARG(MASK_VAL, __VA_ARGS__)


#endif
