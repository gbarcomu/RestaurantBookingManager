/*
 * ConjuntoVisitantesPrueba.h
 *
 *  Created on: 25 May 2015
 *      Author: guillermo
 */

#ifndef CONJUNTOVISITANTESPRUEBA_H_
#define CONJUNTOVISITANTESPRUEBA_H_

#include "Visitante.h"
#include "ConjuntoVisitantes.h"

namespace std {

class ConjuntoVisitantesPrueba {

private:

	ConjuntoVisitantes *conjuntoVisitantes;

public:
	ConjuntoVisitantesPrueba();

	void Ejecutar();

	~ConjuntoVisitantesPrueba();
};

} /* namespace std */

#endif /* CONJUNTOVISITANTESPRUEBA_H_ */
