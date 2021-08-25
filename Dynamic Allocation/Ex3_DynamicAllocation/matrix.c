#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrix.h"

int** mk_matrix(int line, int column)
{
    int** matrix, i, j;
    srand(time(NULL));

    matrix = (int**) malloc(line * sizeof(int*));

    for(i = 0; i < line; i++)
    {
        *(matrix + i) = (int*) malloc(column * sizeof(int));
    }

    for(i = 0; i < line; i++)
    {
        for(j = 0; j < column; j++)
        {
            *(*(matrix + i)+ j) = rand() % 10;
        }
    }

    return matrix;
}

int** transpose_matrix(int** matrix, int line, int column)
{
    int** tMatrix, i, j;

    tMatrix = (int**) malloc(column * sizeof(int*));

    for(i = 0; i < column; i++)
    {
        *(tMatrix + i) = (int*) malloc(line * sizeof(int));
    }

    for(i = 0; i < line; i++)
    {
        for(j = 0; j < column; j++)
        {
            *(*(tMatrix + j)+ i) = *(*(matrix + i)+ j);
        }
    }

    return tMatrix;
}
