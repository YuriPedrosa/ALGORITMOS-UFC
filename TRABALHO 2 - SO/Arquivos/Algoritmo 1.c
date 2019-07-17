#include <stdio.h>
#include <stdlib.h>

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

int** preencheMatriz(int l, int c, FILE* arquivo){
    int** m;
    m = (int **)  malloc( l * sizeof( int * ));

    int nl;

    for(nl = 0; nl < l; nl++){
        m[nl] = (int *) malloc( c * sizeof(int));
    }

    int i,j;
    for(i=0;i<l;i++){
        for(j=0; j<c; j++){
            fscanf(arquivo,"%d", &m[i][j]);
        }
    }
    return m;
}

int* preencheVetor(int l, FILE* arquivo){
    int* m = (int *) malloc( l * sizeof(int));

    int i;

    for(i=0;i<l;i++){
        fscanf(arquivo,"%d", &m[i]);
    }

    return m;
}

int* soma(int **m, int l, int c){
    int i,j;
    int* v = (int *) malloc( c * sizeof(int));

    for(i = 0; i < c; i++){
        v[i] = 0;
        for(j = 0; j < l; j++){
            v[i] += m[j][i];
        }
    }

    return v;
}

int* subtrai(int *m, int *v, int c){
    int i;
    int* x = (int *) malloc( c * sizeof(int));

    for(i = 0; i < c; i++){
        x[i] = m[i] - v[i];
    }

    return x;
}

int verifica(int *m, int *rD,int c){
    int* x = subtrai(rD,m,c);
    int i,j;

    for(i = 0; i < c; i++){
       if(x[i] < 0) return 0;
    }

    return 1;
}

void imprimir(int **mA, int **mS, int *rT, int *rD, int *rU ,int l,int c){

    printf("\nProcessos: %d Recursos: %d \n", l, c);
    int i,j;

    printf("Recursos de cada tipo: ");
    for(i=0;i<c;i++){
        printf(" %d ", rT[i]);
    }

    printf("\nMatriz de Alocacao: \n");

    for(i=0;i<l;i++){
        for(j=0; j<c; j++){
            printf(" %d ", mA[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz de Solicitacoes: \n");

    for(i=0;i<l;i++){
        for(j=0; j<c; j++){
            printf(" %d ", mS[i][j]);
        }
        printf("\n");
    }

    printf("Recursos utilizados: ");
    for(i=0;i<c;i++){
        printf(" %d ", rU[i]);
    }

    printf("\nRecursos disponiveis: ");
    for(i=0;i<c;i++){
        printf(" %d ", rD[i]);
    }
}

int* zerar(int *x, int c){
    int i = 0;
    for(i = 0; i < c; i++){
        x[i] = 0;
    }
    return x;
}

int main(){

    int l,c;
    FILE *arquivo;

    int **mA;
    int **mS;
    int *rT, *rU, *rD;

    arquivo = AbreArquivo('l',"teste.txt");

    fscanf(arquivo,"%d %d", &l, &c);

    rT = preencheVetor(c,arquivo);
    mA = preencheMatriz(l,c, arquivo);
    mS = preencheMatriz(l,c, arquivo);
    rU = soma(mA,l,c);
    rD = subtrai(rT,rU,c);

    int* estado = (int *) malloc(l * sizeof(int));
    int* ordem = (int *) malloc(l * sizeof(int));

    int i,j, pos = 0;

    imprimir(mA,mS,rT,rD,rU,l,c);

    for(j = 0; j < l; j++){
        for(i = 0; i < l; i++){
            if(estado[i] != 1 && verifica(mS[i], rD, c)){
                mA[i] = zerar(mA[i], c);
                mS[i] = zerar(mS[i], c);
                rU = soma(mA,l,c);
                rD = subtrai(rT,rU,c);
                estado[i] = 1;
                ordem[pos++] = i+1;
            }
        }
    }
    printf("\n");
    if( pos == l ){
        printf("Nao houve impasses, ordem de execucao: ");
        for(i = 0; i < pos; i++){
            printf(" %d", ordem[i]);
        }
    }else {
        printf("\nImpasse nos processos : ");
        for(i = 0; i < l; i++){
            if(estado[i] != 1){
                printf(" %d", i+1);
            }
        }
    }

    FecharArquivo(arquivo);

    return 0;
}
