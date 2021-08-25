#include <stdio.h>
#include <stdlib.h>

int* sum_vectors(int *v1, int *v2, int N)
{
    int* v3, i;

    v3 = (int* ) malloc(N * sizeof(int));

    for(i = 0; i < N; i++)
    {
        v3[i] = v1[i] + v2[i];
    }

    return v3;
}

int main()
{
    int v1[4] = {2, 4, 1, 4}, v2[4] = {6, 6, 4, 9}, * v3, N = 4, i;

    v3 = sum_vectors(v1, v2, N);

    printf("Vectors sum: \n");
    for(i = 0; i < N; i++)
    {
        printf("[%i]\t", v3[i]);
    }

    return 0;
}
