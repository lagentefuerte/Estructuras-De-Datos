#include "TElemento.h"
#include "string.h"
#include "stdio.h"

void crearElemento (TClave* c,TValor* v, TElemento* e){
    asignarClave(c,&e->clave);
    asignarValor(v,&e->valor);
}
void mostrarElemento (TElemento* e){
    printf("Clave: ");
    mostrarClave(&e->clave);
    printf("\n");
    printf(" Valor: ");
    mostrarValor(&e->valor);
    printf("\n");
}
void asignarElemento(TElemento* original, TElemento* copia){
    asignarClave(&original->clave,&copia->clave);
    asignarValor(&original->valor,&copia->valor);
}
int igualElemento (TElemento* uno, TElemento* dos){
    return igualClave(&uno->clave,&dos->clave);
}
int mayorQue(TElemento* uno,TElemento* dos){
    return mayorClave(&uno->clave,&dos->clave)&&mayorValor(&uno->valor,&dos->valor);
}
void getClave(TElemento* e, TClave* c){
    asignarClave(&e->clave,c);
}
void getValor(TElemento* e, TValor* v){
    asignarValor(&e->valor,v);
}
