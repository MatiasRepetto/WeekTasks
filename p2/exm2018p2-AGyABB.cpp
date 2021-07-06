/* exm 2018 p2 */

// Ejercicio 1

struct nodoABB{
    int dato;
    nodoABB *izq, *der;
};

typedef nodoABB * ABB;

bool elimHoja(ABB &a, int e){
    bool aux;
    if(a->izq == NULL && a->der == NULL && a->dato == e){
        delete a;
        a = NULL;
        aux = true;
    }else if(e < a->dato){
        aux = elimHoja(a->izq, e);
    }else if(e > a->dato){
        aux = elimHoja(a->der, e);
    }else{
        aux = false;
    }
    return aux;
}

// Ejercicio 2 

struct nodoAG{
    int dato;
    AG *pH, *sH;
};

typedef nodoAG * AG;

bool amplitudAcotada(AG a, uint k){
    bool aux = false;
    if(a == NULL){
        aux = true;
    }else{
        int j = 0;
        nodoAG *aux = a->pH;
        while(aux != NULL && j <= k){
            aux = aux->sH;
            k--;
        }
        j = 0;
        aux = (j <= k) && amplitudAcotada(a->pH, k) && amplitudAcotada(a->sH, k);
    }
    return aux;
}
















