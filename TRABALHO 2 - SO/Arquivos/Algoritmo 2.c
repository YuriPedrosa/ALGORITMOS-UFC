#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define MX 4
#define PRONTO 0
#define ESPERA 1
#define EXECUCAO 2

sem_t mutex;
sem_t *S;
int n;
int M = MX;
int *estado;
int *valor;
int *nprocesso;
FILE* arquivo;

void imprimir(){
   int x;
   for(x = 0; x < n; x++){
	printf("Filosofo : %d , ", x+1);
	if(estado[x] == PRONTO){
		printf("Estado: PRONTO\n");
	}else if(estado[x] == ESPERA){
		printf("Estado: EM ESPERA\n");
	}else{
		printf("Estado: EXECUTANDO\n");
	}
   }
   printf(" ----------------------------------------- \n");
}

void testar(int nprocesso)
{
   if( estado[nprocesso] == ESPERA && valor[nprocesso] <= MX)
   {
	if(valor[nprocesso] <= M){
	      estado[nprocesso]=EXECUCAO;
	      M -= valor[nprocesso];
	      sleep(2);
	      imprimir();
	      fprintf(arquivo,"PROCESSO %d SOLICITA %d, SEGURO\n", nprocesso, valor[nprocesso]);
	      sem_post(&S[nprocesso]);
	}

	else if(valor[nprocesso] > M){
       	      fprintf(arquivo,"PROCESSO %d SOLICITA %d, INSEGURO\n", nprocesso, valor[nprocesso]);
   	}
   }

   else if (estado[nprocesso] == ESPERA && valor[nprocesso] > MX){
	estado[nprocesso] == PRONTO;
	fprintf(arquivo,"PROCESSO %d SOLICITA %d, INSEGURO, valor excede o valor maximo\n", nprocesso, valor[nprocesso]);
	sem_post(&S[nprocesso]);
   }
}

void solicita(int nprocesso)
{
   sem_wait(&mutex);
   estado[nprocesso] = ESPERA;

   imprimir();
   testar(nprocesso);
   sem_post(&mutex);
   sem_wait(&S[nprocesso]);
   sleep(2);
}

void libera(int nprocesso)
{
   sem_wait(&mutex);
   estado[nprocesso]=PRONTO;
   if(valor[nprocesso] <= MX){
     M+= valor[nprocesso];
   }
   imprimir();
   testar((nprocesso+n-1)%n);
   testar((nprocesso+1)%n);
   sem_post(&mutex);
}

void *processo(void *num)
{
     int *i = num;
     sleep(3);
     solicita(*i);
     sleep(3);
     libera(*i);

}


int main() {
   int i;
   arquivo = fopen("ag2.txt","w");
   printf("Quantidade de processos: ");
   scanf("%d", &n);

   nprocesso = (int *) malloc (n * sizeof(int));

   for(i=0;i<n;i++)
      nprocesso[i] = i;

   pthread_t* thread_id = (pthread_t *) malloc ( n * sizeof(pthread_t));

   S = (sem_t *) malloc( n * sizeof(sem_t) );
   estado = (int *) malloc (n * sizeof(int));
   valor = (int *) malloc (n * sizeof(int));

   for(i=0;i<n;i++){
     printf("Valor maximo do processo %d: ", i+1);
     scanf("%d", &valor[i]);
   }

   sem_init(&mutex,0,1);

   for(i=0;i<n;i++)
      sem_init(&S[i],0,0);
   for(i=0;i<n;i++)
      pthread_create(&thread_id[i], NULL, processo, &nprocesso[i]);

   for(i=0;i<n;i++)
      pthread_join(thread_id[i],NULL);


   fclose(arquivo);
   return 0;
}
