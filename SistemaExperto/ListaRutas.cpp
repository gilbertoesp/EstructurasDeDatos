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
bool ListaRutas::buscar(float longitud)
{
    CajaRuta *p = NULL;

    bool encontrado = false;
    donde = VACIO;
    anterior = NULL;

    p = principio;
    while(p){
        //Todavia no llegamos al valor buscado
        if(  p->longitud_minima < longitud   ){
            anterior = p;
            p = p->siguiente;
            //Verificamos si no llegamos al final de la Lista
            if(!p)						donde = FINAL;
        //Hemos encontrado el valor buscado
        }else if( p->longitud_minima == longitud ){
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
bool ListaRutas::agregar(CajaNodo *direccion, float longitud)
{
    CajaRuta *p;

    //Mandamos buscar el valor que queremos agregar para ponerlo en el lugar que correspon
	if(buscar(longitud)) return false;

	p = new CajaRuta;
	p->longitud_minima = longitud;
	p->direccion_nodo = direccion;

	lugar_agregado = p;

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
	return true;
}
//*************************************************************************************************
bool ListaRutas::borrar()
{
    return false;
}
//*************************************************************************************************
CajaNodo * ListaRutas::sacar()
{
    CajaRuta *p;

    if(!principio){
        return NULL;
    }

    p = principio;

    principio = principio->siguiente;
    principio->anterior = NULL;
    p->siguiente = NULL;

    return p->direccion_nodo;
}
//*************************************************************************************************
void ListaRutas::pintarAsc()
{
    CajaRuta *p;
	p = principio;

	while(p){
		std::cout << "[" << p->direccion_nodo->id << ", " << p->longitud_minima << "], ";
		p = p->siguiente;
	}
	std::cout << "\b\b ";
}
//*************************************************************************************************
void ListaRutas::pintarDes()
{
    CajaRuta *p;
	p = final;

	while(p){
		std::cout << "[" << p->direccion_nodo->id << ", " << p->longitud_minima << "], ";
		p = p->anterior;
	}
	std::cout << "\b\b ";
}
//*************************************************************************************************
void ListaRutas::ajustar(CajaRuta *nodo, float nueva_ruta)
{
    nodo->longitud_minima = nueva_ruta;

    if(nodo == principio || nodo->anterior->longitud_minima > nodo->longitud_minima){
        return;
    }

    CajaRuta *p;

    p = nodo->anterior;

    p->siguiente = nodo->siguiente;

    if(nodo->siguiente) nodo->siguiente->anterior = p;
    else final = p;

    while(p && p->longitud_minima > nodo->longitud_minima){
        p = p->anterior;
    }

    if(!p){
        nodo->anterior = NULL;
        nodo->siguiente = principio;
        principio->anterior = nodo;
        principio = nodo;
    }else{
        nodo->siguiente = p->siguiente;
        nodo->anterior = p;
        nodo->siguiente->anterior = nodo;
        p->siguiente = nodo;
    }
}
//*************************************************************************************************
CajaNodo * ListaRutas::pop()
{
    CajaRuta *p;
    CajaNodo *nodo;

    p = principio;

    if (!principio) return NULL;

    nodo = p->direccion_nodo;

    principio = p->siguiente; //Recorre la pila una posicion hacia abajo.
    delete p;

    return nodo;
}
//*************************************************************************************************
void ListaRutas::push(CajaNodo *a)
{
    CajaRuta *nuevo;

    nuevo = new CajaRuta;

    nuevo->direccion_nodo = a;

    //Mueve el principio hacia arriba una unidad.
    nuevo->siguiente = principio;
    principio = nuevo;
}
//*************************************************************************************************
