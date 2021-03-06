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
///********     PRIMERA FORMA DE RESOLVER   **************************************************************
/// EN ESTA FORMA LA MATRIZ SE REDUCE A TRIANGULAR SUPERIOR A LA DERECHA
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
        Dado un lugar de una matriz donde se encuentra un 1 (hacer_uno), recibido en p
        realiza las operaciones para que el elemento q sea 0, multiplicando p por el inverso de q
        y luego sumandolo a este mismo. Mismo proceso se repete una cantidad n de veces al avance del
        renglon.
        \param Renglon que comienza en 1;
        \param Renglon que comienza en el elemento que queremos hacer cero
        \return Valor por el cual el renglon p fue multiplicado para hacer cero
    */
    float hacer_cero(float *p,float *q, int n);
    //**********************************************************************
    /**
        Tomamos una matriz y un vector y modificamos estos para que la matriz en p, quede de forma
        triangular superior, con la diagonal mayor de 1's, estas modificaciones se hacen a la par con
        el vector en q. Este metodo solo acepta matrices cuadradas junto con vectores de la misma dimension.
        Para la reduccion este metodo involucra PIVOTEO PARCIAL, revisando que el valor que se cambia a uno sea en
        efecto el mayor absoluto

        \param Matriz a reducir, inicio en A[1][1]
        \param Vector b que es el resultado de la matriz. Sera modificado
        \param Dimension de las estructuras
    */
    void reducir(float *p, float *q, int n);
    //**********************************************************************
    /**
        Dada una matriz cuadrada y un vector de dimension n, los reduce y hace sustitucion hacia atras para
        encontrar un vector x que multiplicado por la matriz dada da como resultado al vector dado.
        Utiliza el metodo reducir, el cual es Gauss-Jordan con Pivoteo Parcial
        \param Matriz A
        \param Vector b, en este vector quedara la solucion
        \param Dimension de la matriz y vector
    */
    void resolver(float *p, float *q, int n);
//**********************************************************************
///********     SEGUNDA FORMA DE RESOLVER   **************************************************************
/// EN ESTA FORMA LA MATRIZ SE REDUCE A TRIANGULAR INFERIOR A LA DERECHA, No pivoteamos
    /**
        Funcion que dado el renglon de una matriz, este es multiplicado por el reciproco
        del elemento inicial de p, se empieza desde el puntero p y avanza en el renglon la cantidad n
        de veces.
        *** En esta version necesitamos mandar la dimension que estamos manejando para poder los saltos
            en de este tamano y avanzar por columnas
        \param Elemento a calcular su reciproco y hacer uno
        \param Cantidad de elementos que siguen despues de p
        \param Dimension de la matriz
        \return Reciprobo de p. Elemento por el cual el renglon fue multiplicado
    */
    float hacer_uno_2(float *p, int n, int dim);
    //**********************************************************************
    /**
        Dado un lugar de una matriz donde se encuentra un 1 (hacer_uno), recibido en p
        realiza las operaciones para que el elemento q sea 0, multiplicando p por el inverso de q
        y luego sumandolo a este mismo. Mismo proceso se repete una cantidad n de veces al avance del
        renglon.
        *** En esta version necesitamos mandar la dimension que estamos manejando para poder los saltos
            en de este tamano y avanzar por columnas
        \param Renglon que comienza en 1;
        \param Renglon que comienza en el elemento que queremos hacer cero
        \param Cantidad de elementos por enfrente en la estructura (renglon o columnas)
        \param Dimension de la matriz
        \return Valor por el cual el renglon p fue multiplicado para hacer cero
    */
    float hacer_cero_2(float *p,float *q, int n, int dim);
    //**********************************************************************
    /**
        Tomamos una matriz y un vector y modificamos estos para que la matriz en p, quede de forma
        triangular superior, con la diagonal mayor de 1's, estas modificaciones se hacen a la par con
        el vector en q. Este metodo solo acepta matrices cuadradas junto con vectores de la misma dimension.
        Para la reduccion este metodo involucra PIVOTEO PARCIAL, revisando que el valor que se cambia a uno sea en
        efecto el mayor absoluto

        \param Matriz a reducir, inicio en A[1][1]
        \param Vector b que es el resultado de la matriz. Sera modificado
        \param Dimension de las estructuras
    */
    void reducir_2(float *p, float *q, int n);
    //**********************************************************************
    /**
        Dada una matriz cuadrada y un vector de dimension n, los reduce y hace sustitucion hacia atras para
        encontrar un vector x que multiplicado por la matriz dada da como resultado al vector dado.
        Utiliza el metodo reducir, el cual es Gauss-Jordan con Pivoteo Parcial
        \param Matriz A
        \param Vector b, en este vector quedara la solucion
        \param Dimension de la matriz y vector
    */
    void resolver_2(float *p, float *q, int n);
