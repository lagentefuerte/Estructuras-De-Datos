#include <stdio.h>
#include <string.h>
#include "TElemento.h"


void mostrarElemento (TElemento* t){
    printf(" %d ",*t);
}

void asignarElemento(TElemento* original, TElemento* copia){
    *copia=*original;
}

int igualElemento(TElemento* uno, TElemento* dos){
    return (*uno)==(*dos);
}

void crearElemento(int i, TElemento* e){
    (*e)=i;
} 
int esMayor(TElemento* lhs, TElemento* rhs){
    return (*lhs)>(*rhs);
}
