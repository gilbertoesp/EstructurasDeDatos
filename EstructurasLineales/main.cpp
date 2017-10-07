/**
    Estructuras Lineales

*/
#include <cstdlib>
#include <iostream>
//Librerias de la estructuras
#include "Pila.h"
#include "Cola.h"
#include "ListaOrdenada.h"
#include "ListaOrdenadaRepBaja.h"
#include "ListaOrdenadaRepAlta.h"
#include "ListaDobleLigada.h"
#include "ListaMitad.h"
#include "ListaOrdenadaRepAlta.h"
#include "ListaOrdenadaRepAlta.h"

int main()
{
    std::cout << "\t\tESTRUCTURAS LINEALES\n" << std::endl;
//*************************************************************************************************************************************
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
//*************************************************************************************************************************************
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
//*************************************************************************************************************************************
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
//*************************************************************************************************************************************
    std::cout << "\n\n\t\t\tLISTA ORDENADA CON REPETICION BAJA\n" << std::endl;
    std::cout << "Agregando 8, 5, 9, 4, 7, 8, 4 a la Lista" << std::endl;
    ListaOrdenadaRepBaja listaRB;
    listaRB.agregar(8);
    listaRB.agregar(5);
    listaRB.agregar(9);
    listaRB.agregar(4);
    listaRB.agregar(7);
    listaRB.agregar(8);
    listaRB.agregar(4);
    listaRB.agregar(9);
    listaRB.agregar(9);
    std::cout << "\nPintando Lista: " << std::endl;
    listaRB.pintar();
    std::cout << std::endl;
    std::cout << "Cantidad de elementos en la Lista: " << listaRB.cuantosSon() << std::endl;
    std::cout << "\nSacando el primer valor de la listaRB: " << listaRB.sacar() << std::endl;
    std::cout << "\nPintando Lista: " << std::endl;
    listaRB.pintar();
    std::cout << std::endl;
    std::cout << "Eliminando el elemento 8" << std::endl;
    listaRB.borrar(8);
    std::cout << "\nPintando Lista: " << std::endl;
    listaRB.pintar();
    std::cout << std::endl;
//*************************************************************************************************************************************
    std::cout << "\n\n\t\t\tLISTA ORDENADA CON REPETICION ALTA\n" << std::endl;
    std::cout << "Agregando 8, 5, 9, 4, 7, 8, 4 a la Lista" << std::endl;
    ListaOrdenadaRepAlta listaRA;
    listaRA.agregar(8);
    listaRA.agregar(5);
    listaRA.agregar(9);
    listaRA.agregar(4);
    listaRA.agregar(7);
    listaRA.agregar(8);
    listaRA.agregar(4);
    std::cout << "\nPintando Lista: " << std::endl;
    listaRA.pintar();
    std::cout << std::endl;
    std::cout << "Cantidad de elementos en la Lista: " << listaRA.cuantosSon() << std::endl;
    std::cout << "\nSacando el primer valor de la listaRA: " << listaRA.sacar() << std::endl;
    std::cout << "\nPintando Lista: " << std::endl;
    listaRA.pintar();
    std::cout << std::endl;
    std::cout << "Eliminando el elemento 8" << std::endl;
    listaRA.borrar(8);
    std::cout << "\nPintando Lista: " << std::endl;
    listaRA.pintar();
    std::cout << std::endl;
    std::cout << "Eliminando el elemento 8" << std::endl;
    listaRA.borrar(8);
    std::cout << "\nPintando Lista: " << std::endl;
    listaRA.pintar();
    std::cout << std::endl;
//*************************************************************************************************************************************
    std::cout << "\n\n\t\t\tLISTA DOBLE LIGADA\n" << std::endl;
    std::cout << "Agregando 8, 5, 9, 4, 7 a la Lista" << std::endl;
    ListaDobleLigada listaDL;
    listaDL.agregar(8);
    listaDL.agregar(5);
    listaDL.agregar(9);
    listaDL.agregar(4);
    listaDL.agregar(7);
    std::cout << "\nPintando Lista 1: ";
    listaDL.pintar1();
    std::cout << std::endl;
    std::cout << "\nPintando Lista 2: ";
    listaDL.pintar2();
    std::cout << std::endl;
    std::cout << "Cantidad de elementos en la Lista: " << listaDL.cuantosSon() << std::endl;
    std::cout << "\nSacando el primer valor de la listaDL: " << listaDL.sacar() << std::endl;
    std::cout << "\nPintando Lista 1: ";
    listaDL.pintar1();
    std::cout << std::endl;
    std::cout << "\nPintando Lista 2: ";
    listaDL.pintar2();
    std::cout << std::endl;
    std::cout << "Eliminando el elemento 8" << std::endl;
    listaDL.borrar(8);
    std::cout << std::endl;
    std::cout << "\nPintando Lista 1: ";
    listaDL.pintar1();
    std::cout << std::endl;
    std::cout << "\nPintando Lista 2: ";
    listaDL.pintar2();
    std::cout << std::endl;
//*************************************************************************************************************************************
    std::cout << "\n\n\t\t\tLISTA CON MITAD\n" << std::endl;
    std::cout << "Agregando 8, 5, 9, 4, 7, 6, 3, 0 a la Lista" << std::endl;
    ListaMitad listaM;
    listaM.agregar(8);
    listaM.agregar(5);
    listaM.agregar(9);
    listaM.agregar(4);
    listaM.agregar(7);
    listaM.agregar(6);
    listaM.agregar(3);
    listaM.agregar(0);
    std::cout << "\nPintando Lista: " << std::endl;
    listaM.pintar();
    std::cout << std::endl;
    std::cout << "\nCantidad de elementos en la Lista: " << listaM.cuantosSon() << std::endl;
    std::cout << "Cantidad de Mayores: " << listaM.mayoresSon() << std::endl;
    std::cout << "Cantidad de menores: " << listaM.menoresSon() << std::endl;
    std::cout << "\tMitad de la lista: " << listaM.Mitad()->valor << std::endl;
    std::cout << "\nSacando el primer valor de la listaM: " << listaM.sacar() << std::endl;
    std::cout << "\nCantidad de elementos en la Lista: " << listaM.cuantosSon() << std::endl;
    std::cout << "\nPintando Lista: " << std::endl;
    listaM.pintar();
    std::cout << std::endl;
    std::cout << "\nPintando Lista: " << std::endl;
    listaM.pintar();
    std::cout << std::endl;
//*************************************************************************************************************************************
    std::cout << "\n\n" << std::endl;
    system("pause");
    return 0;
}
