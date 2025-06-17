//
// Created by famil on 3/3/2022.
//

#ifndef UNTITLED63_LISTACIRCULARESTATICA_H
#define UNTITLED63_LISTACIRCULARESTATICA_H

#define DIM 100
#include "TElemento.h"

typedef struct
{
    Telemento almacen[DIM]; // se pueden almacenar solo 99 elementos ya que inicio siempre va a apuntar a un elemento no valido
    int inicio;
    int final;
    int ocupadas;
}TLista;

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

#endif //UNTITLED63_LISTACIRCULARESTATICA_H
