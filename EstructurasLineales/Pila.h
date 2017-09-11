#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "Caja.h"

class Pila{
    Caja *principio;
    int cuantos;

public:
    Pila();
    ~Pila();
    void agregar(int a);
    int sacar();
    void pintar();
    int cuantosSon();
};


#endif // PILA_H_INCLUDED
