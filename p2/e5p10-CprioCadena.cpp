/* e5p10 */

struct nodocprio{
    t* dato;
    nat* prio;
    nodocprio* sig;
};

typedef nodocprio * Tcprio;

Tcprio crearcolaprio(){
    return NULL;
}

void ingresaracprio(Tcprio &cp, t dato, nat prio){
    nodocprio* newno = new nodocprio;
    newno->dato = dato;
    newno->prio = prio;
    newno->sig = cp;
    cp = newno;
}

bool estavaciacprio(Tcprio cp){
    return cp == NULL;
}

Tcprio obteneranteriorpunteoaprioritario(Tcprio cp){
    Tcprio aux = cp;
    cp = cp->sig;
    while(cp->sig != NULL){
        if(cp->sig->prio < aux->prio){
            aux = cp;
        }
        cp = cp->sig
    }
    return aux;
}

t infoprio(Tcprio cp){
    Tcprio aux = obteneranteriorpunteoaprioritario(cp);
    return aux->sig->dato;
}

void eliminarprioritario(Tcprio &cp){
    Tcprio aux = obteneranteriorpunteoaprioritario(cp);
    Tcprio aux2 = aux->sig;
    aux = aux->sig->sig;
    delete aux2;
}


