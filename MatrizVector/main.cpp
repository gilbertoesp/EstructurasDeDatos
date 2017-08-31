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
    // Punteros a matrices, inicializados en NULL para proteccion
    float *A=NULL,*B=NULL,*C=NULL;
    //Dimensiones
    int renA,colA,renB,colB,renC,colC;

    //Nombres de matrices
    char matrizA[] = {"matrizA.txt"};
    char matrizB[] = {"vectorB.txt"};

    //leyendo matrices
    A = leer(matrizA,&renA,&colA);
    B = leer(matrizB,&renB);

    if(A == NULL || B == NULL){
        std::cout << "Falla en lectura" << std::endl;
        return 0;
    }

    pintar(A,renA,colA);
    std::cout << std::endl;
    std::cout << std::endl;
    pintar(B,renB);

    // Se crea una matriz de dimensiones compatibles a la operacion a realizar

    C = crear(renA);

//    C = crearMatriz(renC,colC);

    ///Seccion de pruebas para las operaciones con matrices
    //suma(A,B,C,renA,colA);
    //resta(A,B,C,renA,colA);
    prod_mat_vec(A,B,C,renA,colA);


    std::cout << std::endl;
    std::cout << std::endl;
    pintar(C,renA);

    ///escribir("matrizC.txt",C,renC,colC);


    ///Liberacion de memoria
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
