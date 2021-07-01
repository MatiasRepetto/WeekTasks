/* TAD Diccionario */

// Contruye un diccionario vacio
Tdic crearDiccionario();

// Agrega un elemento al diccionario si es que este no se encuentra en el mismo.
void ingresarADic(int e, Tdic &d);

// Retorna true si el diccionario esta vacio de lo contrario retorna false.
bool esVacioDic(Tdic d);

// Retorna true si el elemento x esta en el diccionario, false de lo contrario.
bool estaenDic(int x, Tdic d);

// Borra el elemento especificado de el diccionario pre: estaenDic.
void eliminarADic(int e, Tdic &d);

// Libera la memoria asociada al diccionario.
void liberarDic(Tdic &d);


// Posibles estructuras para implementacion

// Arreglo booleanos para diccionarios ACOTADOS !!
struct nodoset{
    bool *esta;
    int tope;
};

typedef nodoset * Tdic;

// representacion por AVL para Diccionarios no acotados {Recomendada} 0(log2 (n)) pc

struct nodoavl{
    int dato;
    nodoavl *izq, *der;
    int alturaAvl;
};

typedef nodoavl * Tdic;