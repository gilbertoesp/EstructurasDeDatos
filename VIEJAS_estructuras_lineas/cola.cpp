/*
Nombre: GEM-.cpp
Autor: Gilberto Espinoza
Fecha:
Descripcion:
*/

#include <iostream>
#include <cstdlib>

#include "cola.h"

using namespace std;


//**********************************************************************
cola::cola()
{
    principio = NULL;
    final = NULL;
    cuantos = 0;
}
//**********************************************************************
cola::~cola()
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
void cola::agregar(int a)
{
    //Creamos el nuevo dato
    caja *p;
    p = (caja *) malloc(sizeof(caja));
    // al espacio creado le asignamos el dato del parametro
    p->valor = a;
    // como es cola, el siguiente es necesariemente nulo
    p->siguiente = NULL;
    //Si el elemento agregado es el primero de la cola
    if(principio == NULL){
        // Tanto el principo como el final son el mismo dato
        principio = p;
        final = p;
    }else{
        //Tomamos el ultimo elmento de la cola y le decimos que el que sigue de el es p
        final->siguiente = p;
        //Entonces ahora el elemento final es p
        final = p;
    }
    cuantos++;
}
//**********************************************************************
void cola::pintar(void)
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
int cola::sacar()
{
    caja *p;
    int valor;
    // Si la cola esta vacia
    if(principio == NULL)
        return VACIO;
    // Sacas el principio de la cola
    p = principio;
    // guardas su valor
    valor = p->valor;
    // Haces que el principio sea el siguiente del que solia ser el principio
    principio = p->siguiente;
    // Borras el principio
    free(p);
    // Restas la cantidad
    cuantos--;
    // Regresas el dato que tenia la cima de la cola
    return valor;
}
//**********************************************************************
