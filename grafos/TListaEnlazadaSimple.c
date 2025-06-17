//
// Created by alfon on 09/03/2021.
//

#include "TListaEnlazadaSimple.h"
#include "stdlib.h"
#include "stdio.h"

void crearListaVacia (TLista* l){
    *l=NULL;
}

void mostrarLista (TLista* l){
    TLista aux =*l;
    while(aux!=NULL){ //  while(aux)
        mostrarElemento(&aux->info);
        aux=aux->sig;
    }
}


void insertarLista (TElemento* e, TLista* l){ //Inserta un elemento en la cabecera de la lista
  TNodo* aux = (TNodo*)  malloc(1*sizeof(TNodo));
  //TLista aux = (TLista)  malloc(1*sizeof(TNodo));
  asignarElemento(e,&aux->info);
  aux->sig=*l;
  *l=aux;//actualizar cabecera lista
}


void insertarFinalLista (TElemento* e, TLista* l){
   if(esListaVacia(l)){ //si va a ser el primero también
       insertarLista(e,l);
   }
   else{
          TLista aux =*l;
          while(aux->sig!=NULL){//while (aux->sig)
              aux=aux->sig;
          }
          TNodo* auxN= (TNodo*) malloc(1*sizeof(TNodo));
          auxN->sig=NULL;
          asignarElemento(e,&auxN->info);
          aux->sig=auxN;
   }
}


int eliminarLista (TElemento* e, TLista* l){ //borra la primera aparicion de e
    TNodo* act = *l;
    TNodo* ant = NULL;
    int encontrado =0;
    while (act!=NULL && (!encontrado)){
        encontrado=igualElemento(&act->info,e);
        if(encontrado){
            if(ant==NULL){ //primero de la lista
                (*l)=(*l)->sig;
            }
            else{
                ant->sig=act->sig;
            }
            free(act);
        }
        else{ //no es el actual
            ant=act;
            act=act->sig;
        }
    }
    return encontrado;
}
void primeroLista(TElemento* e, TLista* l){ //Condicion: Lista No vacia
    if(!esListaVacia(l)){
        asignarElemento(&(*l)->info,e);
    }
    else{
        printf("La lista esta vacia\n");
    }
 }
void restoLista (TLista* l){ //Condicion: Lista No vacia
    if(!esListaVacia(l)){
        TLista aux= *l;
        *l=(*l)->sig;
        free(aux);
    }
}
void ultimoLista(TElemento* e, TLista* l){//Condicion: Lista No vacia
    if(!esListaVacia(l)){
        TLista aux=*l;
        while(aux->sig!=NULL){//aux->sig
            aux=aux->sig;
        }
        asignarElemento(&aux->info,e);

    }
    else{
        printf("La lista esta vacia\n");
    }

}
void concatenarLista (TLista* l1, TLista* l2){
    //en esta implementación no hay problemas con que ambas sean la misma
    TLista auxL;//no la creo vacía porque sé que la voy a crear después, en asignarLista
    crearListaVacia(&auxL);//para evitar problemas con las reservas de memoria
    asignarLista(l2,&auxL);
    if(esListaVacia(l1)){
        *l1=auxL;
    }
    else{
        TNodo* aux=*l1;
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig=auxL;
    }
}

int contieneLista (TElemento* e, TLista* l){
    TLista aux=*l;
    int encontrado = 0;
    while((aux!=NULL)&&(!encontrado)){
        encontrado=igualElemento(&aux->info,e);
        if(!encontrado){
            aux=aux->sig;
        }
    }
    return encontrado;
}
int esListaVacia (TLista* l){
    return *l==NULL;//return !(*l)
}
int longitudLista (TLista* l){
    TLista aux=*l;
    int longitud = 0;
    while((aux!=NULL)){
        longitud++;
         aux=aux->sig;
     }
    return longitud;

}
int igualLista (TLista* l1, TLista* l2){
    TLista aux1=*l1;
    TLista aux2=*l2;
    int iguales =1;
    while(iguales&&aux1!=NULL&&aux2!=NULL){ // (iguales&&aux1&&aux2
        iguales = igualElemento(&aux1->info,&aux2->info);
        aux1=aux1->sig;
        aux2=aux2->sig;
    }
    return iguales&&(aux1==NULL)&&(aux2==NULL);//return iguales&&!aux1&&!aux2
}

void asignarLista (TLista* original, TLista* copia){
    if(*original!=*copia){//si no son los mismos punteros. Así evitamos hacer una asignación sobre si mismo
        crearListaVacia(copia);//destruirLista(copia)
        if(!esListaVacia(original)){
            TNodo* auxO =*original;
            TNodo* aux = (TNodo*) malloc(1*sizeof(TNodo));
            asignarElemento(&auxO->info,&aux->info);
            aux->sig=NULL;
            *copia=aux;
            TNodo* ant = aux;
            auxO=auxO->sig;
            while(auxO!=NULL){
                TNodo* aux = (TNodo*) malloc(1*sizeof(TNodo));
                asignarElemento(&auxO->info,&aux->info);
                aux->sig=NULL;
                ant->sig= aux;
                auxO=auxO->sig;
                ant=aux;
            }
        }
    }

}

void destruirLista(TLista* l){
    while(!esListaVacia(l)){
        restoLista(l);
    }
}