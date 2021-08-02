#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int soma() {} //Função usada para soma dos operandos

int main() {
    int n1, n2;

    printf("Digite o primeiro numero: ");
    scanf("%i", &n1);
    printf("Digite o segundo numero: ");
    scanf("%i", &n2);

    int soma(int a, int b) {
        return a + b;
    }

printf("\nSoma: %i\n", soma(n1, n2));
}
