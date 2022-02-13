################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Create_test_catalog.cpp \
../src/File_statistic.cpp \
../src/lines_counter.cpp 

CPP_DEPS += \
./src/Create_test_catalog.d \
./src/File_statistic.d \
./src/lines_counter.d 

OBJS += \
./src/Create_test_catalog.o \
./src/File_statistic.o \
./src/lines_counter.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -std=c++17 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Create_test_catalog.d ./src/Create_test_catalog.o ./src/File_statistic.d ./src/File_statistic.o ./src/lines_counter.d ./src/lines_counter.o

.PHONY: clean-src

