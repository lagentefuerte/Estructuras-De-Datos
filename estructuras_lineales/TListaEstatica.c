//
// Created by franciscojose.garcia on 17/02/2022.
//

#include "TListaEstatica.h"

void crearListaVacia(TLista * l) {
    l->indice = -1;
}

int esListaVacia(TLista* l) {
    return l->indice == -1;
}

int longitudLista(TLista* l) {
    return l->indice+1;
}

void primeroLista(TLista * l, TElemento* e) {
    if (!esListaVacia(l)) {
        asignarElemento(&l->almacen[l->indice], e);
    }
}

void restoLista(TLista* l) {
    if (!esListaVacia(l)) {
        l->indice--;
    }
}

void ultimoLista(TLista* l, TElemento* e) {
    if (!esListaVacia(l)) {
        asignarElemento(&l->almacen[0], e);
    }
}

void destruirLista(TLista* l) {
    l->indice = -1;
}

void mostrarLista(TLista * l) {
    if (esListaVacia(l)) {
        printf("[]\n");
    } else {
        printf("[");
        for (int i = l->indice; i > -1; i--) {
            mostrarElemento(&l->almacen[i]);
            printf(", ");
        }
        printf("]\n");
    }
}

void insertarLista(TElemento* e, TLista * l) {
    if (longitudLista(l) < DIM) {
        l->indice++;
        asignarElemento(e, &l->almacen[l->indice]);
    } else {
        printf("ERROR: La lista esta llena\n");
    }
}

void asignarLista(TLista* orig, TLista* dest) {
    if (orig != dest) {
        dest->indice = orig->indice;
        for (int i = 0; i < longitudLista(orig); i++) {
            asignarElemento(&orig->almacen[i], &dest->almacen[i]);
        }
    }
}

void insertarFinalLista(TElemento* e, TLista * l) {
    if (longitudLista(l) < DIM) {
        for (int i = l->indice; i > -1; i--) {
            asignarElemento(&l->almacen[i], &l->almacen[i+1]);
        }
        asignarElemento(e, &l->almacen[0]);
        l->indice++;
    } else {
        printf("ERROR: La lista esta llena\n");
    }
}

int contieneLista(TElemento* e, TLista* l) {
    int encontrado = 0;
    int i = l->indice;
    while (!encontrado && i > -1) {
        encontrado = igualesElemento(&l->almacen[i], e);
        i--;
    }
    return encontrado;
}

int igualLista(TLista* l1, TLista* l2) {
    if (longitudLista(l1) == longitudLista(l2)) {
        int i = 0;
        while(i < l1->indice && igualesElemento(&l1->almacen[i], &l2->almacen[i])) {
            i++;
        }
        return igualesElemento(&l1->almacen[i], &l2->almacen[i]);
    } else {
        return 0;
    }
}

int eliminarLista(TElemento* e, TLista * l) {
    int encontrado = 0;
    int i = l->indice;
    while (!encontrado && (i > -1)) {
        encontrado = igualesElemento(&l->almacen[i], e);
        i--;
    }
    if (encontrado) {
        for (int j = i; j < l->indice; j++) {
            asignarElemento(&l->almacen[j+1], &l->almacen[j]);
        }
        l->indice--;
    }
    return encontrado;
}

void concatenarLista(TLista* l1, TLista* l2) {
    if (longitudLista(l1) + longitudLista(l2) <= DIM) {
        int offset = longitudLista(l2);
        for (int i = l1->indice; i > -1; i--) {
            asignarElemento(&l1->almacen[i], &l1->almacen[i+offset]);
        }
        if (l1 != l2) {
            for (int i = l2->indice; i > -1; i--) {
                asignarElemento(&l2->almacen[i], &l1->almacen[i]);
            }
        }
        l1->indice += offset;
    } else {
        printf("ERROR: No hay sitio para concatenar las listas\n");
    }
}