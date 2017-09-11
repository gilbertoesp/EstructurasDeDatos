/**
	GEM-.cpp
[Descripcion]
@autor Gilberto Espinoza
@date
*/

#include <iostream>
#include <cstdlib>
#include "vector.h"
#include <iomanip> //std::setw
#include <fstream> // Manejo de archivos
#include <cmath> // abs


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
#define ESPACIADO 15
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
    // Iteran m,k,n respectivamente
    int i,j,a;

    p1 = p;
    q1 = q;
    r1 = r;

    /// (m x n) * (n x k) = (m x k)
    //Se toma cada renglon de Matriz_A
    for(i = 0 ; i < m ; ++i){
        //Cada columna de Matriz_B
        for(j = 0 ; j < k ; ++j,r1++){
            //y con n cada elemento de ellas, se multiplican y suman para ser guaradas en (i, j)
            *(r1) = 0.0;
            //Posicionamos el recorredor al incio del renglon
            p1 = p + i * n;
            //Posicionamos el recorredor al inicio de la columna
            q1 = q + j;
            //Avanzamos con el puntero directo
            for(a = 0 ; a < n ; ++a, p1++, q1 += k){
                *(r1) += *(p1) * *(q1);
            }
        }
    }
}
//**********************************************************************
void prod_mat_mat_2(float *p, float *q, float *r, int m, int n, int k)
{
    // Iteradores de las matrices
    float *p1,*q1,*r1;
    // Iteran m,k,n respectivamente
    int i,j,a;

    p1 = p;
    q1 = q;
    r1 = r;

    /// (m x n) * (n x k) = (m x k)
    //Se toma cada renglon de Matriz_A
    for(i = 0 ; i < m ; ++i){
        //Cada columna de Matriz_B
        for(j = 0 ; j < k ; ++j,r1++){
            //y con n cada elemento de ellas, se multiplican y suman para ser guaradas en (i, j)
            *(r1) = 0.0;
            //Posicionamos el recorredor al incio del renglon
            p1 = p + i * n;
            //Posicionamos el recorredor al inicio de la columna
            q1 = q + j;
            //Avanzamos con el puntero directo
            for(a = 0 ; a < n ; ++a, p1++, q1 += k){
                *(r1) += *(p1) * *(q1);
            }
        }
    }
}
//**********************************************************************
void prod_mat_mat_3(float *p, float *q, float *r, int m, int n, int k)
{
    // Iteradores de las matrices
    float *p1,*q1,*r1;
    // Iteran m,k,n respectivamente
    int i,j,a;

    p1 = p;
    q1 = q;
    r1 = r;

    /// (m x n) * (n x k) = (m x k)
    //Se toma cada renglon de Matriz_A
    for(i = 0 ; i < m ; ++i){
        //Cada columna de Matriz_B
        for(j = 0 ; j < k ; ++j,r1++){
            //y con n cada elemento de ellas, se multiplican y suman para ser guaradas en (i, j)
            *(r1) = 0.0;
            //Posicionamos el recorredor al incio del renglon
            p1 = p + i * n;
            //Posicionamos el recorredor al inicio de la columna
            q1 = q + j;
            //Avanzamos con el puntero directo
            for(a = 0 ; a < n ; ++a, p1++, q1 += k){
                *(r1) += *(p1) * *(q1);
            }
        }
    }
}
//**********************************************************************
void prod_mat_mat_4(float *p, float *q, float *r, int m, int n, int k)
{
    // Iteradores de las matrices
    float *p1,*q1,*r1;
    // Iteran m,k,n respectivamente
    int i,j,a;

    p1 = p;
    q1 = q;
    r1 = r;

    /// (m x n) * (n x k) = (m x k)
    //Se toma cada renglon de Matriz_A
    for(i = 0 ; i < m ; ++i){
        //Cada columna de Matriz_B
        for(j = 0 ; j < k ; ++j,r1++){
            //y con n cada elemento de ellas, se multiplican y suman para ser guaradas en (i, j)
            *(r1) = 0.0;
            //Posicionamos el recorredor al incio del renglon
            p1 = p + i * n;
            //Posicionamos el recorredor al inicio de la columna
            q1 = q + j;
            //Avanzamos con el puntero directo
            for(a = 0 ; a < n ; ++a, p1++, q1 += k){
                *(r1) += *(p1) * *(q1);
            }
        }
    }
}
//**********************************************************************
float * prod_mat_mat_archivo(char * nombre_archivo, int *ren, int *col)
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
    float *p,*p1,*q,*q1,*r;
    // iteradores
    int i;
    //Guardando dimensiones los tres primeros numeros
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

    ///Multiplicacion
    prod_mat_mat_1(p,q,r,m,n,k);

    //Saliendo de forma segura
    entrada.close();
    free(p);
    free(q);

    *ren = m;
    *col = k;
    return r;
}
//**********************************************************************
void intercambiarRen(float *p,float *q, int n)
{
    float aux, *p1,*q1;
    p1 = p;
    q1 = q;

    for(int i = 0 ; i < n ; i++, p1++, q1++){
        aux = *p1;
        *p1 = *q1;
        *q1 = aux;
    }
}
///********     PRIMERA FORMA DE RESOLVER   **************************************************************
    float hacer_uno(float *p, int n)
    {
        float *p1, valor;

        p1 = p;

        valor = 1.0 / *p1;

        for(int i = 0 ; i < n ; i++, p1++){
            *p1 = valor * (*p1);
        }
        return valor;
    }
    //**********************************************************************
    float hacer_cero(float *p,float *q, int n)
    {
        float *p1,*q1,valor;

        p1 = p;
        q1 = q;

        valor = -(*q1);

        for(int i = 0 ; i < n ; i++, p1++,q1++){
            //Haciendo la suma
            *q1 = *q1 + (valor * (*p1));
        }

        return valor;
    }
    //**********************************************************************
    void reducir(float *p, float *q, int n)
    {
        //Recorredores de la matriz y el vector
        float *p1,*q1, valor;
        p1 = p;
        q1 = q;
        //Recoremos la matriz
        // Avanzamos el apuntador de la matriz en diagonal ( += n + 1) y el vector en lineal
        for(int i = 0 ; i < n ; i++, p1 += n+1, q1++){
            ///Pivoteo
            //Revisamos uno por uno cada elemento debajo de p1
            for(int j = 1 ; j < n - i ; j++){
                // Si el elemento debajo de p1, es mayor se intercambia
                if( std::abs(*(p1 + j * n )) > std::abs(*p1) ){
                    intercambiarRen(p1, (p1 + j * n ), n - i);
                    //Intercambiamos los valores del vector resutlado, con un metodo de burbuja simple
                    valor = *q1;
                    *q1 = *(q1 + j);
                    *(q1 + j) = valor;
                }

            }
            //Hacemos uno el primer elemento del renglon, y dada esta modificacion, manipulamos
            // todo lo que esta por enfrente de esta posicion, hasta n (dimension de la matriz)
            valor = hacer_uno(p1, n - i);
            //Modificamos el vector con el valor el cual manipulamos la matriz
            *q1 = (*q1) * valor;
            // Haremos cero todos los renglones por debajo del renglon que acabamos de hacer uno
            // Para ello empezamos este contador con uno para modificar el de abajo de p1, y el ciclo se acaba en la
            // cantidad de renglones restantes por procesar
            for(int j = 1 ; j < n - i ; j++){
                //Hacemos cero con base al renglon recien hecho uno, todos lo que le siguen por debajo recorriendo
                // cada renglon, cada uno de estos renglones tienen una longitud n - i, dado que avanzamos en diagonal
                valor = hacer_cero(p1, p1 + (j * n), n - i);
                //Modificamos el elemento del vector que corresponde
                *(q1 + j) = *(q1 + j) + valor * (*q1);
            }
        }
    }
    //**********************************************************************
    void resolver(float *p, float *q, int n)
    {
        float *p1,*q1, valor;
        p1 = p;
        q1 = q;
        //Reducimos la matriz
        reducir(p1,q1,n);
        ///Sustitucion hacia atras
        //Recorremos la matriz hasta el penultimo renglon
        for(int i = 0 ; i < n - 1 ; i++){
            //Posicionamos el apuntador de la matriz arriba del 1 empezando por el ultimo
            p1 = p + (n - i - 2 ) * n + (n - i - 1);
            //Posicionamos el vector en el mismo renglon que la p que manipulamos
            q1 = q + (n - i - 2);
            //Extraemos el valor de la incognita recien descubierta, siendo la primera resulta por reducir
            // y en cada iteracion se descubre la siguiente
            valor = *(q1+1);
            //Recorremos la matriz hacia "arriba", retrocedemos en el vector y en la columna
            for(int j = 0 ; j < n - (i - 1) ; j++, q1--, p1 -= n){
                //A cada resultado en el vector le restamos la multiplicaicion del elemento de la columna por la incognita recien resuelta
                *q1 = *q1 - (valor * *p1);
            }
        }
/*
void resolver(float *p, float *q, int n)
+{
+    float *p1,*q1, valor;
+    p1 = p;
+    q1 = q;
+    //Reducimos la matriz
+    reducir(p1,q1,n);
+    ///Sustitucion hacia atras
+    for(int i = 0 ; i < n - 1 ; i++){
+        p1 = p + (n - i - 2 ) * n + (n - i - 1);
+        q1 = q + (n - i - 2);
+        valor = *(q1+1);
+        for(int j = 0 ; j < n - (i - 1) ; j++, q1--, p1 -= n){
+            *q1 = *q1 - (valor * *p1);
+        }
+    }
*/

    }
    //**********************************************************************
