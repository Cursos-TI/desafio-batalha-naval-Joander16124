#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    // Declaração do tabuleiro 5x5 e inicialização com 0 (água)

    int tabuleiro[5][5] = {0};

    // Posicionamento do navio horizontal (3 posições)
    int linhaH = 1;  // linha fixa
    int colunaH = 0; // começa na coluna 0

    printf("Posicionando navio horizontal:\n");
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;
        printf("  Parte %d do navio em (%d, %d)\n", i + 1, linhaH, colunaH + i);
    }

    // Posicionamento do navio vertical (3 posições)
    int linhaV = 0;  // começa na linha 0
    int colunaV = 3; // coluna fixa

    printf("\nPosicionando navio vertical:\n");
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
        printf("  Parte %d do navio em (%d, %d)\n", i + 1, linhaV + i, colunaV);
    }

    // Exibição do tabuleiro
    printf("\nTabuleiro:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

     int tabuleiro[10][10];
     int tamanhoNavio = 3;
 
     for (int i = 0; i < 10; i++) {
         for (int j = 0; j < 10; j++) {
             tabuleiro[i][j] = 0;
         }
     }
 
     // Posicionando os navios - Verificação de sobreposição e limites dentro da própria main
 
     // Navio 1 - Horizontal (linha 1, coluna 2 até 4)
     int x1 = 1, y1 = 2;
     if (y1 + tamanhoNavio <= 10) { // Verificar se o navio cabe horizontalmente
         int podePosicionar = 1;
         for (int i = y1; i < y1 + tamanhoNavio; i++) {
             if (tabuleiro[x1][i] == 3) {
                 podePosicionar = 0;
                 break;
             }
         }
         if (podePosicionar) {
             for (int i = y1; i < y1 + tamanhoNavio; i++) {
                 tabuleiro[x1][i] = 3;
             }
         }
     }
 
     // Navio 2 - Vertical (coluna 7, linha 5 até 7)
     int x2 = 5, y2 = 7;
     if (x2 + tamanhoNavio <= 10) { // Verificar se o navio cabe verticalmente
         int podePosicionar = 1;
         for (int i = x2; i < x2 + tamanhoNavio; i++) {
             if (tabuleiro[i][y2] == 3) {
                 podePosicionar = 0;
                 break;
             }
         }
         if (podePosicionar) {
             for (int i = x2; i < x2 + tamanhoNavio; i++) {
                 tabuleiro[i][y2] = 3;
             }
         }
     }
 
     // Navio 3 - Diagonal principal (linha 0,1,2 e coluna 0,1,2)
     int x3 = 0, y3 = 0;
     if (x3 + tamanhoNavio <= 10 && y3 + tamanhoNavio <= 10) { // Verificar se o navio cabe na diagonal
         int podePosicionar = 1;
         for (int i = 0; i < tamanhoNavio; i++) {
             if (tabuleiro[x3 + i][y3 + i] == 3) {
                 podePosicionar = 0;
                 break;
             }
         }
         if (podePosicionar) {
             for (int i = 0; i < tamanhoNavio; i++) {
                 tabuleiro[x3 + i][y3 + i] = 3;
             }
         }
     }
 
     // Navio 4 - Diagonal inversa (linha 3,4,5 e coluna 6,5,4)
     int x4 = 3, y4 = 6;
     if (x4 + tamanhoNavio <= 10 && y4 - tamanhoNavio >= -1) { // Verificar se o navio cabe na diagonal inversa
         int podePosicionar = 1;
         for (int i = 0; i < tamanhoNavio; i++) {
             if (tabuleiro[x4 + i][y4 - i] == 3) {
                 podePosicionar = 0;
                 break;
             }
         }
         if (podePosicionar) {
             for (int i = 0; i < tamanhoNavio; i++) {
                 tabuleiro[x4 + i][y4 - i] = 3;
             }
         }
     }
 
     printf("Tabuleiro 10x10 com navios (0 = água, 3 = navio):\n\n");
 
     for (int i = 0; i < 10; i++) {
         for (int j = 0; j < 10; j++) {
             printf("%2d ", tabuleiro[i][j]);
         }
         printf("\n");
     }
    

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Definindo as matrizes de habilidades
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Posição de origem das habilidades (definidas diretamente no código)
    int coneOrigemX = 2, coneOrigemY = 2;
    int cruzOrigemX = 5, cruzOrigemY = 5;
    int octaedroOrigemX = 7, octaedroOrigemY = 7;

    // Aplicando as habilidades ao tabuleiro
    // Cone
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {
                int newX = coneOrigemX - 2 + i;
                int newY = coneOrigemY - 2 + j;
                if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10) {
                    tabuleiro[newX][newY] = 5;
                }
            }
        }
    }

    // Cruz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                int newX = cruzOrigemX - 2 + i;
                int newY = cruzOrigemY - 2 + j;
                if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10) {
                    tabuleiro[newX][newY] = 5;
                }
            }
        }
    }

    // Octaedro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) {
                int newX = octaedroOrigemX - 2 + i;
                int newY = octaedroOrigemY - 2 + j;
                if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10) {
                    tabuleiro[newX][newY] = 5;
                }
            }
        }
    }

    // Exibindo o tabuleiro final
    printf("Tabuleiro 10x10 com navios (3), áreas afetadas (5) e água (0):\n\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
