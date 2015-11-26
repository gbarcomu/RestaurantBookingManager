/*
 * VolcadoFichero.cpp
 *
 *  Created on: 24 May 2015
 *      Author: guillermo
 */

#include "VolcadoFichero.h"

namespace std {

VolcadoFichero::VolcadoFichero() {

	arbolValoracion = new Arbol<Restaurante*, CompararValoracion>();
}

void VolcadoFichero::obtenerMenor(Restaurante *&restaurante,Arbol<Restaurante*, CompararValoracion>* abb) {

	Arbol<Restaurante*, CompararValoracion>* aux;

	if (!abb->vacio()) {

		aux = abb->hijoIzq();

		if (aux != NULL) {

			obtenerMenor(restaurante,aux);
		}

		else {

			restaurante = abb->raiz();
		}
	}
}

VolcadoFichero::~VolcadoFichero() {

	delete arbolValoracion;
}

void VolcadoFichero::generarLogDiario() {

	string nombreFichero;

	nombreFichero = "gastroedi_" + getFecha() + ".log";

	fsal.open(nombreFichero.c_str());
}

void VolcadoFichero::cerrarLogDiario() {

	fsal.close();
}

void VolcadoFichero::insertarYVolcar(Restaurante* restaurante) {

	Visitante *visitante;

	fsal << restaurante->getNombre() << '#';
	fsal << restaurante->getDireccion() << '#';
	fsal << restaurante->getTenedores() << '#';
	fsal << restaurante->getTelefono() << '#';
	fsal << restaurante->getAforo() << '#';
	fsal << restaurante->getValoracion() << endl;

	while (restaurante->extraerPrimerCliente(visitante)) {

		fsal << visitante->getNombre() << '#';
		fsal << visitante->getApellidos() << '#';
		fsal << visitante->getCiudad() << '#';
		fsal << visitante->getComensales() << '#';
		fsal << visitante->getNumEleccion() << endl;

		delete visitante; // con esto eliminamos todos los visitantes que comen
	}

	arbolValoracion->insertar(restaurante);
}

string VolcadoFichero::getFecha() {

	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%d%m", &tstruct);
	return buf;
}

void VolcadoFichero::generarLogRestaurantes() {

	fsal.open("restaurantesmasvalorados.log");
	Restaurante *restaurante;

	while (!arbolValoracion->vacio()) {

		obtenerMenor(restaurante,arbolValoracion);

		fsal << restaurante->getNombre() << '#';
		fsal << restaurante->getDireccion() << '#';
		fsal << restaurante->getAforo() - restaurante->getAforoLibre() << '#';
		fsal << restaurante->getValoracion() << endl;

		arbolValoracion->borrar(restaurante);

		delete restaurante; // eliminamos todos los restaurantes;
	}

	fsal.close();
}

} /* namespace std */
