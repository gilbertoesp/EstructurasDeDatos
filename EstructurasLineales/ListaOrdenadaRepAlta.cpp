/**
	ListaOrdenadaRepAlta.cpp
	Estructura lineal que organiza los datos dados de menor a mayor
*/
#include <cstdlib>
#include <iostream>
//Estructura base
#include "CajaRepeticion.h"
#include "Enumeraciones.h"
//Prototipos
#include "ListaOrdenadaRepAlta.h"

//*******************************************************************************************
ListaOrdenadaRepAlta::ListaOrdenadaRepAlta()
{
	principio = anterior = NULL;
	cuantos = 0;
}
//*******************************************************************************************
ListaOrdenadaRepAlta::~ListaOrdenadaRepAlta()
{
	CajaRepeticion *p;

	while(principio){
		p = principio;
		principio = principio->siguiente;
		delete p;
	}
	principio = anterior = NULL;
	cuantos = 0;
}
//*******************************************************************************************
void ListaOrdenadaRepAlta::buscar(int a)
{
	CajaRepeticion *p = NULL;

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
int ListaOrdenadaRepAlta::agregar(int a)
{
	CajaRepeticion *p;
	//Mandamos buscar el valor que queremos agregar para ponerlo en el lugar que correspone
	buscar(a);

    if(encontrado){
        switch(donde){
            case PRINCIPIO:
                principio->cuantos++;
                break;
            default:
                anterior->siguiente->cuantos++;
                break;
        }
        return 1;
    }

	p = new CajaRepeticion;
	p->valor = a;
	p->cuantos = 1;

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
int ListaOrdenadaRepAlta::borrar(int a)
{
	CajaRepeticion *p = NULL;
	//Buscamos el elemento a borrar
	buscar(a);
	if(encontrado == NO) return 0;
    //Si hay mas de 1 en la lista solo reduce su numero de repeticiones
	if(!anterior){
	    if(principio->cuantos > 1){
            principio->cuantos--;
        }else{
            p = principio;
            principio = p->siguiente;
            delete p;
        }
	}else{
        if(anterior->siguiente->cuantos > 1){
            (anterior->siguiente->cuantos)--;
        }else{
            p = anterior->siguiente;
            anterior->siguiente = p->siguiente;
            delete p;
        }
	}
	cuantos--;
	return 1;
}
//*******************************************************************************************
#define VACIO 9999999
int ListaOrdenadaRepAlta::sacar()
{
	CajaRepeticion *p;
	int valor;

	if(!principio) valor = VACIO;
	else{
        if(principio->cuantos > 1 ){
            valor = principio->valor;
            principio->cuantos--;
        }else{
            p = principio;
            valor = p->valor;
            principio = p->siguiente;

            delete p;
        }
	}
    cuantos--;
	return valor;
}
//*******************************************************************************************
void ListaOrdenadaRepAlta::pintar()
{
	CajaRepeticion *p;

	p = principio;

	while(p){
		std::cout << "[" << p->valor << ", " << p->cuantos << "], ";
		p = p->siguiente;
	}
	std::cout << "\b\b ";
}
//*******************************************************************************************
int ListaOrdenadaRepAlta::cuantosSon()
{
    return cuantos;
}
//*******************************************************************************************
CajaRepeticion * ListaOrdenadaRepAlta::LugarAgregado()
{
    return lugar_agregado;
}

//*******************************************************************************************






























