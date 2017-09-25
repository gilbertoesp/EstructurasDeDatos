#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

//Incluyendo estructura base
#include "Caja.h"
/**
    Estructura Lineal tipo Cola que segui la naturaleza de First Out First Out.
*/
class Cola{
    /// Inicio y final de la cola
    Caja *principio, *final;
    /// Cantidad de datos
    int cuantos;

public:
    /**
        Constructor que inicializa los atributos del objeto en NULL o 0, segun corresponda
    */
	Cola();
    /**
       Destructor que libera la memoria solicitada de toda la estructura
    */
	~Cola();
    /**
        Agrega el nuevo dato al estructura
        \param a Dato a agregar
    */
	void agregar(int a);
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
	int  cuantosSon();
};

#endif // COLA_H_INCLUDED
