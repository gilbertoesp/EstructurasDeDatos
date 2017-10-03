/**
	ListaOrdenadaRepBaja.cpp
	Estructura lineal que organiza los datos dados de menor a mayor
	Esta Lista permite la repeticion de Datos, se recomineda que la repeticion de esta sea
	pequena ya que genera una nueva caja por cada valor repetido o no
*/
#include <cstdlib>
#include <iostream>
//Estructura base
#include "Caja.h"
//Prototipos
#include "ListaOrdenadaRepBaja.h"

//*******************************************************************************************
ListaOrdenadaRepBaja::ListaOrdenadaRepBaja()
{
	principio = anterior = NULL;
	cuantos = 0;
}
//*******************************************************************************************
ListaOrdenadaRepBaja::~ListaOrdenadaRepBaja()
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
void ListaOrdenadaRepBaja::buscar(int a)
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
				if(!p)					    	donde = FINAL;
            //Hemos encontrado el valor buscado
			}else if(p->valor == a){
				encontrado = SI;
				//Vemos en que seccion de la lista se encuentra
				if(p == principio)			    donde = PRINCIPIO;
				else if(p->siguiente == NULL)   donde = FINAL;
				else						    donde = EN_MEDIO;
                //Dado que se encontro, regresamos
                break;
            //Llegamos a un elemento mayor al buscado y no se encontro
			}else{
				encontrado = NO;
				if(!anterior)			       	donde = PRINCIPIO;
				else						    donde = EN_MEDIO;
				//Como el ya estamos en un valor mayor al cual buscamos, regresamos
				break;
			}
		}
	}
	return;
}
//*******************************************************************************************
void ListaOrdenadaRepBaja::agregar(int a)
{
	Caja *p;
	//Mandamos buscar el valor que queremos agregar para ponerlo en el lugar que correspone
	buscar(a);

	p = new Caja;
	p->valor = a;
    if(a == 9) std::cout << "donde: " << donde << std::endl;
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
			return;
	}

	lugar_agregado = p;
	cuantos++;
	return;
}
//*******************************************************************************************
int ListaOrdenadaRepBaja::borrar(int a)
{
	Caja *p = NULL;
	//Buscamos el elemento a borrar
	buscar(a);
	if(encontrado == NO) return 0;
    //se borra el princio?
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
int ListaOrdenadaRepBaja::sacar()
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
void ListaOrdenadaRepBaja::pintar()
{
	Caja *p;

	p = principio;

	while(p){
		std::cout << p->valor << " ";
		p = p->siguiente;
	}
}
//*******************************************************************************************
int ListaOrdenadaRepBaja::cuantosSon()
{
    return cuantos;
}
//*******************************************************************************************
Caja * ListaOrdenadaRepBaja::LugarAgregado()
{
    return lugar_agregado;
}

//*******************************************************************************************






























