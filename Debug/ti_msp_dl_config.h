/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
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

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3505

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)


#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_MOTOR */
#define PWM_MOTOR_INST                                                     TIMA0
#define PWM_MOTOR_INST_IRQHandler                               TIMA0_IRQHandler
#define PWM_MOTOR_INST_INT_IRQN                                 (TIMA0_INT_IRQn)
#define PWM_MOTOR_INST_CLK_FREQ                                         32000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_MOTOR_C0_PORT                                             GPIOB
#define GPIO_PWM_MOTOR_C0_PIN                                      DL_GPIO_PIN_8
#define GPIO_PWM_MOTOR_C0_IOMUX                                  (IOMUX_PINCM25)
#define GPIO_PWM_MOTOR_C0_IOMUX_FUNC                 IOMUX_PINCM25_PF_TIMA0_CCP0
#define GPIO_PWM_MOTOR_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_MOTOR_C1_PORT                                             GPIOA
#define GPIO_PWM_MOTOR_C1_PIN                                     DL_GPIO_PIN_22
#define GPIO_PWM_MOTOR_C1_IOMUX                                  (IOMUX_PINCM47)
#define GPIO_PWM_MOTOR_C1_IOMUX_FUNC                 IOMUX_PINCM47_PF_TIMA0_CCP1
#define GPIO_PWM_MOTOR_C1_IDX                                DL_TIMER_CC_1_INDEX
/* GPIO defines for channel 2 */
#define GPIO_PWM_MOTOR_C2_PORT                                             GPIOB
#define GPIO_PWM_MOTOR_C2_PIN                                      DL_GPIO_PIN_0
#define GPIO_PWM_MOTOR_C2_IOMUX                                  (IOMUX_PINCM12)
#define GPIO_PWM_MOTOR_C2_IOMUX_FUNC                 IOMUX_PINCM12_PF_TIMA0_CCP2
#define GPIO_PWM_MOTOR_C2_IDX                                DL_TIMER_CC_2_INDEX
/* GPIO defines for channel 3 */
#define GPIO_PWM_MOTOR_C3_PORT                                             GPIOB
#define GPIO_PWM_MOTOR_C3_PIN                                      DL_GPIO_PIN_2
#define GPIO_PWM_MOTOR_C3_IOMUX                                  (IOMUX_PINCM15)
#define GPIO_PWM_MOTOR_C3_IOMUX_FUNC                 IOMUX_PINCM15_PF_TIMA0_CCP3
#define GPIO_PWM_MOTOR_C3_IDX                                DL_TIMER_CC_3_INDEX



/* Defines for TIMER_MS_SYS */
#define TIMER_MS_SYS_INST                                                (TIMG0)
#define TIMER_MS_SYS_INST_IRQHandler                            TIMG0_IRQHandler
#define TIMER_MS_SYS_INST_INT_IRQN                              (TIMG0_INT_IRQn)
#define TIMER_MS_SYS_INST_LOAD_VALUE                                    (31999U)



