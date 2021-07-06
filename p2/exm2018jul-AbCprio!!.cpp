/* exm 2018 jul */
/*  (a) Defina la estructura de datos vista en el curso para la representación de árboles binarios de enteros AB.
    (b) Especifique completamente el TAD Cola de AB (con pre y post condiciones).
    (c) Suponiendo que el árbol no cumple ninguna propiedad de orden y que puede contener elementos
    repetidos, se pide implementar una operación nivelSumaS que recibe un un árbol a y devuelve el nivel
    hasta el cual se deben sumar los elementos del árbol desde la raiz, para alcanzar un valor dado S. Para
    el árbol vacío el resultado debe ser -1 y el nivel de la raíz se considera que es el 0.
    int nivelSumaS ( AB & a , int S ) ; */

// (a)

struct nodoAB{
    int dato;
    nodoAB *izq, *der;
};

typedef nodoAB * AB;

// (b)

// Crea una cola vacia de elementos de tipo AB
Cprio crearCpAB();

// Inserta un elemento de tipo AB a la cola siguiendo la prioridad prio correspondiente
void insertarCpAB(Cprio &cp, int prio , AB a);

// Retorna true si la cola de prioridad es vacia y false de lo contrario
bool esVaciaCpAB(Cprio cp);

// Retorna el Ab del elemento de mayopr prioridad pre: !esVaciaCpAB
AB retornarCpAB(Cprio cp);

// elimina el elemento de la cola de mayor prioridad pre: !esVaciaCpAB
void eliminarCpAB(Cprio &cp);

// libera la memoria asociada a la cola de prioridad 
void liberarCpAB(Cprio &cp);

// (c)
int nivelSumaS ( AB & a , int S ) {
    int result = -1;
    bool termine = false ;
    if ( a != NULL ) {
        Cola cAux = crearCola () ;
        encolar ( cAux , NULL ) ;
        encolar ( cAux , a ) ;
        while (! esVacia ( cAux ) && ! termine ) {
            AB frenteAB = frente ( cAux ) ;
            desencolar ( cAux ) ;
            if ( frenteAB == NULL ) {
                result ++;
                encolar ( cAux , NULL ) ;
            } else {
                S = S - frenteAB - > valor ;
                if ( S <= 0) {
                    termine = true ;
                } else {
                    encolar (a - > izq , cAux ) ;
                    encolar (a - > der , cAux ) ;
                };
            };
        };
        destruirCola ( cAux ) ;
    };
    return result ;
}











