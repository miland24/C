#include <stdio.h>                                         /*Author: Matheus Miland Pimentl do Vale ------- E-mail: matheus.miland@gmail.com*/
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <unistd.h>
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
    int nObstacles = -1, line, column;

    //Erases matrix in case there's obstacles already in it
    for(int i = 0; i < boardSIZE; i++)
    {
        for(int j = 0; j < boardSIZE; j++)
        {
            matrix[i][j] = ' ';
        }
    }

    //Prints the matrix
    for(int i = 0; i < boardSIZE; i++)
    {
        printf("\n");
        for(int j = 0; j < boardSIZE; j++)
        {
            printf("|%c|", matrix[i][j]);
        }
    }

    //Collects the number of obstacles and treats invalid number of obstacles
    printf("\n\nType the number of obstacles you want: ");
    fflush(stdin);
    scanf("%i", &nObstacles);

    while(nObstacles > 100 || nObstacles < 0)
    {
        printf("Invalid number of obstacles, type a new number: ");
        fflush(stdin);
        scanf("%i", &nObstacles);
    }

    //Insert obstacles and treats invalid index numbers
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
        fflush(stdin);
        scanf("%i", &line);
        printf("Type the column of the number %i obstacle:", i + 1);
        fflush(stdin);
        scanf("%i", &column);

        while(line > boardSIZE || column > boardSIZE || line < 0 || column < 0)
        {
        printf("Invalid column or line number, type a valid column/line ");
        printf("\n\nType the line of the number %i obstacle: ", i + 1);
        fflush(stdin);
        scanf("%i", &line);
        printf("Type the column of the number %i obstacle:", i + 1);
        fflush(stdin);
        scanf("%i", &column);
        }

        matrix[line][column] = 'X';
    }
    system("cls");
}

void initialPosition(char matrix[boardSIZE][boardSIZE])
{
    int pLine = -1, pColumn = -1;

    //Prints the matrix
    for(int i = 0; i < boardSIZE; i++)
    {
        printf("\n");
        for(int j = 0; j < boardSIZE; j++)
        {
            printf("|%c|", matrix[i][j]);
        }
    }

    //Collects the indexes where the snake will start and treats invalid indexes
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
    printf("\nType the number of the line you wish the snake to spawn: ");
    fflush(stdin);
    scanf("%i", &pLine);
    printf("Type the number of the column you wish the snake to spawn: ");
    fflush(stdin);
    scanf("%i", &pColumn);
    }

    //Erases the matrix in case there's a snake already in it
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

    //Treats invalid positions and inserts the snake in the matrix
    for(int i = 0; i < snakeSIZE; i++)
    {
        if(i == 0)
        {
            while(matrix[pLine][pColumn] != 'C')
            {

                if((matrix[pLine][pColumn] != 'X') && (matrix[pLine][pColumn + 1] == ' ') && (pColumn + 1 < boardSIZE))
                {
                    if(matrix[pLine + 1][pColumn] == ' ' || matrix[pLine][pColumn - 1] == ' ' || matrix[pLine - 1][pColumn] == ' ')
                    {
                        matrix[pLine][pColumn] = 'C';
                        fflush(stdin);
                    }
                    else
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
                    printf("\nType the number of the line you wish the snake to spawn: ");
                    fflush(stdin);
                    scanf("%i", &pLine);
                    printf("Type the number of the column you wish the snake to spawn: ");
                    fflush(stdin);
                    scanf("%i", &pColumn);
                    }
                }
                else if((matrix[pLine][pColumn] != 'X') && (matrix[pLine + 1][pColumn] == ' ') && (pLine + 1 < boardSIZE))
                {
                    if(matrix[pLine][pColumn + 1] == ' ' || matrix[pLine][pColumn - 1] == ' ' || matrix[pLine - 1][pColumn] == ' ')
                    {
                        matrix[pLine][pColumn] = 'C';
                        fflush(stdin);
                    }
                    else
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
                    printf("\nType the number of the line you wish the snake to spawn: ");
                    fflush(stdin);
                    scanf("%i", &pLine);
                    printf("Type the number of the column you wish the snake to spawn: ");
                    fflush(stdin);
                    scanf("%i", &pColumn);
                    }
                }
                else if((matrix[pLine][pColumn] != 'X') && (matrix[pLine][pColumn - 1] == ' ') && (pColumn - 1 >= 0))
                {
                    if(matrix[pLine + 1][pColumn] == ' ' || matrix[pLine][pColumn + 1] == ' ' || matrix[pLine - 1][pColumn] == ' ')
                    {
                        matrix[pLine][pColumn] = 'C';
                        fflush(stdin);
                    }
                    else
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
                    printf("\nType the number of the line you wish the snake to spawn: ");
                    fflush(stdin);
                    scanf("%i", &pLine);
                    printf("Type the number of the column you wish the snake to spawn: ");
                    fflush(stdin);
                    scanf("%i", &pColumn);
                    }
                }
                else if((matrix[pLine][pColumn] != 'X') && (matrix[pLine - 1][pColumn] == ' ') && (pLine - 1 >= 0))
                {
                    if(matrix[pLine + 1][pColumn] == ' ' || matrix[pLine][pColumn - 1] == ' ' || matrix[pLine][pColumn + 1] == ' ')
                    {
                        matrix[pLine][pColumn] = 'C';
                        fflush(stdin);
                    }
                    else
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
                    printf("\nType the number of the line you wish the snake to spawn: ");
                    fflush(stdin);
                    scanf("%i", &pLine);
                    printf("Type the number of the column you wish the snake to spawn: ");
                    fflush(stdin);
                    scanf("%i", &pColumn);
                    system("cls");
                    }
                }
                else
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
                    printf("\nType the number of the line you wish the snake to spawn: ");
                    fflush(stdin);
                    scanf("%i", &pLine);
                    printf("Type the number of the column you wish the snake to spawn: ");
                    fflush(stdin);
                    scanf("%i", &pColumn);
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
    system("cls");
}

