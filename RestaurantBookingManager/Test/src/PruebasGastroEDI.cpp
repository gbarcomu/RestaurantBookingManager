//============================================================================
// Name        : PruebasGastroEDI.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "EncapsuladoRestaurantesPrueba.h"
#include "ConjuntoVisitantesPrueba.h"
#include "RestaurantePrueba.h"
using namespace std;

int main() {

	EncapsuladoRestaurantesPrueba *encapsuladoRestaurantesPrueba = new EncapsuladoRestaurantesPrueba();
	ConjuntoVisitantesPrueba *conjuntoVisitantesPrueba = new ConjuntoVisitantesPrueba();
	RestaurantePrueba *restaurantePrueba = new RestaurantePrueba();

	encapsuladoRestaurantesPrueba->Ejecucion();

	cout << "-----------------------------------------------" << endl;

	conjuntoVisitantesPrueba->Ejecutar();

	cout << "-----------------------------------------------" << endl;

	restaurantePrueba->Ejecutar();

	delete encapsuladoRestaurantesPrueba;
	delete conjuntoVisitantesPrueba;
	delete restaurantePrueba;

	return 0;
}
