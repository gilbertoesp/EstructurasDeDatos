/*
 * Este archivo contiene la implementacion de la grafica definida
 * en el archivo Graph.h.
 *
 * Autor: Ivan Alejandro Moreno Soto.
 * Ultima modificacion: 20/Abril/2017.
 */

#include "Graph.h"

/************************/

/**
 * @brief Busca una pregunta no redundante que pueda realizarse al usuario.
 */
Node* Graph::searchQuestion() {
	bool keepSearching;
	Node *currentQuestion;

	currentQuestion = set.peek(); //Obtiene la primera pregunta del motor.
	keepSearching = true;

	while(currentQuestion && keepSearching) {
		//Primero revisa si la pregunta ha sido hecha.
		if (currentQuestion->isTrue == NO_TRUTH_VALUE) {
			//Si la pregunta no ha sido hecha, revisa si es redundante.
			if (!currentQuestion->aft.checkRedundancy()) {
				keepSearching = false;
				break; //Deja de buscar.
			}
		}

		currentQuestion = currentQuestion->next;

		//Si es cualquier otra cosa aparte de pregunta, para la busqueda.
		if (currentQuestion != NULL && currentQuestion->label != QUESTION) {
			keepSearching = false;
			currentQuestion = NULL; //Esto indicara que no hay pregunta que pueda hacerse.
		}
	}

	return currentQuestion;
}

/************************/

/**
 * @brief Dado un nodo interior y una respuesta, cambia la informacion
 * de un nodo de la grafica.
 * @param consequence Nodo interior que va a cambiar al nodo de la grafica que referencia.
 * @param answer Valor de verdad que modificara el nodo de la grafica.
 * @return Direccion del nodo de la grafica que fue modificado.
 */
Node* Graph::changeTruthValue(RelatedNode *consequence, int answer) {
	Node *modified;

	//Obtiene el nodo de la grafica que sera modificado.
	modified = consequence->direction;

	//Invierte la respuesta si es necesario.
	if (consequence->changeValue)
		answer = !answer;

	//Solo modifica el nodo de la grafica si no ha adquirido valor de
	//verdad definitivo.
	if (modified->isTrue == NO_TRUTH_VALUE) {
		if (answer == YES) {
			++modified->currentCorrect;

			//Revisa si ya se cumplio el nodo modificado.
			if (modified->currentCorrect == modified->necessary)
				modified->isTrue = TRUE_VALUE;
		} else {
			modified->isTrue = FALSE_VALUE;
		}
	}

	/*
	 * En caso de que una clausula intermedia o conclusion este compuesta por
	 * una o mas proposiciones unidas por una disyuncion, marca como verdaderas
	 * las otras partes, para evitar repeticiones.
	 */
	if (modified->connector > AND && modified->isTrue == TRUE_VALUE)
		cancelRedundantPropositions(modified->connector, modified->isTrue);

	return modified;
}

/************************/

/**
 * @brief Procesa los nodos interiores salientes de un nodo de la grafica.
 * @param node Nodo cuyos salientes seran procesados.
 * @return True si se deben seguir haciendo preguntas, false en otro caso.
 */
bool Graph::processConsequences(Node* currentQuestion) {
	Node *currentModified;
	RelatedNode *currentConsequence;
	int answer;
	bool keepAsking;

	answer = currentQuestion->isTrue;
	currentConsequence = currentQuestion->aft.peek();
	keepAsking = true;

	while(currentConsequence && keepAsking) {
		//Revisa que todavia no haya sido modificada definitivamente.
		if (currentConsequence->direction->isTrue == NO_TRUTH_VALUE) {
			currentModified = changeTruthValue(currentConsequence, answer);

			//Si es clausula intermedia y ha obtenido un valor de verdad
			//definitivo, la agrega a la pila de pendientes.
			if (currentModified->label == CLAUSULE && currentModified->isTrue != NO_TRUTH_VALUE) {
				pending.push(currentModified);
			//De lo contrario, es una conclusion y revisa si ya se cumplio.
			} else if (currentModified->isTrue == TRUE_VALUE) {
				guess = currentModified;
				keepAsking = false; //Para de preguntar.
			}
		}

		currentConsequence = currentConsequence->next;
	}

	return keepAsking;
}

