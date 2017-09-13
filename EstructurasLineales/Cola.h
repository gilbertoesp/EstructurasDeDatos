#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

//Incluyendo estructura base
#include "Caja.h"

class Cola{
    Caja *principio, *final;
    int cuantos;

public:
	Cola();
	~Cola();
	void agregar(int a);
	int sacar();
	void pintar();
	int  cuantosSon();
};

#endif // COLA_H_INCLUDED
