typedef struct st_product
{
    int code, qty;
    char name[50];
    float price;
} product;

product* r_products(int N); //The number of products is passed to this function, then she creates the vector of products.
int hValue(int N, product* p); //Checks the products for the most valuable item.
int hQty(int N, product* p); //Checks the products for the item in the largest quantity.
void print_products(int N, int mValueIndex, int lQtyIndex, product* p); //This function prints all the products.
