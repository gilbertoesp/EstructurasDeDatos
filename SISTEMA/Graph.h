/*
 * Este archivo contiene la declaracion de la grafica usada para
 * implementar un sistema experto.
 *
 * Autor: Ivan Alejandro Moreno Soto.
 * Ultima modificacion: 20/Abril/2017.
 */

/***************************************************/

#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include "Node.h"

/***************************************************/

/**
 * Define una grafica representada a traves de una lista de adyacencias.
 * Cada nodo representa una pregunta, una clausula intermedia o una
 * conclusion que forma parte del motor de inferencia de un sistema
 * experto.
 */
class Graph {
private:
	NodeList set; //Nodos de la grafica.
	Stack pending; //Pila auxiliar para no dejar ninguna consecuencia sin atender.
	Node *guess; //Conclusion del sistema experto.
	/**
     * @brief Busca una pregunta no redundante que pueda realizarse al usuario.
     */
	Node* searchQuestion();
	/**
     * @brief Dado un nodo interior y una respuesta, cambia la informacion
	 * de un nodo de la grafica.
     */
	Node* changeTruthValue(RelatedNode*, int);
	/**
	 * @brief Procesa los nodos interiores salientes de un nodo de la grafica.
	 */
	bool processConsequences(Node*);
	/**
     * @brief Cambia el valor de verdad de los nodos que contengan el conector
	 * indicado. Es usado para las reglas que utilizan disyunciones logicas para
	 * que al cambiar una parte, toda la regla cambie.
     */
	void cancelRedundantPropositions(int, int);
public:
	/**
     * @brief Constructor por default.
     */
	Graph(): guess(NULL) {};
	/**
     * @brief Destructor por default.
     */
	~Graph() {guess = NULL;};
	/**
     * @brief Agrega un nodo a la grafica con los datos indicados.
     */
	void addNode(int, int, int, int, string);
	/**
     * @brief Agrega un arco (consecuencia) entre dos nodos.
     */
	void addEdge(int, int, bool);
	/**
     * @brief Maneja el proceso de preguntas y respuestas con el usuario
	 * y de obtencion de conclusiones.
     */
	void expertSystem();
	/**
     * @brief Describe la lista de nodos que forman la grafica.
     */
	void describe() {set.describe();};
};

#endif
