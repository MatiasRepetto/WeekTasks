/* e7bp10 */
/* matriz con buen uso de memoria */

struct celda{
    uint *nrofila, *nrocol;
    int* valor;
    celda *sigFila, *sigCol;
};

typedef celda * celdas;

struct cabezal{
    uint *rangofila, *rangocolumna;
    celda* columnas;
    celda* fila; 
};

typedef cabezal * Tmatrix;

Tmatrix crearmatrix(uint n, uint m){
    Tmatrix newmx = new cabezal;
    newmx->rangocolumna = m;
    newmx->rangofila = n;
    newmx->fila = new int[n+1];
    for(uint i=1; i<=n+1; i++){
        newmx->fila[i] = NULL;
    }
    newmx->columnas = new int[m+1];
    for(uint i=1; i<=m+1; i++){
        newmx->columnas[i] = NULL;
    }
    return newmx;
}

void asignaramatrix(Tmatrix &mx, uint n, uint m, int valor){
    celdas aux = new celda;
    aux->valor = valor;
    aux->nrocol = m;
    aux->nrofila = n;

    bool existe = false;

    if(mx->columnas[m] == NULL || mx->columnas[m]->nrofila > n){ // Busco en columna
        aux->sigCol = mx->columnas[m]; //inserto al inicio
        mx->columnas[m] = aux;
    }else{ // busco si existe el lugar donde debo insertar columna 
        if(mx->columnas[m]->nrofila == n){ // si columna ya existente y es la primera
            mx->columnas[m]->valor = valor;
            existe = true; 
        }else{ // celda no es la primera
            celdas iterc = mx->columnas[m];
            while(iterc->sigCol != NULL && iterc->sigCol->nrofila < n){
                iterc = iterc->sigCol;
            }
            if(iterc == NULL || iterc->sigCol->sigFila > n){ //celda no existe debo insertar antes de iterc
                aux->sigCol = iterc->sigCol;
                iterc->sigCol = aux;
            }else{ // la celda ya existe y solo modifico
                iterc->sigCol->valor = valor;
                existe = true;
            }
        }
    }
    if(!existe){ // se que no existe la celda y debo insertar en fila correspondiente
        if(mx->fila[n] == NULL || mx->fila[n]->nrocol > m){ // no existe celda y debo insertar al inicio de fila
            aux->sigFila = mx->fila[n];
            mx->fila[n] = aux;
        }else{ // busco si existe lugar donde debo ingresar la celda
            celdas iterf = mx->fila[n];
            while(iterf->sigFila != NULL && iterf->sigFila->nrocol < m){
                iterf = iterf->sigFila;
            }
            aux->sigFila = iterf->sigFila; // la celda va luedo de iterf porque se que no existe celda en (n, c)
            iterf->sigFila = aux;
            }
        }
    }else{
        delete aux; // libero memoria la creada porque ya existe
    }
}
