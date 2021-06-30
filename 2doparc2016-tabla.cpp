/* 2do Parcial e3 */

struct nodotab{
    int d;
    string *dat;
    nodotab *sig;
};

struct _rep_tabla{
    nodotab **tabla;
};

typedef _rep_tabla * Tabla;

// Implementar solo crearT y recuperarT

Tabla crearT(){
    Tabla newt = new _rep_tabla;
    newt->tabla = new nodotab[N];
    for(int i=0; i<=N; i++){
        newt->tabla[i] = NULL;
    }
    return newt;
}

string recuperarT(int d, Tabla t){
    nodotab *list = t->tabla[h(d)%N];
    if(estaDefinidaEnT(d, t)){
        while(list->d != d){
            list = list->sig;
        }
    }
    return list->dat;
}

int buscar(string s, ListaEnt li, Tabla t){
    int aux, aux2=0;
    aux = obtenerPrimeroLEnt(li);
    while(!esVaciaLEnt(li)){
        if(aux2 < aux && estaDefinidaEnT(aux) && strEq(s, recuperarT(aux, t))){
            aux2 = aux;
        }
        aux = obtenerPrimeroLEnt(restoLEnt(li));
        restoLEnt(li);
    }
    return aux2;
}
