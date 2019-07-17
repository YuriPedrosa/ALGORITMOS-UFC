typedef struct pilha Pilha;
typedef struct cartas Cartas;

void p_imprime(Pilha* p);
int p_pilhaVazia(Pilha* p);
int p_pilhaCheia(Pilha* p);
Pilha* p_cria();
void p_imprimeCarta(Cartas* c);
void p_empilha(Pilha* p, char v[], int id);
Cartas* p_desempilha(Pilha* p);
void p_libera(Pilha* p);
