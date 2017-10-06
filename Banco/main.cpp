/**
    BANCO

    \author Gilberto Espinoza
*/
#include <cstdlib>
#include <iostream>
//Semilla de aleatorio
#include <ctime>

#include "Cola.h"
// Definimos cuantos cajeras queremos
#define CAJERAS 4
//Suponemos habia clientes antes de empezar a trabajar, cuantos?
#define CLIENTES_ANTES_APERTURA 10
//Cada minuto puede llegar un cliente, que tan probable es esto?
#define PROBABILIDAD_CLIENTE 50

#define APERTURA 1
#define CIERRE 60
int main()
{
    //Generamos la semilla de radom
    srand(time(NULL));

    Cola cola;
    //Hacemos un arreglo de int para simular el tiempo que tienen las
    //cajeras atendiendo a cada cliente
    int cajeras[CAJERAS];
    //Que llegan al banco
    int total_clientes = CLIENTES_ANTES_APERTURA, random;

    std::cout << "----------  BANCO  ----------" << std::endl;

    for(int i = 0 ; i < CAJERAS ; i++){
        cajeras[i] = 0;
    }
    //Simulamos que en el banco ya habia clientes esperando antes de la apertura
    for(int i = 0 ; i < CLIENTES_ANTES_APERTURA ; i++){
        cola.agregar(APERTURA);
    }
    for(int hora = APERTURA ; hora < CIERRE ; hora++){
        cola.agregar(APERTURA);
        random = aleatorio(1,100);
        if(random < PROBABILIDAD_CLIENTE){
            cola.agregar(hora);
            total_clientes++;
        }
        for(int i = 0 ; i < CAJERAS ; i++){
            if(cajeras[i] == 0 && cola.CuantosSon() != 0){
                cajeras[i] = cola.sacar(hora);
            }else{
                if(cajeras[i] > 0){
                    cajeras[i]--;
                }
            }
        }
    }
    std::cout << "Total de clientes: " << total_clientes << std::endl;
    std::cout << "Cola mas larga: " << cola.CuantosMax() << std::endl;
    std::cout << "Tiempo de espera maximo: " << cola.EsperaMax() << std::endl;


    system("pause");
    return 0;
}
