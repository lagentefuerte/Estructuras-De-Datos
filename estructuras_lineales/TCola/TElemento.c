//
// Created by famil on 3/17/2022.
//

#include "TElemento.h"

void crearElemento (TElemento * e, char name [256], int dinero)
{
    strcpy(e->name, name);
    e->dinero = dinero;
}
void mostrarElemento (TElemento * e)
{
    printf("%s %d\n", e->name, e->dinero);
}
int igualesElemento (TElemento * e1, TElemento * e2)
{
    return strcmp(e1->name, e2->name) == 0 && e1->dinero == e2->dinero;
}

void asignarElemento (TElemento * orig, TElemento * dest)
{
    *orig = *dest;
}

void incrementarElemento (TElemento * e, int incremento)
{
    e->dinero += incremento;
}
