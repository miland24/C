#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int calcularFatorial(); //Fun��o para c�lculo da fatorial

int main()
{
    setlocale(LC_ALL, "");
    int numero = 0;

    printf("Entre com um n�mero para calcular o fatorial: ");
    scanf("%i", &numero);

    printf("O fatorial deste n�mero �: %i", calcularFatorial(numero));

}

int calcularFatorial(int a) {

    for (int i = a - 1; i >= 1; i--) {
            a = a * i;
    }

return a;
}
