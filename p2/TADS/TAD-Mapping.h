/* TAD Tabla o Mapping */

// Crea un Mapping vacio de tamaño esperable N.
Tmap crearMap(int N);

// inserta una correspondencia (d,r) en un mapping t. Si d está definida en t (tiene imagen), actualiza sucorrespondencia con r.
void insetarenMap(int d, int r, Tmap &mp);

// Devulve true si el Mapping es vacio y false si no lo esta.
bool esvacioMap(Tmap mp);

// devuelve true si un valor e tiene imagen en el mapping mp.
bool imagenEnMap(int e, Tmap mp);

// Devuelve una correspondencia de e en el mapping mp pre: imagenEnMap.
int obtenerimagenMap(int e, Tmap mp);

// Borra una de las correspondencias del elemento e en el mapping mp. pre: !esvacioMap.
void borrarMultiSet(int e, Tmap &mp);

// destruye el mapping y Libera la memoria asociada al mismo.
void liberarMap(Tmap &mp);

//Posibles estructuras para implementar Mapping

// Recomendada HASH pre: disponer de una funcion de hashing que tenga buena distribucion par obtener promedio 0(1) en peores casos ((ACOTADO))

// Hash 

struct nodohash{
    int imagen;
    nodohash *sig;
};

struct _rep_Mapping{
    nodohash **Map;
    int cantidadelem;
    int tope;
};

typedef _rep_Mapping * Tmap;