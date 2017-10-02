#ifndef LISTAMITAD_H_INCLUDED
#define LISTAMITAD_H_INCLUDED

#include "CajaDobleLigada.h"
#include "Enumeraciones.h"
/**
    Estructura lineal que organiza los datos dados de menor a mayor
*/
//*******************************************************************************************
class ListaMitad{
    ///Inicio de la lista. Variable auxiliar para desplazarnos en la Lista de forma interna
	CajaDobleLigada *principio,*anterior, *mitad;
	/// Ultimo dato en ser agregado
	CajaDobleLigada *lugar_agregado;
	// Variables que nos ubican la cantidad de elementos en la lista
	int cuantos, mayores, menores;
	Posicion donde;
	Boolean encontrado;

public:
    /**
        Constructor que inicializa los atributos del objeto en NULL o 0, segun corresponda
    */
	ListaMitad();
    /**
       Destructor que libera la memoria solicitada de toda la estructura
    */
	~ListaMitad();
    /**
        Dado un Dato, los busca en la ListaMitad desde principio, guardando la informacion de la
        busqueda en las variables auxiliares (CajaDobleLigada*) anterior, (Posicion) donde y (Boolean) encontrado
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
        \return Cantidad de Datos mayores en la estructura
    */
	int mayoresSon();
    /**
        \return Cantidad de Datos menores en la estructura
    */
	int menoresSon();
    /**
        El ultimo Dato agregado se guarda en la variable auxiliar lugar_agregado, para conseguirlo, se
        utiliza esta funcion
        \return Ultimo dato en ser agregado a la estructura
    */
    CajaDobleLigada * LugarAgregado();
    /**
        Regresa la dirrecion de la mitad de la Lista
        \return Mitad de la lista
    */
    CajaDobleLigada * Mitad();
    /**

    */
    void ajustarMitad(CajaDobleLigada * lugar_agregado);

};

#endif // LISTAMITAD_H_INCLUDED
