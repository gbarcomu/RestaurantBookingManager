/*
 * RestaurantePrueba.h
 *
 *  Created on: 25 May 2015
 *      Author: guillermo
 */

#ifndef RESTAURANTEPRUEBA_H_
#define RESTAURANTEPRUEBA_H_

#include "Restaurante.h"
#include "Visitante.h"

namespace std {

class RestaurantePrueba {

private:

	Restaurante *restaurante;

public:
	RestaurantePrueba();

	void Ejecutar();

	~RestaurantePrueba();
};

} /* namespace std */

#endif /* RESTAURANTEPRUEBA_H_ */
