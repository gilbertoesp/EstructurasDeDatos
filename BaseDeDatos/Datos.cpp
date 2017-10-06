/**
    Estructura tipo Pila que guarda los datos de la base de datos

	\author Gilberto Espinoza
*/
#include <iostream>
#include <cstdlib>

#include "Datos.h"
#include "Persona.h"
//*************************************************************************************************
Datos::~Datos()
{
    Persona * p;

    while(principio){
        p = principio;
        principio = principio->siguiente;
        delete p;
    }
    principio = lugar_agregado = NULL;
}

//*************************************************************************************************
void Datos::agregar(std::string nombre, std::string  apellido)
{
    Persona *p;
     p = new Persona;

     p->nombre = nombre;
     p->apellido = apellido;

     if(!principio){
        p->siguiente = NULL;
        principio = p;
     }else{
        p->siguiente = principio;
        principio = p;
     }
    ///Definimos lugar agregado
     lugar_agregado = p;
}

//*************************************************************************************************
