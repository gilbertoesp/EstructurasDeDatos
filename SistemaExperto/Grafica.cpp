/**
	Grafica.cpp

	Simulacion de una grafica.
	Para aparentar la estructura de una grafica se hace referencia a las conexiones entre los nodos, con
	listas de adyacencia, cada Nodo de la grafica, contiene sus propias listas, entrada y salida.

	\author Gilberto Espinoza
*/
#include <iostream>
#include <cstdlib>

#include "Grafica.h"
//*************************************************************************************************
Grafica::Grafica()
{
    grafica.constructor();
}
//*************************************************************************************************
Grafica::~Grafica()
{
    grafica.destructor();
}
//*************************************************************************************************
void Grafica::agregar_arco(int a, int b, bool inversor)
{
    CajaNodo *nodo_a, *nodo_b;
    CajaArco *arco;

    grafica.buscar(a);
    nodo_a = grafica.LugarAgregado();
    nodo_a->salientes.agregar(b, inversor);
    //El arco recien creado
    arco = nodo_a->salientes.LugarAgregado();

    grafica.buscar(b);
    nodo_b = grafica.LugarAgregado();
    // Al arco le decimos donde se encuentra dentro de grafica
    arco->direccion_nodo = nodo_b;

    nodo_b->entrantes.agregar(a, inversor);
    arco = nodo_b->entrantes.LugarAgregado();
    // Igual al arco entrante de b le decimos que su posicion en la grafica es el nodo_a
    arco->direccion_nodo = nodo_a;
}
//*************************************************************************************************
void Grafica::agregar_nodo(int id, Bandera bandera, int totales, Conectivo conectivo, string texto)
{
    grafica.agregar(id,bandera,totales,conectivo,texto);
}
//*************************************************************************************************
void Grafica::cargar()
{
    //Primero se agregan las preguntas necesarias para identificar
    //los animales.
    agregar_nodo(1, PREGUNTA, 0, SIN_CONECTIVO, "Tiene pelo?");
    agregar_nodo(2, PREGUNTA, 0, SIN_CONECTIVO, "Da leche?");
    agregar_nodo(3, PREGUNTA, 0, SIN_CONECTIVO, "Tiene plumas?");
    agregar_nodo(4, PREGUNTA, 0, SIN_CONECTIVO, "Vuela?");
    agregar_nodo(5, PREGUNTA, 0, SIN_CONECTIVO, "Pone huevos?");
    agregar_nodo(6, PREGUNTA, 0, SIN_CONECTIVO, "Come carne?");
    agregar_nodo(7, PREGUNTA, 0, SIN_CONECTIVO, "Tiene dientes agudos?");
    agregar_nodo(8, PREGUNTA, 0, SIN_CONECTIVO, "Tiene garras?");
    agregar_nodo(9, PREGUNTA, 0, SIN_CONECTIVO, "Tiene ojos que miran hacia adelante?");
    agregar_nodo(10, PREGUNTA, 0, SIN_CONECTIVO, "Tiene pezunas?");
    agregar_nodo(11, PREGUNTA, 0, SIN_CONECTIVO, "Rumia?");
    agregar_nodo(12, PREGUNTA, 0, SIN_CONECTIVO, "Es de color leonado?");
    agregar_nodo(13, PREGUNTA, 0, SIN_CONECTIVO, "Tiene manchas oscuras?");
    agregar_nodo(14, PREGUNTA, 0, SIN_CONECTIVO, "Tiene franjas negras?");
    agregar_nodo(15, PREGUNTA, 0, SIN_CONECTIVO, "Es de color blanco?");
    agregar_nodo(16, PREGUNTA, 0, SIN_CONECTIVO, "Tiene patas largas?");
    agregar_nodo(17, PREGUNTA, 0, SIN_CONECTIVO, "Tiene cuello largo?");
    agregar_nodo(18, PREGUNTA, 0, SIN_CONECTIVO, "Es blanca y negra?");
    agregar_nodo(19, PREGUNTA, 0, SIN_CONECTIVO, "Nada?");
    agregar_nodo(20, PREGUNTA, 0, SIN_CONECTIVO, "Vuela muy bien?");

    /*
    * Ahora se agregan las clausulas intermedias.
    * En el caso de las clausulas intermedias, los nodos
    * que aparecen con textos identicos representan virtualmente
    * a la misma clausula; cada nodo forma parte de una disyuncion
    * logica, por lo que al dispararse cualquiera de los nodos
    * con texto identico se cancelan las otras partes de la disyuncion.
    * Para agrupar distintas partes de una disyuncion logica se
    * utiliza el mismo conector (cuarto parametro de agregar_nodo).
    * Para mayor informacion consultar: changeTruthValue(RelatedNode*, int)
    * en el archivo Graph.cpp; y el sistema Zookeeper de PREGUNTAR LA FUENTE.
    */
    agregar_nodo(21, INTERMEDIO, 1, MAMIFERO/*2*/, "Es mamifero");
    agregar_nodo(22, INTERMEDIO, 1, MAMIFERO/*2*/, "Es mamifero");
    agregar_nodo(23, INTERMEDIO, 1, AVE/*3*/, "Es ave");
    agregar_nodo(24, INTERMEDIO, 2, AVE/*3*/, "Es ave");
    agregar_nodo(25, INTERMEDIO, 2, CARNIVORO/*4*/, "Es carnivoro");
    agregar_nodo(26, INTERMEDIO, 4, CARNIVORO/*4*/, "Es carnivoro");
    agregar_nodo(27, INTERMEDIO, 2, UNGULADO/*5*/, "Es ungulado");
    agregar_nodo(28, INTERMEDIO, 2, UNGULADO/*5*/, "Es ungulado");

    //Se agregan las conclusiones del sistema Zookeeper.
    agregar_nodo(29, CONCLUSION, 3, AND, "Es una onza");
    agregar_nodo(30, CONCLUSION, 3, AND, "Es un tigre");
    agregar_nodo(31, CONCLUSION, 3, AND, "Es una cebra");
    agregar_nodo(32, CONCLUSION, 5, AND, "Es una avestruz");
    agregar_nodo(33, CONCLUSION, 4, AND, "Es un pinguino");
    agregar_nodo(34, CONCLUSION, 2, AND, "Es un albatros");

    //Ahora si, se agregan todas las reglas definidas
    //en el sistema Zookeeper.
    agregar_arco(1, 21, false); //Z1
    agregar_arco(2, 22, false); //Z2
    agregar_arco(3, 23, false); //Z3
    //Los siguientes dos arcos representan una sola regla (Z4).
    agregar_arco(4, 24, false);
    agregar_arco(5, 24, false);

    //Los siguientes tres arcos representan una sola regla (Z5).
    agregar_arco(21, 25, false);
    agregar_arco(22, 25, false);
    agregar_arco(6, 25, false);

    //Los siguientes cinco arcos representan una sola regla (Z6).
    agregar_arco(21, 26, false);
    agregar_arco(22, 26, false);
    agregar_arco(7, 26, false);
    agregar_arco(8, 26, false);
    agregar_arco(9, 26, false);

    //Los siguientes tres arcos representan una sola regla (Z7).
    agregar_arco(21, 27, false);
    agregar_arco(22, 27, false);
    agregar_arco(10, 27, false);

    //Los siguientes tres arcos representan una sola regla (Z8).
    agregar_arco(21, 28, false);
    agregar_arco(22, 28, false);
    agregar_arco(11, 28, false);

    //Los siguientes cuatro arcos representan una sola regla (Z9).
    agregar_arco(25, 29, false);
    agregar_arco(26, 29, false);
    agregar_arco(12, 29, false);
    agregar_arco(13, 29, false);

    //Los siguientes cuatro arcos representan una sola regla (Z10).
    agregar_arco(25, 30, false);
    agregar_arco(26, 30, false);
    agregar_arco(12, 30, false);
    agregar_arco(14, 30, false);

    //Los siguientes cuatro arcos representan una sola regla (Z12).
    agregar_arco(27, 31, false);
    agregar_arco(28, 31, false);
    agregar_arco(15, 31, false);
    agregar_arco(14, 31, false);

    //Los siguientes seis arcos representan una sola regla (Z13).
    agregar_arco(23, 32, false); //Z13
    agregar_arco(24, 32, false);
    agregar_arco(4, 32, true);
    agregar_arco(16, 32, false);
    agregar_arco(17, 32, false);
    agregar_arco(18, 32, false);

    //Los siguientes cinco arcos representan una sola regla (Z14).
    agregar_arco(23, 33, false);
    agregar_arco(24, 33, false);
    agregar_arco(4, 33, true);
    agregar_arco(19, 33, false);
    agregar_arco(18, 33, false);

    //Los siguientes tres arcos representan una sola regla (Z15).
    agregar_arco(23, 34, false);
    agregar_arco(24, 34, false);
    agregar_arco(20, 34, false);


}
//*************************************************************************************************
void Grafica::ejecutar()
{
    int respuesta;
	bool continua;
	CajaNodo *pregunta;

	continua = true;
	conclusion = NULL; //Conclusion del sistema experto.

	std::cout << "[0] -> NO" << std::endl;
	std::cout << "[1] -> SI\n" << std::endl;

	while (continua) {
		pregunta = buscarPregunta();

		if (pregunta) {
			//Se hace la pregunta al usuario.
			std::cout << pregunta->texto << std::endl;
			std::cout << "Respuesta: ";
			std::cin >> respuesta;

			//Se modifica el nodo de la pregunta actual acorde a la
			//respuesta del usuario.
			pregunta->valorVerdad = respuesta;

			//Se procesan los salientes de la pregunta actual.
			continua = procesarConsecuencias(pregunta);

			//Al terminar de procesar los salientes, se procesan las clausulas
			//intermedias que esten en la pila de pendientes.
			pregunta = pendientes.pop();

			//Hace lo mismo que cuando se hace una pregunta al usuario, excepto
			//que aqui no se pone texto en pantalla; las respuestas se toman de
			//la pila de pendientes.
			while (pregunta) {
				continua = procesarConsecuencias(pregunta);

				pregunta = pendientes.pop();
			}
		} else { //Si no se encontro pregunta que hacer, termina el proceso.
			continua = false;
		}
	}

	//Le avisa al usuario si se encontro una respuesta.
	if (conclusion) {
		std::cout << "Se ha encontrado una respuesta." << std::endl;
		std::cout << conclusion->texto << std::endl;
	} else {
		std::cout << "No se ha encontrado una respuesta y se agotaron las preguntas." << std::endl;
	}
}
//*************************************************************************************************
CajaNodo * Grafica::buscarPregunta()
{
    bool continua;
    CajaNodo *pregunta;

    pregunta = grafica.Principio(); //Obtiene la primera pregunta del motor.
    continua = true;

    while(pregunta && continua) {
        //Primero revisa si la pregunta ha sido hecha.
        if (pregunta->valorVerdad == SIN_RESPUESTA) {
            //Si la pregunta no ha sido hecha, revisa si es redundante.
            if (!pregunta->salientes.redundancia()) {
                continua = false;
                break; //Deja de buscar.
            }
        }

        pregunta = pregunta->siguiente;

        //Si es cualquier otra cosa aparte de pregunta, para la busqueda.
        if (pregunta != NULL && pregunta->bandera != PREGUNTA) {
            continua = false;
            pregunta = NULL; //Esto indicara que no hay pregunta que pueda hacerse.
        }
    }

    return pregunta;
}

