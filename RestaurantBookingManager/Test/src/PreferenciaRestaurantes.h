/*
 * PreferenciaRestaurantes.h
 *
 *  Created on: 27/4/2015
 *      Author: guille
 */

#ifndef SRC_PREFERENCIARESTAURANTES_H_
#define SRC_PREFERENCIARESTAURANTES_H_

#include <iostream>
#include "cola.h"

using namespace std;

class PreferenciaRestaurantes {

private:

	Cola<string> *colaPrincipal;
	Cola<string> *colaAuxiliar;

public:

	/*
	 * Metodo que inserta un dato en la cola principal
	 * Pre = La instancia debe estar creada
	 * Post= Añade un elemento a la cola principal
	 * Complejidad O(1)
	 */
	void insertarRestaurante(string dato);

	/*
	 * Metodo que deevuelve un restaurante y lo inserta en la cola auxiliar
	 * Pre = La instancia debe estar creada
	 * Post= Retorna un restaurante de la cola principal, queda almacenado en
	 * la auxiliar
	 * Complejidad O(1)
	 */
	string sacarRestaurante();

	/*
	 * Metodo que comprueba si la cola principal esta vacia
	 * Pre = La instancia debe estar creada
	 * Post= Retorna true o false en funcion del estado de la cola
	 * Complejidad O(1)
	 */
	bool vaciaPpal();

	/*
	 * Metodo que vuelca la cola auxiliar en la principal
	 * Pre = La instancia debe estar creada, es conveniente que la cola
	 * principal este vacia
	 * Post= Vacia la cola auxiliar y manda los elementos a la principal
	 * en el mismo orden
	 * Complejidad O(n)
	 */
	void restaurarCola();

	/*
	 * Constructor por defecto
	 * Pre =
	 * Post= Crea las colas principal y auxiliar
	 * Complejidad O(1)
	 */
	PreferenciaRestaurantes();

	/*
	 * Destructor
	 * Pre = La instancia debe estar creada
	 * Post= Elimina las colas principal y auxiliar
	 * Complejidad O(1)
	 */
	~PreferenciaRestaurantes();
};

#endif /* SRC_PREFERENCIARESTAURANTES_H_ */
