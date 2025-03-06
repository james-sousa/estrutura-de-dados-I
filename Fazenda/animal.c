#include <stdio.h>
#include <stdlib.h>
#include "fazenda.h"
#include "animal.h"

struct animal{
	int id_animal, id_fazenda;
	char sexo; // M ou F
	float peso; //em KG
	int status; // 1 - Nascimento na propria fazenda | 2 - venda | 3 - troca 
	struct animal *prox;
};
//---------------------------------------------------
Animal *criaListaEncadeadaSimplesAnimais() {
	Animal *no = (Animal *)malloc(sizeof(Animal));
	return no;

}
//---------------------------------------------------
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
//---------------------------------------------------
Animal *cadastrarAnimal(Animal *rebanho) {
    Animal *no = criaListaEncadeadaSimplesAnimais();
	Animal *aux = rebanho;

	no = criaListaEncadeadaSimplesAnimais();
    no->id_animal = rand() % 1000;
    printf("ID FAZENDA: "); scanf("%i", &no->id_fazenda);
    limparBuffer();
    printf("SEXO: "); scanf("%c", &no->sexo);
    limparBuffer();
    printf("PESO: "); scanf("%f", &no->peso);
    limparBuffer();
    printf("STATUS: "); scanf("%i", &no->status);
    limparBuffer();

    // ñ tem animais na minha fazenda
    if (aux== NULL) {
        // Indica que é meu ultimo elemento e que ele aponta pra NULL, indicando o fim da lista
        no->prox = NULL;
        // Retorno o meu dado
        return no;
    }   
    no->prox = aux;
    return no;
}
//---------------------------------------------------
// Verifica se existe um animal presente no rebanho
int animalPresente(Animal *rebanho, int id_animal) {
    while (rebanho != NULL) {
        if (rebanho->id_animal == id_animal) return 1;
        
        rebanho = rebanho->prox;
    }
    return 0;
}
//---------------------------------------------------
// Mover um animal de um rebanho pro outro
Animal *moverAnimal(Animal *RebanhoOrigem, Animal *ReabanhoDestino, int id_animal) {
    Animal *origem = RebanhoOrigem, *destino = ReabanhoDestino;
	// o id foi encontrado no primeiro no
    if (origem->id_animal == id_animal) {
		//destino é atualizado pro ultimo no
        while (destino->prox != NULL) destino = destino->prox;
		// adiciona ao final da lista origem
        destino->prox = origem;

		// rebanho de origem avança pro proximo elemento, efeito de remoção
        RebanhoOrigem = RebanhoOrigem->prox;
        origem->prox = NULL;
		// retorna o novo rebanho de origem agora sem elementos
        return RebanhoOrigem;
    }
	// ñ está no primeiro no e estou procurando por ele
    while (origem->prox != NULL && origem->prox->id_animal != id_animal) {
        origem = origem->prox;
    }

    if (origem->prox == NULL) {
        printf("\nAnimal de origem nao encontrado!\n");
        return RebanhoOrigem;
    }
	// atualizo destino novamente para o ultimo no
    while (destino->prox != NULL) destino = destino->prox;
	// apenas adiciono o elemento da origem no destino, e removo o elemento do rebanho de origem
    destino->prox = origem->prox;
    origem->prox = origem->prox->prox;
    destino->prox->prox = NULL;

    return RebanhoOrigem;
}
//---------------------------------------------------
// Atualizar as informações do animal
void atualizarAnimal(Animal *animal, int id_fazenda, int status) {
	// Atualiza o id da fazenda e status
    animal->id_fazenda = id_fazenda;
    animal->status = status + 1;
}
//---------------------------------------------------
Animal *permutasAnimais(Fazenda *RebanhoOrigem, Fazenda *ReabanhoDestino, int id_animal) {
    int status, id_fazenda;
    Animal *destino = ReabanhoDestino->rebanho;

    printf("Qual o tipo de permuta:\n1 - Venda\n2 - Troca\n- ");
    scanf("%d", &status);

    if (listaVaziaAnimal(RebanhoOrigem->rebanho) || listaVaziaAnimal(ReabanhoDestino->rebanho)) {
        printf("\nUm dos reabanhos vazios!\nCadastre pelo menos um animal para permutar!\n");
        return RebanhoOrigem->rebanho;
    }

    if (!animalPresente(RebanhoOrigem->rebanho, id_animal)) {
        printf("\nAnimal nao cadastrado!\n");
        return RebanhoOrigem->rebanho;
    }

    RebanhoOrigem->rebanho = moverAnimal(RebanhoOrigem->rebanho, ReabanhoDestino->rebanho, id_animal);

    while (destino->prox != NULL) destino = destino->prox;
    
    atualizarAnimal(destino, destino->id_fazenda, status);

    return RebanhoOrigem->rebanho;
}
//---------------------------------------------------
Animal *removerAnimal(Fazenda *fazenda, int id_animal) { // lista encadeada simples
	Animal *aux = fazenda->rebanho, *aux2;

	if (listaVaziaAnimal(fazenda->rebanho)) {
		printf("\nLista vazia\n");
		return fazenda->rebanho;
	}

	if (!buscarAnimal(fazenda->rebanho, id_animal)) {
		printf("\nAnimal nao cadastrado!\n");
		return fazenda->rebanho;
	}
	// Se o id estiver no primeiro
	if (aux->id_animal == id_animal) {
		fazenda->rebanho = aux->prox;
		free(aux);
		return fazenda->rebanho;
	}
	// Se ñ estiver no 1º no
	while(aux->prox->id_animal != id_animal) aux = aux->prox;
	
	aux2 = aux->prox;
	aux->prox = aux2->prox;
	free(aux2);

	return fazenda->rebanho;
}
//---------------------------------------------------
int listaVaziaAnimal(Animal *animais) { 
	if (animais == NULL)
	{
		return 1;
	}
	
	return 0; 
}
//---------------------------------------------------
void mostrarAnimais(Animal *animais) {
	Animal *aux = animais;

	if(listaVaziaAnimal(aux)) {
		printf("\nNao ha animais nesta fazenda!\n");
		return;
	}

	printf("\n-ANIMAIS\n");
	while(aux != NULL) {
		printf("\nID ANIMAL: %d\n", aux->id_animal); 
		printf("ID FAZENDA: %d\n", aux->id_fazenda); 
		printf("SEXO: %c\n", aux->sexo); 
		printf("PESO: %.2f\n", aux->peso); 
		printf("STATUS: %d\n", aux->status);

		aux = aux->prox; 
	}
	printf("\n");
}
//---------------------------------------------------
int buscarAnimal(Animal *rebanho, int id) {
	Animal *aux = rebanho;

	if (listaVaziaAnimal(rebanho)){
		return 0;
	}

	while (aux != NULL && aux->id_animal != id) aux = aux->prox;
	
	return aux != NULL;
	
}
//---------------------------------------------------
void liberarMemoriaAnimal(Animal *animais) {
	Animal *aux = animais;
	while(aux != NULL) {
		aux = aux->prox;
		free(animais);
		animais = aux;
	}
	free(animais);
}
//---------------------------------------------------
// não altera o ponteiro original, porque n estou retornando ele no final da função, entao as alterações permanecem somente aq
int countAnimais(Animal *animais, char sexo){
	int count = 0;
	while (animais != NULL) {
		if(animais->sexo == sexo) count++;
		
		animais = animais->prox;
	}
	return count;
}
//---------------------------------------------------
float countArroba(Animal *animais) {
	float soma = 0;
	while (animais != NULL) {
		soma += animais->peso;
		animais = animais->prox;
	}
	// Convere quilogramas para arroba
	return soma / 15;
}
//---------------------------------------------------
void printStatus(Animal *animais) {
	Animal *aux = animais;
	// 1 nascimento na propria fazenda, 2 venda, 3 troca
	for (int i = 1; i <= 3; i++) {
		aux = animais;
		printf("\n------------Status %d--------------\n", i);
		while (aux != NULL){
			if(aux->status == i){
				printf("\nID ANIMAL: %d\n", aux->id_animal); 
				printf("ID FAZENDA: %d\n", aux->id_fazenda); 
				printf("SEXO: %c\n", aux->sexo); 
				printf("PESO: %.2f\n", aux->peso); 
				printf("STATUS: %d\n", aux->status);
			}
			aux = aux->prox;
		}
	}
}