/*
 * EncapsuladoRestaurantes.cpp
 *
 *  Created on: 22 May 2015
 *      Author: guillermo
 */

#include "EncapsuladoRestaurantes.h"

EncapsuladoRestaurantes::EncapsuladoRestaurantes() {

	arbolRestaurante = new Arbol<Restaurante*, Comparar>();
}

void EncapsuladoRestaurantes::recorridoInOrden() {

	if (!arbolRestaurante->vacio()) {

		this->inOrden(arbolRestaurante);
	}
}

void EncapsuladoRestaurantes::recorridoPreOrden() {

	if (!arbolRestaurante->vacio()) {

		cout << endl << "Recorrido PRE orden." << endl;

		this->preOrden(arbolRestaurante);
	}
}

void EncapsuladoRestaurantes::recorridoPostOrden() {

	if (!arbolRestaurante->vacio()) {

		cout << endl << "Recorrido POST orden." << endl;

		this->postOrden(arbolRestaurante);
	}
}

int EncapsuladoRestaurantes::cuantosElementos() {

	return this->cuantos(arbolRestaurante);
}

bool EncapsuladoRestaurantes::buscarPorNombre(string nombre,
		Restaurante *&restaurante) {

	return this->buscar(nombre, arbolRestaurante, restaurante);
}

void EncapsuladoRestaurantes::inOrden(Arbol<Restaurante*, Comparar>* abb) {

	Arbol<Restaurante*, Comparar>* aux;

	if (!abb->vacio()) {

		aux = abb->hijoIzq();

		if (aux != NULL) {

			inOrden(aux);
		}

		abb->raiz()->mostrar();

		aux = abb->hijoDer();

		if (aux != NULL) {

			inOrden(aux);
		}
	}
}

void EncapsuladoRestaurantes::preOrden(Arbol<Restaurante*, Comparar>* abb) {

	Arbol<Restaurante*, Comparar>* aux;

	if (!abb->vacio()) {

		abb->raiz()->mostrar();

		aux = abb->hijoIzq();

		if (aux != NULL) {

			preOrden(aux);
		}

		aux = abb->hijoDer();

		if (aux != NULL) {

			preOrden(aux);
		}
	}
}

void EncapsuladoRestaurantes::postOrden(Arbol<Restaurante*, Comparar>* abb) {

	Arbol<Restaurante*, Comparar>* aux;

	if (!abb->vacio()) {

		aux = abb->hijoIzq();

		if (aux != NULL) {

			postOrden(aux);
		}

		aux = abb->hijoDer();

		if (aux != NULL) {

			postOrden(aux);
		}

		abb->raiz()->mostrar();
	}
}

int EncapsuladoRestaurantes::cuantos(Arbol<Restaurante*, Comparar>* abb) {

	Arbol<Restaurante*, Comparar>* aux;

	int dcha = 0;
	int izqda = 0;

	if (!abb->vacio()) {

		aux = abb->hijoIzq();

		if (aux != NULL) {

			izqda = cuantos(aux);
		}

		aux = abb->hijoDer();

		if (aux != NULL) {

			dcha = cuantos(aux);
		}

		return 1 + izqda + dcha;
	}

	return 0;
}

//TODO Preguntar lunes si tengo que sacar esto de aqui

bool EncapsuladoRestaurantes::buscar(string nombre,
		Arbol<Restaurante*, Comparar>* abb, Restaurante *&restaurante) {

	bool encontrado = false;

	Arbol<Restaurante*, Comparar>* aux;
	string nombreAux;

	if (!abb->vacio()) {

		nombreAux = abb->raiz()->getNombre();

		if (nombreAux == nombre) {

			encontrado = true;
			restaurante = abb->raiz();
		}

		else if (nombre < nombreAux) {

			aux = abb->hijoIzq();

			if (aux != NULL) {

				encontrado = buscar(nombre, aux, restaurante);
			}

			else {

				encontrado = false;
			}

		}

		else {

			aux = abb->hijoDer();

			if (aux != NULL) {

				encontrado = buscar(nombre, aux, restaurante);
			}

			else {

				encontrado = false;
			}
		}
	}

	else {

		encontrado = false;
	}

	return encontrado;
}

void EncapsuladoRestaurantes::insertarRestaurante(Restaurante *restaurante) {

	arbolRestaurante->insertar(restaurante);
}

bool EncapsuladoRestaurantes::vacio() {

	return arbolRestaurante->vacio();
}

void EncapsuladoRestaurantes::subcadena(string subcad,
		Arbol<Restaurante*, Comparar>* abb) {

	bool encontrado = false;

	Arbol<Restaurante*, Comparar>* aux;
	string nombreAux;

	if (!abb->vacio()) {

		nombreAux = abb->raiz()->getNombre();

		if (compararCadenas(nombreAux, subcad)) {

			encontrado = true;
			abb->raiz()->mostrarCorto();
		}

		if (subcad < nombreAux || encontrado) {

			aux = abb->hijoIzq();

			if (aux != NULL) {

				subcadena(subcad, aux);
			}
		}

		if (subcad > nombreAux || encontrado) {

			aux = abb->hijoDer();

			if (aux != NULL) {

				subcadena(subcad, aux);
			}
		}
	}
}

bool EncapsuladoRestaurantes::compararCadenas(string cad, string subcad) {

	if (cad.length() < subcad.length()) {

		return false;
	}

	for (int i = 0; i < (int)subcad.length(); i++) {

		if (cad[i] != subcad[i]) {

			return false;
		}
	}

	return true;
}

void EncapsuladoRestaurantes::buscarSubcadena(string subcadena) {

	return this->subcadena(subcadena, arbolRestaurante);
}

bool EncapsuladoRestaurantes::devolverDatoMenor(Restaurante*& restaurante) {

	if (!arbolRestaurante->vacio()) {

		this->obtenerMenor(restaurante,arbolRestaurante);

		cout << endl;

		arbolRestaurante->borrar(restaurante);
		return true;
	}

	return false;
}

EncapsuladoRestaurantes::~EncapsuladoRestaurantes() {

	delete arbolRestaurante;
}

void EncapsuladoRestaurantes::obtenerMenor(Restaurante*& restaurante,
		Arbol<Restaurante*, Comparar>* abb) {

	Arbol<Restaurante*, Comparar>* aux;

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
