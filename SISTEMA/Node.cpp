/*
 * Este archivo contiene la implementacion de cada clase definida
 * en el archivo Node.h.
 *
 * Autor: Ivan Alejandro Moreno Soto.
 * Ultima modificacion: 20/Abril/2017.
 */

#include "Node.h"

/***************************************************/

/**
 * @brief Borra de manera secuencial cada nodo interior de esta lista.
 */
EdgeList::~EdgeList() {
    RelatedNode *currentNode;

    while (beg != NULL) {
        currentNode = beg;
        beg = beg->next;
        delete currentNode;
    }

    size = 0;
    plcFound = EMPTY;
    last = NULL;
    previous = NULL;
}

/************************/

/**
 * @brief Busca un nodo interior con el "nombre" indicado.
 * @param a "Nombre" del nodo que sera buscado.
 * @return True si a es encontrado, false en cualquier otro caso.
 */
bool EdgeList::search(int a) {
    RelatedNode *p;

    p = beg;

    //En caso de que la lista este vacia.
    if (p == NULL) {
        plcFound = EMPTY;
        previous = NULL;
        last = NULL;
        return false;
    }

    //Busca en cada nodo de la lista.
    while (p) {
        if (p->value == a) {
            if (beg == p) {
                plcFound = BEG;
            } else {
                if (p->next == NULL) {
                    plcFound = END;
                } else {
                    plcFound = MID;
                }
            }
            last = p;
            return true;
        } else {
            //Se recorre la lista una posicion a la derecha.
            if (p->value < a) {
                previous = p;
                p = p->next;
            } else { //Cuando p->value es mayor que a.
                if (beg == p) {
                    plcFound = BEG;
                } else {
                    if (p->next == NULL) {
                        plcFound = END;
                    } else {
                        plcFound = MID;
                    }
                }
                return false;
            }
        }
    }

    plcFound = END;
    return false;
}

/************************/

/**
 * @brief Agrega un nuevo nodo interior con el "nombre" indicado y con un
 * indicador para saber si se invierte la respuesta.
 * @param a "Nombre" del nodo que se quiere agregar.
 * @param change Indica si la respuesta se invierte al querer cambiar el
 * nodo al que hace referencia.
 * @return True si se agrega el nodo, false en caso de que no se agregue.
 */
bool EdgeList::add(int a, bool change) {
    bool wasAdded;
    RelatedNode *newNode;

    if (search(a)) {
        wasAdded = false; //Si lo encuentra no lo agrega.
    } else {
        //Crea el nuevo nodo y lo inicializa con los valores predeterminados.
        newNode = new RelatedNode;
        newNode->value = a;
        newNode->direction = NULL;
        newNode->changeValue = change;

        last = newNode;

        if (plcFound == EMPTY) { //Al principio de la lista vacia.
            newNode->next = NULL;
            beg = newNode;
        } else {
            if (plcFound == BEG) { //Al principio de la lista pero no esta vacia.
                newNode->next = beg;
                beg = newNode;
            } else {
                if (plcFound == MID) { //En medio.
                    newNode->next = previous->next;
                    previous->next = newNode;
                } else { //Al final
                    newNode->next = NULL;
                    previous->next = newNode;
                }
            }
        }

        ++size;
        wasAdded = true;
    }

    return wasAdded;
}

/************************/

/**
 * @brief Describe secuencialmente los nodos interiores de esta lista.
 */
void EdgeList::describe() {
    RelatedNode *currentNode;

    currentNode = beg;

    while (currentNode != NULL) {
        std::cout << "Value: " << currentNode->value << ", Change: " << currentNode->changeValue << "; ";
        currentNode = currentNode->next;
    }

    std::cout << std::endl;
}

/************************/

/**
 * @brief Revisa si los nodos interiores de esta lista referencian a
 * un nodo del sistema experto que todavia no tiene valor definitivo
 * de verdad.
 * @return True si la pregunta es redundante, false si no lo es.
 */
