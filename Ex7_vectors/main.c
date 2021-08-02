#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 20 //tamanho do vetor em que os números serão alocados.

void vetorResultante(); //Função para transferências dos valores para o vetor resultante.

int main()
{
    setlocale(LC_ALL, "");
    int primeiro[TAM] = {4, 2, 7, 2, 9, 3, 1, 5, 4, 2, 9, 12, 17, 93, 25, 30, 11, 4, 3, 27};
    int segundo[TAM] = {9, 3, 1, 3, 6, 4, 19, 91, 35, 21, 46, 85, 21, 47, 52, 34, 32, 19, 28, 11};
    int vetRes[TAM];

    vetorResultante(primeiro, segundo, vetRes);

    printf("O vetor resultante é: ");
    for (int i = 0; i < TAM; i++) {
        printf("[%i] ", vetRes[i]);
    }
}

void vetorResultante(int v1[], int v2[], int vetResultado[]) {

    for (int i = 0; i < TAM; i++) {
        if (i % 2 == 0) {
            vetResultado[i] = v1[i];
        }
        else {
            vetResultado[i] = v2[i];
        }
    }
}
