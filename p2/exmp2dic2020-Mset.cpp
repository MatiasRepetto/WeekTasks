/* Exm Dic 2020 e2 */

// POS: Devuelve el multiset vacío.
Multiset crear();

// POS: Agrega n ocurrencias del elemento x al multiset m. PRE: n>0, 1<=x<=K.
void insertar (Multiset & m, int x, int n);

// POS: Devuelve la suma total de ocurrencias de todos los elementos del multiset m (0 si m está vacío).
int cantidad (Multiset m);

// POS: Devuelve la cantidad de ocurrencias del elemento x del multiset m (0 si x no está en m).
int ocurrencias (Multiset m, int x);

/* POS: Elimina a lo sumo n ocurrencia del elemento x del multiset m. Si ocurrencias(m, x)<=n entonces
en m no quedarán ocurrencias del elemento x. */
void eliminar (Multiset & m, int x, int n);

// POS: Devuelve el mínimo elemento del multiset m (independientemente del número de ocurrencias).
//PRE: m no vacío.
int min (Multiset m);

// imlementar crear, insertar y min.

struct nodomultiset{
    int elem;
    int ocurrencias;
    nodomultiset *izq, *der;
};

struct _rep_multiset{
    nodomultiset *raiz;
    int minimo;
};

typedef _rep_multiset * Multiset;

// Implementamos crear;
Multiset crear(){
    return NULL;
}

//Implementamos insertar
void insertar(Multiset & m, int x, int n){
    nodomultiset *newn = new nodomultiset;
    newn->elem = x;
    newn->ocurrencias = n;
    if(m == NULL){
        newn->izq = NULL;
        newn->der = NULL;
        m->raiz = newn;
        m->minimo = x;
    }else if(x == m->raiz->elem){
        m->raiz->ocurrencias = m->raiz->ocurrencias + n;
    }else if(x < m->raiz->elem){
        m->minimo = x;
        insertar(m->raiz->izq, x, n);
    }else if(x > m->raiz->elem){
        insertar(m->raiz->der, x, n);
    }
}

// Implementamos minimo
int min (Multiset m){
    return m->minimo;
}

// Implementamos vaciar
void vaciar(Multiset &m){
    while(m != NULL){
        if(m->raiz->izq == NULL && m->raiz->der == NULL){
            delete m
        }else if(m->raiz->izq != NULL){
            vaciar(m->raiz->izq);
        }else if(m->raiz->der != NULL){
            vaciar(m->raiz->der);
        }
    }
}









