/* Parcial 2016 e1 */

struct nodo{
    int dato;
    nodo *izq, *der;
};

typedef nodo * AB;

// Usaremos TAD Cola prioridad no acotada y asumiremos que ya esta implementado y efectivo O(1) peor caso 

// Crea cola prioridad
Cola crearCola();

// Insearta a el final de la cola C
void insertar(AB a, Cola &c);

// Retorna true si esta vacia la cola y false si no lo esta
bool esvaciacola(Cola c);

// devuelve el elemento con mayor prioridad en la cola !esvaciacola
AB priemeroAB(Cola c);

// borra el elemento con mayor prioridad en la cola !esvaciacola
void borrarprimerAB(Cola &c);

// Libera la memoria ocupadda por la cola
void liberarcola(Cola &c);

/* Dado un AB imprime sus elementos de izquierda a derecha y por niveles de arriba hacia abajo . Los elementos se deben imprimir en un solo renglon
separados por un espacio sin incluir los elementos de las hojas de el arbol, O(n) peor caso */
void internosPorNiveles(AB &ab){
    AB auxab = ab;
    Cola auxc = crearCola();
    if(ab != NULL){
        insertar(ab, auxc);
    }
    while(!esvaciacola(auxc)){
        auxab = priemeroAB(auxc);
        borrarprimerAB(auxc);
        if(auxab->izq != NULL || auxab->der != NULL){
            printf("%i ", auxab->dato);
            if(auxab->izq != NULL){
                insertar(auxab->izq, auxc);
            }
            if(auxab->der != NULL){
                insertar(auxab->der, auxc);
            }
        }
    }
    liberarcola(auxc);
}