/**
	Grafica.cpp

	Simulacion de una grafica.
	Para aparentar la estructura de una grafica se hace referencia a las conexiones entre los nodos, con
	listas de adyacencia, cada Nodo de la grafica, contiene sus propias listas, entrada y salida.

	\author Gilberto Espinoza
*/
#include <iostream>
#include <cstdlib>

#include "Grafica.h"
//*************************************************************************************************
Grafica::Grafica()
{
    grafica.constructor();
}
//*************************************************************************************************
Grafica::~Grafica()
{
    grafica.destructor();
}
//*************************************************************************************************
void Grafica::agregar_arco(int a, int b, float longitud /* = 0 */)
{
    CajaNodo *nodo_a, *nodo_b;
    CajaArco *arco;

    grafica.agregar(a);
    nodo_a = grafica.LugarAgregado();
    nodo_a->salientes.agregar(b);
    //El arco recien creado
    arco = nodo_a->salientes.LugarAgregado();
    arco->longitud = longitud;

    grafica.agregar(b);
    nodo_b = grafica.LugarAgregado();
    // Al arco le decimos donde se encuentra dentro de grafica
    arco->direccion_nodo = nodo_b;

    nodo_b->entrantes.agregar(a);
    arco = nodo_b->entrantes.LugarAgregado();
    arco->longitud = longitud;
    // Igual al arco entrante de b le decimos que su posicion en la grafica es el nodo_a
    arco->direccion_nodo = nodo_a;
}
//*************************************************************************************************
void Grafica::calcular_ruta_corta(int a, int b)
{

}
//*************************************************************************************************
void Grafica::pintar()
{
    grafica.pintar();
}
//*************************************************************************************************
