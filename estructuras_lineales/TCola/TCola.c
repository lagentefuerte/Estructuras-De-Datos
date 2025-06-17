//
// Created by famil on 3/17/2022.
//

#include "TCola.h"

void crearColaVacia(TCola * c)
{
    c->longitud = 0;
    c->ini = NULL;
    c->final = NULL;
}
void insertarFinalLista(TElemento* e, TCola * c)
{
    TNodo * aux = (TNodo *) malloc(sizeof (TNodo));
    asignarElemento(&aux->info, e);
    if (esListaVacia(c))
        c->ini = aux;
    else
        c->final->sig = aux;
    aux->sig = NULL;
    c->final = aux;
    c->longitud++;
}
void primeroLista(TCola * c, TElemento* e)
{
    if (!esListaVacia(c))
        asignarElemento(e, &c->ini->info);
}
void restoLista(TCola * c)
{
    if (longitudLista(c) == 1)
    {
        free(c->ini);
        crearColaVacia(c);
    }
    else {
        TNodo *aux = c->ini;
        c->ini = c->ini->sig;
        free(aux);
        aux = NULL;
        c->longitud--;
    }

}
int esListaVacia(TCola * c)
{
    return longitudLista(c) == 0 && !c->ini && !c->final;
}
int longitudLista(TCola * c)
{
    return c->longitud;
}
void asignarLista(TCola* orig, TCola* dest) {
    if (orig != dest) {
        destruirLista(dest);
        if (!esListaVacia(orig)) {
            TNodo* act_orig = orig->ini;
            TNodo* aux = (TNodo*) malloc(sizeof (TNodo));
            asignarElemento(&act_orig->info, &aux->info);
            aux->sig = NULL;
            dest->ini = aux;
            TNodo* ultimo = aux;
            act_orig = act_orig->sig;
            while (act_orig) {
                aux = (TNodo*) malloc(sizeof (TNodo));
                asignarElemento(&act_orig->info, &aux->info);
                aux->sig = NULL;
                ultimo->sig = aux;
                ultimo = aux;
                act_orig = act_orig->sig;
                dest->final = aux;
            }
        }
    }
}
void destruirLista(TCola * c)
{
    while(!esListaVacia(c))
        restoLista(c);
}

