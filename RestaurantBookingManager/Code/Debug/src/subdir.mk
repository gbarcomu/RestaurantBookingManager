################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ConjuntoRestaurantes.cpp \
../src/ConjuntoVisitantes.cpp \
../src/EncapsuladoRestaurantes.cpp \
../src/GastroEDI.cpp \
../src/PreferenciaRestaurantes.cpp \
../src/Restaurante.cpp \
../src/Visitante.cpp \
../src/VolcadoFichero.cpp \
../src/genaleatorios.cpp \
../src/ui.cpp 

OBJS += \
./src/ConjuntoRestaurantes.o \
./src/ConjuntoVisitantes.o \
./src/EncapsuladoRestaurantes.o \
./src/GastroEDI.o \
./src/PreferenciaRestaurantes.o \
./src/Restaurante.o \
./src/Visitante.o \
./src/VolcadoFichero.o \
./src/genaleatorios.o \
./src/ui.o 

CPP_DEPS += \
./src/ConjuntoRestaurantes.d \
./src/ConjuntoVisitantes.d \
./src/EncapsuladoRestaurantes.d \
./src/GastroEDI.d \
./src/PreferenciaRestaurantes.d \
./src/Restaurante.d \
./src/Visitante.d \
./src/VolcadoFichero.d \
./src/genaleatorios.d \
./src/ui.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


