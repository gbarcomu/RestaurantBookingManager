/*
 * VolcadoFichero.h
 *
 *  Created on: 24 May 2015
 *      Author: guillermo
 */

#ifndef VOLCADOFICHERO_H_
#define VOLCADOFICHERO_H_

#include <fstream>
#include "Restaurante.h"
#include "arbol.h"
#include "CompararValoracion.h"

namespace std {

class VolcadoFichero {

private:

	Arbol<Restaurante*, CompararValoracion> *arbolValoracion;
	ofstream fsal;

	/*
	 * Metodo recursivo que deevuelve el restaurante con valoracion mas baja
	 * Pre = La instancia debe estar creada, restaurante no apunta a nada
	 * Post= Devuelve en restaurante el restaurante con menos puntuacion
	 * y lo extrae del arbol
	 * Complejidad O(log n)
	 */
	void obtenerMenor (Restaurante *&restaurante,Arbol<Restaurante*, CompararValoracion> *abb);

	/*
	 * Metodo obtiene el dia y el mes actual
	 * Pre = La instancia debe estar creada
	 * Post= Retorna el dia y mes actual
	 * Complejidad O(1)
	 */
	string getFecha();


public:

	/*
	 * Constructor por defecto
	 * Pre =
	 * Post= Inicializa el arbol de valoraciones
	 * Complejidad O(1)
	 */
	VolcadoFichero();

	/*
	 * Destructor
	 * Pre = La instancia debe estar creada
	 * Post= Elimina el arbol de valoraciones
	 * Complejidad O(1)
	 */
	~VolcadoFichero();

	/*
	 * Metodo que abre el flujo de datos fsal con gastroedi_fecha.log
	 * Pre = La instancia debe estar creada, el flujo no debe estar abierto
	 * previamente
	 * Post=
	 * Complejidad O(1)
	 */
	void generarLogDiario ();

	/*
	 * Metodo que cierra el flujo de datos fsal
	 * Pre = La instancia debe estar creada, el flujo debe estar abierto
	 * Post=
	 * Complejidad O(1)
	 */
	void cerrarLogDiario ();

	/*
	 * Metodo que, dado un restaurante, vuelca su informacion y la de sus
	 * comensales a traves de fsal y lo guarda en el arbol
	 * Pre = La instancia debe estar creada, restaurante creado
	 * Post= Inserta en el arbol restaurante y modifica fsal
	 * Complejidad O(n)
	 */
	void insertarYVolcar (Restaurante *restaurante);

	/*
	 * Metodo que vacia el arbol y lo vuelca a traves de fsal en
	 * restaurantesmasvalorados.log
	 * Pre = La instancia debe estar creada
	 * Post= Hace el delete de los restaurantes y lo vuelca en fsal
	 * Complejidad O(n)
	 */
	void generarLogRestaurantes();
};

} /* namespace std */

#endif /* VOLCADOFICHERO_H_ */
