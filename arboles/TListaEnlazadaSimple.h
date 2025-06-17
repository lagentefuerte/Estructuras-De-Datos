//
// Created by alfon on 09/03/2021.
//

#ifndef LISTAENLAZADASIMPLE_TLISTAENLAZADASIMPLE_H
#define LISTAENLAZADASIMPLE_TLISTAENLAZADASIMPLE_H
#include "TElemento.h"

typedef struct Nodo{
    TElemento info;
    struct Nodo* sig;
}TNodo;

typedef TNodo* TLista;


void crearListaVacia (TLista* l);
void mostrarLista (TLista* l);
void insertarLista (TElemento* e, TLista* l);
void insertarFinalLista (TElemento* e, TLista* l);
int eliminarLista (TElemento* e, TLista* l);
void primeroLista(TElemento* e, TLista* l);
void restoLista (TLista* l);
void ultimoLista(TElemento* e, TLista* l);
void concatenarLista (TLista* l1, TLista* l2);
int contieneLista (TElemento* e, TLista* l);
int esListaVacia (TLista* l);
int longitudLista (TLista* l);
int igualLista (TLista* l1, TLista* l2);
void asignarLista (TLista* original, TLista* copia);
void destruirLista(TLista* l);



#endif //LISTAENLAZADASIMPLE_TLISTAENLAZADASIMPLE_H
