#include "TConjuntoDinamico.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"

void crearConjuntoVacio (set* l){
    *l=NULL;
}

void mostrarConjunto (set* l){
    set aux =*l;
    while(aux!=NULL){ //  while(aux)
        mostrarElemento(&aux->info);
        aux=aux->sig;
    }
}


void poner (TElemento* e, set* l){ //Inserta un elemento en la cabecera de la Conjunto
  if(!pertenece(e,l)){
      TNodoConjunto* aux = (TNodoConjunto*)  malloc(1*sizeof(TNodoConjunto));
      //set aux = (set)  malloc(1*sizeof(TNodoConjunto));
      asignarElemento(e,&aux->info);
      aux->sig=*l;
      *l=aux;//actualizar cabecera Conjunto
  }
}


int quitar (TElemento* e, set* l){ //borra la primera aparicion de e
    TNodoConjunto* act = *l;
    TNodoConjunto* ant = NULL;
    int encontrado =0;
    while (act!=NULL && (!encontrado)){
        encontrado=igualElemento(&act->info,e);
        if(encontrado){
            if(ant==NULL){ //primero de la Conjunto
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



void elegir(TElemento* e, set* l){//Condicion: Conjunto No vacia
    if(!esConjuntoVacio(l)){
        int cantidad = cardinal(l);
        srand(time(NULL));
        int r = rand()%cantidad;
        set aux=*l;
        int i =0;
        while(i!=r){//aux->sig
            aux=aux->sig;
            i++;
        }
        asignarElemento(&aux->info,e);
    }
    else{
        printf("La Conjunto esta vacia\n");
    }
}


void unir (set* l1, set* l2, set* u){
    asignarConjunto(l1,u);
    TNodoConjunto* aux=*l2;
        while(aux!=NULL){
            poner(&aux->info,u);
            aux=aux->sig;
        }
}

void interseccion (set* l1, set* l2, set* i){
    TNodoConjunto* aux=*l1;
    while(aux!=NULL){
        if (pertenece(&aux->info,l2)){
            poner(&aux->info,i);
        }
        aux=aux->sig;
    }
}

void diferencia (set* l1, set* l2, set* d){
    TNodoConjunto* aux=*l1;
    while(aux!=NULL){
        if (!pertenece(&aux->info,l2)){
            poner(&aux->info,d);
        }
        aux=aux->sig;
    }
}


int esSubconjunto (set* l1, set* l2){//l2 esta dentro de l1?
    TNodoConjunto* aux=*l2;
    int resultado=1;
    while(aux!=NULL && resultado){
        resultado=pertenece(&aux->info,l1);
        aux=aux->sig;
    }
    return resultado;
}






int pertenece (TElemento* e, set* l){
    set aux=*l;
    int encontrado = 0;
    while((aux!=NULL)&&(!encontrado)){
        encontrado=igualElemento(&aux->info,e);
        if(!encontrado){
            aux=aux->sig;
        }
    }
    return encontrado;
}
int esConjuntoVacio (set* l){
    return *l==NULL;//return !(*l)
}

int cardinal (set* l){
    set aux=*l;
    int longitud = 0;
    while((aux!=NULL)){
        longitud++;
         aux=aux->sig;
     }
    return longitud;

}

    
int igualConjunto (set* l1, set* l2){
   return esSubconjunto(l1,l2)&&esSubconjunto(l2,l1);

}



void asignarConjunto (set* original, set* copia){
    if(*original!=*copia){//si no son los mismos punteros. Así evitamos hacer una asignación sobre si mismo
        crearConjuntoVacio(copia);//destruirConjunto(copia)
        if(!esConjuntoVacio(original)){
            TNodoConjunto* auxO =*original;
            TNodoConjunto* aux = (TNodoConjunto*) malloc(1*sizeof(TNodoConjunto));
            asignarElemento(&auxO->info,&aux->info);
            aux->sig=NULL;
            *copia=aux;
            TNodoConjunto* ant = aux;
            auxO=auxO->sig;
            while(auxO!=NULL){
                TNodoConjunto* aux = (TNodoConjunto*) malloc(1*sizeof(TNodoConjunto));
                asignarElemento(&auxO->info,&aux->info);
                aux->sig=NULL;
                ant->sig= aux;
                auxO=auxO->sig;
                ant=aux;
            }
        }
    }

}

//Funcion auxiliar
void restoConjunto (set* l){ //Condicion: Conjunto No vacia
    if(!esConjuntoVacio(l)){
        set aux= *l;
        *l=(*l)->sig;
        free(aux);
    }
}

void destruirConjunto(set* l){
    while(!esConjuntoVacio(l)){
        restoConjunto(l);
    }
}