/*
 * Comparar.h
 *
 *  Created on: 22 May 2015
 *      Author: guillermo
 */

#ifndef COMPARAR_H_
#define COMPARAR_H_

#include "Restaurante.h"

class Comparar {

public:

	int operator()(const Restaurante *r1, const Restaurante *r2) const {

		if (r1->getNombre() == r2->getNombre())
			return 0;
		else if (r1->getNombre() < r2->getNombre())
			return -1;
		else
			return 1;

	}
};

#endif /* COMPARAR_H_ */
