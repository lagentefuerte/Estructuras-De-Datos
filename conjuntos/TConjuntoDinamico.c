//
// Created by famil on 3/24/2022.
//

#include "TConjuntoDinamico.h"


void crearConjuntoVacio(set*a){
    *a = NULL;
}
void mostrarConjunto(set*a)
{
    if(!esConjuntoVacio(a)){
        TNodoSet *aux= *a;
        printf("[");
        while(aux){
            mostrarElemento(&aux->info);
            printf(",");
            aux=aux->sig;
        }
        printf("]\n");
    }else{
        printf("[]\n");
    }
}
void poner(TElemento*e,set*a){
    if(!pertenece(e, a)){
        TNodoSet* aux = (TNodoSet*) malloc(sizeof(TNodoSet));
        asignarElemento(e, &aux->info);
        aux->sig = *a;
        *a = aux;
    }
}
int quitar(TElemento*e,set*a){
    set act = *a;
    set ant = NULL;
    int encontrado = 0;
    while (!encontrado && (act != NULL)){
        encontrado = igualesElemento(e, &act->info);
        if(!encontrado){
            ant = act;
            act = act->sig;
        }
    }
    if (encontrado)
    {
        if (!ant) {
            *a = act->sig;
        }
        else {
            ant->sig = act->sig;
        }
        free(act);
        act = NULL;
    }
    return encontrado;
}
int elegir(TElemento*e,set* a){
    if(!esConjuntoVacio(a)){
        int l = cardinal(a);
        srand(time(NULL));
        int r = rand()%l;
        set aux = *a;
        int i = 0;
        while(i!=r){
            aux = aux->sig;
            i++;
        }
        asignarElemento(&aux->info, e);
        return 1;

    }else{
        printf("No hay elementos");
        return 0;
    }
}
void interseccion(set* a1,set* a2,set* i)
{
    destruirConjunto(i);
    if (!esConjuntoVacio(a1) && !esConjuntoVacio(a2)) {
        TNodoSet *aux = *a1;
        while (aux) {
            if (pertenece(&aux->info, a2))
                poner(&aux->info, i);
            aux = aux->sig;
        }
    }
}
void diferencia(set* a1,set* a2,set* d)
{
    TNodoSet * aux = *a1;
    destruirConjunto(d);
    if (!esConjuntoVacio(a1)) {
        while (aux) {
            if (!pertenece(&aux->info, a2))
                poner(&aux->info, d);
            aux = aux->sig;
        }
    }
}
void unir(set* a1,set* a2,set* u)
{
    destruirConjunto(u);
    asignarConjunto(a1, u);
    if (!esConjuntoVacio(a2)) {
        TNodoSet *aux = *a2;
        while (aux) {
            if (!pertenece(&aux->info, u))
                poner(&aux->info, u);
            aux = aux->sig;
        }
    }
}
int esSubconjunto(set* a1,set* a2)
{
    TNodoSet * aux = *a1;
    int i = 0;
    if (!esConjuntoVacio(a2)) {
        while (aux) {
            if (pertenece(&aux->info, a2))
                i++;
            aux = aux->sig;
        }
    }
    return i == cardinal(a1);
}
int pertenece(TElemento*e,set* a){
    set act = *a;
    int encontrado = 0;
    while (!encontrado && (act != NULL)){
        encontrado = igualesElemento(e, &act->info);
        if(!encontrado){
            act = act->sig;
        }
    }
    return encontrado;
}
int esConjuntoVacio(set* a)
{
    return *a == NULL;
}
int cardinal(set* a)
{
    int longitud = 0;
    if (!esConjuntoVacio(a)) {
        TNodoSet *aux = *a;
        while (aux != NULL) {
            aux = aux->sig;
            longitud++;
        }
    }
    return longitud;
}
void asignarConjunto(set* original,set* copia)
{
    if (*original != *copia) {
        destruirConjunto(copia);
        if (!esConjuntoVacio(original)) {
            TNodoSet * recorrer = *original;
            TNodoSet * aux = (TNodoSet *) malloc(sizeof (TNodoSet));
            asignarElemento(&(*original)->info, &aux->info);
            *copia = aux;
            aux->sig = NULL;
            TNodoSet * ant = aux;
            recorrer = recorrer->sig;
            while (recorrer)
            {
                aux = (TNodoSet *) malloc(sizeof (TNodoSet));
                asignarElemento(&recorrer->info, &aux->info);
                aux->sig = NULL;
                ant->sig = aux;
                ant = ant->sig;
                recorrer = recorrer->sig;
            }
        }
    }
}

int igualConjunto(set* uno,set*dos)
{
    TNodoSet * aux1 = *uno;
    TNodoSet * aux2 = *dos;
    int iguales = 1;
    while (iguales && aux1 && aux2) {
        iguales = igualesElemento(&aux1->info, &aux2->info);
        aux1 = aux1->sig;
        aux2 = aux2->sig;
    }
    return iguales && !aux1 && !aux2;
}
void destruirConjunto(set* a)
{
    while (!esConjuntoVacio(a))
    {
        TNodoSet * aux = *a;
        *a = (*a)->sig;
        free(aux);
        aux = NULL;
    }
}