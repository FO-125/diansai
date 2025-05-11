################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Source/source/ti/motor_control_pmsm_foc/common_modules/hal/LP_MSPM0Gx5xx/gateDriverInterface/LP_MSPM0G3507/source/%.o: ../Source/source/ti/motor_control_pmsm_foc/common_modules/hal/LP_MSPM0Gx5xx/gateDriverInterface/LP_MSPM0G3507/source/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/APP/TI/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/28042/workspace_ccstheia/Car_LP_MSPM0G3507_nortos_ticlang" -I"C:/Users/28042/workspace_ccstheia/Car_LP_MSPM0G3507_nortos_ticlang/Driver" -I"C:/Users/28042/workspace_ccstheia/Car_LP_MSPM0G3507_nortos_ticlang/Debug" -I"D:/APP/TI/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"D:/APP/TI/mspm0_sdk_2_04_00_06/source" -gdwarf-3 -MMD -MP -MF"Source/source/ti/motor_control_pmsm_foc/common_modules/hal/LP_MSPM0Gx5xx/gateDriverInterface/LP_MSPM0G3507/source/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


