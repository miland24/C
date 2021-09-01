typedef struct _item
{
    int cont; //counter
    char* term; //word
} Item;

typedef struct _map
{
    int total; // number of items in the map
    int blocks; // number of blocks of items allocated.
    Item **lst; // vector of pointers for items.
} Map;

void start_map (Map* mp);
void insert_term (Map* mp, char* s);
int increment (Map* mp, char* s);
int write_counter (Map* mp, char* s, int c);
int read_counter (Map* mp, char* s);
void remove_term (Map* mp, char* s);
void free_map (Map* mp);
int size_map (Map *mp);
void read_term (Map* mp, int i, char* t, int* c);
