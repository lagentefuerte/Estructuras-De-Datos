//
// Created by famil on 3/24/2022.
//

#include "TConjuntoBooleano.h"

void crearConjuntoVacio(set*a)
{
    for (int i = 0; i<DIM; i++)
    {
        (*a)[i] = 0;
    }
}
void mostrarConjunto(set*a)
{
    for (int i = 0; i<DIM; i++)
    {
        if ((*a)[i] == 1)
            printf("%d ", i);
    }
    printf("\n");
}
void poner(TElemento*e,set*a)
{
    int ind = indice(e);
    if (ind > -1 && ind < DIM)
        (*a)[ind] = 1;
}
int quitar(TElemento*e,set*a)
{
    int ind = indice(e);
    if ((*a)[ind] != 0 && ind > -1 && ind < DIM)
    {
        (*a)[ind] = 0;
        return 1;
    }
    else
        return 0;
}
int elegir(TElemento*e,set* a)
{
    int flag = 0;
    if (!esConjuntoVacio(a)) {
        srand(time(NULL));
        int aleatorio = rand() % cardinal(a);
        int i = 0, j = 0;
        while (i < DIM && j != aleatorio) {
            if ((*a)[i] == 1)
                j++;
            i++;
        }
        crearElemento(e, i);
        flag = 1;
    }
    return flag;
}
void interseccion(set* a1,set* a2,set* i)
{
    for (int j = 0; j < DIM; ++j) {
        if ((*a1)[j] == 1 && (*a2)[j] == 1)
        {
            (*i)[j] = 1;
        }
    }
}
void diferencia(set* a1,set* a2,set* d)
{
    for (int j = 0; j < DIM; ++j) {
        if ((*a1)[j] == 1 && (*a2)[j] == 0) {
            (*d)[j] = 1;
        }
    }
}
void unir(set* a1,set* a2,set* u)
{
    for (int j = 0; j < DIM; ++j) {
        if ((*a1)[j] == 1 || (*a2)[j] == 1)
        {
            (*u)[j] = 1;
        }
    }
}
int esSubconjunto(set* a1,set* a2)
{
    for (int i = 0; i < DIM; ++i) {
        if ((*a1)[i] == 1)
            if ((*a2)[i] == 0)
                return 0;
    }
    return 1;
}
int pertenece(TElemento*e,set* a)
{
    return (*a)[indice(e)];
}
int esConjuntoVacio(set* a)
{
    int iguales = 0;
    int i = 0;
    while (!iguales && i<DIM) {
        iguales = (*a)[i];
        i++;
    }
    return !iguales && i == DIM;
}
int cardinal(set* a) {
    int j = 0;
    for (int i = 0; i < DIM; i++) {
        if ((*a)[i] == 1)
            j++;
    }
    return j;
}
void asignarConjunto(set* original,set* copia)
{
    for (int i = 0; i < DIM; ++i) {
        (*copia)[i] = (*original)[i];
    }
}
int igualConjunto(set* uno,set*dos)
{
    int iguales = 1;
    int i = 0;
    while (i != DIM && iguales) {
        iguales = (*uno)[i] == (*dos)[i];
        i++;
    }
    return iguales && i == DIM;
}
void destruirConjunto(set* a)
{
    crearConjuntoVacio(a);
}