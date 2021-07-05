/* exm 2020 feb */

// Ejercicio 3 

// Tad tabla con binario

// Especificacion

// Crea un Mapping no acotado y vacio
Tmap creoTabla();

// Dado una preimagen x y una imagen y las inserta a la tabla siguiendo el esquema de Arbol binario
void insertar(int x, int y, Tmap &mp);

// Retorna true si la tabla es vacia y false de lo contrario 
bool esTablaVacia(Tmap mp);

// Devuelve true si existe imagen de X en la tabla false de lo contrario pre: !esTablaVacia
bool estaDefinida(int x, Tmap mp);

// recupera el valor de la imagen de x en la tabla pre: estaDefinida
int recuperar(int x, Tmap mp);

// Borra el elemento de preimagen x pre : !esTablaVacia
void borrar(Tmap &mp);

// Devuelve true si solo si la tabla es inyectiva y false de lo contrario
bool esInyectiva(Tmap mp);

struct nodotabla{
    int x;
    int y;
    nodotabla *izq, *der;
};

typedef nodotabla * Tmap;

// Implementamos insertar y esInyectiva

// Insertar
void insertar(int x, int y, Tmap &mp){
    nodotabla *newnod = new nodotabla;
    newnod->x = x;
    newnod->y = y;
    newnod->izq = NULL;
    newnod->der = NULL;
    if(esTablaVacia){
        mp = newnod;
    }else if(x < mp->x){
        insertar(x, y, mp->izq);
    }else if(x > mp->x){
        insertar(x, y, mp->der);
    }
}

// esInyectiva
bool esInyectiva(Tmap mp){
    bool aux;
    if(mp->y == mp->izq->y || mp->y == mp->der->y || mp->der->y == mp->izq->y){
        aux = false;
    }
    return (aux && esInyectiva(mp->izq) && esInyectiva(mp->der));
}






