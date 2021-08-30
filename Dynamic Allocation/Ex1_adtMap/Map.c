#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Map.h"
#define BLOCK 10

// Starts a new map
void start_map (Map* mp)
{
    mp -> lst = (Item**) malloc(BLOCK * sizeof(Item*));

    if(mp -> lst == NULL)
    {
        printf("Insufficient memory.");
        return;
    }

    mp -> blocks = 1;
    mp -> total = 0;

    return;
}

// Inserts an item with term s and counter = 1
void insert_term (Map* mp, char* s)
{
    if(increment(mp, s) == 0)
        return;

    if(mp -> total / BLOCK == mp -> blocks)
    {
        mp -> lst = (Item**) realloc(mp -> lst, (BLOCK * mp -> blocks) + BLOCK * sizeof(Item*));
        mp -> blocks++;
    }
    mp -> lst[mp -> total] = (Item*) malloc(sizeof(Item));

    mp -> lst[mp -> total] -> term = s;
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
        if(strcmp(s, mp -> lst[i] -> term) == 0)
        {
            mp -> lst[i] -> cont++;
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
        if(strcmp(s, mp -> lst[i] -> term) == 0)
        {
            mp -> lst[i] -> cont = c;
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
        if(strcmp(s, mp -> lst[i] -> term) == 0)
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
        if(strcmp(s, mp -> lst[i] -> term) == 0)
        {
            mp -> lst[i] -> term = NULL;
            for(j = i; j < (mp -> total) - 1; j++)
            {
                mp -> lst[j] -> term = mp -> lst[j+1] -> term;
                mp -> lst[j] -> cont = mp -> lst[j+1] -> cont;
            }
            mp -> total--;
            mp -> lst[j] -> term = NULL;
            if(mp -> total == BLOCK * (mp->blocks -1))
            {
                mp -> blocks--;
                mp -> lst = (Item**) realloc(mp -> lst, BLOCK * mp -> blocks * sizeof(Item*));
            }
            break;
        }
    }
    return;
}

// free's the space occupied by the map
void free_map (Map* mp)
{
    int i;

    for(i = 0; i < mp -> total; i++)
    {
        free(mp -> lst[i]);
    }

    if( mp -> blocks > 1)
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
