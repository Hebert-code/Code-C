/*Vamos definir um TAD matriz que representa uma matriz esparsa.

A estrutura a seguir permite o armazenamento de uma matriz e as operações criar, atribuir e consulta 
de um determinado elemento da matriz.*/
#include <stdio.h>
#include <stdlib.h>

#define max 100

typedef struct {
    int N_Ele;
    int L1;
    int L2;
    float VAL[max];
    int IND[2][max];
} MAT;

void criar(MAT *, int, int);
void atribuir(MAT *, int, int, float);
float consultar(MAT *, int, int);
void inserir(MAT *, int, int, float);
void retirar(MAT *, int);

int main() {
    MAT matriz;
    int linhas, colunas;

    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);

    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);

    criar(&matriz, linhas, colunas);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            float valor;
            printf("Digite o valor para a posicao (%d, %d): ", i, j);
            scanf("%f", &valor);
            atribuir(&matriz, i, j, valor);
        }
    }

    printf("Matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%.2f\t", consultar(&matriz, i, j));
        }
        printf("\n");
    }

    return 0;
}

void criar(MAT *m, int n_l, int n_c) {
    m->N_Ele = 0;
    m->L1 = n_l;
    m->L2 = n_c;
}

void atribuir(MAT *m, int i, int j, float v) {
    if (0 <= i && i < m->L1 && 0 <= j && j < m->L2) {
        int indice = -1, cont;
        for (cont = 0; cont < m->N_Ele; cont++) {
            if (m->IND[0][cont] == i && m->IND[1][cont] == j) {
                indice = cont;
                break;
            }
        }

        if (indice != -1) {
            if (v) {
                m->VAL[indice] = v;
            } else {
                retirar(m, indice);
            }
        } else {
            if (v) {
                inserir(m, i, j, v);
            }
        }
    } else {
        printf("\nErro (Indices Invalidos!)\n");
        exit(1);
    }
}

void inserir(MAT *m, int i, int j, float v) {
    if (m->N_Ele < max) {
        m->VAL[m->N_Ele] = v;
        m->IND[0][m->N_Ele] = i;
        m->IND[1][m->N_Ele] = j;
        m->N_Ele++;
    } else {
        printf("\nErro (Estouro na Matriz!)\n");
        exit(2);
    }
}

void retirar(MAT *m, int indice) {
    if (--m->N_Ele) {
        m->VAL[indice] = m->VAL[m->N_Ele];
        m->IND[0][indice] = m->IND[0][m->N_Ele];
        m->IND[1][indice] = m->IND[1][m->N_Ele];
    }
}

float consultar(MAT *m, int i, int j) {
    if (0 <= i && i < m->L1 && 0 <= j && j < m->L2) {
        float aux = 0;
        int cont;
        for (cont = 0; cont < m->N_Ele; cont++) {
            if (m->IND[0][cont] == i && m->IND[1][cont] == j) {
                aux = m->VAL[cont];
                break;
            }
        }
        return (aux);
    } else {
        printf("\nErro (Indices Invalidos!)\n");
        exit(1);
    }
}
