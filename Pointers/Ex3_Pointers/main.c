#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *pt;
    char *ptc, letter = 'a';

    pt = &letter;
    ptc = &letter;

    printf("Pt address before the increment: %i\n", pt);
    printf("Ptc address before the increment: %i\n", ptc);

    pt++;
    ptc++;

    printf("\nPt address after the increment: %i\n", pt);
    printf("Ptc address after the increment: %i\n", ptc);
}
