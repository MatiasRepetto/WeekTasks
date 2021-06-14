/* Operaciones core de arboles AVL */

struct nodoavl{
    int dato;
    nodoavl *izq, *der;
    int alturAVL;
};

typedef nodoavl * arbAVL;

/* Altura del AVL */
int alturaAvl(arbAVL A){
    int alt = 0;
    if(A != NULL){
        alt = A->alturAVL;
    }
    return alt;
}

/* Rotar hacia la derecha Precond: z y z->izq != NULL;*/
void rotarDerecha(arbAVL &z){
    arbAVL y = z->izq;
    arbAVL T3 = y->der;

    y->der = z;
    z->izq = T3;

    z->alturAVL = max(alturaAvl(z->izq), alturaAvl(z->der)) + 1;
    y->alturAVL = max(alturaAvl(y->izq), alturaAvl(y->der)) + 1;

    z = y;
}

/* Rotar hacia la izquierda Precond: z y z->der != NULL;*/
void rotarIzquierda(arbAVL &z){
    arbAVL y = z->der;
    arbAVL T2 = y->izq;

    y->izq = z;
    z->der = T2;

    z->alturAVL = max(alturaAvl(z->izq), alturaAvl(z->der)) + 1;
    y->alturAVL = max(alturaAvl(y->izq), alturaAvl(y->der)) + 1;

    z = y;
}

/* Codigo de insercion en un AVL manteniendo politica AVL */
void insertarAVL ( int x , arbAVL & A ) {
    if ( A == NULL ) { // caso base
        A = new nodoavl ;
        A->dato = x ;
        A->izq = A->der = NULL ;
        A->alturAVL = 1;
    }else{
        if ( x < A->dato) {
            insertarAVL (x , A->izq) ;
            A->alturAVL = max (alturaAVL(A->izq), alturaAVL(A->der)) + 1;
            // Factor de balanceo
            int FB = alturaAVL(A->izq) - alturaAVL(A->der) ;
            if ( FB > 1) {
                //sólo puede aumentar la altura del sub árbol izquiero
                if (alturaAVL(A->izq->izq) > alturaAVL(A->izq->der)){
                    // sub árbol izquierdo del sub árbol izquierdo muy alto
                    // caso LL o II
                    rotarDerecha (A) ;
                }else{ 
                    // sub árbol derecho del sub árbol izquierdo muy alto
                    // caso LR o ID
                    rotarIzquierda (A->izq);
                    rotarDerecha(A);
                }
            }
        }else{
            insertarAVL(x , A->der);
            A->alturAVL = max(alturaAVL(A->izq), alturaAVL(A->der)) + 1;
            // Factor de balanceo
            int FB = alturaAVL(A->izq) - alturaAVL(A->der);
            if ( FB < -1) {
                // s ó lo puede aumentar la altura del sub á rbol derecho
                if ( alturaAVL(A->der->der) > alturaAVL(A->der->izq)){
                    // sub á rbol derecho del sub á rbol derecho muy alto
                    // caso RR o DD
                    rotarIzquierda (A) ;
                }else {
                    // sub á rbol izquierdo del sub á rbol derecho muy alto
                    // caso RL o DI
                    rotarDerecha(A->der);
                    rotarIzquierda(A);
                }
            }
        }
    }
}