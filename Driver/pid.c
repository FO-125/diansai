#include "lib.h"

S_PID PID_FL;
S_PID PID_FR;
S_PID PID_BL;
S_PID PID_BR;
S_PID PID_Yaw;
S_PID PID_Turn;
void PID_Init(S_PID* PID,float Kp,float Ki,float Kd)
{
    PID->KP=Kp;
    PID->KI=Ki;
    PID->KD=Kd;
}

void PID_Init_Wheel()
{
    PID_Init(&PID_FL,KP_FL,KI_FL,KD_FL);
    PID_Init(&PID_FR,KP_FR,KI_FR,KD_FR);
    PID_Init(&PID_BL,KP_BL,KI_BL,KD_BL);
    PID_Init(&PID_BR,KP_BR,KI_BR,KD_BR);
}

void PID_SetTaget(S_PID* PID,float taget)
{
    PID->Target=taget;
}

void PID_Update_FL(S_PID* PID)
{
    PID->Last_LastActual=PID->Last_Actual;
    PID->Last_Actual=PID->Actual;
    (*PID).Actual=0.448*Get_QEI_FL()-1.56;
    PID->Last_LastError=PID->LastError;
    PID->LastError=PID->Error;
    PID->Error=PID->Target-PID->Actual;
    // if(PID->Error<0&&PID->Error>-1)
    // {
    //     PID->Error=0;
    // }
    // else if (PID->Error>0&&PID->Error<1)
    // {
    //     PID->Error=0;
    // }
    //微分先行(增量式)
    PID->Difout=(-PID->KD)*(PID->Actual-2*PID->Last_Actual+PID->Last_LastActual);

    PID->out+=PID->KP*(PID->Error-PID->LastError)+PID->KI*PID->Error+PID->Difout;//增量式
    if(PID->out>95)
    {
        PID->out=95;
    }
    if(PID->out<-95)
    {
        PID->out=-95;
    }
    if(fabsf(PID->Actual-PID->Target)<5)
        PID->out=PID->Target;
    Set_Speed(Wheel_FL,PID->out);
}

void PID_Update_FR(S_PID* PID)
{
    PID->Last_LastActual=PID->Last_Actual;

    PID->Last_Actual=PID->Actual;
    (*PID).Actual=0.448*Get_QEI_FR()-1.56;
    PID->Last_LastError=PID->LastError;
    PID->LastError=PID->Error;
    PID->Error=PID->Target-PID->Actual;
    //微分先行(增量式)
    PID->Difout=(-PID->KD)*(PID->Actual-2*PID->Last_Actual+PID->Last_LastActual);

    PID->out+=PID->KP*(PID->Error-PID->LastError)+PID->KI*PID->Error+PID->Difout;//增量式
    if(PID->out>95)
    {
        PID->out=95;
    }
    if(PID->out<-95)
    {
        PID->out=-95;
    }
    if(fabsf(PID->Actual-PID->Target)<5)
        PID->out=PID->Target;
    Set_Speed(Wheel_FR,PID->out);
}

void PID_Update_BL(S_PID* PID)
{
    PID->Last_LastActual=PID->Last_Actual;
    PID->Last_Actual=PID->Actual;
    (*PID).Actual=0.448*Get_QEI_BL()-1.56;
    PID->Last_LastError=PID->LastError;
    PID->LastError=PID->Error;
    PID->Error=PID->Target-PID->Actual;
    //微分先行(增量式)
    PID->Difout=(-PID->KD)*(PID->Actual-2*PID->Last_Actual+PID->Last_LastActual);

    PID->out+=PID->KP*(PID->Error-PID->LastError)+PID->KI*PID->Error+PID->Difout;//增量式
    if(PID->out>95)
    {
        PID->out=95;
    }
    if(PID->out<-95)
    {
        PID->out=-95;
    }
    if(fabsf(PID->Actual-PID->Target)<5)
        PID->out=PID->Target;
    Set_Speed(Wheel_BL,PID->out);
}

void PID_Update_BR(S_PID* PID)
{
    PID->Last_LastActual=PID->Last_Actual;
    PID->Last_Actual=PID->Actual;
    (*PID).Actual=0.448*Get_QEI_BR()-1.56;
    PID->Last_LastError=PID->LastError;
    PID->LastError=PID->Error;
    PID->Error=PID->Target-PID->Actual;
    //微分先行(增量式)
    PID->Difout=(-PID->KD)*(PID->Actual-2*PID->Last_Actual+PID->Last_LastActual);

    PID->out+=PID->KP*(PID->Error-PID->LastError)+PID->KI*PID->Error+PID->Difout;//增量式
    if(PID->out>95)
    {
        PID->out=95;
    }
    if(PID->out<-95)
    {
        PID->out=-95;
    }
    if(fabsf(PID->Actual-PID->Target)<5)
        PID->out=PID->Target;
    Set_Speed(Wheel_BR,PID->out);
}

int PID_Update_Yaw(S_PID* PID)
{
    static float BianSu_C=0;
    PID->Last_Actual=PID->Actual;
    PID->Actual=wit_data.yaw - wit_data.yawInit;
    PID->Error=(sin(PID->Target*3.1416/180)-sin(PID->Actual*3.1416/180));
    //变速积分
    BianSu_C=1/(8*fabs(PID->Error)+1);
    PID->ErrorInt+= BianSu_C*PID->Error;
    //积分限幅
    if(PID->ErrorInt>6000)
	{
		PID->ErrorInt = 6000;	
	}
	else if(PID->ErrorInt < -6000)
	{
		PID->ErrorInt = -6000;	
	}
    //不完全微分+微分先行（位置式）
    PID->Difout=(1-0.8)*(-PID->KD)*(PID->Actual-PID->Last_Actual)+0.8*PID->Difout;

    PID->out=PID->KP*PID->Error+PID->KI*PID->ErrorInt+PID->KD*PID->Difout;//位置式

    return (int)PID->out;
}

int PID_Update_Xunji(S_PID* PID)
{	
    static float BianSu_C=0;
    PID->LastError = PID->Error;
	PID->Error =  GetXunJIErr();
    //变速积分
    BianSu_C=1/(8*fabs(PID->Error)+1);
    PID->ErrorInt+= BianSu_C*PID->Error;
        if(PID->ErrorInt>6000)
        {
            PID->ErrorInt = 6000;	
        }
        else if(PID->ErrorInt < -6000)
        {
            PID->ErrorInt = -6000;	
        }	
        PID->out = PID->KP*PID->Error + PID->KI*PID->ErrorInt + PID->KD*(PID->Error - PID->LastError);	
    return (int)PID->out;	
}

