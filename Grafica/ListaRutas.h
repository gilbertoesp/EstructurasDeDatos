#ifndef LISTARUTAS_H_INCLUDED
#define LISTARUTAS_H_INCLUDED

/**
	...

	\author Gilberto Espinoza
*/
#include "CajaRuta.h"
#include "Posicion.h"
//*************************************************************************************************
class ListaRutas{
    CajaRuta *principio, *anterior, *lugar_agregado;
    Posicion donde;
public:
//*************************************************************************************************
/**
    Inicializa los atributos en NULL o 0
*/
    ListaRutas();
//*************************************************************************************************
/**
    Inicializa los atributos en NULL o 0
*/
    void constructor();
//*************************************************************************************************
/**
   Libera la memoria de toda la estructura y sus componentes para despues asignarlos en NULL o 0
*/
    ~ListaRutas();
//*************************************************************************************************
/**
   Libera la memoria de toda la estructura y sus componentes para despues asignarlos en NULL o 0
*/
    void destructor();
//*************************************************************************************************

    bool buscar();
//*************************************************************************************************

    bool agregar();
//*************************************************************************************************

    bool borrar();
//*************************************************************************************************

    void pintar();
//*************************************************************************************************
    CajaRuta* LugarAgregado() { return lugar_agregado; }
};

//*************************************************************************************************


#endif // LISTARUTAS_H_INCLUDED
