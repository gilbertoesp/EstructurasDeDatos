#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
/**
    BANCO

    \author Gilberto Espinoza
*/
struct Cliente{
    Cliente *siguiente;
    int hora_llegada;
    int tiempo_en_caja;
    int espera;
};


#endif // CLIENTE_H_INCLUDED
