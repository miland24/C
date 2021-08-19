#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *pt;
    float *ptf, number = 3.5;

    pt = &number;
    ptf = &number;

    printf("pt Content: %i\n", *pt); //The content will be memory trash, incorrect pointer type.
    printf("ptf Content: %.2f\n", *ptf);
}
