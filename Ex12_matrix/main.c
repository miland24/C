#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 5

int main()
{
    int mat[TAM][TAM];

    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            if(i == j)
                mat[i][j] = 1;
            else
                mat[i][j] = 0;

        }
    }

    printf("Matriz: \n");
    for(int i = 0; i < TAM; i++)
    {
        printf("\n");
        for(int j = 0; j < TAM; j++)
        {
            printf("%i\t", mat[i][j]);
        }
    }
}
