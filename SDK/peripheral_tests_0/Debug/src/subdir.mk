################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/my_lcd.c \
../src/my_lcd_selftest.c \
../src/my_plb_rgb_leds.c \
../src/my_plb_rgb_leds_selftest.c \
../src/teclado.c \
../src/teclado_selftest.c \
../src/testperiph.c \
../src/xbram_example.c 

LD_SRCS += \
../src/lscript.ld 

OBJS += \
./src/my_lcd.o \
./src/my_lcd_selftest.o \
./src/my_plb_rgb_leds.o \
./src/my_plb_rgb_leds_selftest.o \
./src/teclado.o \
./src/teclado_selftest.o \
./src/testperiph.o \
./src/xbram_example.o 

C_DEPS += \
./src/my_lcd.d \
./src/my_lcd_selftest.d \
./src/my_plb_rgb_leds.d \
./src/my_plb_rgb_leds_selftest.d \
./src/teclado.d \
./src/teclado_selftest.d \
./src/testperiph.d \
./src/xbram_example.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: MicroBlaze gcc compiler
	mb-gcc -Wall -O0 -g3 -c -fmessage-length=0 -Wl,--no-relax -I../../peripheral_tests_bsp_0/microblaze_0/include -mxl-pattern-compare -mcpu=v8.30.a -mno-xl-soft-mul -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo Finished building: $<
	@echo ' '


