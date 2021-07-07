Tabla crearT ( unsigned int N ) ;
// Crea una tabla vacía

void AsociarT ( string nom , unsigned int tel , Tabla & t ) ;
// Asocia el tel é fono tel al nombre nom en la Tabla t
// Si ya tenía asociado un tel éfono , se modifica

bool estaNomT ( string nom , Tabla t ) ;
// Devuelve verdadero si el nombre nom tiene un tel é fono asociado

unsigned int darTelT ( string nom , Tabla t ) ;
// Devuelve el tel é fono asociado al nombre nom
// Precond : el nombre nom tiene un telé fono asociado

void eliminarT ( string nom , Tabla t ) ;
// Elimina la asociaci ón del nombre nom
// Precond : el nombre nom tiene un telé fono asociado

// (a)

struct nodohash{
    uint tel;
    string *nom;
    nodohash *sig;
};

struct _rep_hash{
    nodohash **map;
    int tope;
    int cantelements;
};

typedef _rep_hash * Tabla;

Tabla crearT(uint N){
    Tabla newt = new _rep_hash;
    newt->map = new *nodohash[N];
    for(int i = 0, i<=N; i++){
        newt->map[i] = NULL;
    }
    newt->tope = N;
    newt->cantelements = 0;
    return newt;
}

void AsociarT(string nom, uint tel, Tabla &t){
    nodohash *aux = new nodohash;
    aux->tel = tel;
    aux->nom = nom;
    uint direccion = h(nom)%t->tope;
    if(!estaNomT(nom , t)){
        aux->sig = t->map[direccion];
        t->map[direccion] = aux;
        t->cantelements++;
    }else{
        nodohash aux2 = t->map[direccion];
        while(!strcmp(aux2->nom, nom)){
            aux2 = aux2->sig;
        }
        aux2->tel = tel;
    }
}