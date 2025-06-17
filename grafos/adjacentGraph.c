#include <stdio.h>
#include <stdlib.h>
#include "adjacentGraph.h"
#include "TElemento1.h"

int contieneVertice (TElemento* e, TAdyacentGraph* a){
    TnodoG * aux = *a;
    int encontrado = 0;
    while (aux && !encontrado)
    {
        encontrado = igualElemento(&aux->info, e);
        aux = aux->sig;
    }
    return encontrado;
}

void crearGrafoNulo (TAdyacentGraph* a){
    (*a) = NULL;
}
void insertarVertice (TElemento* e, TAdyacentGraph* a){
    if (!contieneVertice(e, a))
    {
        TnodoG * aux = (TnodoG *) malloc (e, &aux->info);
        asignarElemento(e, &aux->info);
        crearListaVacia(&aux->adyacentes);
        aux->sig = *a;
        *a = aux;
    }
}
void insertarArista (TElemento* e1,TElemento* e2, TAdyacentGraph* a){//si no están los nodos se insertan también
    insertarVertice(e1, a);
    insertarVertice(e2, a);
    int encontrado1 = 0;
    int encontrado2 = 0;
    TnodoG * aux = *a;
    while (aux && !encontrado1 && !encontrado2)
    {
        if (igualElemento(e1, &aux->info))
        {
            encontrado1 = 1;
            insertarLista(e2, &aux->adyacentes);
        }
        if (igualElemento(e2, &aux->info))
        {
            encontrado2 = 1;
            insertarLista(e1, &aux->adyacentes);
        }
        aux = aux->sig;
    }
}

int eliminarVertice (TElemento* e, TAdyacentGraph* a){
    int encontrado = 0;
    TnodoG * act = *a;
    TnodoG * ant = NULL;
    while (act && !encontrado)
    {
        encontrado = igualElemento(e, &act->info);
        if (!encontrado)
        {
            ant = act;
            act = act->sig;
        }
    }
    if (encontrado)
    {
        if (!ant)
            *a = (*a)->sig;
        else
            ant->sig = act->sig;
        destruirLista(&act->adyacentes);
        free(act);
        TnodoG * aux = *a;
        while (aux)
        {
            eliminarLista(e, &aux->adyacentes);
            aux = aux->sig;
        }
        return encontrado;
    }
}
void eliminarArista (TElemento* e1,TElemento* e2, TAdyacentGraph* a){
    int encontrado1 = 0;
    int encontrado2 = 0;
    TnodoG * aux = *a;
    while (aux && !encontrado1 && !encontrado2)
    {
        if (igualElemento(e1, &aux->info))
        {
            encontrado1 = 1;
            eliminarLista(e2, &aux->adyacentes);
        }
        if (igualElemento(e2, &aux->info))
        {
            encontrado2 = 1;
            eliminarLista(e1, &aux->adyacentes);
        }
        aux = aux->sig;
    }
}

int esAdyacente(TElemento* e1,TElemento* e2,TAdyacentGraph* a){
    TnodoG * g = *a;
    int encontrado = 0;
    while (g && !encontrado)
    {
        if (igualElemento(&aux->info, e1))
        {
            if (contieneLista(e2, l))
                encontrado = 1;
        }
        if (igualElemento(&aux->info, e2))
        {
            if (contieneLista(e1, l))
                encontrado = 1;
        }
    }
    g = g->sig;
}

int esGrafoNulo (TAdyacentGraph* a){
    return *a == NULL;
}
void listaVertices (TAdyacentGraph* a, TLista* l){
    crearListaVacia(l);
    TnodoG * aux = *a;
    while (aux)
    {
        insertarFinalLista(&aux->info, l);
        aux = aux->sig;
    }
}
void conjuntoAristas (TAdyacentGraph* a,set* s){
    crearConjuntoVacio(s);
    TnodoG * aux = *a;
    TLista l;
    crearListaVacia(&l);
    while (aux)
    {
        asignarLista(&aux->adyacentes, &l);
        while (!esListaVacia(&l))
        {
            TElemento primero;
            primeroLista(&primero, &l);
            restoLista(&l);
            TElemento1 insertar;
            crearElemento1(aux->info, primero, &insertar);
            poner(&insertar, s);
        }
        aux = aux->sig;
    }
}
void asignarGrafo(TAdyacentGraph* original, TAdyacentGraph* copia){
    TnodoG * uno = *original;
    TnodoG * dos = (TnodoG *) malloc(sizeof (TnodoG));
    asignarLista(&uno->adyacentes, &dos->adyacentes);
    asignarElemento(&uno->info, &dos->info);
    dos->sig = NULL;
    *copia = dos;
    TnodoG * ant = dos;
    uno = uno->sig;
    while (uno)
    {
        dos = (TnodoG *) malloc(sizeof (TnodoG));
        asignarLista(&uno->adyacentes, &dos->adyacentes);
        asignarElemento(&uno->info, &dos->info);
        dos->sig = NULL;
        ant->sig = dos;
        ant = dos;
        uno = uno->sig;
    }
}
void destruirG(TAdyacentGraph* a){
    TnodoG * act = *a;
    TnodoG * sig = (*a)->sig;
    while (act)
    {
        destruirLista(&act->adyacentes);
        free(act);
        act = sig;
        sig = act->sig;
    }
    *a = NULL;
}

int igualGrafo(TAdyacentGraph* uno, TAdyacentGraph* dos){
    int iguales = 1;
    TnodoG * aux1 = *uno;
    TnodoG * aux2 = *dos;
    while (iguales && aux1 && aux2)
    {
        iguales = igualElemento(&aux1->info, &aux2->info) && igualLista(&aux1->adyacentes, &aux2->adyacentes);
        aux1 = aux1->sig;
        aux2 = aux2->sig;
    }
    return iguales && !aux1 && !aux2;
}