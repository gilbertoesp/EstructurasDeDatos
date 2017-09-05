/*
Nombre: GEM-.cpp
Autor: Gilberto Espinoza
Fecha:
Descripcion:
*/

#ifndef LISTA_DOBLE_H_INCLUDED
#define LISTA_DOBLE_H_INCLUDED

#include "cajaDobleLigada.h"

enum Boolean{NO, SI};

class lista_doble{
private:
    cajaDobleLigada *principio, *anterior, *ultimo;
    Boolean encontrado;
    int cuantos;
public:
//**********************************************************************
/*
 * Descripcion: Constructor que inicializa los punteros en NULL
*/
    lista_doble();
//**********************************************************************
/*
 * Descripcion: Destructor que libera elemento a elemento de la lista
*/
    ~lista_doble();
//**********************************************************************
/*
 * Descripcion: Busca a lo largo de la lista el elemento solicitado y define la lavariable auxiliar propia de la lista, anterior, como el
            elemento anterior a donde esta ubicada o deberia estarlo el valor buscado
 * Parametro: Valor a buscar
*/
    void buscar(int a);
//**********************************************************************
/*
 * Descripcion: Busca, crea y agrega en orden un nuevo elemento a la lsita con el paramaetro recibido
 * Parametro: Dato a asignar al nuevo elemento
 * Valor devuelto: 0, Si no se agrego el elemento solicitado; 1 si se agrego
*/
    int agregar(int a);
//**********************************************************************
/*
 * Descripcion: Libera memoria y mueve el flujo de la lista para eliminar un valor en concreto
 * Parametro: Elimina especificamente un valor de la lista
 * Valor devuelto: 0, Si el borrado no pudo realizarse, 1 si en efecto se elimno
*/
    int borrar(int a);
//**********************************************************************
/*
 * Descripcion: Saca el primer elemento de la lista
 * Valor devuelto: 0 si no se destruye, 1 si lo hace
*/
    int sacar();
//**********************************************************************
/*
 * Descripcion: Imprime el dato de cada elemento de la lista empezando desde el principio de la misma
*/
    void pintarMayorMenor();
//**********************************************************************
/*
 * Descripcion: Imprime el dato de cada elemento de la lista empezando desde el principio de la misma
*/
    void pintarMenorMayor();
//**********************************************************************
/*
 * Descripcion: Cantidad de elementos asignados en la lista
 * Valor devuelto: cuantos elementos tiene la lista
*/
    int getCuantos() { return cuantos; }
//**********************************************************************
};


#endif // LISTA_DOBLE_H_INCLUDED
