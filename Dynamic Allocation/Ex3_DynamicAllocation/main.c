#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
    int n, m, i, j, **matrix, **tMatrix;

    printf("Type the number of lines of the matrix: ");
    scanf("%i", &n);
    printf("Type the number of columns of the matrix: ");
    scanf("%i", &m);

    matrix = mk_matrix(n, m);

    printf("\nOriginal matrix: \n");
    for(i = 0; i < n; i++)
    {
        printf("\n");
        for(j = 0; j < m; j++)
        {
            printf("[%i]\t", *(*(matrix + i)+ j));
        }
    }

    tMatrix = transpose_matrix(matrix, n, m);

    printf("\n\nTransposed matrix: \n");
    for(i = 0; i < m; i++)
    {
        printf("\n");
        for(j = 0; j < n; j++)
        {
            printf("[%i]\t", *(*(tMatrix + i)+ j));
        }
    }

    return 0;
}
