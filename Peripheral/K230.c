#include "K230.h"

uint8_t k230_dmaBuffer[10];

K230_Data_t k230_data=
{
    
};


void K230_Init(void)
{
    DL_DMA_setSrcAddr(DMA, DMA_K230_CHAN_ID, (uint32_t)(&UART_OPENMV_INST->RXDATA));
    DL_DMA_setDestAddr(DMA, DMA_K230_CHAN_ID, (uint32_t) &k230_dmaBuffer[0]);
    DL_DMA_setTransferSize(DMA, DMA_K230_CHAN_ID, 9);
    DL_DMA_enableChannel(DMA, DMA_K230_CHAN_ID);

    NVIC_EnableIRQ(UART_OPENMV_INST_INT_IRQN);
}


void UART_OPENMV_INST_IRQHandler(void)
{
    DL_UART_IIDX uartIntIdx = (DL_UART_IIDX)UART_OPENMV_INST->CPU_INT.IIDX;
    if (uartIntIdx == DL_UART_IIDX_RX) 
    {

    }
    else
    {
         extern uint8_t k230_dmaBuffer[10];

        DL_DMA_disableChannel(DMA, DMA_K230_CHAN_ID);
        uint8_t rxSize = 9 - DL_DMA_getTransferSize(DMA, DMA_K230_CHAN_ID);

        if(DL_UART_isRXFIFOEmpty(UART_OPENMV_INST) == false)
            k230_dmaBuffer[rxSize++] = DL_UART_receiveData(UART_OPENMV_INST);

        while(rxSize >= 10)
        {
        
            rxSize -= 10;
        }
        
        uint8_t dummy[4];
        DL_UART_drainRXFIFO(UART_OPENMV_INST, dummy, 4);

        DL_DMA_setDestAddr(DMA, DMA_K230_CHAN_ID, (uint32_t) &k230_dmaBuffer[0]);
        DL_DMA_setTransferSize(DMA, DMA_K230_CHAN_ID, 9);
        DL_DMA_enableChannel(DMA, DMA_K230_CHAN_ID);
    }
   
}