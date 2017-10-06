#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED

/**
    Estructura tipo Pila que guarda los datos de la base de datos

	\author Gilberto Espinoza
*/
#include "Persona.h"
//*************************************************************************************************
class Datos{
    Persona *principio, *lugar_agregado;
public:
/**
	...
	\param
	\return
*/
    Datos() {principio = lugar_agregado = NULL;}
/**
	...
	\param
	\return
*/
    ~Datos();
/**
	...
	\param
	\return
*/
    void agregar(std::string nombre, std::string apellido);
/**
	...
	\param
	\return
*/
    Persona * lugarAgregado() { return lugar_agregado; }
};
//*************************************************************************************************

#endif // DATOS_H_INCLUDED
