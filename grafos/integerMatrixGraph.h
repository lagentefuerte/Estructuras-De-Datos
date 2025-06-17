#include <stdio.h>
#include <stdlib.h>
#include "TListaEnlazadaSimple.h"
#include "arrayset.h"
#define dim 100


typedef struct MGraph{
    int nodes[dim];
    int matrix[dim][dim];
}TMGraph;

void crearGrafoVacio (TMGraph* a);
void insertarVertice (int i, TMGraph* a);
void insertarArista (int lhs,int rhs, TMGraph* a);
int eliminarVertice (int i, TMGraph* a);
void eliminarArista (int lhs,int rhs, TMGraph* a);
int esAdyacente(int lhs,int rhs,TMGraph* a);
int contieneVertice (int i, TMGraph* a);
int esGrafoVacio (TMGraph* a);
void listaVertices (TMGraph* a, TLista* l);
void conjuntoAristas (TMGraph* a,set* s);

void copiarGrafo(TMGraph* original, TMGraph* copia);
void destruirGrafo(TMGraph* a);
int igualGrafo(TMGraph* original, TMGraph* copia);