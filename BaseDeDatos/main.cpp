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
    std::string nombre, apellido;

    int opcion;
    do{
        std::cout << "[0] SALIR" << std::endl;
        std::cout << "[1] AGREGAR" << std::endl;
        std::cout << "[2] IMPRIMIR POR NOMBRE" << std::endl;
        std::cout << "[3] IMPRIMIR POR APELLIDO" << std::endl;

        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch(opcion){
        case 0:
            break;
        case 1:
            std::cout << "Nombre: ";
            std::cin >> nombre;
            std::cout << "Apellido: ";
            std::cin >> apellido;
            database.agregar(nombre,apellido);
            break;
        case 2:
                database.pintarNombre();
            break;
        case 3:
                database.pintarApellido();
            break;
        }
    }while(opcion != 0);

    system("pause");
    return 1;
}

//*************************************************************************************************


//*************************************************************************************************
