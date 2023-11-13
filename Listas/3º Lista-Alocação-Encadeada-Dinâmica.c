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
void insercao(LISTA *, int, int);
int recupera(LISTA, int);
void retirada(LISTA *, int);
void destruir(LISTA *);
int pertence(LISTA, int);
int ordenada(LISTA);

int main() {
    LISTA minhaLista;
    int opcao, posicao, valor;

    // Criar lista vazia
    criar(&minhaLista);

    do {
        // Menu de opções
        printf("\n------ Menu ------\n");
        printf("1. Inserir elemento\n");
        printf("2. Imprimir lista\n");
        printf("3. Verificar se a lista esta vazia\n");
        printf("4. Obter o tamanho da lista\n");
        printf("5. Recuperar elemento em uma posicao\n");
        printf("6. Verificar se um valor pertence a lista\n");
        printf("7. Verificar se a lista esta ordenada\n");
        printf("8. Remover elemento\n");
        printf("9. Destruir lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Inserir elemento
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Digite a posicao de insercao: ");
                scanf("%d", &posicao);
                insercao(&minhaLista, valor, posicao);
                break;
            case 2:
                // Imprimir lista
                printf("Lista: ");
                for (LISTA aux = minhaLista; aux != NULL; aux = aux->next) {
                    printf("%d ", aux->inf);
                }
                printf("\n");
                break;
            case 3:
                // Verificar se a lista está vazia
                if (vazia(minhaLista)) {
                    printf("A lista esta vazia.\n");
                } else {
                    printf("A lista não está vazia.\n");
                }
                break;
            case 4:
                // Obter o tamanho da lista
                printf("Tamanho da lista: %d\n", tamanho(minhaLista));
                break;
            case 5:
                // Recuperar elemento em uma posição
                printf("Digite a posicao desejada: ");
                scanf("%d", &posicao);
                printf("Elemento na posicao %d: %d\n", posicao, recupera(minhaLista, posicao));
                break;
            case 6:
                // Verificar se um valor pertence à lista
                printf("Digite o valor a ser verificado: ");
                scanf("%d", &valor);
                if (pertence(minhaLista, valor)) {
                    printf("%d pertence a lista.\n", valor);
                } else {
                    printf("%d não pertence a lista.\n", valor);
                }
                break;
            case 7:
                // Verificar se a lista está ordenada
                if (ordenada(minhaLista)) {
                    printf("A lista esta ordenada.\n");
                } else {
                    printf("A lista não esta ordenada.\n");
                }
                break;
            case 8:
                // Remover elemento
                printf("Digite a posicao do elemento a ser removido: ");
                scanf("%d", &posicao);
                retirada(&minhaLista, posicao);
                break;
            case 9:
                // Destruir lista (liberar memória)
                destruir(&minhaLista);
                printf("Lista destruida.\n");
                break;
            case 0:
                // Sair do programa
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

//Referencia Externa para NULL
void criar(LISTA *L)
{
    *L = NULL;
}

//Retorna se a lista está vazia 
int vazia(LISTA L)
{
    return (!L);
}

//Retorna o tamanho da lista
int tamanho(LISTA L)
{
    int cont;

    for (cont = 0; L != NULL; cont++, L = L->next);

    return cont;
}

//Faz a inserção de um novo elemento
void insercao(LISTA *L, int valor, int posicao)
{
    NODO *novo;

    if (posicao < 0 || posicao > tamanho(*L) + 1)
    {
        printf("ERRO! Posicao invalida");
        exit(1);
    }

    novo = (NODO *)malloc(sizeof(NODO));

    if (!novo)
    {
        printf("\nERRO!! Memoria insuficiente!\n");
        exit(2);
    }

    novo->inf = valor;

    // Duas situações

    if (posicao == 1)
    { // Caso seja a primeira posição
        novo->next = *L;
        *L = novo;
    }
    else
    { // Posição qualquer
        LISTA aux;
        for (aux = *L; posicao > 2; aux = aux->next, posicao--);
        novo->next = aux->next;
        aux->next = novo;
    }
}

//Recupera um elemento 
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

//Retira um elemento 
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
        for (aux = *L; posicao > 2; posicao--, aux = aux->next)
            ;

        aux2 = aux->next;
        aux->next = aux2->next;
        free(aux2);
    }
}

//Libera toda a área de memória 
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

//Verifica se o valor pertence a lista
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

//Verifica se a lista está ordenada
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
