#ifndef LISTANODOS_H_INCLUDED
#define LISTANODOS_H_INCLUDED

/**
	...

	\author Gilberto Espinoza
*/

#include "CajaNodo.h"
#include "ListaNodos.h"
#include "Posicion.h"
//*************************************************************************************************
class ListaNodos{
    CajaNodo *principio, *lugar_agregado;
    bool encontrado;

    CajaNodo *anterior;
    Posicion donde;
public:
//*************************************************************************************************
/**
	...
	\param
	\return
*/
    ListaNodos();
//*************************************************************************************************
/**
	...
	\param
	\return
*/
    void constructor();
//*************************************************************************************************
/**
	...
	\param
	\return
*/
    ~ListaNodos();
//*************************************************************************************************
/**
	...
	\param
	\return
*/
    void destructor();
//*************************************************************************************************
/**
	...
	\param
	\return
*/
    void buscar(int id);
//*************************************************************************************************
/**
	...
	\param
	\return
*/
    bool agregar(int id);
//*************************************************************************************************
/**
	...
	\param
	\return
*/
    bool borrar(int id);
//*************************************************************************************************
/**
	...
	\param
	\return
*/
    void pintar();
//*************************************************************************************************
/**
	...
	\param
	\return
*/
    CajaNodo * LugarAgregado() { return lugar_agregado; }
};
//*************************************************************************************************


#endif // LISTANODOS_H_INCLUDED