///********     SEGUNDA FORMA DE RESOLVER   **************************************************************
    float hacer_uno_2(float *p, int n, int dim)
    {
        float *p1, valor;

        p1 = p;

        valor = 1.0 / *p1;
        //*** En esta version en vez de avanzar hacia enfrente, lo hacemos hacia abajo
        for(int i = 0 ; i < n ; i++, p1+=dim){
            *p1 = valor * (*p1);
        }
        return valor;
    }
    //**********************************************************************
    float hacer_cero_2(float *p,float *q, int n,int dim)
    {
        float *p1,*q1,valor;

        p1 = p;
        q1 = q;

        valor = -(*q1);
        // *** En esta version en vez de dos renglones manejamos dos columnas entonces en vez de
        // avanzar 1 en 1, avanzamos en n
        for(int i = 0 ; i < n ; i++, p1 += dim, q1 += dim){
            //Haciendo la suma
            *q1 = *q1 + (valor * (*p1));
        }

        return valor;
    }
    //**********************************************************************
    void reducir_2(float *p, float *q, int n)
    {
        //Recorredores de la matriz y el vector
        float *p1,*q1, valor;
        p1 = p;
        q1 = q;
        //Recoremos la matriz
        // Avanzamos el apuntador de la matriz en diagonal ( += n + 1) y el vector en lineal
        for(int i = 0 ; i < n ; i++, p1 += n+1, q1++){
            //Hacemos uno el primer elemento del renglon, y dada esta modificacion, manipulamos
            // todo lo que esta por enfrente de esta posicion, hasta n (dimension de la matriz)
            valor = hacer_uno_2(p1, n - i,n);
            //Modificamos el vector con el valor el cual manipulamos la matriz
            *q1 = (*q1) * valor;
            // Haremos cero todos los renglones por debajo del renglon que acabamos de hacer uno
            // Para ello empezamos este contador con uno para modificar el de abajo de p1, y el ciclo se acaba en la
            // cantidad de renglones restantes por procesar
            for(int j = 1 ; j < n - i ; j++){
                //Hacemos cero con base al renglon recien hecho uno, todos lo que le siguen por debajo recorriendo
                // cada renglon, cada uno de estos renglones tienen una longitud n - i, dado que avanzamos en diagonal
                // *** En esta version le damos la direccion del renglon de al lado
                valor = hacer_cero_2(p1, p1 + (j), n - i,n);
                //Modificamos el elemento del vector que corresponde
                *(q1 + j) = *(q1 + j) + valor * (*q1);
            }
        }
    }
    //**********************************************************************
    void resolver_2(float *p, float *q, int n)
    {
        float *p1,*q1, valor;
        p1 = p;
        q1 = q;
        //Reducimos la matriz
        reducir_2(p1,q1,n);
        // *** En esta version son las operaciones transpuestas
        ///Sustitucion hacia atras
        //Recorremos la matriz hasta el penultimo renglon
        for(int i = 0 ; i < n - 1 ; i++){
            //Posicionamos el apuntador de la matriz arriba del 1 empezando por el ultimo
            p1 = p + (n-i-1) * n + (n - i - 2 );
            //Posicionamos el vector en el mismo renglon que la p que manipulamos
            q1 = q + (n - i - 2);
            //Extraemos el valor de la incognita recien descubierta, siendo la primera resulta por reducir
            // y en cada iteracion se descubre la siguiente
            valor = *(q1+1);
            //Recorremos la matriz hacia "arriba", retrocedemos en el vector y en la columna
            for(int j = 0 ; j < n - (i - 1) ; j++, q1--, p1--){
                //A cada resultado en el vector le restamos la multiplicaicion del elemento de la columna por la incognita recien resuelta
                *q1 = *q1 - (valor * *p1);
            }
        }


    }
    //**********************************************************************
