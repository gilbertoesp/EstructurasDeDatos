/**
	GEM-.cpp
[Descripcion]
@autor Gilberto Espinoza
@date
*/

#include <iostream>
#include <cstdlib>
#include "vector.h"
using namespace std;

//**********************************************************************
int main()
{
    std::cout << std::endl;
    std::cout << std::endl;

    float *p,*q;
    int n1,n2;

    char vectorA[] = {"vectorA.txt"};
    char vectorB[] = {"vectorB.txt"};

    p = leer(vectorA, &n1);
    q = leer(vectorB, &n2);

    if(p == NULL || q == NULL){
        std::cout << "Falla en lectura" << std::endl;
        return 0;
    }

    std::cout << "\nVector A del archivo " << vectorA << "-> " << std::endl;
    pintar(p,n1);

    std::cout << "\nVector B del archivo " << vectorB << "-> " << std::endl;
    pintar(q,n2);
    //Opeacion a evaluar su funcionalidad

    //prod_escalar(p,3,q,n1);


    std::cout << "\nResultado " << std::endl;

    pintar(q,n2);


    free(p);
    free(q);

    std::cout << std::endl;
    std::cout << std::endl;

	system("pause");
	return 0;
}
//**********************************************************************
