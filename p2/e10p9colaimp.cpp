/* e10 p9 Cola impresion */ 

typedef nodata * colastring;

struct nodoimpre{
    colastring* colaimpr;
    uint* aimprimir;
};

typedef nodoimpre * Timp;

Timp crearcolaimp(uint n){
    Timp aux = new nodoimpre;
    aux->aimprimir = 0;
    aux->colaimpr = new colastring[n + 1];
    for(uint i = 1; i <= n + 1; i++){
        aux->colaimpr[i] = crearcolastring();
    }
    return aux;
}

bool esvaciacolaimp(Timp c){
    return (c->aimprimir == 0);
}

/* 0 < prio <= n+1 */
void insertarencolaimp(string elem, uint prio, Timp &c){
    encolarstring(elem, c->colaimpr[prio]);
    if(c->aimprimir < prio){
        c->aimprimir = prio;
    }
}

string imprimir(Timp c){
    uint maxprio = c->aimprimir;
    string texto = c->colaimpr[maxprio];
    desencolarColaString(c->colaimpr[maxprio]);

    while(esvaciocolaString(c->colaimpr[maxprio]) && maxprio > 0){
        maxprio = maxprio - 1;
    }
    return texto;
}
