/* e6p10 */

struct arraypila{
    t* elem;
    int topepila;
    int ultimoinsert;
};

typedef arraypila * Tpila;

Tpila crearpila(into tope){
    Tpila newp = new arraypila;
    newp->elem = new *t[tope];
    newp->topepila = tope;
    newp->ultimoinsert = 0;
    for(int i = 0; i <= tope; i++){
        newp->elem[i] = NULL;
    }
    return newp;
}

bool esllenopila(Tpila p){
    return (p->topepila == p->ultimoinsert);
}

void insertarpila(Tpila &p, t elem){
    if (esllenopila(p)){
        for(int i = 0; i < p->topepila; i++){
            p->elem[i] = p->elem[i+1];
        }
        p->elem[p->topepila] = elem;
    }else{
        p->ultimoinsert++;
        p->elem[p->ultimoinsert] = elem;
    }
}

t elementotopepil(Tpila p){
    return p->elem[p->ultimoinsert];
}

bool esvaciapila(Tpila p){
    return p->ultimoinsert == 0;
}

void desapilar(Tpila &p){
    if(!esvaciapila(p)){
        p->ultimoinsert--;
    }
}

void destruirpila(Tpila &p){
    if(!esvaciapila(p)){
        p->ultimoinsert = 0;
    }
}






