#define Dim 10
#include "TElemento.h"
#include "TClave.h"
//#include "TListaEnlazadaSimple.h"
#include "TConjuntoDinamico.h"
#include "TConjuntoDinamico1.h"
#include "TConjuntoDinamico2.h"


typedef struct NodoH{
    TElemento e; // entrada
    int disponible;//0 si esta ocupado,1 libre, 2 si ha estado ocupado
}TNodoH;

typedef TNodoH Mapa[Dim];




void crearMapaVacioDA (Mapa* a);
void mostrarMapaDA (Mapa* a);
void ponerMapaDA (TClave* c, TValor* e, Mapa* a);
void devolverDA (TClave* c, TValor* v, Mapa* a);
int esMapaVacioDA (Mapa* a);
int sizeMapaDA (Mapa* a);
int quitarMapaDA (TClave* c, Mapa* a);
void conjuntoEntradasDA (set* e, Mapa* h);
void conjuntoClavesDA (set1* e, Mapa* h);
void conjuntoValoresDA (set2* e, Mapa* h);
void asignarMapaDA(Mapa* original, Mapa* copia);
void destruirMapaDA(Mapa* a);