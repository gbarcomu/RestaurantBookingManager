//============================================================================
// Name        : Restaurante.h
// Author      : profesores de la asignatura EDi
// Version     : curso 14/15
// Copyright   : Your copyright notice
// Description : Definición de la clase restaurante
//============================================================================

#ifndef RESTAURANTE_H_
#define RESTAURANTE_H_
#include <fstream>
#include <iostream>
#include "listapi.h"
#include "Visitante.h"

using namespace std;

/**
 * \class Restaurante
 * \brief Definición de objetos de tipo Restaurante para la aplicación GastroEDI
 */
class Restaurante {
	// atributos privados de la clase
private:
	string nombre;
	string direccion;
	int numTenedores;
	int aforo;
	int aforoRestante;
	string telefono;
	ListaPI<Visitante*> *clientes;

	float valoracionRestaurante;

public:
	/*
	 * Constructor por defecto
	 * Pre ={}
	 * Post= {Crea/inicializa la instancia de la clase}
	 * Complejidad O(1)
	 */
	Restaurante();
	/*
	 * Constructor parametrizado
	 * Pre ={ nombre & direccion <> empty 0>= numtenedores <=4, aforo >0}
	 * Post= {Crea/inicializa la instancia de la clase con los parámetros que recibe}
	 * Parametros Entrada:
	 *     nombre= Nombre que le asignamos a los datos de al restaurante
	 *     direccion=
	 *     numtenedores= numero de tenedores que asignamos al restaurantes
	 *     aforo= capacidad en numero de personas que asignamos al restaurante
	 *     telefono =
	 */
	Restaurante(string nombre, string direccion, int numTenedores, int aforo,
			string telefono);

	// operadores
	/*
	 * post:Compara instancias de la clase por el nombre
	 */
	bool operator ==(Restaurante& R);

	/*
	 * post: compara la instacia de la clase que invoca al operadore con un nombre
	 */
	bool operator ==(string nombreRestaurante);

	/*
	 * Destructor
	 * Pre: La instancia debe estar creada.
	 * Parametros: No hay
	 * Post: Libera la memoria reservada para los atributos de la instancia
	 * Complejidad: O(n)
	 */
	~Restaurante();

	/*
	 * Metodo que muestra por pantalla la informacion del restaurante y de sus
	 * visitantes
	 * Pre: La instancia debe estar creada
	 * Post:
	 * Complejidad: O(1)
	 */
	void mostrar();

	/*
	 * Metodo que muestra por pantalla el nombre y el aforo restante del restaurante
	 * Pre: La instancia debe estar creada
	 * Post:
	 * Complejidad: O(1)
	 */
	void mostrarCorto();



	/*
	 * Metodo que modifica los sitios disponibles en un restaurante.
	 * Pre: numero no puede ser nunca mayor que los sitios disponibles
	 * Parametros: numero = determina en cuanto se modifican los sitios libres, puede
	 * ser negativo.
	 * Post: Modifica el valor de aforoRestante.
	 * Complejidad: O(1)
	 */
	void reajustarComensales(int numero);

	/*
	 * Metodo que inserta un cliente al final de la cola de clientes
	 * Pre: La instancia debe estar creada
	 * Post:Añade un cliente a la cola de clientes
	 * Complejidad: O(1)
	 */
	void hacerReserva(Visitante *visitante);

	/*
	 * Metodo que elimina un cliente y reajusta el aforo restante
	 * Pre: La instancia debe estar creada
	 * Post:Elimina un cliente cuyo nombre y apellidos coinciden con los parametros del
	 * metodo, reajusta el aforo y devuelve false en caso de no encontrarlo
	 * Complejidad: O(n)
	 */
	bool extraerCliente(string nombreCliente, string apellidoCliente);

	/*
	 * Metodo que devuelve y elimina el primer cliente de la lista
	 * Pre: La instancia debe estar creada, visitante no apunta a nada
	 * Post: Devuelve en visitante el primer visitante de la lista o false si
	 * esta vacia
	 * Complejidad: O(1)
	 */
	bool extraerPrimerCliente(Visitante *&visitante);

	/*
	 * Metodo que coloca el puntero de clientes en el inicio
	 * Pre: La instancia debe estar creada
	 * Post:El puntero se coloca en el inicio
	 * Complejidad: O(1)
	 */
	void preparacionParaValoracion();

	/*
	 * Metodo que obtiene el primer visitante de la lista, no borra
	 * Pre: La instancia debe estar creada, visitante no apunta a nada
	 * Post: Devuelve en visitante el visitante apuntado y avanza el puntero,
	 * cuando llega al final devuelve false
	 * Complejidad: O(1)
	 */
	bool obtenerVisitanteParaValoracion(Visitante *&visitante);

	/*
	 * Metodo que muestra por pantalla la informacion de los visitantes del
	 * restaurante
	 * Pre: La instancia debe estar creada
	 * Post:
	 * Complejidad: O(n)
	 */
	void mostrarVisitantes();


	/*
	 * Metodos de get y set
	 */
	string getNombre() const;
	int getAforoLibre();
	void setValoracion(float numero);
	float getValoracion() const;
	string getDireccion();
	int getTenedores();
	int getAforo();
	string getTelefono();


};

#endif /* RESTAURANTE_H_ */