///********     TERCER FORMA DE RESOLVER   **************************************************************
/// *** En esta version ademas de recorrerse renglones en reversa
    float hacer_uno_3(float *p, int n)
    {
        float *p1, valor;

        p1 = p;

        valor = 1.0 / *p1;
        //*** En esta version en vez de avanzar hacia enfrente, lo hacemos hacia abajo
        for(int i = 0 ; i < n ; i++, p1--){
            *p1 = valor * (*p1);
        }
        return valor;
    }
    //**********************************************************************
    float hacer_cero_3(float *p,float *q, int n)
    {
        float *p1,*q1,valor;

        p1 = p;
        q1 = q;

        valor = -(*q1);
        // *** En esta version en vez de dos renglones manejamos dos columnas entonces en vez de
        // avanzar 1 en 1, avanzamos en n
        for(int i = 0 ; i < n ; i++, p1--, q1--){
            //Haciendo la suma
            *q1 = *q1 + (valor * (*p1));
        }

        return valor;
    }
    //**********************************************************************
    void reducir_3(float *p, float *q, int n)
    {
        //Recorredores de la matriz y el vector
        float *p1,*q1, valor;
        // *** Final del primer renglon
        p1 = p + n - 1;
        q1 = q;
        //Recoremos la matriz
        // Avanzamos el apuntador de la matriz en diagonal ( += n - 1) y el vector en lineal
        for(int i = 0 ; i < n ; i++, p1 += n-1, q1++){
            //Hacemos uno el primer elemento del renglon, y dada esta modificacion, manipulamos
            // todo lo que esta por enfrente de esta posicion, hasta n (dimension de la matriz)
            valor = hacer_uno_3(p1, n - i);
            //Modificamos el vector con el valor el cual manipulamos la matriz
            *q1 = (*q1) * valor;
            // Haremos cero todos los renglones por debajo del renglon que acabamos de hacer uno
            // Para ello empezamos este contador con uno para modificar el de abajo de p1, y el ciclo se acaba en la
            // cantidad de renglones restantes por procesar
            for(int j = 1 ; j < n - i ; j++){
                //Hacemos cero con base al renglon recien hecho uno, todos lo que le siguen por debajo recorriendo
                // cada renglon, cada uno de estos renglones tienen una longitud n - i, dado que avanzamos en diagonal
                valor = hacer_cero_3(p1, p1 + (j * n), n - i);
                //Modificamos el elemento del vector que corresponde
                *(q1 + j) = *(q1 + j) + valor * (*q1);
            }

        }
    }
    //**********************************************************************
    void resolver_3(float *p, float *q, int n)
    {
        float *p1,*q1, valor;
        p1 = p;
        q1 = q;
        //Reducimos la matriz
        reducir_3(p1,q1,n);
        ///Sustitucion hacia atras
        //Recorremos la matriz hasta el penultimo renglon
        for(int i = 0 ; i < n - 1 ; i++){
            //Posicionamos el apuntador de la matriz arriba del 1 empezando por el ultimo
            p1 = p + (n - i - 2 ) * n + ( i );
            //Posicionamos el vector en el mismo renglon que la p que manipulamos
            q1 = q + (n - i - 2);
            //Extraemos el valor de la incognita recien descubierta, siendo la primera resulta por reducir
            // y en cada iteracion se descubre la siguiente
            valor = *(q1+1);
            //Recorremos la matriz hacia "arriba", retrocedemos en el vector y en la columna
            for(int j = 0 ; j < n - (i - 1) ; j++, q1--, p1 -= n){
                //A cada resultado en el vector le restamos la multiplicacion del elemento de la columna por la incognita recien resuelta
                *q1 = *q1 - (valor * *p1);
            }
        }
    }
    //**********************************************************************
