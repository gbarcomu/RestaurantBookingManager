/*
 * CompararValoracion.h
 *
 *  Created on: 24 May 2015
 *      Author: guillermo
 */

#ifndef COMPARARVALORACION_H_
#define COMPARARVALORACION_H_

#include "Restaurante.h"

class CompararValoracion {

public:

	int operator()(const Restaurante *r1, const Restaurante *r2) const {

		if (r1->getValoracion() == r2->getValoracion())
			return r1->getNombre() > r2->getNombre();
		else if (r1->getValoracion() > r2->getValoracion())
			return -1;
		else
			return 1;

	}
};



#endif /* COMPARARVALORACION_H_ */
