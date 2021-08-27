#include <stdio.h>
#include <stdlib.h>
#include "product.h"

int main()
{
    product *pt;
    int rNumber, mValIndex, lQtyIndex;

    printf("Type the number of products you wish to register :");
    scanf("%i", &rNumber);

    pt = r_products(rNumber);
    mValIndex = hValue(rNumber, pt);
    lQtyIndex = hQty(rNumber, pt);
    print_products(rNumber, mValIndex, lQtyIndex, pt);

    return 0;
}
