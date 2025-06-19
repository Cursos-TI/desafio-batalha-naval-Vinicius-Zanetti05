#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // Função auxiliar: verifica se pode posicionar um navio sem sair dos limites ou sobrepor outro
    int podePosicionar = 1;

    // NAVIO 1 — HORIZONTAL (linha 2, coluna 1 a 3)
    int linha1 = 2, coluna1 = 1;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha1][coluna1 + i] != VALOR_AGUA) {
            podePosicionar = 0;
        }
    }
    if (podePosicionar) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha1][coluna1 + i] = VALOR_NAVIO;
        }
    }

    // NAVIO 2 — VERTICAL (linha 5 a 7, coluna 6)
    podePosicionar = 1;
    int linha2 = 5, coluna2 = 6;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha2 + i][coluna2] != VALOR_AGUA) {
            podePosicionar = 0;
        }
    }
    if (podePosicionar) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha2 + i][coluna2] = VALOR_NAVIO;
        }
    }

    // NAVIO 3 — DIAGONAL PRINCIPAL (linha/coluna aumentam: 0,0 até 2,2)
    podePosicionar = 1;
    int linha3 = 0, coluna3 = 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha3 + i][coluna3 + i] != VALOR_AGUA) {
            podePosicionar = 0;
        }
    }
    if (podePosicionar) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha3 + i][coluna3 + i] = VALOR_NAVIO;
        }
    }

    // NAVIO 4 — DIAGONAL SECUNDÁRIA (linha aumenta, coluna diminui: 0,9 até 2,7)
    podePosicionar = 1;
    int linha4 = 0, coluna4 = 9;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha4 + i][coluna4 - i] != VALOR_AGUA) {
            podePosicionar = 0;
        }
    }
    if (podePosicionar) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha4 + i][coluna4 - i] = VALOR_NAVIO;
        }
    }

    // Exibe o tabuleiro final
    printf("TABULEIRO BATALHA NAVAL (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
