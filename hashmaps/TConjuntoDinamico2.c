#include "TConjuntoDinamico2.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"

void crearConjuntoVacio2 (set2* l){
    *l=NULL;
}

void mostrarConjunto2 (set2* l){
    set2 aux =*l;
    while(aux!=NULL){ //  while(aux)
        mostrarValor(&aux->info);
        aux=aux->sig;
    }
}


void poner2 (TValor* e, set2* l){ //Inserta un Valor en la cabecera de la Conjunto
  if(!pertenece2(e,l)){
      TNodoConjunto2* aux = (TNodoConjunto2*)  malloc(1*sizeof(TNodoConjunto2));
      //set2 aux = (set2)  malloc(1*sizeof(TNodoConjunto2));
      asignarValor(e,&aux->info);
      aux->sig=*l;
      *l=aux;//actualizar cabecera Conjunto
  }
}


int quitar2 (TValor* e, set2* l){ //borra la primera aparicion de e
    TNodoConjunto2* act = *l;
    TNodoConjunto2* ant = NULL;
    int encontrado =0;
    while (act!=NULL && (!encontrado)){
        encontrado=igualValor(&act->info,e);
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



void elegir2(TValor* e, set2* l){//Condicion: Conjunto No vacia
    if(!esConjuntoVacio2(l)){
        int cantidad = cardinal2(l);
        srand(time(NULL));
        int r = rand()%cantidad;
        set2 aux=*l;
        int i =0;
        while(i!=r){//aux->sig
            aux=aux->sig;
            i++;
        }
        asignarValor(&aux->info,e);
    }
    else{
        printf("La Conjunto esta vacia\n");
    }
}


void unir2 (set2* l1, set2* l2, set2* u){
    asignarConjunto2(l1,u);
    TNodoConjunto2* aux=*l2;
        while(aux!=NULL){
            poner2(&aux->info,u);
            aux=aux->sig;
        }
}

void interseccion2 (set2* l1, set2* l2, set2* i){
    TNodoConjunto2* aux=*l1;
    while(aux!=NULL){
        if (pertenece2(&aux->info,l2)){
            poner2(&aux->info,i);
        }
        aux=aux->sig;
    }
}

void diferencia2 (set2* l1, set2* l2, set2* d){
    TNodoConjunto2* aux=*l1;
    while(aux!=NULL){
        if (!pertenece2(&aux->info,l2)){
            poner2(&aux->info,d);
        }aux=aux->sig;
    }
}


int esSubconjunto2 (set2* l1, set2* l2){//l2 esta dentro de l1?
    TNodoConjunto2* aux=*l2;
    int resultado=1;
    while(aux!=NULL && resultado){
        resultado=pertenece2(&aux->info,l1);
        aux=aux->sig;
    }
    return resultado;
}






int pertenece2 (TValor* e, set2* l){
    set2 aux=*l;
    int encontrado = 0;
    while((aux!=NULL)&&(!encontrado)){
        encontrado=igualValor(&aux->info,e);
        if(!encontrado){
            aux=aux->sig;
        }
    }
    return encontrado;
}
int esConjuntoVacio2 (set2* l){
    return *l==NULL;//return !(*l)
}

int cardinal2 (set2* l){
    set2 aux=*l;
    int longitud = 0;
    while((aux!=NULL)){
        longitud++;
         aux=aux->sig;
     }
    return longitud;

}

    
int igualConjunto2 (set2* l1, set2* l2){
   return esSubconjunto2(l1,l2)&&esSubconjunto2(l2,l1);

}



void asignarConjunto2 (set2* original, set2* copia){
    if(*original!=*copia){//si no son los mismos punteros. Así evitamos hacer una asignación sobre si mismo
        crearConjuntoVacio2(copia);//destruirConjunto(copia)
        if(!esConjuntoVacio2(original)){
            TNodoConjunto2* auxO =*original;
            TNodoConjunto2* aux = (TNodoConjunto2*) malloc(1*sizeof(TNodoConjunto2));
            asignarValor(&auxO->info,&aux->info);
            aux->sig=NULL;
            *copia=aux;
            TNodoConjunto2* ant = aux;
            auxO=auxO->sig;
            while(auxO!=NULL){
                TNodoConjunto2* aux = (TNodoConjunto2*) malloc(1*sizeof(TNodoConjunto2));
                asignarValor(&auxO->info,&aux->info);
                aux->sig=NULL;
                ant->sig= aux;
                auxO=auxO->sig;
                ant=aux;
            }
        }
    }

}

//Funcion auxiliar
void restoConjunto2 (set2* l){ //Condicion: Conjunto No vacia
    if(!esConjuntoVacio2(l)){
        set2 aux= *l;
        *l=(*l)->sig;
        free(aux);
    }
}

void destruirConjunto2(set2* l){
    while(!esConjuntoVacio2(l)){
        restoConjunto2(l);
    }
}