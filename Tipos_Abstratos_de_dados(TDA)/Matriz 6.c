/*Vamos definir um TAD matriz que representa uma matriz antí-simétrica de floats.

A estrutura a seguir permite o armazenamento de uma matriz e as operações criar, inicializar,
imprimir, e consulta de um determinado elemento da matriz.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int ordem;
    float *elementos;
} MATRIZ;

void criar(MATRIZ *, int);
void inicializar(MATRIZ *);
void imprimir(MATRIZ *);
float retorna(MATRIZ *, int, int);
int mapeamento(int, int);

int main()
{
    MATRIZ matriz;
    int ordem;

    printf("Digite a ordem da matriz: ");
    scanf("%d", &ordem);

    criar(&matriz, ordem);
    inicializar(&matriz);

    printf("Matriz criada:\n");
    imprimir(&matriz);

    int linha, coluna;
    printf("Digite a linha e a coluna para consulta (comecando em 1): ");
    scanf("%d %d", &linha, &coluna);

    if (linha <= matriz.ordem && coluna <= matriz.ordem) {
        float valor = retorna(&matriz, linha - 1, coluna - 1);
        printf("Valor na posicao [%d][%d] e: %.2f\n", linha, coluna, valor);
    } else {
        printf("Linha ou coluna fora dos limites da matriz.\n");
    }

    free(matriz.elementos); // Libera a memória alocada

    return 0;

}

//Faz a Criação da Matriz
void criar(MATRIZ *M, int or)
{

    M->elementos = (float *)malloc(sizeof(float) * (or +1) * or / 2);

    if (!M->elementos)
    {
        printf("Nao foi possivel reservar memoria para a matriz!\n");
        exit(1);
    }
    else
    {
        M->ordem = or ;
    }
}

//Faz a Inicialização da Matriz
void inicializar(MATRIZ *M)
{
    int i, j;
    for (i = 0; i < M->ordem; i++) {
        for (j = i + 1; j < M->ordem; j++) {
            printf("Digite o elemento[%d][%d]: ", i + 1, j + 1);
            scanf("%f", M->elementos + mapeamento(i, j));
        }
    }
}

//Faz a Impressão da Matriz
void imprimir(MATRIZ *M)
{
    int i, j;
    for (i = 0; i < M->ordem; i++)
    {
        printf("| ");
        for (j = 0; j < M->ordem; j++)
        {
            printf("%.2f ", retorna(M, i, j));
        }
        printf("|\n");
    }
}

//Restorna o elemento para Impressão
float retorna(MATRIZ *M, int i, int j)
{
    if (i == j) {
        return 0.0; // Diagonal principal é sempre zero em uma matriz anti-simétrica
    } else if (i < j) {
        return M->elementos[mapeamento(i, j)]; // Abaixo da diagonal principal
    } else {
        return -M->elementos[mapeamento(j, i)]; // Acima da diagonal principal
    }
}

//Faz o Mapeamento para pegar somente a
int mapeamento(int i, int j)
{
    return i * (i - 1) / 2 + j - 1;
}
