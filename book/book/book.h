typedef struct book Book;

typedef struct {
    Book* inicio;
} ListaLivros;

void inserir_livro(ListaLivros* lista, const char* titulo, const char* autor, int ano, int id);
void remover_livro(ListaLivros* lista, int id);
ListaLivros listar_livros_por_autor(ListaLivros* lista, const char* autor);
void atualizar_ano_publicacao(ListaLivros* lista, int id, int novo_ano);
void imprimir_lista(ListaLivros* lista);
