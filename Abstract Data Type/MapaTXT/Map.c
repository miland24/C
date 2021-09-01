#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Map.h"
#define BLOCK 10

// Starts a new map
void start_map (Map* mp)
{
    mp -> lst = (Item**) malloc(BLOCK * sizeof(Item*)); //Allocates a vector of pointers with BLOCK size.

    if(mp -> lst == NULL) //Verifies if there's enough memory to allocate the vector of pointers.
    {
        printf("Insufficient memory.");
        return;
    }

    mp -> blocks = 1; //Initializes mp -> block
    mp -> total = 0; //Initializes mp -> total

    return;
}

// Inserts an item with term s and counter = 1
void insert_term (Map* mp, char* s)
{
    int x = 0;

    x = strlen(s); //Stores the size of the word, to allocate a memory fit for that word size
    x++; //Adds the '\0', showing the end of the string

    if(increment(mp, s) == 0) //Verifies if the term already exists inside the map, if it exists, it only adds 1 to the counter of the word.
        return;

    if(mp -> total / BLOCK == mp -> blocks) //Verifies if the number of items in the map is exceeding the number of blocks of memory allocated for the items.
    {
        mp -> lst = (Item**) realloc(mp -> lst, (BLOCK * mp -> blocks + BLOCK) * sizeof(Item*)); //Reallocates the memory to store more items.
        mp -> blocks++;
    }

    mp -> lst[mp -> total] = (Item*) malloc(sizeof(Item)); //Allocates memory for 1 item

    mp -> lst[mp -> total] -> term = (char*) malloc(x * sizeof(char)); //Allocates the memory fit for the term 's'

    strcpy(mp -> lst[mp -> total] -> term, s);

    mp -> lst[mp -> total] -> cont = 1;

    mp -> total++;
    return;
}

// Increments counter of the term s, returns 1 if the term was not found.
int increment (Map* mp, char* s)
{
    int i;

    for(i = 0; i < mp -> total; i++)
    {
        if(strcmp(s, mp -> lst[i] -> term) == 0) //Checks if the term exists in the map
        {
            mp -> lst[i] -> cont++; //Increments the counter of the term
            return 0;
        }
    }

    return 1;
}

// Write's 'c' in the counter of the term s, returns 1 if the term was not found.
int write_counter (Map* mp, char* s, int c)
{
    int i;

    for(i = 0; i < mp -> total; i++)
    {
        if(strcmp(s, mp -> lst[i] -> term) == 0) //Checks if the term 's' exists in the map
        {
            mp -> lst[i] -> cont = c; //Increment the counter of the word with the number 'c'
            return 0;
        }
    }

    return 1;
}

// returns counter of the term s
int read_counter (Map* mp, char* s)
{
    int i;

    for(i = 0; i < mp -> total; i++)
    {
        if(strcmp(s, mp -> lst[i] -> term) == 0) //Checks if the term exists in the map
        {
            return mp -> lst[i] -> cont;
        }
    }
    printf("This word doesn't exist in the map!");
    return 0;
}

// removes the item with the term s
void remove_term (Map* mp, char* s)
{
    int i, j;
    for(i = 0; i < mp -> total; i++)
    {
        if(strcmp(s, mp -> lst[i] -> term) == 0) //Checks if the term exists in the map
        {
            free(mp -> lst[i]); //Frees the pointer to the term the user has chosen (removes the term from the map)

            for(j = i; j < (mp -> total) - 1; j++) //Moves the terms in the map, so the map don't have a hole in it
            {
                mp -> lst[j] -> term = mp -> lst[j+1] -> term;

                mp -> lst[j] -> cont = mp -> lst[j+1] -> cont;
            }

            mp -> total--;

            free(mp -> lst[j]); //Frees the last position of the map, where the last term were.

            if(mp -> total == BLOCK * (mp->blocks -1)) //Checks if the items size is below the block size, and reallocates the memory so we don't waste memory.
            {
                mp -> blocks--;
                mp -> lst = (Item**) realloc(mp -> lst, BLOCK * mp -> blocks * sizeof(Item*));
            }
            break;
        }
    }
    return;
}

// frees the space occupied by the map
void free_map (Map* mp)
{
    int i;

    for(i = 0; i < mp -> total; i++) //frees every pointer in the vector of pointers for structs of the item type.
    {
        free(mp -> lst[i]);
    }

    if( mp -> blocks > 1) //reallocates the memory to the size of 1 block only.
    {
        mp -> lst = (Item**) realloc(mp -> lst, BLOCK * sizeof(Item*));
    }

    mp -> blocks = 1;
    mp -> total = 0;

    return;
}

// return the number of items in the map
int size_map (Map *mp)
{
    return mp -> total;
}

// returns in 't' the term in the index 'i' and in 'c' his counter.
void read_term (Map* mp, int i, char* t, int* c)
{
    strcpy(t, mp -> lst[i] -> term);
    *c = mp -> lst[i] -> cont;

    return;
}
