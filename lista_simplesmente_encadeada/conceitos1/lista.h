typedef struct lista* def_lista;

struct lista
{
    int info;
    struct lista *prox;
};



def_lista cria_no();
def_lista *insere_inicio(def_lista* Lista, int nro);
void insere_final(def_lista* Lista, int nro);
int busca(def_lista Lista, int nro);
void imprime_lista(def_lista Lista);
int qtd_no(def_lista Lista, int num);
