/* e1p10 Ranking FIFA */

struct nodohash{
    char* pais;
    int puesto;
    nodohash* sig;
};

struct multififa{
    nodohash** escala;
    int cotapaises;
    nodohash** tablahash;
};

typedef multififa * fifa;

fifa crearFIFA(int cota){
    fifa newf = new multififa;
    newf->escala = new nodohash[cota];
    newf->tablahash = new nodohash[cota];
    newf->cotapaises = cota;
    for(int i = 0; i <= cota; i++){
        newf->escala[i] = NULL;
        newf->tablahash[i] = NULL; 
    }
    return newf;
}

void agrega(fifa &f,int puest, char* pais){
    nodohash* newp = new nodohash;
    newp->pais = pais;
    newp->puesto = puesto;
    newp->sig = f->tablahash[hash(pais) % f->cotapaises];
    f->tablahash[hash(pais) % f->cotapaises] = newp;
    f->escala[puest] = newp;
}

char* reta(fifa f, char* pais){
    nodohash* aux = f->tablahash[hash(pais) % f->cotapaises];
    while(strcmp(aux->pais, pais) && aux != NULL){
        aux = aux->sig;
    }
    if(aux == NULL && aux->puesto != 1){
        return f->escala[aux->puesto - 1]->pais;
    }else{
        return NULL;
    }
}

void cambia(fifa &f, int posicion){
    nodohash aux = f->escala[posicion];
    f->escala[posicion]->puesto--;
    f->escala[posicion - 1]->puesto++;
    f->escala[posicion] = f->escala[posicion - 1];
    f->escala[posicion - 1] = aux;
}





