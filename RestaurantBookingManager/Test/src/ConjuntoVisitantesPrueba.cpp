/*
 * ConjuntoVisitantesPrueba.cpp
 *
 *  Created on: 25 May 2015
 *      Author: guillermo
 */

#include "ConjuntoVisitantesPrueba.h"

namespace std {

ConjuntoVisitantesPrueba::ConjuntoVisitantesPrueba() {

	conjuntoVisitantes = new ConjuntoVisitantes();

}

void ConjuntoVisitantesPrueba::Ejecutar() {

	Visitante *v;

	v = new Visitante("aaa","aaaa"," ",2);
	v->aniadirSolicitud("RestaurantePrueba");
	conjuntoVisitantes->insertar(v);

	v = new Visitante("bbb","bbbb"," ",2);
	v->aniadirSolicitud("RestaurantePrueba");
	conjuntoVisitantes->insertar(v);

	v = new Visitante("ccc","cccc"," ",2);
	v->aniadirSolicitud("RestaurantePrueba");
	conjuntoVisitantes->insertar(v);

	v = new Visitante("ddd","dddd"," ",2);
	v->aniadirSolicitud("RestaurantePrueba");
	conjuntoVisitantes->insertar(v);

	v = new Visitante("eee","eeee"," ",2);
	v->aniadirSolicitud("RestaurantePrueba");
	conjuntoVisitantes->insertar(v);

	if (conjuntoVisitantes->consultar("aaa","aaaa",v)) {

		cout << "Visitante encontrado" << endl;
		v->mostrarCorto();
	}

	if (!conjuntoVisitantes->consultar("mmm","mmmm",v)) {

		cout << "Visitante no encontrado" << endl;
	}

	conjuntoVisitantes->extraerVisitante(v);
	cout << "El visitante extraido es:" << endl;
	v->mostrarCorto();

	conjuntoVisitantes->insertarEnNoServidos(v);

	cout << "Ahora esta en no servidos" << endl;

	conjuntoVisitantes->mostrarNoServidos();
}

ConjuntoVisitantesPrueba::~ConjuntoVisitantesPrueba() {

	delete conjuntoVisitantes;
}

} /* namespace std */
