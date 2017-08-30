/**
	GEM-.cpp
[Descripcion]
@autor Gilberto Espinoza
@date
*/

#include <iostream>
#include <cstdlib>
#include "vector.h"
#include "matriz.h"

int main()
{
    // Punteros a matrices
    float *A,*B,*C;
    //Dimensiones
    int renA,colA,renB,colB,renC,colC;

    //Nombres de matrices
    char matrizA[] = {"matrizA.txt"};
    char matrizB[] = {"matrizB.txt"};

    //leyendo matrices
    A = leer(matrizA,&renA,&colA);
    B = leer(matrizB,&renB,&colB);

    if(A == NULL || B == NULL){
        std::cout << "Falla en lectura" << std::endl;
        return 0;
    }

    pintar(A,renA,colA);
    std::cout << std::endl;
    std::cout << std::endl;
    pintar(B,renB,colB);

    // Se crea una matriz de dimensiones compatibles a la operacion a realizar
    renC = renA;
    colC = colA;
    C = crearMatriz(renC,colC);


    suma(A,B,C,renA,colA);

    std::cout << std::endl;
    std::cout << std::endl;
    pintar(C,renC,colC);

    escribir("matrizC.txt",C,renC,colC);

    free(A);
    free(B);
    free(C);

    std::cout << std::endl;
    std::cout << std::endl;

	system("pause");
	return 0;

}
///***************  MAIN - PRUEBA VECTORES  *******************************************************
/*
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
*/
//**********************************************************************
