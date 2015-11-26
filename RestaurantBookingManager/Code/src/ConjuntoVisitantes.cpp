/*
 * ConjuntoVisitantes.cpp
 *
 *  Created on: 8/4/2015
 *      Author: guille
 */

#include "ConjuntoVisitantes.h"

ConjuntoVisitantes::ConjuntoVisitantes() {

	visitantes = new ListaPI<Visitante*>();

	visitantesNoServidos = new ListaPI<Visitante*>();
}

void ConjuntoVisitantes::insertar(Visitante* visitante) {

	visitantes->insertar(visitante);
	visitantes->avanzar();
}

bool ConjuntoVisitantes::consultar(string nombre, string apellidos,
		Visitante *&visitante1) {

	visitantes->moverInicio();
	bool encontrado = false;
	Visitante *visitante;
	string nombreAux, apellidoAux;

	while (!encontrado and !visitantes->finLista()) {

		visitantes->consultar(visitante);
		nombreAux = visitante->getNombre();
		apellidoAux = visitante->getApellidos();

		if (nombreAux == nombre && apellidoAux == apellidos) {

			encontrado = true;
			visitante1 = visitante;
		}

		visitantes->avanzar();
	}

	if (!encontrado) {

		cout << "Visitante no encontrado." << endl;
	}

	return encontrado;
}

bool ConjuntoVisitantes::extraerVisitante(Visitante *&visitante) {

	visitantes->moverInicio();

	if (!visitantes->estaVacia()) {

		visitantes->consultar(visitante);
		visitantes->borrar();

		return true;
	}

	else {

		return false;
	}
}

void ConjuntoVisitantes::insertarEnNoServidos(Visitante* visitante) {

	visitantesNoServidos->insertar(visitante);
	visitantesNoServidos->avanzar();
}

int ConjuntoVisitantes::procesarValoracion(Visitante* visitante) {

	string nombre = visitante->getNombre();
	float valoracion = GenAleatorios::generarNumero(10);
	visitante->mostrarCorto();
	cout << "El sr/sra: " << nombre << ", otorga un " << valoracion << endl;

	return valoracion;
}

void ConjuntoVisitantes::mostrarNoServidos() {

	if (!visitantesNoServidos->estaVacia()) {

		Visitante *visitante;

		visitantesNoServidos->moverInicio();

		while (!visitantesNoServidos->finLista()) {

			visitantesNoServidos->consultar(visitante);
			visitante->mostrarCorto();
			visitantesNoServidos->avanzar();
		}
	}
}

void ConjuntoVisitantes::restaurarDeNoServidos() {

	visitantesNoServidos->moverInicio();
	Visitante *visitante;

	while (!visitantesNoServidos->estaVacia()) {

		visitantesNoServidos->consultar(visitante);
		visitantes->insertar(visitante);
		visitantes->avanzar();
		visitantesNoServidos->borrar();
	}
}

ConjuntoVisitantes::~ConjuntoVisitantes() {

	ofstream fsal;
	Visitante *visitante;

	fsal.open("visitantesnoatendidos.log");

	visitantesNoServidos->moverInicio();

	while (!visitantesNoServidos->estaVacia()) {

		visitantesNoServidos->consultar(visitante);

		fsal << visitante->getNombre() << visitante->getApellidos() << '#';
		fsal << visitante->getCiudad() << '#';
		fsal << visitante->getComensales() << endl;

		visitantesNoServidos->borrar();
		delete visitante; // borramos los visitantes no servidos
	}

	fsal.close();

	delete visitantes;
	delete visitantesNoServidos;
}

