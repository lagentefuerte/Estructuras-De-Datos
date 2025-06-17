#include <stdio.h>
#include <string.h>
#include "TElemento1.h"


void mostrarElemento1 (TElemento1* t){
    printf("[%d , %d] ",t->origen,t->destino);
}

void asignarElemento1(TElemento1* original, TElemento1* copia){
    copia->destino=original->destino;
    copia->origen=original->origen;
}

int igualElemento1(TElemento1* uno, TElemento1* dos){
    return ((uno->origen==dos->origen)&&(dos->destino==uno->destino)||(uno->origen==dos->destino)&&(dos->origen==uno->destino));//al no ser dirigido, es el mismo elemento el (4,7) que (7,4)
}

void crearElemento1(int o, int d, TElemento1* e){
    e->destino=d;
    e->origen=o;
} 
