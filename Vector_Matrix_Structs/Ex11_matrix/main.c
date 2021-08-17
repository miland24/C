#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define TAM 10

void preencheMatriz();
void verificarMatriz();


int main()
{
    setlocale(LC_ALL, "");
    time_t tempo;
    float mat[TAM][TAM], maiorNumero;
    int maiorNumeroLin, maiorNumeroCol;
    srand(time(&tempo));

    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            mat[i][j] = ((float)rand() / (float)(RAND_MAX) * 5);
        }
    }

    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            if(mat[i][j] > maiorNumero)
            {
                maiorNumero = mat[i][j];
                maiorNumeroLin = i;
                maiorNumeroCol = j;
            }
        }
    }

    printf("\nMatriz: ");
    for(int i = 0; i < TAM; i++)
    {
        printf("\n");
        for(int j = 0; j < TAM; j++)
        {
            printf("%.2f\t", mat[i][j]);
        }
    }
    printf("\n\nO índice da matriz com o maior número é: [%i][%i]", maiorNumeroLin, maiorNumeroCol);
    printf("\nE o número é: %.2f", maiorNumero);
}
