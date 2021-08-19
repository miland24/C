#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"");
    int *pt, number = 2;

    pt = &number;

    printf("Address: %i\n", pt);
    printf("Content: %i\n", *pt);
}
