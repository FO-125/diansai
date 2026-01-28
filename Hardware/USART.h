#ifndef __USART_H
#define __USART_H

#ifdef __cplusplus
extern "C" {
#endif
#include "ti_msp_dl_config.h"
#define UART_transmitBlocking(puart,data)   DL_UART_Main_transmitDataBlocking(puart, data)    

#ifdef __cplusplus
}
#endif
#endif