#include <stdio.h>
#include <stdlib.h>
#include "Map.h"

int main()
{
    Map* mp;
    mp = (Map*) malloc(sizeof(Map));

    char word1[50] = "Banana";
    char word2[50] = "Avocado";
    char word3[50] = "Pineaple";
    char word4[50] = "Jambo";
    char termo[50];
    int tamMap, i, y;

    // Starts an empty map.
    start_map(mp);

    // Testing the function that inserts a term.
    insert_term(mp, word1);
    printf("%s\n", mp -> lst[0] -> term);

    // Testing the increment function, when the added word is already inside the struct.
    insert_term(mp, word1);
    printf("%i\n", mp -> lst[0] -> cont);

    // Testing the function that modifies the term counter.
    write_counter(mp, word1, 30);
    printf("%i\n", mp -> lst[0] -> cont);

    // Testing the function that returns the number of itens in the map.
    insert_term(mp, word2);
    insert_term(mp, word3);
    insert_term(mp, word4);
    tamMap = size_map(mp);
    printf("%i\n", tamMap);

    // Testing the function that removes an item from the map.
    remove_term(mp, word2);
    printf("%s\n", mp -> lst[0] -> term);
    printf("%s\n", mp -> lst[1] -> term);
    printf("%s\n", mp -> lst[2] -> term);

    // Testing the function that returns a index and a counter from the chosen term.
    i = 0;
    read_term(mp, i, termo, &y);
    printf("%s\n", termo);
    printf("%i\n", y);

    // Function that frees the space ocupied by the ADT Map.
    free_map(mp);
    printf("%i\n", mp -> total);
    printf("%i\n", mp -> blocks);

    system("pause");
    return 0;
}
