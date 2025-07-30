################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Driver/%.o: ../Driver/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2010/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Driver" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Control_Car" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Peripheral/OLED_Hardware_I2C" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Debug" -I"C:/ti/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_05_01_00/source" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Peripheral" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Peripherial/IMU660RB" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Peripherial/IMU660RB/Fusion" -gdwarf-3 -MMD -MP -MF"Driver/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Driver/Timer.o: ../Driver/Timer.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2010/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Driver/OLED_Hardware_I2C" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Driver" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Peripheral" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Debug" -I"C:/ti/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_05_01_00/source" -gdwarf-3 -MMD -MP -MF"Driver/$(basename $(<F)).d_raw" -MT"Driver/$(basename\ $(<F)).o"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


