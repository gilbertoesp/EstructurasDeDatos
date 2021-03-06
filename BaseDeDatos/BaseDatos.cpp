/**
	Base de datos que agrega los nombre y apellidos de las personas a la pila de datos (data) y a las listas
	ordenadas ordenNombre y ordenApellido

	\author Gilberto Espinoza
*/
#include <iostream>
#include <cstdlib>

#include "BaseDatos.h"
#include <string>
//*************************************************************************************************
void BaseDatos::agregar(std::string nombre, std::string apellido)
{
    data.agregar(nombre,apellido);
    ordenNombre.agregar(data.lugarAgregado());
    ordenApellido.agregar(data.lugarAgregado());
}
//*************************************************************************************************
void BaseDatos::pintarNombre()
{
    std::cout << "----Orden por Nombre -----" << std::endl;
    ordenNombre.pintar();
    std::cout << "--------------------------" << std::endl;
}
//*************************************************************************************************
void BaseDatos::pintarApellido()
{
    std::cout << "----Orden por Apellido -----" << std::endl;
    ordenApellido.pintar();
    std::cout << "--------------------------" << std::endl;
}
//*************************************************************************************************
