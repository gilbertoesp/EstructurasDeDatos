#ifndef CAJA_H_INCLUDED
#define CAJA_H_INCLUDED

/**
    Estructura que guarda la direccion a otra estructura (Persona), y ademas contiene (Caja *) siguiente
    que sirve para generar una estructura lineal

	\author Gilberto Espinoza
*/
#include "Persona.h"
//*************************************************************************************************
/**
	...
	\param
	\return
*/
struct Caja{
    Persona * persona;
    Caja * siguiente;
};
//*************************************************************************************************
/**
	...
	\param
	\return
*/

//*************************************************************************************************


#endif // CAJA_H_INCLUDED
