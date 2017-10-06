#ifndef BASEDATOS_H_INCLUDED
#define BASEDATOS_H_INCLUDED

/**
	...

	\author Gilberto Espinoza
*/
#include "Persona.h"
#include "Datos.h"
#include "ListaNombre.h"
#include "ListaApellido.h"
#include <string>
//*************************************************************************************************
class BaseDatos{
    Datos data;
    ListaNombre ordenNombre;
    ListaApellido ordenApellido;
public:
/**
    ...
    \param
    \return
*/
    void agregar(std::string nombre, std::string);
/**
    ...
    \param
    \return
*/
    void pintarNombre();
/**
    ...
    \param
    \return
*/
    void pintarApellido();
};
//*************************************************************************************************


//*************************************************************************************************


#endif // BASEDATOS_H_INCLUDED
