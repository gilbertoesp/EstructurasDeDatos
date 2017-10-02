/**
	ListaOrden1.cpp
	Estructura lineal que organiza los datos dados de menor a mayor
*/
#include <cstdlib>
#include <iostream>
//Estructura base
#include "CajaPersona.h"
//Prototipos
#include "ListaOrden1.h"

//*******************************************************************************************
ListaOrden1::ListaOrden1()
{
	principio = anterior = NULL;
	cuantos = 0;
	lugar_agregado = NULL;
    donde = VACIO;
	encontrado = NO;
}
//*******************************************************************************************
ListaOrden1::~ListaOrden1()
{
	CajaPersona *p;

	while(principio){
		p = principio;
		principio = principio->siguiente;
		delete p;
	}
	principio = anterior = NULL;
	cuantos = 0;
}
//*******************************************************************************************
void ListaOrden1::buscar(int a)
{
	CajaPersona *p = NULL;

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
int ListaOrden1::agregar(int a)
{
	CajaPersona *p;
	//Mandamos buscar el valor que queremos agregar para ponerlo en el lugar que correspone
	buscar(a);

	if(encontrado == SI) return 0;

	p = new CajaPersona;
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
int ListaOrden1::borrar(int a)
{
	CajaPersona *p = NULL;
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
int ListaOrden1::sacar()
{
	CajaPersona *p;
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
void ListaOrden1::pintar()
{
	CajaPersona *p;

	p = principio;

    while(p){
        std::cout << p->nombre << " " << p->apellido << std::endl;
        p = p->siguiente;
    }
}
//*******************************************************************************************
int ListaOrden1::cuantosSon()
{
    return cuantos;
}
//*******************************************************************************************
CajaPersona * ListaOrden1::LugarAgregado()
{
    return lugar_agregado;
}

//*******************************************************************************************






























