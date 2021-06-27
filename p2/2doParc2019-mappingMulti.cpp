/* 2do Parcial 2019 e3 */

struct par{
    int valor;
    string clave;
};

struct nodotabla{
    par asoc;
    nodotabla *sig;
};

typedef nodotabla * ListPares;

struct _rep_mapp{
    int max;
    ListPares *hash;
    nodotabla **aux;
};

typedef _rep_mapp * Tmap;

int str_a_num(string s, int n); // de la letra

void insertaralmapp(Tmap &mp, int valor, string clave){
    par *aux = new par;
    aux->valor = valor;
    aux->clave = clave;
    nodotabla *newnod = new nodotabla;
    newnod->asoc = aux;
    newnod->sig = mp->hash[str_a_num(clave, valor) % mp->max];
    mp->hash[str_a_num(clave, valor) % mp->max] = newnod;
    mp->aux[valor] = newnod; 
}

void interccambioenmap(int x, int y, Tmap &mp){
    string aux = mp->aux[x]->asoc->clave;
    mp->aux[x]->asoc->clave = mp->aux[y]->asoc->clave;
    mp->aux[y]->asoc->clave = aux;
};