/**
    ListaNodos.cpp
    Estructura que simula una grafica con nodos y sus arcos

	\author Gilberto Espinoza
*/
#include <iostream>
#include <cstdlib>

#include "CajaNodo.h"
#include "ListaNodos.h"

//*************************************************************************************************
ListaNodos::ListaNodos()
{
    principio = lugar_agregado = NULL;

    anterior = NULL;
    donde = VACIO;
}
//*************************************************************************************************
void ListaNodos::constructor()
{
    principio = lugar_agregado = NULL;

    anterior = NULL;
    donde = VACIO;
}
//*************************************************************************************************
ListaNodos::~ListaNodos()
{
    CajaNodo *p;

    while(principio){
        p = principio;
        principio = principio->siguiente;

        p->entrantes.destructor();
        p->salientes.destructor();

        delete p;
    }
    principio = lugar_agregado = NULL;

    anterior = NULL;
    donde = VACIO;
}
//*************************************************************************************************
void ListaNodos::destructor()
{
    CajaNodo *p;

    while(principio){
        p = principio;
        principio = principio->siguiente;

        p->entrantes.destructor();
        p->salientes.destructor();

        delete p;
    }
    principio = lugar_agregado = NULL;

    anterior = NULL;
    donde = VACIO;
}
//*************************************************************************************************
bool ListaNodos::buscar(int id)
{
    CajaNodo *p = NULL;

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
bool ListaNodos::agregar(int id)
{
	CajaNodo   *p;
	//Mandamos buscar el valor que queremos agregar para ponerlo en el lugar que correspone
    //Si se encontro lo definimos en lugar_agregado
	if(buscar(id)){
        if(anterior)    lugar_agregado = anterior->siguiente;
        else            lugar_agregado = principio;
        return false;
	}

	p = new CajaNodo;
	p->id = id;
	p->salientes.constructor();
	p->entrantes.constructor();

	p->longitud_ruta = 0.0;
    p->antecesor = NULL;
    p->bandera = RUTA_NO_EVALUADA;

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
bool ListaNodos::borrar(int id)
{
    CajaNodo * p;
    //Buscamos el elemento a borrar
	if(!buscar(id)) return false;

	if(!anterior){
		p = principio;
		principio = p->siguiente;
	}else{
		p = anterior->siguiente;
		anterior->siguiente = p->siguiente;
	}
    //Destruimos sus conexiones
    p->entrantes.destructor();
    p->salientes.destructor();

	delete p;

	return true;
}
//*************************************************************************************************
void ListaNodos::pintar()
{
    CajaNodo *p;

    p = principio;
    while(p){
        std::cout << "Nodo ID: " << p->id << std::endl;
        std::cout << "Arcos entrantes: ";
        p->entrantes.pintar();
        std::cout << std::endl;
        std::cout << "Arcos salientes: ";
        p->salientes.pintar();
        std::cout << std::endl << "---------------" << std::endl;
        p = p->siguiente;
    }
}
//*************************************************************************************************
