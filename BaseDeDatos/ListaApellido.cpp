/**
	...

	\author Gilberto Espinoza
*/
#include <iostream>
#include <cstdlib>

#include "Caja.h"
#include "Persona.h"
#include "ListaApellido.h"
//*************************************************************************************************
ListaApellido::~ListaApellido()
{
    Caja *p;

    while(principio){
        p = principio;
        principio = principio->siguiente;
        delete p;
    }
    principio = anterior = NULL;
}
//*************************************************************************************************
void ListaApellido::buscar(Persona *persona)
{
    Caja *p = NULL;

    if(!principio){
        encontrado = NO;
        donde = VACIO;
        anterior = NULL;
    }else{
        encontrado = NO;
        anterior = NULL;

        p = principio;
        while(p){
            ///Comparamos
            if(p->persona->apellido < persona->apellido){
                anterior = p;
                p = p->siguiente;

                if(!p) donde = FINAL;
            }else if( (p->persona->nombre == persona->nombre) && (p->persona->apellido == persona->apellido) ){
                encontrado = SI;

                if(p == principio) donde = PRINCIPIO;
                else if(!p->siguiente) donde = FINAL;
                else donde = EN_MEDIO;

                break;
            }else{
                encontrado = NO;
                if(!anterior) donde = PRINCIPIO;
                else donde = EN_MEDIO;

                break;

            }
        }
    }
    return;
}

//*************************************************************************************************
void ListaApellido::agregar(Persona *persona)
{
    Caja *p;

    buscar(persona);

    p = new Caja;
    p->persona = persona;

	switch(donde){
		case VACIO:
			p->siguiente = NULL;
			principio = p;
			break;
		case PRINCIPIO:
			p->siguiente = principio;
			principio = p;
			break;
		case EN_MEDIO:
			p->siguiente = anterior->siguiente;
			anterior->siguiente = p;
			break;
		case FINAL:
			p->siguiente = NULL;
			anterior->siguiente = p;
			break;
		default:
			return;
	}
}

//*************************************************************************************************
void ListaApellido::pintar()
{
    Caja *p;
    p = principio;

    while(p){
        std::cout << p->persona->apellido << " " << p->persona->nombre << std::endl;
        p = p->siguiente;
    }
}
