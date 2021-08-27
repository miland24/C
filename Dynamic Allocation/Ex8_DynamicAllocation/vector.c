#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

int* fill_vector(int* N, int* lenght)
{
    int x = 1, *v;

    v = (int*) malloc(*N * sizeof(int));

    //Reallocates the vector and fills it, until the user asks to stop
    while(x != 0)
    {
        if(*lenght == *N - 1)
        {
            *N += *N;
            v = (int*) realloc(v, *N * sizeof(int));
        }
        printf("\nType the number you wish to fit inside the [%i] position of the vector: ", *lenght + 1);
        scanf("%i", &v[*lenght]);
        *lenght += 1;
        printf("Do you wish to enter another number? (1 for yes/0 for no)");
        scanf("%i", &x);
    }

    return v;
}
