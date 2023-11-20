/*Vamos definir um TAD matriz que representa uma matriz simétrica de caracteres.

A estrutura a seguir permite o armazenamento de uma matriz e as operações criar, inicializar,
imprimir, e consulta de um determinado elemento da matriz.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int ordem;
    char *elementos;
} MATRIZ;

void criar(MATRIZ *, int);
void inicializar(MATRIZ *);
void imprimir(MATRIZ *);
char retorna(MATRIZ *, int, int);
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

    if (linha <= matriz.ordem && coluna <= matriz.ordem)
    {
        char valor = retorna(&matriz, linha - 1, coluna - 1);
        printf("Valor na posicao [%d][%d] e: %c\n", linha, coluna, valor);
    }
    else
    {
        printf("Linha ou coluna fora dos limites da matriz.\n");
    }

    free(matriz.elementos); // Libera a memória alocada

    return 0;
}

void criar(MATRIZ *M, int or)
{

    M->elementos = (char *)malloc(sizeof(char) * (or +1) * or / 2);
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

void inicializar(MATRIZ *M)
{
    int i, j;

    for (i = 0; i < M->ordem; i++)
    {
        for (j = 0; j < M->ordem; j++)
        {
            if (j >= i)
            {
                printf("Digite o elemento[%d][%d]: ", i + 1, j + 1);
                setbuf(stdin, NULL);
                scanf("%c", M->elementos + mapeamento(i, j));
            }
        }
    }
}

void imprimir(MATRIZ *M)
{
    int i, j;

    for (i = 0; i < M->ordem; i++)
    {
        printf("| ");
        for (j = 0; j < M->ordem; j++)
        {
            printf("%c ", retorna(M, i, j));
        }
        printf(" |\n");
    }
}

char retorna(MATRIZ *M, int i, int j)
{
    if (i <= j)
    {
        return M->elementos[mapeamento(i, j)];
    }
    else
    {
        return M->elementos[mapeamento(j, i)];
    }
}

int mapeamento(int i, int j)
{
    return (i * (i + 1) / 2 + j);
}