/*
Nombre: GEM-.cpp
Autor: Gilberto Espinoza
Fecha:
Descripcion:
*/

#include <iostream>
#include <cstdlib>
#include "lista_doble.h"
using namespace std;

//**********************************************************************
lista_doble::lista_doble()
{
    //Inicializando
    principio = NULL;
    anterior = NULL;
    ultimo = NULL;
}
//**********************************************************************
lista_doble::~lista_doble()
{
    //Apuntadores auxiliares
    cajaDobleLigada *p, *q;
    //Encontramos el principio de la pila
    p = principio;
    //Mientras no lleguemos a null, continua
    while(p){
        // Extraemos el siguiente  elemento
        q = p->siguiente;
        //Eliminamos puentes
        p->siguiente = NULL;
        p->anterior = NULL;
        //Borramos
        free(p);
        // Cambiamos de lugar a q, para ponerle el siguiente
        p = q;
    }
    //Aseguramos el acceso
    principio = NULL;
    anterior = NULL;
    ultimo = NULL;
    cuantos = 0;
}
//**********************************************************************
void lista_doble::buscar(int a)
{
    cajaDobleLigada *p;
    p = principio;
    //Si la pila esta vacia
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
            //Verificamos que si estamos en el inicio anterior es igual a NULL
            if(p == principio){
                anterior = NULL;
            }
            //Salimos, encontrado = NO
            return;
        }
        //Avanzamos
        p = p->siguiente;
    }
}

//**********************************************************************
int lista_doble::agregar(int a)
{
    cajaDobleLigada *p;
    // Se busca en la lista para saber el comportamiento de la agregacion
    buscar(a);
    // Esta lista no permite repeticion
    if(encontrado == SI) return 0;
    //Creando nueva cajaDobleLigada
    p = (cajaDobleLigada *)malloc(sizeof(cajaDobleLigada));
    p->valor = a;
    //Si no se define anterior es que el nuevo elemento va al principio
    if(anterior == NULL){
        //Agregamos la nueva caja al principio de la lista
        p->siguiente = principio;
        p->anterior = NULL;
        principio->siguiente->anterior = p;
        principio = p;
    //En caso de que se tenga que agregar en medio o al final, anterior queda definido
    }else{
        anterior->siguiente = p;
        p->anterior = anterior;
        p->siguiente = anterior->siguiente;
        //Asiganndo Ultimo si se necesita
        if(anterior == ultimo){
            ultimo = p;
        }else{
            anterior->siguiente->anterior = p;
        }
    }
    cuantos++;
    return 1;    //Agregado satisfactoriamente
}
//**********************************************************************
int lista_doble::borrar(int a)
{
    cajaDobleLigada *p;
    //Buscamos lo que queremos borrar
    buscar(a);
    if(encontrado == NO) return 0; //No puedes borrar lo que no hay
    // Si se quiere eliminar el primer elemento
    if(anterior == NULL){
        p = principio;
        if(principio == ultimo){
            ultimo = NULL;
        }else{
            principio->siguiente->anterior = principio->anterior;
        }
        principio = principio->siguiente;
    //En caso de que se quiera elminar un elemento medio o final
    }else{
        p = anterior->siguiente;
        if(anterior->siguiente != ultimo){
            p->siguiente->anterior = anterior;
        }else{
            ultimo = anterior;
        }
        anterior->siguiente = p->siguiente;
    }
    free(p);
    cuantos--;
    return 1; //Borrado satisfactoriamente
}
//**********************************************************************
void lista_doble::pintarMayorMenor(void)
{
    cajaDobleLigada *p;
    p = ultimo;
    // Ciclo que se repite hasta que p sea NULL, es decir, 0, el equivalente a false
    while(p){
        cout << p->valor << " ";
        //Avanzamos
        p = p->anterior;
    }
}
//**********************************************************************
void lista_doble::pintarMenorMayor(void)
{
    cajaDobleLigada *p;
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
int lista_doble::sacar()
{
    cajaDobleLigada *p;
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
