#ifndef CAJARUTA_H_INCLUDED
#define CAJARUTA_H_INCLUDED

/**
	...

	\author Gilberto Espinoza
*/
#include "CajaNodo.h"
//*************************************************************************************************
/**

	\param direccion_nodo   : Posicion en la grafica al nodo al que haccemos referencia
	\param longitud_minima  : Longitud total para llegar  al nodo direccion_nodo
	\param siguiente        : Siguiente en la lista de rutas
	// ?????
	\param anterior

*/
struct CajaRuta{
    CajaNodo * direccion_nodo;
    float longitud_minima;
    CajaRuta *siguiente, *anterior;
};

//*************************************************************************************************


#endif // CAJARUTA_H_INCLUDED
