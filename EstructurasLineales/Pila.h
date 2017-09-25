#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "Caja.h"
/**
    Estructura Lineal tipo Pila que segui la naturaleza de First Out Last Out.
*/
class Pila{
    /// Inicio de la Pila
    Caja *principio;
    /// Cantidad de datos en la pila
    int cuantos;

public:
    /**
        Constructor que inicializa los atributos del objeto en NULL o 0, segun corresponda
    */
    Pila();
    /**
       Destructor que libera la memoria solicitada de toda la estructura
    */
    ~Pila();
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
    int cuantosSon();
};


#endif // PILA_H_INCLUDED
