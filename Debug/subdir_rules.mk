################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/APP/TI/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/28042/workspace_ccstheia/Car_LP_MSPM0G3507_nortos_ticlang" -I"C:/Users/28042/workspace_ccstheia/Car_LP_MSPM0G3507_nortos_ticlang/Driver" -I"C:/Users/28042/workspace_ccstheia/Car_LP_MSPM0G3507_nortos_ticlang/Debug" -I"D:/APP/TI/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"D:/APP/TI/mspm0_sdk_2_04_00_06/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-444051729: ../empty.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"D:/APP/TI/ccs/utils/sysconfig_1.23.0/sysconfig_cli.bat" --script "C:/Users/28042/workspace_ccstheia/Car_LP_MSPM0G3507_nortos_ticlang/empty.syscfg" -o "." -s "D:/APP/TI/mspm0_sdk_2_04_00_06/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-444051729 ../empty.syscfg
device.opt: build-444051729
device.cmd.genlibs: build-444051729
ti_msp_dl_config.c: build-444051729
ti_msp_dl_config.h: build-444051729
Event.dot: build-444051729

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/APP/TI/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/28042/workspace_ccstheia/Car_LP_MSPM0G3507_nortos_ticlang" -I"C:/Users/28042/workspace_ccstheia/Car_LP_MSPM0G3507_nortos_ticlang/Driver" -I"C:/Users/28042/workspace_ccstheia/Car_LP_MSPM0G3507_nortos_ticlang/Debug" -I"D:/APP/TI/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"D:/APP/TI/mspm0_sdk_2_04_00_06/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: D:/APP/TI/mspm0_sdk_2_04_00_06/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/APP/TI/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/28042/workspace_ccstheia/Car_LP_MSPM0G3507_nortos_ticlang" -I"C:/Users/28042/workspace_ccstheia/Car_LP_MSPM0G3507_nortos_ticlang/Driver" -I"C:/Users/28042/workspace_ccstheia/Car_LP_MSPM0G3507_nortos_ticlang/Debug" -I"D:/APP/TI/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"D:/APP/TI/mspm0_sdk_2_04_00_06/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