bool EdgeList::checkRedundancy() {
    bool isRedundant, keepSearching;
    RelatedNode *currentNode;
    Node *currentQuestion;
    Stack consequences;

    currentNode = beg;
    isRedundant = true;
    keepSearching = true;

    /*
     * Dentro del ciclo se determina si la pregunta NO es redundante.
     * Si no hay exito, el valor de isRedundant no sera cambiado y se
     * devolvera true.
     */
    while(currentNode && keepSearching) {
        //Simplemente revisa si el nodo interior lleva a un nodo que
        //todavia no obtiene un valor de verdad definitivo.
        if (currentNode->direction->isTrue == NO_TRUTH_VALUE) {
            isRedundant = false;
            /**
             * Ahora revisa si es conclusion o clausula intermedia a donde
             * lleva el arco actual. Si es conclusion corta el proceso debido
             * a que la pregunta definitivamente no es redundante. Si por otra
             * parte es una clausula intermedia, la agrega a un stack de
             * pendientes para ver si estas a su vez son redundantes.
             */
            if (currentNode->direction->label == CONCLUSION)
                keepSearching = false;
            else
                consequences.push(currentNode->direction);
        }
        currentNode = currentNode->next;
    }

    /*
     * Ahora se checan las clausulas intermedias a donde se llegan con esta
     * pregunta.
     * Esto se hace para saber si la pregunta tendra impacto en alguno de los
     * nodos a donde se propaga su valor de verdad.
     */
    currentQuestion = consequences.pop();
    while (currentQuestion && keepSearching) {
        currentNode = currentQuestion->aft.peek();
        isRedundant = true;

        /*
         * Dentro del ciclo se determina si la pregunta NO es redundante.
         * Si no hay exito, el valor de isRedundant no sera cambiado y se
         * devolvera true.
         */
        while(currentNode && keepSearching) {

            //Simplemente revisa si el nodo interior lleva a un nodo que
            //todavia no obtiene un valor de verdad definitivo.
            if (currentNode->direction->isTrue == NO_TRUTH_VALUE) {
                isRedundant = false;
                /**
                 * Ahora revisa si es conclusion o clausula intermedia a donde
                 * lleva el arco actual. Si es conclusion corta el proceso debido
                 * a que la pregunta definitivamente no es redundante. Si por otra
                 * parte es una clausula intermedia, la agrega a un stack de
                 * pendientes para ver si estas a su vez son redundantes.
                 */
                if (currentNode->direction->label == CONCLUSION)
                    keepSearching = false;
                else
                    consequences.push(currentNode->direction);
            }
            currentNode = currentNode->next;
        }
        currentQuestion = consequences.pop();
    }

    return isRedundant;
}

/***************************************************/

/**
 * @brief Borra secuencialmente cada nodo de esta lista.
 */
NodeList::~NodeList() {
    Node *currentNode;

    while (beg != NULL) {
        currentNode = beg;
        beg = beg->next;
        delete currentNode;
    }

    size = 0;
    plcFound = EMPTY;
    last = NULL;
    previous = NULL;
}

/************************/

/**
 * @brief Busca un nodo interior con el "nombre" indicado.
 * @param a "Nombre" del nodo que se va a buscar.
 * @return True si a es encontrado, false en cualquier otro caso.
 */
bool NodeList::search(int a) {
    Node *p;

    p = beg;

    //En caso de que no haya algo en la lista.
    if (p == NULL) {
        plcFound = EMPTY;
        previous = NULL;
        last = NULL;
        return false;
    }

    //Busca en cada nodo de la lista.
    while (p) {
        if (p->value == a) {
            if (beg == p) {
                plcFound = BEG;
            } else {
                if (p->next == NULL) {
                    plcFound = END;
                } else {
                    plcFound = MID;
                }
            }
            last = p;
            return true;
        } else {
            //Se recorre la lista una posicion.
            if (p->value < a) {
                previous = p;
                p = p->next;
            } else { //Cuando p->value es mayor que a
                if (beg == p) {
                    plcFound = BEG;
                } else {
                    if (p->next == NULL) {
                        plcFound = END;
                    } else {
                        plcFound = MID;
                    }
                }
                return false;
            }
        }
    }

    plcFound = END;
    return false;
}

