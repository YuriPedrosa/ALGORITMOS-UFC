#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "pilha.h"
#define n 50
#define s 100

struct cartas{
    char nome[s];
    int id;
};

struct pilha{
    int topo;
    Cartas* c[n];
};

void p_imprimeCarta(Cartas* c){
  printf("Carta: %s ID: %d\n",c->nome,c->id);
}

void p_imprime(Pilha* p){
  if(p_pilhaVazia(p)){
    printf("Nao ha cartas");
  }else{
    int i = 0;
    while(i < p->topo){
        p_imprimeCarta(p->c[i]);
        i++;
    }
  }
}

int p_pilhaVazia(Pilha* p){
	return p->topo==0;
}

int p_pilhaCheia(Pilha* p){
	return p->topo==n;
}

Pilha* p_cria(){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p->topo = 0;
	return p;
}

void p_empilha(Pilha* p, char v[], int id){
    if(p_pilhaCheia(p)){
        printf("Pilha cheia");
    }
    else{
        Cartas* cs = (Cartas*) malloc(sizeof(Cartas));
        strcpy(cs->nome,v);
        cs->id = id;
        p->c[p->topo++] = cs;
    }
}

Cartas* p_desempilha(Pilha* p){
    if(p_pilhaVazia(p)){
        printf("Sem Cartas");
        return NULL;
    }else{
      Cartas* c = p->c[--p->topo];
  	  return c;
    }
}

void p_libera(Pilha* p){
  free(p);
}
