################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2010/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Driver" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Control_Car" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Peripheral/OLED_Hardware_I2C" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Debug" -I"C:/ti/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_05_01_00/source" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Peripheral" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Peripherial/IMU660RB" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Peripherial/IMU660RB/Fusion" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1122421169: ../empty01.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs2010/ccs/utils/sysconfig_1.23.0/sysconfig_cli.bat" --script "C:/Users/28042/workspace_ccstheia/dansaichongshengban/empty01.syscfg" -o "." -s "C:/ti/mspm0_sdk_2_05_01_00/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-1122421169 ../empty01.syscfg
device.opt: build-1122421169
device.cmd.genlibs: build-1122421169
ti_msp_dl_config.c: build-1122421169
ti_msp_dl_config.h: build-1122421169
Event.dot: build-1122421169

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2010/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Driver" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Control_Car" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Peripheral/OLED_Hardware_I2C" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Debug" -I"C:/ti/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_05_01_00/source" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Peripheral" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Peripherial/IMU660RB" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Peripherial/IMU660RB/Fusion" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: C:/ti/mspm0_sdk_2_05_01_00/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2010/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Driver" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Control_Car" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Peripheral/OLED_Hardware_I2C" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Debug" -I"C:/ti/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_05_01_00/source" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Peripheral" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Peripherial/IMU660RB" -I"C:/Users/28042/workspace_ccstheia/dansaichongshengban/Peripherial/IMU660RB/Fusion" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


