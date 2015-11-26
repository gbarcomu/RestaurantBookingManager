//============================================================================
// Name        : GastroEdi.cpp
// Author      : profesores de la asignatura EDi
// Version     : curso 14/15
// Copyright   : Your copyright notice
// Description : Implementación de la clase GastroEdi
//===========================================================
#include "GastroEDI.h"
#include "Visitante.h"
#include "ConjuntoRestaurantes.h"
#include<fstream>
#include "Restaurante.h"

GastroEDI::GastroEDI() {

	conjuntoRestaurantes = new ConjuntoRestaurantes();
	conjuntoVisitantes = new ConjuntoVisitantes();
	volcadoFichero = new VolcadoFichero();

	mejorNota = -1;
	mejorRestaurante = "desconocido";
}

void GastroEDI::cargarRestaurantes() {

	Restaurante *r;
	ifstream fent;
	fent.open("restaurantes.txt");

	if (fent.is_open()) {

		cout << "Utilizando datos de fichero" << endl;

		string nombre;
		string direccion;
		string tenedores;
		string telefono;
		string comensales;

		while (!fent.eof()) {

			getline(fent, nombre, '#');
			if (!fent.eof()) {
				getline(fent, direccion, '#');
				getline(fent, tenedores, '#');
				getline(fent, telefono, '#');
				getline(fent, comensales);

				r = new Restaurante(nombre, direccion, atoi(tenedores.c_str()),
						atoi(comensales.c_str()), telefono);

				conjuntoRestaurantes->insertar(r);

			}
		}

		fent.close();
	}

	else {

		cout << "Usando datos por defecto" << endl;

		Restaurante *r;
		r = new Restaurante("La Tahona", "Felipe Uribarri 4", 2, 55,
				"927210023");
		conjuntoRestaurantes->insertar(r);

		r = new Restaurante("Atrio", "Plaza San Mateo", 10, 60, "927231266");
		conjuntoRestaurantes->insertar(r);

		r = new Restaurante("Casa Mijhaeli", "Barrio Nuevo 6", 1, 34,
				"927242112");
		conjuntoRestaurantes->insertar(r);

		r = new Restaurante("Figon", "Plaza San Juan 12", 3, 60, "927215389");
		conjuntoRestaurantes->insertar(r);

		r = new Restaurante("La Cacharreria", "Orellana 1", 1, 40, "927251477");
		conjuntoRestaurantes->insertar(r);

		r = new Restaurante("Torre de Sande", "Calle de los Condes 3", 3, 55,
				"927249000");
		conjuntoRestaurantes->insertar(r);

		r = new Restaurante("El Puchero", "Plaza Mayor 7", 1, 80, "927231132");
		conjuntoRestaurantes->insertar(r);

		r = new Restaurante("El Paladar de Felisa", "Sergio Sánches 10", 2, 40,
				"927232222");
		conjuntoRestaurantes->insertar(r);

		r = new Restaurante("Oquendo", "Obispo Segura Sáez 2", 2, 30,
				"927235173");
		conjuntoRestaurantes->insertar(r);

		r = new Restaurante("La Minerva", "Plaza Mayor", 1, 50, "927234400");
		conjuntoRestaurantes->insertar(r);

		r = new Restaurante("El Raco de Sanguino", "Plaza de las Veletas 4", 2,
				40, "927235566");
		conjuntoRestaurantes->insertar(r);

		r = new Restaurante("Hornos 25", "Hornos 25", 1, 20, "927217766");
		conjuntoRestaurantes->insertar(r);

		r = new Restaurante("Palacio de los Golfines", "Adarve Padre Rosalio 2",
				3, 200, "927221221");
		conjuntoRestaurantes->insertar(r);

		r = new Restaurante("San Juan", "Plaza de San Juan 9", 2, 40,
				"927225566");
		conjuntoRestaurantes->insertar(r);
	}
}

