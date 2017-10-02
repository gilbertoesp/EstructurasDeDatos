/**

*/
#include <cstdlib>
#include <iostream>

#include <string>
#include "BaseDeDatos.h"
//******************************************************************************************
BaseDeDatos::BaseDeDatos()
{
    data.iniciar();
}
//******************************************************************************************
BaseDeDatos::~BaseDeDatos()
{
    data.destruir();
}
//******************************************************************************************
bool BaseDeDatos::agregar(std::string nombre, std::string apellido)
{
    CajaPersona *p;

    data.agregar(nombre, apellido);

    p = data.lugarAgregado();

    data.pintarNombre();

}
//******************************************************************************************
//bool borrar(string nombre, string apellido);