/************************/

/**
 * @brief Agrega un nuevo nodo al sistema experto con los datos dados.
 * @param a "Nombre" del nuevo nodo.
 * @param label Etiqueta que indica si es pregunta(0), clausula intermedia(1) o conclusion(2).
 * @param count Cantidad de respuestas correctas necesarias para el nuevo nodo.
 * @param logic Etiqueta del conector logico del nuevo nodo.
 * @param text Texto que se mostrara en pantalla al usuario.
 * @return True si se agrega el nodo, false en caso de que no se agregue.
 */
bool NodeList::add(int a, int label, int count, int logic, string text) {
    bool wasAdded;
    Node *newNode;

    if (search(a)) {
        wasAdded = false; //Si lo encuentra no lo agrega.
    } else {
        //Crea el nuevo nodo y lo inicializa con los valores dados.
        newNode = new Node;
        newNode->value = a;
        newNode->label = label;
        newNode->currentCorrect = 0;
        newNode->necessary = count;
        newNode->connector = logic;
        newNode->isTrue = NO_TRUTH_VALUE;
        newNode->text = text;

        last = newNode;

        if (plcFound == EMPTY) { //Al principio de la lista vacia.
            newNode->next = NULL;
            beg = newNode;
        } else {
            if (plcFound == BEG) { //Al principio de la lista pero no esta vacia.
                newNode->next = beg;
                beg = newNode;
            } else {
                if (plcFound == MID) { //En medio.
                    newNode->next = previous->next;
                    previous->next = newNode;
                } else { //Al final.
                    newNode->next = NULL;
                    previous->next = newNode;
                }
            }
        }

        ++size;
        wasAdded = true;
    }

    return wasAdded;
}

/************************/

/**
 * @brief Describe secuencialmente los nodos de esta lista.
 */
void NodeList::describe() {
    Node *currentNode;

    currentNode = beg;

    while (currentNode != NULL) {
        std::cout << "Nodo: " << currentNode->value << std::endl;

        std::cout << "Etiqueta: " << currentNode->label << ", ";
        std::cout << "Respuestas correctas actuales: " << currentNode->currentCorrect << std::endl;
        std::cout << "Respuestas necesarias: " << currentNode->necessary << std::endl;
        std::cout << "Conector logico: " << currentNode->connector << std::endl;
        std::cout << "Ya es verdad? " << currentNode->isTrue << std::endl;
        std::cout << "Texto: " << currentNode->text << std::endl;

        std::cout << "Consecuencias:" << std::endl;
        currentNode->aft.describe();
        std::cout << std::endl;

        currentNode = currentNode->next;
    }

    std::cout << std::endl;
}

/***************************************************/

/*
 * @brief Borra cada nodo de la pila de manera secuencial.
 */
Stack::~Stack() {
    MiddleNode *currentNode;

    while (beg != NULL) {
        currentNode = beg;
        beg = beg->next;
        delete currentNode;
    }

    size = 0;
}

/************************/

/**
 * @brief Agrega un nuevo nodo intermedio a la cima de la pila.
 * @param a Direccion a un nodo que sera agregado encima en la pila.
 */
void Stack::push(Node *a) {
    MiddleNode *newNode;

    newNode = new MiddleNode;

    newNode->direction = a;

    //Mueve el principio hacia arriba una unidad.
    newNode->next = beg;
    beg = newNode;
    ++size;
}

/************************/

/**
 * @brief Borra el primer nodo de la pila y regresa la direccion que contenia.
 * @return Direccion a un nodo que contenia el primer elemento de la pila.
 */
Node* Stack::pop() {
    MiddleNode *topNode;
    Node *value;

    topNode = beg;

    if (beg == NULL)
        return NULL;

    value = topNode->direction;

    beg = topNode->next; //Recorre la pila una posicion hacia abajo.
    delete topNode;

    --size;

    return value;
}

/************************/
