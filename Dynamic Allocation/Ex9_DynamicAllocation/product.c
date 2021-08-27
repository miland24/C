#include <stdio.h>
#include <stdlib.h>
#include "product.h"

product* r_products(int N)
{
    product* p;
    int i;

    p = (product*) malloc(N * sizeof(product));

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

    for(i = 0; i < N; i++)
    {
        if(mValuable < p[i].price)
        {
            mValuable = p[i].price;
            index = i;
        }
    }
    return index;
}

int hQty(int N, product* p)
{
    int i, index = 0, lQty = 0;

    for(i = 0; i < N; i++)
    {
        if(lQty < p[i].qty)
        {
            lQty = p[i].qty;
            index = i;
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
