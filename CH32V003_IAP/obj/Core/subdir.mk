################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Core/core_riscv.c 

C_DEPS += \
./Core/core_riscv.d 

OBJS += \
./Core/core_riscv.o 



# Each subdirectory must supply rules for building sources it contributes
Core/core_riscv.o: c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Core/core_riscv.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Core" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/USART_IAP/CH32V003_IAP/User" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

