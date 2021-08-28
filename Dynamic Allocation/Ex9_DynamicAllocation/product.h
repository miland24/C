typedef struct st_product product; //Product information struct.

product* r_products(int N); //The number of products is passed to this function, which then creates the list of products.
int hValue(int N, product* p); //Checks the products for the most valuable item.
int hQty(int N, product* p); //Checks the products for the item in the largest quantity.
void print_products(int N, int mValueIndex, int lQtyIndex, product* p); //This function prints all the products, the most valuable product, and also the product in the largest quantity.
