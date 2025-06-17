#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define Dim 100

#include "arrayset.h"

void crearConjuntoVacio (set* a){
    a->indice=-1;
    
}

int esConjuntoVacio (set* a){
    return (a->indice==-1);
}

int cardinal (set* a){
    return (a->indice+1);
}

void mostrarConjunto (set* a){
    if (!esConjuntoVacio(a)){
        for (int i=a->indice;i>-1;i--){
            mostrarElemento1(&a->almacen[i]);
            printf(" ");
        }
        printf("\n");
    }    
}

void poner (TElemento1* e, set* a){
    if(a->indice<Dim-1){
        if(!pertenece(e,a)){
            (a->indice)++;
            asignarElemento1(e,&(a->almacen[a->indice]));
            }
    }
    else{
        printf("La lista esta llena");
    }
}

int quitar (TElemento1* e, set* a){
    int i = a->indice;
    int encontrado=0;
    while ((i>-1)&&(!encontrado)){ 
        encontrado=igualElemento1(&a->almacen[i],e);
        if (encontrado){
            for(int j=i;j<a->indice;j++){ 
                asignarElemento1(&(a->almacen[j+1]),&a->almacen[j]);
            }
            (a->indice)--;
            }
        else{
            i--;  
        }    
    }
    return encontrado;
}

int elegir (TElemento1* e, set* a){
    int l=cardinal(a);
    srand(time(NULL));   
    int r = rand()%l;
    asignarElemento1(&a->almacen[r],e);
}


void unir(set* a1, set* a2,set* u){
    asignarConjunto(a1,u);
    for(int Elemento1 = (a2->indice); Elemento1>-1;Elemento1--){
        poner(&a2->almacen[Elemento1],u);
    }

}

int pertenece (TElemento1* e, set* a){
    int esta=0;
    int i=-1;
    while ((i<(a->indice))&&(!esta)){
        i++;
        esta=igualElemento1(&a->almacen[i],e);
    }
    return esta;
}

void destruirConjunto(set* a){
    a->indice=-1;
}

void asignarConjunto(set* original, set* copia){
    copia->indice=original->indice;
    for(int i=0;i<=original->indice;i++){
        asignarElemento1(&original->almacen[i],&copia->almacen[i]);
    }
}

void interseccion (set* a1, set* a2, set* i){
    for(int j=0;j<=a1->indice;j++){
        if(pertenece(&a1->almacen[j],a2)){
            poner(&a1->almacen[j],i);
        }
    }
}
void diferencia (set* a1, set* a2, set* d){
    for(int i=0;i<=a1->indice;i++){
        if(!pertenece(&a1->almacen[i],a2)){
            poner(&a1->almacen[i],d);
        }
    }

}


int esSubconjunto (set* a1, set* a2){
    int resultado=1;
    for(int i=0;i<=a2->indice;i++){
        resultado=resultado&&(pertenece(&a2->almacen[i],a1));
    }
}


int igualConjunto(set* l1, set* l2){
    if (cardinal(l1)==cardinal(l2)){
        int i=0;
        int iguales = 1; 
        while ((i<=l2->indice) && (iguales)){
            	iguales=pertenece(&l1->almacen[i],l2);//nos lo aseguramos al tener igual cardinal
		i++;
        }
        return iguales;
    }
    else{
        return 0;
    }

}







