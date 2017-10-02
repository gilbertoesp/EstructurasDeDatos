/**
    Estructura base para la Base de Datos, que contiene variables para guardar el nombre de una persona,
    y la que sigue
*/
#ifndef CAJAPERSONA_H_INCLUDED
#define CAJAPERSONA_H_INCLUDED

#include <string>

struct CajaPersona{
    std::string nombre, apellido;
    CajaPersona * siguiente;
};

#endif // CAJAPERSONA_H_INCLUDED
