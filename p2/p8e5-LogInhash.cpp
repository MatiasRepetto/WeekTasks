/* Sistema LogIn con mapping de hash */

#include <cstring>
#include <iostream>

struct nodomap{
    char* elem;
    char* r;
    nodomap* sig;
};

struct _rep_map{
    nodomap** hash;
    int tamaMap;
    int elemMap;
};

typedef _rep_map * Tmap;

int hash(char* c, unsigned int N){
    unsigned long res;
    for(unsigned int i = 0; i<strlen(c); i++){
        res = res * 28 + res + c[i];
    }
    return res;
}

Tmap crearMap(int N){
    Tmap nMap = new _rep_map;
    nMap->tamaMap = N;
    nMap->hash = new nodomap[N];
    nMap->elemMap = 0;
    for (int i = 0; i < nMap->tamaMap; i++){
        nMap->hash[i] = NULL;
    }
    return nMap;
}

void insertar(char* ch, char* re, Tmap & m){
    nodomap* aux = new nodomap;
    aux->elem = ch;
    aux->r = re;
    aux->sig = m->hash[hash(ch)];
    m->hash[hash(ch)] = aux;
    m->elemMap++;
}

bool estaDefinidoD(char* ch, Tmap m){
    bool encontre = false;
    nodomap* aux = m->hash[hash(ch)];
    while(aux != NULL && !encontre){
        if (strcmp(ch, aux->elem)){
            encontre = true;
        }
        aux = aux->sig;
    }
    return aux == NULL;
}

char recuperarvalor(char* ch, Tmap m){
    char auxi;
    if(estaDefinidoD(ch, m)){
        nodomap* aux = m->hash[hash(ch)];
        while(!strcmp(aux->elem, ch)){
            aux = aux->sig;
        }
        auxi = aux->r;
    }
    return auxi;
}

/* Main */

int main(){
    char pass, usr;
    Tmap aux;
    printf("ingrese su Usuario");
    scanf("%c", &usr);
    printf("ingrese su Password");
    scanf("%c", &pass);
    aux = crearMap(13);
    insertar(usr, pass, aux);
    printf("ingrese su Usuario");
    scanf("%c", &usr);
    printf("ingrese su Password");
    scanf("%c", &pass);
    if (strcmp(recuperarvalor(usr, aux), pass)){
        printf("exito");
    }else{
        printf("error");
    }
}