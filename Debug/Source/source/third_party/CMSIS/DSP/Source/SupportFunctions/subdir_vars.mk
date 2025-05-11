################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_barycenter_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_bitonic_sort_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_bubble_sort_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_copy_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_copy_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_copy_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_copy_q7.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_fill_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_fill_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_fill_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_fill_q7.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q7.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_heap_sort_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_insertion_sort_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_merge_sort_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_merge_sort_init_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_float.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q7.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_float.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q7.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_float.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q15.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q31.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_quick_sort_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_selection_sort_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_sort_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_sort_init_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_spline_interp_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_spline_interp_init_f32.c \
../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_weighted_sum_f32.c 

C_DEPS += \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_barycenter_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_bitonic_sort_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_bubble_sort_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_copy_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_copy_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_copy_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_copy_q7.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_fill_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_fill_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_fill_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_fill_q7.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q7.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_heap_sort_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_insertion_sort_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_merge_sort_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_merge_sort_init_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_float.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q7.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_float.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q7.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_float.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q15.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q31.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_quick_sort_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_selection_sort_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_sort_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_sort_init_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_spline_interp_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_spline_interp_init_f32.d \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_weighted_sum_f32.d 

OBJS += \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_barycenter_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_bitonic_sort_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_bubble_sort_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_copy_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_copy_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_copy_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_copy_q7.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_fill_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_fill_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_fill_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_fill_q7.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q7.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_heap_sort_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_insertion_sort_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_merge_sort_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_merge_sort_init_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_float.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q7.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_float.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q7.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_float.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q15.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q31.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_quick_sort_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_selection_sort_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_sort_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_sort_init_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_spline_interp_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_spline_interp_init_f32.o \
./Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_weighted_sum_f32.o 

OBJS__QUOTED += \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_barycenter_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_bitonic_sort_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_bubble_sort_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_copy_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_copy_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_copy_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_copy_q7.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_fill_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_fill_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_fill_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_fill_q7.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_float_to_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_float_to_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_float_to_q7.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_heap_sort_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_insertion_sort_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_merge_sort_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_merge_sort_init_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_q15_to_float.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_q15_to_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_q15_to_q7.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_q31_to_float.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_q31_to_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_q31_to_q7.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_q7_to_float.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_q7_to_q15.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_q7_to_q31.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_quick_sort_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_selection_sort_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_sort_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_sort_init_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_spline_interp_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_spline_interp_init_f32.o" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_weighted_sum_f32.o" 

C_DEPS__QUOTED += \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_barycenter_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_bitonic_sort_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_bubble_sort_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_copy_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_copy_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_copy_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_copy_q7.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_fill_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_fill_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_fill_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_fill_q7.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_float_to_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_float_to_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_float_to_q7.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_heap_sort_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_insertion_sort_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_merge_sort_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_merge_sort_init_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_q15_to_float.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_q15_to_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_q15_to_q7.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_q31_to_float.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_q31_to_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_q31_to_q7.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_q7_to_float.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_q7_to_q15.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_q7_to_q31.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_quick_sort_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_selection_sort_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_sort_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_sort_init_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_spline_interp_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_spline_interp_init_f32.d" \
"Source\source\third_party\CMSIS\DSP\Source\SupportFunctions\arm_weighted_sum_f32.d" 

C_SRCS__QUOTED += \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_barycenter_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_bitonic_sort_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_bubble_sort_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_copy_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_copy_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_copy_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_copy_q7.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_fill_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_fill_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_fill_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_fill_q7.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_float_to_q7.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_heap_sort_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_insertion_sort_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_merge_sort_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_merge_sort_init_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_float.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q15_to_q7.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_float.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q31_to_q7.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_float.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q15.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_q7_to_q31.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_quick_sort_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_selection_sort_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_sort_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_sort_init_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_spline_interp_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_spline_interp_init_f32.c" \
"../Source/source/third_party/CMSIS/DSP/Source/SupportFunctions/arm_weighted_sum_f32.c" 


