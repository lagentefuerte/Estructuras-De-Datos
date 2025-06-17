//
// Created by famil on 3/22/2022.
//

#include <stdlib.h>
#include <time.h>
#include "TConjunto.h"

void crearConjuntoVacio (set *a)
{
    a->cardinal = -1;
}
int esConjuntoVacio (set * a)
{
    return a->cardinal == -1;
}

void mostrarConjunto (set* a)
{
    if (!esConjuntoVacio(a))
    {
        for (int i = 0; i<=a->cardinal; i++)
            mostrarElemento(&a->almacen[i]);
    }
    printf("\n");
}
void poner (TElemento* e, set* a)
{
    if (a->cardinal < DIM - 1) {
        if (!pertenece(e, a)) {
            a->cardinal++;
            asignarElemento(e, &a->almacen[a->cardinal]);
        }
    } else
        printf("No hay sitio\n");
}
int quitar (TElemento* e, set* a)
{
    int encontrado = 0;
    int i = -1;
    while (i != a->cardinal && !encontrado)
    {
        i++;
        encontrado = igualesElemento(e, &a->almacen[i]);
    }
    if (encontrado)
    {
        for (int j = i; j<a->cardinal; j++)
        {
            asignarElemento(&a->almacen[j+1], &a->almacen[j]);
        }
        a->cardinal--;
    }
    return encontrado;
}
int elegir (TElemento* e, set* a)
{
    if(!esConjuntoVacio(a)) {
        int l = cardinal(a);
        srand(time(NULL));
        int r = rand() % l;
        asignarElemento(&a->almacen[r], e);
    }
    return esConjuntoVacio(a);
}
void interseccion (set* a1, set* a2, set* i)
{
    if (!esConjuntoVacio(a1) || !esConjuntoVacio(a2)) {
        for (int j = 0; j <= cardinal(a1); ++j) {
            if (pertenece(&a1->almacen[j], a2)) {
                poner(&a1->almacen[j], i);
            }
        }
    }
}
void diferencia (set* a1, set* a2, set* d)
{
    destruirConjunto(d);
    if (!esConjuntoVacio(a1)) {
        for (int j = 0; j <= cardinal(a1); ++j) {
            if (!pertenece(&a1->almacen[j], a2)) {
                poner(&a1->almacen[j], d);
            }
        }
    }
}
void unir(set* a1, set* a2, set* u)
{
    destruirConjunto(u);
    asignarConjunto(a1, u);
    if (!esConjuntoVacio(a2)) {
        for (int j = 0; j <= cardinal(a1); ++j) {
            if (!pertenece(&a2->almacen[j], u)) {
                poner(&a2->almacen[j], u);
            }
        }
    }
}
int esSubconjunto (set* a1, set* a2)
{
    int iguales = 0;
    if (cardinal(a1) == cardinal(a2))
    {
        int i = -1;
        iguales = 1;
        while (iguales && i != cardinal(a1))
        {
            i++;
            iguales = igualesElemento(&a1->almacen[i], &a2->almacen[i]);
        }
    }
    return iguales;
}
int pertenece (TElemento* e, set* a)
{
    int encontrado = 0;
    int i = -1;
    while (!encontrado && i != a->cardinal)
    {
        i++;
        encontrado = igualesElemento(e, &a->almacen[i]);
    }
    return encontrado;
}
int cardinal (set* a)
{
    return a->cardinal;
}
void asignarConjunto(set* original, set* copia)
{
    if (original != copia)
    {
        destruirConjunto(copia);
        if (!esConjuntoVacio(original))
        {
            for (int i = 0; i <= original->cardinal; ++i) {
                asignarElemento(&original->almacen[i], &copia->almacen[i]);
            }
            copia->cardinal = cardinal(original);
        }
    }
}
int igualConjunto(set* uno, set* dos)
{
    if (uno->cardinal == dos->cardinal)
    {
        int iguales = 1;
        int i = -1;
        while (iguales && i != uno->cardinal)
        {
            i++;
            iguales = igualesElemento(&uno->almacen[i], &dos->almacen[i]);
        }
        return iguales;
    }
    else
        return 0;
}
void destruirConjunto(set* a)
{
    crearConjuntoVacio(a);
}

