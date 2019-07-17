typedef struct fila Fila;
typedef struct roupa Roupa;
typedef struct pessoa Pessoa;

Fila* f_cria();
int f_vazia(Fila* f);
void f_insere(Fila* f, char v[], char r[],char t);
Pessoa* f_retira(Fila* f);
void f_imprimeRoupa(Roupa* r);
void f_imprimePessoa(Pessoa* p);
void f_imprime(Fila* f);
void f_libera(Fila* f);
