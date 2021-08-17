#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int calcularFatorial(); //Função para cálculo da fatorial

int main()
{
    setlocale(LC_ALL, "");
    int numero = 0;

    printf("Entre com um número para calcular o fatorial: ");
    scanf("%i", &numero);

    printf("O fatorial deste número é: %i", calcularFatorial(numero));

}

int calcularFatorial(int a) {

    for (int i = a - 1; i >= 1; i--) {
            a = a * i;
    }

return a;
}
