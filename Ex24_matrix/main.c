#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define ALUNOS 3
#define GABARITO 5
#define VALORQUESTAO 2

void preencheGabarito(int linhas, char vetor[linhas])
{
    for(int i = 0; i < linhas; i++)
    {
        printf("Digite o gabarito da questão (%i):", i + 1);
        fflush(stdin);
        vetor[i] = getc(stdin);
    }
}

void preencheRespostas(int linhas, int colunas, char matriz[linhas][colunas])
{
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            printf("\nDigite a resposta %i do aluno(%i): ", j + 1, i + 1);
            fflush(stdin);
            matriz[i][j] = getc(stdin);
        }
    }
}

void comparaRespostas(int linhas, int colunas, int nota[linhas], char vetor[colunas], char matriz[linhas][colunas])
{
    for(int i = 0; i < linhas; i++)
    {
        nota[i] = 0;
    }

    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            if(matriz[i][j] == vetor[j])
            {
                nota[i] += VALORQUESTAO;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");
    char matRes[ALUNOS][GABARITO], vetGab[GABARITO];
    int notas[ALUNOS];

    preencheGabarito(GABARITO, vetGab);

    preencheRespostas(ALUNOS, GABARITO, matRes);

    comparaRespostas(ALUNOS, GABARITO, notas, vetGab, matRes);

    system("cls");

    for(int i = 0; i < ALUNOS; i++)
    {
     printf("\nA nota do aluno (%i), foi: %i\n", i + 1, notas[i]);
    }
}
