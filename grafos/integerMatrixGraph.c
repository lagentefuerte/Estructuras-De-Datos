#include <stdio.h>
#include <stdlib.h>
#include "integerMatrixGraph.h"


void crearGrafoVacio (TMGraph* a){
    for (int i = 0; i<dim; i++)
    {
        a->nodes[i] = 0;
        for (int j = 0; j < dim; ++j) {
            a->matrix[i][j] = 0;
        }
    }
 }

void insertarVertice (int i, TMGraph* a){
    a->nodes[i] = 1;
}
void insertarArista (int lhs,int rhs, TMGraph* a){
    a->nodes[lhs] = 1;
    a->nodes[rhs] = 1;
    a->matrix[lhs][rhs] = 1;
    a->matrix[rhs][lhs] = 1;
}
int eliminarVertice (int i, TMGraph* a){
    if (a->nodes[i] == 0) {
        a->nodes[i] = 0;
        for (int j = 0; j < dim; j++)
            a->matrix[j][i] = 0;
        for (int j = 0; j < dim; j++)
            a->matrix[i][j] = 0;
        return 1;
    }
    else
        return 0;
}
void eliminarArista (int lhs,int rhs, TMGraph* a){
    a->matrix[lhs][rhs] = 0;
    a->matrix[rhs][lhs] = 0;
}
int esAdyacente(int lhs,int rhs,TMGraph* a){
    return a->matrix[lhs][rhs];
}
int contieneVertice (int i, TMGraph* a){
    return a->nodes[i];
}
int esGrafoVacio (TMGraph* a){
    int encontrado = 0;
    int i = 0;
    while (!encontrado && i != dim) {
        encontrado = a->nodes[i];
        i++;
    }
    return encontrado;
}
void listaVertices (TMGraph* a, TLista * l){
    for (int i = 0; i<dim; i++)
    {
        if (a->nodes[i])
        {
            TElemento e;
            crearElemento(i, &e);
            insertarLista(&e, l);
        }
    }
}
void conjuntoAristas (TMGraph* a,set* s){
    for (int i = 0; i<dim; i++)
    {
        for (int j = 0; j < dim; ++j) {
            if (a->matrix[i][j] == 1)
            {
                TElemento1 e;
                crearElemento1(i, j, &e);
                /* TElemento1 aux; //si no es dirigido
                crearElemento1(j, i, &aux);
                if (!pertenece(&aux, s)) */
                    poner(&e, s);
            }
        }
    }
}

void copiarG(TMGraph* original, TMGraph* copia){
    for (int i = 0; i<dim; i++)
    {
        copia->nodes[i] = original->nodes[i];
        for (int j = 0; j < dim; ++j) {
            copia->matrix[i][j] = original->matrix[i][j];
        }
    }
}
void destruirG(TMGraph* a){
    crearGrafoVacio(a);
}

int igualGrafo(TMGraph* original, TMGraph* copia){
    int iguales = 1;
    int i = 0, j = 0;
    while (iguales && i != dim) {
        iguales = igualElemento(&copia->nodes[i], &original->nodes[i]);
        while (j != dim && iguales) {
            iguales = igualElemento(&copia->matrix[i][j], &original->matrix[i][j]);
            j++;
        }
        i++;
    }
    return iguales;
}

