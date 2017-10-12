/**
	...

	\author Gilberto Espinoza
*/
#include <iostream>
#include <cstdlib>
//*************************************************************************************************
struct Caja{
    int valor;
    Caja *siguiente;
};
//*************************************************************************************************
class ListaOrd{
    Caja * principio;
    bool encontrado;

public:
    ListaOrd() : principio(NULL), encontrado(false){};
    ~ListaOrd();
    Caja *buscar(int a);
    bool agregar(int a);
    bool borrar(int a);
    void pintar();
};

ListaOrd::~ListaOrd()
{
    Caja *p;

    while(principio){
        p = principio;
        principio = principio->siguiente;
        delete p;
    }
}
Caja* ListaOrd::buscar(int a)
{
    Caja * p = NULL;
    encontrado = false;

    if(principio){
        encontrado = false;
        p = principio;

        while(p){
            if(p->valor < a){
                //Si se acaba la lista rompe y regresa el "final"
                if(!p->siguiente) break;
                // avanzamos
                else p = p->siguiente;
            }else if(p->valor == a){
                encontrado = true;
                break;
            }else{
                encontrado = false;
                break;
            }
        }
    }
    return p;
}
bool ListaOrd::agregar(int a)
{
    Caja *nuevo, *p;

    p = buscar(a);

    if(encontrado) return false;

    nuevo = new Caja;
    nuevo->valor = a;

    if(!p){
        nuevo->siguiente = principio;
        principio = nuevo;
    }else{
        if(principio->valor > a){
            nuevo->siguiente = p->siguiente;
            p->siguiente = nuevo;
        }else{
            principio->siguiente = nuevo;
            nuevo->siguiente = principio;
            principio = nuevo;
        }
    }
    return true;
}
bool ListaOrd::borrar(int a)
{

}
void ListaOrd::pintar()
{
    Caja *p;
    p = principio;
    while(p){
        std::cout << p->valor << " ";
        p = p->siguiente;
    }
    std::cout << std::endl;
}
//*************************************************************************************************
int main()
{
    std::cout << "Lista sin anterior ni donde" << std::endl;
    ListaOrd lista;

    lista.agregar(5);
    lista.agregar(4);
    lista.agregar(3);
    lista.agregar(2);
    lista.agregar(1);


    lista.pintar();

    std::cout << std::endl;
    system("pause");
    return 0;
}
//*************************************************************************************************
