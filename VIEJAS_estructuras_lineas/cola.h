/*
Nombre: GEM-.cpp
Autor: Gilberto Espinoza
Fecha:
Descripcion:
*/

#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include "caja.h"
//**********************************************************************
/*
 * Descripcion:
 * Parametro:
 * Parametro:
 * Valor devuelto:
*/
class cola{
private:
    caja *principio, *final;
    int cuantos;
public:
/*
 * Descripcion: Constructor por default, designa a principio y final como nulo y a cuantos en 0
*/
    cola();
//**********************************************************************
/*
 * Descripcion: Destructor que libera la memoria de todo los elementos de la cola
*/
    ~cola();
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


#endif // COLA_H_INCLUDED
