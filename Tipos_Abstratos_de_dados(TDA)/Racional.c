/*Definiremos um TAD RACIONAL.*/
/*Um número racional pode ser expresso como o quociente de dois inteiros. 
Definiremos: as operações de criação, multiplicação, soma e verificação de equivalencia de números racionais.
Por fim ultilizamos o Algoritmo de Euclides para fazer a redução do números racionais.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int numerador;
    int denominador;
}RACIONAL;

void criar(RACIONAL *,int ,int);
void multiplicar(RACIONAL *,RACIONAL *,RACIONAL *);
void somar(RACIONAL *,RACIONAL *,RACIONAL *);
int equivalencia(RACIONAL *,RACIONAL *);
void reduzir(RACIONAL *,RACIONAL *);

int main() {
    RACIONAL num1, num2, resultado, reduzido;
    
    int numerador1, denominador1, numerador2, denominador2;
    
    printf("Digite o numerador e denominador do primeiro numero racional: ");
    scanf("%d %d", &numerador1, &denominador1);
    
    printf("Digite o numerador e denominador do segundo numero racional: ");
    scanf("%d %d", &numerador2, &denominador2);
    
    criar(&num1, numerador1, denominador1);
    criar(&num2, numerador2, denominador2);
    
    printf("Numero Racional 1: %d/%d\n", num1.numerador, num1.denominador);
    printf("Numero Racional 2: %d/%d\n", num2.numerador, num2.denominador);
    
    multiplicar(&num1, &num2, &resultado);
    printf("Multiplicacao: %d/%d\n", resultado.numerador, resultado.denominador);
    
    somar(&num1, &num2, &resultado);
    printf("Soma: %d/%d\n", resultado.numerador, resultado.denominador);
    
    if (equivalencia(&num1, &num2)) {
        printf("Os numeros racionais sao equivalentes.\n");
    } else {
        printf("Os numeros racionais nao sao equivalentes.\n");
    }
    
    reduzir(&num1, &reduzido);
    printf("Numero Racional 1 reduzido: %d/%d\n", reduzido.numerador, reduzido.denominador);
    
    reduzir(&num2, &reduzido);
    printf("Numero Racional 2 reduzido: %d/%d\n", reduzido.numerador, reduzido.denominador);
    
    return 0;
}

void criar(RACIONAL *R,int n,int d){
    R->numerador = n;
    R->denominador = d;
}

void multiplicar(RACIONAL *A,RACIONAL *B,RACIONAL *C){
    C->numerador = A->numerador * B->numerador;
    C->denominador = A->denominador * B->denominador;
}

void somar(RACIONAL *A,RACIONAL *B, RACIONAL*C){
    C->numerador = (A->numerador * B->denominador) + (B->numerador * A->denominador);
    C->denominador = A->denominador * B->denominador;
}

//Olhar o que eh essa equivalencia
int equivalencia(RACIONAL *A,RACIONAL *B){
    return(A->numerador * B->denominador == A->denominador * B->numerador);
}

void reduzir(RACIONAL *RAC_IN,RACIONAL *RAC_OUT){
    int a,b,res;

    if(RAC_IN->numerador > RAC_IN->denominador){
        a = RAC_IN->numerador;
        b = RAC_IN->denominador;
    }else{
        a = RAC_IN ->denominador;
        b = RAC_IN ->numerador;
    }

    while(b){
        res = a%b;
        a = b;
        b = res;
    }
    RAC_OUT->numerador = RAC_IN->numerador/a;
    RAC_OUT->denominador = RAC_IN->denominador/a;
}