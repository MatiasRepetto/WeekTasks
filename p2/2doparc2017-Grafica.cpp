/* 2do Parcial 2017 e2 */

struct _rep_grafica{
    lista *lista;
    int cantidad;
    int tope;
};

typedef _rep_grafica * Grafica;

Grafica crearGrafica(int N){
    Grafica newg = new _rep_grafica;
    newg->lista = new lista[N];
    for(int i=0; i<=N; i++){
        newg->lista[i] = CrearLista();
    }
    newg->cantidad = 0;
    newg->tope = N;
    return newg;
}

void asociar(int x, int y, Grafica &g){
    if(g->cantidad < g->tope){
        punto p = new p;
        p->x = x;
        p->y = y;
        Cons(p, g->lista[x % g->tope]);
        g->cantidad++;
    }
}

void actualizar(int x, int y, Grafica &g){
    if(!EsVacialista(g->lista[x % g->tope]) && ExisteX(x, g->lista[x % g->tope])){
        punto p = new punto;
        p->x = x;
        p->y = y;
        RemoverX(x, g->lista[x % g->tope]);
        Cons(p, g->lista[x % g->tope]);
    }
}

int valor(int x, Grafica g){
    int aux = -1;
    if(!EsVacialista(g->lista[x % g->tope]) && ExisteX(x, g->lista[x % g->tope])){
        while(!EsVaciaLista(g->lista[x % g->tope]) && Primero(g->lista[x % g->tope]).x != x){
            Resto(g->lista[x % g->tope]);
        }
        if(!EsVaciaLista(g->lista[x % g->tope])){
            aux = -1;
        }else{
            aux = Primero(g->lista[x % g->tope]).y;
        }
    }
    return aux;
}

void desasociar(int x, Grafica &g){
    if(!EsVacialista(g->lista[x % g->tope]) && ExisteX(x, g->lista[x % g->tope])){
        while(ExisteX(x, g->lista[x % g->tope])){
            RemoverX(x, g->lista[x % g->tope]);
            g->cantidad--;
        }
    }
}