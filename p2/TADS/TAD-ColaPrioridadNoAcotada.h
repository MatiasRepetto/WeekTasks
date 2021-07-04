/* TAD Cola Prioridad No Acotada */

// Crea una cola de prioridad vacia de hasta
ColaPrio crearCP();

// Inserta un elemento a la cola de prioridad (el de menor valor tiene mas prioridad)
void insertarenCP(int e, ColaPrio &cp);

// Nos informa si la cola de prioridad esta vacia
bool esVaciaCP(ColaPrio cp);

// Nos regresa el elemento de mayor prioridad en la cola pre: !esVaciaCP
int mayorprioCP(ColaPrio cp);

// Elimina el elemento de mayor prioridad en la cola pre: !esVaciaCP
void eliminarenCP(ColaPrio &cp);

// Elimina y libera la memoria asociada a la cola de prioridad
void liberarCP(ColaPrio &cp);

// Estructura ejemplo para la implementacion (Lista doblemente encadenada).

struct nodoCP{
    int dato;
    nodoCP *sig;
    nodoCP *ante;
};

struct _rep_CP{
    nodoCP *ini;
    nodoCP *fin;
};

typedef _rep_CP * ColaPrio;
