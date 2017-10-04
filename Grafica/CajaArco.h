#ifndef CAJAARCO_H_INCLUDED
#define CAJAARCO_H_INCLUDED

/**
	Estructura que hace referencia a un nodo, ubicado con (int) id.
	Esta estructura es auxiliar a los objetos tipo "Grafica". Se puede organizar como si de una Lista Ordenada
	se tratase gracias a la variable (CajaArco *) siguiente.


	\author Gilberto Espinoza
*/
//*************************************************************************************************
/**
	...
	\param id           : Identificador del nodo al que esta estructura hacce referencia
	\param siguiente    : Si se necesita, siguiente en una supuesta lista de arcos. Default = NULL
*/
struct CajaArco{
    int id;
    CajaArco * siguiente = NULL;
};

//*************************************************************************************************


#endif // CAJAARCO_H_INCLUDED
