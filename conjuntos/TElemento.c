//
// Created by famil on 3/22/2022.
//

#include "TElemento.h"

void crearElemento(TElemento* e, int i) {
    *e = i;
}

void mostrarElemento(TElemento* e) {
    printf("%d", *e);
}

void asignarElemento(TElemento* orig, TElemento* dest) {
    *dest = *orig;
}

int igualesElemento(TElemento* e1, TElemento* e2) {
    return *e1 == *e2;
}

int indice (TElemento * e)
{
    return *e;
}