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
    while(s->ha[]){
        
    }
}

void ingresarProducto(char *prod, int cant, Stock &s){
    int direccion = h(prod) % s->tope;
    
}
