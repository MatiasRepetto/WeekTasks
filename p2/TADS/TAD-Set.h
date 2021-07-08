/* TAD Set */

// Construye un un conjunto C vacio.
Tset crearConjunto(int M);

// Nos informa si el conjunto tiene el maximo de elementos.
bool esllenoconjunto(Tset s); // solo para definicion de set acotado

// Ingresa un elemento al set si el elemento no pertenece aun !pertenece(e, s).
void ingresarenset(int e, Tset &s);

// Retorna si nuestro conjunto esta vacio.
bool esVacioConjunto(Tset s);

// Elimina del conjunto el elemento especificado, pre: !esVacioConjunto();
void eliminarenset(int e, Tset &s);

// Elimina el conjunto entero y libera la memoria del mismo.
void liberarset(Tset &s);

// Devuelve un set con la disyuncion de dos conjuntos c1 y c2
Tset disyuncion(Tset c1, Tset c2);

// Devuelve un set con la conjuncion de dos cunjuntos c1 y c2
Tset conjuncion(Tset c1, Tset c2);

// Devuelve un set con la diferencia c1 - c2
Tset diferencia(Tset c1, Tset c2);

// Posibles implementaciones de estructura.

// Arreglo booleanos para set ACOTADOS!!
struct nodoset{
    bool *esta;
    int tope;
};

typedef nodoset * Tset;

// representacion por AVL para set no acotados {Recomendado} (log2 (n)) pc

struct nodoavl{
    int dato;
    nodoavl *izq, *der;
    int alturaAvl;
};

typedef nodoavl * Tset;
