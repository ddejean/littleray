################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Materials/BlinnPhongMaterial.cpp \
../Materials/Material.cpp \
../Materials/PhongMaterial.cpp 

OBJS += \
./Materials/BlinnPhongMaterial.o \
./Materials/Material.o \
./Materials/PhongMaterial.o 

CPP_DEPS += \
./Materials/BlinnPhongMaterial.d \
./Materials/Material.d \
./Materials/PhongMaterial.d 


# Each subdirectory must supply rules for building sources it contributes
Materials/%.o: ../Materials/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/solarius/Developpement/raytracer/Materials" -I"/home/solarius/Developpement/raytracer/Objects" -I"/home/solarius/Developpement/raytracer/Factories" -I"/home/solarius/Developpement/raytracer" -O2 -g -Wall -Werror -c -fmessage-length=0 -Wextra -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


