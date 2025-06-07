#ifndef __XUNJI_H
#define __XUNJI_H
int GetXunJIErr(void);
void XunJIPIDConcrolTurn(uint16_t EncoderNumber);
void ControlSinAngleA_B(float targetAngle,uint16_t EncoderNumber);
void ControlSinAngleC_D(float targetAngle,uint16_t EncoderNumber);

#endif
