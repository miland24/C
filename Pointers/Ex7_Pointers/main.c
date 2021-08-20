#include <stdio.h>
#include <stdlib.h>

int operation(int *pa, int *pb)
{
    int a, b;

    a = *pa;
    b = *pb;

    a++;
    b++;

    return a + b;
}

int main()
{
    int a, b, sum;

    printf("Type the first number: ");
    scanf("%i", &a);
    printf("Type the second number: ");
    scanf("%i", &b);

    sum = operation(&a, &b);

    printf("\nNumbers sum: %i\n", sum);

    return 0;
}
