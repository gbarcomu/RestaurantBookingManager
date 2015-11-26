//============================================================================
// Name        : GastroEdi.h
// Author      : profesores de la asignatura EDi
// Version     : curso 14/15
// Copyright   : Your copyright notice
// Description : Definición de la clase GastroEdi
//===========================================================
#ifndef GASTROEDI_H_
#define GASTROEDI_H_

#include "ConjuntoRestaurantes.h"
#include "ConjuntoVisitantes.h"
#include "listapi.h"
#include "VolcadoFichero.h"

class GastroEDI {

private:

	ConjuntoRestaurantes *conjuntoRestaurantes;
	ConjuntoVisitantes *conjuntoVisitantes;
	VolcadoFichero *volcadoFichero;


	float mejorNota;
	string mejorRestaurante;

public:
	/*
	* Constructor por defecto
	 * Pre ={}
	 * Post= {Crea/inicializa la instancia de la clase}
	 * Complejidad O(1)
	 */
	GastroEDI();
	/*
	 * Método cargaVisitantes. Crea los visitantes y los introduce en la ED correspondiente. En Fase 3 deberá hacerse
	 * esta carga de datos desde ficheros de entrada
	 * Pre = La instancia debe estar creada
	 * Post= Los visitantes son creados e introducidos en la ED que los almacena temporalmente hasta que se asignen
	 * a sus respectivos restaurantes
	 * Complejidad O(n)
	 */
	void cargaVisitantes();
	/*
	 * Método cargarRestaurantes. Crea los restaurantes y los introduce en la ED correspondiente. En Fase 3 deberá hacerse
	 * esta carga de datos desde ficheros de entrada
	 * Pre = La instancia debe estar creada
	 * Post= Los restaurantes son creados e introducidos en la ED que los almacena (esta ED cambiará en la fase 3)
	 * Complejidad O(n)
	 */
	void cargarRestaurantes();

	/*
	 * Destructor
	 * Pre = La instancia debe estar creada
	 * Post= Elimina la instancia y libera la memoria dinámica asociada a esta instancia
	 * Complejidad O(n)
	 */
	~GastroEDI();

	/*
	 * Método que permite hacer una consulta sobre un restaurante
	 * Pre = La instancia debe estar creada
	 * Post= Muestra por pantalla la informacion sobre un restaurante
	 * Complejidad O(1)
	 */
	void consultaUnRestaurante();

	/*
	 * Método que permite hacer una consulta sobre un visitante
	 * Pre = La instancia debe estar creada
	 * Post= Muestra por pantalla la informacion sobre un visitante
	 * Complejidad O(1)
	 */
	void consultaUnVisitante();

	/*
	 * Método que asigna los visitantes a los restaurantes correspondientes
	 * Pre = La instancia debe estar creada
	 * Post= Los visitantes pasan a estar asignados a los restaurantes
	 * y los no asignados a la lista de no atendidos
	 * Complejidad O(n²)
	 */
	void distribucionVisitantes();

	/*
	 * Método que permite hacer una consulta sobre varios restaurantes
	 * Pre = La instancia debe estar creada
	 * Post= Muestra por pantalla la informacion sobre los restaurantes que empiecen
	 * por una determinada raiz
	 * Complejidad O(1)
	 */
	void consultaUnRestauranteRaiz();

	/*
	 * Método que crea las valoraciones de los restaurantes por parte de los clientes
	 * Pre = La instancia debe estar creada
	 * Post= Crea un fichero log y añade las valoraciones a los restaurantes
	 * Complejidad O(n²)
	 */
	void valoracionRestaurante();

	/*
	 * Método que permite consultar el restaurante mas valorados
	 * Pre = La instancia debe estar creada
	 * Post= Muestra por pantalla la informacion sobre el restaurante mas valorado
	 * Complejidad O(1)
	 */
	void consultaMejor();

	/*
	 * Método que permite hacer una consulta sobre los visitantes no atendidos
	 * Pre = La instancia debe estar creada
	 * Post= Muestra por pantalla la informacion sobre los visitantes
	 * que no han encontrado restaurante
	 * Complejidad O(1)
	 */
	void mostrarNoAtendidos();

	/*
	 * Método que permite eliminar un visitante de un restaurante
	 * Pre = La instancia debe estar creada
	 * Post= Elimina el visitante del restaurante en cuestion y
	 * busca si puede añadir a alguno de los no servidos
	 * Complejidad O(n)
	 */
	void anularReserva();
};

#endif /* GASTROEDI_H_ */
