################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/creational/abstract_factory.cpp \
../src/creational/builder.cpp \
../src/creational/factory_method.cpp \
../src/creational/prototype.cpp \
../src/creational/simple_factory.cpp \
../src/creational/singleton.cpp 

OBJS += \
./src/creational/abstract_factory.o \
./src/creational/builder.o \
./src/creational/factory_method.o \
./src/creational/prototype.o \
./src/creational/simple_factory.o \
./src/creational/singleton.o 

CPP_DEPS += \
./src/creational/abstract_factory.d \
./src/creational/builder.d \
./src/creational/factory_method.d \
./src/creational/prototype.d \
./src/creational/simple_factory.d \
./src/creational/singleton.d 


# Each subdirectory must supply rules for building sources it contributes
src/creational/%.o: ../src/creational/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


