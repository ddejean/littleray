################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Display.cpp \
../Light.cpp \
../Pixel.cpp \
../Point.cpp \
../Ray.cpp \
../Scene.cpp \
../Vector.cpp \
../raytracer.cpp 

OBJS += \
./Display.o \
./Light.o \
./Pixel.o \
./Point.o \
./Ray.o \
./Scene.o \
./Vector.o \
./raytracer.o 

CPP_DEPS += \
./Display.d \
./Light.d \
./Pixel.d \
./Point.d \
./Ray.d \
./Scene.d \
./Vector.d \
./raytracer.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/solarius/Developpement/raytracer/Materials" -I"/home/solarius/Developpement/raytracer/Objects" -I"/home/solarius/Developpement/raytracer/Factories" -I"/home/solarius/Developpement/raytracer" -O2 -g -Wall -Werror -c -fmessage-length=0 -Wextra -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