void GastroEDI::cargaVisitantes() {

	Visitante *v;
	ifstream fent;
	fent.open("visitantes.txt");

	if (fent.is_open()) {

		cout << "Utilizando datos de fichero" << endl;

		string nombre;
		string apellidos;
		string provinciaOrigen;
		string numeroDeComensales;
		string numeroDeRestaurantesElegidos;
		string restauranteElegido;

		while (!fent.eof()) {

			getline(fent, nombre, '#');
			if (!fent.eof()) {
				getline(fent, apellidos, '#');
				getline(fent, provinciaOrigen, '#');
				getline(fent, numeroDeComensales, '#');
				getline(fent, numeroDeRestaurantesElegidos);

				v = new Visitante(nombre, apellidos, provinciaOrigen,
						atoi(numeroDeComensales.c_str()));

				int i = atoi(numeroDeRestaurantesElegidos.c_str());

				while (i > 0) {

					getline(fent, restauranteElegido);
					v->aniadirSolicitud(restauranteElegido);
					i--;

				}
				conjuntoVisitantes->insertar(v);

			}
		}

		fent.close();
	}

	else {

		cout << "Usando datos por defecto" << endl;

		Visitante *v;
		v = new Visitante("Soraya", "Saez de Santamaria", "Madrid", 20);
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Oquendo");
		v->aniadirSolicitud("Figon");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Susana", "Diaz Pacheco", "Sevilla", 2);
		v->aniadirSolicitud("Figon");
		v->aniadirSolicitud("Atrio");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Leire", "Pajin", "Bilbao", 4);
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Torre de Sande");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Antonio", "Alcantara", "Albacete", 7);
		v->aniadirSolicitud("El Puchero");
		v->aniadirSolicitud("Casa Mijhaeli");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Willy", "Toledo", "Madrid", 30);
		v->aniadirSolicitud("Palacio de los Golfines");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Pepa", "Bueno", "Madrid", 4);
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Torre de Sande");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Carmen", "Martinez", "Santander", 2);
		v->aniadirSolicitud("Atrio");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Belen", "Esteban", "Madrid", 3);
		v->aniadirSolicitud("La Minerva");
		v->aniadirSolicitud("San Juan");
		v->aniadirSolicitud("Hornos 25");
		v->aniadirSolicitud("La Cacharreria");
		v->aniadirSolicitud("El Puchero");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Luz", "Cuesta Caro", "Segovia", 6);
		v->aniadirSolicitud("El Raco de Sanguino");
		v->aniadirSolicitud("Palacio de los Golfines");
		v->aniadirSolicitud("El Paladar de Felisa");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Miguel", "Marco Gol", "Toledo", 4);
		v->aniadirSolicitud("El Puchero");
		v->aniadirSolicitud("Palacio de los Golfines");
		v->aniadirSolicitud("El Paladar de Felisa");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Julio", "Conesa Cara", "Albacete", 5);
		v->aniadirSolicitud("Hornos 25");
		v->aniadirSolicitud("Palacio de los Golfines");
		v->aniadirSolicitud("El Paladar de Felisa");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Adrian", "Puente Madera", "Toledo", 3);
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("San Juan");
		v->aniadirSolicitud("Figon");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Jose", "Mourinho", "Madrid", 36);
		v->aniadirSolicitud("Torre de Sande");
		v->aniadirSolicitud("Palacio de los Golfines");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Jose", "Blanco", "Pontevedra", 12);
		v->aniadirSolicitud("La Minerva");
		v->aniadirSolicitud("La Cacharreria");
		v->aniadirSolicitud("San Juan");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Risto", "Mejide", "Barcelona", 22);
		v->aniadirSolicitud("El Puchero");
		v->aniadirSolicitud("El Raco de Sanguino");
		v->aniadirSolicitud("El Paladar de Felisa");
		v->aniadirSolicitud("Oquendo");
		v->aniadirSolicitud("La Tahona");
		v->aniadirSolicitud("Torre de Sande");
		v->aniadirSolicitud("Palacio de los Golfines");
		v->aniadirSolicitud("Atrio");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Jose Manuel", "Lara Bosch", "Barcelona", 50);
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Torre de Sande");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Cesar", "Alierta Izuel", "Zaragoza", 6);
		v->aniadirSolicitud("El Raco de Sanguino");
		v->aniadirSolicitud("Oquendo");
		v->aniadirSolicitud("Torre de Sande");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Juan", "Roig Alfonso", "Valencia", 10);
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Figon");
		v->aniadirSolicitud("Torre de Sande");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Felix", "Llanos", "Valladolid", 5);
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Torre de Sande");
		v->aniadirSolicitud("Figon");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Sonia", "Castedo", "Alicante", 5);
		v->aniadirSolicitud("Oquendo");
		v->aniadirSolicitud("Torre de Sande");
		v->aniadirSolicitud("Figon");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Ricardo", "Costa", "Valencia", 15);
		v->aniadirSolicitud("El Raco de Sanguino");
		v->aniadirSolicitud("Torre de Sande");
		v->aniadirSolicitud("Figon");
		v->aniadirSolicitud("La Cacharreria");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Jaume", "Matas", "Baleares", 12);
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("La Minerva");
		v->aniadirSolicitud("Figon");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Agustin", "Barberas", "Sevilla", 8);
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Figon");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Ferran", "Falco", "Barcelona", 15);
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Figon");
		v->aniadirSolicitud("Torre de Sande");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Pablo", "Iglesias", "Madrid", 12);
		v->aniadirSolicitud("El Puchero");
		v->aniadirSolicitud("Oquendo");
		v->aniadirSolicitud("Casa Mijhaeli");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Jose", "Carretero Domenech", "Pamplona", 22);
		v->aniadirSolicitud("El Puchero");
		v->aniadirSolicitud("Casa Mijhaeli");
		v->aniadirSolicitud("San Juan");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Emma", "Garcia", "Vitoria", 2);
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Casa Mijhaeli");
		v->aniadirSolicitud("San Juan");
		v->aniadirSolicitud("Hornos 25");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Nuria", "Roca", "Castellon", 4);
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Casa Mijhaeli");
		v->aniadirSolicitud("San Juan");
		v->aniadirSolicitud("Hornos 25");
		v->aniadirSolicitud("La Minerva");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Patricia", "Conde", "Castellon", 4);
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Casa Mijhaeli");
		v->aniadirSolicitud("San Juan");
		v->aniadirSolicitud("Hornos 25");
		v->aniadirSolicitud("La Minerva");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Sara", "Carbonero", "Almeria", 9);
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Casa Mijhaeli");
		v->aniadirSolicitud("San Juan");
		v->aniadirSolicitud("Hornos 25");
		v->aniadirSolicitud("La Minerva");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Ana", "Morgade", "León", 6);
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Casa Mijhaeli");
		v->aniadirSolicitud("San Juan");
		v->aniadirSolicitud("Hornos 25");
		v->aniadirSolicitud("La Minerva");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Cristina", "Pedroche", "Jaén", 4);
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Casa Mijhaeli");
		v->aniadirSolicitud("San Juan");
		v->aniadirSolicitud("Hornos 25");
		v->aniadirSolicitud("La Minerva");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Beatriz", "Montanez", "Burgos", 8);
		v->aniadirSolicitud("Oquendo");
		v->aniadirSolicitud("Casa Mijhaeli");
		v->aniadirSolicitud("San Juan");
		v->aniadirSolicitud("Hornos 25");
		v->aniadirSolicitud("La Minerva");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Usun", "Yoon", "Madrid", 2);
		v->aniadirSolicitud("Atrio");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Pilar", "Rubio", "Madrid", 2);
		v->aniadirSolicitud("Figon");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Jose Maria", "Carrascal", "Toledo", 2);
		v->aniadirSolicitud("La Minerva");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Kiko", "Rivera", "Malaga", 3);
		v->aniadirSolicitud("El Puchero");
		v->aniadirSolicitud("El Paladar de Felisa");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Jose", "Mota", "Segovia", 13);
		v->aniadirSolicitud("El Puchero");
		v->aniadirSolicitud("El Paladar de Felisa");
		v->aniadirSolicitud("Hornos 25");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Cristina", "Tarrega", "Gerona", 30);
		v->aniadirSolicitud("El Puchero");
		v->aniadirSolicitud("El Paladar de Felisa");
		v->aniadirSolicitud("Hornos 25");
		v->aniadirSolicitud("El Raco de Sanguino");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Arturo", "Valls", "Barcelona", 25);
		v->aniadirSolicitud("La Tahona");
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Hornos 25");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Matias", "Prats", "Barcelona", 10);
		v->aniadirSolicitud("La Tahona");
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Hornos 25");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Roberto", "Brasero", "Salamanca", 5);
		v->aniadirSolicitud("La Tahona");
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Hornos 25");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Mercedes", "Mila", "Barcelona", 12);
		v->aniadirSolicitud("La Tahona");
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Oquendo");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Nieves", "Herrero", "Malaga", 8);
		v->aniadirSolicitud("La Minerva");
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Hornos 25");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Jaime", "Cantizano", "Malaga", 8);
		v->aniadirSolicitud("La Minerva");
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Hornos 25");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Karlos", "Arguinano", "Bilbao", 10);
		v->aniadirSolicitud("San Juan");
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Hornos 25");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Ramon", "Aranguena", "Bilbao", 10);
		v->aniadirSolicitud("San Juan");
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Hornos 25");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Anabel", "Alonso", "Bilbao", 20);
		v->aniadirSolicitud("San Juan");
		v->aniadirSolicitud("Palacio de los Golfines");
		v->aniadirSolicitud("Hornos 25");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Jesus", "Quintero", "Cordoba", 9);
		v->aniadirSolicitud("San Juan");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Jordi", "Evole", "Barcelona", 4);
		v->aniadirSolicitud("San Juan");
		v->aniadirSolicitud("Figon");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Pedro", "Sanchez", "Madrid", 4);
		v->aniadirSolicitud("San Juan");
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Figon");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Monica", "Lopez", "Madrid", 6);
		v->aniadirSolicitud("Figon");
		v->aniadirSolicitud("San Juan");
		v->aniadirSolicitud("La Minerva");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Jorge Javier", "Vazquez", "Madrid", 6);
		v->aniadirSolicitud("La Cacharreria");
		v->aniadirSolicitud("Palacio de los Golfines");
		v->aniadirSolicitud("La Minerva");
		v->aniadirSolicitud("San Juan");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Ana", "Pastor", "Salamanca", 8);
		v->aniadirSolicitud("La Cacharreria");
		v->aniadirSolicitud("La Minerva");
		v->aniadirSolicitud("San Juan");
		v->aniadirSolicitud("Casa Mijhaeli");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Maria", "Escario", "Valladolid", 10);
		v->aniadirSolicitud("El Raco de Sanguino");
		v->aniadirSolicitud("La Cacharreria");
		v->aniadirSolicitud("La Minerva");
		v->aniadirSolicitud("Casa Mijhaeli");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Juan", "Echanove", "Madrid", 10);
		v->aniadirSolicitud("El Raco de Sanguino");
		v->aniadirSolicitud("La Cacharreria");
		v->aniadirSolicitud("La Minerva");
		v->aniadirSolicitud("Casa Mijhaeli");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Cristobal", "Montoro", "Burgos", 10);
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Figon");
		v->aniadirSolicitud("San Juan");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Amancio", "Ortega", "Vigo", 20);
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Figon");
		v->aniadirSolicitud("San Juan");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Rosa", "Diez", "Bilbao", 2);
		v->aniadirSolicitud("La Minerva");
		v->aniadirSolicitud("El Paladar de Felisa");
		v->aniadirSolicitud("San Juan");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Iker", "Casillas", "Madrid", 2);
		v->aniadirSolicitud("Oquendo");
		v->aniadirSolicitud("El Paladar de Felisa");
		v->aniadirSolicitud("Casa Mihaeli");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Javier", "Barden", "Baleares", 3);
		v->aniadirSolicitud("El Raco de Sanguino");
		v->aniadirSolicitud("El Paladar de Felisa");
		v->aniadirSolicitud("San Juan");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Pedro", "Almodovar", "Ciudad Real", 13);
		v->aniadirSolicitud("El Raco de Sanguino");
		v->aniadirSolicitud("Casa Mijhaeli");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Ferran", "Adria", "Barcelona", 2);
		v->aniadirSolicitud("Atrio");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Joan", "Roca", "Gerona", 2);
		v->aniadirSolicitud("Atrio");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Tania", "Sanchez", "Madrid", 2);
		v->aniadirSolicitud("Figon");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Boris", "Izaguirre", "Madrid", 3);
		v->aniadirSolicitud("San Juan");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Carmen", "Machi", "Madrid", 6);
		v->aniadirSolicitud("Figon");
		v->aniadirSolicitud("La Minerva");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Cristobal", "Montoro", "Jaen", 8);
		v->aniadirSolicitud("La Cacharreria");
		v->aniadirSolicitud("La Minerva");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Ouka", "Leele", "Madrid", 18);
		v->aniadirSolicitud("Casa Mijhaeli");
		v->aniadirSolicitud("La Minerva");
		v->aniadirSolicitud("San Juan");
		v->aniadirSolicitud("La Tahona");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Lorenzo", "Caprile", "Madrid", 11);
		v->aniadirSolicitud("La Tahona");
		v->aniadirSolicitud("La Minerva");
		v->aniadirSolicitud("San Juan");
		v->aniadirSolicitud("Figon");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Gabino", "Diego", "Madrid", 7);
		v->aniadirSolicitud("La Tahona");
		v->aniadirSolicitud("Figon");
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("San Juan");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Rafael", "Amargo", "Granada", 12);
		v->aniadirSolicitud("Torre de Sande");
		v->aniadirSolicitud("El Raco de Sanguino");
		v->aniadirSolicitud("Hornos 25");
		v->aniadirSolicitud("San Juan");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Candido", "Mendez", "Badajoz", 5);
		v->aniadirSolicitud("El Puchero");
		v->aniadirSolicitud("Casa Mijhaeli");
		v->aniadirSolicitud("Hornos 25");
		v->aniadirSolicitud("San Juan");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Roman", "Calavera Calva", "Badajoz", 5);
		v->aniadirSolicitud("El Puchero");
		v->aniadirSolicitud("Casa Mijhaeli");
		v->aniadirSolicitud("Hornos 25");
		v->aniadirSolicitud("Palacio de los Golfines");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Jose", "Mira Iborra", "Badajoz", 4);
		v->aniadirSolicitud("Casa Mijhaeli");
		v->aniadirSolicitud("Hornos 25");
		v->aniadirSolicitud("Palacio de los Golfines");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Manuel", "Esparrago Triguero", "Badajoz", 8);
		v->aniadirSolicitud("Casa Mijhaeli");
		v->aniadirSolicitud("Hornos 25");
		v->aniadirSolicitud("San Juan");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Isolina", "Gato Sardina", "Toledo", 6);
		v->aniadirSolicitud("San Juan");
		v->aniadirSolicitud("La Minerva");
		v->aniadirSolicitud("La Cacharreria");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Dani", "Rovira", "Sevilla", 26);
		v->aniadirSolicitud("Palacio de los Golfines");
		v->aniadirSolicitud("El Puchero");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Nerea", "Barros", "Cordoba", 10);
		v->aniadirSolicitud("Palacio de los Golfines");
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("Figon");
		conjuntoVisitantes->insertar(v);

		v = new Visitante("Raul", "Arevalo", "Toledo", 5);
		v->aniadirSolicitud("Figon");
		v->aniadirSolicitud("Palacio de los Golfines");
		v->aniadirSolicitud("Atrio");
		v->aniadirSolicitud("San Juan");
		conjuntoVisitantes->insertar(v);
	}
}

