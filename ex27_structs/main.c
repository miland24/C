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
        printf("Digite o n�mero do v�o: ");
        scanf("%i", &vs[i].NUM_VOO);
        printf("Digite o tipo de v�o: ");
        fflush(stdin);
        fgets(vs[i].tipo, 20, stdin);
        printf("Digite o pre�o do v�o: ");
        scanf("%f", &vs[i].preco);
        printf("Digite o n�mero de lugares do v�o: ");
        fflush(stdin);
        scanf("%i", &vs[i].num_lugares);
    }
}

void imprimeRegistros(AVIAO vs[nRegistros])
{
    for(int i = 0; i < nRegistros; i++)
    {
        printf("\nN�mero do v�o: %i", vs[i].NUM_VOO);
        printf("\nTipo de v�o: %s", vs[i].tipo);
        printf("Pre�o do v�o: %.2f", vs[i].preco);
        printf("\nN�mero de lugares do v�o: %i\n", vs[i].num_lugares);
    }
}

int main()
{
    setlocale(LC_ALL, "");

    AVIAO vetAviao[nRegistros];

    criarRegistros(vetAviao);

    system("cls");
    printf("-----REGISTRO DE V�OS-----");
    imprimeRegistros(vetAviao);

}
