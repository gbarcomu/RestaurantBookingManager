//============================================================================
// Name        : UI.h
// Author      : profesores de la asignatura EDi
// Version     : curso 14/15
// Copyright   : Your copyright notice
// Description : Definición de la clase User Interface
//============================================================================

#ifndef UI_H_
#define UI_H_

#include "GastroEDI.h"

/**
* \class UI (User Interface)
* \brief Definición la clase que muestra el menú de opciones y ejecuta dicho menú hasta que el usuario desee
* abandonar la aplicación GastroEDI
*/
class UI {

private:

	GastroEDI *gastroEDI;

	/*
	 * Metodo menu. Muestra el menú con las distintas opciones de la aplicación
	 * Pre= { La instancia debe estar creada }
	 * Post= Muestra el menú de opciones de la aplicación
	 * Parámetros No hay
	 * Complejidad: O(1)
	 */
	int  menu     ();
	/*
	 * Metodo ejecutar. Ejecuta la opción del menú deseada
	 * Pre= { La instancia debe estar creada }
	 * Post= Ejecuta la opción del menú seleccionada
	 * Parámetros No hay
	 * Complejidad: O(n)
	 */
	void ejecutar ();

public:
	/*
	* Constructor por defecto
	 * Pre ={}
	 * Post= {Crea/inicializa la instancia de la clase}
	 * Complejidad O(1)
	 */
	 UI();
	/*
	 * Destructor
	 * Pre: La instancia debe estar creada.
	 * Parámetros: No hay
	 * Post: Elimina la instancia
	 * Complejidad: O(1)
	 */
	~UI();
};

#endif /* UI_H_ */
