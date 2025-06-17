//
// Created by ASUS on 3/13/2022.
//

#ifndef CIRCULARESTATICA_TLISTA_H
#define CIRCULARESTATICA_TLISTA_H

#include "TElemento.h"
#include <stdlib.h>

typedef struct Nodo{
    TElemento info;
    struct Nodo* sig;
}TNodo;

typedef TNodo * TLista;

void crearListaVacia(TLista * l);
void mostrarLista(TLista * l);
void insertarLista(TElemento* e, TLista * l);
void insertarFinalLista(TElemento* e, TLista * l);
int eliminarLista(TElemento* e, TLista * l);
void primeroLista(TLista * l, TElemento* e);
void restoLista(TLista* l);
void ultimoLista(TLista* l, TElemento* e);
void concatenarLista(TLista* l1, TLista* l2);
int contieneLista(TElemento* e, TLista* l);
int esListaVacia(TLista* l);
int longitudLista(TLista* l);
int igualLista(TLista* l1, TLista* l2);
void asignarLista(TLista* orig, TLista* dest);
void destruirLista(TLista* l);

#endif //CIRCULARESTATICA_TLISTA_H
