#include <stdio.h>
#include <string.h>


typedef char TValor [4];

void crearValor(char* c, TValor* e);

void mostrarValor (TValor* t);

void asignarValor(TValor* original, TValor* copia);

int igualValor(TValor* uno, TValor* dos);

int mayorValor(TValor* uno, TValor* dos);