///********     CUARTA FORMA DE RESOLVER   **************************************************************
    float hacer_uno_4(float *p, int n, int dim)
    {
        float *p1, valor;

        p1 = p;

        valor = 1.0 / *p1;
        //*** En esta version en vez de avanzar hacia enfrente, lo hacemos hacia abajo
        for(int i = 0 ; i < n ; i++, p1+=dim){
            *p1 = valor * (*p1);
        }
        return valor;
    }
    //**********************************************************************
    float hacer_cero_4(float *p,float *q, int n,int dim)
    {
        float *p1,*q1,valor;

        p1 = p;
        q1 = q;

        valor = -(*q1);
        // *** En esta version en vez de dos renglones manejamos dos columnas entonces en vez de
        // avanzar 1 en 1, avanzamos en n
        for(int i = 0 ; i < n ; i++, p1 += dim, q1 += dim){
            //Haciendo la suma
            *q1 = *q1 + (valor * (*p1));
        }

        return valor;
    }
    //**********************************************************************
    void reducir_4(float *p, float *q, int n)
    {
        //Recorredores de la matriz y el vector
        float *p1,*q1, valor;
        p1 = p + n - 1;
        q1 = q;
        //Recoremos la matriz
        // Avanzamos el apuntador de la matriz en diagonal ( += n + 1) y el vector en lineal
        for(int i = 0 ; i < n ; i++, p1 += n-1, q1++){
            //Hacemos uno el primer elemento del renglon, y dada esta modificacion, manipulamos
            // todo lo que esta por enfrente de esta posicion, hasta n (dimension de la matriz)
            valor = hacer_uno_4(p1, n - i, n);
            //Modificamos el vector con el valor el cual manipulamos la matriz
            *q1 = (*q1) * valor;
            // Haremos cero todos los renglones por debajo del renglon que acabamos de hacer uno
            // Para ello empezamos este contador con uno para modificar el de abajo de p1, y el ciclo se acaba en la
            // cantidad de renglones restantes por procesar
            for(int j = 1 ; j < n - i ; j++){
                //Hacemos cero con base al renglon recien hecho uno, todos lo que le siguen por debajo recorriendo
                // cada renglon, cada uno de estos renglones tienen una longitud n - i, dado que avanzamos en diagonal
                valor = hacer_cero_4(p1, p1 - (j), n - i,n);
                //Modificamos el elemento del vector que corresponde
                *(q1 + j) = *(q1 + j) + valor * (*q1);
            }
        }
    }
    //**********************************************************************
    void resolver_4(float *p, float *q, int n)
    {
        float *p1,*q1, valor;
        p1 = p;
        q1 = q;
        //Reducimos la matriz
        reducir(p1,q1,n);
        ///Sustitucion hacia atras
        //Recorremos la matriz hasta el penultimo renglon
        for(int i = 0 ; i < n - 1 ; i++){
            //Posicionamos el apuntador de la matriz arriba del 1 empezando por el ultimo
            p1 = p + (n - i - 2 ) * n + (n - i - 1);
            //Posicionamos el vector en el mismo renglon que la p que manipulamos
            q1 = q + (n - i - 2);
            //Extraemos el valor de la incognita recien descubierta, siendo la primera resulta por reducir
            // y en cada iteracion se descubre la siguiente
            valor = *(q1+1);
            //Recorremos la matriz hacia "arriba", retrocedemos en el vector y en la columna
            for(int j = 0 ; j < n - (i - 1) ; j++, q1--, p1 -= n){
                //A cada resultado en el vector le restamos la multiplicaicion del elemento de la columna por la incognita recien resuelta
                *q1 = *q1 - (valor * *p1);
            }
        }


    }
    //**********************************************************************
