/*
 * conjuntoRestaurantes.h
 *
 *  Created on: 8/4/2015
 *      Author: guille
 */

#ifndef CONJUNTORESTAURANTES_H_
#define CONJUNTORESTAURANTES_H_
#include "EncapsuladoRestaurantes.h"
#include "Restaurante.h"
#include "Visitante.h"

class ConjuntoRestaurantes {

private:

	EncapsuladoRestaurantes *restaurantes;

public:

	/*
	 * Constructor de la clase ConjuntoRestaurantes
	 * Pre =
	 * Post= Crea una instancia de EncapsuladoRestaurantes
	 * Complejidad O(1)
	 */
	ConjuntoRestaurantes();

	/*
	 * Método que permite insertar un restaurante
	 * Pre = La instancia debe estar creada, restaurante debe estar creado
	 * Post= Introduce el restaurante en la estructura de datos restaurantes
	 * Complejidad O(1)
	 */
	void insertar(Restaurante *restaurante);

	/*
	 * Método que permite hacer una consulta sobre un restaurante
	 * Pre = La instancia debe estar creada, restaurante no debe apuntar a nada
	 * Post= Devuelve el restaurante en cuestion en el parametro restaurante
	 * y true o false dependiendo de si lo encuentra o no
	 * Complejidad O(1)
	 */
	bool consultar(string nombre, Restaurante *&restaurante);

	/*
	 * Método que calcula si un restaurante tiene suficiente aforo libre para
	 * albergar a un visitante
	 * Pre = La instancia debe estar creada, restaurante debe estar creado
	 * Post= Devuelve true o false en funcion de si cabe o no
	 * Complejidad O(1)
	 */
	bool visitanteCabeEnRestaurante(Restaurante *restaurante, int comensales);

	/*
	 * Método que busca un restaurante por el nombre, comprueba si el
	 * visitante cabe en el, y si es asi lo asigna
	 * Pre = La instancia debe estar creada, restaurante debe estar creado
	 * Post= Devuelve true o false en funcion de si le ha asignado o no
	 * un sitio para comer
	 * Complejidad O(1)
	 */
	bool procesarVisitante(Visitante *visitante, string restaurante);

	/*
	 * Método que busca restaurantes que coinciden con una raiz dada
	 * Pre = La instancia debe estar creada
	 * Post= Muestra por pantalla breve informacion sobre esos restaurantes
	 * Complejidad O(1)
	 */
	void buscarRestaurante(string subCadena);

	/*
	 * Método que obtiene el menor de los restaurantes alfabeticamente
	 * Pre = La instancia debe estar creada, restaurante no apunta a nada
	 * Post= Devuelve el restaurante en el parametro restaurante y false si no
	 * queda ninguno
	 * Complejidad O(1)
	 */
	bool procesarValoracion(Restaurante *&restaurante);

	/*
	 * Método que elimina a un visitante del restaurante en el que se encuentra
	 * Pre = La instancia debe estar creada
	 * Post= Elimina del restaurante cuyo nombre coincide con el primer parametro,
	 * el comensal cuyo nombre coincide con los otros dos. Devuelve true o false
	 * en funcion de si ha tenido exito la operacion
	 * Complejidad O(1)
	 */
	bool anularReserva(string nombreRestaurante, string nombreComensal,
			string apellidosComensal);

	/*
	 * Método que muestra todos los restaurantes en orden alfabetico
	 * Pre = La instancia debe estar creada
	 * Post= Muestra por pantalla la informacion sobre los restaurantes en orden
	 * alfabetico
	 * Complejidad O(1)
	 */
	void mostrarDistribucion();

	/*
	 * Destructor
	 * Pre = La instancia debe estar creada
	 * Post= Hace un delete de la clase restaurantes
	 * Complejidad O(1)
	 */
	~ConjuntoRestaurantes();
};

#endif /* CONJUNTORESTAURANTES_H_ */
