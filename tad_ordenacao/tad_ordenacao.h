typedef struct ordenacao Ordem;

struct ordenacao{
    int *num;
    int tam;
};

void inicializar(Ordem *vet, int tam);
int geraNumero();
void preencherVetor(Ordem *vet);
void imprimir(Ordem *vet);
void bubble_sort(Ordem *vet);
void insertion_sort(Ordem *vet);
void selection_sort(Ordem *vet);

