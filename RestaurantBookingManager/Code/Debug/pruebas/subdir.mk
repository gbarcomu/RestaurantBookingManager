################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../pruebas/EncapsuladoRestaurantesPrueba.cpp 

OBJS += \
./pruebas/EncapsuladoRestaurantesPrueba.o 

CPP_DEPS += \
./pruebas/EncapsuladoRestaurantesPrueba.d 


# Each subdirectory must supply rules for building sources it contributes
pruebas/%.o: ../pruebas/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


