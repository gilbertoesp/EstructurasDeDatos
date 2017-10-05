/**
	...

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
    //ordenApellido(data.lugarAgregado());
}
//*************************************************************************************************
void BaseDatos::pintarNombre()
{
    std::cout << "----Orden por Nombre -----" << std::endl;
    ordenNombre.pintar();
}

//*************************************************************************************************
