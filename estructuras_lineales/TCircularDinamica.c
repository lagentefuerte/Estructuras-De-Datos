//
// Created by ASUS on 3/13/2022.
//

#include "Tlista.h"

void crearListaVacia(TLista * l){
    *l=NULL;
}
void mostrarLista(TLista * l){
    if(!esListaVacia(l)){
        TNodo *aux=(*l)->sig;
        printf("[");
        while(aux!=*l){
            mostrarElemento(&aux->info);
            printf(",");
            aux=aux->sig;
        }
        if(aux==*l){
            mostrarElemento(&aux->info);
            printf("]\n");
        }
    }else{
        printf("[]\n");
    }
}
void insertarLista(TElemento* e, TLista * l){
    TNodo *aux=(TNodo*)malloc(sizeof(TNodo));
    if(!esListaVacia(l)){
        asignarElemento(e,&aux->info);
        aux->sig=(*l)->sig;
        (*l)->sig=aux;
    }else{
        asignarElemento(e,&aux->info);
        aux->sig=aux;
        *l=aux;
    }
}
void insertarFinalLista(TElemento* e, TLista * l){
    if(!esListaVacia(l)){
        TNodo *aux=(TNodo*)malloc(sizeof(TNodo));
        asignarElemento(e,&aux->info);
        aux->sig=(*l)->sig;
        (*l)->sig=aux;
        (*l)=aux;
    }else{
        insertarLista(e,l);
    }
}

int eliminarLista(TElemento *e, TLista *l) {
    int encontrado = 0;
    if (!esListaVacia(l)) {
        TNodo * aux = (*l)->sig;
        TNodo * ant = (*l);
        while (!encontrado && aux != *l)
        {
            encontrado = igualesElemento(e, &aux->info);
            if (encontrado)
            {
                ant->sig = aux->sig;
                free(aux);
                aux = NULL;
            }
            else {
                aux = aux->sig;
                ant = ant->sig;
            }
        }
        if (igualesElemento(e, &(*l)->info) && !encontrado)
        {
            encontrado = 1;
            if (*l != (*l)->sig) {
                ant->sig = (*l)->sig;
                free(aux);
                aux = NULL;
                (*l) = ant;
            }
            else
            {
                free(*l);
                *l = NULL;
            }
        }
    }
    return encontrado;
}

void primeroLista(TLista * l, TElemento* e){
    if(!esListaVacia(l)){
        asignarElemento(&((*l)->sig->info),e);
    }
}

void restoLista(TLista* l){
    if (!esListaVacia(l)) {
        TNodo *aux = (*l)->sig;
        if (aux != *l) {
            (*l)->sig = aux->sig;
            free(aux);
            aux = NULL;
        }else{
            (*l)=NULL;
            free(aux);
            aux=NULL;
        }
    }
}
void ultimoLista(TLista* l, TElemento* e){
    if(!esListaVacia(l)){
        asignarElemento(&((*l)->info),e);
    }
}
void concatenarLista(TLista* l1, TLista* l2){
    TLista aux;
    crearListaVacia(&aux);
    asignarLista(l2, &aux);
    if (esListaVacia(l1)) {
        *l1 = aux;
    } else {
        TNodo *aux2 = aux->sig;
        aux->sig = (*l1)->sig;
        (*l1)->sig = aux2;
        (*l1) = aux;
    }
}
int contieneLista(TElemento* e, TLista* l){
    int encontrado=0;
    if(!esListaVacia(l)){
        TNodo *aux=(*l)->sig;
        while(!encontrado && aux!=*l){
            encontrado= igualesElemento(&aux->info,e);
            aux=aux->sig;
        }
        if(aux==*l){
            encontrado= igualesElemento(&aux->info,e);
        }
    }
    return encontrado;
}
int esListaVacia(TLista* l){
    return *l==NULL;
}
int longitudLista(TLista* l){
    int longitud = 0;
    if (!esListaVacia(l)) {
        TNodo *aux = (*l)->sig;
        longitud = 1;
        while (aux != *l) {
            aux = aux->sig;
            longitud++;
        }
    }
    return longitud;
}

int igualLista(TLista *l1, TLista *l2) {
    int iguales = 1;
    TNodo *aux1 = (*l1)->sig;
    TNodo *aux2 = (*l2)->sig;
    while (iguales && aux1 != *l1 && aux2 != *l2) {
        iguales = igualesElemento(&aux1->info, &aux2->info);
        aux1 = aux1->sig;
        aux2 = aux2->sig;
    }
    if (iguales && aux1 == *l1 && aux2 ==*l2) {
        iguales = igualesElemento(&aux1->info, &aux2->info);
    }
    return iguales && aux2 == *l2 && aux1 == *l1;
}
void asignarLista(TLista* orig, TLista* dest){
    if (*orig != *dest) {
        destruirLista(dest);
        if (!esListaVacia(orig)) {
            TNodo * recorrer = (*orig)->sig;
            TNodo * aux = (TNodo *) malloc(sizeof (TNodo));
            asignarElemento(&(*orig)->info, &aux->info);
            *dest = aux;
            aux->sig = aux;
            TNodo * ant = aux;
            while (recorrer != *orig)
            {
                aux = (TNodo *) malloc(sizeof (TNodo));
                asignarElemento(&recorrer->info, &aux->info);
                aux->sig = *dest;
                ant->sig = aux;
                ant = ant->sig;
                recorrer = recorrer->sig;
            }
        }
    }
}
void destruirLista(TLista* l){
    while(!esListaVacia(l)){
        restoLista(l);
    }
}