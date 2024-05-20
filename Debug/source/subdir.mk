################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/FUNCTION_GENERATOR.c \
../source/GENERADOR_ADC.c \
../source/GENERADOR_DAC.c \
../source/NVIC.c \
../source/PIT.c \
../source/TERMINAL.c \
../source/UART_DRIVER.c \
../source/main.c \
../source/semihost_hardfault.c 

C_DEPS += \
./source/FUNCTION_GENERATOR.d \
./source/GENERADOR_ADC.d \
./source/GENERADOR_DAC.d \
./source/NVIC.d \
./source/PIT.d \
./source/TERMINAL.d \
./source/UART_DRIVER.d \
./source/main.d \
./source/semihost_hardfault.d 

OBJS += \
./source/FUNCTION_GENERATOR.o \
./source/GENERADOR_ADC.o \
./source/GENERADOR_DAC.o \
./source/NVIC.o \
./source/PIT.o \
./source/TERMINAL.o \
./source/UART_DRIVER.o \
./source/main.o \
./source/semihost_hardfault.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\TAE_DM\DAC\generador\board" -I"C:\TAE_DM\DAC\generador\source" -I"C:\TAE_DM\DAC\generador\utilities" -I"C:\TAE_DM\DAC\generador\drivers" -I"C:\TAE_DM\DAC\generador\device" -I"C:\TAE_DM\DAC\generador\component\serial_manager" -I"C:\TAE_DM\DAC\generador\component\lists" -I"C:\TAE_DM\DAC\generador\CMSIS" -I"C:\TAE_DM\DAC\generador\component\uart" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/FUNCTION_GENERATOR.d ./source/FUNCTION_GENERATOR.o ./source/GENERADOR_ADC.d ./source/GENERADOR_ADC.o ./source/GENERADOR_DAC.d ./source/GENERADOR_DAC.o ./source/NVIC.d ./source/NVIC.o ./source/PIT.d ./source/PIT.o ./source/TERMINAL.d ./source/TERMINAL.o ./source/UART_DRIVER.d ./source/UART_DRIVER.o ./source/main.d ./source/main.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o

.PHONY: clean-source

