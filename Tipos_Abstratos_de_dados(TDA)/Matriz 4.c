/*Vamos definir um TAD matriz que representa uma matriz triangular superior de inteiros.

A estrutura a seguir permite o armazenamento de uma matriz e as operações criar, inicializar,
imprimir, e consulta de um determinado elemento da matriz.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int ordem;
    int *elementos;
} MATRIZ;

void criar(MATRIZ *, int);
void inicializar(MATRIZ *);
void imprimir(MATRIZ *);
int retorna(MATRIZ *, int, int);
int mapeamento(int, int);
int consulta(MATRIZ *,int,int);

int main(){
     int ordem;
    printf("Digite a ordem da matriz: ");
    scanf("%d", &ordem);

    MATRIZ matriz;
    criar(&matriz, ordem);
    inicializar(&matriz);
    imprimir(&matriz);

    int linha, coluna;
    printf("Digite a linha e a coluna para consulta (comecando em 1): ");
    scanf("%d %d", &linha, &coluna);

    if (linha <= matriz.ordem && coluna <= matriz.ordem) {
        int valor = retorna(&matriz, linha - 1, coluna - 1);
        printf("Valor na posicao [%d][%d] e: %d\n", linha, coluna, valor);
    } else {
        printf("Linha ou coluna fora dos limites da matriz.\n");
    }

    free(matriz.elementos); // Não se esqueça de liberar a memória alocada

    return 0;
}

//Cria a Matriz
void criar(MATRIZ *M, int or)
{

    M->elementos = (int *)malloc(sizeof(int) * (or + 1) * or / 2);
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

//Inicializa a Matriz
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
                scanf("%d", M->elementos + mapeamento(i, j));
            }
        }
    }
}

//Imprimi a Matriz
void imprimir(MATRIZ *M)
{
    int i, j;

    for (i = 0; i < M->ordem; i++)
    {
        printf("| ");
        for (j = 0; j < M->ordem; j++)
        {
            printf("%02d ", retorna(M, i, j));
        }
        printf(" |\n");
    }
}

//Retorna o elemento para impressão
int retorna(MATRIZ *M, int i, int j)
{
    if (i <= j)
    {
        return (M->elementos[mapeamento(i, j)]);
    }
    else
    {
        return (0);
    }
}

//Faz o mapeamento para pegar somente a triangular superior
int mapeamento(int i, int j)
{
    return (i + (j + 1) * j / 2);
}

//Faz a consulta de um elemento da matriz
int consultarElemento(MATRIZ *M, int linha, int coluna)
{
    if (linha >= 0 && coluna >= 0 && linha < M->ordem && coluna < M->ordem)
    {
        if (linha <= coluna)
        {
            return M->elementos[mapeamento(linha, coluna)];
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return -1;
    }
}