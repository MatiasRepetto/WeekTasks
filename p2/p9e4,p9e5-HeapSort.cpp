/* Ejercicio 4 p9 */

void arraytoheapFd(T &array, uint n){
    for (uint i = 1; i <= n; i++){
        filtradoAscRec(array, i);
    }
}

void arraytoheapFa(T &array, uint n){
    for(uint i = n*2; i >= 1; i--){
        filtradoAscRec(array, n, i);
    }
}

void HeapSort(T &array, uint n){
    arraytoheapFd(array, n);
    for(uint i = 1; i < n; i++){
        T max = array[1];
        array[1] = array[n - i + 1];
        array[n - i + 1] = max;
        filtradoDescRec(array, n - i, 1)
    }
}

int kesimoMayor(T &array, uint n, uint k){
    arraytoheapFd(array, n);
    for(uint i = 1; i<=k; i++){
        array[1] = array[n - i + 1];
        filtradoDescRec(array, n - i, 1);
    }
    return array[1];
}

/* Ejercicio 5 p9 */

bool buscarAux(T array, uint n, uint pos, int dato){
    if(pos > n){
        return false;
    }else if(array[pos] > dato){
        return false;
    }else{
        return (array[pos] == dato || buscarAux(array, n, pos * 2, dato) || buscarAux(array, n, pos * 2 + 1, dato));
    }
}

bool buscar(T array, int dato, uint n){
    return buscarAux(array, n, 1, dato);
}