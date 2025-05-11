#include "lib.h"

void TASK_INIT()
{
    SYSCFG_DL_init();
    UART_INIT(UART_OPENMV_INST_INT_IRQN);
    UART_INIT(UART_PC_INST_INT_IRQN);
    QEI_INIT(GPIO_MOTOR_QEI_GPIOA_INT_IRQN);
    QEI_INIT(GPIO_MOTOR_QEI_GPIOB_INT_IRQN);

    while(DL_GPIO_readPins(GPIO_BUTTON_PORT, GPIO_BUTTON_PIN_S2_PIN));
    DL_UART_transmitDataBlocking(UART_OPENMV_INST, 'S');

    delay_cycles(32000000);

    Set_Speed(0, baseSpeed);
    Set_Speed(1, baseSpeed);
    Motor_On();

}

void TASK_LOOP()
{
    Motor_Ctrl();
}

