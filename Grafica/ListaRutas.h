#ifndef LISTARUTAS_H_INCLUDED
#define LISTARUTAS_H_INCLUDED

/**
	...

	\author Gilberto Espinoza
*/
#include "CajaRuta.h"
#include "CajaNodo.h"
#include "Posicion.h"
//*************************************************************************************************
class ListaRutas{
    CajaRuta *principio, *anterior, *lugar_agregado, *final;
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
/**
    Buscamos en la lista de rutas la posicion de la CajaRuta donde agregar una nueva longitud para que estas esten ordenadas
    \param longitud : Longitud nueva de una ruta que agregar
*/
    bool buscar(float longitud);
//*************************************************************************************************

    bool agregar(CajaNodo *direccion, float longitud);
//*************************************************************************************************

    bool borrar();
//*************************************************************************************************
    CajaNodo * sacar();
//*************************************************************************************************
    void pintarAsc();
//*************************************************************************************************
    void pintarDes();
//*************************************************************************************************
    void ajustar(CajaRuta *nodo, float nueva_ruta);
//*************************************************************************************************
    CajaRuta* LugarAgregado() { return lugar_agregado; }
};

//*************************************************************************************************


#endif // LISTARUTAS_H_INCLUDED
