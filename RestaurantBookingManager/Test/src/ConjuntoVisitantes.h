/*
 * ConjuntoVisitantes.h
 *
 *  Created on: 8/4/2015
 *      Author: guille
 */

#ifndef SRC_CONJUNTOVISITANTES_H_
#define SRC_CONJUNTOVISITANTES_H_

#include<iostream>
#include "listapi.h"
#include "Visitante.h"
#include "genaleatorios.h"
#include <fstream>

using namespace std;

class ConjuntoVisitantes {

private:

	ListaPI<Visitante*> *visitantes;
	ListaPI<Visitante*> *visitantesNoServidos;

public:

	/*
	 * Constructor por defecto
	 * Pre =
	 * Post= Crea instancias de las listas de visitantes y visitantes no servidos
	 * Complejidad O(1)
	 */
	ConjuntoVisitantes();

	/*
	 * Método que añade un nuevo visitante
	 * Pre = La instancia debe estar creada
	 * Post= Inserta un visitante nuevo al final de la lista de visitantes
	 * Complejidad O(1)
	 */
	void insertar(Visitante *visitante);

	/*
	 * Método que busca un visitante por nombre y apellido
	 * Pre = La instancia debe estar creada, visitante1 no apunta a nada
	 * Post= Devuelve en visitante1 la persona que coincide con nombre y
	 * apellidos. Si no encuentra a nadie devuelve false
	 * Complejidad O(n)
	 */
	bool consultar(string nombre, string apellidos, Visitante *&visitante1);

	/*
	 * Método que devuelve y elimina el primer visitante de la lista
	 * Pre = La instancia debe estar creada, visitante apunta a NULL
	 * Post= Devuelve en visitante el primer elemento de la lista. Retorna
	 * false si está vacia
	 * Complejidad O(1)
	 */
	bool extraerVisitante (Visitante *&visitante);

	/*
	 * Método que añade un visitantes a la lista de no servidos
	 * Pre = La instancia debe estar creada, visitante debe estar inicializado
	 * Post= Inserta un visitante en la lista de no servidos
	 * Complejidad O(1)
	 */
	void insertarEnNoServidos(Visitante *visitante);

	/*
	 * Método que genera un numero aleatorio como valoracion de un visitante
	 * Pre = La instancia debe estar creada, visitante debe estar inicializado
	 * Post= Retorna un numero aleatorio como valoracion del visitante en cuestion
	 * Complejidad O(1)
	 */
	int procesarValoracion(Visitante *visitante);

	/*
	 * Método que muestra todos los visitantes no servidos
	 * Pre = La instancia debe estar creada
	 * Post= Muestra por pantalla la informacion de la lista de no servidos
	 * Complejidad O(n)
	 */
	void mostrarNoServidos();

	/*
	 * Método que mueve los visitantes de la lista de no servidos a la de visitantes
	 * Pre = La instancia debe estar creada, visitantes debe estar vacio para
	 * garantizar la coherencia de la operacion
	 * Post= Vacia la lista de no servidos y los coloca en la de visitantes en el
	 * mismo orden
	 * Complejidad O(n)
	 */
	void restaurarDeNoServidos();

	/*
	 * Destructor
	 * Pre = La instancia debe estar creada
	 * Post= Elimina las estructuras de datos creadas y genera un fichero log
	 * con la informacion de los visitantes no atendidos, tambien elimina a estos
	 * Complejidad O(n)
	 */
	~ConjuntoVisitantes();
};

#endif /* SRC_CONJUNTOVISITANTES_H_ */
