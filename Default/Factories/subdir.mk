################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Factories/LightFactory.cpp \
../Factories/MaterialFactory.cpp \
../Factories/ObjectFactory.cpp \
../Factories/SceneFactory.cpp \
../Factories/SphereFactory.cpp 

OBJS += \
./Factories/LightFactory.o \
./Factories/MaterialFactory.o \
./Factories/ObjectFactory.o \
./Factories/SceneFactory.o \
./Factories/SphereFactory.o 

CPP_DEPS += \
./Factories/LightFactory.d \
./Factories/MaterialFactory.d \
./Factories/ObjectFactory.d \
./Factories/SceneFactory.d \
./Factories/SphereFactory.d 


# Each subdirectory must supply rules for building sources it contributes
Factories/%.o: ../Factories/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/solarius/Developpement/raytracer/Materials" -I"/home/solarius/Developpement/raytracer/Objects" -I"/home/solarius/Developpement/raytracer/Factories" -I"/home/solarius/Developpement/raytracer" -O2 -g -Wall -Werror -c -fmessage-length=0 -Wextra -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


