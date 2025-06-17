// Created by famil on 3/17/2022.
//

#ifndef UNTITLED67_TCOLA_H
#define UNTITLED67_TCOLA_H

#include "TElemento.h"

#include <stdlib.h>

typedef struct Nodo{
    struct Nodo * sig;
    TElemento info;
} TNodo;

typedef struct
{
    TNodo * ini;
    TNodo * final;
    int longitud;
} TCola;

void crearColaVacia(TCola * c);
void insertarFinalLista(TElemento* e, TCola * c);
void primeroLista(TCola * c, TElemento* e);
void restoLista(TCola * c);
int esListaVacia(TCola * c);
int longitudLista(TCola * c);
void asignarLista(TCola * orig, TCola * dest);
void destruirLista(TCola * c);

#endif //UNTITLED67_TCOLA_H
