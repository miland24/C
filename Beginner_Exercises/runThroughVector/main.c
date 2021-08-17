#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main() {
    char vet[10] = "CoCOZINHO";
    int x = strlen(vet), i;
    printf("Tamanho do vetor: %i\n\n", x);

    for (i = 0; i < x; i++) {
        printf("Posicao: [%i] do vetor, letra: %c\n", i + 1, vet[i]);
    }

    return;
}