GastroEDI::~GastroEDI() {

	volcadoFichero->generarLogRestaurantes();

	delete conjuntoVisitantes;
	delete volcadoFichero;
	delete conjuntoRestaurantes;
}

void GastroEDI::consultaUnRestaurante() {

	string nombre;
	Restaurante *restaurante;
	cout << "Introduce el nombre del restaurante: ";
	getline(cin, nombre);
	if (conjuntoRestaurantes->consultar(nombre, restaurante)) {

		restaurante->mostrar();
	}

	else {

		cout << "Restaurante no encontrado." << endl;
	}

}

//TODO cambiar esto como consultaUnRestaurante por coherencia
void GastroEDI::consultaUnVisitante() {

	Visitante *visitante;
	string nombre, apellidos;
	cout << "Introduce el nombre del visitante: ";
	getline(cin, nombre);
	cout << "Introduce los apellidos del visitante: ";
	getline(cin, apellidos);

	if (conjuntoVisitantes->consultar(nombre, apellidos, visitante)) {

		visitante->mostrarVisitanteYRestaurantes();
	}
}

void GastroEDI::distribucionVisitantes() {

	Visitante *visitante;
	string restaurante;
	bool encontradoSitio = false;

	while (conjuntoVisitantes->extraerVisitante(visitante)) { //extrae el siguiente visitante de la lista

		while (visitante->extraerRestaurante(restaurante) and !encontradoSitio) { // extrae el siguiente restaurante de la cola

			if (conjuntoRestaurantes->procesarVisitante(visitante,
					restaurante)) { // comprueba si visitante cabe en restaurante

				encontradoSitio = true;
			}
		}

		if (!encontradoSitio) {

			visitante->notificarSitioNoEncontrado();

			conjuntoVisitantes->insertarEnNoServidos(visitante);
		}

		encontradoSitio = false;
	}

	conjuntoRestaurantes->mostrarDistribucion();
}

