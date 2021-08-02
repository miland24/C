#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define nRegistros 2

typedef struct av
{
    int NUM_VOO;
    char tipo[20];
    float preco;
    int num_lugares;
} AVIAO;

void criarRegistros(AVIAO vs[nRegistros])
{
    for(int i = 0; i < nRegistros; i++)
    {
        printf("Digite o número do vôo: ");
        scanf("%i", &vs[i].NUM_VOO);
        printf("Digite o tipo de vôo: ");
        fflush(stdin);
        fgets(vs[i].tipo, 20, stdin);
        printf("Digite o preço do vôo: ");
        scanf("%f", &vs[i].preco);
        printf("Digite o número de lugares do vôo: ");
        fflush(stdin);
        scanf("%i", &vs[i].num_lugares);
    }
}

void imprimeRegistros(AVIAO vs[nRegistros])
{
    for(int i = 0; i < nRegistros; i++)
    {
        printf("\nNúmero do vôo: %i", vs[i].NUM_VOO);
        printf("\nTipo de vôo: %s", vs[i].tipo);
        printf("Preço do vôo: %.2f", vs[i].preco);
        printf("\nNúmero de lugares do vôo: %i\n", vs[i].num_lugares);
    }
}

int main()
{
    setlocale(LC_ALL, "");

    AVIAO vetAviao[nRegistros];

    criarRegistros(vetAviao);

    system("cls");
    printf("-----REGISTRO DE VÔOS-----");
    imprimeRegistros(vetAviao);

}