//*************************************************************************************************
bool Grafica::procesarConsecuencias(CajaNodo* pregunta_actual)
{
    CajaNodo *nodo_actual;
	CajaArco *consecuencia_actual;
	int respuesta;
	bool continua;

	respuesta = pregunta_actual->valorVerdad;
	consecuencia_actual = pregunta_actual->salientes.Principio();
	continua = true;

	while(consecuencia_actual && continua) {
		//Revisa que todavia no haya sido modificada definitivamente.
		if (consecuencia_actual->direccion_nodo->valorVerdad == SIN_RESPUESTA) {
			nodo_actual = cambiarValorVerdad(consecuencia_actual, respuesta);

			//Si es clausula intermedia y ha obtenido un valor de verdad
			//definitivo, la agrega a la pila de pendientes.
			if (nodo_actual->bandera == INTERMEDIO && nodo_actual->valorVerdad != SIN_RESPUESTA) {
				pendientes.push(nodo_actual);
			//De lo contrario, es una conclusion y revisa si ya se cumplio.
			} else if (nodo_actual->valorVerdad == VERDAD) {
				conclusion = nodo_actual;
				continua = false; //Para de preguntar.
			}
		}

		consecuencia_actual = consecuencia_actual->siguiente;
	}

	return continua;
}
//*************************************************************************************************
CajaNodo * Grafica::cambiarValorVerdad(CajaArco *consecuencia, int respuesta)
{
    CajaNodo *modificado;

	//Obtiene el nodo de la grafica que sera modificado.
	modificado = consecuencia->direccion_nodo;

	//Invierte la respuesta si es necesario.
	if (consecuencia->inversor)
		respuesta = !respuesta;

	//Solo modifica el nodo de la grafica si no ha adquirido valor de
	//verdad definitivo.
	if (modificado->valorVerdad == SIN_RESPUESTA) {
		if (respuesta == VERDAD) {
			++modificado->cuantos;

			//Revisa si ya se cumplio el nodo modificado.
			if (modificado->cuantos == modificado->totales)
				modificado->valorVerdad = VERDAD;
		} else {
			modificado->valorVerdad = FALSO;
		}
	}

	/*
	 * En caso de que una clausula intermedia o conclusion este compuesta por
	 * una o mas proposiciones unidas por una disyuncion, marca como verdaderas
	 * las otras partes, para evitar repeticiones.
	 */
	if (modificado->conectivo > AND && modificado->valorVerdad == VERDAD)
		cancelarProposicionesRedundantes(modificado->conectivo, modificado->valorVerdad);

	return modificado;
}
//*************************************************************************************************
void Grafica::cancelarProposicionesRedundantes(Conectivo conector, int valorVerdad)
{
    CajaNodo *nodo_actual;

	//Obtiene el primer nodo de la grafica.
	nodo_actual = grafica.Principio();

	while (nodo_actual) {
		//Cambia el valor de verdad a los nodos que esten asociados
		//a la etiqueta del conector logico.
		if (nodo_actual->conectivo == conector)
			nodo_actual->valorVerdad = valorVerdad;

		nodo_actual = nodo_actual->siguiente;
	}
}
//*************************************************************************************************
