/**
	Grafica.cpp

	Simulacion de una grafica.
	Para aparentar la estructura de una grafica se hace referencia a las conexiones entre los nodos, con
	listas de adyacencia, cada Nodo de la grafica, contiene sus propias listas, entrada y salida.

	\author Gilberto Espinoza
*/
#include <iostream>
#include <cstdlib>

#include "Grafica.h"
//*************************************************************************************************
Grafica::Grafica()
{
    grafica.constructor();
}
//*************************************************************************************************
Grafica::~Grafica()
{
    grafica.destructor();
}
//*************************************************************************************************
void Grafica::agregar_arco(int a, int b, float longitud /* = 0 */)
{
    CajaNodo *nodo_a, *nodo_b;
    CajaArco *arco;

    grafica.agregar(a);
    nodo_a = grafica.LugarAgregado();
    nodo_a->salientes.agregar(b);
    //El arco recien creado
    arco = nodo_a->salientes.LugarAgregado();
    arco->longitud = longitud;

    grafica.agregar(b);
    nodo_b = grafica.LugarAgregado();
    // Al arco le decimos donde se encuentra dentro de grafica
    arco->direccion_nodo = nodo_b;

    nodo_b->entrantes.agregar(a);
    arco = nodo_b->entrantes.LugarAgregado();
    arco->longitud = longitud;
    // Igual al arco entrante de b le decimos que su posicion en la grafica es el nodo_a
    arco->direccion_nodo = nodo_a;
}
//*************************************************************************************************
bool Grafica::calcular_ruta_corta(int a, int b)
{
    bool existe_ruta_corta = false;
    CajaNodo *nodo; //p
    CajaArco *arco; //q

    //Madamos buscar la dirrecion del nodo a
    if(!grafica.buscar(a)) return existe_ruta_corta = false;
    nodo = grafica.LugarAgregado();
    //Mientras haya nodo que procesar sigue haciendolo
    while(nodo){
        //Este nodo ya esta siendo procesado directamente, su ruta corta ha sido calculada
        nodo->bandera = RUTA_DEFINITIVA;
        //Si nodo es que el definido objetivo, GENIAL!
        if(nodo->id == b){
            existe_ruta_corta = true;  ///ENCONTRADA
            //Limpiamos la lista de nodos para agregar los salientes de nodo y precesar sus caminos desde este nodo
            rutas.destructor();

            while(nodo){
                //Guardamos el nodo con su peso total para llegar a el
                rutas.agregar(nodo,nodo->longitud_ruta);
                //Nos desplazamos al anterior en el camino definido por el camino ya trasado
                nodo = nodo->antecesor;
            }
            return existe_ruta_corta; ///RUTA ENCONTRADA
        }//No se ha llegado al nodo b

        //Tomamos el primer arco del nodo en procesamiento
        arco = (nodo->salientes).Principio();
        while(arco){
            if(arco->direccion_nodo->bandera == RUTA_NO_EVALUADA){
                arco->direccion_nodo->bandera = RUTA_EVALUADA;
                //La ruta corta hasta el siguiente nodo desde el actual, es la ruta acumulada mas la longitud entre este nodo y el conectado
                arco->direccion_nodo->longitud_ruta = nodo->longitud_ruta + arco->longitud;
                arco->direccion_nodo->antecesor = nodo;

                rutas.agregar(arco->direccion_nodo,arco->direccion_nodo->longitud_ruta);
                // Al nodo recien procesado le decimos que su posicion en la lista esta
                arco->direccion_nodo->direccion = rutas.LugarAgregado();
                                                // Se procesa si la longitud del nodo destino es mayor a la nueva ruta desde este nodo
            }else if(arco->direccion_nodo->bandera == RUTA_EVALUADA && ( arco->direccion_nodo->longitud_ruta  >  nodo->longitud_ruta + arco->longitud ) ){
                //La ruta corta hasta el siguiente nodo desde el actual, es la ruta acumulada mas la longitud entre este nodo y el conectado
                arco->direccion_nodo->longitud_ruta = nodo->longitud_ruta + arco->longitud;
                arco->direccion_nodo->antecesor = nodo;

                rutas.ajustar(arco->direccion_nodo->direccion, arco->direccion_nodo->longitud_ruta);
            }
            // Siguiente en la lista de salientes de nodo
            arco = arco->siguiente;
        }
        nodo = rutas.sacar();
    }
    return existe_ruta_corta;
}
//*************************************************************************************************
void Grafica::pintar()
{
    grafica.pintar();
}
//*************************************************************************************************
void Grafica::pintar_rutas()
{
    rutas.pintarAsc();
}
//*************************************************************************************************
