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
 * @file	analog_reg.h
 *
 * @brief	This is the header file for B91
 *
 * @author	Driver Group
 *
 *******************************************************************************************************/
#ifndef ANALOG_REG_H
#define ANALOG_REG_H
#include "../sys.h"
/*******************************      alg  registers: 140180      ******************************/
#define ALG_BASE_ADDR			   0x140180
#define reg_ana_addr			REG_ADDR8(ALG_BASE_ADDR)
#define reg_ana_ctrl			REG_ADDR8(ALG_BASE_ADDR+0x02)
enum
{
	//FLD_ANA_TX_EN         = BIT(0),
	FLD_ANA_RX_EN         = BIT(1),
	FLD_ANA_MASKX_TX_DONE = BIT(2),
	FLD_ANA_MASKX_RX_DONE = BIT(3),
	FLD_ANA_CONTIU_ACC    = BIT(4),
	FLD_ANA_RW            = BIT(5),   /**< 1:write,0:read */
	FLD_ANA_CYC           = BIT(6),
	FLD_ANA_BUSY          = BIT(7),
};
#define reg_ana_len             REG_ADDR8(ALG_BASE_ADDR+0x03)
#define reg_ana_data(n)			REG_ADDR8(ALG_BASE_ADDR+0x04+(n))
#define reg_ana_addr_data16		REG_ADDR16(ALG_BASE_ADDR+0x04)
#define reg_ana_addr_data32		REG_ADDR32(ALG_BASE_ADDR+0x04)

#define reg_ana_sta             REG_ADDR8(ALG_BASE_ADDR+0x09)
enum
{
	FLD_ANA_RX_DONE    = BIT(7),
};
#define reg_ana_irq_sta         REG_ADDR8(ALG_BASE_ADDR+0x0a)
enum
{
	FLD_ANA_TXBUFF_IRQ    = BIT(0),
	FLD_ANA_RXBUFF_IRQ    = BIT(1),
};
#define reg_ana_dma_ctl         REG_ADDR8(ALG_BASE_ADDR+0x0b)
enum
{
	FLD_ANA_CYC1           = BIT(0),
	FLD_ANA_DMA_EN         = BIT(1),

};

#endif
