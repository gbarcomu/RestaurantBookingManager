//============================================================================
// Name        : Restaurante.cpp
// Author      : profesores de la asignatura EDi
// Version     : curso 14/15
// Copyright   : Your copyright notice
// Description : Definición de la clase visitante
//============================================================================


#ifndef VISITANTE_H_
#define VISITANTE_H_
#include <string>
#include <cstdlib>
#include <sstream>
#include "cola.h"
#include "genaleatorios.h"
#include "PreferenciaRestaurantes.h"
using namespace std;
/**
* \class Visitante
* \brief Definición de objetos de tipo Visitante para la aplicación GastroEDI
*/
class Visitante {

private:

	int comensales;
	int numEleccionRestaurante;
	string nombre;
	string apellidos;
	string lugarOrigen;
	PreferenciaRestaurantes *preferenciaRestaurantes;
//TODO preguntar string o punteros a string

public:
	/*
	* Constructor por defecto
	 * Pre ={}
	 * Post= {Crea/inicializa la instancia de la clase}
	 * Complejidad O(1)
	 */
	Visitante();
	/*
	* Constructor por defecto
	 * Pre = {}
	 * Post= {Crea/inicializa la instancia de la clase con los parámetros de entrada}
	 * Parámetros Entrada:
	 * 		nombre: nombre del visitante
	 * 		apellidos: apellidos del visitante
	 * 		poblacion: ciudad de origen del visitante
	 * 		comensales: número de personas totales que desean comer en la ciudad
	 * Complejidad O(1)
	 */
	Visitante(string nombre, string apellidos, string poblacion, int comensales);
	/*
	 * Método aniadirSolicitud. Añade un nombre de un restaurante preferido para comer en él
	 * Pre= { La instancia debe estar creada nombreRes <> ""}
	 * Post= {Añade el nombre de restaurante al conjunto de preferencias del visitante}
	 * Parámetros Entrada: nombreRes= Nombre que añadimos al conjunto de preferencias del visitante
	 * Complejidad: O(1)
	 */
	void aniadirSolicitud(string nombreRes);
	/*
	 * Destructor
	 * Pre: La instancia debe estar creada.
	 * Parámetros: No hay
	 * Post: Libera la memoria reservada para los atributos de la instancia
	 * Complejidad: O(n)
	 */
	~Visitante();


	/*
	 * Metodo que muestra por pantalla informacion del visitante y sus preferencias
	 * Pre: La instancia debe estar creada.
	 * Post:
	 * Complejidad: O(n)
	 */
	void mostrarVisitanteYRestaurantes();

	/*
	 * Metodo que muestra por pantalla el nombre y apellidos del visitante
	 * Pre: La instancia debe estar creada.
	 * Post:
	 * Complejidad: O(1)
	 */
	void mostrarCorto();

	/*
	 * Metodo que devuelve el primer restaurante de preferenciaRestaurantes
	 * Pre: La instancia debe estar creada.
	 * Post: Devuelve en restaurante el nombre del primer elemento, false
	 * si no queda ninguno
	 * Complejidad: O(1)
	 */
	bool extraerRestaurante(string &restaurante);

	/*
	 * Metodo que comprueba si un nombre y apellidos coinciden con el visitante
	 * Pre: La instancia debe estar creada.
	 * Post: Devuelve true o false en funcion de si coinciden o no
	 * Complejidad: O(1)
	 */
	bool comprobarComensal(string nombreComensal, string apellidoComensal);

	/*
	 * Metodo que deja a un visitante como estaba antes de buscar restaurante
	 * Pre: La instancia debe estar creada.
	 * Post: Restaura la cola principal de preferenciaRestaurantes
	 * Complejidad: O(1)
	 */
	void notificarSitioNoEncontrado();

	/*
	 * Metodo que comprueba si un restaurante esta entre las preferencias del visitante
	 * Pre: La instancia debe estar creada.
	 * Post: Devuelve true o false en funcion de si encuentra el nombre del restaurante
	 * en preferenciaRestaurantes
	 * Complejidad: O(n)
	 */
	bool buscarRestaurante(string nombreRestaurante);


	/* Metodos get */

	string getNombre();

	int getComensales();

	string getApellidos();

	string getCiudad();

	int getNumEleccion();
};

#endif /* VISITANTE_H_ */
