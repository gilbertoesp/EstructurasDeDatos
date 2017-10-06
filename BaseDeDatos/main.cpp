/**
	Simulacion de una base de datos que recibe los datos de una persona, nombre y apellido, y estos los guarda
	en una pila (con datos tipo Persona). Una vez agregados a la pila se agregan a las listas ListaNombre y ListaApellido
	que se encargan de organizar los datos por orden alfabetico ya sea empezando con el Nombre o con el Apellido.
	Los datos agregados a esta pila (Datos), son a su vez agregados a las Listas, las cuales son creadas con estructuras (Caja)
	que pueden almacenar el dato (Persona *) y la siguiente estrucutra de la lista (Caja *). Organizando los datos en estas lista
	pueden ser impresos y ver los resultados de que en efecto estan ordenados.

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
            //Agregando nombre
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
