typedef struct livro Livro;

struct livro
{
    char titulo[100];
    char autor[50];
    int ano;
    int id;
    struct livro *prox;
};

Livro *criar();
Livro *insere_livro(Livro *lista,const char *titulo,const char *autor, int ano, int id);
void imprimir(Livro *lista);

