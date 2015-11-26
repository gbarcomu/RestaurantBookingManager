/*
 * EncapsuladoRestaurantesPrueba.h
 *
 *  Created on: 22 May 2015
 *      Author: guillermo
 */

#ifndef ENCAPSULADORESTAURANTESPRUEBA_H_
#define ENCAPSULADORESTAURANTESPRUEBA_H_

#include<iostream>
#include "Restaurante.h"
#include "EncapsuladoRestaurantes.h"

class EncapsuladoRestaurantesPrueba {

private:

	EncapsuladoRestaurantes *encapsuladoRestaurantes;

public:

	EncapsuladoRestaurantesPrueba();

	void Ejecucion();

	~EncapsuladoRestaurantesPrueba();
};

#endif /* ENCAPSULADORESTAURANTESPRUEBA_H_ */
