//============================================================================
// Name        : Restaurante.cpp
// Author      : profesores de la asignatura EDi
// Version     : curso 14/15
// Copyright   : Your copyright notice
// Description : Implementación de la clase visitante
//============================================================================

#include "Visitante.h"

Visitante::Visitante() {

	comensales = 1;
	numEleccionRestaurante = -1;
	nombre = "desconocido";
	apellidos = "desconocido";
	lugarOrigen = "desconocido";
	preferenciaRestaurantes = new PreferenciaRestaurantes();
}

Visitante::Visitante(string nombre, string apellidos, string poblacion,
		int comensales) {

	this->nombre = nombre;
	this->apellidos = apellidos;
	lugarOrigen = poblacion;
	this->comensales = comensales;
	preferenciaRestaurantes = new PreferenciaRestaurantes();
	numEleccionRestaurante = -1;
}

void Visitante::aniadirSolicitud(string nombreRes) {

	preferenciaRestaurantes->insertarRestaurante(nombreRes);
}

Visitante::~Visitante() {

	delete preferenciaRestaurantes;
}

string Visitante::getNombre() {

	return nombre;
}

int Visitante::getComensales() {

	return comensales;
}

void Visitante::mostrarVisitanteYRestaurantes() {

	{

		cout << nombre << " " << apellidos << endl;
		cout << "Con " << comensales << " comensales" << endl;
		cout << "Procedente de " << lugarOrigen << endl;
		cout << "Ha elegido los siguientes restaurantes:" << endl;

		string restaurante;

		while (!preferenciaRestaurantes->vaciaPpal()) {

			restaurante = preferenciaRestaurantes->sacarRestaurante();
			cout << restaurante << endl;
		}

		preferenciaRestaurantes->restaurarCola();
	}
}

bool Visitante::extraerRestaurante(string& restaurante) {

	numEleccionRestaurante++;

	if (!preferenciaRestaurantes->vaciaPpal()) {

		restaurante = preferenciaRestaurantes->sacarRestaurante();

		return true;
	}

	else {

		return false;
	}
}

void Visitante::mostrarCorto() {

	cout << nombre << " " << apellidos << endl;
}

bool Visitante::comprobarComensal(string nombreComensal, string apellidoComensal) {

	return nombre == nombreComensal && apellidos == apellidoComensal;
}

void Visitante::notificarSitioNoEncontrado() {

	preferenciaRestaurantes->restaurarCola();
	numEleccionRestaurante = 0;
}

string Visitante::getApellidos() {

	return apellidos;
}

bool Visitante::buscarRestaurante(string nombreRestaurante) {

	string aux;
	bool encontrado = false;

	while (!preferenciaRestaurantes->vaciaPpal()) {

		aux = preferenciaRestaurantes->sacarRestaurante();

		if (!encontrado) {

			numEleccionRestaurante++;
		}

		if (nombreRestaurante == aux) {

			encontrado = true;;
		}
	}

	preferenciaRestaurantes->restaurarCola();

	if (!encontrado) {

		numEleccionRestaurante = 0;
	}

	return encontrado;

}

string Visitante::getCiudad() {

	return lugarOrigen;
}

int Visitante::getNumEleccion() {

	return numEleccionRestaurante;
}
