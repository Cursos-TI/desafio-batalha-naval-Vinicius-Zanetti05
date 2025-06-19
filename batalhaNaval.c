#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para imprimir o tabuleiro com legenda
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("Legenda: 0 = Água | 3 = Navio | 5 = Habilidade\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Aplica uma matriz de habilidade no tabuleiro, centrada na origem
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[7][7], int origemLinha, int origemColuna, int tamanho) {
    int offset = tamanho / 2;

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origemLinha - offset + i;
                int coluna = origemColuna - offset + j;

                // Verifica se está dentro dos limites do tabuleiro
                if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                    if (tabuleiro[linha][coluna] == AGUA) {
                        tabuleiro[linha][coluna] = HABILIDADE;
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa com água
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = AGUA;

    // Posiciona 4 navios (2 normais + 2 diagonais) como feito antes
    // Navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[2][1 + i] = NAVIO;

    // Navio vertical
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[5 + i][6] = NAVIO;

    // Diagonal principal
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[0 + i][0 + i] = NAVIO;

    // Diagonal secundária
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[0 + i][9 - i] = NAVIO;

    // Matriz Cone (7x7) — Cone apontando para baixo
    int cone[7][7] = {0};
    for (int i = 0; i < 7; i++) {
        int meio = 3;
        for (int j = meio - i; j <= meio + i; j++) {
            if (j >= 0 && j < 7) {
                cone[i][j] = 1;
            }
        }
    }

    // Matriz Cruz (7x7)
    int cruz[7][7] = {0};
    for (int i = 0; i < 7; i++) {
        cruz[i][3] = 1; // vertical
        cruz[3][i] = 1; // horizontal
    }

    // Matriz Octaedro (7x7) — Forma de losango
    int octaedro[7][7] = {0};
    for (int i = 0; i < 7; i++) {
        int meio = 3;
        int start = meio - (i <= 3 ? i : 6 - i);
        int end = meio + (i <= 3 ? i : 6 - i);
        for (int j = start; j <= end; j++) {
            octaedro[i][j] = 1;
        }
    }

    // Aplicando habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, cone, 4, 4, 7);       // centro do cone em (4,4)
    aplicarHabilidade(tabuleiro, cruz, 6, 6, 7);       // centro da cruz em (6,6)
    aplicarHabilidade(tabuleiro, octaedro, 3, 7, 7);   // centro do octaedro em (3,7)

    // Exibe o resultado
    imprimirTabuleiro(tabuleiro);

    return 0;
}
