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
void Grafica::agregar_arco(int a, int b)
{
    CajaNodo *p;

    grafica.agregar(a);
    p = grafica.LugarAgregado();
    p->salientes.agregar(b);

    grafica.agregar(b);
    p = grafica.LugarAgregado();
    p->entrantes.agregar(a);
}
//*************************************************************************************************
void Grafica::pintar()
{
    grafica.pintar();
}
//*************************************************************************************************
