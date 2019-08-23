#include "libsequ.h"

void criar(Tlista *L){	
	memset(L->elemento, 0, sizeof(L->elemento)); 
    L->n = 0;
}
    
int tamanho(Tlista L){
    return (L.n);
}

int elemento(Tlista L, int pos, Telemento *valor){
    if(pos<1 || pos> MAX)
    	return 0;
    *valor = L.elemento[pos];
	return 1;
}

void exibir(Tlista L){
	int i = 0,j = 0;
	int t = tamanho(L);

	if(t == 0)
		printf("Nao ha elementos na lista");
	
	while(j < t){
		if(L.elemento[i].dado.cartao != 0){
			printf("----------Dados----------\n");
			printf("Nome: %s\n", L.elemento[i].dado.nome);
			printf("Cartao: %d\n", L.elemento[i].dado.cartao);
			printf("Bandeira: %d\n", L.elemento[i].dado.bandeira);
			printf("Codigo de verificacao: %d\n", L.elemento[i].dado.cod_verificador);			
			printf("----------Boleto----------\n");
			printf("Codigo do boleto: %d\n", L.elemento[i].boleto.cod_barras);
			printf("Valor: %f\n", L.elemento[i].boleto.valor);
			j++;
		}
		i++;
	}
} 

void inserir(Tlista *L, int hash, Telemento dado){
	L->elemento[hash] = dado;
    L->n++;
}

int hashing(int chave){
	int tamanho = 0, hash, i;
	int aux = chave;
	int *v;
	
	do{
		tamanho++;
		aux /= 10;
	}
	while(aux!=0);
	
	v = (int *) malloc(tamanho * sizeof(int));
	
	//s[0] * 11^(n-1) + s[1] * 11^(n-2) + … s[n-1] * 11^(0);
		
	for( i = 0 ; i < tamanho ; i++ ){
		v[i] = chave % 10;
		chave /= 10;
	}
	
	aux = tamanho;
	for( i = 0 ; i < aux ; i++ ){
		hash += ( v[i]*pow(11,--tamanho) );
	}
	
	return (hash % MAX);
}
