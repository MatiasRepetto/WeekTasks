/* 2do Parcial 2017 e1 */

// Crea un tad T con modelo LIFO de tamano M
T creart(uint M);

// Ingresa elementos a T a lo sumo M pero no importa si esta llena quedan siempre los ultimos M
void ingresarT(T &t, int elem);

// Informa si T es vacio
bool esvacioT(T t);

// saca el primer elemento de T respetando politica LIFO pre: !esvacioT
void sacardeT(T &t);

// Nos proporciona el ultimo dato ingresado en T respetando LIFO
int datoT(T t);

// Librea memoria asgnada a T
void destruirT(T &t);

// crea un clon de T pero que no comparte memoria
T clonT(T t);

struct nodoT{
    int dato;
    nodoT *sig;
};

struct _rep_T{
    nodoT *inicio, *final;
    uint *cantelem;
    uint *tope;
};

typedef _rep_T * T;

T creart(uint M){
    T newt = new _rep_T;
    newt->inicio = NULL;
    newt->final = NULL;
    newt->cantelem = 0;
    newt->tope = M;
    return newt;
}

void ingresarT(T &t, int elem){
    nodoT *aux = new nodoT;
    aux->dato = elem;
    if(esvacioT){
        aux->sig = t->inicio;
        t->inicio = aux;
    }else if(t->cantelem < t->tope){
        t->final->sig = aux;
        t->final = t->final->sig;
    }else{
        nodoT aux2 = t->inicio;
        t->inicio = t->inicio->sig;
        t->final->sig = aux;
        t->final = t->final->sig;
        delete aux2;
    }
}
// Dado un entero positivo k, t1 y t2 devuelve true si t1 y t2 son similares por k elementos, false si no o t1 y t2 < k elementos
bool similares(T t1, T t2, int k){
    if(t1->cantelem >= k && t2->cantelem >= k){
        while(k>0 && !esvacioT(t1) && !esvacioT(t2) && datoT(t1) == datoT(t2)){
            k--;
            sacardeT(t1);
            sacardeT(t2);
        }
        return (k == 0);
    }else{
        return NULL;
    }
}










