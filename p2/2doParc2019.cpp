/* 2do parcial 2019 e1b */

struct rep_heap{
    int max;
    int tope;
    int *elems;
};

typedef rep_heap * heap;

void filtradoAscendente(int i, heap &h){
    while(1 <= i && i <= h->tope && h->elems[i] < h->elems[i/2]){
        int elemaux = h->elems[i];
        h->elems[i] = h->elems[i/2];
        h->elems[i/2] = elemaux;
        i = i/2;
    }
}

/* e1c */

typedef heap ColaPrioridad;

void insertar(int p, ColaPrioridad &cp){
    if(cp->max > cp->tope){
        cp->tope++;
        cp->elems[cp->tope] = p;
        filtradoAscendente(cp->tope, cp);
    }
}