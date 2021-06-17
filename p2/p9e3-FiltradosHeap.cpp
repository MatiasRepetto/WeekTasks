/* Filtrado Ascendente y Descendente p9 */

/* Parte a) y b) */

void filtradoascendenteIter(T *arreglo, uint pos){
    T swapx = arreglo[pos];
    while(pos > 1 && arreglo[pos/2] > swapx){
        arreglo[pos] = arreglo[pos/2];
        pos = (pos / 2);
    }
    arreglo[pos] = swapx;
}

void filtradoAscRec(T *arreglo, uint pos){
    if(pos > 1 && arreglo[pos/2] > arreglo[pos]){
        T swapx = arreglo[pos];
        arreglo[pos] = arreglo[pos/2];
        arreglo[pos/2] = swapx;
        filtradoAscRec (arreglo, pos/2);
    }
}

void filtradoDescIter(T *arreglo, uint N, uint pos){
    T swapx = arreglo[pos];
    while(pos*2 < N){
        uint hijo = pos*2;
        if(((hijo + 1) <= N) && arreglo[hijo] > arreglo[hijo + 1]){
            hijo = hijo + 1;
        }
        if(arreglo[hijo] < arreglo[pos]){
            arreglo[pos] = arreglo[hijo];
            pos = hijo;
        }else{
            break;
        }
    }
    arreglo[pos] = swapx;
}

void filtradoDescRec(T *arreglo, uint N, uint pos){
    if (pos * 2 <= N){
        uint hijo = pos*2;
        if(((hijo + 1) <= N) && arreglo[hijo] > arreglo[hijo + 1]){
            hijo = hijo + 1;
        }
        if(arreglo[hijo] < arreglo[pos]){
            T swapx = arreglo[pos];
            arreglo[pos] = arreglo[hijo];
            arreglo[hijo] = swapx;
            filtradoDescRec(arreglo, hijo);
        }
    }
}
