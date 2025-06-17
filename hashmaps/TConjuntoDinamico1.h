#ifndef ConjuntoENLAZADASIMPLE_set1ENLAZADASIMPLE_H
#define ConjuntoENLAZADASIMPLE_set1ENLAZADASIMPLE_H
#include "TClave.h"



typedef struct NodoC1{
    TClave info;
    struct NodoC1* sig;
}TNodoConjunto1;

typedef TNodoConjunto1* set1;


void crearConjuntoVacio1 (set1* l);
void mostrarConjunto1 (set1* l);
void poner1 (TClave* e, set1* l);
int quitar1 (TClave* e, set1* l);
int esConjuntoVacio1 (set1* l);
int cardinal1 (set1* l);
int pertenece1 (TClave* e, set1* l);
void elegir1 (TClave* e, set1* l);

void unir1 (set1* l1, set1* l2, set1* u);
void interseccion1 (set1* l1, set1* l2, set1* i);
void diferencia1 (set1* l1, set1* l2, set1* d);
int esSubconjunto1 (set1* l1, set1* l2);



int igualConjunto1 (set1* l1, set1* l2);
void asignarConjunto1 (set1* original, set1* copia);
void destruirConjunto1(set1* l);



#endif //ConjuntoENLAZADASIMPLE_set1ENLAZADASIMPLE_H
