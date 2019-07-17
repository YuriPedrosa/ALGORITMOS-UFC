#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"
#include "fila.h"

void menu(){
  printf("\n--------------------MENU----------------------");
  printf("\nESCOLHA UMA DAS SEGUINTES OPCOES :");
  printf("\n1- Imprimir fila de doadores");
  printf("\n2- Imprimir pilha de cartas");
  printf("\n3- Imprimir lista de doacoes");
  printf("\n4- Cadastrar nova carta");
  printf("\n5- Cadastrar novo doador");
  printf("\n6- Receber doacao");
  printf("\n7- Sair");
  printf("\n");
}

void cadastrarCarta(Pilha* p){
    char nome[100];
    printf("Nome : ");
    scanf(" %[^\n]s",nome);
    int id;
    printf("ID : ");
    scanf("%d",&id);
    p_empilha(p,nome,id);
}

void cadastrarDoador(Fila* f){

    char nome[100];
    printf("Nome : ");
    scanf(" %[^\n]s",nome);
    char roupa[100];
    printf("Roupa : ");
    scanf(" %[^\n]s",roupa);
    char tam;
    printf("TAMANHOS APENAS: P,M,G\n");
    printf("Tamanho : ");
    scanf(" %[^\n]s",tam);
    f_insere(f,nome,roupa,tam);
}

Lista* doar(Lista* l, Fila* f, Pilha* p){
    if(p_pilhaVazia(p)){
        printf("Sem cartas");
    }else if(f_vazia(f)){
        printf("Sem doadores");
    }else{
        l = l_insere(l,f_retira(f),p_desempilha(p));
    }
    return l;
}

int main(){
    Pilha* p = p_cria();
    p_empilha(p,"Mago do Tempo",1);
    p_empilha(p,"Dragao Bebe",2);
    p_empilha(p,"Dragao Branco de Olhos Azuis",3);

    Fila* f = f_cria();
    f_insere(f,"Yuri","Camiseta",'P');
    f_insere(f,"Teste","Camiseta",'M');
    f_insere(f,"Teste1","Camiseta",'G');

    Lista* l = l_cria();
    int i = 1;

    do {
      int opc;
      menu();
      scanf("%d",&opc);
      switch(opc){
        case 1:
          printf("Fila de doadores\n");
          f_imprime(f);
          break;
        case 2:
          printf("Pilha de cartas\n");
          p_imprime(p);
          break;
        case 3:
          printf("Lista de doacoes\n");
          l_imprime(l);
          break;
        case 4:
           cadastrarCarta(p);
           break;
        case 5:
           cadastrarDoador(f);
           break;
        case 6:
          l = doar(l,f,p);
          break;
        case 7:
          i = 0;
          break;
        default:
          printf("Opcao invalida");
          break;
      }
    } while(i);

    p_libera(p);
    f_libera(f);
    l_libera(l);
    return 0;
}
