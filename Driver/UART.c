#include "lib.h"
void UART_INIT(IRQn_Type UART0_INT_IRQn)
{
    NVIC_ClearPendingIRQ(UART0_INT_IRQn);
    NVIC_EnableIRQ(UART0_INT_IRQn);
}

void UART_OPENMV_INST_IRQHandler(void)
{
    uint8_t gData;
    switch (DL_UART_Main_getPendingInterrupt(UART_OPENMV_INST)) 
    {
        case DL_UART_MAIN_IIDX_RX:
            gData = DL_UART_Main_receiveData(UART_OPENMV_INST);
            if(gData == 'S')
            {
                Motor_Off();
                DL_GPIO_clearPins(GPIO_LED_PORT, GPIO_LED_PIN_LED1_PIN);
            }
            else if(gData == '#')
                rxbuf = 0;
            else if(gData == '$')
                cx = rxbuf;
            else
                rxbuf = rxbuf*10 + (gData - '0');
            break;
        default:
            break;
    }
}