void GastroEDI::consultaUnRestauranteRaiz() {

	string subCadena;
	cout << "Busca los restaurantes por una raiz: ";
	getline(cin, subCadena);
	conjuntoRestaurantes->buscarRestaurante(subCadena);

}

void GastroEDI::valoracionRestaurante() {

	Restaurante *restaurante;
	float mediaRest;
	int numRest;
	Visitante *visitante;

	volcadoFichero->generarLogDiario();

	cout << "Comienza el proceso de valoracion de restaurantes:" << endl;

	while (conjuntoRestaurantes->procesarValoracion(restaurante)) {

		mediaRest = 0;
		numRest = 0;

		restaurante->preparacionParaValoracion();

		while (restaurante->obtenerVisitanteParaValoracion(visitante)) {

			mediaRest += conjuntoVisitantes->procesarValoracion(visitante);
			numRest++;
		}

		mediaRest /= numRest;

		if (mediaRest > mejorNota) {

			mejorNota = mediaRest;
			mejorRestaurante = restaurante->getNombre();
		}

		cout << "El restaurante: " << restaurante->getNombre()
				<< " ha obtenido una nota media de " << mediaRest << endl;

		restaurante->setValoracion(mediaRest);

		volcadoFichero->insertarYVolcar(restaurante);
	}

	volcadoFichero->cerrarLogDiario();
}

