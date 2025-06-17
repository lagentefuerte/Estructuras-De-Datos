#ifndef ConjuntoENLAZADASIMPLE_setENLAZADASIMPLE_H
#define ConjuntoENLAZADASIMPLE_setENLAZADASIMPLE_H
#include "TElemento.h"

typedef struct NodoC{
    TElemento info;
    struct NodoC* sig;
}TNodoConjunto;

typedef TNodoConjunto* set;


void crearConjuntoVacio (set* l);
void mostrarConjunto (set* l);
void poner (TElemento* e, set* l);
int quitar (TElemento* e, set* l);
int esConjuntoVacio (set* l);
int cardinal (set* l);
int pertenece (TElemento* e, set* l);
void elegir (TElemento* e, set* l);

void unir (set* l1, set* l2, set* u);
void interseccion (set* l1, set* l2, set* i);
void diferencia (set* l1, set* l2, set* d);
int esSubconjunto (set* l1, set* l2);



int igualConjunto (set* l1, set* l2);
void asignarConjunto (set* original, set* copia);
void destruirConjunto(set* l);



#endif //ConjuntoENLAZADASIMPLE_setENLAZADASIMPLE_H
