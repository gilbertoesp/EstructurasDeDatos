/**
    Cola.cpp
    Estructura Lineal de tipo cola, FIFO
    Gilberto Espinoza
*/
#include <cstdlib>
#include <iostream>
//Estructuras
#include "Caja.h"
#include "Cola.h"

//***************************************************************************************
Cola::Cola()
{
	this->principio = this->final = NULL;
	cuantos = 0;
}
//***************************************************************************************
Cola::~Cola()
{
	Caja *p;

	while(principio){
		p = principio;
		principio = principio->siguiente;
		delete p;
	}
	principio = final = NULL;
	cuantos = 0;
}
//***************************************************************************************
void Cola::agregar(int a)
{
	Caja *p;

	p = new Caja;

	p->valor = a;

	if(!principio){
		principio = p;
		p->siguiente = NULL;
		final = p;
	}else{
		final->siguiente = p;
		final = p;
		p->siguiente = NULL;
	}
	cuantos++;
}
//***************************************************************************************
#define VACIO 9999999
int Cola::sacar()
{
	Caja *p;
	int valor;

	if(!principio){
		valor = VACIO;
	}else{
		//Conseguimos el valor del principio de la pila, FIFO
		valor = principio->valor;
		// Este principio lo aislamos en p
		p = principio;
		//Asignamos el nuevo principio, el segundo elemento de la lista
		principio = principio->siguiente;
		// Borramos el antiguo principio
		delete p;
		//Restamos un elementos del total de elemtnos de la cola
		cuantos--;
	}

	return valor;

}
//***************************************************************************************
void Cola::pintar()
{
	Caja *p;
	//Nos ubicamos al principio de la cola
	p = principio;
	while(p){
		//Imprimimos el valor
		std::cout << p->valor << " ";
		//Avanzamos en la cola
		p = p->siguiente;
	}
}
//***************************************************************************************
int Cola::cuantosSon()
{
	return cuantos;
}
//***************************************************************************************


