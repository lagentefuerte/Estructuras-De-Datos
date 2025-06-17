#include <stdio.h>
#include <string.h>


typedef struct Elemento1{
    int origen,destino;
}TElemento1;

void mostrarElemento1 (TElemento1* t);

void asignarElemento1(TElemento1* original, TElemento1* copia);

int igualElemento1(TElemento1* uno, TElemento1* dos);

void crearElemento1(int o, int d, TElemento1* e);

