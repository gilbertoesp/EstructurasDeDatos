#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
/**
    BANCO

    \author Gilberto Espinoza
*/
#include "Cliente.h"

class Cola{
    Cliente *principio, *ultimo;

    int cuantos;
    int cuantos_max;
    int espera_max;

public:
    Cola();

    ~Cola();

    void agregar(int tiempo_llegada);

    int sacar(int hora_actual);

    int CuantosSon() { return cuantos; }

    int CuantosMax() { return cuantos_max; }

    int EsperaMax() { return espera_max; }
};
/**
    Funcion auxiliar que genera un entero aleatorio entre los parametros
    Nota: No olvida de iniciar la semilla en el inicio de programa

        srand(time(NULL));

    \param Intervalo minimo
    \param Intervalo maximo
    \return Entero aleatorio
*/
int aleatorio(int min, int max);

#endif // COLA_H_INCLUDED
