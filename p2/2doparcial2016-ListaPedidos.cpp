/* 2do Parcial 2016 e2 */

// Crea una lista de pedidos vavcia que puede contener k+1 pedidos
Tpedi crearlistapedidos(int k);

// informa si la lista de pedidos esta llena
bool estallenalista(Tpedi p);

// Inserta un pedido en la lista de pedidos si es que no esta llena !estallenalista
void insertarpedi(Tpedi &lp, colaP p);

// Elimina el pedido mas antiguo (el primero ingresado) de una lista no vacia y devuelve la descripcion de dicho pedido
void infoyelimalprimero(Tpedi &lp);

// consulata si la lista de pedidos es vacia
bool esvacialistaped(Tpedi lp);

// Consultar si hay un pedido con identificador i en un lista pedidos
bool existei(Tpedi lp);

struct pedi{
    int identificador;
    string descripcion;
    pedi *sig;
};

typedef pedi * colaP;

struct _rep_listapedi{
    bool * iduso;
    colaP *inicio, *final;
    int cantidadelems;
    int tope;
};

typedef _rep_listapedi * Tpedi;

Tpedi crearlistapedidos(int k){
    Tpedi newp = new _rep_listapedi;
    newp->iduso = new bool[k+1];
    newp->inicio = NULL;
    newp->final = NULL;
    newp->cantidadelems = 0;
    newp->tope = K+1;
    for(int i=0; i<=K+1; i++){
        newp->iduso[i] = false;
    }
    return newp;
}

void insertarpedi(Tpedi &lp, int id, string pedido){
    if(lp->cantidadelems < lp->tope){
        colaP auxp = new colaP;
        auxp->identificador = id;
        auxp->descripcion = pedido;
        auxp->sig = NULL;
        if(lp->inicio == NULL && lp->final == NULL){
            lp->inicio = auxp;
            lp->final = auxp;
            lp->cantidadelems++;
            lp->iduso[id] = true;
        }
        if(lp->iduso[id] == false){
            lp->final->sig = auxp;
            lp->final = auxp;
            lp->cantidadelems++;
            lp->iduso[id] = true;
        }
    }
}
