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

    printf("Digite o valor de origem do vôo: ");
    fflush(stdin);
    origem = getchar();
    fflush(stdin);

    for(int i = 0; i < TAM; i++)
    {
        if(vs[i].origem == origem || ((vs[i].hrPartida < 12) && (vs[i].hrPartida > 0)))
        {
            printf("\nCódigo do vôo: %i", vs[i].codigo);
            printf("\nNúmero de passageiros: %i", vs[i].passageiros);
            printf("\nHorário de Partida: %i:00", vs[i].hrPartida);
            printf("\nOrigem do vôo: %c", vs[i].origem);
            printf("\nDestino do vôo: %c", vs[i].destino);
            printf("\nPreço do vôo: %i\n", vs[i].preco);
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
