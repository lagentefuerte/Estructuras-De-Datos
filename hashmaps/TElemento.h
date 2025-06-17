#ifndef TLISTAESTATICA_TELEMENTO_H
#define TLISTAESTATICA_TELEMENTO_H

#include "TClave.h"
#include "TValor.h"

typedef struct  nodeMapa{
    TClave clave;
    TValor valor;
}TElemento;

void crearElemento (TClave* c,TValor* v, TElemento* e);
void mostrarElemento (TElemento* e);
void asignarElemento(TElemento* original, TElemento* copia);
int igualElemento (TElemento* uno, TElemento* dos);
int mayorQue(TElemento* uno,TElemento* dos);
void getClave(TElemento* e, TClave* c);
void getValor(TElemento* e, TValor* v);




#endif //TLISTAESTATICA_TELEMENTO_H
