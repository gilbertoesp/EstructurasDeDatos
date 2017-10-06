/**
    BANCO

    \author Gilberto Espinoza
*/
#include <cstdlib>
#include <iostream>

#include <ctime>
#include "Cola.h"
#include "Cliente.h"
//Limites de tiempo en caja
#define MIN 3
#define MAX 15
//*******************************************************************
Cola::Cola()
{
    principio = ultimo = NULL;
    cuantos = cuantos_max = espera_max = 0;
}

//*******************************************************************
Cola::~Cola()
{
    Cliente *p;
    while(principio){
        p = principio;
        principio = p->siguiente;
        delete p;
    }
}
//*******************************************************************
void Cola::agregar(int tiempo_llegada)
{
    Cliente *p;

    p = new Cliente;

    p->hora_llegada = tiempo_llegada;
    p->tiempo_en_caja = aleatorio(MIN,MAX);
    p->espera = 0;

    if(!principio){
        p->siguiente = NULL;
        principio = p;
        ultimo =p;
    }else{
        p->siguiente = NULL;
        ultimo->siguiente = p;
        ultimo = p;
    }

    cuantos++;

    if(cuantos_max < cuantos){
        cuantos_max = cuantos;
    }

}
//*******************************************************************
int Cola::sacar(int hora_actual)
{
    Cliente *p;
    //Variable que regresamos para indicar cuanto tiempo tarda el cliente en la caja
    int en_caja;

    if(cuantos == 0){
        return -1;
    }

    p = principio;
    p->espera = hora_actual - p->hora_llegada;

    if(p->espera > espera_max){
        espera_max = p->espera;
    }

    en_caja = p->tiempo_en_caja;

    principio = principio->siguiente;

    if(principio == ultimo){
        ultimo = NULL;
    }

    delete p;
    cuantos--;

    return en_caja;

}
//*******************************************************************

//*******************************************************************

//*******************************************************************
int aleatorio(int min, int max)
{
    int aleat;
    aleat = rand()%max + min;
    return aleat;
}
//*******************************************************************
