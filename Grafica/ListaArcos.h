#ifndef LISTAARCOS_H_INCLUDED
#define LISTAARCOS_H_INCLUDED

/**
	ListaArcos.h

	Listas de adyacencia para algun nodo en Grafica, ya sea entrante o saliente
    Esta estructura ordena de menor a mayor los identificadores (int) de los nodos que estan conectados
    a otro nodo

	\author Gilberto Espinoza
*/


#include "CajaArco.h"

#include "Posicion.h"
//*************************************************************************************************
class ListaArcos{
    CajaArco *principio, *lugar_agregado;
    bool encontrado;

    CajaArco *anterior;
    Posicion donde;
public:
//*************************************************************************************************
/**
    Inicializa los atributos en NULL o 0
*/
    ListaArcos();
//*************************************************************************************************
/**
    Inicializa los atributos en NULL o 0
*/
    void constructor();
//*************************************************************************************************
/**
   Libera la memoria de toda la estructura y sus componentes para despues asignarlos en NULL o 0
*/
    ~ListaArcos();
//*************************************************************************************************
/**
   Libera la memoria de toda la estructura y sus componentes para despues asignarlos en NULL o 0
*/
    void destructor();
//*************************************************************************************************
/**
    Busca el identificador del nodo en la lista de arcos de un nodo para que esta lista sea ordenada
    \param id   : Identificador del nodo
*/
    void buscar(int id);
//*************************************************************************************************
/**
    Agrega un nuevo arco a la lista, primero lo busca y despues enlaza los punteros en orden para conservar
    la estrucutra
	\param  id   : Identificador del nodo
	\return true: Se agrego el arco. false: no se agrego el arco
*/
    bool agregar(int id);
//*************************************************************************************************
/**
    Elimina un arco de forma segura ademas de modificar las referencias (siguiente) para que la lista siga
    con su funcionamiento
	\param id   : Identificador del nodo
	\return true: Se borro el arco. false: no se borro el arco
*/
    bool borrar(int id);
//*************************************************************************************************
/**
	Pinta la lista de arco junto con sus respectivos datos, id, longitud, etc
*/
    void pintar();
//*************************************************************************************************
/**
    Ultimo arco agregado a la lista, su dirreccion en memoria
	\return arco recien agregado
*/
    CajaArco * LugarAgregado() { return lugar_agregado; }
//*************************************************************************************************
};

//*************************************************************************************************


#endif // LISTAARCOS_H_INCLUDED
