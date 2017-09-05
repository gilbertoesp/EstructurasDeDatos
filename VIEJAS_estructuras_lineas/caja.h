/*
Nombre: caja.h
Autor: Gilberto Espinoza
Fecha:
Descripcion: Etructura que sirve de elemento en las pilas colas y listas de este proyecto
*/
#ifndef CAJA_H_INCLUDED
#define CAJA_H_INCLUDED

//**********************************************************************
/*
 * Descripcion: Estructura que respresenta un Dato generico, de ejemplo para las tareas y proyecctos de segundo parcial de la
            materia de Estructuras de Datos
 * Atributo: Valor que guarda la estructura, en este caso es un entero pero podria ser otra struc, clase o algun otro tipo de dato primitivo
 * Atributo: Puntero que apunta a una caja que se encuentra despues.
*/
struct caja{
    int valor;
    caja* siguiente;
};
//**********************************************************************


#endif // CAJA_H_INCLUDED
