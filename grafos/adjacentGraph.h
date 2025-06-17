#include <stdio.h>
#include <stdlib.h>
#include "TElemento.h"
#include "TListaEnlazadaSimple.h"
#include "arrayset.h"


typedef struct NodoG{
    TElemento info;
    TLista adyacentes;
    struct NodoG* sig;
} TnodoG;

typedef TnodoG* TAdyacentGraph;





void crearGrafoNulo (TAdyacentGraph* a);
void insertarVertice (TElemento* e, TAdyacentGraph* a);
void insertarArista (TElemento* lhs,TElemento* rhs, TAdyacentGraph* a);
int eliminarVertice (TElemento* e, TAdyacentGraph* a);
void eliminarArista (TElemento* lhs,TElemento* rhs, TAdyacentGraph* a);
int esAdyacente(TElemento* lhs,TElemento* rhs,TAdyacentGraph* a);
int contieneVertice (TElemento* e, TAdyacentGraph* a);
int esGrafoNulo (TAdyacentGraph* a);
void listaVertices (TAdyacentGraph* a, TLista* l);
void conjuntoAristas (TAdyacentGraph* a,set* s);

void copiarG(TAdyacentGraph* original, TAdyacentGraph* copia);
void destruirG(TAdyacentGraph* a);
