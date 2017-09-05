#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "caja.h"

class pila{
    caja *principio;
    int cuantos;

public:
    pila();
    ~pila();
    void agregar(int a);
    int sacar();
    void pintar();
    int cuantosSon();
};


#endif // PILA_H_INCLUDED
