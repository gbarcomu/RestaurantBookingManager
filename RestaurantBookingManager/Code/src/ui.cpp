//============================================================================
// Name        : UI.cpp
// Author      : profesores de la asignatura EDi
// Version     : curso 14/15
// Copyright   : Your copyright notice
// Description : Implementación de la clase User Interface
//=============================================================================
#include <fstream>
#include <iostream>
#include "ui.h"
#include "GastroEDI.h"

using namespace std;


UI::UI() {

	gastroEDI = new GastroEDI();

	ejecutar();
}

void UI::ejecutar() {

int opcion;
bool salir=false;
	do {
		opcion = menu();
		switch(opcion){
			case 1:
				gastroEDI->cargarRestaurantes();
				gastroEDI->cargaVisitantes();
				break;
			case 2:
				gastroEDI->consultaUnVisitante();
				break;
			case 3:
				gastroEDI->distribucionVisitantes();
				break;
			case 4:
				gastroEDI->consultaUnRestaurante();
				break;
			case 5:
				gastroEDI->consultaUnRestauranteRaiz();
				break;
			case 6:
				gastroEDI->mostrarNoAtendidos();
				break;
			case 7:
				gastroEDI->anularReserva();
				break;
			case 8:
				gastroEDI->valoracionRestaurante();
				break;
			case 9:
				gastroEDI->consultaMejor();
				break;
			case 10:
				delete gastroEDI;
				salir=true;
				break;
			default:
				cout << "ERROR en la opcion de menu" << endl;
				break;
		}

	} while (!salir);
}


int UI::menu(){

	int opcion;

	do {
		cout << endl;
		cout << "__________________ MENU PRINCIPAL ________________" << endl << endl;
		cout << "   1.  Carga de datos."                             << endl;
		cout << "   2.  Consulta de un visitante y sus peticiones." << endl;
		cout << "   3.  Distribución.                             " << endl;
		cout << "   4.  Consulta de un restaurante.               " << endl;
		cout << "   5.  Consulta de restaurantes.                 " << endl;
		cout << "   6.  Consulta de visitantes no servidos.       " << endl;
		cout << "   7.  Anulación de reserva.                     " << endl;
		cout << "   8.  Valoración.                               " << endl;
		cout << "   9.  Restaurante mejor valorado.               " << endl;
		cout << "   10. Finalizar.                                " << endl;
		cout << "Opcion:  ";
		cin>> opcion;
		cin.ignore();

	} while ((opcion < 0) || (opcion > 11));

	return opcion;
}




UI::~UI() {

}



int main () {

	cout << "-------->>   Bienvenidos a la aplicación GastroEDI2015  <<--------";
	cout << "------------------------------------------------------------------";
	UI ui;

}


