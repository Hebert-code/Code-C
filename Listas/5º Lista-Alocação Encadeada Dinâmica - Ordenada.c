// Lista-Alocação Encadeada Dinâmica - Ordenada

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int inf;
    struct nodo *next;
} NODO;

typedef NODO *LISTA;

void criar(LISTA *);
int vazia(LISTA);
int tamanho(LISTA);
void insercao(LISTA *, int);
int recupera(LISTA, int);
void retirada(LISTA *, int);
int retirada_valor(LISTA *, int);
void destruir(LISTA *);
int pertence(LISTA, int);
int ordenada(LISTA);

#include <stdio.h>
#include <stdlib.h>

int main() {
    LISTA lista;
    criar(&lista);
    int opcao, valor, posicao;

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Inserir elemento\n");
        printf("2. Recuperar elemento\n");
        printf("3. Remover elemento por posicao\n");
        printf("4. Remover elemento por valor\n");
        printf("5. Verificar pertencimento\n");
        printf("6. Verificar ordenacao\n");
        printf("7. Mostrar tamanho da lista\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                insercao(&lista, valor);
                break;
            case 2:
                printf("Digite a posicao do elemento a ser recuperado: ");
                scanf("%d", &posicao);
                printf("Elemento na posicao %d: %d\n", posicao, recupera(lista, posicao));
                break;
            case 3:
                printf("Digite a posicao do elemento a ser removido: ");
                scanf("%d", &posicao);
                retirada(&lista, posicao);
                break;
            case 4:
                printf("Digite o valor do elemento a ser removido: ");
                scanf("%d", &valor);
                if (retirada_valor(&lista, valor)) {
                    printf("Valor %d removido com sucesso!\n", valor);
                } else {
                    printf("Valor %d nao encontrado na lista!\n", valor);
                }
                break;
            case 5:
                printf("Digite o valor a ser verificado: ");
                scanf("%d", &valor);
                printf("Valor %d %s na lista\n", valor, pertence(lista, valor) ? "está" : "não está");
                break;
            case 6:
                printf("A lista esta %s\n", ordenada(lista) ? "ordenada" : "desordenada");
                break;
            case 7:
                printf("Tamanho da lista: %d\n", tamanho(lista));
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção invalida!\n");
        }
    } while(opcao != 0);

    destruir(&lista);

    return 0;
}

// Referencia Externa para NULL
void criar(LISTA *L)
{
    *L = NULL;
}

// Retorna se a lista está vazia
int vazia(LISTA L)
{
    return (!L);
}

// Retorna o tamanho da lista
int tamanho(LISTA L)
{
    int cont;

    for (cont = 0; L != NULL; cont++, L = L->next);

    return cont;
}

// Faz a inserção de um novo elemento
void insercao(LISTA *L, int valor)
{
    NODO *novo;
    novo = (NODO *)malloc(sizeof(NODO));

    if (!novo)
    {
        printf("\nERRO!! Memoria insuficiente!\n");
        exit(2);
    }

    novo->inf = valor;

    // Duas situações

    if (*L == NULL || valor < (*L)->inf)
    { // Caso seja a primeira posição
        novo->next = *L;
        *L = novo;
    }
    else
    { // Posição qualquer
        LISTA aux;
        for (aux = *L; aux->next != NULL && valor > (aux->next)->inf; aux = aux->next);

        novo->next = aux->next;
        aux->next = novo;
    }
}

// Recupera um elemento
int recupera(LISTA L, int posicao)
{
    if (posicao < 1 || posicao > tamanho(L))
    {
        printf("\nPosicao invalida!");
        exit(3);
    }

    for (; posicao > 1; posicao--)
    {
        L = L->next;
    }

    return (L->inf);
}

// Retira um elemento
void retirada(LISTA *L, int posicao)
{
    NODO *aux;
    if (posicao < 1 || posicao > tamanho(*L) + 1)
    {
        printf("\nPosicao invalida!");
        exit(4);
    }
    if (posicao == 1)
    {
        aux = *L;
        *L = aux->next;
        free(aux);
    }
    else
    {
        NODO *aux2;
        for (aux = *L; posicao > 2; posicao--, aux = aux->next);

        aux2 = aux->next;
        aux->next = aux2->next;
        free(aux2);
    }
}

//Faz a retirada com base no valor
int retirada_valor(LISTA *L, int valor)
{
    NODO *aux = *L;
    int k = 1, retorno = 0;

    while (aux && aux->inf <= valor)
    {
        if (aux->inf == valor)
        {
            aux = aux->next;
            retirada(L, k);
            retorno = 1;
        }else {
            aux = aux->next;
            k++;
        }
    }
    return retorno;
}

// Libera toda a área de memória
void destruir(LISTA *L)
{
    LISTA aux;
    while (L)
    {
        aux = *L;
        *L = (*L)->next;
        free(aux);
    }
}

// Verifica se o valor pertence a lista
int pertence(LISTA L, int valor)
{
    int t;
    for (t = tamanho(L); t > 0; t--, L = L->next)
    {
        if (L->inf == valor)
        {
            return (1);
        }
    }
    return (0);
}

// Verifica se a lista está ordenada
int ordenada(LISTA L)
{
    int t;
    for (t = tamanho(L); t > 1; t--, L = L->next)
    {
        if (L->inf > (L->next)->inf)
        {
            return (0);
        }
    }
    return (1);
}