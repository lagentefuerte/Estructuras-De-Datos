//
// Created by famil on 3/29/2022.
//

#ifndef ARBOLES_ARBOLDINAMICO_H
#define ARBOLES_ARBOLDINAMICO_H

#include "TElemento.h"
#include "TListaEnlazadaSimple.h"

typedef struct NodeTree{
    TElemento info;
    struct NodeTree* left;
    struct NodeTree* right;
}TNodeTree;

typedef TNodeTree* TBinaryTree;

void crearArbolVacio(TBinaryTree* a);
void crearArbol(TBinaryTree* a,TBinaryTree* izq,TBinaryTree* der,TElemento* e);
void devolverRaiz(TBinaryTree* a, TElemento* r);
void devolverHijoIzquierdo(TBinaryTree* a, TBinaryTree* r);
void devolverHijoDerecho(TBinaryTree* a, TBinaryTree* r);
void destruirArbol(TBinaryTree* a);
void asignarArbol(TBinaryTree* original, TBinaryTree* copia);
int igualArbol(TBinaryTree* uno, TBinaryTree* dos);
int esArbolVacio(TBinaryTree* a);
int numeroNodos (TBinaryTree *a);
int numeroHojas (TBinaryTree* a);
int altura (TBinaryTree * a);
void recorridoPreorden (TBinaryTree *a, TLista * r);
void recorridoInorden (TBinaryTree *a, TLista * r);
void recorridoPostorden (TBinaryTree *a, TLista * r);
int nodoNivel(TBinaryTree* a, TElemento* e, int i);
int sonHermanos(TBinaryTree* a, TElemento* e1, TElemento* e2);
void imagenEspecular (TBinaryTree* a);

#endif //ARBOLES_ARBOLDINAMICO_H
