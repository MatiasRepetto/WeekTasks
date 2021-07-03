/* exm 2021 feb */

// Ejercicio 1.

struct ABNode{
    int info;
    ABNode *izq, *der;
};

// Implemente una funcion recursiva ordParcial que dado un arbol binario de enteros retorne 
// si y solo si el arbol esta parcialmente ordenado.

bool ordParcial(ABNode *t){
    bool aux = false;
    if(t == NULL){
        aux = true;
    }else if(t->izq != NULL){
        aux = t->info <= t->izq->info;
    }else if(t->der != NULL){
        aux = aux && t->info <= t->der->info;
    }else{
        aux = aux && ordParcial(t->izq) && ordParcial(t->der);
    }
    return aux;
}
