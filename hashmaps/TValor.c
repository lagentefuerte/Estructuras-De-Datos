#include <stdio.h>
#include <string.h>
#include "TValor.h"


void mostrarValor (TValor* t){
    printf("%s ",*t);

}

void asignarValor(TValor* original, TValor* copia){
    strcpy (*copia,*original);
}

int igualValor(TValor* uno, TValor* dos){
    return  (strcmp(*uno,*dos)==0);
}

void crearValor(char* c, TValor* e){
    strcpy (*e,c);
}
int mayorValor(TValor* uno, TValor* dos){
    return  (strcmp(*uno,*dos)>0);
}