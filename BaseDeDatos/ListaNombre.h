#ifndef LISTANOMBRE_H_INCLUDED
#define LISTANOMBRE_H_INCLUDED

/**
	...

	\author Gilberto Espinoza
*/
#include "Caja.h"
#include "Persona.h"
#include "Enumeraciones.h"
//*************************************************************************************************
/**
	...
	\param
	\return
*/
class ListaNombre{
    Caja *principio, *anterior;
    Boolean encontrado;
    Posicion donde;
public:
/**
	...
	\param
	\return
*/
    ListaNombre() {principio = anterior = NULL;}
/**
	...
	\param
	\return
*/
    ~ListaNombre();
/**
	...
	\param
	\return
*/
    void buscar(Persona *persona);
/**
	...
	\param
	\return
*/
    void agregar(Persona *persona);
/**
	...
	\param
	\return
*/
    void pintar();
};
//*************************************************************************************************
/**
	...
	\param
	\return
*/

//*************************************************************************************************


#endif // LISTANOMBRE_H_INCLUDED
