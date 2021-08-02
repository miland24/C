#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int calculaSoma(); //Função para cálculo da soma das posições escolhidas do vetor.

int main()
{
    setlocale(LC_ALL, "");

    int vet[12] = {4, 5, 1, 3, 3, 5, 1, 9, 8, 4, 3, 2}, x, y;

    do {
    printf("Digite a primeira posição do vetor(1 até 12): ");
    fflush(stdin);
    scanf("%i", &x);
    fflush(stdin);
    printf("Digite a segunda posição do vetor(1 até 12): ");
    scanf("%i", &y);
        if (x > 12 || y > 12 || x < 1 || y < 1) {
            printf("\nEntrada inválida, entre com números de 1 até 12!\n\n");
        }
    } while ( x > 12 || y > 12 || x < 1 || y < 1);

    printf("\nSoma das posições [%i] e [%i] do vetor: %i\n", x, y, calculaSoma(x, y, vet));
}

int calculaSoma(int a, int b, int v[]) {
    return v[a - 1] + v[b - 1];
}
