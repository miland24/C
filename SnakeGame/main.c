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
    printf("*==========================================SNAKE GAME==========================================C\n");
    for(int i = 0; i < boardSIZE; i++)
    {
        printf("\n");
        for(int j = 0; j < boardSIZE; j++)
        {
            printf("|%c|", matrix[i][j]);
        }
    }
    printf("\n\n\nSelect an option: ");
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

    for(int i = 0; i < boardSIZE; i++)
    {
        printf("\n");
        for(int j = 0; j < boardSIZE; j++)
        {
            printf("|%c|", matrix[i][j]);
        }
    }

    printf("\n\nType the number of obstacles you want: ");
    scanf("%i", &nObstacles);

    while(nObstacles > 100 || nObstacles < 0)
    {
        printf("Invalid number of obstacles, type a new number: ");
        scanf("%i", &nObstacles);
    }

    for(int i = 0; i < nObstacles; i++)
    {
        system("cls");
        for(int i = 0; i < boardSIZE; i++)
        {
        printf("\n");
            for(int j = 0; j < boardSIZE; j++)
            {
                printf("|%c|", matrix[i][j]);
            }
        }

        printf("\n\nType the line of the number %i obstacle: ", i + 1);
        scanf("%i", &line);
        printf("Type the column of the number %i obstacle:", i + 1);
        scanf("%i", &column);

        while(line > boardSIZE || column > boardSIZE || line < 0 || column < 0)
        {
        printf("Invalid column or line number, type a valid column/line ");
        printf("\n\nType the line of the number %i obstacle: ", i + 1);
        scanf("%i", &line);
        printf("Type the column of the number %i obstacle:", i + 1);
        scanf("%i", &column);
        }

        matrix[line][column] = 'X';
    }
    system("cls");
}

void initialPosition(char matrix[boardSIZE][boardSIZE])
{
    int pLine, pColumn;

    for(int i = 0; i < boardSIZE; i++)
    {
        printf("\n");
        for(int j = 0; j < boardSIZE; j++)
        {
            printf("|%c|", matrix[i][j]);
        }
    }

    printf("\n\nType the number of the line you wish the snake to spawn: ");
    scanf("%i", &pLine);
    printf("Type the number of the column you wish the snake to spawn: ");
    scanf("%i", &pColumn);

    while(matrix[pLine][pColumn] != ' ' || pLine > boardSIZE || pColumn > boardSIZE || pLine < 0 || pColumn < 0)
    {
    system("cls");

    for(int i = 0; i < boardSIZE; i++)
    {
        printf("\n");
        for(int j = 0; j < boardSIZE; j++)
        {
            printf("|%c|", matrix[i][j]);
        }
    }

    printf("\nInvalid position, choose another one.\n");
    printf("\n\nType the number of the line you wish the snake to spawn: ");
    scanf("%i", &pLine);
    printf("Type the number of the column you wish the snake to spawn: ");
    scanf("%i", &pColumn);
    }

    for(int i = 0; i < boardSIZE; i++)
    {
        for(int j = 0; j < boardSIZE; j++)
        {
            if(matrix[i][j] != 'X' && matrix[i][j] != ' ')
            {
                matrix[i][j] = ' ';
            }
        }
    }

    for(int i = 0; i < snakeSIZE; i++)
    {
        if(i == 0)
        {
            while(matrix[pLine][pColumn] != 'C')
            {

                if((matrix[pLine][pColumn + 1] == ' ') && (pColumn + 1 < boardSIZE))
                {
                    if(matrix[pLine + 1][pColumn] == ' ' || matrix[pLine][pColumn - 1] == ' ' || matrix[pLine - 1][pColumn] == ' ')
                    {
                        matrix[pLine][pColumn] = 'C';
                        fflush(stdin);
                    }
                    else
                    {
                    printf("Invalid position, choose another one.\n");
                    printf("\nType the number of the line you wish the snake to spawn: ");
                    scanf("%i", &pLine);
                    printf("Type the number of the column you wish the snake to spawn: ");
                    scanf("%i", &pColumn);
                    system("cls");
                    }
                }
                else if((matrix[pLine + 1][pColumn] == ' ') && (pLine + 1 < boardSIZE))
                {
                    if(matrix[pLine][pColumn + 1] == ' ' || matrix[pLine][pColumn - 1] == ' ' || matrix[pLine - 1][pColumn] == ' ')
                    {
                        matrix[pLine][pColumn] = 'C';
                        fflush(stdin);
                    }
                    else
                    {
                    printf("Invalid position, choose another one.\n");
                    printf("\nType the number of the line you wish the snake to spawn: ");
                    scanf("%i", &pLine);
                    printf("Type the number of the column you wish the snake to spawn: ");
                    scanf("%i", &pColumn);
                    system("cls");
                    }
                }
                else if((matrix[pLine][pColumn - 1] == ' ') && (pColumn - 1 >= 0))
                {
                    if(matrix[pLine + 1][pColumn] == ' ' || matrix[pLine][pColumn + 1] == ' ' || matrix[pLine - 1][pColumn] == ' ')
                    {
                        matrix[pLine][pColumn] = 'C';
                        fflush(stdin);
                    }
                    else
                    {
                    printf("Invalid position, choose another one.\n");
                    printf("\nType the number of the line you wish the snake to spawn: ");
                    scanf("%i", &pLine);
                    printf("Type the number of the column you wish the snake to spawn: ");
                    scanf("%i", &pColumn);
                    system("cls");
                    }
                }
                else if((matrix[pLine - 1][pColumn] == ' ') && (pLine - 1 >= 0))
                {
                    if(matrix[pLine + 1][pColumn] == ' ' || matrix[pLine][pColumn - 1] == ' ' || matrix[pLine][pColumn + 1] == ' ')
                    {
                        matrix[pLine][pColumn] = 'C';
                        fflush(stdin);
                    }
                    else
                    {
                    printf("Invalid position, choose another one.\n");
                    printf("\nType the number of the line you wish the snake to spawn: ");
                    scanf("%i", &pLine);
                    printf("Type the number of the column you wish the snake to spawn: ");
                    scanf("%i", &pColumn);
                    system("cls");
                    }
                }
                else
                {
                    printf("Invalid position.");
                    return;
                }
            }
        }
        else if(i > 0 && i < 4)
        {
            if((matrix[pLine][pColumn + 1] == ' ') && (pColumn + 1 < boardSIZE))
            {
                matrix[pLine][pColumn + 1] = '*';
                pColumn += 1;
            }
            else if((matrix[pLine + 1][pColumn] == ' ') && (pLine + 1 < boardSIZE))
            {
                matrix[pLine + 1][pColumn] = '*';
                pLine += 1;
            }
            else if((matrix[pLine][pColumn - 1] == ' ') && (pColumn - 1 >= 0))
            {
                matrix[pLine][pColumn - 1] = '*';
                pColumn -= 1;
            }
            else if((matrix[pLine - 1][pColumn] == ' ') && (pLine - 1 >= 0))
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
            if((matrix[pLine][pColumn + 1] == ' ') && (pColumn + 1 < boardSIZE))
            {
                matrix[pLine][pColumn + 1] = '.';
            }
            else if((matrix[pLine + 1][pColumn] == ' ') && (pLine + 1 < boardSIZE))
            {
                matrix[pLine + 1][pColumn] = '.';
            }
            else if((matrix[pLine][pColumn - 1] == ' ') && (pColumn - 1 >= 0))
            {
                matrix[pLine][pColumn - 1] = '.';
            }
            else if((matrix[pLine - 1][pColumn] == ' ') && (pLine - 1 >= 0))
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
