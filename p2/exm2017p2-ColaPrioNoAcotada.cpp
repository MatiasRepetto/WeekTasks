/* exm p2 2017 jul */

// Ejercicio 2 

// Especifique completamente el TAD ColaPrio

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

// Implementamos crearCP
ColaPrio crearCP(){
    ColaPrio newcp = new _rep_CP;
    newcp->ini = NULL;
    newcp->fin = NULL;
}

// Implementamos insertarenCP
void insertarenCP(int e, ColaPrio &cp){
    nodoCP *newno = new nodoCP;
    newno->dato = e;
    if(e < cp->ini->dato){
        newno->sig = cp->ini;
        newno->ante = NULL;
        cp->ini->ante = newno;
        cp->ini = newno;
    }else if(e > cp->fin->dato){
        newno->sig = NULL;
        newno->ante = cp->fin;
        cp->fin->sig = newno;
        cp->fin = newno;
    }else{
        nodoCP aux = cp->ini;
        while(aux != NULL && e > aux->dato){
            aux = aux->sig;
        }
        newno->sig = aux->sig;
        newno->ante = aux->sig->ante;
        aux->sig = newno;
        newno->sig->ante = newno;
    }
}

// Implementamos esVaciaCP
bool esVaciaCP(ColaPrio cp){
    return (cp->ini == NULL && cp->fin == NULL);
}

// Implementamos mayorprioCP
int mayorprioCP(ColaPrio cp){
    return cp->ini->dato;
}

// Implementamos eliminarenCP
void eliminarenCP(ColaPrio &cp){
    nodoCP aux = cp->ini;
    cp->ini = cp->ini->sig;
    delete aux;
}

// Implementamos liberarCP
void liberarCP(ColaPrio &cp){
    while(cp->ini != NULL){
        eliminarenCP(cp);
    }
    cp->ini = NULL;
    cp->fin = NULL;
    delete cp;
}
























