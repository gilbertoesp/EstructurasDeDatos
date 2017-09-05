/*
Nombre: caja.h
Autor: Gilberto Espinoza
Fecha:
Descripcion: Etructura que sirve de elemento en las pilas colas y listas de este proyecto
*/
#ifndef CAJADOS_H_INCLUDED
#define CAJADOS_H_INCLUDED

//**********************************************************************
/*
 * Descripcion: Estructura que respresenta un Dato generico, de ejemplo para las tareas y proyecctos de segundo parcial de la
            materia de Estructuras de Datos
 * Atributo: Valor que guarda la estructura, en este caso es un entero pero podria ser otra struc, clase o algun otro tipo de dato primitivo
 * Atributo: Cantidad de elementos del valor de la caja
 * Atributo: Puntero que apunta a una caja que se encuentra despues.
*/
struct cajaDos{
    int valor;
    int cantidad;
    cajaDos* siguiente;
};
//**********************************************************************


#endif // CAJADOS_H_INCLUDED
