################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Display.cpp \
../Light.cpp \
../LightFactory.cpp \
../Material.cpp \
../MaterialFactory.cpp \
../ObjectFactory.cpp \
../Pixel.cpp \
../Point.cpp \
../Ray.cpp \
../Scene.cpp \
../SceneFactory.cpp \
../Sphere.cpp \
../SphereFactory.cpp \
../Vector.cpp \
../raytracer.cpp 

OBJS += \
./Display.o \
./Light.o \
./LightFactory.o \
./Material.o \
./MaterialFactory.o \
./ObjectFactory.o \
./Pixel.o \
./Point.o \
./Ray.o \
./Scene.o \
./SceneFactory.o \
./Sphere.o \
./SphereFactory.o \
./Vector.o \
./raytracer.o 

CPP_DEPS += \
./Display.d \
./Light.d \
./LightFactory.d \
./Material.d \
./MaterialFactory.d \
./ObjectFactory.d \
./Pixel.d \
./Point.d \
./Ray.d \
./Scene.d \
./SceneFactory.d \
./Sphere.d \
./SphereFactory.d \
./Vector.d \
./raytracer.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -Werror -c -fmessage-length=0 -Wextra -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


