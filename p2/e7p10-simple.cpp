/* e7p10 */

struct arraymatrtiz{
    int n;
    int m;
    nat* dato;
};

typedef arraymatrtiz * Tmatriz;

Tmatriz crearmatriz(int n, int m){
    Tmatriz newma = new arraymatrtiz;
    newma->m = m;
    newma->n = n;
    newma->dato = new nat[n,m];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            newma->dato[i,j] = 0;
        }
    }
    return newma;
}

nat devolvernaturalmatrix(Tmatriz mx, int n, int m){
    return (mx->dato[n,m]);
}

void ingresaramatrix(Tmatriz &mx, int n, int m, nat elem){
    mx->dato[n,m] = elem;
}

void imprimirfila(Tmatriz &mx, int m){
    for(int i=0; i<mx->n, i++){
        printf(%u, mx->dato[i,m]);
    }
}

void imprimircolumna(Tmatriz &mx, int n){
    for(int i=0; i<mx->m, i++){
        printf(%u, mx->dato[n,i]);
    }
}


