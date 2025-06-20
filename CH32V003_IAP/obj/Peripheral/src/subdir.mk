################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_adc.c \
c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_dbgmcu.c \
c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_dma.c \
c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_exti.c \
c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_flash.c \
c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_gpio.c \
c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_i2c.c \
c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_iwdg.c \
c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_misc.c \
c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_opa.c \
c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_pwr.c \
c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_rcc.c \
c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_spi.c \
c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_tim.c \
c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_usart.c \
c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_wwdg.c 

C_DEPS += \
./Peripheral/src/ch32v00x_adc.d \
./Peripheral/src/ch32v00x_dbgmcu.d \
./Peripheral/src/ch32v00x_dma.d \
./Peripheral/src/ch32v00x_exti.d \
./Peripheral/src/ch32v00x_flash.d \
./Peripheral/src/ch32v00x_gpio.d \
./Peripheral/src/ch32v00x_i2c.d \
./Peripheral/src/ch32v00x_iwdg.d \
./Peripheral/src/ch32v00x_misc.d \
./Peripheral/src/ch32v00x_opa.d \
./Peripheral/src/ch32v00x_pwr.d \
./Peripheral/src/ch32v00x_rcc.d \
./Peripheral/src/ch32v00x_spi.d \
./Peripheral/src/ch32v00x_tim.d \
./Peripheral/src/ch32v00x_usart.d \
./Peripheral/src/ch32v00x_wwdg.d 

OBJS += \
./Peripheral/src/ch32v00x_adc.o \
./Peripheral/src/ch32v00x_dbgmcu.o \
./Peripheral/src/ch32v00x_dma.o \
./Peripheral/src/ch32v00x_exti.o \
./Peripheral/src/ch32v00x_flash.o \
./Peripheral/src/ch32v00x_gpio.o \
./Peripheral/src/ch32v00x_i2c.o \
./Peripheral/src/ch32v00x_iwdg.o \
./Peripheral/src/ch32v00x_misc.o \
./Peripheral/src/ch32v00x_opa.o \
./Peripheral/src/ch32v00x_pwr.o \
./Peripheral/src/ch32v00x_rcc.o \
./Peripheral/src/ch32v00x_spi.o \
./Peripheral/src/ch32v00x_tim.o \
./Peripheral/src/ch32v00x_usart.o \
./Peripheral/src/ch32v00x_wwdg.o 



# Each subdirectory must supply rules for building sources it contributes
Peripheral/src/ch32v00x_adc.o: c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_adc.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Core" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/USART_IAP/CH32V003_IAP/User" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v00x_dbgmcu.o: c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_dbgmcu.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Core" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/USART_IAP/CH32V003_IAP/User" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v00x_dma.o: c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_dma.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Core" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/USART_IAP/CH32V003_IAP/User" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v00x_exti.o: c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_exti.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Core" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/USART_IAP/CH32V003_IAP/User" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v00x_flash.o: c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_flash.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Core" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/USART_IAP/CH32V003_IAP/User" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v00x_gpio.o: c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_gpio.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Core" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/USART_IAP/CH32V003_IAP/User" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v00x_i2c.o: c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_i2c.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Core" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/USART_IAP/CH32V003_IAP/User" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v00x_iwdg.o: c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_iwdg.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Core" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/USART_IAP/CH32V003_IAP/User" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v00x_misc.o: c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_misc.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Core" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/USART_IAP/CH32V003_IAP/User" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v00x_opa.o: c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_opa.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Core" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/USART_IAP/CH32V003_IAP/User" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v00x_pwr.o: c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_pwr.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Core" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/USART_IAP/CH32V003_IAP/User" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v00x_rcc.o: c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_rcc.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Core" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/USART_IAP/CH32V003_IAP/User" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v00x_spi.o: c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_spi.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Core" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/USART_IAP/CH32V003_IAP/User" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v00x_tim.o: c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_tim.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Core" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/USART_IAP/CH32V003_IAP/User" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v00x_usart.o: c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_usart.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Core" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/USART_IAP/CH32V003_IAP/User" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
Peripheral/src/ch32v00x_wwdg.o: c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/src/ch32v00x_wwdg.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Debug" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Core" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/USART_IAP/CH32V003_IAP/User" -I"c:/Users/HoangAnh/Downloads/CH32V003EVT/EVT/EXAM/SRC/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

