#include "TListaDoblementeEnlazadaInicioyFinal.h"

void crearListaVacia(TLista * l)
{
    l->inicio = NULL;
    l->final = NULL;
}
int esListaVacia(TLista* l)
{
    return l->inicio == NULL && l->final == NULL;
}
int longitudLista(TLista* l)
{
    TNodo * aux = l->inicio;
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
    *e = l->inicio->info;
}
void restoLista(TLista* l)
{
    if (!esListaVacia(l)) {
        TNodo *aux = l->inicio;
        l->inicio = l->inicio->sig;
        if (l->inicio)
            l->inicio->ant = NULL;
        else
            l->final = NULL;
        free(aux);
        aux = NULL;
    }
}
void ultimoLista(TLista* l, Telemento* e)
{
    *e = l->final->info;
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
    if (!esListaVacia(l)) {
        TNodo *aux = l->inicio;
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
    aux->sig = l->inicio;
    aux->ant = NULL;
    if (!esListaVacia(l))
        l->inicio->ant = aux;
    else
        l->final = aux;
    l->inicio = aux;
}
void asignarLista(TLista* orig, TLista* dest)
{
    if (orig->inicio != dest->inicio && orig->final != dest->final) {
        destruirLista(dest);
        if (!esListaVacia(orig)) {
            TNodo *aux = (TNodo *) malloc(sizeof(TNodo));
            asignarElemento(&aux->info, &(orig->inicio)->info);
            dest->inicio = aux;
            aux->sig = NULL;
            aux->ant = NULL;
            TNodo *siguiente = orig->inicio->sig;
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
            dest->final = aux;
        }
    }
}
void insertarFinalLista(Telemento* e, TLista * l)
{
    TNodo * aux = (TNodo *) malloc(sizeof (TNodo));
    asignarElemento(&aux->info, e);
    aux->sig = NULL;
    aux->ant = l->final;
    if (!esListaVacia(l))
        l->final->sig = aux;
    else
        l->inicio = aux;
    l->final = aux;
}
int contieneLista(Telemento* e, TLista* l)
{
    int encontrado = 0;
    TNodo * aux = l->inicio;
    while (aux && !encontrado)
    {
        encontrado = igualesElemento(e, &aux->info);
        aux = aux->sig;
    }
    return encontrado;
}
int igualLista(TLista* l1, TLista* l2)
{
    TNodo* aux1 = l1->inicio;
    TNodo* aux2 = l2->inicio;
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
        if (igualesElemento(&l->inicio->info, e))
        {
            restoLista(l);
            encontrado = 1;
        }
        else if (igualesElemento(&l->final->info, e))
        {
            TNodo * aux =l->final;
            l->final = l->final->ant;
            if (l->final) //esta comprobacion no es necesaria ya que si fuese el unico elemento de la lista hubiese saltado en el if anterior, y la funcion restolista si que contempla ese caso
                l->final->sig = NULL;
            free(aux);
            aux = NULL;
        }
        else
        {
            TNodo * aux = l->inicio;
            while (aux->sig && !encontrado)
            {
                encontrado = igualesElemento(&aux->info, e);
                aux = aux->sig;
            }
            encontrado = igualesElemento(&aux->info, e);
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
        l1 = &auxiliar;
    }
    else
    {
        l1->final->sig = auxiliar.inicio;
        auxiliar.inicio->ant = l1->final;
    }
}