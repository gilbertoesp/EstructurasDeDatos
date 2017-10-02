#ifndef BASEDEDATOS__H_INCLUDED
#define BASEDEDATOS__H_INCLUDED

#include "Datos.h"
#include "ListaOrden1.h"
#include "ListaOrden2.h"

#include <string>

class BaseDeDatos{
    Datos data;
    ListaOrden1 orden1;
    ListaOrden2 orden2;

public:
    /**

    */
    BaseDeDatos();
    /**

    */
    ~BaseDeDatos();
    /**

    */
    bool agregar(std::string nombre, std::string apellido);
    /**

    */
    bool borrar(std::string nombre, std::string apellido);

    void pintarNombre();

    void pintarApellido();

};

#endif // BASEDEDATOS__H_INCLUDED
