//
// Created by famil on 3/1/2022.
//

#ifndef UNTITLED62_TLISTADOBLEMENTEENLAZADA_H
#define UNTITLED62_TLISTADOBLEMENTEENLAZADA_H

#include "TElemento.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo {
    Telemento info;
    struct Nodo*sig;
    struct Nodo*ant;
}TNodo;

typedef TNodo *TLista;

void crearListaVacia(TLista * l);
int esListaVacia(TLista* l);
int longitudLista(TLista* l);
void primeroLista(TLista * l, Telemento* e);
void restoLista(TLista* l);
void ultimoLista(TLista* l, Telemento* e);
void destruirLista(TLista* l);
void mostrarLista(TLista * l);
void insertarLista(Telemento* e, TLista * l);
void asignarLista(TLista* orig, TLista* dest);
void insertarFinalLista(Telemento* e, TLista * l);
int contieneLista(Telemento* e, TLista* l);
int igualLista(TLista* l1, TLista* l2);
int eliminarLista(Telemento* e, TLista * l);
void concatenarLista(TLista* l1, TLista* l2);

#endif //UNTITLED62_TLISTADOBLEMENTEENLAZADA_H
