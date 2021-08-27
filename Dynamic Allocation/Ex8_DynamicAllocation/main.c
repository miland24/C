#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "vector.h"

int main()
{
    int *vec, N = 10, lenght = 0, i;

    vec = fill_vector(&N, &lenght);

    system("cls");
    for(i = 0; i < lenght; i++)
    {
        sleep(1);
        printf("Vector [%i]: %i\n", i + 1, *(vec + i));
    }

    free(vec);
    return 0;
}
