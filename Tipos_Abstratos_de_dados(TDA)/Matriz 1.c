/*
 * TAD Matriz e Operações
 * Este é um Tipo Abstrato de Dados (TAD) que permite o armazenamento e manipulação de matrizes.
 * O conjunto de operações inclui a criação, inicialização, impressão, soma, subtração e multiplicação
 * de matrizes.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int nlinhas;
    int nColunas;
    int **elementos;
} MATRIZ;

void criar(MATRIZ *, int, int);
void inicializar_matriz(MATRIZ *);
void imprimir(MATRIZ *);
void somar(MATRIZ *, MATRIZ *, MATRIZ *);
void subtrair(MATRIZ *, MATRIZ *, MATRIZ *);
void multiplicar(MATRIZ *, MATRIZ *, MATRIZ *);

int main()
{
    MATRIZ M1, M2, M3;

    int nl1, nc1, nl2, nc2;

    printf("Digite o numero de linhas e colunas da primeira matriz: ");
    scanf("%d %d", &nl1, &nc1);

    printf("Digite o numero de linhas e colunas da segunda matriz: ");
    scanf("%d %d", &nl2, &nc2);

    criar(&M1, nl1, nc1);
    criar(&M2, nl2, nc2);

    printf("Digite os elementos da primeira matriz:\n");
    inicializar_matriz(&M1);

    printf("Digite os elementos da segunda matriz:\n");
    inicializar_matriz(&M2);

    printf("Matriz 1:\n");
    imprimir(&M1);

    printf("\nMatriz 2:\n");
    imprimir(&M2);

    somar(&M1, &M2, &M3);
    printf("\nSoma de Matriz 1 e Matriz 2:\n");
    imprimir(&M3);

    subtrair(&M1, &M2, &M3);
    printf("\nSubtracao de Matriz 1 e Matriz 2:\n");
    imprimir(&M3);

    multiplicar(&M1, &M2, &M3);
    printf("\nMultiplicacao de Matriz 1 e Matriz 2:\n");
    imprimir(&M3);

    // Libera a memória alocada para as matrizes
    free(M1.elementos);
    free(M2.elementos);
    free(M3.elementos);

    return 0;
}

//Cria a Matriz
void criar(MATRIZ *M, int nl, int nc)
{
    int i, j;
    M->elementos = (int **)malloc(sizeof(int *) * nl);

    if (!M->elementos)
    {
        printf("Nao foi possivel reservar memoria para a matriz!\n");
        exit(1);
    }

    for (i = 0; i < nl; i++)
    {
        M->elementos[i] = (int *)malloc(sizeof(int) * nc);
        if (!M->elementos[i])
        {
            printf("Nao foi possivel reservar memoria para a matriz!\n");
            exit(2);
        }
    }

    M->nColunas = nc;
    M->nlinhas = nl;

    for (i = 0; i < nl; i++)
    {
        for (j = 0; j < nc; j++)
        {
            M->elementos[i][j] = 0;
        }
    }
}

//Inicializa a Matriz
void inicializar_matriz(MATRIZ *M)
{
    int i, j;
    for (i = 0; i < M->nlinhas; i++)
    {
        for (j = 0; j < M->nColunas; j++)
        {
            printf("\nEntre com o elemento[%d][%d]", i + 1, j + 1);
            scanf("%d", &(M->elementos[i][j]));
        }
    }
}

//Imprimi a Matriz
void imprimir(MATRIZ *M)
{
    int i, j;
    for (i = 0; i < M->nlinhas; i++)
    {
        printf("\n| ");
        for (j = 0; j < M->nColunas; j++)
        {
            printf("%03d ", M->elementos[i][j]);
        }
        printf(" |");
    }
}

//Faz a Soma entre duas Matrizes
void somar(MATRIZ *M1, MATRIZ *M2, MATRIZ *M3)
{
    if (M1->nlinhas == M2->nlinhas && M1->nColunas == M2->nColunas)
    {
        int i, j;
        criar(M3, M1->nlinhas, M1->nColunas);

        for (i = 0; i < M3->nlinhas; i++)
        {
            for (j = 0; j < M3->nColunas; j++)
            {
                M3->elementos[i][j] = M1->elementos[i][j] + M2->elementos[i][j];
            }
        }
    }
    else
    {
        printf("A soma nao foi possivel!\n");
    }
}

//Faz a Subtração entre duas Matrizes
void subtrair(MATRIZ *M1, MATRIZ *M2, MATRIZ *M3)
{
    if (M1->nlinhas == M2->nlinhas && M1->nColunas == M2->nColunas)
    {
        int i, j;
        criar(M3, M1->nlinhas, M1->nColunas);
        for (i = 0; i < M3->nlinhas; i++)
        {
            for (j = 0; j < M3->nColunas; j++)
            {
                M3->elementos[i][j] = M1->elementos[i][j] - M2->elementos[i][j];
            }
        }
    }
    else
    {
        printf("A subtracao nao foi possivel!\n");
    }
}

//Faz a Multiplicação entre duas Matrizes
void multiplicar(MATRIZ *M1, MATRIZ *M2, MATRIZ *M3)
{
    if (M1->nlinhas == M2->nColunas)
    {
        int i, j, z;
        criar(M3, M1->nlinhas, M2->nColunas);
        for (i = 0; i < M1->nlinhas; i++)
        {
            for (j = 0; j < M2->nColunas; j++)
            {
                for (z = 0; z < M1->nColunas; z++)
                {
                    M3->elementos[i][j] += M1->elementos[i][z] * M2->elementos[z][j];
                }
            }
        }
    }
    else
    {
        printf("A Multiplicacao nao foi posivel!\n");
    }
}