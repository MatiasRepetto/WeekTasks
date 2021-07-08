/* exm 2016 jul */

// Ejercicio 2

// Crear una lista de pedidos vacia de a lo sumo k pedidos
Tped crarListPed(uint k);

// retorna true si la lista de pedidos esta llena y false de lo contrario 
bool esLlenaPed(Tped l);

// inserta el pedido en la lista si y solo si el identificador no esta en lista, pre : !esLlenaPed
void insertarenPed(Tped &l, string dat, int id);

// retorna true si la lista de pedidos es vacia y false de lo contrario
bool esVaciaPed(Tped l);

// nos da el dato del pedido con mayor prioridad pre: !esVaciaPed
string datoPed(Tped l);

// Borra el pedido con mayor prioridad de la lista pre : !esVaciaPed
void borrarenPed(Tped &l);

// Libera y elimina los elementos de la memoria de la lista de pedidos
void liberarPed(Tped &l);

// Implementacion 

struct nodolist{
    int id;
    string dato;
    nodolist *sig;
};

struct _rep_listPed{
    bool *estaid;
    nodolist *ini, *fin;
    int tope, cantidad;
};

typedef _rep_listPed * Tped;

// Implementamos Crear
Tped crarListPed(uint k){
    Tped *auxped = new _rep_listPed;
    auxped->ini = NULL;
    auxped->fin = NULL;
    auxped->tope = k;
    auxped->cantidad = 0;
    auxped->estaid = new *bool[k];
    for(int i=0; i<=k; i++){
        auxped->estaid[i] = false;
    }
    return auxped;
}

// Implementamos insertarenPed
void insertarenPed(Tped &l, string dat, int id){
    if(l->cantidad < l->tope && l->estaid[id] == false){
        nodolist *aux = new nodolist;
        aux->dato = dat;
        aux->id = id;
        aux->sig = NULL;
        if(l->ini == NULL){
            l->ini = aux;
            l->fin = aux;
        }else{
            l->fin->sig = aux;
            l->fin = aux;
        }
        l->cantidad++;
        l->estaid[id] = true;
    }
}

// Ejercicio 3 

// Crea y devuelve una Tabla vacía
Tabla crearT();

// Asocia a d el valor s en t; si ya tenía un valor asociado, lo redefine
void insertarT(int d, string s, Tabla &t);

// Devuelve true si t esta vacía y false en caso contrario
bool esVaciaT(Tabla t);

/* Devuelve true si el elemento d tiene asociado un elemento en t y false en caso
contrario */
bool estaDefinidaEnT(int d, Tabla t);

/* Devuelve el elemento del codominio asociado a d en t
Pre: estaDefinidaEnT(d,t) */
string recuperarT(int d, Tabla t);

/* Modifica t de modo que d no tenga un elemento asociado.
Si !estaDefinidaEnT(d,t), la operación no tiene efecto */
void borrarT(int d, Tabla &t); 

struct nodohash{
    int dom;
    string cod;
    nodohash *sig;
};

struct _rep_tabla{
    nodohash **tabla;
    int tope;
    int cantidadelems;
};

typedef _rep_tabla * Tabla;

// implementamos crearT
Tabla crearT(){
    Tabla newt = new _rep_tabla;
    newt->tabla = new nodohash[N];
    newt->tope = N;
    newt->cantidadelems = 0;
    for(int i=0; i<=N; i++){
        newt->tabla[i] = NULL;
    }
    return newt;
}

// Implementamos recuperarT
string recuperarT(int d, Tabla t){
    if(estaDefinidaEnT(d, t)){
        string resul;
        int direccion = h(d) % t->tope;
        nodohash aux = t->Tabla[direccion];
        while(aux != NULL && aux->dom != d){
            aux = aux->sig;
        }
        resul = aux->cod;
    }
    return resul;
}





























