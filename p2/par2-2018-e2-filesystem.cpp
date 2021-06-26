/* Ejercicoo parcial 2018 file system */

//crea cola prioridad no acotada
Tcola Crearcolaprioridad();
// encola elementos del arbol de tipo FS 
void encolarcolaprioridad(Tcola &cp, FS elem);
// desencola el elemento mas viejo
void desencolarcolaprio(Tcola &cp);
// nos devuelve el elemento mas viejo
FS frentecola(Tcola cp);
// nos dice si la cola es vacia
bool esvaciacolaprio(Tcola cp);
// destrulle la cola de prio
void destruircolaprio(Tcola &cp);

struct nodoFS{
    char * nombre;
    Fecha* fecha;
    nodoFS *ph, *sh;
};

typedef nodoFS * FS;

Fecha masCercano(FS t, char * nomDir){
    Fecha resultado = NULL;
    if(t != NULL){
        Tcola auxcp = Crearcolaprioridad();
        encolarcolaprioridad(auxcp, t);
        while(!esvaciacolaprio(auxcp)){
            FS prio = frentecola(auxcp);
            desencolarcolaprio(auxcp);
            if(sonIguales(prio->nombre, nomDir)){
                resultado = prio->nombre;
                while(!esvaciacolaprio(auxcp)){
                    desencolarcolaprio(auxcp);
                }else{
                    FS prioaux = prio->ph;
                    while(prioaux != NULL){
                        encolarcolaprioridad(auxcp, prioaux)
                        prioaux = prioaux->sh;
                        resultado = masCercano(prioaux, nomDir);
                    }
                }
            }
        }
        destruircolaprio(auxcp);
    }
    return resultado;
}

