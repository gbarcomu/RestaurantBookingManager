/*
 * PreferenciaRestaurantes.cpp
 *
 *  Created on: 27/4/2015
 *      Author: guille
 */

#include "PreferenciaRestaurantes.h"

PreferenciaRestaurantes::PreferenciaRestaurantes() {

	colaPrincipal = new Cola<string>();
	colaAuxiliar = new Cola<string>();
}

void PreferenciaRestaurantes::insertarRestaurante(string dato) {

	colaPrincipal->encolar(dato);
}

string PreferenciaRestaurantes::sacarRestaurante() {

	string auxiliar;
	colaPrincipal->primero(auxiliar);
	colaPrincipal->desencolar();
	colaAuxiliar->encolar(auxiliar);

	return auxiliar;
}

void PreferenciaRestaurantes::restaurarCola() {

	string auxiliar;

	while (!colaAuxiliar->vacia()) {

		colaAuxiliar->primero(auxiliar);
		colaAuxiliar->desencolar();
		colaPrincipal->encolar(auxiliar);
	}
}

bool PreferenciaRestaurantes::vaciaPpal() {

	return colaPrincipal->vacia();
}

PreferenciaRestaurantes::~PreferenciaRestaurantes() {

	delete colaAuxiliar;
	delete colaPrincipal;
}

