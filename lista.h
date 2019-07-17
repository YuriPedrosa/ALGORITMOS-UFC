typedef struct lista Lista;
typedef struct cartas Cartas;
typedef struct pessoa Pessoa;

Lista* l_cria();
Lista* l_insere(Lista* l, Pessoa* p, Cartas* c);
void l_imprime(Lista* l);
void l_libera(Lista* l);
