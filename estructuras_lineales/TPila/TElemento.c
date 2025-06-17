//
// Created by famil on 3/10/2022.
//
#include "TElemento.h"

void crearElemento (Telemento * e, int i)
{
    *e = i;
}
void mostrarElemento (Telemento * e)
{
    printf("%d", *e);
}
int igualesElemento (Telemento * e1, Telemento * e2)
{
    return *e1 == *e2;
}

void asignarElemento (Telemento * orig, Telemento * dest)
{
    *orig = *dest;
}
