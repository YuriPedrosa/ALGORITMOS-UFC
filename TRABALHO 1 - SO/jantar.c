#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define N 5
#define PENSAR 0
#define FOME 1
#define COMER 2

//para compilar gcc -o jantar jantar.c -pthread

sem_t mutex;
sem_t S[N];
int estado[N];
int nfilosofo[N]={0,1,2,3,4};


void imprimir(){
   int x;
   for(x = 0; x < N; x++){
	printf("Filosofo : %d , ", x+1);
	if(estado[x] == PENSAR){
		printf("Estado: PENSANDO\n");
	}else if(estado[x] == FOME){
		printf("Estado: COM FOME\n");
	}else{
		printf("Estado: COMENDO\n");
	}
   }
   printf(" ----------------------------------------- \n");
}

void testar(int nfilosofo)
{
   if(estado[nfilosofo]==FOME && estado[(nfilosofo+4)%N]!=COMER && estado[(nfilosofo+1)%N]!=COMER)
   {
      estado[nfilosofo]=COMER;
      sleep(2);
      imprimir();
      sem_post(&S[nfilosofo]);
   }
}

void agarraHashi(int nfilosofo)
{
   sem_wait(&mutex);
   estado[nfilosofo] = FOME;
   imprimir();
   testar(nfilosofo);
   sem_post(&mutex);
   sem_wait(&S[nfilosofo]);
   sleep(2);
}

void largarHashi(int nfilosofo)
{
   sem_wait(&mutex);
   estado[nfilosofo]=PENSAR;
   imprimir();
   testar((nfilosofo+4)%N);
   testar((nfilosofo+1)%N);
   sem_post(&mutex);
}



void *filosofo(void *num)
{
   while(1)
   {
      int *i = num;
      sleep(3);
      agarraHashi(*i);
      sleep(3);
      largarHashi(*i);
   }
}


int main() {
   int i;
   pthread_t thread_id[N];

   sem_init(&mutex,0,1);
   for(i=0;i<N;i++)
      sem_init(&S[i],0,0);
   for(i=0;i<N;i++)
      pthread_create(&thread_id[i], NULL, filosofo, &nfilosofo[i]);

   imprimir();

   for(i=0;i<N;i++)
      pthread_join(thread_id[i],NULL);

   return 0;
}
