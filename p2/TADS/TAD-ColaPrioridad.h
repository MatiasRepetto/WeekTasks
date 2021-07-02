/* TAD Cola prioridad */

// Crea una cola dew prioridad de tamaño M.
Tcola crearCola(int M);

// Retorna true si la cola de prioridad esta llena false de lo contrario.
bool esllenaCola(Tcola cp); // Para versiones acotadas

// Inserta un elemento a la cola de prioridad con la prioridad asignada pre: !esllenaCola.
void insertarenCola(int elem, int prio, Tcola &cp);

// Devuelve true si la cola de prioridad es vacia y false si no lo es.
bool esVaciacola(Tcola cp);

// Devuelve el elemento de mayor prioridad en la cola pre: !esVacioCola.
int elementoCola(Tcola cp);

// Elimina el elemento de mayor prioridad en la cola de prioridad pre: !esVaciaCola.
void eliminarenCola(Tcola &cp);

// Elimina la cola de prioridad y libera la memoria asignada a ella.
void liberarCola(Tcola &cp);

// Posibles estructuras que sirvan para implementar una cola de prioridad (hay muchas maneras) acorde a las necesidades y efectividad de implementaciones.

// Para versiones acotadas (Ej).

// Implementacion Con Monticulos binarios (Binary Heaps) son arboles AVL con la siguiente propiedad.
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
//    Para todo nodo X, la clave en el padre de X es:
//    menor --si nos basamos en Sets para prioridades--
//    (menor o igual --si nos basamos en Multisets para
//    prioridades--)
//    16
//    que la clave en X, con la excepción obvia de la raíz
//    (donde esta el mínimo elemento).
//    Esta propiedad permite realizar eficientemente las
//    propiedades de una cola de prioridad que refieren
//    al mínimo.
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
//                              🢃
//                              🢃
//                              🢃
//Arreglo estructurado como Heap o monticulo el cual cumple 
// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
//    Para cualquier elemento en la posición i del arreglo,
//    el hijo izquierdo está en la posición 2*i, el hijo
//    derecho en la posición siguiente: 2*i+1 y el padre
//    está en la posición i / 2.
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

struct nodoCp{
    int elem;
    int prio;
};

struct _rep_Cprio{
    nodoCp *arreglo;
    int tope;
    int cantidadelems;
};

typedef _rep_Cprio * Tcola;



