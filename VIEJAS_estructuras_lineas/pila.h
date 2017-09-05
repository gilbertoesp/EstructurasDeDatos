/*
Nombre: GEM-.cpp
Autor: Gilberto Espinoza
Fecha:
Descripcion:
*/
#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "caja.h"
/// PROTOTIPOS
//**********************************************************************
/*
 * Descripcion: Clase que simula el funcionamiento de una pila, una estructura lineal del tipo LIFO, (Last In, First Out)
 * Atributo: Apuntador a la direccion del primer elemento de la lista
 * Atributo: Cantidad de elementos de la lista
*/
class pila{
protected:
        caja *principio;
        int cuantos;
public:
/*
 * Descripcion: Constructor por default, designa a principio como nulo y a cuantos en 0
*/
    pila();
//**********************************************************************
/*
 * Descripcion: Destructor que libera la memoria de todo los elementos de la pila
*/
    ~pila();
//**********************************************************************
/*
 * Descripcion: Funcion que toma el parametro y lo agrega a la lista
 * Parametro: Dato a agregar
*/
    void agregar(int a);
//**********************************************************************
/*
 * Descripcion: Funcion que devuelve el valor en la cima de la pila
 * Valor devuelto: Valor en la cima de la pila
*/
    int sacar();
//**********************************************************************
/*
 * Descripcion: Funcion que imprime la pila, empezando desde la cima de la mismas
*/
    void pintar(void);
};
//**********************************************************************


#endif // PILA_H_INCLUDED
