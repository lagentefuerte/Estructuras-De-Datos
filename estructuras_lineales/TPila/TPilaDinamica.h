//
// Created by famil on 3/10/2022.
//

#ifndef UNTITLED65_TPILADINAMICA_H
#define UNTITLED65_TPILADINAMICA_H

#include "TElemento.h"

typedef struct Nodo
{
    struct Nodo * ant;
    Telemento info;
} TNodo;

typedef TNodo * TLinkedStack;

void crearPilaVacia (TLinkedStack *a);
int esPilaVacia (TLinkedStack * a);
void apilar (Telemento* e, TLinkedStack * a);
void cima (Telemento * e, TLinkedStack * a);
void desapilar (TLinkedStack * a);
void copiarpila (TLinkedStack * orig, TLinkedStack * dest);
void destruirPila (TLinkedStack * a);

#endif //UNTITLED65_TPILADINAMICA_H
