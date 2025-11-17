#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --------------------------------------------------
// STRUCT DA ÁRVORE
// Representa cada sala da mansão (nó da árvore).
// --------------------------------------------------
typedef struct Sala {
    char nome[50];
    struct Sala *esq; // caminho para a esquerda
    struct Sala *dir; // caminho para a direita
} Sala;

// --------------------------------------------------
// FUNÇÃO criarSala()
// Cria dinamicamente uma sala e inicializa seus filhos.
// --------------------------------------------------
Sala* criarSala(char nome[]) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

// --------------------------------------------------
// FUNÇÃO explorarSalas()
// Permite que o jogador navegue pela árvore a partir do Hall.
// O jogo termina quando se chega a um nó-folha (sem caminhos).
// --------------------------------------------------
void explorarSalas(Sala *atual) {
    char escolha;

    printf("\n Bem-vindo à exploração da mansão Detective Quest!\n");
    printf("Você começará no Hall de entrada.\n");

    while (atual != NULL) {
        // Mostra a sala atual
        printf("\n Você está agora em: %s\n", atual->nome);

        // Se for nó-folha, acabou
        if (atual->esq == NULL && atual->dir == NULL) {
            printf("\n Esta sala não possui mais caminhos.\n");
            printf("Exploração encerrada!\n");
            return;
        }

        // Mostra opções de caminho
        printf("\nEscolha seu caminho:\n");
        if (atual->esq != NULL)
            printf("  (e) Ir para a esquerda → %s\n", atual->esq->nome);
        if (atual->dir != NULL)
            printf("  (d) Ir para a direita → %s\n", atual->dir->nome);
        printf("  (s) Sair da exploração\n");

        printf("Opção: ");
        scanf(" %c", &escolha);

        if (escolha == 'e' && atual->esq != NULL) {
            atual = atual->esq;
        }
        else if (escolha == 'd' && atual->dir != NULL) {
            atual = atual->dir;
        }
        else if (escolha == 's') {
            printf("\n Exploração encerrada pelo jogador.\n");
            return;
        }
        else {
            printf("\n Caminho inválido! Tente novamente.\n");
        }
    }
}

// --------------------------------------------------
// FUNÇÃO PRINCIPAL
// Monta manualmente a árvore da mansão e inicia a exploração.
// --------------------------------------------------
int main() {
    // Criando as salas (nós)
    Sala *hall = criarSala("Hall de Entrada");
    Sala *salaEstar = criarSala("Sala de Estar");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *cozinha = criarSala("Cozinha");
    Sala *jardim = criarSala("Jardim");
    Sala *porao = criarSala("Porão");

    // Montando a árvore (mapa da mansão)
    //
    //                Hall
    //               /    \
    //        Estar        Biblioteca
    //        /   \         /      \
    //    Cozinha Jardim  NULL    Porão

    hall->esq = salaEstar;
    hall->dir = biblioteca;

    salaEstar->esq = cozinha;
    salaEstar->dir = jardim;

    biblioteca->dir = porao;

    // Inicia a exploração a partir do Hall
    explorarSalas(hall);

    return 0;
}
