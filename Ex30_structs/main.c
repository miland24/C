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

void preencheVoos(VOOS vs[2])
{
    for(int i = 0; i < 2; i++)
    {
        vs[i].codigo = rand() % (500 - 100) + 100;
        vs[i].passageiros = rand() % (50 - 10) + 10;
        vs[i].preco = rand() % (500 - 100) + 100;
        vs[i].origem = rand() % (122 - 97) + 97;
        vs[i].destino = rand() % (122 - 97) + 97;
        vs[i].hrPartida = rand() % 23;
    }
}

int main()
{
    setlocale(LC_ALL,"");
    VOOS voo[2];
    srand(time(NULL));

    preencheVoos(voo);

        for(int i = 0; i < 2; i++)
    {
    printf("\n%i", voo[i].codigo);
    printf("\n%i", voo[i].passageiros);
    printf("\n%i:00", voo[i].hrPartida);
    printf("\n%c", voo[i].origem);
    printf("\n%c", voo[i].destino);
    printf("\n%i", voo[i].preco);
    }

}