/************************/

/**
 * @brief Cambia el valor de verdad de los nodos que contengan el conector
 * indicado. Es usado para las reglas que utilizan disyunciones logicas para
 * que al cambiar una parte, toda la regla cambie.
 * @param connectorLabel Etiqueta del conector logico que se buscara.
 * @param truthValue Valor de verdad que ha adquirido la proposicion.
 */
void Graph::cancelRedundantPropositions(int connectorLabel, int truthValue) {
	Node *currentNode;

	//Obtiene el primer nodo de la grafica.
	currentNode = set.peek();

	while (currentNode) {
		//Cambia el valor de verdad a los nodos que esten asociados
		//a la etiqueta del conector logico.
		if (currentNode->connector == connectorLabel)
			currentNode->isTrue = truthValue;

		currentNode = currentNode->next;
	}
}

/************************/

/**
 * @brief Agrega un nodo a la grafica con los datos indicados.
 * @param a "Nombre" del nuevo nodo.
 * @param label Etiqueta que indica si es pregunta(0), clausula intermedia(1) o conclusion(2).
 * @param count Cantidad de respuestas correctas necesarias para el nuevo nodo.
 * @param logic Etiqueta del conector logico del nuevo nodo.
 * @param text Texto que se mostrara en pantalla al usuario.
 */
void Graph::addNode(int a, int label, int count, int logic, string text) {
	set.add(a, label, count, logic, text);
}

/************************/

/**
 * @brief Agrega un arco (consecuencia) entre dos nodos.
 * @param a Nodo de donde sale la consecuencia.
 * @param b Nodo que sera modificado cuando a obtenga un valor de verdad definitivo.
 * @param change Indica si la respuesta de a se invierte antes de llegar a b.
 */
void Graph::addEdge(int a, int b, bool change) {
	RelatedNode *lastRelated1;
	Node *lastNode1, *lastNode2;

	//Localiza a.
	set.search(a);
	lastNode1 = set.getLastAdded();
	//Agrega el arco.
	(lastNode1->aft).add(b, change);

	//Localiza la consecuencia a b y el nodo b.
	lastRelated1 = (lastNode1->aft).getLastAdded();
	set.search(b);

	//Referencia el nodo de la grafica a la consecuencia.
	lastNode2 = set.getLastAdded();
	lastRelated1->direction = lastNode2;
}

/************************/

/**
 * @brief Maneja el proceso de preguntas y respuestas con el usuario
 * y de obtencion de conclusiones.
 */
void Graph::expertSystem() {
	int answer;
	bool keepAsking;
	Node *currentQuestion;

	keepAsking = true;
	guess = NULL; //Conclusion del sistema experto.

	while (keepAsking) {
		currentQuestion = searchQuestion();

		if (currentQuestion) {
			//Se hace la pregunta al usuario.
			std::cout << currentQuestion->text << std::endl;
			std::cin >> answer;

			//Se modifica el nodo de la pregunta actual acorde a la
			//respuesta del usuario.
			currentQuestion->isTrue = answer;

			//Se procesan los salientes de la pregunta actual.
			keepAsking = processConsequences(currentQuestion);

			//Al terminar de procesar los salientes, se procesan las clausulas
			//intermedias que esten en la pila de pendientes.
			currentQuestion = pending.pop();

			//Hace lo mismo que cuando se hace una pregunta al usuario, excepto
			//que aqui no se pone texto en pantalla; las respuestas se toman de
			//la pila de pendientes.
			while (currentQuestion) {
				keepAsking = processConsequences(currentQuestion);

				currentQuestion = pending.pop();
			}
		} else { //Si no se encontro pregunta que hacer, termina el proceso.
			keepAsking = false;
		}
	}

	//Le avisa al usuario si se encontro una respuesta.
	if (guess != NULL) {
		std::cout << "Se ha encontrado una respuesta." << std::endl;
		std::cout << guess->text << std::endl;
	} else {
		std::cout << "No se ha encontrado una respuesta y se agotaron las preguntas." << std::endl;
	}
}
