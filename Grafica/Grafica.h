#ifndef GRAFICA_H_INCLUDED
#define GRAFICA_H_INCLUDED

/**
	Grafica.h

	Simulacion de una grafica.
	Para aparentar la estructura de una grafica se hace referencia a las conexiones entre los nodos, con
	listas de adyacencia, cada Nodo de la grafica, contiene sus propias listas, entrada y salida.

	\author Gilberto Espinoza
*/
#include "ListaNodos.h"
#include "ListaRutas.h"
class Grafica{
    ListaNodos grafica;
    ListaRutas rutas;
public:
//*************************************************************************************************
/**
    Inicializa los atributos en NULL o 0
*/
    Grafica();
//*************************************************************************************************
/**
    Libera la memoria de toda la estructura y sus componentes para despues asignarlos en NULL o 0
*/
    ~Grafica();
//*************************************************************************************************
/**
    Agrega un arco entre dos nodos, si estos no existen los crea

	\param a        : Identificador del nodo donde parte el arco
	\param b        : Identificador del nodo donde el arco llega
	\param longitud : Longitud o peso del arco
*/
    void agregar_arco(int a, int b, float longitud = 0);
//*************************************************************************************************
/**

    \param
    \param
*/
    bool calcular_ruta_corta(int a, int b);
//*************************************************************************************************
/**
    Pinta la grafica
*/
    void pintar();
//*************************************************************************************************

};
#endif // GRAFICA_H_INCLUDED
