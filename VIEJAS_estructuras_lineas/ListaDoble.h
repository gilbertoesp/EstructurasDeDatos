#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

/**
	GEM-.cpp
[Descripcion]
@autor Gilberto Espinoza
@date
*/
#include "cajaDobleLigada.h"
//**********************************************************************
enum Posicion{VACIO,PRINCIPIO,EN_MEDIO,FINAL};
enum Boolean{NO,SI};
//**********************************************************************
//**********************************************************************
/**

	\param
	\param
	\return
*/
class ListaDoble{
private:
    cajaDobleLigada *principio, *anterior, *ultimo;
    Boolean encontrado;
    Posicion donde;
    int cuantos;
public:
//**********************************************************************
/**
    Constructor que inicializa los punteros en NULL
*/
    ListaDoble();
//**********************************************************************
/**
    Destructor que libera elemento a elemento de la lista
*/
    ~ListaDoble();
//**********************************************************************
/**
    Busca a lo largo de la lista el elemento solicitado y define la lavariable auxiliar propia de la lista, anterior, como el
            elemento anterior a donde esta ubicada o deberia estarlo el valor buscado
    \param Valor a buscar
*/
    void buscar(int a);
//**********************************************************************
/**
    Busca, crea y agrega en orden un nuevo elemento a la lsita con el paramaetro recibido
    \param Dato a asignar al nuevo elemento
    \return 0, Si no se agrego el elemento solicitado; 1 si se agrego
*/
    int agregar(int a);
//**********************************************************************
/**
    Libera memoria y mueve el flujo de la lista para eliminar un valor en concreto
    \param Elimina especificamente un valor de la lista
    \return 0, Si el borrado no pudo realizarse, 1 si en efecto se elimno
*/
    int borrar(int a);
//**********************************************************************
/**
    Saca el primer elemento de la lista
*/
    int sacar();
//**********************************************************************
/**
    Imprime el dato de cada elemento de la lista empezando desde el principio de la misma
*/
    void pintar();
    void pintar2();
//**********************************************************************
/**
    Cantidad de elementos asignados en la lista
    \return cuantos elementos tiene la lista
*/
    int getCuantos() { return cuantos; }
};
//**********************************************************************
ListaDoble::ListaDoble()
{
    principio = NULL;
    anterior = NULL;
    ultimo = NULL;
}
//**********************************************************************
ListaDoble::~ListaDoble()
{
    //Apuntadores auxiliares
    cajaDobleLigada *p, *q;
    //Encontramos el principio de la pila
    p = principio;
    //Mientras no lleguemos a null, continua
    while(p){
        // Extraemos el siguiente  elemento
        q = p->siguiente;
        free(p);
        // Cambiamos de lugar a q, para ponerle el siguiente
        p = q;
    }
    //Aseguramos el acceso
    principio = ultimo = anterior = NULL;
    cuantos = 0;
}
//**********************************************************************
void ListaDoble::buscar(int a)
{
    cajaDobleLigada *p;
    p = principio;
    //Si la lista esta vacia
    if(p == NULL){
        encontrado = NO;
        donde = VACIO;
        anterior = NULL;
        return;
    }
    //Suponemos no encontrarlo
    encontrado = NO;
    //Limpiamos la variable auxiliar
    anterior = NULL;
    // Mientras no lleguemos a NULL, el final de la lista, continua
    while(p){
        if(p->valor < a){
            //Avanzamos
            anterior = p;
            p = p->siguiente;
            if(p == NULL)                   donde = FINAL;
        }else if(p->valor == a){
            encontrado = SI;
            if(p == principio)              donde = PRINCIPIO;
            else if(p->siguiente == NULL)   donde = FINAL;
            else                            donde = EN_MEDIO;
            return;
        }else{ // p->valor > a
            encontrado = NO;
            if(anterior == NULL)            donde = PRINCIPIO;
            else                            donde = EN_MEDIO;
            return;
        }
    }
}

//**********************************************************************
int ListaDoble::agregar(int a)
{
    cajaDobleLigada *p;
    // Se busca en la lista para saber el comportamiento de la agregacion
    buscar(a);
    // Esta lista no permite repeticion
    if(encontrado == SI) return 0;
    //Creando nueva cajaDobleLigada
    p = (cajaDobleLigada *)malloc(sizeof(cajaDobleLigada));
    p->valor = a;
    switch(donde){
        case VACIO:
                p->siguiente = NULL;
                p->anterior = NULL;
                principio = p;
                ultimo = p;
            break;
        case PRINCIPIO:
                p->siguiente = principio;
                principio->anterior = p;
                principio = p;
                p->anterior = NULL;
            break;
        case EN_MEDIO:
                anterior->siguiente->anterior = p;
                p->siguiente = anterior->siguiente;
                anterior->siguiente = p;
                p->anterior = anterior;
            break;
        case FINAL:
                p->siguiente = NULL;
                anterior->siguiente = p;
                p->anterior = anterior;
                ultimo = p;
            break;
        default:
            return 0;
    }
    cuantos++;
    return 1;    //Agregado satisfactoriamente
}
//**********************************************************************
int ListaDoble::borrar(int a)
{
    cajaDobleLigada *p;
    //Buscamos lo que queremos borrar
    buscar(a);
    if(encontrado == NO) return 0; //No puedes borrar lo que no hay
    // Si se quiere eliminar el primer elemento
    if(anterior == NULL){
        p = principio;
        principio = p->siguiente;
    //En caso de que se quiera elminar un elemento medio o final
    }else{
        p = anterior->siguiente;
        anterior->siguiente = p->siguiente;
        p->siguiente->anterior = anterior;
    }

    free(p);
    cuantos--;
    return 1; //Borrado satisfactoriamente
}
//**********************************************************************
void ListaDoble::pintar(void)
{
    cajaDobleLigada *p;
    p = principio;
    // Ciclo que se repite hasta que p sea NULL, es decir, 0, el equivalente a false
    while(p){
        std::cout << p->valor << " ";
        //Avanzamos
        p = p->siguiente;
    }
}
void ListaDoble::pintar2(void)
{
    cajaDobleLigada *p;
    p = ultimo;
    // Ciclo que se repite hasta que p sea NULL, es decir, 0, el equivalente a false
    while(p){
        std::cout << p->valor << " ";
        //Avanzamos
        p = p->anterior;
    }
}
//**********************************************************************
#define VACIO 99999999
//**********************************************************************
int ListaDoble::sacar()
{
    cajaDobleLigada *p;
    int valor;

    if(principio == NULL) return VACIO;

    p = principio;
    valor = p->valor;
    principio = p->siguiente;
    free(p);
    cuantos--;
    return valor;
}
//**********************************************************************
//**********************************************************************


#endif // LISTADOBLE_H_INCLUDED
