/*Vamos definir um TAD matriz que representa uma matriz diagonal de inteiros.

A estrutura a seguir permite o armazenamento de uma matriz e as operações criar, inicializar,
imprimir, e consulta de um determinado elemento da matriz.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int ordem;
    int *elementos;
} MATRIZ_DIAGONAL;

void criar(MATRIZ_DIAGONAL *, int);
void inicializar(MATRIZ_DIAGONAL *);
void imprimir(MATRIZ_DIAGONAL *);
int retorna(MATRIZ_DIAGONAL *, int, int);
int consulta(MATRIZ_DIAGONAL *,int ,int);

int main(){
    int ordem;
    printf("Digite a ordem da matriz diagonal: ");
    scanf("%d", &ordem);

    MATRIZ_DIAGONAL matriz;
    criar(&matriz, ordem);
    inicializar(&matriz);
    imprimir(&matriz);

    int linha, coluna;
    printf("Digite as coordenadas (linha e coluna) para consultar um elemento da matriz: ");
    scanf("%d %d", &linha, &coluna);

    int elemento = consulta(&matriz, linha, coluna);

    if (elemento != -1)
        printf("Elemento na posicao (%d, %d): %d\n", linha, coluna, elemento);
    else
        printf("Coordenadas fora da diagonal principal.\n");

    free(matriz.elementos);

}

//Cria a matriz
void criar(MATRIZ_DIAGONAL *M, int or)
{

    M->ordem = or ;

    M->elementos = (int *)malloc(sizeof(int) * or);

    if (!M->elementos)
    {
        printf("Nao foi possivel reservar memoria para a matriz!\n");
        exit(1);
    }
}

//Inicializa a Matriz
void inicializar(MATRIZ_DIAGONAL *M)
{
    int i;

    for (i = 0; i < M->ordem; i++)
    {
        printf("Digite o elemento[%d][%d]: ", i + 1, i + 1);
        scanf("%d", M->elementos + i);
    }
}

//Imprimi a Matriz
void imprimir(MATRIZ_DIAGONAL *M)
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

//Reorna a posição para imprimir
int retorna(MATRIZ_DIAGONAL *M, int i, int j)
{
    if (i == j)
    {
        return (M->elementos[i]);
    }
    else
    {
        return (0);
    }
}

//Faz a consulta de um elemento
int consulta(MATRIZ_DIAGONAL *M,int i,int j){
    
    if(i == 0 || j == 0){
        return -1;
    }
    if (i == j)
    {
        return M->elementos[i - 1];
    }
    else
    {
        return -1; // Valor especial para indicar que a consulta está fora da diagonal principal
    }
}