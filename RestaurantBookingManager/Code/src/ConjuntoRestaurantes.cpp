/*
 * conjuntoRestaurantes.cpp
 *
 *  Created on: 8/4/2015
 *      Author: guille
 */

#include "ConjuntoRestaurantes.h"

ConjuntoRestaurantes::ConjuntoRestaurantes() {

	restaurantes = new EncapsuladoRestaurantes;

}

void ConjuntoRestaurantes::insertar(Restaurante* restaurante) {

	restaurantes->insertarRestaurante(restaurante);
}

bool ConjuntoRestaurantes::consultar(string nombre, Restaurante *&restaurante) {

	return restaurantes->buscarPorNombre(nombre, restaurante);
}

bool ConjuntoRestaurantes::visitanteCabeEnRestaurante(Restaurante *restaurante,
		int comensales) {

	string nombreAux;
	bool cabe = false;

	if (restaurante->getAforoLibre() >= comensales) {

		cabe = true;
	}

	return cabe;
}

bool ConjuntoRestaurantes::procesarVisitante(Visitante* visitante,
		string nombreRestaurante) {

	Restaurante *restaurante;

	if (consultar(nombreRestaurante, restaurante)) {

		if (visitanteCabeEnRestaurante(restaurante,
				visitante->getComensales())) {

			restaurante->reajustarComensales(-visitante->getComensales());

			restaurante->hacerReserva(visitante);

			return true;
		}
	}

	return false;
}

void ConjuntoRestaurantes::buscarRestaurante(string subCadena) {

	restaurantes->buscarSubcadena(subCadena);
}

bool ConjuntoRestaurantes::procesarValoracion(Restaurante *&restaurante) {

	if (restaurantes->devolverDatoMenor(restaurante)) {

		cout << "Se procede a valorar el restaurante: " << restaurante->getNombre() << endl;
		return true;
	}

	return false;
}

void ConjuntoRestaurantes::mostrarDistribucion() {

	restaurantes->recorridoInOrden();
}

ConjuntoRestaurantes::~ConjuntoRestaurantes() {

	delete restaurantes;
}

bool ConjuntoRestaurantes::anularReserva(string nombreRestaurante,
		string nombreComensal, string apellidosComensal) {

	Restaurante *restaurante;

	if (this->consultar(nombreRestaurante, restaurante) &&
			restaurante->extraerCliente(nombreComensal, apellidosComensal)) {

		return true;
	}

	return false;
}
