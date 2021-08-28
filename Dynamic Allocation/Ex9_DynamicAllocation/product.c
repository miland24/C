#include <stdio.h>
#include <stdlib.h>
#include "product.h"

typedef struct st_product
{
    int code, qty;
    char name[50];
    float price;
} product;

product* r_products(int N)
{
    product* p;
    int i;

    //Allocates memory for the number of products the user defined.
    p = (product*) malloc(N * sizeof(product));

    //Gets all the information about all the products the user defined.
    for(i = 0; i < N; i++)
    {
        printf("\nType the name of the [%i]ish product: ", i + 1);
        fflush(stdin);
        scanf("%s", (p + i) -> name);
        printf("\nType the code of the [%i]ish product: ", i + 1);
        scanf("%i", &(p + i) -> code);
        printf("\nType the quantity of the [%i]ish product: ", i + 1);
        scanf("%i", &(p + i) -> qty);
        printf("\nType the price of the [%i]ish product: ", i + 1);
        scanf("%f", &(p + i) -> price);
    }

    return p;
}

int hValue(int N, product* p)
{
    int i, index = 0, mValuable = 0;

    //Checks the list of products for the most valuable product, then it stores and returns the index of the vector the product's in.
    for(i = 0; i < N; i++)
    {
        if(mValuable < p[i].price)
        {
            mValuable = p[i].price; //stores the highest price in this variable.
            index = i; //index of the vector the product's in.
        }
    }
    return index;
}

int hQty(int N, product* p)
{
    int i, index = 0, lQty = 0;

    //Checks the list of products for the product in largest quantity, then it stores and returns the index of the vector the product's in.
    for(i = 0; i < N; i++)
    {
        if(lQty < p[i].qty)
        {
            lQty = p[i].qty; //stores the largest quantity in this variable.
            index = i; //index of the vector the product's in.
        }
    }
    return index;
}

void print_products(int N, int mValueIndex, int lQtyIndex, product* p)
{
    int i;

    system("cls");

    printf("\nPRODUCTS:");
    for(i = 0; i < N; i++)
    {
        printf("\n\nName: %s", p[i].name);
        printf("\nCode: %i", p[i].code);
        printf("\nQuantity: %i", p[i].qty);
        printf("\nPrice: %.2f", p[i].price);
    }

    printf("\n\nMost valuable product: ");
    printf("\nName: %s", p[mValueIndex].name);
    printf("\nCode: %i", p[mValueIndex].code);
    printf("\nQuantity: %i", p[mValueIndex].qty);
    printf("\nPrice: %.2f", p[mValueIndex].price);

    printf("\n\nLargest quantity product: ");
    printf("\nName: %s", p[lQtyIndex].name);
    printf("\nCode: %i", p[lQtyIndex].code);
    printf("\nQuantity: %i", p[lQtyIndex].qty);
    printf("\nPrice: %.2f\n\n", p[lQtyIndex].price);
}
