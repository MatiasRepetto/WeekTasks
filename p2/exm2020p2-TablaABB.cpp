/* exm 2020 p2 */

// Ejercicio 2 

struct nodoABB{
    nat dominio;
    float codominio;
    nodoABB *izq, *der;
};

struct RepTabla{
    nodoABB *ABB;
    int cantidad;
};

typedef RepTabla * Tabla;

// Implementamos crear
Tabla crear(){
    Tabla newt = new RepTabla;
    newt->ABB = NULL;
    newt->cantidad = 0;
}

// Implementamos insertar
void insertar(nat d, float c, Tabla &t){
    if(!definida(d, t)){
        nodoABB *aux = new nodoABB;
        aux->dominio = d;
        aux->codominio = c;
        aux->izq = NULL;
        aux->der = NULL;
        if(t == NULL){
            t = aux;
            t->cantidad++;
        }else if(d < t->dominio){
            insertar(d, c, t->izq);
        }else if(d > t->dominio){
            insertar(d, c, t->der);
        }
    }else{
        if(d == t->dominio){
            t->codominio = c;
        }else if(d < t->dominio){
            insertar(d, c, t->izq);
        }else if(d > t->dominio){
            insertar(d, c, t->der);
        }
    }
}

// Implementamos cantidad
int cantidad(Tabla t){
    return t->cantidad;
}

// Ejercicio 3
Tabla consolidar(Tabla t1, Tabla t2, nat inf, nat sup){
    Tabla auxconsi = crear();
    for(int i = inf ; i <= sup; i++){
        bool esta_t1 = definida(d, t1);
        bool esta_t2 = definida(d, t2);
        if(esta_t1 && esta_t2){
            auxconsi = insertar(d, recuperar(d, t1) + recuperar(d, t2), auxconsi);
        }else if(esta_t1){
            auxconsi = insertar(d, recuperar(d, t1), auxconsi);
        }else if(esta_t2){
            auxconsi = insertar(d, recuperar(d, t2), auxconsi);
        }
    }
    return auxconsi;
}







