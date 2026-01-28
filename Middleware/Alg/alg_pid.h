#ifndef __ALG_PID_H
#define __ALG_PID_H
#ifdef __cplusplus
extern "C" {
#endif
#include "stdint.h"

// PID控制器类型枚举
typedef enum {
    PID_POSITIONAL = 0,  // 位置式PID
    PID_INCREMENTAL = 1  // 增量式PID
} PID_Type;

// PID控制器设备结构体
struct Dev_PID {
    char *name;                              // 设备名称
    
    // 函数指针
    int (*init)(struct Dev_PID *pid, float kp, float ki, float kd, PID_Type type);  // 初始化函数
    int (*set_target)(struct Dev_PID *pid, float target);                           // 设置目标值
    int (*set_params)(struct Dev_PID *pid, float kp, float ki, float kd);           // 设置PID参数
    float (*update)(struct Dev_PID *pid, float actual);                             // 更新PID计算
    int (*reset)(struct Dev_PID *pid);                                              // 重置PID控制器
    int (*set_output_limits)(struct Dev_PID *pid, float min, float max);            // 设置输出限幅
    int (*set_integral_limit)(struct Dev_PID *pid, float limit);                    // 设置积分限幅
    
    // PID控制器数据
    void *pid_data;                         // PID数据指针
    PID_Type type;                          // PID类型
};

// PID状态结构体（用于获取当前状态）
typedef struct {
    float target;           // 目标值
    float actual;           // 实际值
    float error;            // 当前误差
    float output;           // PID输出
    float kp;               // 比例系数
    float ki;               // 积分系数
    float kd;               // 微分系数
} PID_Status;

// 函数声明
struct Dev_PID *GetPID(char *name);
int PID_GetStatus(struct Dev_PID *pid, PID_Status *status);  // 获取PID状态

// 常用PID参数常量定义
#define DEFAULT_PID_KP      1.0f
#define DEFAULT_PID_KI      0.1f
#define DEFAULT_PID_KD      0.05f
#define DEFAULT_OUTPUT_MAX  100.0f
#define DEFAULT_OUTPUT_MIN  -100.0f
#define DEFAULT_INTEGRAL_LIMIT 1000.0f

#ifdef __cplusplus
}
#endif
#endif
