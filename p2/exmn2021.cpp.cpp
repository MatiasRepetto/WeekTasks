// exmn 2021

// ejercicio 1

struct ABnode{
    int info;
    ABnode *izq, *der;
};

bool ordParcial(ABnode *t){
    bool resul = false;
    if(t->info == NULL){
        resul = true;
    }else if(t->izq != NULL){
        resul = t->izq->info >= t->info;
    }else if(t->der != NULL){
        resul =  t->der->info >= t->info;
    }
    return (resul && ordParcial(t->izq) && ordParcial(t->der));
}

// Ejercicio 2

//Crea un stock con N cantidad de elems esperada.
stock crearstock(int N);

//Inserta inserta N cantidad de un elemento a un stock si este ya se encuentra lo actualiza
void insertarstock(stock *st, int cantidad, string product);

//nos devuelve true si el producto se encuentra en el stock y false de lo contrario
bool estaenstock(stock st, string product);

//elimina del stock el producto deseado pre: estaenstock();
void eliminardestock(stock *st, int N, string product);

//arroja la cantidad de stock de un producto pre: estaenstock();
int cantidadstock(stock st, string prod);

// Libera la memoria asociada a la coleccion de stock
void liberarstock(stock *st);

struct nodohash{
    string prod;
    int cantidad;
    nodohash *sig;
};

struct rep_hash_prod{
    nodohash **hash;
};

typedef rep_hash_prod * stock;

void insertarstock(stock *st, int cantidad, string product){
    int direccion = h(product) % N;
    nodohash lugarhash = st->hash[direccion];
    if(estaenstock(st, product)){
        while(lugarhash != NULL && strcmp(lugarhash->prod, product)!= 0){
            lugarhash = lugarhash->sig;
        }
        lugarhash->cantidad = lugarhash->cantidad + cantidad;
    }else{
        nodohash newitem = new nodohash;
        newitem->prod = product;
        newitem->cantidad = cantidad;
        newitem->sig = lugarhash;
        lugarhash = newitem;
    }
}

void eliminardestock(stock *st, int cantidad, string product){
    if(estaenstock(st, product)){
        int direccion = h(product) % N;
        nodohash lugarhash = st->hash[direccion];
        while(lugarhash != NULL && strcmp(lugarhash->prod, product)!= 0){
            lugarhash = lugarhash->sig;
        }
        lugarhash->cantidad = min(lugarhash->cantidad - N, 0);
    }
}

int cantidadstock(stock st, string prod){
    int aux;
    if(estaenstock(st, product)){
        int direccion = h(product) % N;
        nodohash lugarhash = st->hash[direccion];
        while(lugarhash != NULL && strcmp(lugarhash->prod, product)!= 0){
            lugarhash = lugarhash->sig;
        }
        aux = lugarhash->cantidad;
    }else{
        aux = 0;
    }
    return aux;
}





