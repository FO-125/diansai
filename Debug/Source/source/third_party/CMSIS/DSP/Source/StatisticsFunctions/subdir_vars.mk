################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_entropy_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_entropy_f64.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_kullback_leibler_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_kullback_leibler_f64.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_logsumexp_dot_prod_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_logsumexp_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_no_idx_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q7.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q7.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_min_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q7.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_power_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q7.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_std_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_std_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_std_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_var_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_var_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_var_q31.c 

C_DEPS += \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_entropy_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_entropy_f64.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_kullback_leibler_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_kullback_leibler_f64.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_logsumexp_dot_prod_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_logsumexp_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_no_idx_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q7.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q7.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_min_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q7.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_power_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q7.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_std_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_std_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_std_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_var_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_var_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_var_q31.d 

OBJS += \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_entropy_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_entropy_f64.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_kullback_leibler_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_kullback_leibler_f64.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_logsumexp_dot_prod_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_logsumexp_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_no_idx_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q7.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q7.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_min_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q7.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_power_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q7.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_std_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_std_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_std_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_var_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_var_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_var_q31.o 

OBJS__QUOTED += \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_entropy_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_entropy_f64.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_kullback_leibler_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_kullback_leibler_f64.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_logsumexp_dot_prod_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_logsumexp_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_max_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_max_no_idx_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_max_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_max_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_max_q7.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_mean_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_mean_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_mean_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_mean_q7.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_min_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_min_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_min_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_min_q7.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_power_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_power_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_power_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_power_q7.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_rms_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_rms_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_rms_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_std_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_std_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_std_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_var_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_var_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_var_q31.o" 

C_DEPS__QUOTED += \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_entropy_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_entropy_f64.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_kullback_leibler_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_kullback_leibler_f64.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_logsumexp_dot_prod_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_logsumexp_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_max_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_max_no_idx_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_max_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_max_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_max_q7.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_mean_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_mean_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_mean_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_mean_q7.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_min_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_min_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_min_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_min_q7.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_power_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_power_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_power_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_power_q7.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_rms_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_rms_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_rms_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_std_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_std_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_std_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_var_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_var_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\StatisticsFunctions\arm_var_q31.d" 

C_SRCS__QUOTED += \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_entropy_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_entropy_f64.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_kullback_leibler_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_kullback_leibler_f64.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_logsumexp_dot_prod_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_logsumexp_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_no_idx_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_max_q7.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_mean_q7.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_min_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_min_q7.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_power_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_power_q7.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_rms_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_std_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_std_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_std_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_var_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_var_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/StatisticsFunctions/arm_var_q31.c" 


