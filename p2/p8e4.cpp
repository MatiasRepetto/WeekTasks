/* implementacion de grafica(Mapping) con hash abierto */

struct nodoGraf{
    int x;
    int y;
    nodoGraf *sig;
};

struct _rep_graf{
    nodoGraf** hash;
    int topegraf;
    int elemsgraf;
};

typedef _rep_graf * grafica;

grafica CrearGrafica(int N){
    grafica aux = new _rep_graf;
    aux->hash = new nodoGraf [N];
    aux->topegraf = N;
    for (int i=0; i < N; i++){
        aux->hash[i] = NULL;
    }
    aux->elemsgraf = 0;
    return aux;
}

void Asociar(int x, int y, grafica &g){
    if(x > 0 && y > 0 && Valor(x, g) == -1 && g->elemsgraf < g->topegraf){
        nodoGraf* aux = new nodoGraf;
        aux->x = x;
        aux->y = y;
        aux->sig = g->hash[hash(x)];
        g->hash[hash(x)] = aux;
        g->elemsgraf++;
    }
}

bool estaDefinidoP(int x, grafica g){
    bool encontre = false;
    nodoGraf* aux = g->hash[hash(ch)];
    while(aux != NULL && !encontre){
        if (x == aux->x){
            encontre = true;
        }
        aux = aux->sig;
    }
    return aux != NULL;
}

void Actualizar(int x, int y, grafica &g){
    if(x > 0 && y > 0 && Valor(x, g) != -1){
        nodoGraf* aux = g->hash[hash(x)];
        while(aux->x != x){
            aux = aux->sig;
        }
        aux->y = y;
    }
}

int Valor(int x, grafica g){
    int aux;
    if(estaDefinidoP(x, g) && x > 0){
        nodoGraf* auxn = g->hash[hash(x)];
        while(auxn->x != x){
            auxn = auxn->sig;
        }
        aux = auxn->y;
    }else{
        aux = -1;
    }
    return aux;
}

void desasociar(int x, grafica &g){
    if(estaDefinidoP(x, g) && x > 0){
        nodoGraf* aux = g->hash[hash(x)];
        nodoGraf* aux2 = new nodoGraf;
        while(aux->x != x){
            aux = aux->sig;
        }
        aux2 = aux;
        aux = aux->sig;
        delete aux2;
    }
}