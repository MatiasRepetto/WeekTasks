/* ejercicio 2a)*/

struct _rep_conjunto{
    bool* elems;
    int tope;
};

typedef _rep_conjunto * TConj;

TConj crearconjunto(int cota){
    TConj newconj = new _rep_conjunto;
    newconj->elems = new bool[cota+1];
    newconj->tope = cota;
    for (int i=1; i<cota; i++){ newconj->elems[i] = false; }
    return newconj;
}

void insertar(int i, TConj &c){
    c->elems[i] = true;
}

void borrar(int i, TConj &c){
    c->elems[i] = false;
}

bool perteneceaConjunto(int i, TConj c){
    return (c->elems[i] == true);
}

TConj interseccion(TConj c1, TConj c2){
    TConj aux = crearconjunto(c1->tope);
    for(int i=1; i<=c1->tope; i++){
        aux->elems[i] = c1->elems[i] && c2->elems[i];
    }
    return aux;
}

Tconj unionfc(TConj c1, TConj c2){
    TConj auxe;
    if(c1->tope > c2->tope){
        TConj aux = crearconjunto(c1->tope);
        for(int i=1; i<=c2->tope; i++){
            aux->elems[i] = c1->elems[i] || c2->elems[i];
        }
        for(int i=c2->tope; i<=c1->tope; i++){
            aux->elems[i] = c1->elems[i];
        }
        auxe = aux;
    }else{
        TConj aux = crearconjunto(c1->tope);
        for(int i=1; i<=c1->tope; i++){
            aux->elems[i] = c1->elems[i] || c2->elems[i];
        }
        for(int i=c1->tope; i<=c2->tope; i++){
            aux->elems[i] = c2->elems[i];
        }
        auxe = aux;
    }
    return auxe;
}

Tconj diferenciafc(TConj c1, TConj c2){
    TConj auxe;
    if(c1->tope > c2->tope){
        TConj aux = crearconjunto(c1->tope);
        for(int i=1; i<=c2->tope; i++){
            aux->elems[i] = c1->elems[i] != c2->elems[i];
        }
        for(int i=c2->tope; i<=c1->tope; i++){
            aux->elems[i] = c1->elems[i];
        }
        auxe = aux;
    }else{
        TConj aux = crearconjunto(c1->tope);
        for(int i=1; i<=c1->tope; i++){
            aux->elems[i] = c1->elems[i] != c2->elems[i];
        }
        for(int i=c1->tope; i<=c2->tope; i++){
            aux->elems[i] = c2->elems[i];
        }
        auxe = aux;
    }
    return auxe;   
}