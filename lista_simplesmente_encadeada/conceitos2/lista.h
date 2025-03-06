typedef struct no No;

struct no
{
    int reg;
    struct no *prox;
};

No *criar();
No *Insere_inicio(No *lista, int n);
void imprimir(No *lista);
No *insere_final(No *lista,int n);
int qtd_no(No *lista, int n);
