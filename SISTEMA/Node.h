/*
 * Este archivo contiene las declaraciones de las estructuras y clases auxiliares
 * que la grafica del sistema experto usa.
 *
 * Autor: Ivan Alejandro Moreno Soto.
 * Ultima modificacion: 20/Abril/2017.
 */

/***************************************************/

#ifndef NODE_INCLUDED_H
#define NODE_INCLUDED_H

#include <iostream>
#include <cstdlib>
#include <string>

#define QUESTION 0
#define CLAUSULE 1
#define CONCLUSION 2
#define NO_CONNECTOR 0 //Se usa cuando una pregunta es agregada al motor de inferencia.
#define AND 1
//Valores para los nodos de la grafica.
#define NO_TRUTH_VALUE -1
#define FALSE_VALUE 0
#define TRUE_VALUE 1
//Valores para las respuestas del usuario.
#define YES 1
#define NO 0

/***************************************************/

#define VACIO 99999999
enum where{EMPTY, BEG, MID, END};

/***************************************************/

struct RelatedNode;
struct Node;
struct MiddleNode;

using std::string;

/***************************************************/

/**
 * Esta estructura representa un nodo interior que permite cambiar
 * el valor de verdad de otro nodo (clausila intermedia o conclusion).
 */
struct RelatedNode {
    int value; //"Nombre" del nodo al que hace referencia.
    bool changeValue; //Indica si se cambia el valor.
    Node *direction; //Nodo al que ira a cambiar su valor de verdad.
    RelatedNode *next;
};

/***************************************************/

/**
 * Esta lista representa las consecuencias que tiene un nodo que forma parte
 * del sistema experto. Aqui se guardan los arcos que indican como son afectados
 * los nodos referenciados cuando alguna pregunta o clausula intermedia obtiene
 * un valor definitivo de verdad.
 */
class EdgeList {
private:
	RelatedNode *beg, *last, *previous;
    where plcFound;
    int size;
public:

	EdgeList(): beg(NULL), last(NULL), previous(NULL), plcFound(EMPTY), size(0) {};
	~EdgeList();
	bool search(int);
    bool add(int, bool);
    RelatedNode* getLastAdded() {return last;};
    RelatedNode* peek() {return beg;};
    void describe();
    bool checkRedundancy();
};

/***************************************************/

/**
 * Este nodo representa una pregunta, una clausula intermedia o una
 * conclusion del sistema experto que se modele.
 */
struct Node {
    int value, label, currentCorrect, necessary, connector, isTrue;
    string text; //Texto que se despliega al usuario en pantalla.
    EdgeList aft;
    Node *next;
};

struct MiddleNode {
    Node *direction;
    MiddleNode *next;
};

/***************************************************/

/**
 * Esta lista contiene las preguntas, clausulas intermedias y conclusiones
 * que componen al sistema experto que se implemente.
 */
class NodeList {
private:
	Node *beg, *last, *previous;
    where plcFound;
    int size;
public:
    /**
     * @brief Inicializa cada atributo en su valor predeterminado.
     */
	NodeList(): beg(NULL), last(NULL), previous(NULL), plcFound(EMPTY), size(0) {};
    /**
     * @brief Borra secuencialmente cada nodo de esta lista.
     */
	~NodeList();
    /**
     * @brief Busca un nodo interior con el "nombre" indicado.
     */
    bool search(int);
    /**
     * @brief Agrega un nuevo nodo al sistema experto con los datos dados.
     */
    bool add(int, int, int, int, string);
    /**
     * @brief Regresa la direccion del ultimo nodo que fue agregado a esta lista.
     */
    Node* getLastAdded() {return last;};
    /**
     * @brief Describe secuencialmente los nodos de esta lista.
     */
    void describe();
    /**
     * @brief Regresa la direccion del primer nodo de esta lista.
     */
    Node* peek() {return beg;};
};

/***************************************************/

/**
 * Una pila. Implementa las operaciones basicas de esta estructura de datos.
 * Es usada para guardar las clausulas intermedias que son disparadas como
 * consecuencia de otra clausula intermedia o una pregunta y que necesitan
 * ser procesados sus arcos.
 */
class Stack {
private:
    MiddleNode *beg;
    int size;
public:
    /*
     * @brief Inicializa los atributos de la clase en sus valores predeterminados.
     */
    Stack(): beg(NULL), size(0) {};
    /*
     * @brief Borra cada nodo de la pila de manera secuencial.
     */
    ~Stack();
    /**
     * @brief Agrega un nuevo nodo intermedio a la cima de la pila.
     */
    void push(Node*);
    /**
     * @brief Borra el primer nodo de la pila y regresa la direccion que contenia.
     */
    Node* pop();
};

#endif
