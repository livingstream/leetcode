################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Edit\ Distance.cpp 

OBJS += \
./src/Edit\ Distance.o 

CPP_DEPS += \
./src/Edit\ Distance.d 


# Each subdirectory must supply rules for building sources it contributes
src/Edit\ Distance.o: ../src/Edit\ Distance.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Edit Distance.d" -MT"src/Edit\ Distance.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