/* Defines for UART_OPENMV */
#define UART_OPENMV_INST                                                   UART1
#define UART_OPENMV_INST_FREQUENCY                                      32000000
#define UART_OPENMV_INST_IRQHandler                             UART1_IRQHandler
#define UART_OPENMV_INST_INT_IRQN                                 UART1_INT_IRQn
#define GPIO_UART_OPENMV_RX_PORT                                           GPIOB
#define GPIO_UART_OPENMV_TX_PORT                                           GPIOB
#define GPIO_UART_OPENMV_RX_PIN                                    DL_GPIO_PIN_7
#define GPIO_UART_OPENMV_TX_PIN                                    DL_GPIO_PIN_6
#define GPIO_UART_OPENMV_IOMUX_RX                                (IOMUX_PINCM24)
#define GPIO_UART_OPENMV_IOMUX_TX                                (IOMUX_PINCM23)
#define GPIO_UART_OPENMV_IOMUX_RX_FUNC                 IOMUX_PINCM24_PF_UART1_RX
#define GPIO_UART_OPENMV_IOMUX_TX_FUNC                 IOMUX_PINCM23_PF_UART1_TX
#define UART_OPENMV_BAUD_RATE                                           (115200)
#define UART_OPENMV_IBRD_32_MHZ_115200_BAUD                                 (17)
#define UART_OPENMV_FBRD_32_MHZ_115200_BAUD                                 (23)
/* Defines for UART_WIT */
#define UART_WIT_INST                                                      UART0
#define UART_WIT_INST_FREQUENCY                                         32000000
#define UART_WIT_INST_IRQHandler                                UART0_IRQHandler
#define UART_WIT_INST_INT_IRQN                                    UART0_INT_IRQn
#define GPIO_UART_WIT_RX_PORT                                              GPIOA
#define GPIO_UART_WIT_RX_PIN                                       DL_GPIO_PIN_1
#define GPIO_UART_WIT_IOMUX_RX                                    (IOMUX_PINCM2)
#define GPIO_UART_WIT_IOMUX_RX_FUNC                     IOMUX_PINCM2_PF_UART0_RX
#define UART_WIT_BAUD_RATE                                              (115200)
#define UART_WIT_IBRD_32_MHZ_115200_BAUD                                    (17)
#define UART_WIT_FBRD_32_MHZ_115200_BAUD                                    (23)




/* Defines for SPI_IMU660RB */
#define SPI_IMU660RB_INST                                                  SPI0
#define SPI_IMU660RB_INST_IRQHandler                            SPI0_IRQHandler
#define SPI_IMU660RB_INST_INT_IRQN                                SPI0_INT_IRQn
#define GPIO_SPI_IMU660RB_PICO_PORT                                       GPIOA
#define GPIO_SPI_IMU660RB_PICO_PIN                                DL_GPIO_PIN_5
#define GPIO_SPI_IMU660RB_IOMUX_PICO                            (IOMUX_PINCM10)
#define GPIO_SPI_IMU660RB_IOMUX_PICO_FUNC            IOMUX_PINCM10_PF_SPI0_PICO
#define GPIO_SPI_IMU660RB_POCI_PORT                                       GPIOA
#define GPIO_SPI_IMU660RB_POCI_PIN                               DL_GPIO_PIN_10
#define GPIO_SPI_IMU660RB_IOMUX_POCI                            (IOMUX_PINCM21)
#define GPIO_SPI_IMU660RB_IOMUX_POCI_FUNC            IOMUX_PINCM21_PF_SPI0_POCI
/* GPIO configuration for SPI_IMU660RB */
#define GPIO_SPI_IMU660RB_SCLK_PORT                                       GPIOA
#define GPIO_SPI_IMU660RB_SCLK_PIN                               DL_GPIO_PIN_11
#define GPIO_SPI_IMU660RB_IOMUX_SCLK                            (IOMUX_PINCM22)
#define GPIO_SPI_IMU660RB_IOMUX_SCLK_FUNC            IOMUX_PINCM22_PF_SPI0_SCLK



/* Defines for DMA_K230 */
#define DMA_K230_CHAN_ID                                                     (1)
#define UART_OPENMV_INST_DMA_TRIGGER                         (DMA_UART1_RX_TRIG)
/* Defines for DMA_WIT */
#define DMA_WIT_CHAN_ID                                                      (0)
#define UART_WIT_INST_DMA_TRIGGER                            (DMA_UART0_RX_TRIG)


/* Port definition for Pin Group GPIO_BEEP */
#define GPIO_BEEP_PORT                                                   (GPIOB)

