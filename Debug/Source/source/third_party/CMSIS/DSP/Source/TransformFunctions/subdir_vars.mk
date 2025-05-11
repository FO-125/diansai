################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal2.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_f64.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_f64.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix8_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_f64.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_init_f64.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q31.c 

C_DEPS += \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal2.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_f64.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_f64.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix8_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_f64.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_init_f64.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q31.d 

OBJS += \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal2.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_f64.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_f64.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix8_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_f64.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_init_f64.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q31.o 

OBJS__QUOTED += \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_bitreversal.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_bitreversal2.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_f64.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_init_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_init_f64.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_init_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_init_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix2_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix2_init_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix2_init_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix2_init_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix2_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix2_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix4_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix4_init_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix4_init_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix4_init_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix4_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix4_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix8_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_dct4_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_dct4_init_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_dct4_init_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_dct4_init_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_dct4_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_dct4_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_fast_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_fast_f64.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_fast_init_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_fast_init_f64.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_init_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_init_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_init_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_q31.o" 

C_DEPS__QUOTED += \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_bitreversal.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_bitreversal2.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_f64.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_init_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_init_f64.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_init_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_init_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix2_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix2_init_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix2_init_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix2_init_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix2_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix2_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix4_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix4_init_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix4_init_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix4_init_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix4_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix4_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_cfft_radix8_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_dct4_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_dct4_init_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_dct4_init_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_dct4_init_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_dct4_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_dct4_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_fast_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_fast_f64.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_fast_init_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_fast_init_f64.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_init_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_init_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_init_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\TransformFunctions\arm_rfft_q31.d" 

C_SRCS__QUOTED += \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_bitreversal2.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_f64.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_f64.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_init_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_init_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix2_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_init_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix4_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_cfft_radix8_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_init_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_dct4_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_f64.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_init_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_fast_init_f64.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_init_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/TransformFunctions/arm_rfft_q31.c" 


