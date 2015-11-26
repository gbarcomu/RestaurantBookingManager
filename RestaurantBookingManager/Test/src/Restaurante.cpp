//============================================================================
// Name        : restaurante.cpp
// Author      : Profesores de la asignatura EDI
// Version     : curso 14/15
// Copyright   :
// Description : Implementación de la clase restaurante
//============================================================================

#include "Restaurante.h"
using namespace std;

Restaurante::Restaurante() {

	nombre = "desconocido";
	direccion = "desconocida";
	numTenedores = 0;
	aforo = aforoRestante = 1;
	telefono = "desconocido";
	clientes = new ListaPI<Visitante*>();
	valoracionRestaurante = 0;
}

Restaurante::Restaurante(string nombre, string direccion, int numTenedores,
		int aforo, string telefono) {

	this->nombre = nombre;
	this->direccion = direccion;
	this->numTenedores = numTenedores;
	this->aforo = aforoRestante = aforo;
	this->telefono = telefono;
	clientes = new ListaPI<Visitante*>();

	valoracionRestaurante = 0;

}

bool Restaurante::operator ==(Restaurante& R) {
	return (this->nombre == R.nombre);

}

bool Restaurante::operator ==(string nombreRestaurante) {
	return (this->nombre == nombreRestaurante);
}

Restaurante::~Restaurante() {

	delete clientes;
}

void Restaurante::mostrar() {

	cout << endl;

	cout << "Restaurante: " << nombre << endl;
	cout << "Direccion: " << direccion << endl;
	cout << "Tenedores: " << numTenedores << endl;
	cout << "Aforo total " << aforo << ", " << "Disponible " << aforoRestante
			<< endl;
	cout << "Telefono " << telefono << endl << endl;

	cout << "Reservas: " << endl;

	mostrarVisitantes();
}

string Restaurante::getNombre() const{

	return nombre;
}

int Restaurante::getAforoLibre() {

	return aforoRestante;
}

void Restaurante::reajustarComensales(int numero) {

	aforoRestante += numero;
}

void Restaurante::hacerReserva(Visitante* visitante) {

	clientes->moverFinal();
	clientes->avanzar();
	clientes->insertar(visitante);
	//TODO comprobar si se especifica orden en esta lista
}

void Restaurante::mostrarCorto() {

	cout << nombre << " con " << aforoRestante << " plazas libres." << endl;
}

bool Restaurante::extraerCliente(string nombreCliente, string apellidoCliente) {

	Visitante *visitante;
	bool encontrado = false;

	if (!clientes->estaVacia()) {

		clientes->moverInicio();

		while (!clientes->finLista() && !encontrado) {

			clientes->consultar(visitante);

			if (visitante->comprobarComensal(nombreCliente, apellidoCliente)) {

				aforoRestante += visitante->getComensales();
				clientes->borrar();
				encontrado = true;
				delete visitante; // eliminamos los visitantes que cancelan reserva
			}

			clientes->avanzar();
		}
	}

	return encontrado;
}

bool Restaurante::obtenerVisitanteParaValoracion(Visitante*& visitante) {

	if (!clientes->estaVacia() && !clientes->finLista()) {

		clientes->consultar(visitante);
		clientes->avanzar();
		return true;
	}

	return false;
}

void Restaurante::mostrarVisitantes() {

	Visitante *visitante;
	clientes->moverInicio();

	while (!clientes->finLista()) {

		clientes->consultar(visitante);
		visitante->mostrarCorto();
		clientes->avanzar();
	}

	cout << endl;
}

void Restaurante::setValoracion(float numero) {

	valoracionRestaurante = numero;
}

float Restaurante::getValoracion() const{

	return valoracionRestaurante;
}

bool Restaurante::extraerPrimerCliente(Visitante*& visitante) {

	if (!clientes->estaVacia()) {

		clientes->moverInicio();
		clientes->consultar(visitante);
		clientes->borrar();
		return true;
	}

	return false;
}

string Restaurante::getDireccion() {

	return direccion;
}

int Restaurante::getTenedores() {

	return numTenedores;
}

int Restaurante::getAforo() {

	return aforo;
}

void Restaurante::preparacionParaValoracion() {

	clientes->moverInicio();
}

string Restaurante::getTelefono() {

	return telefono;
}
