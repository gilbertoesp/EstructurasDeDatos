/**
	Vectors.cpp

@autor Gilberto Espinoza
@date 20 Agosto 2017
*/

#include <iostream>
#include <stdlib.h>
//Manejo de archivos
#include <fstream>
//Uso de la funcion cos
#include <cmath>
//**********************************************************************
// main auxiliar para pruebas y corridas de escritorio de vector
/*
int main()
{
    float v[3] = {2,3,5}, w[3] = {5,9,6}, r[3] = {0,0,0};
    int n = 3;

    std::cout << "Vector v: ";
    pintar(v, n);

    std::cout << std::endl << "Vector w: ";
    pintar(w, n);

    suma(v,w,r,n);
    std::cout << std::endl << "v + w = ";
    pintar(r, n);

    resta(v,w,r,n);
    std::cout << std::endl << "v - w = ";
    pintar(r, n);

    std::cout << std::endl << "v . w = " << ppunto(v,w,n);

    std::cout << std::endl << "||v|| = " << norma(v,n);
    std::cout << std::endl << "||w|| = " << norma(w,n);

    std::cout << std::endl << "Angle between v and w: " << angle(v,w,n);

	system("pause");
	return 0;
}
*/
//**********************************************************************
float * crear(int dim)
{
    return (float*) malloc(sizeof(float)* (dim) );
}
//**********************************************************************
float * copiar(float *p,int dim)
{
    float *copia, *copia1, *p1;
    int i;
    //Creacion del espacio de la matriz
    copia = (float*) malloc(sizeof(float)* (dim) );
    // Iteradores de las matrices
    copia1 = copia;
    p1 = p;
    //copiando elemento a elemento de la matriz
    for(i = 0 ; i < dim ; i++,p1++,copia1++) *copia1 = *p1;

    return copia;
}
//**********************************************************************
void pintar(float *p, int n)
{
    float *p1;
    int i;
    // No se te olvide copiar los punteros
    p1 = p;

    std::cout << "[";
    for(i = 0 ; i < n ; i++, p1++){
        std::cout << *p1 << ", ";
    }
    std::cout << "\b\b]";
}
//*******************************************************************************************
float * leer(char * nombre_archivo, int *n)
{
    std::ifstream entrada;
    entrada.open(nombre_archivo);

    if(!entrada){
        std::cout << "Error: no se pudo abrir el archivo..." << std::endl;

        system("pause");
        return NULL;
    }
    //Guardando dimension
    entrada >> *n;
    //Creando espacio y copia del puntero para iterar
    float *p, *p1;
    p =  (float*) malloc(sizeof(float)*(*n));
    p1 = p;
    //Variable dada para ir leyendo el archivo
    float x;
    int i;
    // El primer elemento en el archivo es el vector
    for(i = 0 ; i < *n ; ++i, ++p1){
        entrada >> x;
        (*p1) = x;
    }

    entrada.close();

    return p;
}
//*********************************************************
void escribir(char * nombre_archivo, float *p, int n)
{
    std::ofstream salida;
    salida.open(nombre_archivo);

    //Se escriben las dimensiones
    salida << n << std::endl;
    salida << std::endl;
    float *p1;
    p1 = p;
    //Se escribe elemento a elemento
    for(int i = 0 ; i < n ; ++i, p1++){
        salida << *p1 << " ";
    }
    salida << std::endl;
    std::cout << "\nGuardado vector en " << nombre_archivo << std::endl;
    salida.close();
}
//**********************************************************************
void suma(float *p, float *q, float *r, int n)
{
    float *p1,*q1,*r1;
    int i;

    p1 = p;
    q1 = q;
    r1 = r;
    // Suma de Vectores
    for(i = 0 ; i < n ; i++, p1++, q1++, r1++){
        *r1 = (*p1) + (*q1);
    }
    return;
}
//**********************************************************************
void resta(float *p, float *q, float *r, int n)
{
    float *p1,*q1,*r1;
    int i;

    p1 = p;
    q1 = q;
    r1 = r;
    // Resta de vectores
    for(i = 0 ; i < n ; i++, p1++, q1++, r1++){
        *r1 = (*p1) - (*q1);
    }
    return;
}
//**********************************************************************
float ppunto(float *p, float *q, int n)
{
    float *p1,*q1;
    float suma = 0.0;
    int i;

    p1 = p;
    q1 = q;
    // Producto Punto
    for(i = 0 ; i < n ; i++, p1++, q1++){
        suma += (*p1) * (*q1);
    }
    return suma;
}
//**********************************************************************
void prod_escalar(float *p, float a, float *q, int n)
{
    float *p1,*q1;
    int i;

    p1 = p;
    q1 = q;
    // Producto escalar
    for(i = 0 ; i < n ; i++, p1++, q1++){
        *q1 = (*p1) * a;
    }
    return;
}
//**********************************************************************
float norma(float *p, int n)
{
    float *p1;
    float norma = 0.0;

    p1 = p;
    // Producto punto de un vector consigo mismo
    norma = ppunto(p1, p1, n);
    // Raiz cuadrada
    norma = std::sqrt(norma);

    return norma;
}
//**********************************************************************
// Constante para transformar radianes a grados
#define PI 3.14159265
float angulo(float *p, float *q, int n)
{
    float *p1,*q1;
    float coseno = 0.0;
    // Copia de punteros
    p1 = p;
    q1 = q;
    // Producto punto entre ambos vectores dividido entre el producto de la norma de cada uno
    coseno = ( ppunto(p1,q1,n) ) / ( norma(p1,n) * norma(q1,n) );
    // Se transforma el resultado de radianes a grados y se devuelve
    return acos( coseno ) * 180 / PI;
}
//*******************************************************************************************
float * leer(char * nombre_archivo, int *n)
{
    std::ifstream entrada;
    entrada.open(nombre_archivo);

    if(!entrada){
        std::cout << "Error: no se pudo abrir el archivo..." << std::endl;

        system("pause");
        return NULL;
    }
    //Guardando dimension
    entrada >> *n;
    //Creando espacio y copia del puntero para iterar
    float *p, *p1;
    p =  (float*) malloc(sizeof(float)*(*n));
    p1 = p;
    //Variable dada para ir leyendo el archivo
    float x;
    int i;
    // El primer elemento en el archivo es el vector
    for(i = 0 ; i < *n ; ++i, ++p1){
        entrada >> x;
        (*p1) = x;
    }

    entrada.close();

    return p;
}
//*********************************************************
void escribir(char * nombre_archivo, float *p, int n)
{
    std::ofstream salida;
    salida.open(nombre_archivo);

    //Se escriben las dimensiones
    salida << n << std::endl;
    salida << std::endl;
    float *p1;
    p1 = p;
    //Se escribe elemento a elemento
    for(int i = 0 ; i < n ; ++i, p1++){
        salida << *p1 << " ";
    }
    salida << std::endl;
    std::cout << "\nGuardado vector en " << nombre_archivo << std::endl;
    salida.close();
}
