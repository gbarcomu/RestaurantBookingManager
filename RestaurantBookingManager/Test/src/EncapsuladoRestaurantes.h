/*
 * EncapsuladoRestaurantes.h
 *
 *  Created on: 22 May 2015
 *      Author: guillermo
 */

#ifndef ENCAPSULADORESTAURANTES_H_
#define ENCAPSULADORESTAURANTES_H_

#include "arbol.h"
#include "Comparar.h"
#include "Restaurante.h"

class EncapsuladoRestaurantes {
private:

	Arbol<Restaurante*, Comparar> *arbolRestaurante;

	/*
	 * Método recursivo que hace un recorrido inorden del arbol
	 * Pre = La instancia debe estar creada
	 * Post= Muestra por pantalla la informacion de cada elemento
	 * Complejidad O(n)
	 */
	void inOrden(Arbol<Restaurante*, Comparar> *abb);

	/*
	 * Método recursivo que hace un recorrido preorden del arbol
	 * Pre = La instancia debe estar creada
	 * Post= Muestra por pantalla la informacion de cada elemento
	 * Complejidad O(n)
	 */
	void preOrden(Arbol<Restaurante*, Comparar> *abb);

	/*
	 * Método recursivo que hace un recorrido postorden del arbol
	 * Pre = La instancia debe estar creada
	 * Post= Muestra por pantalla la informacion de cada elemento
	 * Complejidad O(n)
	 */
	void postOrden(Arbol<Restaurante*, Comparar> *abb);

	/*
	 * Método recursivo que devuelve el numero de elementos que hay en el arbol
	 * Pre = La instancia debe estar creada
	 * Post= Retorna el numero de elementos del arbol
	 * Complejidad O(n)
	 */
	int cuantos(Arbol<Restaurante*, Comparar> *abb);

	/*
	 * Método recursivo que busca un dato en el arbol
	 * Pre = La instancia debe estar creada, restaurante no apunta a nada
	 * Post= Devuelve en restaurante el elemento cuyo nombre coincide con nombre
	 * Complejidad O(log n)
	 */
	bool buscar(string nombre, Arbol<Restaurante*, Comparar> *abb, Restaurante *&restaurante);

	/*
	 * Método recursivo que busca todos los datos cuyo nombre comparte una determinada
	 * raiz
	 * Pre = La instancia debe estar creada
	 * Post= Muestra por pantalla la informacion de cada elemento que coincide
	 * Complejidad O(log n) (Aproximadamente)
	 */
	void subcadena(string subcad, Arbol<Restaurante*, Comparar> *abb);

	/*
	 * Método que comprueba si una cadena esta contenida en otra
	 * Pre = La instancia debe estar creada
	 * Post= Devuelve true o false en funcion de si la segunda esta contenida
	 * en la primera
	 * Complejidad O(n)
	 */
	bool compararCadenas(string cad, string subcad);

	/*
	 * Método recursivo que busca el menor elemento del arbol
	 * Pre = La instancia debe estar creada, restaurante no apunta a nada
	 * Post= Devuelve en restaurante el menor elemento alfabeticamente hablando
	 * del arbol
	 * Complejidad O(log n)
	 */
	void obtenerMenor(Restaurante *&restaurante, Arbol<Restaurante*, Comparar> *abb);

public:

	/*
	 * Constructor
	 * Pre =
	 * Post= Crea una instancia del arbol
	 * Complejidad O(1)
	 */
	EncapsuladoRestaurantes();

	/*
	 * Método que inserta un elemento en el arbol
	 * Pre = La instancia debe estar creada, restaurante inicializado
	 * Post= Añade al arbol un nuevo restaurante
	 * Complejidad O(1)
	 */
	void insertarRestaurante(Restaurante *restaurante);

	/*
	 * Método que comprueba si hay elementos en el arbol
	 * Pre = La instancia debe estar creada
	 * Post= Devuelve true o false en funcion de si hay o no elementos
	 * en el arbol
	 * Complejidad O(1)
	 */
	bool vacio();

	/*
	 * Interfaz que llama al metodo privado obtenerMenor
	 * Pre = La instancia debe estar creada, restaurante apunta a NULL
	 * Post= Devuelve en restaurante el elemento menor
	 * Complejidad O(1)
	 */
	bool devolverDatoMenor(Restaurante *&restaurante);

	/*
	 * Interfaz que llama al metodo privado inOrden
	 * Pre = La instancia debe estar creada
	 * Post= Muestra los elementos inOrden
	 * Complejidad O(1)
	 */
	void recorridoInOrden();

	/*
	 * Interfaz que llama al metodo privado preOrden
	 * Pre = La instancia debe estar creada
	 * Post= Muestra los elementos preOrden
	 * Complejidad O(1)
	 */
	void recorridoPreOrden();

	/*
	 * Interfaz que llama al metodo privado postOrden
	 * Pre = La instancia debe estar creada
	 * Post= Muestra los elementos postOrden
	 * Complejidad O(1)
	 */
	void recorridoPostOrden();

	/*
	 * Interfaz que llama al metodo privado cuantos
	 * Pre = La instancia debe estar creada
	 * Post= Devuelve el numero de elementos del arbol
	 * Complejidad O(1)
	 */
	int cuantosElementos();

	/*
	 * Interfaz que llama al metodo privado buscar
	 * Pre = La instancia debe estar creada, restaurante no apunta a nada
	 * Post= Devuelve en restaurante el restaurante en cuestion, false si no
	 * lo encuentra
	 * Complejidad O(1)
	 */
	bool buscarPorNombre(string nombre, Restaurante *&restaurante);

	/*
	 * Interfaz que llama al metodo privado subcadena
	 * Pre = La instancia debe estar creada
	 * Post= Muestra los restaurantes coincidentes
	 * Complejidad O(1)
	 */
	void buscarSubcadena(string subcadena);

	/*
	 * Destructor
	 * Pre = La instancia debe estar creada
	 * Post= Hace un delete del arbol
	 * Complejidad O(1)
	 */
	~EncapsuladoRestaurantes();
};

#endif /* ENCAPSULADORESTAURANTES_H_ */
