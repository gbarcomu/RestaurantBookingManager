/*
 * RestaurantePrueba.cpp
 *
 *  Created on: 25 May 2015
 *      Author: guillermo
 */

#include "RestaurantePrueba.h"

namespace std {

RestaurantePrueba::RestaurantePrueba() {

	restaurante = new Restaurante("nombreRest","calleCalle",1,10,"123");
}

void RestaurantePrueba::Ejecutar() {

	Visitante *v;

	v = new Visitante("aaa","aaaa"," ", 2);
	restaurante->hacerReserva(v);
	cout << "Aparece el cliente" << endl;
	restaurante->mostrar();

	restaurante->extraerCliente("aaa","aaaa");
	restaurante->mostrar();
	cout << "Ya no aparece" << endl;
}

RestaurantePrueba::~RestaurantePrueba() {

	delete restaurante;
}

} /* namespace std */
