//
// Created by famil on 3/10/2022.
//

#include "TPilaDinamica.h"

void crearPilaVacia (TLinkedStack *a)
{
    *a = NULL;
}
int esPilaVacia (TLinkedStack * a)
{
    return *a == NULL;
}
void apilar (Telemento* e, TLinkedStack * a)
{
    TNodo * aux = (TNodo *) malloc (sizeof (TNodo));
    asignarElemento(&aux->info, e);
    aux->ant = *a;
    *a = aux;
}
void cima (Telemento * e, TLinkedStack * a)
{
    if (!esPilaVacia(a)) {
        asignarElemento(e, &(*a)->info);
    }
}
void desapilar (TLinkedStack * a)
{
    if (!esPilaVacia(a)) {
        TNodo *aux = *a;
        *a = (*a)->ant;
        free(aux);
        aux = NULL;
    }
}
void copiarpila (TLinkedStack * orig, TLinkedStack * dest)
{
    if (!esPilaVacia(orig))
    {
        if (*orig != *dest)
        {
            destruirPila(dest);
        }
        TNodo * bucle = (*orig)->ant;
        TNodo * aux = (TNodo *) malloc(sizeof (TNodo));
        asignarElemento(&aux->info, &(*orig)->info);
        TNodo * sig = aux;
        aux->ant = NULL;
        *dest = aux;
        while (bucle)
        {
            TNodo * auxiliar = (TNodo *) malloc(sizeof (TNodo));
            asignarElemento(&auxiliar->info, &bucle->info);
            auxiliar->ant = NULL;
            sig->ant = auxiliar;
            bucle = bucle->ant;
            sig = auxiliar;
        }
    }
    else
    {
        *dest = NULL;
    }
}
void destruirPila (TLinkedStack * a)
{
    while (!esPilaVacia(a))
    {
        desapilar(a);
    }
}
