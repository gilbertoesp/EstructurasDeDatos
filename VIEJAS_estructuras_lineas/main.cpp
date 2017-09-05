/*
Nombre: GEM-.cpp
Autor: Gilberto Espinoza
Fecha:
Descripcion:
*/

#include <iostream>
#include <cstdlib>
#include "ListaDoble.h"
using namespace std;
enum Opciones{SALIR, AGREGAR, SACAR, PINTAR};
//**********************************************************************
int main()
{
    ListaDoble p;
    int a, opcion;

    // Menu
    do{
        system("cls");
        cout << "[" << SALIR << "] SALIR" << endl;
        cout << "[" << AGREGAR << "] AGREGAR" << endl;
        cout << "[" << SACAR << "] SACAR" << endl;
        cout << "[" << PINTAR << "] PINTAR" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch(opcion){
        case SALIR:
            break;
        case AGREGAR:
            cout << "Entero a agregar: ";
            cin >> a;
            p.agregar(a);
            system("pause");
            break;
        case SACAR:
            cout << "Dato sacado: " << p.sacar() << endl;
        	system("pause");
            break;
        case PINTAR:
            cout << "La estructura es: " << endl;
            p.pintar();
            cout << endl << endl;
            p.pintar2();
            cout << endl;
            system("pause");
            break;
        default:
            break;
        }
    }while(opcion != SALIR);

	system("pause");
	return 0;
}
//**********************************************************************
