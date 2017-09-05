/*
Nombre: GEM-.cpp
Autor: Gilberto Espinoza
Fecha:
Descripcion:
*/

#include <iostream>
#include <cstdlib>

#include "lista_ord_repAlta.h"
using namespace std;
//**********************************************************************
lista_ord_repAlta::lista_ord_repAlta()
{
    principio = NULL;
    anterior = NULL;
}
//**********************************************************************
lista_ord_repAlta::~lista_ord_repAlta()
{
    //Apuntadores auxiliares
    cajaDos *p, *q;
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
void lista_ord_repAlta::buscar(int a)
{
    cajaDos *p;
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
void lista_ord_repAlta::agregar(int a)
{
    cajaDos *p;
    // Se busca en la lista para saber el comportamiento de la agregacion
    buscar(a);
    if(encontrado == NO){
        //Creando nueva caja
        p = (cajaDos *)malloc(sizeof(cajaDos));
        p->valor = a;
        p->cantidad = 1;
        //Si no se define anterior es que el nuevo elemento va al principio
        if(anterior == NULL){
            p->siguiente = principio;
            principio = p;
        //En caso de que se tenga que agregar en medio o al final, anterior queda definido
        }else{
            p->siguiente = anterior->siguiente;
            anterior->siguiente = p;
        }
        //Agregado satisfactoriamente
        ++cuantos;
    }else{
        if(anterior == NULL){
            ++principio->cantidad;
        }else{
            ++anterior->siguiente->cantidad;
        }
    }
}
//**********************************************************************
int lista_ord_repAlta::borrar(int a)
{
    cajaDos *p;
    //Buscamos lo que queremos borrar
    buscar(a);
    if(encontrado == NO) return 0; //No puedes borrar lo que no hay
    // Si se quiere eliminar el primer elemento
    if(anterior == NULL){
        if(principio->cantidad == 1){
            p = principio;
            principio = principio->siguiente;
            free(p);
            --cuantos;
        }else{
            --principio->cantidad;
        }
    //En caso de que se quiera elminar un elemento medio o final
    }else{
        if(principio->cantidad == 1){
            p = anterior->siguiente;
            anterior->siguiente = p->siguiente;
            free(p);
            --cuantos;
        }else{
            --anterior->siguiente->cantidad;
        }
    }
    return 1; //Borrado satisfactoriamente
}
//**********************************************************************
void lista_ord_repAlta::pintar(void)
{
    cajaDos *p;
    p = principio;
    // Ciclo que se repite hasta que p sea NULL, es decir, 0, el equivalente a false
    while(p){
        cout << p->valor << "[" << p->cantidad << "], ";
        //Avanzamos
        p = p->siguiente;
    }
}
//**********************************************************************
#define VACIO 99999999
//**********************************************************************
int lista_ord_repAlta::sacar()
{
    cajaDos *p;
    int valor;

    if(principio == NULL) return VACIO;

    p = principio;
    valor = p->valor;

    if(p->cantidad > 1){
        p->cantidad--;
    }else{
        principio = p->siguiente;
        free(p);
        cuantos--;
    }
    return valor;
}
//**********************************************************************


