/*
Nombre: GEM-.cpp
Autor: Gilberto Espinoza
Fecha:
Descripcion:
*/

#include <iostream>
#include <cstdlib>
#include "lista_mitad.h"

using namespace std;

//**********************************************************************
lista_mitad::lista_mitad()
{
    principio = NULL;
    mitad = NULL;
    menores = 0;
    mayores = 0;
}
//**********************************************************************
lista_mitad::~lista_mitad()
{
    cajaDobleLigada *p, *q;
    //Sacamos el principio
    p = principio;
    while(p){
        q = p->siguiente;
        free(p);
        p = q;
    }
    mayores = 0;
    menores = 0;
    principio = mitad = ultimo = anterior = NULL;
}
//**********************************************************************
void lista_mitad::buscar(int a)
{
    if(principio == NULL){
        encontrado = NO;
        donde = VACIO;
        anterior = NULL;
        mitad = NULL;
        return;
    }

    cajaDobleLigada *p;
    //Revisamos por donde es conveniente empezar a buscar
    if(a < mitad->valor)
        p = principio;
    else
        p = mitad;

    anterior = p->anterior;
    while(p){
        if(p->valor < a){
            anterior = p;
            p = p->siguiente;
        }else if(p->valor == a){
            encontrado = SI;
            return;
        }else{
            encontrado = NO;
            if(principio == p) donde = PRINCIPIO;
            else donde = EN_MEDIO;
            return;
        }
    }
    encontrado = NO;
    donde = FINAL;

}
//**********************************************************************
int lista_mitad::agregar(int a)
{
    buscar(a);

    if(encontrado == SI) return 0;

    cajaDobleLigada *p;
    p = (cajaDobleLigada*)malloc(sizeof(cajaDobleLigada));
    p->valor = a;

    if(donde == EN_MEDIO){
        p->siguiente = anterior->siguiente;
        p->anterior = anterior;
        anterior->siguiente = p;
        p->siguiente->anterior = p;
    }else if(donde == FINAL){
        p->siguiente = NULL;
        p->anterior = ultimo;
        ultimo->siguiente = p;
        ultimo = p;
    }else if(donde == PRINCIPIO){
        p->anterior = NULL;
        p->siguiente = principio;
        principio->anterior = p;
        principio = p;
    // donde == VACIO
    }else{
        p->siguiente = p->anterior = NULL;
        principio = mitad = ultimo = p;
    }

    if(p->valor >= mitad->valor) mayores++;
    else menores++;
    // se suma dos para contrarestar el inicio en 0 y que mayores puede ser solo uno mas grande
    if(menores + 2 <= mayores){
        mitad = mitad->siguiente;
        menores++;
        mayores--;
    }else{
        mitad = mitad->anterior;
        menores--;
        mayores++;
    }

    return 1;
}
//**********************************************************************
void lista_mitad::pintarMenorMayor()
{
    cajaDobleLigada *p;
    p = principio;
    while(p){
        cout << p->valor << " ";
        p = p->siguiente;
    }
}
//**********************************************************************
void lista_mitad::pintarMayorMenor()
{
    cajaDobleLigada *p;
    p = ultimo;
    while(p){
        cout << p->valor << " ";
        p = p->anterior;
    }
}
