#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "fila.h"
#define s 100

struct roupa{
    char nome[s];
    char tamanho;
};

struct pessoa{
    char nome[s];
    Roupa* r;
    struct pessoa* prox;
};

struct fila{
    Pessoa* ini;
    Pessoa* fim;
};

Fila* f_cria(){
  Fila* f = (Fila*) malloc(sizeof(Fila));
  f->ini = NULL;
  f->fim = NULL;
  return f;
}

int f_vazia(Fila* f){
  return f->ini == NULL && f->fim == NULL;
}

void f_insere(Fila* f, char v[], char r[],char t){
    Pessoa* p = (Pessoa*) malloc(sizeof(Pessoa));
    strcpy(p->nome,v);
    Roupa* x = (Roupa*) malloc(sizeof(Roupa));
    strcpy(x->nome,r);
    x->tamanho = t;
    p->r = x;
    p->prox = NULL;
    if(f_vazia(f)){
        f->ini = p;
    }else{
        f->fim->prox = p;
    }
    f->fim = p;
}

Pessoa* f_retira(Fila* f){
    if(f_vazia(f)){
        printf("Fila vazia");
        return NULL;
    }else{
      Pessoa* x = f->ini;
      f->ini = f->ini->prox;
      x->prox = NULL;
      if(f->ini == NULL){
        f->fim = NULL;
      }
      return x;
    }
}

void f_imprimeRoupa(Roupa* r){
    printf("Roupa: %s Tamanho: %s\n",r->nome,r->tamanho);
}

void f_imprimePessoa(Pessoa* p){
  printf("Doador: %s \n",p->nome);
  f_imprimeRoupa(p->r);
}

void f_imprime(Fila* f){
    Pessoa* aux = f->ini;
    while(aux != NULL){
        f_imprimePessoa(aux);
        aux = aux->prox;
    }
}

void f_libera(Fila* f){
  while(f->ini != NULL){
    Pessoa* aux = f->ini;
    f->ini = f->ini->prox;
    free(aux->r);
    free(aux);
  }
  free(f);
}
