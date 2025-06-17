#define Dim 10
#include "TElemento.h"
#include "TClave.h"
#include "TListaEnlazadaSimple.h"
#include "TConjuntoDinamico.h"
#include "TConjuntoDinamico1.h"
#include "TConjuntoDinamico2.h"

typedef TLista Mapa[Dim];

void crearMapaVacio (Mapa* a);
void mostrarMapa (Mapa* a);
void ponerMapa (TClave* c, TValor* e, Mapa* a);
void devolver (TClave* c, TValor* v, Mapa* a);
int esMapaVacio (Mapa* a);
int sizeMapa (Mapa* a);
int quitarMapa (TClave* c, Mapa* a);
void conjuntoEntradas (set* e, Mapa* h);
void conjuntoClaves (set1* e, Mapa* h);
void conjuntoValores (set2* e, Mapa* h);
void asignarMapa(Mapa* original, Mapa* copia);
void destruirMapa(Mapa* a);