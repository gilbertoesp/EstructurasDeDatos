#ifndef LISTANODOS_H_INCLUDED
#define LISTANODOS_H_INCLUDED

/**
    ListaNodos.h
    Estructura que simula una grafica con nodos y sus arcos
	\author Gilberto Espinoza
*/

#include "CajaNodo.h"
#include "ListaNodos.h"
#include "Posicion.h"

#include <string>
//*************************************************************************************************
class ListaNodos{
    CajaNodo *principio, *lugar_agregado;

    CajaNodo *anterior;
    Posicion donde;
public:
//*************************************************************************************************
/**
    Inicializa los atributos en NULL o 0
*/
    ListaNodos();
//*************************************************************************************************
/**
    Inicializa los atributos en NULL o 0
*/
    void constructor();
//*************************************************************************************************
/**
   Libera la memoria de toda la estructura y sus componentes para despues asignarlos en NULL o 0
*/
    ~ListaNodos();
//*************************************************************************************************
/**
   Libera la memoria de toda la estructura y sus componentes para despues asignarlos en NULL o 0
*/
    void destructor();
//*************************************************************************************************
/**
	Busca el identificador en la lista y guarda su posicion con 'donde' y 'anterior'
	\param id : Identificador del nodo
*/
    bool buscar(int id);
//*************************************************************************************************
/**
    Agrega un nuevo nodo a la grafica ademas de inicalizar sus atributos en 0 o NULL, no permite repeticiones
	\param id : Identificador del nodo
	\return true, se agrego el nodo. false, no se agrego el nodo
*/
    bool agregar(int id, Bandera bandera, int totales, Conectivo conectivo, std::string texto);
//*************************************************************************************************
/**
    Elimina el nodo de la lista junto con sus arcos
	\param id : Identificador del nodo
	\return true, se borro. false: no se borro
*/
    bool borrar(int id);
//*************************************************************************************************
/**
    Pinta la lista de nodos, uno por uno junto con sus arcos.
*/
    void pintar();
//*************************************************************************************************
/**
    Ultimo lugar agregado a la lista de nodos
	\return Dirrecion del ultimo lugar agregado
*/
    CajaNodo * LugarAgregado() { return lugar_agregado; }
//*************************************************************************************************
    CajaNodo * Principio() { return principio; }
//*************************************************************************************************
};
//*************************************************************************************************


#endif // LISTANODOS_H_INCLUDED
