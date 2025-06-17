//
// Created by famil on 3/24/2022.
//

#ifndef UNTITLED68_TCONJUNTODINAMICO_H
#define UNTITLED68_TCONJUNTODINAMICO_H

#include "TElemento.h"
#include <stdlib.h>
#include <time.h>

typedef struct Nodo
{
    struct Nodo * sig;
    TElemento info;
} TNodoSet;

typedef TNodoSet * set;

void crearConjuntoVacio(set*a);
void mostrarConjunto(set*a);
void poner(TElemento*e,set*a);
int quitar(TElemento*e,set*a);
int elegir(TElemento*e,set* a);
void interseccion(set* a1,set* a2,set* i);
void diferencia(set* a1,set* a2,set* d);
void unir(set* a1,set* a2,set* u);
int esSubconjunto(set* a1,set* a2);
int pertenece(TElemento*e,set* a);
int esConjuntoVacio(set* a);
int cardinal(set* a);
void asignarConjunto(set* original,set* copia);
int igualConjunto(set* uno,set*dos);
void destruirConjunto(set* a);

#endif //UNTITLED68_TCONJUNTODINAMICO_H
