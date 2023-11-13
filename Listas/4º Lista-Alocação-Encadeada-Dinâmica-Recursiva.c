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
int pertence(LISTA ,int);
int ordenada(LISTA);
void gera_lista(LISTA*,int,int);

int main() {
    LISTA minhaLista;
    int opcao, posicao, valor, m, n;

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
        printf("10. Gerar lista no intervalo\n");
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
                    printf("A lista nao esta vazia.\n");
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
                    printf("%d nao pertence a lista.\n", valor);
                }
                break;
            case 7:
                // Verificar se a lista está ordenada
                if (ordenada(minhaLista)) {
                    printf("A lista esta ordenada.\n");
                } else {
                    printf("A lista nao esta ordenada.\n");
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
            case 10:
                // Gerar lista no intervalo
                printf("Digite o valor inicial do intervalo: ");
                scanf("%d", &m);
                printf("Digite o valor final do intervalo: ");
                scanf("%d", &n);
                gera_lista(&minhaLista, m, n);
                break;
            case 0:
                // Sair do programa
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

//Referencia para NULL
void criar(LISTA *L)
{
    *L = NULL;
}

//Verifica se a lista está vazia
int vazia(LISTA L)
{
    return (!L);
}

//Verifica o tamanho da lista
int tamanho(LISTA L)
{
    if (!L)
        return (0);
    else
        return (1 + tamanho(L->next));
}

//Faz a inserção de um novo elemento na lista
void insercao(LISTA *L, int valor, int posicao)
{
    if (posicao < 1 || posicao > tamanho(*L) + 1)
    {
        printf("\nPosicao invalida!");
        exit(1);
    }

    if (posicao == 1)
    {
        NODO *novo;
        novo = (NODO *)malloc(sizeof(NODO));
        if (!novo)
        {
            printf("\nERRO!! Memoria insuficiente!\n");
            exit(2);
        }
        novo->inf = valor;
        novo->next = *L;
        *L = novo;
    }
    else
    {
        insercao(&((*L)->next), valor, posicao - 1);
    }
}

//Recupera um elemento da lista
int recupera(LISTA L, int posicao)
{
    if (posicao < 1 || posicao > tamanho(L))
    {
        printf("\nERRO! Consulta invalida.\n");
        exit(3);
    }
    if (posicao == 1)
        return (L->inf);
    else
        return (recupera(L->next, posicao - 1));
}

//Retira um elemento da lista
void retirada(LISTA *L, int posicao)
{
    if (posicao < 1 || posicao > tamanho(*L))
    { // verificamos a posição
        printf("\nPosicao invalida!");
        exit(4);
    }
    if (posicao == 1)
    {
        NODO *aux;
        aux = *L;
        *L = aux->next;
        free(aux);
    }
    else
    {
        retirada(&((*L)->next), posicao - 1);
    }
}

//Libera a área de memória 
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
    if (L)
    {
        if (L->inf == valor)
        {
            return (1);
        }
        return (pertence(L->next, valor));
    }
    return (0);
}

//Verifica se a lista está ordenada
int ordenada(LISTA L)
{
    if (!L || (L && !(L->next)))
        return (1);
    if (L->inf > (L->next)->inf)
        return (0);
    return (ordenada(L->next));
}

//Função gera 
void gera_lista(LISTA *L, int m, int n)
{
    if (m > n)
    {
        printf("\nERRO! Intervalo invalido.\n");
        exit(5);
    }
    else if (m == n)
    {
        criar(L);
        insercao(L, m, 1);
    }
    else
    {
        gera_lista(L, m + 1, n);
        insercao(L, m, 1);
    }
}