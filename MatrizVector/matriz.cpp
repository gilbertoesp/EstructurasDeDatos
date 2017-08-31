/**
	GEM-.cpp
[Descripcion]
@autor Gilberto Espinoza
@date
*/

#include <iostream>
#include <cstdlib>
#include <iomanip> //std::setw
#include <fstream> // Manejo de archivos


//**********************************************************************
float * crear(int ren, int col)
{
    return (float*) malloc(sizeof(float)* ((ren) * (col)) );
}
//**********************************************************************
float * copiar(float *p,int ren,int col)
{
    float *copia, *copia1, *p1;
    int i;
    //Creacion del espacio de la matriz
    copia = (float*) malloc(sizeof(float)* ((ren) * (col)) );
    // Iteradores de las matrices
    copia1 = copia;
    p1 = p;
    //copiando elemento a elemento de la matriz
    for(i = 0 ; i < ren*col ; i++,p1++,copia1++) *copia1 = *p1;

    return copia;
}
//**********************************************************************
/*
    ASCII codes:
*/
#define BARRA_VER 179
#define ESQ_SUP_IZQ 218
#define ESQ_SUP_DER 191
#define ESQ_INF_IZQ 192
#define ESQ_INF_DER 217
//Constante para dar espaciado a los valores de la matriz y estos puedan ser apreciados
#define ESPACIADO 5
void pintar(float *p, int ren, int col)
{
    float *p1;
    int i,j;
    //Tomamamos el incio de la matriz
    p1 = p;

    std::cout << char(ESQ_SUP_IZQ);
    //Cantidad de columnas por el espacio dejado para la apreciacion de los datos
    for(i = 0 ; i < col * ESPACIADO ; ++i) std::cout << " ";
    std::cout << char(ESQ_SUP_DER) << std::endl;

    for(i = 0 ; i < ren ; ++i){
        std::cout << char(BARRA_VER);
        for(j = 0 ; j < col ; ++j, p1++){
            //Imprimiendo valor de la posicion de la matriz
            std::cout << std::setw(ESPACIADO) << *p1;
        }
        std::cout << char(BARRA_VER);
        std::cout << std::endl;
    }

    std::cout << char(ESQ_INF_IZQ);
    //Cantidad de columnas por el espacio dejado para la apreciacion de los datos
    for(i = 0 ; i < col * ESPACIADO ; ++i) std::cout << " ";
    std::cout << char(ESQ_INF_DER) << std::endl;

}
//**********************************************************************
float * leer(char * nombre_archivo, int *ren, int *col)
{
    std::ifstream entrada;
    entrada.open(nombre_archivo);

    if(!entrada){
        std::cout << "Error: no se pudo abrir el archivo..." << std::endl;

        system("pause");
        return NULL;
    }
    //Guardando dimensiones
    entrada >> *ren;
    entrada >> *col;
    //Creando espacio y copia del puntero para regresar
    float *p, *p1;
    p =  (float*) malloc(sizeof(float)* ((*ren) * (*col)) );
    p1 = p;
    //Variable dada para ir leyendo el archivo e itrera
    float x;
    int i;
    //Empezamos a leer el archivo
    for(i = 0 ; i < ((*ren)*(*col)) ; ++i, ++p1){
        entrada >> x;
        (*p1) = x;
    }

    entrada.close();

    return p;
}
//**********************************************************************
void escribir(char * nombre_archivo, float *p, int ren, int col)
{
    float *p1;
    int i,j;

    std::ofstream salida;
    salida.open(nombre_archivo);

    //Se escriben las dimensiones
    salida << ren << " " << col << std::endl;
    salida << std::endl;
    //Para recorrer la matriz copiamos el puntero
    p1 = p;

    //Se escribe elemento a elemento
    for(i = 0 ; i < (ren) ; ++i){
        for(j = 0 ; j < (col) ; ++j, ++p1){
            salida << *p1 << " ";
        }
        salida << std::endl;
    }

    std::cout << "\nGuardada matriz en " << nombre_archivo << std::endl;
    salida.close();
}
//**********************************************************************
void suma(float *p, float *q, float *r, int ren, int col)
{
    float *p1,*q1,*r1;
    int i;

    p1 = p;
    q1 = q;
    r1 = r;

    for(i = 0 ; i < ren*col ; ++i, ++p1, ++q1, ++r1){
        *r1 = *p1 + *q1;
    }
}
//**********************************************************************
void resta(float *p, float *q, float *r, int ren, int col)
{
    float *p1,*q1,*r1;
    int i;

    p1 = p;
    q1 = q;
    r1 = r;

    for(i = 0 ; i < ren*col ; ++i, ++p1, ++q1, ++r1){
        *r1 = *p1 - *q1;
    }
}
//**********************************************************************
void prod_mat_vec(float *p, float *q, float *r, int m, int n)
{
    // Iteradores de las matrices
    float *p1,*q1,*r1;

    int i,j;

    p1 = p;
    q1 = q;
    r1 = r;

    for(i = 0 ; i < m ; i++, r1++){
        //eliminamos posible basura
        *r1 = 0.0;
        //Reiniciamos el vector b
        q1 = q;
        for(j = 0 ; j < n ; j++, p1++, q1++){
            *r1 += (*p1) * (*q1);
        }
    }
}
//**********************************************************************
void prod_mat_mat_1(float *p, float *q, float *r, int m, int n, int k)
{
    // Iteradores de las matrices
    float *p1,*q1,*r1;
    // Iteran m,n,k respectivamente
    int i,j,l;

    p1 = p;
    q1 = q;
    r1 = r;

    for(i = 0 ; i < m ; i++){
        for(l = 0 ; l < k ; l++){
            //Limpiamos de posible basura
            *r1 = 0.0;
            //Posicionamos el puntero de la matriz B en el inicio de la columna a asignar
            q1 = q + l;
            for(j = 0 ; j < n ; j++){
                //Sumatoria de la multiplicacion
                *r1 += (*p1) * (*q1);
                //Avanzamos en el renglon de la matriz A
                p1++;
                //Avanzamos en la columna de la matriz B
                q1 += k;
            }
        }
    }
}
//**********************************************************************
void prod_mat_mat_2(float *p, float *q, float *r, int m, int n, int k)
{

}
//**********************************************************************
void prod_mat_mat_3(float *p, float *q, float *r, int m, int n, int k)
{

}
//**********************************************************************
void prod_mat_mat_4(float *p, float *q, float *r, int m, int n, int k)
{

}
//**********************************************************************
float * prod_mat_mat_archivo(char * nombre_archivo)
{
    std::ifstream entrada;
    entrada.open(nombre_archivo);

    if(!entrada){
        std::cout << "Error: no se pudo abrir el archivo..." << std::endl;

        system("pause");
        return NULL;
    }
    // Variables necesitadas
    int m,n,k;
    float *p,*p1,*q,*q1,*r,*r1;
    // iteradores
    int i,j,l;
    //Guardando dimensiones
    entrada >> m;
    entrada >> n;
    entrada >> k;
    //Creando espacio y copia del puntero para iterar y modificar la matriz
    p =  (float*) malloc(sizeof(float)* ((m) * (n)) );
    p1 = p;

    q =  (float*) malloc(sizeof(float)* ((n) * (k)) );
    q1 = q;
    //Puntero donde estara la solucion
    r =  (float*) malloc(sizeof(float)* ((m) * (k)) );
    r1 = r;

    //Variable dada para ir leyendo el archivo e iterar
    float x;

    //Empezamos a leer el archivo, la primer matriz es A[m][n]
    for(i = 0 ; i < ((m)*(n)) ; ++i, ++p1){
        entrada >> x;
        (*p1) = x;
    }
    //La segunda matriz es B[n][k]
    for(i = 0 ; i < ((n)*(k)) ; ++i, ++q1){
        entrada >> x;
        (*q1) = x;
    }
    //Saliendo de forma segura
    entrada.close();
    free(p);
    free(q);
    return r;
}
//**********************************************************************

//**********************************************************************

//**********************************************************************

//**********************************************************************

//**********************************************************************

//**********************************************************************

//**********************************************************************

//**********************************************************************

//**********************************************************************

