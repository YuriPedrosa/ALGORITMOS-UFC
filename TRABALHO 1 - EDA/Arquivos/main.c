#include "libsequ.h"

int main()
{   
    int op, hash, i, pos;
    Tlista L;
	Telemento dado;
	
    criar(&L);

	do{
		system("cls");
		puts("\n\t\t\t\tEDITOR DE LISTAS\n");
        puts("\t1  - EXIBIR LISTA\n \t2  - INSERIR UM ELEMENTO\n \t3  - ENCONTRAR UM ELEMENTO\n \t0  - SAIR");
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
			    scanf("%d", &dado.dado.bandeira);
			    printf("Informe o codigo de verificacao: ");
			    scanf("%d", &dado.dado.cod_verificador);
				printf("Informe o codigo de barras do boleto: ");
			    scanf("%d", &dado.boleto.cod_barras);
				printf("Informe o valor do boleto: ");
			    scanf("%f", &dado.boleto.valor);
			    
				hash = hashing(dado.dado.cartao);
			    //printf("HASH = %d\n", hash);
			   	
				inserir(&L, hash, dado);
            }break; 
            case 3:
            { 
				printf("Informe o numero do cartao: ");
			    scanf("%d", &dado.dado.cartao);
			    hash = hashing(dado.dado.cartao);
				//printf("HASH = %d\n", hash);
				if(elemento(L, hash, &dado)==1){
					printf("----------Dados----------\n");
					printf("Nome: %s\n", dado.dado.nome);
					printf("Cartao: %d\n", dado.dado.cartao);
					printf("Bandeira: %d\n", dado.dado.bandeira);
					printf("Codigo de verificacao: %d\n", dado.dado.cod_verificador);			
					printf("----------Boleto----------\n");
					printf("Codigo do boleto: %d\n", dado.boleto.cod_barras);
					printf("Valor: %f\n", dado.boleto.valor);
				}
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
