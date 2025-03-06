typedef struct aluno al;
struct aluno{
    char nome[50];
    int matricula;
    float nota1;
    float nota2;
    float nota3;
    struct aluno *prox;
};

al *criar();
al *insere_aluno(al *lista, const char *nome, int mat, float nota1,float nota2,float nota3);
void imprimir(al *lista);
