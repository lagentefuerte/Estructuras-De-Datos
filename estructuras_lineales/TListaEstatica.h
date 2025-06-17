//
// Created by franciscojose.garcia on 17/02/2022.
//

#ifndef LISTAESTATICACLASE_TLISTAESTATICA_H
#define LISTAESTATICACLASE_TLISTAESTATICA_H

#include <stdio.h>
#include "TElemento.h"

#define DIM 100

typedef struct {
    TElemento almacen[DIM];
    int indice;
} TLista;

void crearListaVacia(TLista * l);
int esListaVacia(TLista* l);
int longitudLista(TLista* l);
void primeroLista(TLista * l, TElemento* e);
void restoLista(TLista* l);
void ultimoLista(TLista* l, TElemento* e);
void destruirLista(TLista* l);
void mostrarLista(TLista * l);
void insertarLista(TElemento* e, TLista * l);
void asignarLista(TLista* orig, TLista* dest);
void insertarFinalLista(TElemento* e, TLista * l);
int contieneLista(TElemento* e, TLista* l);
int igualLista(TLista* l1, TLista* l2);
int eliminarLista(TElemento* e, TLista * l);
void concatenarLista(TLista* l1, TLista* l2);

#endif //LISTAESTATICACLASE_TLISTAESTATICA_H
