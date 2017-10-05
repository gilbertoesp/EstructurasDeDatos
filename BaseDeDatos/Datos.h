#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED

/**
	...

	\author Gilberto Espinoza
*/
#include "Persona.h"
//*************************************************************************************************
/**
	...
	\param
	\return
*/
class Datos{
    Persona *principio, *lugar_agregado;
public:

    Datos() {principio = lugar_agregado = NULL;}

    ~Datos();

    void agregar(std::string nombre, std::string apellido);

    Persona * lugarAgregado() { return lugar_agregado; }
};
//*************************************************************************************************
/**
	...
	\param
	\return
*/

//*************************************************************************************************


#endif // DATOS_H_INCLUDED
