//
// Created by famil on 3/22/2022.
//

#ifndef ARBOLES_TELEMENTO_H
#define ARBOLES_TELEMENTO_H

#include <stdio.h>

typedef char TElemento;

void crearElemento(TElemento* e, char i);
void mostrarElemento(TElemento* e);
void asignarElemento(TElemento* orig, TElemento* dest);
int igualesElemento(TElemento* e1, TElemento* e2);
int mayorQue (TElemento* e1, TElemento* e2);

#endif //ARBOLES_TELEMENTO_H