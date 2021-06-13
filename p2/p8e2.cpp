/* Implementacion de un Mapping con Hash */
struct nodomap{
    char* elem;
    int r;
    nodomap* sig;
};

struct _rep_map{
    nodomap** hash;
    int tamaMap;
    int elemMap;
};

typedef _rep_map * Tmap;

Tmap crearMap(int N){
    Tmap nMap = new _rep_map;
    nMap->tamaMap = N;
    nMap->hash = new nodomap[N];
    nMap->elemMap = 0;
    for (int i = 0; i < nMap->tamaMap; i++){
        nMap->hash[i] = NULL;
    }
    return nMap;
}

void insertar(char* ch, int re, Tmap & m){
    nodomap* aux = new nodomap;
    aux->elem = ch;
    aux->r = re;
    aux->sig = m->hash[hash(ch)];
    m->hash[hash(ch)] = aux;
    m->elemMap++;
}

bool esVacioMap(Tmap m){
    return (m->elemMap == 0);
}

bool estaDefinidoD(char* ch, Tmap m){
    bool encontre = false;
    nodomap* aux = m->hash[hash(ch)];
    while(aux != NULL && !encontre){
        if (strcmp(ch, aux->elem)){
            encontre = true;
        }
        aux = aux->sig;
    }
    return aux == NULL;
}

void eliminartd(char* ch, Tmap & m){
    if(estaDefinidoD(ch, m)){
        nodomap* aux = m->hash[hash(ch)];
        while(!strcmp(aux->elem, ch)){
            aux = aux->sig;
        }
        nodomap* aux2 = aux;
        aux = aux->sig;
        delete aux2;
    }
}

int recuperarvalor(char* ch, Tmap m){
    int auxi = 0;
    if(estaDefinidoD(ch, m)){
        nodomap* aux = m->hash[hash(ch)];
        while(!strcmp(aux->elem, ch)){
            aux = aux->sig;
        }
        auxi = aux->r;
    }
    return auxi;
}


