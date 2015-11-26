################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ConjuntoRestaurantes.cpp \
../src/ConjuntoVisitantes.cpp \
../src/ConjuntoVisitantesPrueba.cpp \
../src/EncapsuladoRestaurantes.cpp \
../src/EncapsuladoRestaurantesPrueba.cpp \
../src/PreferenciaRestaurantes.cpp \
../src/PruebasGastroEDI.cpp \
../src/Restaurante.cpp \
../src/RestaurantePrueba.cpp \
../src/Visitante.cpp \
../src/VolcadoFichero.cpp \
../src/genaleatorios.cpp 

OBJS += \
./src/ConjuntoRestaurantes.o \
./src/ConjuntoVisitantes.o \
./src/ConjuntoVisitantesPrueba.o \
./src/EncapsuladoRestaurantes.o \
./src/EncapsuladoRestaurantesPrueba.o \
./src/PreferenciaRestaurantes.o \
./src/PruebasGastroEDI.o \
./src/Restaurante.o \
./src/RestaurantePrueba.o \
./src/Visitante.o \
./src/VolcadoFichero.o \
./src/genaleatorios.o 

CPP_DEPS += \
./src/ConjuntoRestaurantes.d \
./src/ConjuntoVisitantes.d \
./src/ConjuntoVisitantesPrueba.d \
./src/EncapsuladoRestaurantes.d \
./src/EncapsuladoRestaurantesPrueba.d \
./src/PreferenciaRestaurantes.d \
./src/PruebasGastroEDI.d \
./src/Restaurante.d \
./src/RestaurantePrueba.d \
./src/Visitante.d \
./src/VolcadoFichero.d \
./src/genaleatorios.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


