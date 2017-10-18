/**
    Dijkstra

	\author Gilberto Espinoza
*/
#include <iostream>
#include <cstdlib>

#include "Grafica.h"
//*************************************************************************************************
int main()
{
    std::cout << "\t\t GRAFICAS " << std::endl;
    Grafica grafica;

    grafica.agregar_arco(1,2,2);
    grafica.agregar_arco(1,3,3);
    grafica.agregar_arco(1,4,4);
    grafica.agregar_arco(2,5,1);

    grafica.agregar_arco(3,5,2);
    grafica.agregar_arco(4,3,3);
    grafica.agregar_arco(4,6,5);
    grafica.agregar_arco(5,6,4);


    grafica.pintar();

    system("pause");
    return 0;
}

//*************************************************************************************************
