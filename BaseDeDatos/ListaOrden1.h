#ifndef LISTAORDEN1_H_INCLUDED
#define LISTAORDEN1_H_INCLUDED

#include "CajaPersona.h"
#include "Enumeraciones.h"
/**
    Estructura lineal que organiza los datos dados de menor a mayor
*/
//*******************************************************************************************
class ListaOrden1{
    ///Inicio de la lista. Variable auxiliar para desplazarnos en la Lista de forma interna
	CajaPersona *principio,*anterior;
	/// Ultimo dato en ser agregado
	CajaPersona *lugar_agregado;
	int cuantos;
	Posicion donde;
	Boolean encontrado;

public:
    /**
        Constructor que inicializa los atributos del objeto en NULL o 0, segun corresponda
    */
	ListaOrden1();
    /**
       Destructor que libera la memoria solicitada de toda la estructura
    */
	~ListaOrden1();
    /**
        Dado un Dato, los busca en la ListaOrden1 desde principio, guardando la informacion de la
        busqueda en las variables auxiliares (CajaPersona*) anterior, (Posicion) donde y (Boolean) encontrado
        \param a Dato a buscar
    */
	void buscar(int a);
    /**
        Agrega el nuevo dato al estructura
        \param a Dato a agregar
        \return 0 Si el dato ya esta en la Lista, 1 Si se agrego de manera satisfactorio
    */
	int agregar(int a);
    /**
        Elimina un Dato especifico de la lista
        \param Dato a eliminar
        \return 0 Si el dato no se encuentra, (no se logro borrar) 1 si el dato fue borrado
    */
	int borrar(int a);
    /**
        Retira el dato que sigue segun la naturaleza de la estructura, eliminando su espacio en memoria
        y solo regresando el Dato (int)
        \return Siguiente valor en la estructura
    */
	int sacar();
    /**
        Pinta la estructra en orden
    */
    void pintar();
    /**
        \return Cantidad de Datos en la estructura
    */
	int cuantosSon();
/**
    El ultimo Dato agregado se guarda en la variable auxiliar lugar_agregado, para conseguirlo, se
    utiliza esta funcion
    \return Ultimo dato en ser agregado a la estructura
    CajaPersona * LugarAgregado();
*/
};

#endif // LISTAORDEN1_H_INCLUDED
