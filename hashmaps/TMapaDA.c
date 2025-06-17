//
// Created by ASUS on 5/8/2022.
//

#include "TMapaAbierto.h"

int hashPDA (TClave * c)
{
    return hash(c) %Dim;
}

void crearMapaVacioDA (Mapa* a)
{
    for (int i = 0; i < Dim; ++i) {
        (*a)[i].disponible = 1;
    }
}
void mostrarMapaDA (Mapa* a)
{
    for (int i = 0; i < Dim; ++i) {
        mostrarElemento(&(*a)[i].e);
    }
}
void ponerMapaDA (TClave* c, TValor* e, Mapa* a)
{
    int posicion = hashPDA(c);
    TElemento aux;
    crearElemento(c, e, &aux);
    if ((*a)[posicion].disponible != 0) {
        asignarElemento(&aux, &(*a)[posicion].e);
        (*a)[posicion].disponible = 0;
    } else {
        int stop = posicion;
        posicion = posicion + 1 % Dim;
        while ((*a)[posicion].disponible == 0 && posicion != stop) {
            posicion = posicion + 1 % Dim;
        }
        if (posicion != stop) {
            asignarElemento(&aux, &(*a)[posicion].e);
            (*a)[posicion].disponible = 0;
        }
    }
}

void devolverDA (TClave* c, TValor* v, Mapa* a)
{
    int posicion = hashPDA(c);
    if ((*a)[posicion].disponible == 0) {
        TClave elemento;
        getClave(&(*a)[posicion].e, &elemento);
        if (igualClave(&elemento, c))
            getValor(&(*a)[posicion].e, v);
        else {
            int encontrado = 0;
            int aux = posicion;
            posicion = posicion + 1 % Dim;
            while ((*a)[posicion].disponible == 0 && !encontrado && posicion != aux)
            {
                getClave(&(*a)[posicion].e, &elemento);
                if (igualClave(&elemento, c)) {
                    getValor(&(*a)[posicion].e, v);
                    encontrado = 1;
                }
                posicion = posicion + 1 % Dim;
            }
        }
    }
}
int esMapaVacioDA (Mapa* a)
{
    return sizeMapaDA(a) == 0;
}
int sizeMapaDA (Mapa* a)
{
    int suma = 0;
    for (int i = 0; i < Dim; ++i) {
        if ((*a)[i].disponible == 1)
            suma+= 1;
    }
    return suma;
}
int quitarMapaDA (TClave* c, Mapa* a)
{
    int encontrado = 0;
    int posicion = hashPDA(c);
    if ((*a)[posicion].disponible == 0) {
        TClave elemento;
        getClave(&(*a)[posicion].e, &elemento);
        if (igualClave(&elemento, c)) {
            (*a)[posicion].disponible = 2;
            encontrado = 1;
        }
        else {
            int aux = posicion;
            posicion = posicion +1 %Dim;
            while ((*a)[posicion].disponible == 0 && !encontrado && posicion != aux)
            {
                getClave(&(*a)[posicion].e, &elemento);
                if (igualClave(&elemento, c)) {
                    (*a)[posicion].disponible = 2;
                    encontrado = 1;
                }
                posicion = posicion +1 %Dim;
            }
        }
    }
    return encontrado;
}
void conjuntoEntradasDA (set* e, Mapa* h)
{
    for (int i = 0; i < Dim; ++i) {
        if ((*h)[i]. disponible == 0)
        {
            poner(&(*h)[i].e, e);
        }
    }
}
void conjuntoClavesDA (set1* e, Mapa* h)
{
    for (int i = 0; i < Dim; ++i) {
        if ((*h)[i]. disponible == 0)
        {
            TClave aux;
            getClave(&(*h)[i].e, &aux);
            poner1(&aux, e);
        }
    }
}
void conjuntoValoresDA (set2* e, Mapa* h)
{
    for (int i = 0; i < Dim; ++i) {
        if ((*h)[i]. disponible == 0)
        {
            TValor aux;
            getValor(&(*h)[i].e, &aux);
            poner2(&aux, e);
        }
    }
}
void asignarMapaDA(Mapa* original, Mapa* copia)
{
    for (int i = 0; i < Dim; ++i) {
        (*copia)[i].disponible = (*original)[i].disponible;
        if ((*copia)[i].disponible == 0)
            asignarElemento(&(*copia)[i].e, &(*original)[i].e);
    }
}
void destruirMapaDA(Mapa* a)
{
    crearMapaVacioDA(a);
}