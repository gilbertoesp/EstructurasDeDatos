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
    cajaDobleLigada *p, *q;
    p = principio;

    while(p){
        // Extraemos el siguiente  elemento
        q = p->siguiente;
        //Borramos
        free(p);
        // Cambiamos de lugar a q, para ponerle el siguiente
        p = q;
    }
    //Aseguramos el acceso
    principio = NULL;
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
        //Si algun elemento de la lista tiene el mismo valor, lo encontramos
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
int lista_doble::agregar(int a)
{
    cajaDobleLigada *p;

    buscar(a);

    if(encontrado == SI) return 0; // No se pudo agregar

    p = (cajaDobleLigada*)malloc(sizeof(cajaDobleLigada));
    p->valor = a;

    if(principio == NULL){
        p->siguiente = p->anterior = NULL;
        principio = ultimo = p;
    }
    //Si el nuevo elemento va en el inicio de la lista, anterior es definido como nulo
    if(anterior == NULL){
        p->siguiente = principio;
        p->anterior = NULL;
        principio = p;
        ultimo = p;
    }else{
        p->siguiente = anterior->siguiente;
        anterior->siguiente = p;
        p->anterior = anterior;
        if(anterior == ultimo){
            ultimo = p;
        }else{
            p->siguiente->anterior = p;
        }
    }
    //Agregams uno mas a la cantidad de elementos en la lista
    cout << "Agregado " << p->valor << endl;

    cuantos++;
    return 1;
}
//**********************************************************************
int lista_doble::borrar(int a)
{
    cajaDobleLigada *p;

    buscar(a);

    if(encontrado == SI) return 0; //Imposible borrar
    //El elemento a borrar se encuentra en el principio de la pila
    if(anterior == NULL){
        p = principio;
        //En caso de que la lista tenga un unico elemento
        if(ultimo == principio){
            //p = principio;
            principio = ultimo = NULL;
        // la lista tiene al menos dos elementos
        }else{
            principio->siguiente->anterior = principio->anterior;
        }
        principio = principio->siguiente;
    //El elemento buscado esta al final
    }else{
        p = anterior->siguiente;
        if(anterior->siguiente == ultimo){
            ultimo = anterior;
        }else{
            p->siguiente->anterior = anterior;
        }
        anterior->siguiente = anterior->siguiente;
    }
    free(p);
    cuantos--;
    return 1;
}
//**********************************************************************
void lista_doble::pintarMayorMenor(void)
{
    cajaDobleLigada *p;
    p = ultimo;
    // Ciclo que se repite hasta que p sea NULL, es decir, 0, el equivalente a false
    while(p != principio){
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
    while(p != ultimo){
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
