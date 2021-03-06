/**
    Listas de adyacencia para algun nodo en Grafica, ya sea entrante o saliente
    Esta estructura ordena de menor a mayor los identificadores (int) de los nodos que estan conectados
    a otro nodo

	\author Gilberto Espinoza
*/
#include <iostream>
#include <cstdlib>

#include "CajaArco.h"
#include "CajaNodo.h"
#include "ListaArcos.h"

//*************************************************************************************************
ListaArcos::ListaArcos()
{
    principio = lugar_agregado = NULL;

    anterior = NULL;
    donde = VACIO;
}
//*************************************************************************************************
void ListaArcos::constructor()
{
    principio = lugar_agregado = NULL;

    anterior = NULL;
    donde = VACIO;
}
//*************************************************************************************************
ListaArcos::~ListaArcos()
{
    CajaArco *p;

    while(principio){
        p = principio;
        principio = p->siguiente;
        delete p;
    }
    principio = lugar_agregado = NULL;

    anterior = NULL;
    donde = VACIO;
}
//*************************************************************************************************
void ListaArcos::destructor()
{
    CajaArco *p;

    while(principio){
        p = principio;
        principio = p->siguiente;
        delete p;
    }
    principio = lugar_agregado = NULL;
    anterior = NULL;
    donde = VACIO;
}
//*************************************************************************************************
bool ListaArcos::buscar(int id)
{
    CajaArco *p = NULL;

    bool encontrado = false;
    donde = VACIO;
    anterior = NULL;

    p = principio;
    while(p){
        //Todavia no llegamos al valor buscado
        if(p->id < id){
            anterior = p;
            p = p->siguiente;
            //Verificamos si no llegamos al final de la Lista
            if(!p)						donde = FINAL;
        //Hemos encontrado el valor buscado
        }else if(p->id == id){
            encontrado = true;
            //Vemos en que seccion de la lista se encuentra
            if(p == principio)			donde = PRINCIPIO;
            else if(!p->siguiente)		donde = FINAL;
            else						donde = EN_MEDIO;
            //Dado que se encontro, regresamos
            break;
        //Llegamos a un elemento mayor al buscado y no se encontro
        }else{
            if(!anterior)				donde = PRINCIPIO;
            else						donde = EN_MEDIO;
            //Como el ya estamos en un valor mayor al cual buscamos, regresamos
            break;
        }
    }
    return encontrado;
}
//*************************************************************************************************
bool ListaArcos::agregar(int id)
{
	CajaArco *p;
	//Mandamos buscar el valor que queremos agregar para ponerlo en el lugar que correspon
	if(buscar(id)) return false;

	p = new CajaArco;
	p->id = id;
	p->direccion_nodo = NULL;
	p->longitud = 0.0;

    lugar_agregado = p;

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
			return false;
	}
	return true;
}
//*************************************************************************************************
bool ListaArcos::borrar(int id)
{
	CajaArco *p = NULL;
	//Buscamos el elemento a borrar
	if(!buscar(id)) return false;

	if(!anterior){
		p = principio;
		principio = p->siguiente;
	}else{
		p = anterior->siguiente;
		anterior->siguiente = p->siguiente;
	}

	delete p;

	return true;
}
//*************************************************************************************************
void ListaArcos::pintar()
{
	CajaArco *p;

	p = principio;

	while(p){
		std::cout << "[" << p->id << ", " << p->longitud << "], ";
		p = p->siguiente;
	}
	std::cout << "\b\b ";
}
//*************************************************************************************************
CajaArco * ListaArcos::Principio()
{
    return principio;
}
