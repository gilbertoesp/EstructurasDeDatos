/**
	GEM-.cpp
[Descripcion]
 Gilberto Espinoza
@date
*/

#include <iostream>
#include <cstdlib>
#include "pila.h"
#include "caja.h"

//**********************************************************************
pila::pila()
{
    this->principio = NULL;
    this->cuantos = 0;
}
//**********************************************************************
void pila::agregar(int a)
{
    caja *p;

    p = new caja;

    p->valor;

    if(!principio){
        p->siguiente = NULL;
        principio = p;
    }else{
        p->siguiente = principio;
        principio = p;
    }
    cuantos++;
}
//**********************************************************************
#define VACIO 999999999999999
int pila::sacar()
{
    caja *p;
    int valor;
    if(principio){
        p = principio;
        principio = principio->siguiente;

        valor = p->valor;

        delete p;

        cuantos--;
    }else{
        valor = VACIO;
    }

    return valor;
}
//**********************************************************************

//**********************************************************************

//**********************************************************************

//**********************************************************************


