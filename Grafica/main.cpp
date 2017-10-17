/**
	...

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

    grafica.agregar_arco(1,2,5);

    grafica.pintar();

    system("pause");
    return 0;
}

//*************************************************************************************************
