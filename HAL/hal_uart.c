#include "USART.h"
#include "hal_uart.h"
#include "string.h"
//printf重定向
int fputc(int c, FILE* stream)
{
	UART_transmitBlocking(UART_OPENMV_INST, c);
    return c;
}

int fputs(const char* restrict s, FILE* restrict stream)
{
    uint16_t i, len;
    len = strlen(s);
    for(i=0; i<len; i++)
    {
        UART_transmitBlocking(UART_OPENMV_INST, s[i]);
    }
    return len;
}

int puts(const char *_ptr)
{
int count = fputs(_ptr, stdout);
count += fputs("\n", stdout);
return count;
}