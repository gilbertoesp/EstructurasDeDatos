/**
	Datos.cpp
    Estructura Lineal tipo Datos que segui la naturaleza de First Out Last Out.
    Con la estructura tipo CajaPersona

 Gilberto Espinoza
@date
*/

#include <iostream>
#include <cstdlib>

#include <string>
#include "Datos.h"
#include "CajaPersona.h"

//**********************************************************************
Datos::Datos()
{
    this->principio = NULL;
    this->cuantos = 0;
}
//**********************************************************************
Datos::~Datos()
{
    CajaPersona *p;

    while(principio){
        p = principio;
        principio = principio->siguiente;
        delete p;
    }
    principio = NULL;
    cuantos = 0;
}
//**********************************************************************
void Datos::iniciar()
{
    this->principio = NULL;
    this->cuantos = 0;
}
//**********************************************************************
void Datos::destruir()
{
    CajaPersona *p;

    while(principio){
        p = principio;
        principio = principio->siguiente;
        delete p;
    }
    principio = NULL;
    cuantos = 0;
}
//**********************************************************************
void Datos::agregar(std::string nombre, std::string apellido)
{
    CajaPersona *p;

    p = new CajaPersona;

    p->nombre = nombre;
    p->apellido = apellido;

    if(!principio){
        p->siguiente = NULL;
        principio = p;
    }else{
        p->siguiente = principio;
        principio = p;
    }
    lugar_agregado = p;
    cuantos++;
}
//**********************************************************************
#define VACIO 999999
std::string Datos::sacar()
{
    CajaPersona *p;
    std::string dato;

    if(principio){
        p = principio;
        principio = principio->siguiente;

        p->nombre + " " + p->apellido;

        delete p;
        cuantos--;
    }else{
        dato = "NULL";
    }

    return dato;
}
//**********************************************************************
void Datos::pintarNombre()
{
    CajaPersona *p;
    p = principio;

    while(p){
        std::cout << p->nombre << " " << p->apellido << std::endl;
        p = p->siguiente;
    }
}
//**********************************************************************
void Datos::pintarApellido()
{
    CajaPersona *p;
    p = principio;

    while(p){
        std::cout << p->apellido << " " << p->nombre << std::endl;
        p = p->siguiente;
    }
}
//**********************************************************************
int Datos::cuantosSon()
{
    return cuantos;
}
//**********************************************************************
CajaPersona * Datos::lugarAgregado()
{
    return lugar_agregado;
}
//**********************************************************************


