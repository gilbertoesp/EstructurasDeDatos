#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED

#include "CajaPersona.h"
#include <string>
/**
    Estructura Lineal tipo pila que segui la naturaleza de First Out Last Out.
*/
class Datos{
    /// Inicio de la Datos
    CajaPersona *principio, *lugar_agregado;
    /// Cantidad de datos en la pila
    int cuantos;

public:
    /**
        Constructor que inicializa los atributos del objeto en NULL o 0, segun corresponda
    */
    Datos();
    /**
       Destructor que libera la memoria solicitada de toda la estructura
    */
    ~Datos();
    /**
        Constructor que inicializa los atributos del objeto en NULL o 0, segun corresponda
    */
    void iniciar();
    /**
       Destructor que libera la memoria solicitada de toda la estructura
    */
    void destruir();
    /**
        Agrega el nuevo dato al estructura
        \param a Dato a agregar
    */
    void agregar(std::string nombre, std::string apellido);
    /**
        Retira el dato que sigue segun la naturaleza de la estructura, eliminando su espacio en memoria
        y solo regresando el Dato (int)
        \return Siguiente valor en la estructura
    */
    std::string sacar();
    /**
        Pinta la estructra en orden, mostrando primero el nombre
    */
    void pintarNombre();
    /**
        Pinta la estructra en orden, mostrando primero el apellido
    */
    void pintarApellido();
    /**
        \return Cantidad de Datos en la estructura
    */
    int cuantosSon();
    /**

    */
    CajaPersona * lugarAgregado();
};


#endif // PILA_H_INCLUDED
