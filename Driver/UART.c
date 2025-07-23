#include "UART.h"
#include "lib.h"
#include "string.h"
#include <stdlib.h>

uint8_t USART_RXBUF_OPENMV[5];


struct OPENMV_Data Openmv=
{
    .head1=0xA5,
    .head2=0xA6,
    .tail=0x5A
};
struct XunJi_Data Xunji=
{

};
// struct JY61P_Data JY61P_Data=
// {
//     .RxIndex=0,
//     .RxState=0,
// };


//printf重定向
int fputc(int c, FILE* stream)
{
	DL_UART_Main_transmitDataBlocking(UART_OPENMV_INST, c);
    return c;
}

int fputs(const char* restrict s, FILE* restrict stream)
{
    uint16_t i, len;
    len = strlen(s);
    for(i=0; i<len; i++)
    {
        DL_UART_Main_transmitDataBlocking(UART_OPENMV_INST, s[i]);
    }
    return len;
}

int puts(const char *_ptr)
{
int count = fputs(_ptr, stdout);
count += fputs("\n", stdout);
return count;
}

// void jy61p_Init(void)

// {

//     NVIC_ClearPendingIRQ(UART_TuoLuoYi_INST_INT_IRQN);

//     NVIC_EnableIRQ(UART_TuoLuoYi_INST_INT_IRQN);

//     DL_UART_clearInterruptStatus(UART_TuoLuoYi_INST,GPIO_UART_TuoLuoYi_IOMUX_RX_FUNC);//清除中断标志位
    
// }


void NVIC_INIT(IRQn_Type UART0_INT_IRQn)
{
    // NVIC_ClearPendingIRQ(UART0_INT_IRQn);
    NVIC_EnableIRQ(UART0_INT_IRQn);
}

void Uart_Run_OPENMV(void)
{
    static uint8_t i = 0;
    uint8_t Res;
    static uint8_t  flag =1;
    Res = DL_UART_Main_receiveData(UART_OPENMV_INST);
    if(Res == 0xA5&&flag == 1)
        flag = 2;
    else if(Res == 0xA6 && flag == 2)
        flag =3;
    else if (flag ==3)
    {
        if(Res != 0x5A)
        {
            USART_RXBUF_OPENMV[i++] = Res;
        }
        else if(Res == 0xA5)
        {
            Openmv.data1=USART_RXBUF_OPENMV[0];
            Openmv.data2=USART_RXBUF_OPENMV[1];
            Openmv.data3=USART_RXBUF_OPENMV[2];
            Openmv.data4=USART_RXBUF_OPENMV[3];
            Openmv.data5=USART_RXBUF_OPENMV[4];
            i = 0;
            flag=1;
        }
    }
    
    else
    {
        i = 0;
        flag=1;
    }
}


// //获取角度
// void Uart_Run_TuoLuoYi()
// {
//     JY61P_Data.Roll_last=JY61P_Data.Roll;
//     JY61P_Data.Pitch_last=JY61P_Data.Pitch;
//     JY61P_Data.RxData = DL_UART_receiveData(UART_TuoLuoYi_INST);
//     uint8_t i,sum=0;
//     if (JY61P_Data.RxState == 0)   //等待包头
//     {
//         if (JY61P_Data.RxData == 0x55) //收到包头
//         {
//             JY61P_Data.RxBuffer[JY61P_Data.RxIndex] = JY61P_Data.RxData;
//             JY61P_Data.RxState = 1;
//             JY61P_Data.RxIndex = 1; //进入下一状态
//         }
//     }
    
//     else if (JY61P_Data.RxState == 1)
//     {
//         if (JY61P_Data.RxData == 0x53) /*判断数据内容，0x53为角度输出*/
//         {
//             JY61P_Data.RxBuffer[JY61P_Data.RxIndex] = JY61P_Data.RxData;
//             JY61P_Data.RxState = 2;
//             JY61P_Data.RxIndex = 2; //进入下一状态
//         }
//     }
//     else if (JY61P_Data.RxState == 2)  //接收数据
//     {
//         JY61P_Data.RxBuffer[JY61P_Data.RxIndex++] = JY61P_Data.RxData;
//         if(JY61P_Data.RxIndex == 11)   //接收完成
//         {
//             // for(i=0;i<10;i++)
//             // {
//             //     sum = sum + JY61P_Data.RxBuffer[i]; //计算校验和
//             // }
//             // if(sum ==JY61P_Data.RxBuffer[10])     //校验成功
//             // {
//             JY61P_Data.Roll = ((int16_t) ((int16_t) JY61P_Data.RxBuffer[3] << 8 | (int16_t) JY61P_Data.RxBuffer[2])) / 32768.0f * 180.0f;
//             JY61P_Data.Pitch = ((int16_t) ((int16_t) JY61P_Data.RxBuffer[5] << 8 | (int16_t) JY61P_Data.RxBuffer[4])) / 32768.0f * 180.0f;
//             JY61P_Data.Yaw = ((int16_t) ((int16_t) JY61P_Data.RxBuffer[7] << 8 | (int16_t) JY61P_Data.RxBuffer[6])) / 32768.0f * 180.0f;
                
