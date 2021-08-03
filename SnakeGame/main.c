#include <stdio.h>                                         /*Author: Matheus Miland Pimentl do Vale ------- E-mail: matheus.miland@gmail.com*/
#include <stdlib.h>
#include <locale.h>
#define boardSIZE 10
#define snakeSIZE 5

int menu(char matrix[boardSIZE][boardSIZE])
{
    int option;

    do
    {
    printf("*==========================================SNAKE GAME==========================================C");
    for(int i = 0; i < boardSIZE; i++)
    {
        printf("\n");
        for(int j = 0; j < boardSIZE; j++)
        {
            printf("|%c|", matrix[i][j]);
        }
    }
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

void specifyObstacles(char matrix[boardSIZE][boardSIZE])
{
    int nObstacles, line, column;

    for(int i = 0; i < boardSIZE; i++)
    {
        for(int j = 0; j < boardSIZE; j++)
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
    system("cls");
}

void initialPosition(char matrix[boardSIZE][boardSIZE])
{
    int pLine, pColumn;

    printf("Type the number of the line you wish the snake to spawn: ");
    scanf("%i", &pLine);
    printf("Type the number of the column you wish the snake to spawn: ");
    scanf("%i", &pColumn);

    while(matrix[pLine][pColumn] != ' ')
    {
    system("cls");
    printf("Invalid position, choose another one.\n");
    printf("\nType the number of the line you wish the snake to spawn: ");
    scanf("%i", &pLine);
    printf("Type the number of the column you wish the snake to spawn: ");
    scanf("%i", &pColumn);
    }

    for(int i = 0; i < snakeSIZE; i++)
    {
        if(i == 0)
        {
            if(matrix[pLine][pColumn + 1] == ' ')
            {
                matrix[pLine][pColumn + 1] = 'C';
            }
            else if(matrix[pLine + 1][pColumn] == ' ')
            {
                matrix[pLine + 1][pColumn] = 'C';
            }
            else if(matrix[pLine][pColumn - 1] == ' ')
            {
                matrix[pLine][pColumn - 1] = 'C';
            }
            else if(matrix[pLine - 1][pColumn] == ' ')
            {
                matrix[pLine - 1][pColumn] = 'C';
            }
            else
            {
                printf("Invalid position, choose another one.\n");
                return;
            }
        }
        else if(i > 0 && i < 4)
        {
            if(matrix[pLine][pColumn + 1] == ' ')
            {
                matrix[pLine][pColumn + 1] = '*';
                pColumn += 1;
            }
            else if(matrix[pLine + 1][pColumn] == ' ')
            {
                matrix[pLine + 1][pColumn] = '*';
                pLine += 1;
            }
            else if(matrix[pLine][pColumn - 1] == ' ')
            {
                matrix[pLine][pColumn - 1] = '*';
                pColumn -= 1;
            }
            else if(matrix[pLine - 1][pColumn] == ' ')
            {
                matrix[pLine - 1][pColumn] = '*';
                pLine -= 1;
            }
            else
            {
                printf("Invalid position, choose another one.\n");
                return;
            }
        }
        else
        {
            if(matrix[pLine][pColumn + 1] == ' ')
            {
                matrix[pLine][pColumn + 1] = '.';
            }
            else if(matrix[pLine + 1][pColumn] == ' ')
            {
                matrix[pLine + 1][pColumn] = '.';
            }
            else if(matrix[pLine][pColumn - 1] == ' ')
            {
                matrix[pLine][pColumn - 1] = '.';
            }
            else if(matrix[pLine - 1][pColumn] == ' ')
            {
                matrix[pLine - 1][pColumn] = '.';
            }
            else
            {
                printf("Invalid position, choose another one.\n");
                return;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL,"");
    int option = 0;
    char board[boardSIZE][boardSIZE];

    for(int i = 0; i < boardSIZE; i++)
    {
        for(int j = 0; j < boardSIZE; j++)
        {
            board[i][j] = ' ';
        }
    }

    while(option != 4)
    {
        option = menu(board);

        switch (option)
        {
            case 1:
            specifyObstacles(board);
            break;

            case 2:
            initialPosition(board);
            break;

            case 4:
            printf("GG!");
            break;
        }
    }
}
