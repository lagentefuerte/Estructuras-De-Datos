//
// Created by famil on 3/29/2022.
//

#include <stdlib.h>
#include "ArbolDinamico.h"

void crearArbolVacio(TBinaryTree* a){
    *a=NULL;
}
void crearArbol(TBinaryTree* a,TBinaryTree* izq,TBinaryTree* der,TElemento* e){
    TNodeTree* aux = (TNodeTree*) malloc(sizeof(TNodeTree));
    asignarElemento(e,&(aux->info));
    aux->left=*izq;
    aux->right=*der;
    *a=aux;
}
void devolverRaiz(TBinaryTree* a, TElemento* r){
    if(!esArbolVacio(a)){
        asignarElemento(&(*a)->info,r);
    }
}

void asignarArbol(TBinaryTree* original, TBinaryTree* copia){
    if (esArbolVacio(original)){
        crearArbolVacio(copia);
    }
    else{
        TBinaryTree hi,hd;
        asignarArbol(&(*original)->left,&hi);
        asignarArbol(&(*original)->right,&hd);
        TNodeTree* aux =(TNodeTree*)malloc(sizeof(TNodeTree));
        aux->left=hi;
        aux->right=hd;
        asignarElemento(&(*original)->info,&aux->info);
        *copia=aux;
    }
}
int esArbolVacio(TBinaryTree* a){
    return (*a)==NULL;
}

int igualArbol(TBinaryTree* uno, TBinaryTree* dos){
    if (esArbolVacio(uno)){
        return esArbolVacio (dos);
    }
    else if (esArbolVacio(dos)){
        return esArbolVacio (uno);
    }
    else{
        return igualesElemento(&(*uno)->info,&(*dos)->info) && igualArbol(&(*uno)->left,&(*dos)->left) && igualArbol(&(*uno)->right,&(*dos)->right);
    }
}

void devolverHijoIzquierdo(TBinaryTree* a, TBinaryTree* hIzq){
    if(!esArbolVacio(a)){
        (*hIzq)=(*a)->left;
    }
}
void devolverHijoDerecho(TBinaryTree* a, TBinaryTree* hDer){
    if(!esArbolVacio(a)){
        (*hDer)=(*a)->right;
    }
}
void destruirArbol(TBinaryTree* a){
    if(!esArbolVacio(a)){
        destruirArbol(&((*a)->left));
        destruirArbol(&((*a)->right));
        free(*a);
        *a=NULL;
    }
}

int numeroNodos (TBinaryTree *a)
{
    if (esArbolVacio(a))
        return 0;
    else
    {
        return 1 + numeroNodos(&(*a)->left) + numeroNodos(&(*a)->right);
    }
}

int numeroHojas (TBinaryTree* a)
{
    if (esArbolVacio(a))
        return 0;
    else if (esArbolVacio(&(*a)->left) && esArbolVacio(&(*a)->right))
        return 1;
    else
        return numeroHojas(&(*a)->right)+ numeroHojas(&(*a)->left);
}

int altura (TBinaryTree * a)
{
    if (esArbolVacio(a))
        return 0;
    else
    {
        return 1 + ((altura(&(*a)->left) > altura(&(*a)->right)) ? altura(&(*a)->left) : altura(&(*a)->right));
    }
}

void recorridoPreorden (TBinaryTree *a, TLista * r)
{
    if (esArbolVacio(a))
        return;
    else
    {
        recorridoPreorden(&(*a)->right, r);
        TLista aux;
        crearListaVacia(&aux);
        recorridoPreorden(&(*a)->left, r);
        concatenarLista(r, &aux);
        destruirLista(&aux);
        insertarLista(&(*a)->info, r);
        return;
    }
}

void recorridoInorden (TBinaryTree *a, TLista * r)
{
    if (esArbolVacio(a))
        return;
    else
    {
        recorridoInorden(&(*a)->right, r);
        insertarLista(&(*a)->info, r);
        TLista aux;
        crearListaVacia(&aux);
        recorridoInorden(&(*a)->left, r);
        concatenarLista(r, &aux);
        destruirLista(&aux);
        return;
    }
}

void recorridoPostorden (TBinaryTree *a, TLista * r)
{
    if (esArbolVacio(a))
        return;
    else
    {
        recorridoPostorden(&(*a)->left, r);
        insertarLista(&(*a)->info, r);
        TLista aux;
        crearListaVacia(&aux);
        recorridoPostorden(&(*a)->right, r);
        concatenarLista(r, &aux);
        destruirLista(&aux);
        return;
    }
}


int nodoNivel (TBinaryTree* a, TElemento* e, int i)
{
    if (!esArbolVacio(a)) {
        if (esArbolVacio(a))
            return 0;
        else if (igualesElemento(&(*a)->info, e)) {
            i++;
            return i;
        }
        else {
            i++;
            return (nodoNivel(&(*a)->left, e, i) > nodoNivel(&(*a)->right, e, i)) ? nodoNivel(&(*a)->left, e, i) : nodoNivel(&(*a)->right, e, i);
        }
    }
    else
        return i;
}

int sonHermanos(TBinaryTree* a, TElemento* e1, TElemento* e2)
{
    if ((esArbolVacio(&(*a)->right) && esArbolVacio(&(*a)->left)) || esArbolVacio(a))
        return 0;
    else if ((esArbolVacio(&(*a)->right) || esArbolVacio(&(*a)->left)))
    {
        return sonHermanos(&(*a)->left, e1, e2) || sonHermanos(&(*a)->right, e1, e2);
    }
    else if (igualesElemento(e1, &(*a)->left->info) && igualesElemento(e2, &(*a)->right->info) || igualesElemento(e1, &(*a)->right->info) && igualesElemento(e2, &(*a)->left->info))
        return 1;
    else
        return sonHermanos(&(*a)->left, e1, e2) || sonHermanos(&(*a)->right, e1, e2);
}

void imagenEspecular (TBinaryTree* a)
{
    if (!esArbolVacio(a)) {
        if (!esArbolVacio(&(*a)->right) || !esArbolVacio(&(*a)->left)) {
            TBinaryTree aux;
            asignarArbol(&(*a)->left, &aux);
            asignarArbol(&(*a)->right, &(*a)->left);
            asignarArbol(&aux, &(*a)->right);
        }
        imagenEspecular(&(*a)->left);
        imagenEspecular(&(*a)->right);
    }

}