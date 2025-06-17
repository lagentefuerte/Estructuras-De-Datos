#include <stdio.h>
#include <string.h>


typedef int TElemento;

void mostrarElemento (TElemento* t);

void asignarElemento(TElemento* original, TElemento* copia);

int igualElemento(TElemento* uno, TElemento* dos);

void crearElemento(int i, TElemento* e);

int esMayor(TElemento* lhs, TElemento* rhs);