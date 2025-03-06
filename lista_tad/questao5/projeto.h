
typedef struct _tarefa Tarefa;
typedef struct _membro Mb;
typedef struct projeto pjt;

void atribuir(pjt* projeto, const char* nome, const char* dataInicio, const char* dataConclusao);
void imprimir( pjt* projeto);
void adicionarTarefa(pjt* projeto, const char* descricao, const char* status);
void adicionarMembroEquipe(pjt* projeto, const char* nome);
void removerTarefa(pjt* projeto, const char* descricao);
void concluirTarefa(pjt* projeto, const char* descricao);
void liberarMemoria(pjt* projeto);
void listarProjetosPorMembro(pjt** projetos, int numProjetos, const char* membro);

