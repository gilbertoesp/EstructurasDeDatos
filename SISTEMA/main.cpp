/*
 * Este archivo contiene la implementacion de un sistema de reglas para
 * identificar animales. Las reglas estan basadas en el sistema Zookeeper.
 *
 * Autor: Ivan Alejandro Moreno Soto.
 * Ultima modificacion: 20/Abril/2017.
 */

/***************************************************/

#include "Graph.h"

/***************************************************/

/**
 * @brief Implementa la base de conocimiento y reglas del motor de
 * inferencia del sistema Zookeeper.
 * @param A Grafica de un sistema experto donde se implementara la
 * base de conocimiento y las reglas del motor de inferencia.
 */
void makeZookeeperKnowledgeBase(Graph *A) {
    //Primero se agregan las preguntas necesarias para identificar
    //los animales.
    A->addNode(1, QUESTION, 0, NO_CONNECTOR, "Tiene pelo?");
    A->addNode(2, QUESTION, 0, NO_CONNECTOR, "Da leche?");
    A->addNode(3, QUESTION, 0, NO_CONNECTOR, "Tiene plumas?");
    A->addNode(4, QUESTION, 0, NO_CONNECTOR, "Vuela?");
    A->addNode(5, QUESTION, 0, NO_CONNECTOR, "Pone huevos?");
    A->addNode(6, QUESTION, 0, NO_CONNECTOR, "Come carne?");
    A->addNode(7, QUESTION, 0, NO_CONNECTOR, "Tiene dientes agudos?");
    A->addNode(8, QUESTION, 0, NO_CONNECTOR, "Tiene garras?");
    A->addNode(9, QUESTION, 0, NO_CONNECTOR, "Tiene ojos que miran hacia adelante?");
    A->addNode(10, QUESTION, 0, NO_CONNECTOR, "Tiene pezunas?");
    A->addNode(11, QUESTION, 0, NO_CONNECTOR, "Rumia?");
    A->addNode(12, QUESTION, 0, NO_CONNECTOR, "Es de color leonado?");
    A->addNode(13, QUESTION, 0, NO_CONNECTOR, "Tiene manchas oscuras?");
    A->addNode(14, QUESTION, 0, NO_CONNECTOR, "Tiene franjas negras?");
    A->addNode(15, QUESTION, 0, NO_CONNECTOR, "Es de color blanco?");
    A->addNode(16, QUESTION, 0, NO_CONNECTOR, "Tiene patas largas?");
    A->addNode(17, QUESTION, 0, NO_CONNECTOR, "Tiene cuello largo?");
    A->addNode(18, QUESTION, 0, NO_CONNECTOR, "Es blanca y negra?");
    A->addNode(19, QUESTION, 0, NO_CONNECTOR, "Nada?");
    A->addNode(20, QUESTION, 0, NO_CONNECTOR, "Vuela muy bien?");

    /*
     * Ahora se agregan las clausulas intermedias.
     * En el caso de las clausulas intermedias, los nodos
     * que aparecen con textos identicos representan virtualmente
     * a la misma clausula; cada nodo forma parte de una disyuncion
     * logica, por lo que al dispararse cualquiera de los nodos
     * con texto identico se cancelan las otras partes de la disyuncion.
     * Para agrupar distintas partes de una disyuncion logica se
     * utiliza el mismo conector (cuarto parametro de addNode).
     * Para mayor informacion consultar: changeTruthValue(RelatedNode*, int)
     * en el archivo Graph.cpp; y el sistema Zookeeper de PREGUNTAR LA FUENTE.
     */
    A->addNode(21, CLAUSULE, 1, 2, "Es mamifero");
    A->addNode(22, CLAUSULE, 1, 2, "Es mamifero");
    A->addNode(23, CLAUSULE, 1, 3, "Es ave");
    A->addNode(24, CLAUSULE, 2, 3, "Es ave");
    A->addNode(25, CLAUSULE, 2, 4, "Es carnivoro");
    A->addNode(26, CLAUSULE, 4, 4, "Es carnivoro");
    A->addNode(27, CLAUSULE, 2, 5, "Es ungulado");
    A->addNode(28, CLAUSULE, 2, 5, "Es ungulado");

    //Se agregan las conclusiones del sistema Zookeeper.
    A->addNode(29, CONCLUSION, 3, AND, "Es una onza");
    A->addNode(30, CONCLUSION, 3, AND, "Es un tigre");
    A->addNode(31, CONCLUSION, 3, AND, "Es una cebra");
    A->addNode(32, CONCLUSION, 5, AND, "Es una avestruz");
    A->addNode(33, CONCLUSION, 4, AND, "Es un pinguino");
    A->addNode(34, CONCLUSION, 2, AND, "Es un albatros");

    //Ahora si, se agregan todas las reglas definidas
    //en el sistema Zookeeper.
    A->addEdge(1, 21, false); //Z1
    A->addEdge(2, 22, false); //Z2
    A->addEdge(3, 23, false); //Z3
    //Los siguientes dos arcos representan una sola regla (Z4).
    A->addEdge(4, 24, false);
    A->addEdge(5, 24, false);

    //Los siguientes tres arcos representan una sola regla (Z5).
    A->addEdge(21, 25, false);
    A->addEdge(22, 25, false);
    A->addEdge(6, 25, false);

    //Los siguientes cinco arcos representan una sola regla (Z6).
    A->addEdge(21, 26, false);
    A->addEdge(22, 26, false);
    A->addEdge(7, 26, false);
    A->addEdge(8, 26, false);
    A->addEdge(9, 26, false);

    //Los siguientes tres arcos representan una sola regla (Z7).
    A->addEdge(21, 27, false);
    A->addEdge(22, 27, false);
    A->addEdge(10, 27, false);

    //Los siguientes tres arcos representan una sola regla (Z8).
    A->addEdge(21, 28, false);
    A->addEdge(22, 28, false);
    A->addEdge(11, 28, false);

    //Los siguientes cuatro arcos representan una sola regla (Z9).
    A->addEdge(25, 29, false);
    A->addEdge(26, 29, false);
    A->addEdge(12, 29, false);
    A->addEdge(13, 29, false);

    //Los siguientes cuatro arcos representan una sola regla (Z10).
    A->addEdge(25, 30, false);
    A->addEdge(26, 30, false);
    A->addEdge(12, 30, false);
    A->addEdge(14, 30, false);

    //Los siguientes cuatro arcos representan una sola regla (Z12).
    A->addEdge(27, 31, false);
    A->addEdge(28, 31, false);
    A->addEdge(15, 31, false);
    A->addEdge(14, 31, false);

    //Los siguientes seis arcos representan una sola regla (Z13).
    A->addEdge(23, 32, false); //Z13
    A->addEdge(24, 32, false);
    A->addEdge(4, 32, true);
    A->addEdge(16, 32, false);
    A->addEdge(17, 32, false);
    A->addEdge(18, 32, false);

    //Los siguientes cinco arcos representan una sola regla (Z14).
    A->addEdge(23, 33, false);
    A->addEdge(24, 33, false);
    A->addEdge(4, 33, true);
    A->addEdge(19, 33, false);
    A->addEdge(18, 33, false);

    //Los siguientes tres arcos representan una sola regla (Z15).
    A->addEdge(23, 34, false);
    A->addEdge(24, 34, false);
    A->addEdge(20, 34, false);
} //Fin makeZookeeperKnowledgeBase(Graph*).

/***************************************************/

/**
 * @brief Implementa las reglas de Zookeeper y empieza las
 * preguntas al usuario.
 */
int main() {
    Graph A;

    //Prepara todo para este sistema experto.
    makeZookeeperKnowledgeBase(&A);

    //Inicia las preguntas al usuario.
    A.expertSystem();

    return 0;
} //Fin main().

/***************************************************/
