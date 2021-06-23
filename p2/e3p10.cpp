/* e3p10 Empleados */

struct nodohash{
    char* nombre;
    int numeremp;
    int numerSsoc;
    nodohash* sig;
};

struct multiemp{
    nodohash** escala;
    int topeemp;
    nodohash** hashemp;
};

typedef multiemp * Temp;

Temp crearestructemp(int tope){
    Temp newme = new multiemp;
    newme->escala = new nodohash[tope];
    newme->hashemp = new nodohash[tope];
    newme->hashemp = 0;
    for(int i = 0; i <= tope; i++){
        newme->escala[i] = NULL;
        newme->hashemp[i] = NULL;
    }
    return newme;
}

void insertar(Temp &e, char* nombre, int numemp, int numSoc){
    nodohash* aux = new nodohash;
    aux->nombre = nombre;
    aux->numeremp = numemp;
    aux->numerSsoc = numSoc;
    aux->sig = e->hashemp[hash(nombre) % e->topeemp];
    e->hashemp[hash(nombre) % e->topeemp] = aux;
    insertarenordenescala(aux, e->escala);
}

void imprimir(Temp &e, char* nombre){
    posicion = hash(nombre) % e->topeemp;
    nodohash* aux = e->hashemp[posicion];
    while(aux != NULL && !strcmp(aux->nombre, nombre)){
        aux = aux->sig;
    }
    if(aux != NULL){
        printf('Su numero de seguridad social es: ', aux->numerSsoc);
        printf('Su numero de empleado es: ', aux->numeremp);
    }
}

