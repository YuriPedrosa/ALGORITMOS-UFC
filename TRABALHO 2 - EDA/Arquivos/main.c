#include "libsequ.h"

char bandeiras[5][20] = {"Visa", "Mastercard", "American Express", "Elo", "Outras bandeiras"};

void lista_bandeira(){
	int cont;
	for(cont = 0; cont<5; cont++){
		printf("%d - %s\t",cont+1 ,bandeiras[cont]);
	}
}

int main()
{   
    int op, hash, i, pos;
    Tlista L;
	Telemento dado;
	
    criar(&L);

	do{
		system("cls");
		puts("\n\t\t\t\tEDITOR DE LISTAS\n");
        puts("\t1  - EXIBIR LISTA\n \t2  - INSERIR UM ELEMENTO\n \t3  - ENCONTRAR UM ELEMENTO\n \t4  - TAXA DE OCUPACAO\n \t0  - SAIR");
        printf("\nINFORME SUA OPCAO:\n");
        scanf("%d", &op);
        
          
        switch(op)
        {
    		case 1:
            {
				exibir(L);
    		}break;	
    		case 2:
            {
            	printf("Informe o nome completo: ");
			    scanf("%s", &dado.dado.nome);
			    printf("Informe o numero do cartao: ");
			    scanf("%d", &dado.dado.cartao);
			    printf("Informe a bandeira: ");
			    lista_bandeira();
			    scanf("%d", &dado.dado.bandeira);
			    printf("Informe o codigo de verificacao: ");
			    scanf("%d", &dado.dado.cod_verificador);
				printf("Informe o codigo de barras do boleto: ");
			    scanf("%d", &dado.boleto.cod_barras);
				printf("Informe o valor do boleto: ");
			    scanf("%f", &dado.boleto.valor);

				hash = double_hashing(&L, dado);
				printf("HASH = %d\n", hash);
			   	
			    
            }break; 
            case 3:
            { 
				printf("Informe o numero do cartao: ");
			    scanf("%d", &dado.dado.cartao);
			    hash = hashing(dado.dado.cartao);
				if(elemento(L, hash, &dado)==1){
					printf("----------Dados----------\n");
					printf("Nome: %s\n", dado.dado.nome);
					printf("Cartao: %d\n", dado.dado.cartao);
					printf("Bandeira: %d\n", bandeiras[dado.dado.bandeira-1]);
					printf("Codigo de verificacao: %d\n", dado.dado.cod_verificador);			
					printf("----------Boleto----------\n");
					printf("Codigo do boleto: %d\n", dado.boleto.cod_barras);
					printf("Valor: %f\n", dado.boleto.valor);
				}
            }break;
            case 4:{
            	printf("Taxa de Ocupacao: %f", taxaOcupacao(L));
			}break;
            case 0:
            {
    		    printf("ENCERRANDO PROGRAMA");
    		    return 0;
    		}break;
    		default:
    			puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");break;
		}
	getch();
	}while(op != 0);
	
	system("PAUSE");	
	return 0;
}

