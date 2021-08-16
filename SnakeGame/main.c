#include <stdio.h>                                                          //Author: Matheus Miland Pimentel do Vale -------------------------------- e-mail: matheus.miland@gmail.com
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <unistd.h>
#define boardSIZE 10
#define snakeSIZE 5

int hLine, hColumn, vecPosLine[4], vecPosColumn[4];

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
                        hLine = pLine;
                        hColumn = pColumn;
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
                        hLine = pLine;
                        hColumn = pColumn;
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
                        hLine = pLine;
                        hColumn = pColumn;
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
                        hLine = pLine;
                        hColumn = pColumn;
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
                vecPosLine[i - 1] = pLine;
                vecPosColumn[i - 1] = pColumn + 1;
                pColumn += 1;
            }
            else if((matrix[pLine + 1][pColumn] == ' ') && (pLine + 1 < boardSIZE))
            {
                matrix[pLine + 1][pColumn] = '*';
                vecPosLine[i - 1] = pLine + 1;
                vecPosColumn[i - 1] = pColumn;
                pLine += 1;
            }
            else if((matrix[pLine][pColumn - 1] == ' ') && (pColumn - 1 >= 0))
            {
                matrix[pLine][pColumn - 1] = '*';
                vecPosLine[i - 1] = pLine;
                vecPosColumn[i - 1] = pColumn - 1;
                pColumn -= 1;
            }
            else if((matrix[pLine - 1][pColumn] == ' ') && (pLine - 1 >= 0))
            {
                matrix[pLine - 1][pColumn] = '*';
                vecPosLine[i - 1] = pLine - 1;
                vecPosColumn[i - 1] = pColumn;
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
                vecPosLine[i - 1] = pLine;
                vecPosColumn[i - 1] = pColumn + 1;
            }
            else if((matrix[pLine + 1][pColumn] == ' ') && (pLine + 1 < boardSIZE))
            {
                matrix[pLine + 1][pColumn] = '.';
                vecPosLine[i - 1] = pLine + 1;
                vecPosColumn[i - 1] = pColumn;
            }
            else if((matrix[pLine][pColumn - 1] == ' ') && (pColumn - 1 >= 0))
            {
                matrix[pLine][pColumn - 1] = '.';
                vecPosLine[i - 1] = pLine;
                vecPosColumn[i - 1] = pColumn - 1;
            }
            else if((matrix[pLine - 1][pColumn] == ' ') && (pLine - 1 >= 0))
            {
                matrix[pLine - 1][pColumn] = '.';
                vecPosLine[i - 1] = pLine - 1;
                vecPosColumn[i - 1] = pColumn;
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
    int vecLine[4], vecColumn[4], nMovements = - 1, visitedSquares = 0, snakeE = 0, speed = -1, movement;
    char aux[boardSIZE][boardSIZE];
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

    //Checks if the snake is inside the board already
    for(int i = 0; i < boardSIZE; i++)
    {
        for(int j = 0; j < boardSIZE; j++)
        {
        if(matrix[i][j] == 'C')
            snakeE = 1;
        }
    }

    if(snakeE == 0)
    {
        printf("\nYou need to put the snake in the matrix first!\n");
        getchar();
        fflush(stdin);
        system("cls");
        return;
    }

    if((matrix[hLine][hColumn + 1] != ' ' || hColumn + 1 > boardSIZE) && (matrix[hLine + 1][hColumn] != ' ' || hLine + 1 > boardSIZE)
        && (matrix[hLine][hColumn - 1] != ' ' || hColumn - 1 < 0) && (matrix[hLine - 1][hColumn] != ' ' || hLine - 1 < 0))
    {
        printf("\nYou need to put the snake in the matrix again, its stuck!\n");
        fflush(stdin);
        getchar();
        fflush(stdin);
        system("cls");
        return;
    }

    //checks where the snake is, adds a flag in the squares she's in on the auxiliar matrix.
    for(int i = 0; i < boardSIZE; i++)
    {
        for(int j = 0; j < boardSIZE; j++)
        {
            if(matrix[i][j] != ' ' && matrix[i][j] != 'X')
            {
                aux[i][j] = 'V';
            }
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

    printf("Type the speed you wish the snake to move(the lesser the faster she'll move):");
    fflush(stdin);
    scanf("%i", &speed);

    while(speed < 0)
    {
    printf("the speed must be more than or equal to 0: ");
    fflush(stdin);
    scanf("%i", &speed);
    }

    //Generates a random number for the snake to move. Also checks for obstacles and the end of the board
    for(int interactions = 0; interactions < nMovements; interactions++)
    {
    sleep(speed);

    system("cls");

        movement = rand() % 4;

        switch(movement)
        {
            //snake movement logic
            case 0:
                if(matrix[hLine - 1][hColumn ] == ' ' && hLine - 1 >= 0)
                {
                    matrix[hLine - 1][hColumn] = 'C';
                    matrix[vecPosLine[3]][vecPosColumn[3]] = ' ';
                    vecLine[0] = hLine;
                    vecColumn[0] = hColumn;
                    vecLine[1] = vecPosLine[0];
                    vecColumn[1] = vecPosColumn[0];
                    vecLine[2] = vecPosLine[1];
                    vecColumn[2] = vecPosColumn[1];
                    vecLine[3] = vecPosLine[2];
                    vecColumn[3] = vecPosColumn[2];
                    matrix[vecLine[0]][vecColumn[0]] = '*';
                    matrix[vecLine[1]][vecColumn[1]] = '*';
                    matrix[vecLine[2]][vecColumn[2]] = '*';
                    matrix[vecLine[3]][vecColumn[3]] = '.';
                    vecPosLine[0] = vecLine[0];
                    vecPosColumn[0] = vecColumn[0];
                    vecPosLine[1] = vecLine[1];
                    vecPosColumn[1] = vecColumn[1];
                    vecPosLine[2] = vecLine[2];
                    vecPosColumn[2] = vecColumn[2];
                    vecPosLine[3] = vecLine[3];
                    vecPosColumn[3] = vecColumn[3];
                    hLine--;
                    aux[hLine][hColumn] = 'V';
                }
                else if(matrix[hLine + 1][hColumn] == ' ' && hLine + 1 < boardSIZE)
                {
                    matrix[hLine + 1][hColumn] = 'C';
                    matrix[vecPosLine[3]][vecPosColumn[3]] = ' ';
                    vecLine[0] = hLine;
                    vecColumn[0] = hColumn;
                    vecLine[1] = vecPosLine[0];
                    vecColumn[1] = vecPosColumn[0];
                    vecLine[2] = vecPosLine[1];
                    vecColumn[2] = vecPosColumn[1];
                    vecLine[3] = vecPosLine[2];
                    vecColumn[3] = vecPosColumn[2];
                    matrix[vecLine[0]][vecColumn[0]] = '*';
                    matrix[vecLine[1]][vecColumn[1]] = '*';
                    matrix[vecLine[2]][vecColumn[2]] = '*';
                    matrix[vecLine[3]][vecColumn[3]] = '.';
                    vecPosLine[0] = vecLine[0];
                    vecPosColumn[0] = vecColumn[0];
                    vecPosLine[1] = vecLine[1];
                    vecPosColumn[1] = vecColumn[1];
                    vecPosLine[2] = vecLine[2];
                    vecPosColumn[2] = vecColumn[2];
                    vecPosLine[3] = vecLine[3];
                    vecPosColumn[3] = vecColumn[3];
                    hLine++;
                    aux[hLine][hColumn] = 'V';
                }
                else if(matrix[hLine][hColumn - 1] == ' ' && hColumn - 1 >= 0)
                {
                    matrix[hLine][hColumn - 1] = 'C';
                    matrix[vecPosLine[3]][vecPosColumn[3]] = ' ';
                    vecLine[0] = hLine;
                    vecColumn[0] = hColumn;
                    vecLine[1] = vecPosLine[0];
                    vecColumn[1] = vecPosColumn[0];
                    vecLine[2] = vecPosLine[1];
                    vecColumn[2] = vecPosColumn[1];
                    vecLine[3] = vecPosLine[2];
                    vecColumn[3] = vecPosColumn[2];
                    matrix[vecLine[0]][vecColumn[0]] = '*';
                    matrix[vecLine[1]][vecColumn[1]] = '*';
                    matrix[vecLine[2]][vecColumn[2]] = '*';
                    matrix[vecLine[3]][vecColumn[3]] = '.';
                    vecPosLine[0] = vecLine[0];
                    vecPosColumn[0] = vecColumn[0];
                    vecPosLine[1] = vecLine[1];
                    vecPosColumn[1] = vecColumn[1];
                    vecPosLine[2] = vecLine[2];
                    vecPosColumn[2] = vecColumn[2];
                    vecPosLine[3] = vecLine[3];
                    vecPosColumn[3] = vecColumn[3];
                    hColumn--;
                    aux[hLine][hColumn] = 'V';
                }
                else if(matrix[hLine][hColumn + 1] == ' ' && hColumn + 1 < boardSIZE)
                {
                    matrix[hLine][hColumn + 1] = 'C';
                    matrix[vecPosLine[3]][vecPosColumn[3]] = ' ';
                    vecLine[0] = hLine;
                    vecColumn[0] = hColumn;
                    vecLine[1] = vecPosLine[0];
                    vecColumn[1] = vecPosColumn[0];
                    vecLine[2] = vecPosLine[1];
                    vecColumn[2] = vecPosColumn[1];
                    vecLine[3] = vecPosLine[2];
                    vecColumn[3] = vecPosColumn[2];
                    matrix[vecLine[0]][vecColumn[0]] = '*';
                    matrix[vecLine[1]][vecColumn[1]] = '*';
                    matrix[vecLine[2]][vecColumn[2]] = '*';
                    matrix[vecLine[3]][vecColumn[3]] = '.';
                    vecPosLine[0] = vecLine[0];
                    vecPosColumn[0] = vecColumn[0];
                    vecPosLine[1] = vecLine[1];
                    vecPosColumn[1] = vecColumn[1];
                    vecPosLine[2] = vecLine[2];
                    vecPosColumn[2] = vecColumn[2];
                    vecPosLine[3] = vecLine[3];
                    vecPosColumn[3] = vecColumn[3];
                    hColumn++;
                    aux[hLine][hColumn] = 'V';
                }
                else
                {
                    printf("The snake got stuck. Game Over!\n\n");
                    for(int i = 0; i < boardSIZE; i++)
                    {
                        for(int j = 0; j < boardSIZE; j++)
                        {
                            if(aux[i][j] == 'V')
                            {
                                visitedSquares++;
                            }
                        }
                    }
                    printf("Number of unique squares the snake has visited: %i\n", visitedSquares);
                    printf("Number of unique squares the snake hasn't visited: %i\n\n", 100 - visitedSquares);
                    return;
                }
            break;
            case 1:
                if(matrix[hLine][hColumn + 1] == ' ' && hColumn + 1 < boardSIZE)
                {
                    matrix[hLine][hColumn + 1] = 'C';
                    matrix[vecPosLine[3]][vecPosColumn[3]] = ' ';
                    vecLine[0] = hLine;
                    vecColumn[0] = hColumn;
                    vecLine[1] = vecPosLine[0];
                    vecColumn[1] = vecPosColumn[0];
                    vecLine[2] = vecPosLine[1];
                    vecColumn[2] = vecPosColumn[1];
                    vecLine[3] = vecPosLine[2];
                    vecColumn[3] = vecPosColumn[2];
                    matrix[vecLine[0]][vecColumn[0]] = '*';
                    matrix[vecLine[1]][vecColumn[1]] = '*';
                    matrix[vecLine[2]][vecColumn[2]] = '*';
                    matrix[vecLine[3]][vecColumn[3]] = '.';
                    vecPosLine[0] = vecLine[0];
                    vecPosColumn[0] = vecColumn[0];
                    vecPosLine[1] = vecLine[1];
                    vecPosColumn[1] = vecColumn[1];
                    vecPosLine[2] = vecLine[2];
                    vecPosColumn[2] = vecColumn[2];
                    vecPosLine[3] = vecLine[3];
                    vecPosColumn[3] = vecColumn[3];
                    hColumn++;
                    aux[hLine][hColumn] = 'V';
                }
                else if(matrix[hLine - 1][hColumn] == ' ' && hLine - 1 >= 0)
                {
                    matrix[hLine - 1][hColumn] = 'C';
                    matrix[vecPosLine[3]][vecPosColumn[3]] = ' ';
                    vecLine[0] = hLine;
                    vecColumn[0] = hColumn;
                    vecLine[1] = vecPosLine[0];
                    vecColumn[1] = vecPosColumn[0];
                    vecLine[2] = vecPosLine[1];
                    vecColumn[2] = vecPosColumn[1];
                    vecLine[3] = vecPosLine[2];
                    vecColumn[3] = vecPosColumn[2];
                    matrix[vecLine[0]][vecColumn[0]] = '*';
                    matrix[vecLine[1]][vecColumn[1]] = '*';
                    matrix[vecLine[2]][vecColumn[2]] = '*';
                    matrix[vecLine[3]][vecColumn[3]] = '.';
                    vecPosLine[0] = vecLine[0];
                    vecPosColumn[0] = vecColumn[0];
                    vecPosLine[1] = vecLine[1];
                    vecPosColumn[1] = vecColumn[1];
                    vecPosLine[2] = vecLine[2];
                    vecPosColumn[2] = vecColumn[2];
                    vecPosLine[3] = vecLine[3];
                    vecPosColumn[3] = vecColumn[3];
                    hLine--;
                    aux[hLine][hColumn] = 'V';
                }
                else if(matrix[hLine][hColumn - 1] == ' ' && hColumn - 1 >= 0)
                {
                    matrix[hLine][hColumn - 1] = 'C';
                    matrix[vecPosLine[3]][vecPosColumn[3]] = ' ';
                    vecLine[0] = hLine;
                    vecColumn[0] = hColumn;
                    vecLine[1] = vecPosLine[0];
                    vecColumn[1] = vecPosColumn[0];
                    vecLine[2] = vecPosLine[1];
                    vecColumn[2] = vecPosColumn[1];
                    vecLine[3] = vecPosLine[2];
                    vecColumn[3] = vecPosColumn[2];
                    matrix[vecLine[0]][vecColumn[0]] = '*';
                    matrix[vecLine[1]][vecColumn[1]] = '*';
                    matrix[vecLine[2]][vecColumn[2]] = '*';
                    matrix[vecLine[3]][vecColumn[3]] = '.';
                    vecPosLine[0] = vecLine[0];
                    vecPosColumn[0] = vecColumn[0];
                    vecPosLine[1] = vecLine[1];
                    vecPosColumn[1] = vecColumn[1];
                    vecPosLine[2] = vecLine[2];
                    vecPosColumn[2] = vecColumn[2];
                    vecPosLine[3] = vecLine[3];
                    vecPosColumn[3] = vecColumn[3];
                    hColumn--;
                    aux[hLine][hColumn] = 'V';
                }
                else if(matrix[hLine + 1][hColumn] == ' ' && hLine + 1 < boardSIZE)
                {
                    matrix[hLine + 1][hColumn] = 'C';
                    matrix[vecPosLine[3]][vecPosColumn[3]] = ' ';
                    vecLine[0] = hLine;
                    vecColumn[0] = hColumn;
                    vecLine[1] = vecPosLine[0];
                    vecColumn[1] = vecPosColumn[0];
                    vecLine[2] = vecPosLine[1];
                    vecColumn[2] = vecPosColumn[1];
                    vecLine[3] = vecPosLine[2];
                    vecColumn[3] = vecPosColumn[2];
                    matrix[vecLine[0]][vecColumn[0]] = '*';
                    matrix[vecLine[1]][vecColumn[1]] = '*';
                    matrix[vecLine[2]][vecColumn[2]] = '*';
                    matrix[vecLine[3]][vecColumn[3]] = '.';
                    vecPosLine[0] = vecLine[0];
                    vecPosColumn[0] = vecColumn[0];
                    vecPosLine[1] = vecLine[1];
                    vecPosColumn[1] = vecColumn[1];
                    vecPosLine[2] = vecLine[2];
                    vecPosColumn[2] = vecColumn[2];
                    vecPosLine[3] = vecLine[3];
                    vecPosColumn[3] = vecColumn[3];
                    hLine++;
                    aux[hLine][hColumn] = 'V';
                }
                else
                {
                    printf("The snake got stuck. Game Over!\n");
                    for(int i = 0; i < boardSIZE; i++)
                    {
                        for(int j = 0; j < boardSIZE; j++)
                        {
                            if(aux[i][j] == 'V')
                            {
                                visitedSquares++;
                            }
                        }
                    }
                    printf("Number of unique squares the snake has visited: %i\n", visitedSquares);
                    printf("Number of unique squares the snake hasn't visited: %i\n\n", 100 - visitedSquares);
                    return;
                }
            break;
            case 2:
                if(matrix[hLine][hColumn - 1] == ' ' && hColumn - 1 >= 0)
                {
                    matrix[hLine][hColumn - 1] = 'C';
                    matrix[vecPosLine[3]][vecPosColumn[3]] = ' ';
                    vecLine[0] = hLine;
                    vecColumn[0] = hColumn;
                    vecLine[1] = vecPosLine[0];
                    vecColumn[1] = vecPosColumn[0];
                    vecLine[2] = vecPosLine[1];
                    vecColumn[2] = vecPosColumn[1];
                    vecLine[3] = vecPosLine[2];
                    vecColumn[3] = vecPosColumn[2];
                    matrix[vecLine[0]][vecColumn[0]] = '*';
                    matrix[vecLine[1]][vecColumn[1]] = '*';
                    matrix[vecLine[2]][vecColumn[2]] = '*';
                    matrix[vecLine[3]][vecColumn[3]] = '.';
                    vecPosLine[0] = vecLine[0];
                    vecPosColumn[0] = vecColumn[0];
                    vecPosLine[1] = vecLine[1];
                    vecPosColumn[1] = vecColumn[1];
                    vecPosLine[2] = vecLine[2];
                    vecPosColumn[2] = vecColumn[2];
                    vecPosLine[3] = vecLine[3];
                    vecPosColumn[3] = vecColumn[3];
                    hColumn--;
                    aux[hLine][hColumn] = 'V';
                }
                else if(matrix[hLine + 1][hColumn] == ' ' && hLine + 1 < boardSIZE)
                {
                    matrix[hLine + 1][hColumn] = 'C';
                    matrix[vecPosLine[3]][vecPosColumn[3]] = ' ';
                    vecLine[0] = hLine;
                    vecColumn[0] = hColumn;
                    vecLine[1] = vecPosLine[0];
                    vecColumn[1] = vecPosColumn[0];
                    vecLine[2] = vecPosLine[1];
                    vecColumn[2] = vecPosColumn[1];
                    vecLine[3] = vecPosLine[2];
                    vecColumn[3] = vecPosColumn[2];
                    matrix[vecLine[0]][vecColumn[0]] = '*';
                    matrix[vecLine[1]][vecColumn[1]] = '*';
                    matrix[vecLine[2]][vecColumn[2]] = '*';
                    matrix[vecLine[3]][vecColumn[3]] = '.';
                    vecPosLine[0] = vecLine[0];
                    vecPosColumn[0] = vecColumn[0];
                    vecPosLine[1] = vecLine[1];
                    vecPosColumn[1] = vecColumn[1];
                    vecPosLine[2] = vecLine[2];
                    vecPosColumn[2] = vecColumn[2];
                    vecPosLine[3] = vecLine[3];
                    vecPosColumn[3] = vecColumn[3];
                    hLine++;
                    aux[hLine][hColumn] = 'V';
                }
                else if(matrix[hLine][hColumn + 1] == ' ' && hColumn + 1 < boardSIZE)
                {
                    matrix[hLine][hColumn + 1] = 'C';
                    matrix[vecPosLine[3]][vecPosColumn[3]] = ' ';
                    vecLine[0] = hLine;
                    vecColumn[0] = hColumn;
                    vecLine[1] = vecPosLine[0];
                    vecColumn[1] = vecPosColumn[0];
                    vecLine[2] = vecPosLine[1];
                    vecColumn[2] = vecPosColumn[1];
                    vecLine[3] = vecPosLine[2];
                    vecColumn[3] = vecPosColumn[2];
                    matrix[vecLine[0]][vecColumn[0]] = '*';
                    matrix[vecLine[1]][vecColumn[1]] = '*';
                    matrix[vecLine[2]][vecColumn[2]] = '*';
                    matrix[vecLine[3]][vecColumn[3]] = '.';
                    vecPosLine[0] = vecLine[0];
                    vecPosColumn[0] = vecColumn[0];
                    vecPosLine[1] = vecLine[1];
                    vecPosColumn[1] = vecColumn[1];
                    vecPosLine[2] = vecLine[2];
                    vecPosColumn[2] = vecColumn[2];
                    vecPosLine[3] = vecLine[3];
                    vecPosColumn[3] = vecColumn[3];
                    hColumn++;
                    aux[hLine][hColumn] = 'V';
                }
                else if(matrix[hLine - 1][hColumn] == ' ' && hLine - 1 >= 0)
                {
                    matrix[hLine - 1][hColumn] = 'C';
                    matrix[vecPosLine[3]][vecPosColumn[3]] = ' ';
                    vecLine[0] = hLine;
                    vecColumn[0] = hColumn;
                    vecLine[1] = vecPosLine[0];
                    vecColumn[1] = vecPosColumn[0];
                    vecLine[2] = vecPosLine[1];
                    vecColumn[2] = vecPosColumn[1];
                    vecLine[3] = vecPosLine[2];
                    vecColumn[3] = vecPosColumn[2];
                    matrix[vecLine[0]][vecColumn[0]] = '*';
                    matrix[vecLine[1]][vecColumn[1]] = '*';
                    matrix[vecLine[2]][vecColumn[2]] = '*';
                    matrix[vecLine[3]][vecColumn[3]] = '.';
                    vecPosLine[0] = vecLine[0];
                    vecPosColumn[0] = vecColumn[0];
                    vecPosLine[1] = vecLine[1];
                    vecPosColumn[1] = vecColumn[1];
                    vecPosLine[2] = vecLine[2];
                    vecPosColumn[2] = vecColumn[2];
                    vecPosLine[3] = vecLine[3];
                    vecPosColumn[3] = vecColumn[3];
                    hLine--;
                    aux[hLine][hColumn] = 'V';
                }
                else
                {
                    printf("The snake got stuck. Game Over!\n\n");
                    for(int i = 0; i < boardSIZE; i++)
                    {
                        for(int j = 0; j < boardSIZE; j++)
                        {
                            if(aux[i][j] == 'V')
                            {
                                visitedSquares++;
                            }
                        }
                    }
                    printf("Number of unique squares the snake has visited: %i\n", visitedSquares);
                    printf("Number of unique squares the snake hasn't visited: %i\n\n", 100 - visitedSquares);
                    return;
                }
            break;
            case 3:
                if(matrix[hLine + 1][hColumn] == ' ' && hLine + 1 < boardSIZE)
                {
                    matrix[hLine + 1][hColumn] = 'C';
                    matrix[vecPosLine[3]][vecPosColumn[3]] = ' ';
                    vecLine[0] = hLine;
                    vecColumn[0] = hColumn;
                    vecLine[1] = vecPosLine[0];
                    vecColumn[1] = vecPosColumn[0];
                    vecLine[2] = vecPosLine[1];
                    vecColumn[2] = vecPosColumn[1];
                    vecLine[3] = vecPosLine[2];
                    vecColumn[3] = vecPosColumn[2];
                    matrix[vecLine[0]][vecColumn[0]] = '*';
                    matrix[vecLine[1]][vecColumn[1]] = '*';
                    matrix[vecLine[2]][vecColumn[2]] = '*';
                    matrix[vecLine[3]][vecColumn[3]] = '.';
                    vecPosLine[0] = vecLine[0];
                    vecPosColumn[0] = vecColumn[0];
                    vecPosLine[1] = vecLine[1];
                    vecPosColumn[1] = vecColumn[1];
                    vecPosLine[2] = vecLine[2];
                    vecPosColumn[2] = vecColumn[2];
                    vecPosLine[3] = vecLine[3];
                    vecPosColumn[3] = vecColumn[3];
                    hLine++;
                    aux[hLine][hColumn] = 'V';
                }
                else if(matrix[hLine][hColumn - 1] == ' ' && hColumn - 1 >= 0)
                {
                    matrix[hLine][hColumn - 1] = 'C';
                    matrix[vecPosLine[3]][vecPosColumn[3]] = ' ';
                    vecLine[0] = hLine;
                    vecColumn[0] = hColumn;
                    vecLine[1] = vecPosLine[0];
                    vecColumn[1] = vecPosColumn[0];
                    vecLine[2] = vecPosLine[1];
                    vecColumn[2] = vecPosColumn[1];
                    vecLine[3] = vecPosLine[2];
                    vecColumn[3] = vecPosColumn[2];
                    matrix[vecLine[0]][vecColumn[0]] = '*';
                    matrix[vecLine[1]][vecColumn[1]] = '*';
                    matrix[vecLine[2]][vecColumn[2]] = '*';
                    matrix[vecLine[3]][vecColumn[3]] = '.';
                    vecPosLine[0] = vecLine[0];
                    vecPosColumn[0] = vecColumn[0];
                    vecPosLine[1] = vecLine[1];
                    vecPosColumn[1] = vecColumn[1];
                    vecPosLine[2] = vecLine[2];
                    vecPosColumn[2] = vecColumn[2];
                    vecPosLine[3] = vecLine[3];
                    vecPosColumn[3] = vecColumn[3];
                    hColumn--;
                    aux[hLine][hColumn] = 'V';
                }
                else if(matrix[hLine - 1][hColumn] == ' ' && hLine - 1 >= 0)
                {
                    matrix[hLine - 1][hColumn] = 'C';
                    matrix[vecPosLine[3]][vecPosColumn[3]] = ' ';
                    vecLine[0] = hLine;
                    vecColumn[0] = hColumn;
                    vecLine[1] = vecPosLine[0];
                    vecColumn[1] = vecPosColumn[0];
                    vecLine[2] = vecPosLine[1];
                    vecColumn[2] = vecPosColumn[1];
                    vecLine[3] = vecPosLine[2];
                    vecColumn[3] = vecPosColumn[2];
                    matrix[vecLine[0]][vecColumn[0]] = '*';
                    matrix[vecLine[1]][vecColumn[1]] = '*';
                    matrix[vecLine[2]][vecColumn[2]] = '*';
                    matrix[vecLine[3]][vecColumn[3]] = '.';
                    vecPosLine[0] = vecLine[0];
                    vecPosColumn[0] = vecColumn[0];
                    vecPosLine[1] = vecLine[1];
                    vecPosColumn[1] = vecColumn[1];
                    vecPosLine[2] = vecLine[2];
                    vecPosColumn[2] = vecColumn[2];
                    vecPosLine[3] = vecLine[3];
                    vecPosColumn[3] = vecColumn[3];
                    hLine--;
                    aux[hLine][hColumn] = 'V';
                }
                else if(matrix[hLine][hColumn + 1] == ' ' && hColumn + 1 < boardSIZE)
                {
                    matrix[hLine][hColumn + 1] = 'C';
                    matrix[vecPosLine[3]][vecPosColumn[3]] = ' ';
                    vecLine[0] = hLine;
                    vecColumn[0] = hColumn;
                    vecLine[1] = vecPosLine[0];
                    vecColumn[1] = vecPosColumn[0];
                    vecLine[2] = vecPosLine[1];
                    vecColumn[2] = vecPosColumn[1];
                    vecLine[3] = vecPosLine[2];
                    vecColumn[3] = vecPosColumn[2];
                    matrix[vecLine[0]][vecColumn[0]] = '*';
                    matrix[vecLine[1]][vecColumn[1]] = '*';
                    matrix[vecLine[2]][vecColumn[2]] = '*';
                    matrix[vecLine[3]][vecColumn[3]] = '.';
                    vecPosLine[0] = vecLine[0];
                    vecPosColumn[0] = vecColumn[0];
                    vecPosLine[1] = vecLine[1];
                    vecPosColumn[1] = vecColumn[1];
                    vecPosLine[2] = vecLine[2];
                    vecPosColumn[2] = vecColumn[2];
                    vecPosLine[3] = vecLine[3];
                    vecPosColumn[3] = vecColumn[3];
                    hColumn++;
                    aux[hLine][hColumn] = 'V';
                }
                else
                {
                    printf("The snake got stuck. Game Over!\n\n");
                    for(int i = 0; i < boardSIZE; i++)
                    {
                        for(int j = 0; j < boardSIZE; j++)
                        {
                            if(aux[i][j] == 'V')
                            {
                                visitedSquares++;
                            }
                        }
                    }
                    printf("Number of unique squares the snake has visited: %i\n", visitedSquares);
                    printf("Number of unique squares the snake hasn't visited: %i\n\n", 100 - visitedSquares);
                    return;
                }
            break;
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
    system("cls");
    printf("The snake has done all the movements successfully!\n\n");
    for(int i = 0; i < boardSIZE; i++)
    {
        for(int j = 0; j < boardSIZE; j++)
        {
            if(aux[i][j] == 'V')
            {
                visitedSquares++;
            }
        }
    }
    printf("Number of unique squares the snake has visited: %i\n", visitedSquares);
    printf("Number of unique squares the snake hasn't visited: %i\n\n", 100 - visitedSquares);
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
            printf("\n\nGoodbye! :D\n\n");
            break;
        }
    }
}
