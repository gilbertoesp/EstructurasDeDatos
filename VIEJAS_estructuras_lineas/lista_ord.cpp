/*
Nombre: GEM-.cpp
Autor: Gilberto Espinoza
Fecha:
Descripcion:
*/

#include <iostream>
#include <cstdlib>

#include "lista_ord.h"
using namespace std;
//**********************************************************************
lista_ord::lista_ord()
{
    principio = NULL;
    anterior = NULL;
}
//**********************************************************************
lista_ord::~lista_ord()
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
void lista_ord::buscar(int a)
{
    caja *p;
    p = principio;
    //Si la lista esta vacia
    if(p == NULL){
        encontrado = NO;
        anterior = NULL;
        return;
    }
    //Suponemos no encontrarlo
    encontrado = NO;
    // Mientras no lleguemos a NULL, el fina de la lista, continua
    while(p){
        //Si algun elementode la lista tiene el mismo valor, lo encontramos
        if(p->valor == a){
            encontrado = SI;
            //Definimos anterior como null si encontramos el elemento en el principio
            if(p == principio){
                anterior = NULL;
            }
            return;
        //Si todavia no pasamos el umbral de busqueda, define el anterior
        }else if(p->valor < a){
            anterior = p;
        //LLegados aqui, significa que p->valor > a por lo que el elemento no esta en la lista
        }else{
            //Verificamos que no estemos en el inicio
            if(p == principio){
                anterior = NULL;
            }
            return;
        }
        //Avanzamos
        p = p->siguiente;
    }
}

//**********************************************************************
int lista_ord::agregar(int a)
{
    caja *p;
    // Se busca en la lista para saber el comportamiento de la agregacion
    buscar(a);
    // Esta lista no permite repeticion
    if(encontrado == SI) return 0;
    //Creando nueva caja
    p = (caja *)malloc(sizeof(caja));
    p->valor = a;
    //Si no se define anterior es que el nuevo elemento va al principio
    if(anterior == NULL){
        p->siguiente = principio;
        principio = p;
    //En caso de que se tenga que agregar en medio o al final, anterior queda definido
    }else{
        p->siguiente = anterior->siguiente;
        anterior->siguiente = p;
    }
    cuantos++;
    return 1;    //Agregado satisfactoriamente
}
//**********************************************************************
int lista_ord::borrar(int a)
{
    caja *p;
    //Buscamos lo que queremos borrar
    buscar(a);
    if(encontrado == NO) return 0; //No puedes borrar lo que no hay
    // Si se quiere eliminar el primer elemento
    if(anterior == NULL){
        p = principio;
        principio = p->siguiente;
    //En caso de que se quiera elminar un elemento medio o final
    }else{
        p = anterior->siguiente;
        anterior->siguiente = p->siguiente;
    }

    free(p);
    cuantos--;
    return 1; //Borrado satisfactoriamente
}
//**********************************************************************
void lista_ord::pintar(void)
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
int lista_ord::sacar()
{
    caja *p;
    int valor;

    if(principio == NULL) return VACIO;

    p = principio;
    valor = p->valor;
    principio = p->siguiente;
    free(p);
    cuantos--;
    return valor;
}
//**********************************************************************

