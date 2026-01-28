#include "alg_pid.h"
#include <string.h>
#include <math.h>

// PID控制器数据结构体
typedef struct {
    float target;           // 目标值
    float actual;           // 实际值
    float last_actual;      // 上一次实际值
    float last_last_actual; // 上上次实际值
    float kp;               // 比例系数
    float ki;               // 积分系数
    float kd;               // 微分系数
    float error;            // 当前误差
    float last_error;       // 上一次误差
    float last_last_error;  // 上上次误差
    float error_int;        // 误差积分
    float difout;           // 微分输出
    float output;           // PID输出
    float output_limit_min; // 输出下限
    float output_limit_max; // 输出上限
    float integral_limit;   // 积分限幅
} PID_Data;

// PID设备数据结构体
typedef struct {
    PID_Data data;          // PID数据
    PID_Type type;          // PID类型
} Dev_PID_Data;

// PID设备数据实例
Dev_PID_Data PID_data_FL = {0};
Dev_PID_Data PID_data_FR = {0};
Dev_PID_Data PID_data_BL = {0};
Dev_PID_Data PID_data_BR = {0};
Dev_PID_Data PID_data_Yaw = {0};
Dev_PID_Data PID_data_Xunji = {0};

// PID初始化函数
int PID_init(struct Dev_PID *pid, float kp, float ki, float kd, PID_Type type)
{
    Dev_PID_Data *data = (Dev_PID_Data *)pid->pid_data;
    
    // 初始化PID参数
    data->data.kp = kp;
    data->data.ki = ki;
    data->data.kd = kd;
    data->type = type;
    
    // 初始化状态变量
    data->data.target = 0.0f;
    data->data.actual = 0.0f;
    data->data.last_actual = 0.0f;
    data->data.last_last_actual = 0.0f;
    data->data.error = 0.0f;
    data->data.last_error = 0.0f;
    data->data.last_last_error = 0.0f;
    data->data.error_int = 0.0f;
    data->data.difout = 0.0f;
    data->data.output = 0.0f;
    
    // 设置默认限幅值
    data->data.output_limit_min = -100.0f;
    data->data.output_limit_max = 100.0f;
    data->data.integral_limit = 1000.0f;
    
    return 1;
}

// 设置目标值函数
int PID_set_target(struct Dev_PID *pid, float target)
{
    Dev_PID_Data *data = (Dev_PID_Data *)pid->pid_data;
    data->data.target = target;
    return 1;
}

// 设置PID参数函数
int PID_set_params(struct Dev_PID *pid, float kp, float ki, float kd)
{
    Dev_PID_Data *data = (Dev_PID_Data *)pid->pid_data;
    data->data.kp = kp;
    data->data.ki = ki;
    data->data.kd = kd;
    return 1;
}

// 位置式PID计算
static float positional_pid_calculate(PID_Data *pid_data, float actual)
{
    // 更新实际值
    pid_data->last_actual = pid_data->actual;
    pid_data->actual = actual;
    
    // 计算误差
    pid_data->last_error = pid_data->error;
    pid_data->error = pid_data->target - pid_data->actual;
    
    // 积分项计算（带限幅）
    pid_data->error_int += pid_data->error;
    if (pid_data->error_int > pid_data->integral_limit) {
        pid_data->error_int = pid_data->integral_limit;
    } else if (pid_data->error_int < -pid_data->integral_limit) {
        pid_data->error_int = -pid_data->integral_limit;
    }
    
    // 微分项计算（不完全微分）
    pid_data->difout = (1.0f - 0.8f) * (-pid_data->kd) * (pid_data->actual - pid_data->last_actual) + 0.8f * pid_data->difout;
    
    // PID输出计算
    pid_data->output = pid_data->kp * pid_data->error + pid_data->ki * pid_data->error_int + pid_data->kd * pid_data->difout;
    
    // 输出限幅
    if (pid_data->output > pid_data->output_limit_max) {
        pid_data->output = pid_data->output_limit_max;
    } else if (pid_data->output < pid_data->output_limit_min) {
        pid_data->output = pid_data->output_limit_min;
    }
    
    return pid_data->output;
}

// 增量式PID计算
static float incremental_pid_calculate(PID_Data *pid_data, float actual)
{
    // 更新实际值
    pid_data->last_last_actual = pid_data->last_actual;
    pid_data->last_actual = pid_data->actual;
    pid_data->actual = actual;
    
    // 计算误差
    pid_data->last_last_error = pid_data->last_error;
    pid_data->last_error = pid_data->error;
    pid_data->error = pid_data->target - pid_data->actual;
    
    // 微分先行（增量式）
    pid_data->difout = (-pid_data->kd) * (pid_data->actual - 2 * pid_data->last_actual + pid_data->last_last_actual);
    
    // 增量式PID输出计算
    pid_data->output += pid_data->kp * (pid_data->error - pid_data->last_error) + 
                       pid_data->ki * pid_data->error + 
                       pid_data->difout;
    
    // 输出限幅
    if (pid_data->output > pid_data->output_limit_max) {
        pid_data->output = pid_data->output_limit_max;
    } else if (pid_data->output < pid_data->output_limit_min) {
        pid_data->output = pid_data->output_limit_min;
    }
    
    return pid_data->output;
}

