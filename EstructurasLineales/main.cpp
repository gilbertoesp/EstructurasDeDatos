/**
    Estructuras Lineales

*/
#include <cstdlib>
#include <iostream>
//Librerias de la estructuras
#include "Pila.h"
int main()
{
    std::cout << "\t\tESTRUCTURAS LINEALES\n" << std::endl;

    std::cout << "\t\t\tPILA\n" << std::endl;

    std::cout << "Agregando 8, 5, 9, 4 a la Pila" << std::endl;
    Pila pila;
    pila.agregar(8);
    pila.agregar(5);
    pila.agregar(9);
    pila.agregar(4);
    std::cout << "Pintando Pila: ";
    pila.pintar();
    std:: cout << std::endl;
    std::cout << "Cantidad de elementos en la Pila: " << pila.cuantosSon() << std::endl;
    std::cout << std::endl << "Sacando el valor: " << pila.sacar() << std::endl;
    std::cout << "Pintando Pila: ";
    pila.pintar();
    std:: cout << std::endl;
    std::cout << "Cantidad de elementos en la Pila: " << pila.cuantosSon() << std::endl;

    std::cout << "\n\n\t\t\tCOLA\n" << std::endl;



    system("pause");
    return 0;
}
