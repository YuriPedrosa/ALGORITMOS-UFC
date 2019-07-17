#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "fila.h"
#include "pilha.h"

struct lista{
    Pessoa* p;
    Cartas* c;
    struct lista* prox;
};

Lista* l_cria(){
    return NULL;
}

Lista* l_insere(Lista* l, Pessoa* p, Cartas* c){
  if(p == NULL || c == NULL){
    return l;
  }
    Lista* x = (Lista*) malloc(sizeof(Lista));
    x->c = c;
    x->p = p;
    x->prox = l;
    return x;
}

void l_imprime(Lista* l){
   while(l != NULL){
        f_imprimePessoa(l->p);
        p_imprimeCarta(l->c);
        l = l->prox;
    }
}

void l_libera(Lista* l){

  while(l != NULL){
    Lista* aux = l;
    l = l->prox;
    free(aux->p);
    free(aux->c);
    free(aux);
  }
}
