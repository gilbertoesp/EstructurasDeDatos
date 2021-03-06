/**
	ListaOrdenada.cpp
	Estructura lineal que organiza los datos dados de menor a mayor
*/
#include <cstdlib>
#include <iostream>
//Estructura base
#include "Caja.h"
//Prototipos
#include "ListaOrdenada.h"

//*******************************************************************************************
ListaOrdenada::ListaOrdenada()
{
	principio = anterior = NULL;
	cuantos = 0;
	lugar_agregado = NULL;
    donde = VACIO;
	encontrado = NO;
}
//*******************************************************************************************
ListaOrdenada::~ListaOrdenada()
{
	Caja *p;

	while(principio){
		p = principio;
		principio = principio->siguiente;
		delete p;
	}
	principio = anterior = NULL;
	cuantos = 0;
}
//*******************************************************************************************
void ListaOrdenada::buscar(int a)
{
	Caja *p = NULL;

	if(!principio){
		encontrado = NO;
		donde = VACIO;
		anterior = NULL;
	}else{
		//Suponemos no esta
		encontrado = NO;
		anterior = NULL;
		//Nos posicionamos al principio de la Lista
		p = principio;
		while(p){
			//Todavia no llegamos al valor buscado
			if(p->valor < a){
				anterior = p;
				p = p->siguiente;
				//Verificamos si no llegamos al final de la Lista
				if(!p)						donde = FINAL;
            //Hemos encontrado el valor buscado
			}else if(p->valor == a){
				encontrado = SI;
				//Vemos en que seccion de la lista se encuentra
				if(p == principio)			donde = PRINCIPIO;
				else if(!p->siguiente)		donde = FINAL;
				else						donde = EN_MEDIO;
                //Dado que se encontro, regresamos
                break;
            //Llegamos a un elemento mayor al buscado y no se encontro
			}else{
				encontrado = NO;
				if(!anterior)				donde = PRINCIPIO;
				else						donde = EN_MEDIO;
				//Como el ya estamos en un valor mayor al cual buscamos, regresamos
				break;
			}
		}
	}
	return;
}
//*******************************************************************************************
int ListaOrdenada::agregar(int a)
{
	Caja *p;
	//Mandamos buscar el valor que queremos agregar para ponerlo en el lugar que correspone
	buscar(a);

	if(encontrado == SI) return 0;

	p = new Caja;
	p->valor = a;

	switch(donde){
		case VACIO:
			p->siguiente = NULL;
			principio = p;
			break;
		case PRINCIPIO:
			p->siguiente = principio;
			principio = p;
			break;
		case EN_MEDIO:
			p->siguiente = anterior->siguiente;
			anterior->siguiente = p;
			break;
		case FINAL:
			p->siguiente = NULL;
			anterior->siguiente = p;
			break;
		default:
			return 0;
	}

	lugar_agregado = p;
	cuantos++;
	return 1;
}
//*******************************************************************************************
int ListaOrdenada::borrar(int a)
{
	Caja *p = NULL;
	//Buscamos el elemento a borrar
	buscar(a);
	if(encontrado == NO) return 0;

	if(!anterior){
		p = principio;
		principio = p->siguiente;
	}else{
		p = anterior->siguiente;
		anterior->siguiente = p->siguiente;
	}

	delete p;
	cuantos--;
	return 1;
}
//*******************************************************************************************
#define VACIO 9999999
int ListaOrdenada::sacar()
{
	Caja *p;
	int valor;

	if(!principio) valor = VACIO;
	else{
		p = principio;
		valor = p->valor;
		principio = p->siguiente;

		delete p;
		cuantos--;
	}
	return valor;
}
//*******************************************************************************************
void ListaOrdenada::pintar()
{
	Caja *p;

	p = principio;

	while(p){
		std::cout << p->valor << " ";
		p = p->siguiente;
	}
}
//*******************************************************************************************
int ListaOrdenada::cuantosSon()
{
    return cuantos;
}
//*******************************************************************************************
Caja * ListaOrdenada::LugarAgregado()
{
    return lugar_agregado;
}

//*******************************************************************************************






























