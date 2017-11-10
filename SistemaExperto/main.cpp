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
    std::cout << "SISTEMA EXPERTO\n" << std::endl;
    std::cout << "Las opciones son: " << std::endl;
    std::cout << "->\tONZA" << std::endl;
    std::cout << "->\tTIGRE" << std::endl;
    std::cout << "->\tCEBRA" << std::endl;
    std::cout << "->\tAVESTRUZ" << std::endl;
    std::cout << "->\tPINGUINO" << std::endl;
    std::cout << "->\tALBATROS" << std::endl;


    Grafica sistema;

    sistema.cargar();

    sistema.ejecutar();

    system("pause");
    return 0;
}

//*************************************************************************************************


//*************************************************************************************************