//**********************************************************************
float * inversa(float *p, int n)
{
    float *p1, *inv, *q1, valor;

    inv = crear(n,n);
    q1 = inv;
    p1 = p;
    //Creando matriz identidad en inv
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++,q1++){
            if( i == j) *q1 = 1;
            else *q1 = 0;
        }
    }

    q1=inv;

    for(int i = 0 ; i < n ; i++, p1 += n+1, q1 += n+1){
        valor = hacer_uno_3(p1, n - i);

        for(int j = 0 ; j < n - i ; j++) *(q1+j) = valor * *(q1+j);
        //Hacemos cero la columna por debajo de p1
        for(int j = 1 ; j < n - i ; j++){
            //Haciendo cero los renglones por debajo
            valor = hacer_cero_3(p1, p1 + (j * n), n - i);
            for(int a = 0 ; a < n - i ; a++) *(q1 + a * n) += valor * *(q1+a);
            valor = hacer_cero_4(p1, p1 + j, n- i, n);
            //Modificamos los renglones corespondientes en la identidad
            for(int a = 0 ; a < n - i ; a++) *(q1 + a) += valor * *(q1+a);

        }

    }
    return inv;
}
//**********************************************************************
float * inversa_2(float *p, int n)
{
    float *p1, *inv, *q1, valor;

    inv = crear(n,n);
    q1 = inv;
    p1 = p;
    //Creando matriz identidad en inv
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++,q1++){
            if( i == j) *q1 = 1;
            else *q1 = 0;
        }
    }

    q1=inv;

    for(int i = 0 ; i < n ; i++, p1 += n+1, q1 += n+1){
        valor = hacer_uno(p1, n - i);

        for(int j = 0 ; j < n - i ; j++) *(q1+j) = valor * *(q1+j);
        //Hacemos cero la columna por debajo de p1
        for(int j = 1 ; j < n - i ; j++){
            //Haciendo cero los renglones por debajo
            valor = hacer_cero(p1, p1 + (j * n), n - i);
            for(int a = 0 ; a < n - i ; a++) *(q1 + a * n) += valor * *(q1+a);
            valor = hacer_cero_4(p1, p1 + j, n- i, n);
            //Modificamos los renglones corespondientes en la identidad
            for(int a = 0 ; a < n - i ; a++) *(q1 + a) += valor * *(q1+a);

        }

    }
    return inv;
}