//             // }
//             JY61P_Data.RxState = 0;

//             JY61P_Data.RxIndex = 0; //读取完成，回到最初状态，等待包头
//             if(abs(JY61P_Data.Yaw-JY61P_Data.Pitch_last)>2&&abs(JY61P_Data.Yaw-JY61P_Data.Roll_last)>2)
//                 JY61P_Data.Yaw_true=JY61P_Data.Yaw;
//             JY61P_Data.QYaw1 = (sin(JY61P_Data.Yaw_true*3.1416/180))*100;      
//         }

//     }

// }

void YawInit(float YawInit)
{
    wit_data.yawInit=YawInit;
}


void UART_OPENMV_INST_IRQHandler(void)
{
    

}

void UART_WIT_INST_IRQHandler(void)
{
    uint8_t checkSum, packCnt = 0;
    extern uint8_t wit_dmaBuffer[33];

    DL_DMA_disableChannel(DMA, DMA_WIT_CHAN_ID);
    uint8_t rxSize = 32 - DL_DMA_getTransferSize(DMA, DMA_WIT_CHAN_ID);

    if(DL_UART_isRXFIFOEmpty(UART_WIT_INST) == false)
        wit_dmaBuffer[rxSize++] = DL_UART_receiveData(UART_WIT_INST);

    while(rxSize >= 11)
    {
        checkSum=0;
        for(int i=packCnt*11; i<(packCnt+1)*11-1; i++)
            checkSum += wit_dmaBuffer[i];

        if((wit_dmaBuffer[packCnt*11] == 0x55) && (checkSum == wit_dmaBuffer[packCnt*11+10]))
        {
            if(wit_dmaBuffer[packCnt*11+1] == 0x51)
            {
                wit_data.ax = (int16_t)((wit_dmaBuffer[packCnt*11+3]<<8)|wit_dmaBuffer[packCnt*11+2]) / 2.048; //mg
                wit_data.ay = (int16_t)((wit_dmaBuffer[packCnt*11+5]<<8)|wit_dmaBuffer[packCnt*11+4]) / 2.048; //mg
                wit_data.az = (int16_t)((wit_dmaBuffer[packCnt*11+7]<<8)|wit_dmaBuffer[packCnt*11+6]) / 2.048; //mg
                wit_data.temperature =  (int16_t)((wit_dmaBuffer[packCnt*11+9]<<8)|wit_dmaBuffer[packCnt*11+8]) / 100.0; //°C
            }
            else if(wit_dmaBuffer[packCnt*11+1] == 0x52)
            {
                wit_data.gx = (int16_t)((wit_dmaBuffer[packCnt*11+3]<<8)|wit_dmaBuffer[packCnt*11+2]) / 16.384; //°/S
                wit_data.gy = (int16_t)((wit_dmaBuffer[packCnt*11+5]<<8)|wit_dmaBuffer[packCnt*11+4]) / 16.384; //°/S
                wit_data.gz = (int16_t)((wit_dmaBuffer[packCnt*11+7]<<8)|wit_dmaBuffer[packCnt*11+6]) / 16.384; //°/S
            }
            else if(wit_dmaBuffer[packCnt*11+1] == 0x53)
            {
                wit_data.roll  = (int16_t)((wit_dmaBuffer[packCnt*11+3]<<8)|wit_dmaBuffer[packCnt*11+2]) / 32768.0 * 180.0; //°
                wit_data.pitch = (int16_t)((wit_dmaBuffer[packCnt*11+5]<<8)|wit_dmaBuffer[packCnt*11+4]) / 32768.0 * 180.0; //°
                wit_data.yaw   = (int16_t)((wit_dmaBuffer[packCnt*11+7]<<8)|wit_dmaBuffer[packCnt*11+6]) / 32768.0 * 180.0; //°
                wit_data.version = (int16_t)((wit_dmaBuffer[packCnt*11+9]<<8)|wit_dmaBuffer[packCnt*11+8]);
                wit_data.QYaw1 = (sin(wit_data.yaw*3.1416/180))*100;
            }
        }

        rxSize -= 11;
        packCnt++;
    }
    
    uint8_t dummy[4];
    DL_UART_drainRXFIFO(UART_WIT_INST, dummy, 4);

    DL_DMA_setDestAddr(DMA, DMA_WIT_CHAN_ID, (uint32_t) &wit_dmaBuffer[0]);
    DL_DMA_setTransferSize(DMA, DMA_WIT_CHAN_ID, 32);
    DL_DMA_enableChannel(DMA, DMA_WIT_CHAN_ID);
}