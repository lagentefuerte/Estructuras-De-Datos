//
// Created by famil on 3/17/2022.
//

#ifndef UNTITLED67_TELEMENTO_H
#define UNTITLED67_TELEMENTO_H

#include <stdio.h>
#include <string.h>

typedef struct
{
    char name [256];
    int dinero;

}TElemento;

void crearElemento (TElemento * e, char name [256], int dinero);
void mostrarElemento(TElemento* e);
void asignarElemento(TElemento* orig, TElemento* dest);
int igualesElemento(TElemento* e1, TElemento* e2);
void incrementarElemento (TElemento * e, int incremento);

#endif //UNTITLED67_TELEMENTO_H
