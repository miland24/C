#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define TAM 100

typedef struct v
{
    int codigo, passageiros;
    int preco;
    char origem, destino;
    int hrPartida;
} VOOS;

void preencheVoos(VOOS vs[TAM])
{
    for(int i = 0; i < TAM; i++)
    {
        vs[i].codigo = rand() % (500 - 100) + 100;
        vs[i].passageiros = rand() % (50 - 10) + 10;
        vs[i].preco = rand() % (500 - 100) + 100;
            do
            {
                vs[i].origem = rand() % (122 - 97) + 97;
                vs[i].destino = rand() % (122 - 97) + 97;
            }while(vs[i].origem == vs[i].destino);
        vs[i].hrPartida = rand() % 23;
    }
}

void imprimeVoosSelecionados(VOOS vs[TAM])
{
    char origem;

    printf("Digite o valor de origem do v�o: ");
    fflush(stdin);
    origem = getchar();
    fflush(stdin);

    for(int i = 0; i < TAM; i++)
    {
        if(vs[i].origem == origem || ((vs[i].hrPartida < 12) && (vs[i].hrPartida > 0)))
        {
            printf("\nC�digo do v�o: %i", vs[i].codigo);
            printf("\nN�mero de passageiros: %i", vs[i].passageiros);
            printf("\nHor�rio de Partida: %i:00", vs[i].hrPartida);
            printf("\nOrigem do v�o: %c", vs[i].origem);
            printf("\nDestino do v�o: %c", vs[i].destino);
            printf("\nPre�o do v�o: %i\n", vs[i].preco);
        }
    }
}

int main()
{
    setlocale(LC_ALL,"");
    VOOS voo[TAM];
    srand((unsigned int)time(NULL));

    preencheVoos(voo);
    imprimeVoosSelecionados(voo);
}
