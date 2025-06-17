#include <stdio.h>
#include <stdlib.h>
#include<time.h>


#include "TMapa.h"

int hashP(TClave* c){     //funcion local, no incluida en la interfaz
    return hash(c) % Dim;
}

void crearMapaVacio (Mapa* a){
    for (int i = 0; i < Dim; ++i) {
        crearListaVacia(*a+i);
    }
}

int esMapaVacio (Mapa* a){
    int vacio = 1;
    int i = 0;
    while (vacio && i<Dim)
    {
        vacio = (*a+i == NULL);
        i++;
    }
    return vacio;
}

int sizeMapa (Mapa* a){
    int size = 0;
    for (int i = 0; i < Dim; ++i) {
        size += longitudLista(*a+i);
    }
    return size;
}

void mostrarMapa (Mapa* a){
    for (int i = 0; i < Dim; ++i) {
        if (!esListaVacia(*a+i))
            mostrarLista(*a+i);
        printf("\n");
    }
}

void ponerMapa (TClave* c, TValor* v, Mapa* a){
    TElemento aux;
    crearElemento(c, v, &aux);
    int posicion = hashP(c);
    if (contieneLista(&aux, *a+posicion)){
        eliminarLista(&aux, *a+posicion);
    }
    insertarLista(&aux, *a+posicion);
}

void devolver (TClave* c, TValor* v, Mapa* a){
    int posicion = hash(c);
    if (!esListaVacia(*a + posicion))
    {
        TLista aux;
        crearListaVacia(&aux);
        asignarLista(*a+posicion, &aux);
        int encontrado = 0;
        while (!esListaVacia(&aux) && !encontrado)
        {
            TClave first;
            TValor devolver;
            TElemento primero;
            primeroLista(&primero, &aux);
            getClave(&primero, &first);
            if (igualClave(&first, c))
            {
                getValor(&primero, &devolver);
                asignarValor(&devolver, v);
                encontrado = 1;
            }
            restoLista(&aux);
        }
    }
}

int quitarMapa (TClave* c, Mapa* a){
    int posicion = hashP(c);
    int eliminado = 0;
    if (!esListaVacia(*a+posicion))
    {
        TElemento aux;
        TValor nulo;
        crearValor("aux", &nulo);
        crearElemento(c, &nulo, &aux);
        eliminado = eliminarLista(&aux, *a+posicion);
    }
    return eliminado;
}

void destruirMapa(Mapa* a){
    for (int i = 0; i < Dim; ++i) {
        destruirLista(*a+i);
    }
}

void asignarMapa(Mapa* original, Mapa* copia){
    if (*original != *copia)
    {
        crearMapaVacio(copia);
        if (!esMapaVacio(original))
        {
            for (int i = 0; i < Dim; ++i) {
                asignarLista(*original+i, *copia+i);
            }
        }
    }
}

void conjuntoEntradas (set* e, Mapa* h){
    for (int i = 0; i<Dim; i++)
    {
        if (!esListaVacia(*h+i))
        {
            TLista l;
            crearListaVacia(&l);
            asignarLista(*h+i, &l);
            while (!esListaVacia(&l))
            {
                TElemento aux;
                primeroLista(&aux, &l);
                restoLista(&l);
                poner(&aux, e);
            }
        }
    }
}

void conjuntoClaves (set1* e, Mapa* h){
    for (int i = 0; i<Dim; i++)
    {
        if (!esListaVacia(*h+i))
        {
            TLista l;
            crearListaVacia(&l);
            asignarLista(*h+i, &l);
            while (!esListaVacia(&l))
            {
                TElemento aux;
                primeroLista(&aux, &l);
                restoLista(&l);
                TClave auxiliar;
                getClave(&aux, &auxiliar);
                poner1(&auxiliar, e);
            }
        }
    }
}

void conjuntoValores (set2* e, Mapa* h){
    for (int i = 0; i<Dim; i++)
    {
        if (!esListaVacia(*h+i))
        {
            TLista l;
            crearListaVacia(&l);
            asignarLista(*h+i, &l);
            while (!esListaVacia(&l))
            {
                TElemento aux;
                primeroLista(&aux, &l);
                restoLista(&l);
                TValor auxiliar;
                getValor(&aux, &auxiliar);
                poner2(&auxiliar, e);
            }
        }
    }
}