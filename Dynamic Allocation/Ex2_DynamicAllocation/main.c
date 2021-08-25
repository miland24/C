#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void f_matrix(int** matrix, int lSize, int cSize)
{
    int i, j;
    srand(time(NULL));

    for(i = 0; i < lSize; i++)
    {
        for(j = 0; j < cSize; j++)
        {
            *(*(matrix+i)+j) = rand() % 20;
        }
    }
}

int checks_matrix(int** matrix, int lSize, int cSize)
{
    int i, j, check;

    printf("\n\nType the number you wish to search inside the matrix: ");
    scanf("%i", &check);

    for(i = 0; i < lSize; i++)
    {
        for(j = 0; j < cSize; j++)
        {
            if(*(*(matrix + i) +j) == check)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int i, j, lSize, cSize, **matrix;

    printf("Type the number of lines in the matrix: ");
    scanf("%i", &lSize);
    printf("Type the number of columns in the matrix: ");
    scanf("%i", &cSize);

    matrix = (int**) malloc(lSize * sizeof(int*));

    if(!matrix)
    {
        printf("There isn't enough memory.");
        return 0;
    }

    for(i = 0; i < lSize; i++)
    {
        *(matrix + i) = (int*) malloc(cSize * sizeof(int));
    }

    if(!*(matrix + i))
    {
        printf("There isn't enough memory.");
        return 0;
    }

    f_matrix(matrix, lSize, cSize);

    if(checks_matrix(matrix, lSize, cSize))
    {
        system("cls");

        for(i = 0; i < lSize; i++)
        {
            printf("\n");
            for(j = 0; j < cSize; j++)
            {
                printf("[%i]\t", *(*(matrix+i)+j));
            }
        }

        printf("\n\nThe number you've chosen is inside the matrix!\n");
    }
    else
    {
        system("cls");

        for(i = 0; i < lSize; i++)
        {
            printf("\n");
            for(j = 0; j < cSize; j++)
            {
                printf("[%i]\t", *(*(matrix+i)+j));
            }
        }

        printf("\n\nThe number you've chosen isn't inside the matrix.\n");
    }

    return 0;
}