// 更新PID计算函数
float PID_update(struct Dev_PID *pid, float actual)
{
    Dev_PID_Data *data = (Dev_PID_Data *)pid->pid_data;
    
    if (data->type == PID_POSITIONAL) {
        return positional_pid_calculate(&data->data, actual);
    } else {
        return incremental_pid_calculate(&data->data, actual);
    }
}

// 重置PID控制器函数
int PID_reset(struct Dev_PID *pid)
{
    Dev_PID_Data *data = (Dev_PID_Data *)pid->pid_data;
    
    // 重置状态变量
    data->data.actual = 0.0f;
    data->data.last_actual = 0.0f;
    data->data.last_last_actual = 0.0f;
    data->data.error = 0.0f;
    data->data.last_error = 0.0f;
    data->data.last_last_error = 0.0f;
    data->data.error_int = 0.0f;
    data->data.difout = 0.0f;
    data->data.output = 0.0f;
    
    return 1;
}

// 设置输出限幅函数
int PID_set_output_limits(struct Dev_PID *pid, float min, float max)
{
    Dev_PID_Data *data = (Dev_PID_Data *)pid->pid_data;
    
    if (min >= max) {
        return 0;  // 参数错误
    }
    
    data->data.output_limit_min = min;
    data->data.output_limit_max = max;
    
    return 1;
}

// 设置积分限幅函数
int PID_set_integral_limit(struct Dev_PID *pid, float limit)
{
    Dev_PID_Data *data = (Dev_PID_Data *)pid->pid_data;
    
    if (limit <= 0) {
        return 0;  // 参数错误
    }
    
    data->data.integral_limit = limit;
    
    return 1;
}

// 获取PID状态函数
int PID_GetStatus(struct Dev_PID *pid, PID_Status *status)
{
    if (pid == NULL || status == NULL) {
        return 0;  // 参数错误
    }
    
    Dev_PID_Data *data = (Dev_PID_Data *)pid->pid_data;
    
    status->target = data->data.target;
    status->actual = data->data.actual;
    status->error = data->data.error;
    status->output = data->data.output;
    status->kp = data->data.kp;
    status->ki = data->data.ki;
    status->kd = data->data.kd;
    
    return 1;
}

// PID设备实例数组
static struct Dev_PID pid_instances[] =
{
    {
        "pid_controller_FL",
        PID_init,
        PID_set_target,
        PID_set_params,
        PID_update,
        PID_reset,
        PID_set_output_limits,
        PID_set_integral_limit,
        &PID_data_FL,
        PID_INCREMENTAL
    },
    {
        "pid_controller_FR",
        PID_init,
        PID_set_target,
        PID_set_params,
        PID_update,
        PID_reset,
        PID_set_output_limits,
        PID_set_integral_limit,
        &PID_data_FR,
        PID_INCREMENTAL
    },
    {
        "pid_controller_BL",
        PID_init,
        PID_set_target,
        PID_set_params,
        PID_update,
        PID_reset,
        PID_set_output_limits,
        PID_set_integral_limit,
        &PID_data_BL,
        PID_INCREMENTAL
    },
    {
        "pid_controller_BR",
        PID_init,
        PID_set_target,
        PID_set_params,
        PID_update,
        PID_reset,
        PID_set_output_limits,
        PID_set_integral_limit,
        &PID_data_BR,
        PID_INCREMENTAL
    },
    {
        "pid_controller_Yaw",
        PID_init,
        PID_set_target,
        PID_set_params,
        PID_update,
        PID_reset,
        PID_set_output_limits,
        PID_set_integral_limit,
        &PID_data_Yaw,
        PID_POSITIONAL
    },
    {
        "pid_controller_Trace",
        PID_init,
        PID_set_target,
        PID_set_params,
        PID_update,
        PID_reset,
        PID_set_output_limits,
        PID_set_integral_limit,
        &PID_data_Xunji,
        PID_POSITIONAL
    }
};

// PID设备指针数组
struct Dev_PID *g_pid_devs[] = {
    &pid_instances[0],
    &pid_instances[1], 
    &pid_instances[2],
    &pid_instances[3],
    &pid_instances[4],
    &pid_instances[5]
};

// 获取PID设备函数
struct Dev_PID *GetPID(char *name)
{
    int i = 0;
    for (i = 0; i < sizeof(g_pid_devs) / sizeof(g_pid_devs[0]); i++)
    {
        if (0 == strcmp(name, g_pid_devs[i]->name))
            return g_pid_devs[i];
    }
    return NULL;
}
