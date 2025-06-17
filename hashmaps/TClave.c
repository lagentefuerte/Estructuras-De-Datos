#include "TClave.h"
#include "string.h"
#include "stdio.h"

void crearClave (char n, TClave* e){
     *e=n;
}
void mostrarClave (TClave* e){
    printf(" %c ", *e);
}

void asignarClave(TClave* original, TClave* copia){
    *copia=*original;
}
int igualClave (TClave* uno, TClave* dos){
    return (*uno==*dos);
}
int mayorClave(TClave* uno,TClave* dos){
    return *uno>*dos;
}

int hash (TClave* c){
    return (*c);
}