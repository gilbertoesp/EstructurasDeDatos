#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

/**
	GEM-.cpp
[Descripcion]
\autor Gilberto Espinoza
\date
*/
//**********************************************************************
/**
    Copiamos los valores de un vector en otro, regresamos este nuevo vector
    \param dim : dimension
	\return Direccion de inicio del vector
*/
float * copiar(float *p,int dim);
//**********************************************************************
/**
    Funcion que pinta un vector entre corchetes
    \param Inicio del vector
    \param Dimension del vector
*/
void pintar(float *p, int n);
//**********************************************************************
/**
    Suma de dos vectores
    \param Inicio del vector 1
    \param Inicio del vector 2
    \param Inicio del vector donde se guardara el resultado
    \param Dimension del vector
*/
void suma(float *p, float *q, float *r, int n);
//**********************************************************************
/**
    Resta de dos vectores
    \param Inicio del vector 1
    \param Inicio del vector 2
    \param Inicio del vector donde se guardara el resultado
    \param Dimension del vector
*/
void resta(float *p, float *q, float *r, int n);
//**********************************************************************
/**
    Calculo del prooducto punto
    \param Inicio del vector 1
    \param Inicio del vector 2
    \param Dimension del vector
    \return Producto punto entre los dos vectores
*/
float ppunto(float *p, float *q, int n);
//**********************************************************************
/**
    Calculo del prooducto escalar
    \param Inicio del vector 1
    \param escalar
    \param Direccion del vector donde se guarda el resultado
    \param Dimension del vector
    \return Producto punto entre los dos vectores
*/
void prod_escalar(float *p, float a, float *q, int n);
//**********************************************************************
/**
    Norma de un vector, longitud del mismo
    \param Inicio del vector
    \param Dimension del vector
    \return Norma de un vector (longitud)
*/
float norma(float *p, int n);
//**********************************************************************
/**
    Funcion que devuelve el angle entre dos vectores
    \param Inicio del vector 1
    \param Inicio del vector 2
    \param Dimension de los vectores
    \return Angulo entre dos vectores
*/
float angulo(float *p, float *q, int n);

//**********************************************************************
/**
    Funcion que crea un vector dado el nombre de un archivo

	\param Nombre del archivo donde esta el vector
	\param Direccion de donde se guarda la dimension del vector
	\return Direccion del primer elemento del vector
*/
float * leer(char * nombre_archivo, int *n);
//**********************************************************************
/**
    Guardar el vector en un archivo

	\param Nombre del archivo donde se guardara el vector
	\param Dirrecion del vector
	\param Dimension del vector
*/
void escribir(char * nombre_archivo, float *p, int n);
//**********************************************************************


#endif // VECTOR_H_INCLUDED
