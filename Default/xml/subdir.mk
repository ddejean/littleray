################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../xml/tinystr.cpp \
../xml/tinyxml.cpp \
../xml/tinyxmlerror.cpp \
../xml/tinyxmlparser.cpp 

OBJS += \
./xml/tinystr.o \
./xml/tinyxml.o \
./xml/tinyxmlerror.o \
./xml/tinyxmlparser.o 

CPP_DEPS += \
./xml/tinystr.d \
./xml/tinyxml.d \
./xml/tinyxmlerror.d \
./xml/tinyxmlparser.d 


# Each subdirectory must supply rules for building sources it contributes
xml/%.o: ../xml/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/solarius/Developpement/raytracer/Materials" -I"/home/solarius/Developpement/raytracer/Objects" -I"/home/solarius/Developpement/raytracer/Factories" -I"/home/solarius/Developpement/raytracer" -O2 -g -Wall -Werror -c -fmessage-length=0 -Wextra -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


