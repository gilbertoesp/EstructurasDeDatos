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
    ListaNombre() {principio = anterior = NULL;}

    ~ListaNombre();

    void buscar(Persona *persona);

    void agregar(Persona *persona);

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
