/**
	Pila.cpp
    Estructura Lineal tipo Pila que segui la naturaleza de First Out Last Out.

 Gilberto Espinoza
@date
*/

#include <iostream>
#include <cstdlib>
#include "Pila.h"
#include "Caja.h"

//**********************************************************************
Pila::Pila()
{
    this->principio = NULL;
    this->cuantos = 0;
}
//**********************************************************************
Pila::~Pila()
{
    Caja *p;

    while(principio){
        p = principio;
        principio = principio->siguiente;
        delete p;
    }
    principio = NULL;
    cuantos = 0;
}
//**********************************************************************
void Pila::agregar(int a)
{
    Caja *p;

    p = new Caja;

    p->valor = a;

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
#define VACIO 999999
int Pila::sacar()
{
    Caja *p;
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
void Pila::pintar()
{
    Caja *p;
    p = principio;

    while(p){
        std::cout << p->valor << " ";
        p = p->siguiente;
    }
}
//**********************************************************************
int Pila::cuantosSon()
{
    return cuantos;
}
//**********************************************************************

//**********************************************************************


