#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct
{
    int numero;
    int valor[max];
} LISTA;

void criar(LISTA *);
int vazia(LISTA *);
int tamanho(LISTA *);
void insercao(LISTA *, int, int);
int recupera(LISTA *, int);
void retirada(LISTA *, int);
int pertence(LISTA *, int);
int ordenada(LISTA *);
void gerar_lista(LISTA *, int, int);

int main()
{
    LISTA lista;
    int opcao;
    do
    {
        printf("Opcoes:\n");
        printf("1 - Verificar se a lista esta vazia\n");
        printf("2 - Obter o tamanho da lista\n");
        printf("3 - Inserir elemento na lista\n");
        printf("4 - Recuperar elemento da lista\n");
        printf("5 - Retirar elemento da lista\n");
        printf("6 - Verificar se um elemento pertence a lista\n");
        printf("7 - Verificar se a lista esta ordenada\n");
        printf("8 - Gerar lista com intervalo de numeros\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (vazia(&lista))
            {
                printf("A lista esta vazia.\n");
            }
            else
            {
                printf("A lista nao esta vazia.\n");
            }
            break;

        case 2:
            printf("Tamanho da lista: %d\n", tamanho(&lista));
            break;
        case 3:
        {
            int valor, posicao;
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            printf("Digite a posicao de insercao: ");
            scanf("%d", &posicao);
            insercao(&lista, valor, posicao);
            printf("Valor inserido na posicao %d.\n", posicao);
        }
        break;
        case 4:
        {
            int posicao, valor;
            printf("Digite a posicao do elemento a ser recuperado: ");
            scanf("%d", &posicao);
            valor = recupera(&lista, posicao);
            printf("Valor na posicao %d: %d\n", posicao, valor);
        }
        break;
        case 5:
        {
            int posicao;
            printf("Digite a posicao do elemento a ser retirado: ");
            scanf("%d", &posicao);
            retirada(&lista, posicao);
            printf("Elemento na posicao %d retirado.\n", posicao);
        }
        break;
        case 6:
        {
            int elemento;
            printf("Digite o elemento a ser verificado: ");
            scanf("%d", &elemento);
            if (pertence(&lista, elemento))
            {
                printf("O elemento %d pertence a lista.\n", elemento);
            }
            else
            {
                printf("O elemento %d nao pertence a lista.\n", elemento);
            }
        }
        break;
        case 7:
            if (ordenada(&lista))
            {
                printf("A lista esta ordenada.\n");
            }
            else
            {
                printf("A lista nao esta ordenada.\n");
            }
            break;
        case 8:
        {
            int inicio, fim;
            printf("Digite o inicio do intervalo: ");
            scanf("%d", &inicio);
            printf("Digite o fim do intervalo: ");
            scanf("%d", &fim);
            gerar_lista(&lista, inicio, fim);
            printf("Lista gerada com sucesso.\n");
        }
        break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}

//Cria a lista
void criar(LISTA *L)
{
    L->numero = 0;
}

//Verifica se a lista está vazia 
int vazia(LISTA *L)
{
    return (L->numero == 0);
}

//Determina o tamanho
int tamanho(LISTA *L)
{
    return (L->numero);
}

//Faz a inserção de um elemento na lista
void insercao(LISTA *L, int valor, int posicao)
{
    int aux;
    if (L->numero == max)
    {
        printf("\nERRO! Estouro na lista.\n");
        exit(1);
    }
    if (posicao < 1 || posicao > L->numero + 1)
    {
        printf("\nERRO! Posição invalida para insercao.\n");
        exit(2);
    }

    for (aux = L->numero; aux >= posicao; aux--)
    {
        L->valor[aux] = L->valor[aux - 1];
    }
    L->valor[posicao - 1] = valor;
    L->numero++;
}

//Recupera o valor de um elemento a parti da posição
int recupera(LISTA *L, int posicao)
{
    if (posicao < 1 || posicao > L->numero + 1)
    {
        printf("\nERRO! Consulta invalida.\n");
        exit(3);
    }
    else
    {
        return (L->valor[posicao - 1]);
    }
}

//Faz a retirade de um elemento da lista
void retirada(LISTA *L, int posicao)
{
    int aux;
    if (posicao < 1 || posicao > L->numero + 1)
    {
        printf("\nERRO! Posicao invalida para retirada.\n");
        exit(4);
    }
    L->numero--;
    for (aux = posicao - 1; aux < L->numero; aux++)
    {
        L->valor[aux] = L->valor[aux + 1];
    }
}

//Verifica se o valor pertece a lista
int pertence(LISTA *L, int valor)
{
    int i;
    for (i = 0; i < L->numero; i++)
    {
        if (L->valor[i] == valor)
        {
            return (1);
        }
    }
    return (0);
}

//Verifica se a lista está ordenada crescente
int ordenada(LISTA *L)
{
    int i;
    for (i = 0; i < L->numero; i++)
    {
        if (L->valor[i] > L->valor[i + 1])
        {
            return (0);
        }
    }
    return (1);
}

//Produz uma lista de inteiros determinada por m e n
void gerar_lista(LISTA *L, int m, int n)
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
        gerar_lista(L, m + 1, n);
        insercao(L, m, 1);
    }
}