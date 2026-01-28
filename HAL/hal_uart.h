#ifndef __HAL_UART_H
#define __HAL_UART_H

#ifdef __cplusplus
extern "C" {
#endif
#include "stdio.h"
#include "ti_msp_dl_config.h"

int fputc(int c, FILE* stream);
int fputs(const char* restrict s, FILE* restrict stream);
int puts(const char *_ptr);

#ifdef __cplusplus
}
#endif

#endif