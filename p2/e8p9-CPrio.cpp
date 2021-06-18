/* Ejercicio 8 p9 */

struct listaLCP{
    TinfoCp *info;
    listaLCP *sig;
};

typedef listaLCP * ListaCP;

ListaCP crearlistacp(){
    return NULL;
}

bool esvacialistaCP(ListaCP cp){
    return (cp == NULL);
}

void insertarenlistaCP(ListaCP &cp, TinfoCp info){
    listaLCP aux = new listaLCP;
    aux->info = info;
    if(esvacialistaCP){
        aux->sig = NULL;
        cp = aux;
    }else{
        listaLCP * iter = cp;
        while(iter != NULL && iter->info <= aux->info){
            iter = iter->sig;
        }
        aux->sig = iter->sig;
        iter = aux;
    }
}

TinfoCp primerodelistaCP(ListaCP cp){
    return (cp->info);
}

void restolistaCP(ListaCP &cp){
    listaLCP aux = cp;
    cp = cp->sig;
    delete aux;
}

/* Implementacion de Cola Prioridad */
struct nodcprio{
    ListaCP cprio;
};

typedef nodcprio * Tcprio;

Tcprio crearcolaprio(){
    Tcprio aux = new nodcprio;
    aux->cprio = crearlistacp();
    return aux;
}

void encolarcolaprioridead(TinfoCp elem, int p, Tcprio &cp){
    TinfoCp aux;
    aux->elem = elem;
    aux->p = p;
    insertarenlistaCP(cp->cprio, elem);
}

bool esvaciacolaprioridad(Tcprio cp){
    return (esvacialistaCP(cp->cprio));
}

TinfoCp prioritariocolaprioridad(Tcprio cp){
    return (primerodelistaCP(cp->cprio).elem);
}

void eliminarpriocolaprio(Tcprio &cp){
    restolistaCP(cp->cprio);
}

/* Segunda parte ahora implementado con heap */

#define M = 10000;

void filtradoascendente(TinfoCp * array, uint pos);
void filtradodescendiente(TinfoCp * array, uint n, uint pos);

struct nodohp{
    TinfoCp * array[M];
    uint *tope;
};

typedef nodohp * heapCP;

heapCP crearcolaprioridadhp(uint n){
    heapCP aux = new nodohp;
    aux->tope = 0;
    return aux;
}

bool esvaciaheapcp(heapCP cp){
    return (cp->tope == 0);
}

void insertarenheapcp(heapCP &cp, T elem, int p){
    if(cp->tope < M){
        TinfoCp aux;
        aux->elem = elem;
        aux->p = p;
        cp->tope++;
        cp->array[cp->tope] = aux;
        filtradoascendente(cp->array, cp->tope)
    }
}

T prioritarioCp(heapCP cp){
    return cp->array[1].elem;
}

void eliminarprioritarioheapcp(heapCP &cp){
    if(cp->tope > 0){
        cp->array[1] = cp->array[cp->tope];
        cp->tope--;
        if(cp->tope > 1){
            filtradodescendiente(cp->array, M, 1);
        }
    }
}
