#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void scanNumbers(int *vec)
{
    int i, number;

    for(i = 0; i < TAM; i++)
    {
        printf("Type the (%i)ish number: \n", i);
        scanf("%i", &number);

        vec[i] = number;
    }
}

void reversePrint(int *vec)
{
    int i;

    system("cls");

    for(i = TAM - 1; i >= 0; i--)
    {
        printf("\nvector[%i] number: %i\n", i, vec[i]);
    }
}

int main()
{
    int vec[TAM];

    scanNumbers(vec);
    reversePrint(vec);

    return 0;
}
