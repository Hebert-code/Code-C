//Lista encadeada ultilizando um vetor alocado estaticamente.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct
{
    int inf;
    int next; 
} NODO;

typedef struct
{
    int primeiro;
    int nodo_livre;
    NODO LISTA[MAX];
} LISTA_ENC;

void criar(LISTA_ENC *);
int vazia(LISTA_ENC *);
int tamanho(LISTA_ENC *);
void insercao(LISTA_ENC *, int, int);
int recupera(LISTA_ENC *, int);
void retirada(LISTA_ENC *, int);

int main()
{
    int opcao;
    LISTA_ENC list;
    criar(&list);

    do
    {
        printf("Opcoes:\n");
        printf("1 - Verificar se a lista esta vazia\n");
        printf("2 - Obter o tamanho da lista\n");
        printf("3 - Inserir elemento na lista\n");
        printf("4 - Recuperar elemento da lista\n");
        printf("5 - Retirar elemento da lista\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (vazia(&list))
            {
                printf("A Lista esta vazia.\n");
            }
            else
            {
                printf("A Lista nao esta vazia.\n");
            }
            break;

        case 2:
            printf("Tamanho da lista: %d.\n", tamanho(&list));
            break;

        case 3:
        {
            int posicao, valor;
            printf("Digite o valor que deseja inserir: ");
            scanf("%d", &valor);
            printf("Digite a posicao que deseja inserir: ");
            scanf("%d", &posicao);
            insercao(&list, valor, posicao);
            printf("O valor foi inserido na posicao %d.\n", posicao);
        }
        break;
        case 4:
        {
            int posicao, valor;
            printf("Digite a posicao do elemento a ser recuperado: ");
            scanf("%d", &posicao);
            valor = recupera(&list, posicao);
            printf("Valor na posicao %d: %d\n", posicao, valor);
        }
        break;
        case 5:
        {
            int posicao;
            printf("Digite a posicao do elemento a ser retirado: ");
            scanf("%d", &posicao);
            retirada(&list, posicao);
            printf("Elemento na posicao %d retirado.\n", posicao);
        }
        break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção invalida!\n");
            break;
        }

    } while (opcao != 0);
}

//Cria uma lista.
void criar(LISTA_ENC *L)
{
    int i;
    L->primeiro = -1;  
    L->nodo_livre = 0; 

    for (i = 0; i < (MAX - 1); i++)
    {
        L->LISTA[i].next = i + 1; 
    }
    L->LISTA[i].next = -1;
}

//Verifica se a lista está vazia.
int vazia(LISTA_ENC *L)
{
    return (L->primeiro == -1);
}

//Determina o tamanho da lista;
int tamanho(LISTA_ENC *L)
{
    int cont = 0;
    int indice = L->primeiro;

    while (indice != -1)
    {
        cont++;
        indice = L->LISTA[indice].next; 
    }
    return cont;
}

//Faz a inserção de um novo elemento na lista.
void insercao(LISTA_ENC *L, int valor, int posicao)
{

    if (posicao < 1 || posicao > tamanho(L) + 1)
    {
        printf("\nERRO! Estouro na lista.\n");
        exit(1);
    }
    if (L->nodo_livre != -1)
    { 
        int aux;
        if (posicao == 1)
        {
            L->LISTA[L->nodo_livre].inf = valor;
            aux = L->LISTA[L->nodo_livre].next;
            L->LISTA[L->nodo_livre].next = L->primeiro;
            L->primeiro = L->nodo_livre;
            L->nodo_livre = aux;
        }
        else
        {
            int indice;

            for (indice = L->primeiro; --posicao - 1; indice = L->LISTA[indice].next);

            L->LISTA[L->nodo_livre].inf = valor;
            aux = L->LISTA[L->nodo_livre].next;
            L->LISTA[L->nodo_livre].next = L->LISTA[indice].next;
            L->LISTA[indice].next = L->nodo_livre;
            L->nodo_livre = aux;
        }
    }
    else
    {
        printf("\nImpossivel inserir novos elementos.\nMemoria insuficiente.");
        exit(2);
    }
}

//Recupera o valor de um elemento a partir da posição.
int recupera(LISTA_ENC *L, int posicao)
{
    if (posicao < 1 || posicao > tamanho(L))
    {
        printf("\nPosicao invalida!");
        exit(3);
    }
    else
    {
        int indice = L->primeiro;
        while (--posicao)
        {
            indice = L->LISTA[indice].next;
        }
        return (L->LISTA[indice].inf);
    }
}

//Faz a retirada de um elemento da lista.
void retirada(LISTA_ENC *L, int posicao)
{
    if (posicao < 1 || posicao > tamanho(L))
    { 
        printf("\nPosicao invalida!");
        exit(4);
    }
    else
    {
        int aux;
        if (posicao == 1)
        {
            aux = L->primeiro;
            L->primeiro = L->LISTA[L->primeiro].next;
            L->LISTA[aux].next = L->nodo_livre;
            L->nodo_livre = aux;
        }
        else
        {
            int indice;
            for (indice = L->primeiro; --posicao - 1; indice = L->LISTA[indice].next)
                ;
            aux = L->LISTA[indice].next;
            L->LISTA[indice].next = L->LISTA[L->LISTA[indice].next].next;
            L->LISTA[aux].next = L->nodo_livre;
            L->nodo_livre = aux;
        }
    }
}
