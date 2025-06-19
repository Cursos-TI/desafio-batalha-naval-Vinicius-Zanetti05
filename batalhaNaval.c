#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_NAVIO 3
#define VALOR_AGUA 0

int main() {
    // Tabuleiro 10x10 inicializado com água (valor 0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // Vetores que representam os navios (não são necessários, mas estão aqui por exigência do desafio)
    int navioHorizontal[TAMANHO_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};
    int navioVertical[TAMANHO_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};

    // Coordenadas iniciais fixas (definidas no código)
    int linhaHoriz = 2, colunaHoriz = 4;   // Posição inicial do navio horizontal
    int linhaVert = 5, colunaVert = 1;     // Posição inicial do navio vertical

    // Validação para não ultrapassar os limites do tabuleiro
    if (colunaHoriz + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        linhaVert + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        // Validação para evitar sobreposição
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaHoriz][colunaHoriz + i] != VALOR_AGUA ||
                tabuleiro[linhaVert + i][colunaVert] != VALOR_AGUA) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio horizontal no tabuleiro
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaHoriz][colunaHoriz + i] = navioHorizontal[i];
            }

            // Posiciona o navio vertical no tabuleiro
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaVert + i][colunaVert] = navioVertical[i];
            }
        } else {
            printf("Erro: Sobreposição de navios detectada.\n");
            return 1;
        }

    } else {
        printf("Erro: Navio fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
