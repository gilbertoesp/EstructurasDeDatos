#ifndef LISTAAPELLIDO_H_INCLUDED
#define LISTAAPELLIDO_H_INCLUDED

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
class ListaApellido{
    Caja *principio, *anterior;
    Boolean encontrado;
    Posicion donde;
public:
    ListaApellido() { principio = anterior = NULL; }

    ~ListaApellido();

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


#endif // LISTAAPELLIDO_H_INCLUDED