/* Defines for beep: GPIOB.20 with pinCMx 48 on package pin 19 */
#define GPIO_BEEP_beep_PIN                                      (DL_GPIO_PIN_20)
#define GPIO_BEEP_beep_IOMUX                                     (IOMUX_PINCM48)
/* Defines for PIN_FL1: GPIOA.26 with pinCMx 59 on package pin 30 */
#define GPIO_MOTOR_PIN_FL1_PORT                                          (GPIOA)
#define GPIO_MOTOR_PIN_FL1_PIN                                  (DL_GPIO_PIN_26)
#define GPIO_MOTOR_PIN_FL1_IOMUX                                 (IOMUX_PINCM59)
/* Defines for PIN_FL2: GPIOB.24 with pinCMx 52 on package pin 23 */
#define GPIO_MOTOR_PIN_FL2_PORT                                          (GPIOB)
#define GPIO_MOTOR_PIN_FL2_PIN                                  (DL_GPIO_PIN_24)
#define GPIO_MOTOR_PIN_FL2_IOMUX                                 (IOMUX_PINCM52)
/* Defines for PIN_FR1: GPIOB.9 with pinCMx 26 on package pin 61 */
#define GPIO_MOTOR_PIN_FR1_PORT                                          (GPIOB)
#define GPIO_MOTOR_PIN_FR1_PIN                                   (DL_GPIO_PIN_9)
#define GPIO_MOTOR_PIN_FR1_IOMUX                                 (IOMUX_PINCM26)
/* Defines for PIN_FR2: GPIOA.27 with pinCMx 60 on package pin 31 */
#define GPIO_MOTOR_PIN_FR2_PORT                                          (GPIOA)
#define GPIO_MOTOR_PIN_FR2_PIN                                  (DL_GPIO_PIN_27)
#define GPIO_MOTOR_PIN_FR2_IOMUX                                 (IOMUX_PINCM60)
/* Defines for PIN_BL1: GPIOB.3 with pinCMx 16 on package pin 51 */
#define GPIO_MOTOR_PIN_BL1_PORT                                          (GPIOB)
#define GPIO_MOTOR_PIN_BL1_PIN                                   (DL_GPIO_PIN_3)
#define GPIO_MOTOR_PIN_BL1_IOMUX                                 (IOMUX_PINCM16)
/* Defines for PIN_BL2: GPIOA.17 with pinCMx 39 on package pin 10 */
#define GPIO_MOTOR_PIN_BL2_PORT                                          (GPIOA)
#define GPIO_MOTOR_PIN_BL2_PIN                                  (DL_GPIO_PIN_17)
#define GPIO_MOTOR_PIN_BL2_IOMUX                                 (IOMUX_PINCM39)
/* Defines for PIN_BR1: GPIOA.24 with pinCMx 54 on package pin 25 */
#define GPIO_MOTOR_PIN_BR1_PORT                                          (GPIOA)
#define GPIO_MOTOR_PIN_BR1_PIN                                  (DL_GPIO_PIN_24)
#define GPIO_MOTOR_PIN_BR1_IOMUX                                 (IOMUX_PINCM54)
/* Defines for PIN_BR2: GPIOA.18 with pinCMx 40 on package pin 11 */
#define GPIO_MOTOR_PIN_BR2_PORT                                          (GPIOA)
#define GPIO_MOTOR_PIN_BR2_PIN                                  (DL_GPIO_PIN_18)
#define GPIO_MOTOR_PIN_BR2_IOMUX                                 (IOMUX_PINCM40)
/* Defines for PIN_FSTBY: GPIOB.4 with pinCMx 17 on package pin 52 */
#define GPIO_MOTOR_PIN_FSTBY_PORT                                        (GPIOB)
#define GPIO_MOTOR_PIN_FSTBY_PIN                                 (DL_GPIO_PIN_4)
#define GPIO_MOTOR_PIN_FSTBY_IOMUX                               (IOMUX_PINCM17)
/* Defines for PIN_BSTBY: GPIOB.13 with pinCMx 30 on package pin 1 */
#define GPIO_MOTOR_PIN_BSTBY_PORT                                        (GPIOB)
#define GPIO_MOTOR_PIN_BSTBY_PIN                                (DL_GPIO_PIN_13)
#define GPIO_MOTOR_PIN_BSTBY_IOMUX                               (IOMUX_PINCM30)
/* Port definition for Pin Group GPIO_LED */
#define GPIO_LED_PORT                                                    (GPIOA)

