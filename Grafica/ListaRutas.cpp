/**
	...

	\author Gilberto Espinoza
*/
#include <iostream>
#include <cstdlib>

#include "ListaRutas.h"
#include "CajaRuta.h"
//*************************************************************************************************
ListaRutas::ListaRutas()
{
    principio = lugar_agregado = NULL;

    anterior = NULL;
    donde = VACIO;
}
//*************************************************************************************************
void ListaRutas::constructor()
{
    principio = lugar_agregado = NULL;

    anterior = NULL;
    donde = VACIO;
}
//*************************************************************************************************
ListaRutas::~ListaRutas()
{
    CajaRuta *p;

    while(principio){
        p = principio;
        principio = principio->siguiente;
        delete p;
    }
    principio = lugar_agregado = NULL;

    anterior = NULL;
    donde = VACIO;
}
//*************************************************************************************************
void ListaRutas::destructor()
{
    CajaRuta *p;

    while(principio){
        p = principio;
        principio = principio->siguiente;
        delete p;
    }
    principio = lugar_agregado = NULL;

    anterior = NULL;
    donde = VACIO;
}
//*************************************************************************************************
bool ListaRutas::buscar()
{
    CajaRuta *p = NULL;

    bool encontrado = false;
    donde = VACIO;
    anterior = NULL;

    p = principio;
    while(p){
        //Todavia no llegamos al valor buscado
        if(       false          ){
            anterior = p;
            p = p->siguiente;
            //Verificamos si no llegamos al final de la Lista
            if(!p)						donde = FINAL;
        //Hemos encontrado el valor buscado
        }else if(           false              ){
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
bool ListaRutas::agregar()
{
    CajaRuta *p;

    if(buscar(              )) return false;

    p = new CajaRuta;
    p->direccion_nodo = NULL;
    p->longitud = 0.0;

    p->anterior = NULL;

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
bool ListaRutas::borrar()
{
    return false;
}
//*************************************************************************************************
void ListaRutas::pintar()
{

}
//*************************************************************************************************

//*************************************************************************************************

//*************************************************************************************************