//**********************************************************************
///********     TERCERA FORMA DE RESOLVER   **************************************************************
/// EN ESTA FORMA LA MATRIZ SE REDUCE A TRIANGULAR SUPERIOR A LA IZQUIERDA, No pivoteamos
    /**
        Funcion que dado el renglon de una matriz, este es multiplicado por el reciproco
        del elemento inicial de p, se empieza desde el puntero p y avanza en el renglon la cantidad n
        de veces.
        \param Elemento a calcular su reciproco y hacer uno
        \param Cantidad de elementos que siguen despues de p
        \return Reciprobo de p. Elemento por el cual el renglon fue multiplicado
    */
    float hacer_uno_3(float *p, int n);
    //**********************************************************************
    /**
        Dado un lugar de una matriz donde se encuentra un 1 (hacer_uno), recibido en p
        realiza las operaciones para que el elemento q sea 0, multiplicando p por el inverso de q
        y luego sumandolo a este mismo. Mismo proceso se repete una cantidad n de veces al avance del
        renglon.
        \param Renglon que comienza en 1;
        \param Renglon que comienza en el elemento que queremos hacer cero
        \return Valor por el cual el renglon p fue multiplicado para hacer cero
    */
    float hacer_cero_3(float *p,float *q, int n);
    //**********************************************************************
    /**
        Tomamos una matriz y un vector y modificamos estos para que la matriz en p, quede de forma
        triangular superior, con la diagonal mayor de 1's, estas modificaciones se hacen a la par con
        el vector en q. Este metodo solo acepta matrices cuadradas junto con vectores de la misma dimension.
        Para la reduccion este metodo involucra PIVOTEO PARCIAL, revisando que el valor que se cambia a uno sea en
        efecto el mayor absoluto

        \param Matriz a reducir, inicio en A[1][1]
        \param Vector b que es el resultado de la matriz. Sera modificado
        \param Dimension de las estructuras
    */
    void reducir_3(float *p, float *q, int n);
    //**********************************************************************
    /**
        Dada una matriz cuadrada y un vector de dimension n, los reduce y hace sustitucion hacia atras para
        encontrar un vector x que multiplicado por la matriz dada da como resultado al vector dado.
        Utiliza el metodo reducir, el cual es Gauss-Jordan con Pivoteo Parcial
        \param Matriz A
        \param Vector b, en este vector quedara la solucion
        \param Dimension de la matriz y vector
    */
    void resolver_3(float *p, float *q, int n);
//**********************************************************************
///********     CUARTA FORMA DE RESOLVER   **************************************************************
/// EN ESTA FORMA LA MATRIZ SE REDUCE A TRIANGULAR INFERIOR A LA IZQUIERDA, No pivoteamos
    /**
        Funcion que dado el renglon de una matriz, este es multiplicado por el reciproco
        del elemento inicial de p, se empieza desde el puntero p y avanza en el renglon la cantidad n
        de veces.
        \param Elemento a calcular su reciproco y hacer uno
        \param Cantidad de elementos que siguen despues de p
        \param Dimension de la matriz
        \return Reciprobo de p. Elemento por el cual el renglon fue multiplicado
    */
    float hacer_uno_4(float *p, int n,int dim);
    //**********************************************************************
    /**
        Dado un lugar de una matriz donde se encuentra un 1 (hacer_uno), recibido en p
        realiza las operaciones para que el elemento q sea 0, multiplicando p por el inverso de q
        y luego sumandolo a este mismo. Mismo proceso se repete una cantidad n de veces al avance del
        renglon.
        \param Renglon que comienza en 1;
        \param Renglon que comienza en el elemento que queremos hacer cero
        \param Dimension de la matriz
        \return Valor por el cual el renglon p fue multiplicado para hacer cero
    */
    float hacer_cero_4(float *p,float *q, int n, int dim);
    //**********************************************************************
    /**
        Tomamos una matriz y un vector y modificamos estos para que la matriz en p, quede de forma
        triangular superior, con la diagonal mayor de 1's, estas modificaciones se hacen a la par con
        el vector en q. Este metodo solo acepta matrices cuadradas junto con vectores de la misma dimension.
        Para la reduccion este metodo involucra PIVOTEO PARCIAL, revisando que el valor que se cambia a uno sea en
        efecto el mayor absoluto

        \param Matriz a reducir, inicio en A[1][1]
        \param Vector b que es el resultado de la matriz. Sera modificado
        \param Dimension de las estructuras
    */
    void reducir_4(float *p, float *q, int n);
    //**********************************************************************
    /**
        Dada una matriz cuadrada y un vector de dimension n, los reduce y hace sustitucion hacia atras para
        encontrar un vector x que multiplicado por la matriz dada da como resultado al vector dado.
        Utiliza el metodo reducir, el cual es Gauss-Jordan con Pivoteo Parcial
        \param Matriz A
        \param Vector b, en este vector quedara la solucion
        \param Dimension de la matriz y vector
    */
    void resolver_4(float *p, float *q, int n);
//**********************************************************************
/**
    Utilizando las variaciones de las funciones hacer uno y hacer cero esta funcion toma una matriz cuadrada, crea una matriz
    identidad de la misma dimension para luego esta se convierta en la inversa
	\param Matriz a invertir
	\param Dimension
	\return Matriz inversa
*/
float * inversa(float *p, int n);
//**********************************************************************
/**
    Utilizando las variaciones de las funciones hacer uno y hacer cero esta funcion toma una matriz cuadrada, crea una matriz
    identidad de la misma dimension para luego esta se convierta en la inversa
	\param Matriz a invertir
	\param Dimension
	\return Matriz inversa
*/
float * inversa_2(float *p, int n);
//**********************************************************************

#endif // MATRIZ_H_INCLUDED
