/* parcial 2018 ejercicio 3 */

/* Crea cola de prioridad */
Tcprio crearcolaprioridad();

/* Determina si la cola de priridad es vacia */
bool esvaciacolaprioridad(Tcprio cp);

/* Inserta elemento a la cola de prioridad */
void encolarelemento(Tcprio &cp, int elem);

/* Desencola el elemento de mayor prioridad (El mas pequeno) precondicion : !esvaciacolaprioridad */
void desencolarelemento(Tcprio &cp);

/* Devuelve la cantidad de elementos de la cola */
int cantidadelementos(Tcprio cp);

/* Devuelve el elemento con mayor prioridad (El mas pequeno) precondicion : !esvaciacolaprioridad */
int elementomayorprio(Tcprio &cp);

/* destrulle cola de prioridad */
void destruircprio(Tcprio &cp);

struct nodocprio{
    int dato;
    nodocprio *sig;
};

struct _rep_cprio{
    nodocprio *inicio, *priori;
    int cantidadnodos;
};

typedef _rep_cprio * Tcprio;

Tcprio crearcolaprioridad(){
    Tcprio newcp = new _rep_cprio;
    newcp->inicio = NULL;
    newcp->cantidadnodos = 0;
    newcp->priori = NULL;
    return newcp;
}

bool esvaciacolaprioridad(Tcprio cp){
    return (cp->cantidadnodos == 0);
}

void encolarelemento(Tcprio &cp, int elem){
    nodocprio* nodonew = new nodocprio;
    nodonew->dato = dato;
    nodonew->sig = cp->inicio;
    cp->inicio = nodonew;
    cp->cantidadnodos++;
    if(nodonew->dato < cp->priori->dato){
        cp->priori = nodonew;
    }
}

void desencolarelemento(Tcprio &cp){
    nodocprio *aux;
    if(cp->inicio = cp->priori){
        aux = cp->inicio;
        cp->inicio = cp->inicio->sig;
        cp->priori = cp->inicio;
        delete aux;
    }else{
        aux = cp->inicio->sig;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        nodocprio * aux2 = aux->sig;
        aux = aux->sig->sig;
        delete aux2;
        cp->priori = cp->inicio;
    }

    cp->cantidadnodos--;

    aux = cp->inicio;
    while(aux != NULL){
        if (aux->dato < cp->priori){
            cp->priori = aux;
        }
        aux = aux->sig;
    }
}

int cantidadelementos(Tcprio cp){
    return cp->cantidadnodos;
}

int elementomayorprio(Tcprio cp){
    return cp->priori->dato;
}

void destruircprio(Tcprio &cp){
    nodocprio *aux = cp->inicio;
    while(aux != NULL){
        nodocprio *aux2 = aux;
        aux = aux->sig;
        delete aux2;
    }
    delete cp;
}