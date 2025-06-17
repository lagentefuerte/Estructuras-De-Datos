#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "binarySearchTree.h"


void crearArbolBusquedaVacio(TBinarySearchTree* a){
    *a = NULL;
}

void insertarArbolBusqueda(TBinarySearchTree* a,TElemento* e){
    if (esArbolBusquedaVacio(a)){
            TNodeSearchTree* aux = (TNodeSearchTree*) malloc(1*sizeof(TNodeSearchTree));
            asignarElemento(e,&aux->info);
            aux->left=NULL;
            crearArbolBusquedaVacio(&aux->right);
            *a=aux;
    }
    else{
        if (mayorQue(&(*a)->info,e)){
            insertarArbolBusqueda(&(*a)->left,e);
        }
        else{
            insertarArbolBusqueda(&(*a)->right,e);
        }
    }
}

int eliminarArbolBusqueda(TBinarySearchTree* a,TElemento* e){
        int borrado =0 ;
        TNodeSearchTree* act =*a;
        TNodeSearchTree* ant = NULL;
        while((act!=NULL)&&(!igualesElemento(e,&(*a)->info))){
            if(mayorQue(&(*a)->info,e)){
                ant=act;
                act=act->left;
            }
            else{
                ant=act;
                act=act->right;
            }
        }

        if(act!=NULL){ //encontrado
            borrado =1;
            if (act->left==NULL && act->right==NULL){ // es hoja
                    
                    if(ant==NULL){ // unico nodo del arbol (arbol hoja)
                        *a=NULL;
                    }
                    else{ //voy a arreglar al padre
                           if(mayorQue(&ant->info,e)){//padre mayor que el hijo
                               ant->left=NULL;
                           } 
                           else{
                               ant->right=NULL;
                           }
                    }
                    free(act);
            }
            else{ //no es hoja

                if(act->left!=NULL){//tengo descendencia por la izquierda
                    TElemento m;
                    mayorNodo(&m,&act->left);
                    asignarElemento(&m,&act->info);
                    return eliminarArbolBusqueda(&act->left,&m);

                }
                else{
                    TElemento m;
                    menorNodo(&m,&act->right);
                    asignarElemento(&m,&act->info);
                    return eliminarArbolBusqueda(&act->right,&m);
                }
        
            }
        }
        return borrado;
}

void devolverRaizBusqueda(TBinarySearchTree* a, TElemento* r){
    asignarElemento(&(*a)->info, r);
}
void devolverHijoIzquierdoBusqueda(TBinarySearchTree* a, TBinarySearchTree* hIzq){
    asignarArbolBusqueda(&(*a)->left, hIzq);
}
void devolverHijoDerechoBusqueda(TBinarySearchTree* a, TBinarySearchTree* hDer){
    asignarArbolBusqueda(&(*a)->left, hDer);
}

void destruirArbolBusqueda(TBinarySearchTree* a){
    if (!esArbolBusquedaVacio(a))
    {
        TNodeSearchTree * aux1 = (*a)->left;
        TNodeSearchTree * aux2 = (*a)->right;
        free(a);
        a = NULL;
        destruirArbolBusqueda(&aux1);
        destruirArbolBusqueda(&aux2);
    }
}
void asignarArbolBusqueda(TBinarySearchTree* original, TBinarySearchTree* copia){
    if (esArbolBusquedaVacio(original)){
        crearArbolBusquedaVacio(copia);
    }
    else{
        TBinarySearchTree hi,hd;
        asignarArbolBusqueda(&(*original)->left,&hi);
        asignarArbolBusqueda(&(*original)->right,&hd);
        TNodeSearchTree* aux =(TNodeSearchTree*)malloc(sizeof(TNodeSearchTree));
        aux->left=hi;
        aux->right=hd;
        asignarElemento(&(*original)->info,&aux->info);
        *copia=aux;
    }
}
int esArbolBusquedaVacio(TBinarySearchTree* a){
    return *a == NULL;
}


void menorNodo( TElemento* e,TBinarySearchTree* a){
    if(!esArbolBusquedaVacio(a)){
        TNodeSearchTree* act = *a;
        TNodeSearchTree* ant =NULL;
        while (act!=NULL){
            ant=act;
            act=act->left;
        }
        if (ant)
            asignarElemento(&ant->info,e);
    }
}
void mayorNodo(TElemento* e,TBinarySearchTree* a){
        if(!esArbolBusquedaVacio(a)){
            TNodeSearchTree* act = *a;
            TNodeSearchTree* ant =NULL;
            while (act!=NULL){
                ant=act;
                act=act->right;
            }
            if (ant)
                asignarElemento(&ant->info,e);
        }
}

int numeroNodos(TBinarySearchTree* a){
    if (esArbolBusquedaVacio(a))
        return 0;
    else
    {
        return 1 + numeroNodos(&(*a)->left) + numeroNodos(&(*a)->right);
    }
}
int numeroHojas(TBinarySearchTree* a){
    if (esArbolBusquedaVacio(a))
        return 1;
    else
        return numeroHojas(&(*a)->left) + numeroHojas(&(*a)->right);
}
int altura(TBinarySearchTree* a){
    if (esArbolBusquedaVacio(a))
        return 0;
    else
    {
        return 1 + ((altura(&(*a)->left) > altura(&(*a)->right)) ? altura(&(*a)->left) : altura(&(*a)->right));
    }
}
void preorden(TBinarySearchTree* a, TLista* r){
    if (esArbolBusquedaVacio(a))
        return;
    else
    {
        preorden(&(*a)->left, r);
        TLista aux;
        crearListaVacia(&aux);
        preorden(&(*a)->right, r);
        concatenarLista(r, &aux);
        destruirLista(&aux);
        insertarLista(&(*a)->info, r);
        return;
    }
}
void inorden(TBinarySearchTree* a, TLista* r){
    if (esArbolBusquedaVacio(a))
        return;
    else
    {
        inorden(&(*a)->right, r);
        insertarLista(&(*a)->info, r);
        TLista aux;
        crearListaVacia(&aux);
        inorden(&(*a)->left, r);
        concatenarLista(r, &aux);
        destruirLista(&aux);
        return;
    }
}
void postorden(TBinarySearchTree* a, TLista* r){
    if (esArbolBusquedaVacio(a))
        return;
    else
    {
        postorden(&(*a)->left, r);
        insertarLista(&(*a)->info, r);
        TLista aux;
        crearListaVacia(&aux);
        postorden(&(*a)->right, r);
        concatenarLista(r, &aux);
        destruirLista(&aux);
        return;
    }
}

int contieneArbolBinarioBusqueda(TBinarySearchTree* a,TElemento* e){
    if (esArbolBusquedaVacio(a)){
        return 0;
    }
    else if(igualesElemento(e,&(*a)->info)){
        return 1;
    }
    else{
        if (mayorQue(&(*a)->info,e)){
            return contieneArbolBinarioBusqueda(&(*a)->left,e);
        }
        else{
            return contieneArbolBinarioBusqueda(&(*a)->right,e);
        }
    }
   
}

int igualArbolBusqueda(TBinarySearchTree* uno, TBinarySearchTree* dos)
{
    if (esArbolBusquedaVacio(uno) && esArbolBusquedaVacio(dos))
        return 1;
    else if (esArbolBusquedaVacio(uno) || esArbolBusquedaVacio(dos))
        return 0;
    else
    {
        if (igualesElemento(&(*uno)->info, &(*dos)->info)) {
            return igualArbolBusqueda(&(*uno)->left, &(*dos)->left) && igualArbolBusqueda(&(*uno)->right, &(*dos)->right);
        }
        else
            return 0;
    }
}