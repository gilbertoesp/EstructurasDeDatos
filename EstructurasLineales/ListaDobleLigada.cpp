/**
	ListaDobleLigada.cpp
	Estructura lineal que organiza los datos dados de menor a mayor
*/
#include <cstdlib>
#include <iostream>
//Estructura base
#include "CajaDobleLigada.h"
//Prototipos
#include "ListaDobleLigada.h"

//*******************************************************************************************
ListaDobleLigada::ListaDobleLigada()
{
	principio = anterior = final = NULL;
	cuantos = 0;
}
//*******************************************************************************************
ListaDobleLigada::~ListaDobleLigada()
{
	CajaDobleLigada *p;

	while(principio){
		p = principio;
		principio = principio->siguiente;
		delete p;
	}
	principio = anterior = final = NULL;
	cuantos = 0;
}
//*******************************************************************************************
void ListaDobleLigada::buscar(int a)
{
	CajaDobleLigada *p = NULL;

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
int ListaDobleLigada::agregar(int a)
{
	CajaDobleLigada *p;
	//Mandamos buscar el valor que queremos agregar para ponerlo en el lugar que correspone
	buscar(a);

	if(encontrado == SI) return 0;

	p = new CajaDobleLigada;
	p->valor = a;

	switch(donde){
		case VACIO:
			p->siguiente = NULL;
			p->anterior = NULL;
			final = p;
			principio = p;
			break;
		case PRINCIPIO:
			p->siguiente = principio;
			principio->anterior = p;
			principio = p;
			p->anterior = NULL;
			break;
		case EN_MEDIO:
		    anterior->siguiente->anterior = p;
			p->siguiente = anterior->siguiente;
			anterior->siguiente = p;
			p->anterior = anterior;
			break;
		case FINAL:
			p->siguiente = NULL;
			anterior->siguiente = p;
			p->anterior = anterior;
			final = p;
			break;
		default:
			return 0;
	}

	lugar_agregado = p;
	cuantos++;
	return 1;
}
//*******************************************************************************************
int ListaDobleLigada::borrar(int a)
{
	CajaDobleLigada *p = NULL;
	//Buscamos el elemento a borrar
	buscar(a);
	if(encontrado == NO) return 0;

	if(!anterior){
		p = principio;
		principio = p->siguiente;
	}else{
		p = anterior->siguiente;
		anterior->siguiente = p->siguiente;
		p->siguiente->anterior = anterior;
	}

	delete p;
	cuantos--;
	return 1;
}
//*******************************************************************************************
#define VACIO 9999999
int ListaDobleLigada::sacar()
{
	CajaDobleLigada *p;
	int valor;

	if(!principio) valor = VACIO;
	else{
		p = principio;
		valor = p->valor;
		principio = p->siguiente;
		principio->anterior = NULL;

		delete p;
		cuantos--;
	}
	return valor;
}
//*******************************************************************************************
void ListaDobleLigada::pintar1()
{
	CajaDobleLigada *p;

	p = principio;

	while(p){
		std::cout << p->valor << " ";
		p = p->siguiente;
	}
}
//*******************************************************************************************
void ListaDobleLigada::pintar2()
{
	CajaDobleLigada *p;

	p = final;

	while(p){
		std::cout << p->valor << " ";
		p = p->anterior;
	}
}
//*******************************************************************************************
int ListaDobleLigada::cuantosSon()
{
    return cuantos;
}
//*******************************************************************************************
CajaDobleLigada * ListaDobleLigada::LugarAgregado()
{
    return lugar_agregado;
}

//*******************************************************************************************






























