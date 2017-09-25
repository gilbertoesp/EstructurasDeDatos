/**
    Estructuras Lineales

*/
#include <cstdlib>
#include <iostream>
//Librerias de la estructuras
#include "Pila.h"
#include "Cola.h"
#include "ListaOrdenada.h"

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
    std::cout << "\nPintando Pila: ";
    pila.pintar();
    std:: cout << std::endl;
    std::cout << "Cantidad de elementos en la Pila: " << pila.cuantosSon() << std::endl;
    std::cout << std::endl << "Sacando el valor: " << pila.sacar() << std::endl;
    std::cout << "\nPintando Pila: ";
    pila.pintar();
    std:: cout << std::endl;
    std::cout << "Cantidad de elementos en la Pila: " << pila.cuantosSon() << std::endl;

    std::cout << "\n\n\t\t\tCOLA\n" << std::endl;
    std::cout << "Agregando 8, 5, 9, 4 a la Cola" << std::endl;
    Cola cola;
    cola.agregar(8);
    cola.agregar(5);
    cola.agregar(9);
    cola.agregar(4);
    std::cout << "\nPintando Cola: " << std::endl;
    cola.pintar();
    std::cout << std::endl;
    std::cout << "Cantidad de elementos en la Cola: " << cola.cuantosSon() << std::endl;
    std::cout << "\nSacando el primer elemento de la Cola: " << cola.sacar() << std::endl;
    std::cout << "\nPintando Cola: " << std::endl;
    cola.pintar();
    std::cout << std::endl;
    std::cout << "Cantidad de elementos en la Cola: " << cola.cuantosSon() << std::endl;

    std::cout << "\n\n\t\t\tLISTA ORDENADA\n" << std::endl;
    std::cout << "Agregando 8, 5, 9, 4, 7 a la Lista" << std::endl;
    ListaOrdenada lista;
    lista.agregar(8);
    lista.agregar(5);
    lista.agregar(9);
    lista.agregar(4);
    lista.agregar(7);
    std::cout << "\nPintando Lista: " << std::endl;
    lista.pintar();
    std::cout << std::endl;
    std::cout << "Cantidad de elementos en la Lista: " << lista.cuantosSon() << std::endl;
    std::cout << "\nSacando el primer valor de la lista: " << lista.sacar() << std::endl;
    std::cout << "\nPintando Lista: " << std::endl;
    lista.pintar();
    std::cout << std::endl;
    std::cout << "Eliminando el elemento 8" << std::endl;
    lista.borrar(8);
    std::cout << "\nPintando Lista: " << std::endl;
    lista.pintar();
    std::cout << std::endl;


    system("pause");
    return 0;
}