void snakeMovement(char matrix[boardSIZE][boardSIZE])
{
    int vecLine[snakeSIZE], vecColumn[snakeSIZE], pos, nMovements = - 1, movement;
    srand(time(NULL));

    //Prints the matrix
    for(int i = 0; i < boardSIZE; i++)
    {
        printf("\n");
        for(int j = 0; j < boardSIZE; j++)
        {
        printf("|%c|", matrix[i][j]);
        }
    }

    //Checks if the movements value is valid and stores it
    printf("\nHow many movements you wish the snake to make? ");
    fflush(stdin);
    scanf("%i", &nMovements);

    while(nMovements < 0)
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

    printf("\nInvalid number of movements, please type a valid number of movements.");
    printf("\nHow many movements you wish the snake to make? ");
    fflush(stdin);
    scanf("%i", &nMovements);
    }

    //Generates a random number for the snake to move. Also checks for obstacles and the end of the board
    for(int interactions = 0; interactions < nMovements; interactions++)
    {
    sleep(1);
    //system("cls");
    pos = 1;

        //Checks the positions the snake is in
        for(int i = 0; i < boardSIZE; i++)
        {
            for(int j = 0; j < boardSIZE; j++)
            {
                    if(matrix[i][j] == 'C')
                    {
                        vecLine[0] = i;
                        vecColumn[0] = j;
                    }
                    else if(matrix[i][j] == '*')
                    {
                        vecLine[pos] = i;
                        vecColumn[pos] = j;
                        pos++;
                    }
                    else if(matrix[i][j] == '.')
                    {
                        vecLine[4] = i;
                        vecColumn[4] = j;
                    }
            }
        }
        movement = 0;

        if(movement == 0)
        {
            if(matrix[vecLine[0]][vecColumn[0] + 1] == ' ' && vecColumn[0] + 1 < boardSIZE)
            {
                matrix[vecLine[0]][vecColumn[0] + 1] = matrix[vecLine[0]][vecColumn[0]];
                matrix[vecLine[0]][vecColumn[0]] = matrix[vecLine[1]][vecColumn[1]];
                matrix[vecLine[1]][vecColumn[1]] = matrix[vecLine[2]][vecColumn[2]];
                matrix[vecLine[2]][vecColumn[2]] = matrix[vecLine[3]][vecColumn[3]];
                matrix[vecLine[3]][vecColumn[3]] = matrix[vecLine[4]][vecColumn[4]];
                matrix[vecLine[4]][vecColumn[4]] = ' ';
            }
            else if(matrix[vecLine[0] + 1][vecColumn[0]] == ' ' && vecLine[0] + 1 < boardSIZE)
            {
                matrix[vecLine[0] + 1][vecColumn[0]] = matrix[vecLine[0]][vecColumn[0]];
                matrix[vecLine[0]][vecColumn[0]] = matrix[vecLine[1]][vecColumn[1]];
                matrix[vecLine[1]][vecColumn[1]] = matrix[vecLine[2]][vecColumn[2]];
                matrix[vecLine[2]][vecColumn[2]] = matrix[vecLine[3]][vecColumn[3]];
                matrix[vecLine[3]][vecColumn[3]] = matrix[vecLine[4]][vecColumn[4]];
                matrix[vecLine[4]][vecColumn[4]] = ' ';
            }
            else if(matrix[vecLine[0]][vecColumn[0] - 1] == ' ' && vecColumn[0] - 1 >= 0)
            {
                matrix[vecLine[0]][vecColumn[0] - 1] = matrix[vecLine[0]][vecColumn[0]];
                matrix[vecLine[0]][vecColumn[0]] = matrix[vecLine[1]][vecColumn[1]];
                matrix[vecLine[1]][vecColumn[1]] = matrix[vecLine[2]][vecColumn[2]];
                matrix[vecLine[2]][vecColumn[2]] = matrix[vecLine[3]][vecColumn[3]];
                matrix[vecLine[3]][vecColumn[3]] = matrix[vecLine[4]][vecColumn[4]];
                matrix[vecLine[4]][vecColumn[4]] = ' ';
            }
            else if(matrix[vecLine[0] - 1][vecColumn[0]] == ' ' && vecLine[0] - 1 >= 0)
            {
                matrix[vecLine[0] - 1][vecColumn[0]] = matrix[vecLine[0]][vecColumn[0]];
                matrix[vecLine[0]][vecColumn[0]] = matrix[vecLine[1]][vecColumn[1]];
                matrix[vecLine[1]][vecColumn[1]] = matrix[vecLine[2]][vecColumn[2]];
                matrix[vecLine[2]][vecColumn[2]] = matrix[vecLine[3]][vecColumn[3]];
                matrix[vecLine[3]][vecColumn[3]] = matrix[vecLine[4]][vecColumn[4]];
                matrix[vecLine[4]][vecColumn[4]] = ' ';
            }
            else
            {
                printf("\nThe snake got stuck. Game Over!\n");
                return;
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
    }
}

int main()
{
    setlocale(LC_ALL,"");
    int option = 0;
    char board[boardSIZE][boardSIZE];
    srand(time(NULL));

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

            case 3:
            snakeMovement(board);
            break;

            case 4:
            printf("GG!");
            break;
        }
    }
}