/* Defines for PIN_LED1: GPIOA.31 with pinCMx 6 on package pin 39 */
#define GPIO_LED_PIN_LED1_PIN                                   (DL_GPIO_PIN_31)
#define GPIO_LED_PIN_LED1_IOMUX                                   (IOMUX_PINCM6)
/* Defines for PIN_LED2: GPIOA.28 with pinCMx 3 on package pin 35 */
#define GPIO_LED_PIN_LED2_PIN                                   (DL_GPIO_PIN_28)
#define GPIO_LED_PIN_LED2_IOMUX                                   (IOMUX_PINCM3)
/* Defines for PIN_FR_A: GPIOB.15 with pinCMx 32 on package pin 3 */
#define GPIO_MOTOR_QEI_PIN_FR_A_PORT                                     (GPIOB)
// groups represented: ["GPIO_Button","GPIO_MOTOR_QEI"]
// pins affected: ["PIN_0","key2","key3","key4","PIN_FR_A","PIN_BR_A"]
#define GPIO_MULTIPLE_GPIOB_INT_IRQN                            (GPIOB_INT_IRQn)
#define GPIO_MULTIPLE_GPIOB_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_MOTOR_QEI_PIN_FR_A_IIDX                        (DL_GPIO_IIDX_DIO15)
#define GPIO_MOTOR_QEI_PIN_FR_A_PIN                             (DL_GPIO_PIN_15)
#define GPIO_MOTOR_QEI_PIN_FR_A_IOMUX                            (IOMUX_PINCM32)
/* Defines for PIN_FR_B: GPIOB.16 with pinCMx 33 on package pin 4 */
#define GPIO_MOTOR_QEI_PIN_FR_B_PORT                                     (GPIOB)
#define GPIO_MOTOR_QEI_PIN_FR_B_PIN                             (DL_GPIO_PIN_16)
#define GPIO_MOTOR_QEI_PIN_FR_B_IOMUX                            (IOMUX_PINCM33)
/* Defines for PIN_FL_A: GPIOA.12 with pinCMx 34 on package pin 5 */
#define GPIO_MOTOR_QEI_PIN_FL_A_PORT                                     (GPIOA)
// groups represented: ["GPIO_Button","GPIO_IMU660RB","GPIO_MOTOR_QEI"]
// pins affected: ["key1","PIN_IMU660RB_INT1","PIN_FL_A","PIN_BL_A"]
#define GPIO_MULTIPLE_GPIOA_INT_IRQN                            (GPIOA_INT_IRQn)
#define GPIO_MULTIPLE_GPIOA_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define GPIO_MOTOR_QEI_PIN_FL_A_IIDX                        (DL_GPIO_IIDX_DIO12)
#define GPIO_MOTOR_QEI_PIN_FL_A_PIN                             (DL_GPIO_PIN_12)
#define GPIO_MOTOR_QEI_PIN_FL_A_IOMUX                            (IOMUX_PINCM34)
/* Defines for PIN_FL_B: GPIOA.13 with pinCMx 35 on package pin 6 */
#define GPIO_MOTOR_QEI_PIN_FL_B_PORT                                     (GPIOA)
#define GPIO_MOTOR_QEI_PIN_FL_B_PIN                             (DL_GPIO_PIN_13)
#define GPIO_MOTOR_QEI_PIN_FL_B_IOMUX                            (IOMUX_PINCM35)
/* Defines for PIN_BR_A: GPIOB.25 with pinCMx 56 on package pin 27 */
#define GPIO_MOTOR_QEI_PIN_BR_A_PORT                                     (GPIOB)
#define GPIO_MOTOR_QEI_PIN_BR_A_IIDX                        (DL_GPIO_IIDX_DIO25)
#define GPIO_MOTOR_QEI_PIN_BR_A_PIN                             (DL_GPIO_PIN_25)
#define GPIO_MOTOR_QEI_PIN_BR_A_IOMUX                            (IOMUX_PINCM56)
/* Defines for PIN_BR_B: GPIOA.21 with pinCMx 46 on package pin 17 */
#define GPIO_MOTOR_QEI_PIN_BR_B_PORT                                     (GPIOA)
#define GPIO_MOTOR_QEI_PIN_BR_B_PIN                             (DL_GPIO_PIN_21)
#define GPIO_MOTOR_QEI_PIN_BR_B_IOMUX                            (IOMUX_PINCM46)
/* Defines for PIN_BL_A: GPIOA.25 with pinCMx 55 on package pin 26 */
#define GPIO_MOTOR_QEI_PIN_BL_A_PORT                                     (GPIOA)
#define GPIO_MOTOR_QEI_PIN_BL_A_IIDX                        (DL_GPIO_IIDX_DIO25)
#define GPIO_MOTOR_QEI_PIN_BL_A_PIN                             (DL_GPIO_PIN_25)
#define GPIO_MOTOR_QEI_PIN_BL_A_IOMUX                            (IOMUX_PINCM55)
/* Defines for PIN_BL_B: GPIOB.17 with pinCMx 43 on package pin 14 */
#define GPIO_MOTOR_QEI_PIN_BL_B_PORT                                     (GPIOB)
#define GPIO_MOTOR_QEI_PIN_BL_B_PIN                             (DL_GPIO_PIN_17)
#define GPIO_MOTOR_QEI_PIN_BL_B_IOMUX                            (IOMUX_PINCM43)
/* Defines for PIN_0: GPIOB.21 with pinCMx 49 on package pin 20 */
#define GPIO_Button_PIN_0_PORT                                           (GPIOB)
#define GPIO_Button_PIN_0_IIDX                              (DL_GPIO_IIDX_DIO21)
#define GPIO_Button_PIN_0_PIN                                   (DL_GPIO_PIN_21)
#define GPIO_Button_PIN_0_IOMUX                                  (IOMUX_PINCM49)
/* Defines for key1: GPIOA.29 with pinCMx 4 on package pin 36 */
#define GPIO_Button_key1_PORT                                            (GPIOA)
#define GPIO_Button_key1_IIDX                               (DL_GPIO_IIDX_DIO29)
#define GPIO_Button_key1_PIN                                    (DL_GPIO_PIN_29)
#define GPIO_Button_key1_IOMUX                                    (IOMUX_PINCM4)
/* Defines for key2: GPIOB.14 with pinCMx 31 on package pin 2 */
#define GPIO_Button_key2_PORT                                            (GPIOB)
#define GPIO_Button_key2_IIDX                               (DL_GPIO_IIDX_DIO14)
#define GPIO_Button_key2_PIN                                    (DL_GPIO_PIN_14)
#define GPIO_Button_key2_IOMUX                                   (IOMUX_PINCM31)
/* Defines for key3: GPIOB.19 with pinCMx 45 on package pin 16 */
#define GPIO_Button_key3_PORT                                            (GPIOB)
#define GPIO_Button_key3_IIDX                               (DL_GPIO_IIDX_DIO19)
#define GPIO_Button_key3_PIN                                    (DL_GPIO_PIN_19)
#define GPIO_Button_key3_IOMUX                                   (IOMUX_PINCM45)
/* Defines for key4: GPIOB.18 with pinCMx 44 on package pin 15 */
#define GPIO_Button_key4_PORT                                            (GPIOB)
#define GPIO_Button_key4_IIDX                               (DL_GPIO_IIDX_DIO18)
#define GPIO_Button_key4_PIN                                    (DL_GPIO_PIN_18)
#define GPIO_Button_key4_IOMUX                                   (IOMUX_PINCM44)
/* Defines for PIN_1: GPIOB.27 with pinCMx 58 on package pin 29 */
#define GPIO_Xunji_PIN_1_PORT                                            (GPIOB)
#define GPIO_Xunji_PIN_1_PIN                                    (DL_GPIO_PIN_27)
#define GPIO_Xunji_PIN_1_IOMUX                                   (IOMUX_PINCM58)
/* Defines for PIN_2: GPIOB.26 with pinCMx 57 on package pin 28 */
#define GPIO_Xunji_PIN_2_PORT                                            (GPIOB)
#define GPIO_Xunji_PIN_2_PIN                                    (DL_GPIO_PIN_26)
#define GPIO_Xunji_PIN_2_IOMUX                                   (IOMUX_PINCM57)
/* Defines for PIN_3: GPIOB.23 with pinCMx 51 on package pin 22 */
#define GPIO_Xunji_PIN_3_PORT                                            (GPIOB)
#define GPIO_Xunji_PIN_3_PIN                                    (DL_GPIO_PIN_23)
#define GPIO_Xunji_PIN_3_IOMUX                                   (IOMUX_PINCM51)
/* Defines for PIN_4: GPIOB.22 with pinCMx 50 on package pin 21 */
#define GPIO_Xunji_PIN_4_PORT                                            (GPIOB)
#define GPIO_Xunji_PIN_4_PIN                                    (DL_GPIO_PIN_22)
#define GPIO_Xunji_PIN_4_IOMUX                                   (IOMUX_PINCM50)
/* Defines for PIN_5: GPIOB.10 with pinCMx 27 on package pin 62 */
#define GPIO_Xunji_PIN_5_PORT                                            (GPIOB)
#define GPIO_Xunji_PIN_5_PIN                                    (DL_GPIO_PIN_10)
#define GPIO_Xunji_PIN_5_IOMUX                                   (IOMUX_PINCM27)
/* Defines for PIN_6: GPIOB.11 with pinCMx 28 on package pin 63 */
#define GPIO_Xunji_PIN_6_PORT                                            (GPIOB)
#define GPIO_Xunji_PIN_6_PIN                                    (DL_GPIO_PIN_11)
#define GPIO_Xunji_PIN_6_IOMUX                                   (IOMUX_PINCM28)
/* Defines for PIN_7: GPIOB.12 with pinCMx 29 on package pin 64 */
#define GPIO_Xunji_PIN_7_PORT                                            (GPIOB)
#define GPIO_Xunji_PIN_7_PIN                                    (DL_GPIO_PIN_12)
#define GPIO_Xunji_PIN_7_IOMUX                                   (IOMUX_PINCM29)
/* Defines for PIN_8: GPIOA.7 with pinCMx 14 on package pin 49 */
#define GPIO_Xunji_PIN_8_PORT                                            (GPIOA)
#define GPIO_Xunji_PIN_8_PIN                                     (DL_GPIO_PIN_7)
#define GPIO_Xunji_PIN_8_IOMUX                                   (IOMUX_PINCM14)
/* Port definition for Pin Group GPIO_IMU660RB */
#define GPIO_IMU660RB_PORT                                               (GPIOA)

/* Defines for PIN_IMU660RB_CS: GPIOA.9 with pinCMx 20 on package pin 55 */
#define GPIO_IMU660RB_PIN_IMU660RB_CS_PIN                        (DL_GPIO_PIN_9)
#define GPIO_IMU660RB_PIN_IMU660RB_CS_IOMUX                      (IOMUX_PINCM20)
/* Defines for PIN_IMU660RB_INT1: GPIOA.14 with pinCMx 36 on package pin 7 */
#define GPIO_IMU660RB_PIN_IMU660RB_INT1_IIDX                (DL_GPIO_IIDX_DIO14)
#define GPIO_IMU660RB_PIN_IMU660RB_INT1_PIN                     (DL_GPIO_PIN_14)
#define GPIO_IMU660RB_PIN_IMU660RB_INT1_IOMUX                    (IOMUX_PINCM36)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_MOTOR_init(void);
void SYSCFG_DL_TIMER_MS_SYS_init(void);
void SYSCFG_DL_UART_OPENMV_init(void);
void SYSCFG_DL_UART_WIT_init(void);
void SYSCFG_DL_SPI_IMU660RB_init(void);
void SYSCFG_DL_DMA_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
