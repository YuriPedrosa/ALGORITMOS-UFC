#include <stdio.h>
#include <stdlib.h>
#define MAX 100

FILE* AbreArquivo(char modo, char caminho[30]){
    FILE *arquivo;
    switch(modo){
        case 'g':
            arquivo = fopen(caminho,"w");
            break;
        case 'l':
            arquivo = fopen(caminho,"r");
            break;
        case 'a':
            arquivo = fopen(caminho,"a");
            break;
    }
    if(arquivo==NULL){
        printf("Nao foi possivel abrir o arquivo");
        exit(0);
    }
    return arquivo;
}

void FecharArquivo(FILE *arquivo){
    fclose(arquivo);
}

int verifica(int *p, int x ,int tam){
    int i;
    for(i = 0; i < tam; i++){
        if(p[i] == x ){
            return 1;
        }
    }
    return 0;
}
int v[MAX];

int busca(int m[][2], int tam,int x){
    int i;
    for(i = 0; i < tam; i++){
        if(m[i][0] == x && v[i] == -1){
            return i;
        }
    }
    return -1;
}

void adicionaCiclo(int ciclo[][2], int tam, int v, int w){
    ciclo[tam][0] = v;
    ciclo[tam][1] = w;
}

void zeraCiclo(int ciclo[][2], int tam){
    int i,j;
    for(i = 0; i < tam; i++){
        for(j = 0; j < 2; j++){
            ciclo[i][j] = -1;
        }
    }
}

int existe(int ciclo[][2], int tam, int x, int v){
    int i;
    for(i = 0; i < tam; i++){
        if(ciclo[i][0] == x && ciclo[i][1] == v) return 1;
    }
    return 0;
}

int preencheMatriz(int tam, int m[][2], FILE* arquivo){

    int i,j;
    fscanf(arquivo,"%d", &j);
    for(i = 0; i < j; i++){
        fscanf(arquivo,"%d %d",&m[tam][0], &m[tam][1]);
        tam++;
    }

    fscanf(arquivo,"%d", &j);
    for(i = 0; i < j; i++){
        fscanf(arquivo,"%d %d",&m[tam][0], &m[tam][1]);
        tam++;
    }

    return tam;
}

int main(){

    int m[MAX][2], a,b,c ;//= {{0,1},{1,2},{2,3},{3,1}};
    //int m[MAX][2] = { {1,9},{2,10},{3,9},{4,9},{4,10},{5,12},{6,9},{7,11},{8,1},{10,5},{11,4},{12,7},{13,6}} ;
    FILE* arquivo = AbreArquivo('l', "alg3.txt");
    fscanf(arquivo,"%d %d",&a,&b);
    int tam = 0;
    tam = preencheMatriz(tam,m,arquivo);
    int cicloAux[MAX][2], contcA = 0;
    int ciclos[MAX][2], contC = 0;

    int i,j;

    for(i = 0; i < tam+1; i++){
        v[i] = -1;
    }

    int cont = 0;
    for( i = 0; i < tam; i++){
        v[i] = 1;
        adicionaCiclo(cicloAux,contcA,m[i][0],m[i][1]);
        contcA++;
        int end = busca(m,tam,m[i][1]);
        while(cont < tam){
            if(end != -1){
                if(existe(cicloAux, contcA, m[end][0],m[end][1])){
                    zeraCiclo(cicloAux, contcA);
                    contcA = 0;
                    break;
                }
                adicionaCiclo(cicloAux,contcA,m[end][0],m[end][1]);
                contcA++;
                if(m[end][1] == m[i][0]){
                    for(j = 0; j < contcA; j++){
                        adicionaCiclo(ciclos,contC,cicloAux[j][0],cicloAux[j][1]);
                        contC++;
                    }
                    zeraCiclo(cicloAux, contcA);
                    contcA = 0;
                    break;
                }
                end = busca(m,tam,m[end][1]);
            }else{
                zeraCiclo(cicloAux, contcA);
                contcA = 0;
                break;
            }
            cont++;
        }
        cont = 0;
    }

    int *pilha = (int *) malloc( a * sizeof(int));
    int tamP = 0;
    for(i = 0; i < contC; i++){
        if(ciclos[i][0] <= a && !verifica(pilha,ciclos[i][0],tamP)){
            pilha[tamP++] = ciclos[i][0];
        }
        if(ciclos[i][1] <= a && !verifica(pilha,ciclos[i][1],tamP)){
            pilha[tamP++] = ciclos[i][1];
        }
    }

    if(tamP > 0){
        printf("Ciclo :");
            for(i = 0; i < contC; i++){
            printf(" (%d-%d)", ciclos[i][0], ciclos[i][1]);
        }
        printf("\nProcessos em deadlock: ");
        for(i = 0; i < tamP; i++){
            printf("%d ", pilha[i]);
        }
    }else{
        printf("\nNao ocorreu deadlock");
    }


    return 0;
}
