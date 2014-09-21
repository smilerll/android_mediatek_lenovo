/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

#ifndef TRUSTZONE_H
#define TRUSTZONE_H

#include "typedefs.h"

#define MOD "[TRUSTZONE]"
/* TEE magic */
#define TEE_ARGUMENT_MAGIC              (0x4B54444DU)
/* TEE version */
#define TEE_ARGUMENT_VERSION            (0x00010000U)

typedef struct {
    unsigned int magic;           // Magic number
    unsigned int version;         // version
    unsigned int NWEntry;         // NW Entry point after t-base
    unsigned int NWBootArgs;      // NW boot args (propagated by t-base in r4 before jump)
    unsigned int NWBootArgsSize;  // NW boot args size (propagated by t-base in r5 before jump)
    unsigned int dRamBase;        // NonSecure DRAM start address
    unsigned int dRamSize;        // NonSecure DRAM size
    unsigned int secDRamBase;     // Secure DRAM start address
    unsigned int secDRamSize;     // Secure DRAM size
    unsigned int sRamBase;        // NonSecure Scratch RAM start address
    unsigned int sRamSize;        // NonSecure Scratch RAM size
    unsigned int secSRamBase;     // Secure Scratch RAM start address
    unsigned int secSRamSize;     // Secure Scratch RAM size
    unsigned int log_port;        // uart base address for logging
    unsigned int log_baudrate;    // uart baud rate
    unsigned int hwuid[4];        // HW Unique id for t-base used    
} tee_arg_t;

/**************************************************************************
 * EXPORTED FUNCTIONS
 **************************************************************************/
extern void tee_set_secmem_size(u32 size);
extern void tee_get_secmem_size(u32 *size);
extern void tee_set_entry(u32 addr);
extern void tee_set_hwuid(u8 *id, u32 size);
extern int  tee_verify_image(u32 *addr, u32 size);
extern void tee_jump(u32 addr, u32 arg1, u32 arg2);

#endif /* TRUSTZONE_H */

