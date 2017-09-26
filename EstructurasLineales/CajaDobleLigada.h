#ifndef CAJADOBLELIGADA_H_INCLUDED
#define CAJADOBLELIGADA_H_INCLUDED
/**
    Estructura base para las Estructuras lineales de datos, Pila, Cola y Lista Ordenada
    la variable (int) valor, puede ser reemplazada segun se necesite para la aplicacion de pila o cola
    Esta version de Caja, contiene un puntero extra para un desplazamiento hacia atras al igual que hacia delante
*/
struct CajaDobleLigada{
    int valor;
    CajaDobleLigada *siguiente;
    CajaDobleLigada *anterior;
};
#endif // CAJADOBLELIGADA_H_INCLUDED
