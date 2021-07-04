/* exm 2021 feb */

// Ejercicio 1 

struct nodohash{
    char *product;
    int unidades; 
    nodohash *sig;
};

struct _rep_hash{
    nodohash **arrayhash;
    int tope;
    int cantelems;
};

typedef _rep_hash * Stock;

bool estaprod(char *prod, Stock &s){
    int direccion = h(prod) % s->tope;
    nodohash *aux = s->arrayhash[h(prod)% s->tope];
    while(aux != NULL && !strcmp(aux->product, prod)){
        aux = aux->sig;
    }
    return aux!=NULL;
}

void ingresarProducto(char *prod, int cant, Stock &s){
    int direccion = h(prod) % s->tope;
    if(!estaprod(prod, s)){
        nodohash *aux = new nodohash
        aux->product = product;
        aux->unidades = cant;
        aux = s->arrayhash[direccion];
        s->arrayhash[direccion] = aux;
        s->cantelems++;
    }else{
        nodohash aux = s->arrayhash[direccion];
        while(aux != NULL && !strcmp(aux->product, prod)){
            aux->sig;
        }
        aux->unidades++;
    }   
}

int cantidaddeProduct(char *prod, Stock &s){
    if(!estaprod(prod, s)){
        return 0;
    }else{
        int direccion = h(prod) % s->tope;
        nodohash aux = s->arrayhash[direccion];
        while(aux != NULL && !strcmp(aux->product, prod)){
            aux->sig;
        }
        return aux->unidades;
    }
}
