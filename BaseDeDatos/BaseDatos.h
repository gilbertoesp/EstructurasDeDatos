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
/**
	...
	\param
	\return
*/
class BaseDatos{
    Datos data;
    ListaNombre ordenNombre;
    ListaApellido ordenApellido;
public:
    void agregar(std::string nombre, std::string);
    void pintarNombre();
    void pintarApellido();
};
//*************************************************************************************************
/**
	...
	\param
	\return
*/

//*************************************************************************************************


#endif // BASEDATOS_H_INCLUDED
