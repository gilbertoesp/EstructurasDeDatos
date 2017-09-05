#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

/**
	GEM-.cpp
[Descripcion]
@autor Gilberto Espinoza
@date
*/
//**********************************************************************
/**
    Creamos una matriz de dimensiones ren x col, dadas en los parametros
	\param ren : Cantidad de Renglones
	\param col : Cantidad de Columnas
	\return Direccion de inicio de la matriz
*/
float * crear(int ren,int col);
//**********************************************************************
/**
    Copiamos los valores de una matriz en otra, regresamos esta nueva matriz
    \param ren : Cantidad de Renglones
	\param col : Cantidad de Columnas
	\return Direccion de inicio de la matriz
*/
float * copiar(float *p,int ren,int col);
//**********************************************************************
/**
    Imprime una matriz en consola
	\param Inicio de la matriz. A[0][0]
	\param Renglones
	\param Columnas
*/
void pintar(float *p, int ren, int col);
//**********************************************************************
/**
    Archivo de texto a matriz
	\param Nombre del archivo
	\param Direccion de los renglones
	\param Direccion de las columnas
	\return Inicio de la matriz creada
*/
float * leer(char * nombre_archivo, int *ren, int *col);
//**********************************************************************
/**
    Matriz a archivo de Texto
	\param Nombre del archivo
	\param Inicio de la matriz
	\param Renglones
	\param Columnas
	\return
*/
void escribir(char * nombre_archivo, float *p, int ren, int col);
//**********************************************************************
/**
    Suma de dos matrices para ser guardada en una tercera
	\param Inicio de la matriz A
	\param Inicio de la matriz B
	\param Inicio de la matriz C
	\param Renglones
	\param Columnas
*/
void suma(float *p, float *q, float *r, int ren, int col);
//**********************************************************************
/**
    Resta de dos matrices para ser guardada en una tercera
	\param Inicio de la matriz A
	\param Inicio de la matriz B
	\param Inicio de la matriz C (resultado)
	\param Renglones
	\param Columnas
*/
void resta(float *p, float *q, float *r, int ren, int col);
//**********************************************************************
/**

	\param
	\param
	\return
*/
void prod_mat_vec(float *p, float *q, float *r, int m, int n);
//**********************************************************************
/**
    Primera forma para multiplicacion de matrices
    \param Inicio de la matriz A
	\param Inicio de la matriz B
	\param Inicio de la matriz C (resultado)
	\param Dimension m
	\param Dimension n
	\param Dimension k
*/
void prod_mat_mat_1(float *p, float *q, float *r, int m, int n, int k);
//**********************************************************************
/**
    Segunda forma para multiplicacion de matrices
    \param Inicio de la matriz A
	\param Inicio de la matriz B
	\param Inicio de la matriz C (resultado)
	\param Dimension m
	\param Dimension n
	\param Dimension k
*/
void prod_mat_mat_2(float *p, float *q, float *r, int m, int n, int k);
//**********************************************************************
/**
    Tercera forma para multiplicacion de matrices
    \param Inicio de la matriz A
	\param Inicio de la matriz B
	\param Inicio de la matriz C (resultado)
	\param Dimension m
	\param Dimension n
	\param Dimension k
*/
void prod_mat_mat_3(float *p, float *q, float *r, int m, int n, int k);
//**********************************************************************
/**
    Cuarta forma para multiplicacion de matrices
    \param Inicio de la matriz A
	\param Inicio de la matriz B
	\param Inicio de la matriz C (resultado)
	\param Dimension m
	\param Dimension n
	\param Dimension k
*/
void prod_mat_mat_4(float *p, float *q, float *r, int m, int n, int k);
//**********************************************************************
/**
    Dado un archivo que contenga las dimensiones m,n,k y dos matrices
    siendo la primera de m x n y la segunda de n x k, calcula su multiplicacion.
    y crea la matriz donde guardar esta para despues regresar su direccion
	\param Nombre del archivo
	\param Renglones de matriz resultado
	\param Columnas de la matriz resultado
	\return Direccion de la matriz AxB creada
*/
float * prod_mat_mat_archivo(char * nombre_archivo, int *ren, int *col);
//**********************************************************************
/**
    Intercambia dos renglones p y q de longitud n
	\param Inicio de la renglon 1 a intercambiar
	\param Inicio de la renglon 2 a intercambiar
	\param Longitud del renglon
*/
void intercambiarRen(float *p,float *q, int n);
//**********************************************************************
/**
    Funcion que dado el renglon de una matriz, este es multiplicado por el reciproco
    del elemento inicial de p, se empieza desde el puntero p y avanza en el renglon la cantidad n
    de veces.
	\param Elemento a calcular su reciproco y hacer uno
	\param Cantidad de elementos que siguen despues de p
	\return Reciprobo de p. Elemento por el cual el renglon fue multiplicado
*/
float hacer_uno(float *p, int n);
//**********************************************************************
/**

	\param
	\param
	\return
*/
float hacer_cero(float *p,float *q, int n);
//**********************************************************************
/**

	\param
	\param
	\return
*/
float reducir(float *p, float *q, int n);
//**********************************************************************
/**

	\param
	\param
	\return
*/
float resolver(float *p, float *q, int n);
//**********************************************************************
/**

	\param
	\param
	\return
*/
float * inversa(float *p, int m, int n);
//**********************************************************************
/**

	\param
	\param
	\return
*/

//**********************************************************************

#endif // MATRIZ_H_INCLUDED
