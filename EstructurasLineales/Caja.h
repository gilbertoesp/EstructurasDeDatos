#ifndef CAJA_H_INCLUDED
#define CAJA_H_INCLUDED
/**
    Estructura base para las Estructuras lineales de datos, Pila, Cola y Lista Ordenada
    la variable (int) valor, puede ser reemplazada segun se necesite para la aplicacion de pila o cola
*/
struct Caja{
    int valor;
    Caja *siguiente;
};
/// Enumeraciones necesarias para ubicarnos en las Listas
//*******************************************************************************************
enum Posicion{VACIO,PRINCIPIO,EN_MEDIO,FINAL};
enum Boolean{NO,SI};
//*******************************************************************************************
#endif // CAJA_H_INCLUDED
