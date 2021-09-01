#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include "Map.h"

int main()
{
    Map* mp;
    mp = (Map*) malloc(sizeof(Map));
    start_map(mp);
    setlocale(LC_ALL,"");
    // Test and control variables, used in the execution of the code.
    int opt, teste=0, totalWords = 0, qtyMin=0, qtyMax=0, minCarac=0, qty=0, i=0, j=0, aux=0, cont, control=0;
    FILE *arq; // Initiates the variable "arq" that will receive the text file.

    while(teste==0) // Loop created for the program so he always returns to the main menu.
    {
        system("cls");
        // "dir" will receive the path to the text file, "word" will store each word from the file.
        // searchWord is a support string used in one of the routines of the code.
        char dir[500], word[50], searchWord[50];
        printf("====Words ranking=====\n\n");
        printf("-------Menu-------\n");
        printf("1. Read file txt\n");
        printf("2. Show complete ranking\n");
        printf("3. Show ranking interval\n");
        printf("4. Word search\n");
        printf("5. Options\n");
        printf("6. Exit\n\n");
        printf("Type an option: ");
        opt = 0;

        while(opt<1||opt>6)
        {
            scanf("%i", &opt);
            if(opt<1||opt>6)
            {
                printf("\nInvalid option, type again: ");
            }
        }

        switch(opt)
        {
        case 1: // Reads the file and stores each word inside the structure "Item".
            system("cls");
            totalWords = 0;
            free_map(mp);
            printf("Obs.: To prevent accentuation bugs, the .txt file must be in the ANSI file extension.\n");
            printf("Type the path of the file [ex.: C:\\Users\\John\\Documents\\text.txt]: ");
            fflush(stdin);
            gets(dir);
            arq = fopen(dir,"r");
            if (arq == NULL)
            {
                printf("ERROR! The file wasn't opened!\n");
                system("pause");
                break;
            }
            else
            {
                printf("The file was opened successfully!\n\n");
            }
            control = 1; // Prevents the user from accessing the logic of other options in the menu, without reading the .txt file.
            while(fscanf(arq,"%[^\n ] ",word)!=EOF)
            {
                for(i=0; i<strlen(word); i++)
                {
                    // The "if" below, excludes some special characters in the "word" variable.
                    if(word[i]=='.'||word[i]==','||word[i]=='?'||word[i]==':'||word[i]==';'||word[i]=='!'||word[i]=='('||word[i]==')')
                    {
                        word[i] = 0;
                    }
                }
                i = 0;
                while(word[i] != '\0') // Makes each character in the "word" lowercase.
                {
                    word[i] = tolower(word[i]);
                    i++;
                }
                insert_term(mp, word); // After each operation above, inserts the "word" in the structure mp and increments the "word" counter.
                for(i=0; i<strlen(word); i++) // Clears the content in the variable "word", so it can store the next word.
                {
                    word[i] = 0;
                }
                totalWords++;
            }
            printf("\n\nTotal words: %i\n", totalWords);
            printf("\nQTY     WORD\n");
            for(i=0; i<mp->total; i++)
            {
                printf("%i       %s\n", mp -> lst[i] -> cont, mp -> lst[i] -> term);
            }
            system("pause");
            break;
        case 2:
            system("cls");
            if(control==0)  // Prevents the user from accessing the logic in this option in the menu, without reading the .txt file.
            {
                printf("You haven't read a text file yet!\n");
                system("pause");
                break;
            }
            printf("Number of words: %i\n\n", totalWords);
            printf("QTY    WORD\n");
            for(i=0; i<(mp->total); i++) // Stores in "aux" the highest value "cont" found in "mp -> lst".
            {
                if(mp->lst[i]->cont > aux)
                {
                    aux = mp->lst[i]->cont;
                }
            }
            for(j=aux; j>0; j--) // Uses "aux" as a support to display, in decreasing order, the number of times the "word" repeats itself.
            {
                for(i=0; i<(mp->total); i++)
                {
                    if(mp->lst[i]->cont == j)
                    {
                        printf("%i      %s\n", mp->lst[i]->cont, mp->lst[i]->term);
                    }
                }
            }
            aux = 0;
            system("pause");
            break;
        case 3:
            system("cls");
            if(control==0)  // Prevents the user from acessing this option logic, without reading a .txt file.
            {
                printf("You haven't read text file yet!\n");
                system("pause");
                break;
            }
            printf("=====Words ranking with a specific size=====\n\n");
            printf("Type the minimum quantity of characters you want in the word");
            while(qtyMin<=0)
            {
                scanf("%i", &qtyMin);
                if(qtyMin<=0)
                {
                    printf("\nInvalid value, type again: ");
                }
            }
            printf("Type the maximum quantity of characters you want in the word:");
            while(qtyMax<=qtyMin)
            {
                scanf("%i", &qtyMax);
                if(qtyMax<=qtyMin)
                {
                    printf("\nERROR, the value must be higher than the one typed before. Type again: ");
                }
            }
            printf("\n\nQTY    WORD\n");
            for(i=0; i<(mp->total); i++) // Stores in "aux" the highest value "cont" found in "mp -> lst".
            {
                if(mp->lst[i]->cont > aux)
                {
                    aux = mp->lst[i]->cont;
                }
            }
            for(j=aux; j>0; j--) // Uses "aux" as a support to display, in decreasing order, the number of times the "word" repeats itself.
            {
                for(i=0; i<(mp->total); i++)
                {
                    if(mp->lst[i]->cont == j)
                    {
                        if(strlen(mp->lst[i]->term)>=qtyMin && strlen(mp->lst[i]->term)<=qtyMax)
                        {
                            printf("%i      %s\n", mp->lst[i]->cont, mp->lst[i]->term);
                            qty += mp->lst[i]->cont;
                        }
                    }
                }
            }
            printf("\nNumber of words: %i\n", qty);
            qty = 0;
            qtyMin = 0;
            qtyMax = 0;
            aux = 0;
            system("pause");
            break;
        case 4:
            system("cls");
            if(control==0)  // Prevents the user from acessing this option logic, without reading a .txt file.
            {
                printf("You haven't read text file yet!\n");
                system("pause");
                break;
            }
            printf("Type the word you want to search for: ");
            fflush(stdin);
            gets(searchWord);
            cont = read_counter(mp, searchWord); // TAD function that returns the value "cont" of the chosen word, or displays to the user that the word he typed doesn't exist in the file.
            printf("\n");
            if(cont!=0)
            {
                printf("The word has been found! Number of words = %i\n", cont);
            }
            system("pause");
            break;
        case 5:
            system("cls");
            if(control==0)  // Prevents the user from acessing this option logic, without reading a .txt file.
            {
                printf("You haven't read text file yet!\n");
                system("pause");
                break;
            }
            cont = 0;
            printf("Type the minimum quantity of characters: ");
            while(minCarac<=0)
            {
                scanf("%i", &minCarac);
                if(minCarac<=0)
                {
                    printf("\nInvalid value, type again: ");
                }
            }
            printf("\nLIST OF WORDS WITH %i OR MORE CHARACTERS:\n\n", minCarac);
            for(i=0; i<mp->total; i++) // Loop that shows the user all the words with the minimum quantity of characters he specified, and the quantity of each word.
            {
                if(strlen(mp->lst[i]->term) >= minCarac)
                {
                    printf("%s\n", mp->lst[i]->term);
                    cont++;
                }
            }
            printf("\nTotal words with %i or more characters: %i\n", minCarac, cont);
            cont = 0;
            minCarac = 0;
            system("pause");
            break;
        case 6:
            exit(0);
        }
    }
    return 0;
}
