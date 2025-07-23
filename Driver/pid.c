#include "lib.h"

// float outer_pid_controller(float setpoint, float input, float kp, float ki, float kd, float dt) {
//     static float integral = 0;
//     static float prev_error = 0;
//     float error = setpoint - input;

//     // 计算积分项
//     integral += error * dt;

//     // 计算微分项
//     float derivative = (error - prev_error) / dt;

//     // 计算输出
//     float output = kp * error + ki * integral + kd * derivative;

//     // 更新上一个误差
//     prev_error = error;

//     return output;
// }

// float inner_pid_controller(float setpoint, float input, float kp, float ki, float kd, float dt) {
//     static float integral = 0;
//     static float prev_error = 0;
//     float error = setpoint - input;

//     // 计算积分项
//     integral += error * dt;

//     // 计算微分项
//     float derivative = (error - prev_error) / dt;

//     // 计算输出
//     float output = kp * error + ki * integral + kd * derivative;

//     // 更新上一个误差
//     prev_error = error;

//     return output;
// }

// float double_pid_controller(float setpoint, float input, float outer_kp, float outer_ki, float outer_kd, float inner_kp, float inner_ki, float inner_kd, float dt) {
//     // 计算外环控制器输出
//     float outer_output = outer_pid_controller(setpoint, input, outer_kp, outer_ki, outer_kd, dt);

//     // 计算内环控制器输出
//     float inner_output = inner_pid_controller(outer_output, input, inner_kp, inner_ki, inner_kd, dt);

//     return inner_output;
// }

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

void PID_Init_Wheel(float kp,float ki,float kd)
{
    PID_Init(&PID_FL,kp,ki,kd);
    PID_Init(&PID_FR,kp,ki,kd);
    PID_Init(&PID_BL,kp,ki,kd);
    PID_Init(&PID_BR,kp,ki,kd);
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
    if(fabsf(PID->out-PID->Target)<2)
        PID->out=PID->Target;
    Set_Speed(Wheel_FL,PID->out);
}

void PID_Update_FR(S_PID* PID)
{
    PID->Last_LastActual=PID->Last_Actual;

    PID->Last_Actual=PID->Actual;
    (*PID).Actual=0.4432*Get_QEI_FR()-0.55;
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
    if(fabsf(PID->out-PID->Target)<1)
        PID->out=PID->Target;
    Set_Speed(Wheel_FR,PID->out);
}

void PID_Update_BL(S_PID* PID)
{
    PID->Last_LastActual=PID->Last_Actual;
    PID->Last_Actual=PID->Actual;
    (*PID).Actual=0.4432*Get_QEI_BL()-0.55;
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
    if(fabsf(PID->out-PID->Target)<1)
        PID->out=PID->Target;
    Set_Speed(Wheel_BL,PID->out);
}

void PID_Update_BR(S_PID* PID)
{
    PID->Last_LastActual=PID->Last_Actual;
    PID->Last_Actual=PID->Actual;
    (*PID).Actual=0.4432*Get_QEI_BR()-0.55;
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
    if(fabsf(PID->out-PID->Target)<1)
        PID->out=PID->Target;
    Set_Speed(Wheel_BR,PID->out);
}

int PID_Update_Yaw(S_PID* PID)
{
    static float BianSu_C=0;
    PID->Last_Actual=PID->Actual;
    PID->Actual=(wit_data.yaw - wit_data.yawInit/*直线的sin(Yaw)*/);
    PID->Error=sin(PID->Target*3.1416/180)-sin(PID->Actual*3.1416/180);
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

