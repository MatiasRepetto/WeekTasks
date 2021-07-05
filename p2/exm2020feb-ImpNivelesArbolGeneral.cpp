/* exm 2020 febr */

// Ejercicio 2

/* impDesdeNivel(AG a, int k) que imprima los elementos del árbol a
que se encuentran en un nivel mayor o igual a k, en cualquier orden. Considere que la raíz del árbol se
encuentra en el nivel 1. No se pueden definir operaciones auxiliares para implementar impDesdeNivel. */

struct nodoAG{
    int dato;
    nodoAG *pH, *sH;
};

typedef nodoAG * AG;

void impDesdeNivel(AG a, int k){
    if(a != NULL){
        if(k <= 1){
            printf("%d \n", a->dato)
        }
        impDesdeNivel(a->sH, k);
        impDesdeNivel(a->pH, k-1);
    }
}

