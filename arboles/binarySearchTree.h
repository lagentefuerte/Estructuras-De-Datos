#include <stdio.h>
#include <stdlib.h>
#include "TElemento.h"
#include "TListaEnlazadaSimple.h"

typedef struct NodeSearchTree{
        TElemento info;
        struct NodeSearchTree* left;
        struct NodeSearchTree* right;
} TNodeSearchTree;

typedef TNodeSearchTree* TBinarySearchTree;


void crearArbolBusquedaVacio(TBinarySearchTree* a);
void insertarArbolBusqueda(TBinarySearchTree* a,TElemento* e);
int  eliminarArbolBusqueda(TBinarySearchTree* a,TElemento* e);
void devolverRaizBusqueda(TBinarySearchTree* a, TElemento* r);
void devolverHijoIzquierdoBusqueda(TBinarySearchTree* a, TBinarySearchTree* r);
void devolverHijoDerechoBusqueda(TBinarySearchTree* a, TBinarySearchTree* r);
void destruirArbolBusqueda(TBinarySearchTree* a);
void asignarArbolBusqueda(TBinarySearchTree* original, TBinarySearchTree* copia);
int igualArbolBusqueda(TBinarySearchTree* uno, TBinarySearchTree* dos);
int esArbolBusquedaVacio(TBinarySearchTree* a);
void mayorNodo(TElemento * e, TBinarySearchTree* a);
void menorNodo(TElemento * e, TBinarySearchTree* a);
int numeroNodos(TBinarySearchTree* a);
int numeroHojas(TBinarySearchTree* a);
int altura(TBinarySearchTree* a);
void preorden(TBinarySearchTree* a, TLista* r);
void inorden(TBinarySearchTree* a, TLista* r);
void postorden(TBinarySearchTree* a, TLista* r);
int contieneArbolBinarioBusqueda(TBinarySearchTree* a,TElemento* e);



