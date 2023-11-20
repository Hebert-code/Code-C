/*Vamos definir um TAD matriz com seu grupo de operações.

A estrutura a seguir permite o armazenamento de uma matriz e as operações criar, inicializar,
imprimir, somar, subtrair e multiplicar matrizes que encontram-se definidas.*/

//A Diferença e que o temos apenas um ponteiro para elementos

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int nlinhas;
    int ncolunas;
    int *elementos;
} MATRIZ;

void criar(MATRIZ *, int, int);
void inicializar(MATRIZ *);
void imprimir(MATRIZ *);
void somar(MATRIZ *, MATRIZ *, MATRIZ *);
void subtrair(MATRIZ *, MATRIZ *, MATRIZ *);
void multiplicar(MATRIZ *, MATRIZ *, MATRIZ *);

int main()
{
    MATRIZ A, B, C;

    int nlA, ncA, nlB, ncB;

    printf("Digite o numero de linhas da matriz A: ");
    scanf("%d", &nlA);
    printf("Digite o numero de colunas da matriz A: ");
    scanf("%d", &ncA);

    printf("Digite o numero de linhas da matriz B: ");
    scanf("%d", &nlB);
    printf("Digite o numero de colunas da matriz B: ");
    scanf("%d", &ncB);

    criar(&A, nlA, ncA);
    criar(&B, nlB, ncB);
    criar(&C, nlA, ncB);

    printf("\nMatriz A:\n");
    inicializar(&A);

    printf("\nMatriz B:\n");
    inicializar(&B);

    printf("\nMatriz A:\n");
    imprimir(&A);

    printf("\nMatriz B:\n");
    imprimir(&B);

    printf("\nResultado da soma (Matriz C):\n");
    somar(&A, &B, &C);
    imprimir(&C);

    printf("\nResultado da subtracao (Matriz C):\n");
    subtrair(&A, &B, &C);
    imprimir(&C);

    printf("\nResultado da multiplicacao (Matriz C):\n");
    multiplicar(&A, &B, &C);
    imprimir(&C);

    free(A.elementos);
    free(B.elementos);
    free(C.elementos);

    return 0;
}

//Cria a Matriz
void criar(MATRIZ *M, int nl, int nc)
{
    M->elementos = (int *)calloc(sizeof(int), nl * nc); 

    if (!M->elementos)
    {
        printf("Nao foi possivel reservar memoria para a matriz!\n");
        exit(1);
    }

    M->nlinhas = nl;
    M->ncolunas = nc;
}

//Inicializa a Matriz
void inicializar(MATRIZ *M)
{
    int i;
    for (i = 0; i < M->nlinhas * M->ncolunas; i++)
    {
        printf("\n Digite o elemento[%d][%d]: ", (i / (M->ncolunas)) + 1, i % M->ncolunas + 1);
        scanf("%d", M->elementos + i);
    }
}

//Imprimi a Matriz
void imprimir(MATRIZ *M)
{
    int i, j;
    for (i = 0; i < M->nlinhas; i++)
    {
        printf("\n| ");
        for (j = 0; j < M->ncolunas; j++)
        {
            printf("%03d ", M->elementos[i * M->ncolunas + j]);
        }
        printf(" |");
    }
}

//Faz a Soma entra duas Matrizes
void somar(MATRIZ *M1, MATRIZ *M2, MATRIZ *M3)
{
    if (M1->nlinhas == M2->nlinhas && M1->ncolunas == M2->ncolunas)
    {
        int i;
        criar(M3, M1->nlinhas, M1->ncolunas);

        for (i = 0; i < M3->nlinhas * M3->ncolunas; i++)
        {
            M3->elementos[i] = M1->elementos[i] + M2->elementos[i];
        }
    }
    else
    {
        printf("Nao foi possivel fazer a soma!\n");
    }
}

//Faz a Subtração entra duas Matrizes
void subtrair(MATRIZ *M1, MATRIZ *M2, MATRIZ *M3)
{
    if (M1->nlinhas == M2->nlinhas && M1->ncolunas == M2->ncolunas)
    {
        int i;
        criar(M3, M1->nlinhas, M1->ncolunas);

        for (i = 0; i < M3->nlinhas * M3->ncolunas; i++)
        {
            M3->elementos[i] = M1->elementos[i] - M2->elementos[i];
        }
    }
    else
    {
        printf("Nao foi possivel fazer a subtracao!\n");
    }
}

//Faz a Multiplicação entra duas Matrizes
void multiplicar(MATRIZ *M1, MATRIZ *M2, MATRIZ *M3)
{
    if (M1->ncolunas == M2->nlinhas)
    {
        int i, j, z;
        criar(M3, M1->nlinhas, M2->ncolunas);
        for (i = 0; i < M1->nlinhas; i++)
        {
            for (j = 0; j < M2->ncolunas; j++)
            {
                M3->elementos[i * M3->ncolunas + j] = 0;
                for (z = 0; z < M1->ncolunas; z++)
                {
                    M3->elementos[i * M3->ncolunas + j] += M1->elementos[i * M1->ncolunas + z] * M2->elementos[z * M2->ncolunas + j];
                }
            }
        }
    }
    else
    {
        printf("Nao foi possivel fazer a multiplicacao!\n");
    }
}
