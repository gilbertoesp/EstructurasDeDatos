#ifndef CAJANODO_H_INCLUDED
#define CAJANODO_H_INCLUDED

/**
	...

	\author Gilberto Espinoza
*/

#include "ListaArcos.h"
//*************************************************************************************************
/**
	...
	\param
	\return
*/
struct CajaNodo{
    int id;
    CajaNodo * siguiente;
    ListaArcos salientes, entrantes;
};

//*************************************************************************************************


#endif // CAJANODO_H_INCLUDED
