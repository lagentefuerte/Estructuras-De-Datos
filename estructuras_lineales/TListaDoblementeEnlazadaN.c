#include <stdio.h>
#include "TListaDoblementeEnlazada.h"

void crearListaVacia(TLista * l)
{
    *l = NULL;
}
int esListaVacia(TLista* l)
{
    return *l == NULL;
}
int longitudLista(TLista* l)
{
    TNodo * aux = *l;
    int i = 0;
    if (!esListaVacia(l)) {
        i++;
        while (aux->sig) {
            i++;
            aux = aux->sig;
        }
    }
    return i;
}
void primeroLista(TLista * l, Telemento* e)
{
    if (!esListaVacia(l)) {
        asignarElemento(e, &(*l)->info);
    }
}
void restoLista(TLista* l)
{
    if (!esListaVacia(l)) {
        TNodo *aux = *l;
        *l = (*l)->sig;
        if (*l)
            (*l)->ant = NULL;
        free(aux);
        aux = NULL;
    }
}
void ultimoLista(TLista* l, Telemento* e)
{
    if (!esListaVacia(l)) {
        TNodo *aux = *l;
        while (aux->sig) {
            aux = aux->sig;
        }
        asignarElemento(e, &aux->info);
    }
}
void destruirLista(TLista* l)
{
    while (!esListaVacia(l))
    {
        restoLista(l);
    }
}

void mostrarLista(TLista * l)
{
    TNodo* aux = *l;
    if (!esListaVacia(l)) {
        printf("[");
        while (aux) {
            mostrarElemento(&aux->info);
            printf(", ");
            aux = aux->sig;
        }
        printf("]\n");
    }
}
void insertarLista(Telemento* e, TLista * l)
{
    TNodo * aux = (TNodo *) malloc(sizeof (TNodo));
    asignarElemento(&aux->info, e);
    aux->sig = *l;
    aux->ant = NULL;
    if (!esListaVacia(l))
        (*l)->ant = aux;
    *l = aux;
}
void asignarLista(TLista* orig, TLista* dest)
{
    if (*orig != *dest) {
        destruirLista(dest);
        if (!esListaVacia(orig)) {
            TNodo *aux = (TNodo *) malloc(sizeof(TNodo));
            asignarElemento(&aux->info, &(*orig)->info);
            *dest = aux;
            aux->sig = NULL;
            aux->ant = NULL;
            TNodo *siguiente = (*orig)->sig;
            TNodo *ultimo = aux;
            while (siguiente) {
                aux = (TNodo *) malloc(sizeof(TNodo));
                asignarElemento(&aux->info, &(siguiente)->info);
                aux->ant = ultimo;
                aux->sig = NULL;
                ultimo->sig = aux;
                ultimo = aux;
                siguiente = siguiente->sig;
            }
        }
    }
}
void insertarFinalLista(Telemento* e, TLista * l)
{
    if (!esListaVacia(l)) {
        TNodo *aux = *l;
        while (aux->sig) {
            aux = aux->sig;
        }
        TNodo *nuevo = (TNodo *) malloc(sizeof (TNodo));
        asignarElemento(&nuevo->info, e);
        aux->sig = nuevo;
        nuevo->sig = NULL;
        nuevo->ant = aux;
    }
    else
        insertarLista(e, l);
}
int contieneLista(Telemento* e, TLista* l)
{
    int encontrado = 0;
    TNodo * aux = *l;
    while (aux && !encontrado)
    {
        encontrado = igualesElemento(e, &aux->info);
        aux = aux->sig;
    }
    return encontrado;
}
int igualLista(TLista* l1, TLista* l2)
{
    TNodo* aux1 = *l1;
    TNodo* aux2 = *l2;
    int iguales = 1;
    while (iguales && aux1 && aux2) {
        iguales = igualesElemento(&aux1->info, &aux2->info);
        aux1 = aux1->sig;
        aux2 = aux2->sig;
    }
    return iguales && !aux1 && !aux2;
}
int eliminarLista(Telemento* e, TLista * l)
{
    int encontrado = 0;
    if (!esListaVacia(l))
    {
        if (igualesElemento(&(*l)->info, e))
        {
            restoLista(l);
            encontrado = 1;
        }
        else
        {
            TNodo * aux = *l;
            while (aux && !encontrado)
            {
                encontrado = igualesElemento(&aux->info, e);
                if (!encontrado)
                    aux = aux->sig;
            }
            if (encontrado) {
                aux->ant->sig = aux->sig;
                if (aux->sig)
                    aux->sig->ant = aux->ant;
                free(aux);
            }
        }
    }
    return encontrado;
}

void concatenarLista(TLista* l1, TLista* l2)
{
    TLista auxiliar;
    crearListaVacia(&auxiliar);
    asignarLista(l2, &auxiliar);
    if (esListaVacia(l1)) {
        *l1 = auxiliar;
    }
    else
    {
        TNodo * aux = *l1;
        while (aux->sig) {
            aux = aux->sig;
        }
        aux->sig = auxiliar;
        auxiliar->ant = aux;
    }
}
