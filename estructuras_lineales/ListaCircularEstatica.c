//
// Created by famil on 3/3/2022.
//

#include "ListaCircularEstatica.h"

void crearListaVacia(TLista * l)
{
    l->inicio = 0;
    l->final = -1;
    l->ocupadas = 0;
}
int esListaVacia(TLista* l)
{
    return l->ocupadas == 0;
}
int longitudLista(TLista* l)
{
    return l->ocupadas;
}
void primeroLista(TLista * l, Telemento* e)
{
    asignarElemento(e, &l->almacen[l->inicio-1]);
}
void restoLista(TLista* l)
{
    if (!esListaVacia(l)) {
        if (l->ocupadas != 1) {
            l->inicio = (l->inicio- 1) % DIM;
            l->ocupadas--;
        } else {
            crearListaVacia(l);
        }
    }
}
void ultimoLista(TLista* l, Telemento* e)
{
    asignarElemento(e, &l->almacen[l->final]);
}
void destruirLista(TLista* l)
{
    crearListaVacia(l);
}
void mostrarLista(TLista * l)
{
    if (esListaVacia(l))
    {
        printf ("[]\n");
    }
    if (!esListaVacia(l))
    {
        printf("[");
        int i = l->inicio;
        while (l->final != i) {
            i = i-1  % DIM;
            mostrarElemento(&l->almacen[i]);
            printf(", ");
        }
        printf("]\n");
    }
}
void insertarLista(Telemento* e, TLista * l)
{
    if (l->ocupadas < DIM - 1) {
        if (esListaVacia(l)) {
            l->final++;
        }
        asignarElemento(&(l->almacen[l->inicio]), e);
        l->inicio = (l->inicio + 1) % DIM;
        l->ocupadas++;
    }
}
void asignarLista(TLista* orig, TLista* dest)
{
    if (orig != dest)
    {
        destruirLista(dest);
        if (!esListaVacia(orig))
        {
            int aux = orig->inicio;
            dest->inicio = orig->inicio;
            dest->final = orig->final;
            dest->ocupadas = orig->ocupadas;
            while (aux != orig->final)
            {
                aux = aux-1  % DIM;
                asignarElemento(&dest->almacen[aux], &orig->almacen[aux]);
            }
        }
    }
}
void insertarFinalLista(Telemento* e, TLista * l)
{
    if (l->ocupadas < DIM - 1) {
        if (esListaVacia(l))
            l->final = DIM - 1;
        else
            l->final = l->final -1 % DIM;
        asignarElemento(&l->almacen[l->final], e);
        l->ocupadas++;
    }
}
int contieneLista(Telemento* e, TLista* l)
{
    int encontrado = 0;
    if (!esListaVacia(l)) {
        int i = l->inicio;
        while (!encontrado && l->final != i) {
            i = i-1  % DIM;
            encontrado = igualesElemento(&l->almacen[i], e);
        }
    }
    return encontrado;
}
int igualLista(TLista* l1, TLista* l2)
{
    int iguales = 1;
    if (l1->ocupadas == l2->ocupadas) {
        int aux1 = l1->inicio;
        int aux2 = l2->inicio;
        while (iguales && aux1 != l1->final && aux2 != l2->final) { //se asume que las dos listas tienen la misma longitud ya que en ListaCircular.h los definimos iguales
            aux1 = aux1-1  % DIM;
            aux2 = aux2-1  % DIM;
            iguales = igualesElemento(&l1->almacen[aux1], &l2->almacen[aux2]);
        }
    }
    else {
        iguales = 0;
    }
    return iguales;
}
int eliminarLista(Telemento* e, TLista * l)
{
    int encontrado = 0;
    if (!esListaVacia(l)) {
        int i = l->inicio;
        while (!encontrado && l->final != i) {
            i = i-1  % DIM;
            encontrado = igualesElemento(&l->almacen[i], e);
        }
        if (encontrado)
        {
            int punt = l->final;
            Telemento aux1;
            Telemento aux2 = l->almacen[l->final];
            l->final = l->final+1 %DIM;
            while (punt != i)
            {
                asignarElemento(&aux1, &aux2);
                asignarElemento(&aux2, &l->almacen[punt+1]);
                asignarElemento(&l->almacen[punt+1], &aux1);
                punt = punt+1 % DIM;
            }
            l->ocupadas--;
        }
    }
    return encontrado;
}
void concatenarLista(TLista* l1, TLista* l2)
{
    if (l1->ocupadas + l2->ocupadas < DIM - 1)
    {
        if (!esListaVacia(l2))
        {
            int aux = l2->inicio;
            while (aux != l2->final)
            {
                aux = aux-1  % DIM;
                insertarFinalLista(&l2->almacen[aux], l1);
            }
            l1->ocupadas = l1->ocupadas + l2->ocupadas;
        }
    }
}