#ifndef CAJAREPETICION_H_INCLUDED
#define CAJAREPETICION_H_INCLUDED
/**
    Estructura base para las Estructuras lineales de datos, Pila, Cola y Lista Ordenada
    la variable (int) valor, puede ser reemplazada segun se necesite para la aplicacion de pila o cola.
    Esta variente de Caja, contiene a (int) cuantos, que representa la cantidad de veces que se repite un Dato
*/
struct CajaRepeticion{
    int valor;
    int cuantos;
    CajaRepeticion *siguiente;
};
#endif // CAJAREPETICION_H_INCLUDED
