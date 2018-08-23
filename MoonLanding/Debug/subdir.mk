################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../driver.cpp \
../game.cpp \
../ground.cpp \
../lander.cpp \
../point.cpp \
../uiDraw.cpp \
../uiInteract.cpp \
../velocity.cpp 

OBJS += \
./driver.o \
./game.o \
./ground.o \
./lander.o \
./point.o \
./uiDraw.o \
./uiInteract.o \
./velocity.o 

CPP_DEPS += \
./driver.d \
./game.d \
./ground.d \
./lander.d \
./point.d \
./uiDraw.d \
./uiInteract.d \
./velocity.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"C:\MinGW\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


