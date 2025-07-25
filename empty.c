/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "task.h"
#include "ti_msp_dl_config.h"


int main(void)
{
    TASK_INIT();

    while (1) 
    {
        TASK_LOOP(); 
    }
    
}

// void NMI_Handler(void)
// {
//      __BKPT();
// }

// void HardFault_Handler(void)
// { 
// #define TASK_STACK_SIZE 1024
// }

// void SVC_Handler(void)
// {
//     __BKPT();
// }

// void PendSV_Handler(void)
// {
//     __BKPT();
// }

// void SysTick_Handler(void)
// {
//     __BKPT();
// }

// void GROUP0_IRQHandler(void)
// {
//     __BKPT();
// }


// void TIMG8_IRQHandler(void)
// {
//     __BKPT();
// }

// void UART3_IRQHandler(void)
// {
//     __BKPT();
// }

// void ADC0_IRQHandler(void)
// {
//     __BKPT();
// }

// void ADC1_IRQHandler(void)
// {
//     __BKPT();
// }

// void CANFD0_IRQHandler(void)
// {
//     __BKPT();
// }

// void DAC0_IRQHandler(void)
// {
//     __BKPT();
// }

// void SPI0_IRQHandler(void)
// {
//     __BKPT();
// }

// void SPI1_IRQHandler(void)
// {
//     __BKPT();
// }



// void UART2_IRQHandler(void)
// {
//     __BKPT();
// }



// void TIMG6_IRQHandler(void)
// {
//     __BKPT();
// }

// void TIMA0_IRQHandler(void)
// {
//     __BKPT();
// }

// void TIMG7_IRQHandler(void)
// {
//     __BKPT();
// }

// void TIMG12_IRQHandler(void)
// {
//     __BKPT();
// }

// void I2C0_IRQHandler(void)
// {
//     __BKPT();
// }

// void I2C1_IRQHandler(void)
// {
//     __BKPT();
// }

// void AES_IRQHandler(void)
// {
//     __BKPT();
// }

// void RTC_IRQHandler(void)
// {
//     __BKPT();
// }

// void DMA_IRQHandler(void)
// {
//     __BKPT();
// }

