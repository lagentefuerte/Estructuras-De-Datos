#ifndef ConjuntoENLAZADASIMPLE_set2ENLAZADASIMPLE_H
#define ConjuntoENLAZADASIMPLE_set2ENLAZADASIMPLE_H
#include "TValor.h"



typedef struct NodoC2{
    TValor info;
    struct NodoC2* sig;
}TNodoConjunto2;

typedef TNodoConjunto2 * set2;


void crearConjuntoVacio2 (set2* l);
void mostrarConjunto2 (set2* l);
void poner2 (TValor* e, set2* l);
int quitar2 (TValor* e, set2* l);
int esConjuntoVacio2 (set2* l);
int cardinal2 (set2* l);
int pertenece2 (TValor* e, set2* l);
void elegir2 (TValor* e, set2* l);

void unir2 (set2* l1, set2* l2, set2* u);
void interseccion2 (set2* l1, set2* l2, set2* i);
void diferencia2 (set2* l1, set2* l2, set2* d);
int esSubconjunto2 (set2* l1, set2* l2);



int igualConjunto2 (set2* l1, set2* l2);
void asignarConjunto2 (set2* original, set2* copia);
void destruirConjunto2(set2* l);



#endif //ConjuntoENLAZADASIMPLE_set2ENLAZADASIMPLE_H
