#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 7

int fatorial(); //Função para cálculo de fatorial

int main()
{
    setlocale(LC_ALL, "");
    int matriz[TAM][TAM], numerador, denominador, denominador2;

    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            if(j == 0 || i == j)
                matriz[i][j] = 1;
            else if(j == 1 || j == i - 1)
                matriz[i][j] = i;
            else
                numerador = fatorial(i);
                denominador = fatorial(j);
                denominador2 = fatorial(i - j);
                matriz[i][j] = numerador/(denominador*denominador2);
        }
    }

    for(int i = 0; i < TAM; i++)
    {
        printf("\n");
        for(int j = 0; j < TAM; j++)
        {
            printf("%i\t", matriz[i][j]);
        }
    }
}

int fatorial(int x)
{
    int res = 1;

    for(x = x; x > 0; x--)
    {
        res *= x;
    }

    return res;
}
