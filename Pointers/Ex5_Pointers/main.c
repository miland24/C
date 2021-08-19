#include <stdio.h>
#include <stdlib.h>

int M[3][4];

int main()
{
    int i, j, line = -1, content;

    printf("Choose the line you wish to fill: ");
    scanf("%i", &line);

    while(line < 0 || line > 2)
    {
        printf("\nPlease, choose a line between 0 and 2: ");
        scanf("%i", &line);
    }

    printf("\nType the content you wish to fill the line with: ");
    scanf("%i", &content);

    for(i = 0; i < 4; i++)
    {
        M[line][i] = content;
    }

    for(i = 0; i < 3; i++)
    {
        printf("\n");
        for(j = 0; j < 4; j++)
        {
            printf("[%i]\t", M[i][j]);
        }
    }

    printf("\n");
    return 0;
}
