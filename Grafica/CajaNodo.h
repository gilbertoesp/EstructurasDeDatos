#ifndef CAJANODO_H_INCLUDED
#define CAJANODO_H_INCLUDED

/**
	...

	\author Gilberto Espinoza
*/

#include "ListaArcos.h"
//#include "CajaRuta.h"
struct CajaRuta;

enum Estado{NO_EVALUADO, EVALUADO, DEFINITIVO};
//*************************************************************************************************
/**
	\param id           : Identificador del nodo
	\param siguiente    : Siguiente nodo en la lista de nodos
	\param salientes    : Lsita de arcos salientes
	\param entrantes    : Lista de arcos entrantes

	\param ruta_corta   : Longitud o peso total que toma llegar a este nodo
	\param antecesor    : Direccion del nodo de donde viene la ruta mas corta
	\param bandera      : Estado en la que se encuentra el nodo en respecto al algoritmo

*/
struct CajaNodo{
    int id;
    CajaNodo * siguiente;
    ListaArcos salientes, entrantes;

    float ruta_corta;
    CajaNodo *antecesor;
    Estado bandera;
    // ?????
    CajaRuta * direccion;
};

//*************************************************************************************************


#endif // CAJANODO_H_INCLUDED
