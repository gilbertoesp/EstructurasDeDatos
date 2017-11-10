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
#include "CajaNodo.h"

#include <string>
using std::string;

#define CANT_PREGUNTAS 20
#define CANT_CONCLUSIONES 7
#define CANT_INTERMEDIOS 9
class Grafica{
    ListaNodos grafica;
    ListaRutas pendientes;
    CajaNodo* conclusion;
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
*/
    void agregar_arco(int a, int b, bool inversor);
//*************************************************************************************************

    void agregar_nodo(int id, Bandera bandera, int totales, Conectivo conectivo, string texto);
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
/**
    Pinta la lista de rutas hasta cada nodo con su longitud minima
*/
    void pintar_rutas();
//*************************************************************************************************
/**
*/
    void cargar();
//*************************************************************************************************
    void ejecutar();
//*************************************************************************************************
    CajaNodo * buscarPregunta();
//*************************************************************************************************
    bool procesarConsecuencias(CajaNodo *pregunta_actual);
//*************************************************************************************************
    CajaNodo * cambiarValorVerdad(CajaArco *consecuencia, int respuesta);

//*************************************************************************************************
    void cancelarProposicionesRedundantes(Conectivo conector, int valorVerdad);
//*************************************************************************************************
};
#endif // GRAFICA_H_INCLUDED
