#include <stdio.h>                                         /*Author: Matheus Miland Pimentl do Vale ------- E-mail: matheus.miland@gmail.com*/
#include <stdlib.h>
#include <locale.h>
#define TAM 10

int menu()
{
    int option;

    do
    {
    printf("*==========================================SNAKE GAME==========================================C");
    printf("\nSelect an option: ");
    printf("\n1- Specify the number and position of obstacles ");
    printf("\n2- Indicate the initial position of the snake's head ");
    printf("\n3- Initiate a simulation indicating the number of movements the snake will make ");
    printf("\n4- Exit game\n");
    scanf("%i", &option);
    fflush(stdin);
    system("cls");
    }while(option < 1 || option > 4);

    return option;
}

void specifyObstacles(char matrix[TAM][TAM])
{
    int nObstacles, line, column;

    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            matrix[i][j] = ' ';
        }
    }

    printf("Type the number of obstacles you want: ");
    scanf("%i", &nObstacles);

    for(int i = 0; i < nObstacles; i++)
    {
        printf("Type the line of the number %i obstacle: ", i + 1);
        scanf("%i", &line);
        printf("Type the column of the number %i obstacle:", i + 1);
        scanf("%i", &column);
        matrix[line][column] = 'X';
    }
}

int main()
{
    setlocale(LC_ALL,"");
    int option = 0;
    char board[TAM][TAM];

    while(option != 4)
    {
        option = menu();

        switch (option)
        {
            case 1:
            specifyObstacles(board);
            break;

            case 4:
            printf("GG!");
            break;
        }
    }
}
