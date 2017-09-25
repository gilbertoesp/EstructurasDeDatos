#ifndef LISTAORDENADA_H_INCLUDED
#define LISTAORDENADA_H_INCLUDED

#include "Caja.h"

//*******************************************************************************************
enum Posicion{VACIO,PRINCIPIO,EN_MEDIO,FINAL};
enum Boolean{NO,SI};
//*******************************************************************************************
class ListaOrdenada{
	Caja *principio,*anterior;
	int cuantos;
	Posicion donde;
	Boolean encontrado;

public:
/**
	\param
	\return
*/
	ListaOrdenada();
/**
	\param
	\return
*/
	~ListaOrdenada();
/**
	\param
	\return
*/
	void buscar(int a);
/**
	\param
	\return
*/
	int agregar(int a);
/**
	\param
	\return
*/
	int borrar(int a);
/**
	\param
	\return
*/
	int sacar();
/**
    \param
    \return
*/
    void pintar();
/**
	\param
	\return
*/
	int cuantosSon();
};

#endif // LISTAORDENADA_H_INCLUDED
