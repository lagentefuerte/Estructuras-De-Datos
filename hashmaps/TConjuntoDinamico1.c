#include "TConjuntoDinamico1.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"

void crearConjuntoVacio1 (set1* l){
    *l=NULL;
}

void mostrarConjunto1 (set1* l){
    set1 aux =*l;
    while(aux!=NULL){ //  while(aux)
        mostrarClave(&aux->info);
        aux=aux->sig;
    }
}


void poner1 (TClave* e, set1* l){ //Inserta un Clave en la cabecera de la Conjunto
  if(!pertenece1(e,l)){
      TNodoConjunto1* aux = (TNodoConjunto1*)  malloc(1*sizeof(TNodoConjunto1));
      //set1 aux = (set1)  malloc(1*sizeof(TNodoConjunto1));
      asignarClave(e,&aux->info);
      aux->sig=*l;
      *l=aux;//actualizar cabecera Conjunto
  }
}


int quitar1 (TClave* e, set1* l){ //borra la primera aparicion de e
    TNodoConjunto1* act = *l;
    TNodoConjunto1* ant = NULL;
    int encontrado =0;
    while (act!=NULL && (!encontrado)){
        encontrado=igualClave(&act->info,e);
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



void elegir1(TClave* e, set1* l){//Condicion: Conjunto No vacia
    if(!esConjuntoVacio1(l)){
        int cantidad = cardinal1(l);
        srand(time(NULL));
        int r = rand()%cantidad;
        set1 aux=*l;
        int i =0;
        while(i!=r){//aux->sig
            aux=aux->sig;
            i++;
        }
        asignarClave(&aux->info,e);
    }
    else{
        printf("La Conjunto esta vacia\n");
    }
}


void unir1 (set1* l1, set1* l2, set1* u){
    asignarConjunto1(l1,u);
    TNodoConjunto1* aux=*l2;
        while(aux!=NULL){
            poner1(&aux->info,u);
            aux=aux->sig;
        }
}

void interseccion1 (set1* l1, set1* l2, set1* i){
    TNodoConjunto1* aux=*l1;
    while(aux!=NULL){
        if (pertenece1(&aux->info,l2)){
            poner1(&aux->info,i);
        }
        aux=aux->sig;
    }
}

void diferencia1 (set1* l1, set1* l2, set1* d){
    TNodoConjunto1* aux=*l1;
    while(aux!=NULL){
        if (!pertenece1(&aux->info,l2)){
            poner1(&aux->info,d);
        }
        aux=aux->sig;
    }
}


int esSubconjunto1 (set1* l1, set1* l2){//l2 esta dentro de l1?
    TNodoConjunto1* aux=*l2;
    int resultado=1;
    while(aux!=NULL && resultado){
        resultado=pertenece1(&aux->info,l1);
        aux=aux->sig;
    }
    return resultado;
}






int pertenece1 (TClave* e, set1* l){
    set1 aux=*l;
    int encontrado = 0;
    while((aux!=NULL)&&(!encontrado)){
        encontrado=igualClave(&aux->info,e);
        if(!encontrado){
            aux=aux->sig;
        }
    }
    return encontrado;
}
int esConjuntoVacio1 (set1* l){
    return *l==NULL;//return !(*l)
}

int cardinal1 (set1* l){
    set1 aux=*l;
    int longitud = 0;
    while((aux!=NULL)){
        longitud++;
         aux=aux->sig;
     }
    return longitud;

}

    
int igualConjunto1 (set1* l1, set1* l2){
   return esSubconjunto1(l1,l2)&&esSubconjunto1(l2,l1);

}



void asignarConjunto1 (set1* original, set1* copia){
    if(*original!=*copia){//si no son los mismos punteros. Así evitamos hacer una asignación sobre si mismo
        crearConjuntoVacio1(copia);//destruirConjunto(copia)
        if(!esConjuntoVacio1(original)){
            TNodoConjunto1* auxO =*original;
            TNodoConjunto1* aux = (TNodoConjunto1*) malloc(1*sizeof(TNodoConjunto1));
            asignarClave(&auxO->info,&aux->info);
            aux->sig=NULL;
            *copia=aux;
            TNodoConjunto1* ant = aux;
            auxO=auxO->sig;
            while(auxO!=NULL){
                TNodoConjunto1* aux = (TNodoConjunto1*) malloc(1*sizeof(TNodoConjunto1));
                asignarClave(&auxO->info,&aux->info);
                aux->sig=NULL;
                ant->sig= aux;
                auxO=auxO->sig;
                ant=aux;
            }
        }
    }

}

//Funcion auxiliar
void restoConjunto1 (set1* l){ //Condicion: Conjunto No vacia
    if(!esConjuntoVacio1(l)){
        set1 aux= *l;
        *l=(*l)->sig;
        free(aux);
    }
}

void destruirConjunto1(set1* l){
    while(!esConjuntoVacio1(l)){
        restoConjunto1(l);
    }
}