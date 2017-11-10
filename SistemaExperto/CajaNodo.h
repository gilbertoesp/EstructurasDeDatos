#ifndef CAJANODO_H_INCLUDED
#define CAJANODO_H_INCLUDED

/**
	...

	\author Gilberto Espinoza
*/

#include "ListaArcos.h"
#include <string>
//#include "CajaRuta.h"
struct CajaRuta;

#define SIN_RESPUESTA -1
#define FALSO 0
#define VERDAD 1
enum Conectivo{SIN_CONECTIVO, AND,MAMIFERO,AVE,CARNIVORO,UNGULADO};
enum Bandera{SIN_BANDERA, PREGUNTA, INTERMEDIO, CONCLUSION};
//*************************************************************************************************
/**
	\param id           : Identificador del nodo
	\param siguiente    : Siguiente nodo en la lista de nodos
	\param salientes    : Lsita de arcos salientes
	\param entrantes    : Lista de arcos entrantes

    Variables SistExperto
*/
struct CajaNodo{
    int id;
    CajaNodo * siguiente;
    ListaArcos salientes, entrantes;
    //Variables para Sistema Experto
    Bandera bandera;
    int totales;
    int cuantos;
    Conectivo conectivo;
    int valorVerdad;
    std::string texto;
};

//*************************************************************************************************


#endif // CAJANODO_H_INCLUDED
