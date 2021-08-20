#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define TAM 5

int main()
{
    int matrix[TAM][TAM], *pt, i, j;
    pt = matrix[0];

    printf("Filling the matrix with indices.\n");
    sleep(1);

    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            matrix[i][j] = 1;
        }
    }

    printf("Matrix filled with indices: \n");
    for(i = 0; i < TAM; i++)
    {
        printf("\n");
            for(j = 0; j < TAM; j++)
            {
                printf("[%i]\t", matrix[i][j]);
            }
    }

    printf("\n\nFilling the matrix linearly.\n");
    sleep(1);

    for(i = 0; i < TAM*TAM; i++)
    {
        *pt = 2;
        pt++;
    }

    pt = matrix[0];

    printf("Matrix filled linearly: \n\n");
    for(i = 0; i < TAM*TAM; i++)
    {
        if(i % 5 == 0 && i != 0)
        {
            printf("\n");
        }
        printf("[%i]\t", *pt);
        pt++;
    }
}
