/*
 * EncapsuladoRestaurantesPrueba.cpp
 *
 *  Created on: 22 May 2015
 *      Author: guillermo
 */

#include "EncapsuladoRestaurantesPrueba.h"

EncapsuladoRestaurantesPrueba::EncapsuladoRestaurantesPrueba() {

	encapsuladoRestaurantes = new EncapsuladoRestaurantes();
}

void EncapsuladoRestaurantesPrueba::Ejecucion() {

	Restaurante *rest;

	rest = new Restaurante("ddd", " ", 0, 0, " ");
	encapsuladoRestaurantes->insertarRestaurante(rest);

	rest = new Restaurante("ccc", " ", 0, 0, " ");
	encapsuladoRestaurantes->insertarRestaurante(rest);

	rest = new Restaurante("bbb", " ", 0, 0, " ");
	encapsuladoRestaurantes->insertarRestaurante(rest);

	rest = new Restaurante("aaa", " ", 0, 0, " ");
	encapsuladoRestaurantes->insertarRestaurante(rest);

	rest = new Restaurante("ggg", " ", 0, 0, " ");
	encapsuladoRestaurantes->insertarRestaurante(rest);

	rest = new Restaurante("eee", " ", 0, 0, " ");
	encapsuladoRestaurantes->insertarRestaurante(rest);

	rest = new Restaurante("fff", " ", 0, 0, " ");
	encapsuladoRestaurantes->insertarRestaurante(rest);

	cout << endl;
	encapsuladoRestaurantes->recorridoInOrden();

	cout << endl;
	encapsuladoRestaurantes->recorridoPreOrden();

	cout << endl;
	encapsuladoRestaurantes->recorridoPostOrden();

	cout << endl;

	cout << encapsuladoRestaurantes->cuantosElementos() << endl;

	Restaurante *restaurante;

	if (encapsuladoRestaurantes->buscarPorNombre("ccc", restaurante)) {

		cout << "Encontrado" << endl;
		restaurante->mostrar();
	}

	if (!encapsuladoRestaurantes->buscarPorNombre("mmm", restaurante)) {

		cout << "No encontrado" << endl;
	}

	rest = new Restaurante("aab", " ", 0, 0, " ");
	encapsuladoRestaurantes->insertarRestaurante(rest);

	encapsuladoRestaurantes->buscarSubcadena("aa");

	cout << "Encontradas dos entradas" << endl;

	encapsuladoRestaurantes->buscarSubcadena("mm");

	cout << "No existe" << endl;

}

EncapsuladoRestaurantesPrueba::~EncapsuladoRestaurantesPrueba() {

	delete encapsuladoRestaurantes;
}

