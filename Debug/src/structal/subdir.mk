################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/structal/adapter.cpp \
../src/structal/bridge.cpp \
../src/structal/composite.cpp 

OBJS += \
./src/structal/adapter.o \
./src/structal/bridge.o \
./src/structal/composite.o 

CPP_DEPS += \
./src/structal/adapter.d \
./src/structal/bridge.d \
./src/structal/composite.d 


# Each subdirectory must supply rules for building sources it contributes
src/structal/%.o: ../src/structal/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


