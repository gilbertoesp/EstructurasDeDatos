#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

/**
	Estructura simple que guarda el nombre de una persona, nombre y apellido, adicionalmente contiene
	una variable para guardar el que siga de el (Persona *) y asi generar una estructura lineal

	\author Gilberto Espinoza
*/
#include <string>
//*************************************************************************************************
/**
	...
	\param
	\param
*/
struct Persona{
    std::string nombre, apellido;
    Persona *siguiente;
};
//*************************************************************************************************
/**
	...
	\param
	\return
*/

//*************************************************************************************************


#endif // PERSONA_H_INCLUDED
