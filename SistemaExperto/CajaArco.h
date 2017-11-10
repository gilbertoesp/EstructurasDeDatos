#ifndef CAJAARCO_H_INCLUDED
#define CAJAARCO_H_INCLUDED

/**
	Estructura que hace referencia a un nodo, ubicado con (int) id.
	Esta estructura es auxiliar a los objetos tipo "Grafica". Se puede organizar como si de una Lista Ordenada
	se tratase gracias a la variable (CajaArco *) siguiente.


	\author Gilberto Espinoza
*/
//#include "CajaNodo.h"
struct CajaNodo;
//*************************************************************************************************
/**
	...
	\param id               : Identificador del nodo al que esta estructura hacce referencia
	\param siguiente        : Siguiente en una supuesta lista de arcos. Default = NULL
	\param direccion_nodo   : Direccion del nodo id, en la Lista de Nodos, que es la grafica en si
*/
struct CajaArco{
    int id;
    CajaArco * siguiente = NULL;
    CajaNodo * direccion_nodo = NULL;
    bool inversor;
};

//*************************************************************************************************


#endif // CAJAARCO_H_INCLUDED
