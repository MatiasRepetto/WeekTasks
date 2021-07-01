/* TAD Multiconjunto */

// Crea un multiconjunto vacio.
Tmset crearMultiSet();

// Ingresa un elemento al multiconjunto.
void insetarMultiSet(int e, Tmset &ms);

// Devulve true si el multiconjunto es vacio y false si no lo esta.
bool esvacioMultiSet(Tmset ms);

// Nos da la cantidad de ocurrencias de un elemento x en el multiconjunto d pre: !esvacioMultiSet.
int cantidadocurrenciasMultiSet(int e, Tmset ms);

// Borra una de las ocurrencias del elemento e en el multiconjunto ms. pre: !esvacioMultiSet.
void borrarMultiSet(int e, Tmset &ms);

// destruye al multiconjunto y Libera la memoria asociada al mismo.
void liberarMultiSet(Tmset &ms);

//Posibles estructuras para implementar Multiset

// Arreglo booleanos para Multiset ACOTADOS!!
struct nodoset{
    int *canrdinalEsta; // Almacena la cantidad de veces que se repite el elemento
    int tope;
};

typedef nodoset * Tmset;

// representacion por AVL para Multiset no acotados {Recomendado} (log2 (n)) pc

struct nodoavl{
    int dato;
    nodoavl *izq, *der;
    int alturaAvl;
};

typedef nodoavl * Tmset;