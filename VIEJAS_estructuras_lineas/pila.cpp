/*
Nombre: GEM-.cpp
Autor: Gilberto Espinoza
Fecha: 22 de Febrero del 2018
Descripcion:
*/

#include <iostream>
#include <cstdlib>

#include "pila.h"

using namespace std;

//**********************************************************************
pila::pila()
{
    principio = NULL;
    cuantos = 0;
}
//**********************************************************************
pila::~pila()
{
    //Apuntadores auxiliares
    caja *p, *q;
    //Encontramos el principio de la pila
    p = principio;
    //Mientras no lleguemos a null, continua
    while(p){
        // Extraemos el siguiente  elemento
        q = p->siguiente;
        free(p);
        // Cambiamos de lugar a q, para ponerle el siguiente
        p = q;
    }
    //Aseguramos el acceso
    principio = NULL;
    cuantos = 0;
}
//**********************************************************************
void pila::agregar(int a)
{
    caja *p;
    p = (caja *) malloc(sizeof(caja));
    p->valor = a;

    //Cuando el que agregamos es el primer elemento de la pila
    if(principio == NULL){
        p->siguiente = NULL;
        principio = p;
    }else{
        //Al elemento creado le decimos que elque sigue es el iba en principio
        p->siguiente = principio;
        principio = p;
    }
    cuantos++;
}
//**********************************************************************
void pila::pintar(void)
{
    caja *p;
    p = principio;
    // Ciclo que se repite hasta que p sea NULL, es decir, 0, el equivalente a false
    while(p){
        cout << p->valor << " ";
        //Avanzamos
        p = p->siguiente;
    }
}
//**********************************************************************
#define VACIO 99999999
//**********************************************************************
int pila::sacar()
{
    caja *p;
    int valor;
    // Si la pila esta vacia
    if(principio == NULL)
        return VACIO;
    // Sacas el principio de la pila
    p = principio;
    // guardas su valor
    valor = p->valor;
    // Haces que el principio sea el siguiente del que solia ser el principio
    principio = p->siguiente;
    // Borras el principio
    free(p);
    // Restas la cantidad
    cuantos--;
    // Regresas el dato que tenia la cima de la pila
    return valor;
}
//**********************************************************************