void GastroEDI::consultaMejor() {

	cout << "El restaurante mejor valorado es: " << mejorRestaurante
			<< " con una nota de: " << mejorNota << endl;
}

void GastroEDI::mostrarNoAtendidos() {

	conjuntoVisitantes->mostrarNoServidos();
}

void GastroEDI::anularReserva() {

	string nombreRestaurante;
	string nombreComensal;
	string apellidosComensal;
	Visitante *visitante;

	cout << "Introduce nombre restaurante: ";
	getline(cin, nombreRestaurante);
	cout << "Introduce nombre del comensal: ";
	getline(cin, nombreComensal);
	cout << "Introduce apellidos del comensal: ";
	getline(cin, apellidosComensal);

	if (conjuntoRestaurantes->anularReserva(nombreRestaurante, nombreComensal,
			apellidosComensal)) {

		conjuntoVisitantes->restaurarDeNoServidos();

		while (conjuntoVisitantes->extraerVisitante(visitante)) {

			if (visitante->buscarRestaurante(nombreRestaurante)) {

				if (conjuntoRestaurantes->procesarVisitante(visitante,
						nombreRestaurante)) {

					visitante->mostrarCorto();
				}

				else {

					conjuntoVisitantes->insertarEnNoServidos(visitante);
				}
			}

			else {

				conjuntoVisitantes->insertarEnNoServidos(visitante);
			}
		}
	}

	else {

		cout << "Restaurante o Visitante no encontrado" << endl;
	}
}
