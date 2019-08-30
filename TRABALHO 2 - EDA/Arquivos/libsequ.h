#include<stdio.h>
#include<stdlib.h>
#include <math.h>

#define MAX 37
#define S 80

typedef struct{
	int cartao;
	char nome[S];
	int bandeira;
	int cod_verificador;
} Dados;

typedef struct{
	int cod_barras;
	float valor;
} Boleto;
   
typedef struct{
	Boleto boleto;
	Dados dado;
} Telemento;
 
typedef struct{
    Telemento elemento[MAX];
    int n;
} Tlista;

int hashing(int chave);
void criar(Tlista *);
int tamanho(Tlista);
int elemento(Tlista, int, Telemento *);
void exibir(Tlista L);
void inserir(Tlista *, int, Telemento);
float taxaOcupacao(Tlista);
int double_hashing(Tlista*, Telemento);

