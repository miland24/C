#include <stdio.h>
#include <stdlib.h>

void read_vector(int v[], int *lenght)
{
    int i;

    for(i = 0; i < *lenght; i++)
    {
        printf("Type the number [%i] content of the vector: ", i);
        scanf("%i", &v[i]);
    }
}

void print_vector(int v[], int *lenght)
{
    int i;

    for(i = 0; i < *lenght; i++)
    {
        printf("[%i]", v[i]);
    }
}

void reverse_vector(int v[], int *lenght)
{
    int v2[*lenght], i, control = 0;

    for(i = *lenght - 1; i >= 0; i--)
    {
        v2[control] = v[i];
        control++;
    }

    for(i = 0; i < *lenght; i++)
    {
        v[i] = v2[i];
    }
}

int main()
{
    int vector[5], s = 5;

    read_vector(vector, &s);
    printf("\nNormal vector: \n");
    print_vector(vector, &s);
    reverse_vector(vector, &s);
    printf("\n\nReverse vector: \n");
    print_vector(vector, &s);

    return 0;
}
