/**
	...

	\author Gilberto Espinoza
*/
#include <iostream>
#include <cstdlib>

#include "BaseDatos.h"
//*************************************************************************************************
int main()
{
    BaseDatos database;

    database.agregar("Fernando", "Sotomayor");
    database.agregar("Alejandro", "Sanz");
    database.agregar("Zarina", "Garcia");

    std::cout << "------Orden por Nombre -------" << std::endl;
    database.pintarNombre();
    std::cout << "------Orden por Apellido -------" << std::endl;
   database.pintarApellido();
}

//*************************************************************************************************


//*************************************************************************************************
