#include <stdio.h>
#include <stdlib.h>
struct hashtable
{
    int *table;
    int count;
    int size;
};
struct hashtable *create_ht(int size)
{
    struct hashtable *ht = (struct hashtable *)malloc(sizeof(struct hashtable));
    ht->table = (int *)malloc(sizeof(int) * size);
    ht->size = size;
    ht->count = 0;
    for (int i = 0; i < size; i++)
    {
        ht->table[i] = -1;
    }

    return ht;
}
int hashfunc(int key, int size)
{
    return key % size;
}

int quadprobing(struct hashtable *ht, int key) {
    int i = 0;
    int index;
    int max_probe = ht->size; 
    do {
        if (i >= max_probe) {
            printf("Error: Table is full or cannot find empty slot!\n");
            exit(1);
        }
        index = (hashfunc(key, ht->size) + i * i) % ht->size;
        i++;
    } while (ht->table[index] != -1);
    return index;
}



void display(struct hashtable *ht)
{
    for (int i = 0; i < ht->size; i++)
    {
        printf("%d ", ht->table[i]);
    }
    printf("\n");
}
void insert(struct hashtable *ht, int key)
{
    
    int idx = quadprobing(ht, key);
    ht->table[idx] = key;
    (ht->count)++;
}
void rehash(struct hashtable *ht)
{
    int *old_table = ht->table;
    int old_size = ht->size;
    ht->size = old_size * 2;
    ht->table = (int *)malloc(sizeof(int) * old_size * 2);
    for (int i = 0; i < ht->size; i++)
    {
        ht->table[i] = -1;
    }
    ht->count = 0;
    // here we need to pass the old stored inputs in that order
    for (int i = 0; i < old_size; i++)
    {
        if (old_table[i] != -1)
        {
            insert(ht,old_table[i]);
        }
    }
    free(old_table);
}
int main()
{
    int n;
    scanf("%d", &n);
    struct hashtable *ht;
    ht = create_ht(n);
    char mode;
    getchar();
    while (1)
    {
        scanf("%c", &mode);
        if (mode == 'i')
        {
            int num;
            scanf("%d", &num);
            float total_elements = ht->count;
            if ((ht->count + 1) * 100 / ht->size > 75) {
                rehash(ht);
            }                   
            insert(ht, num);
        }
        else if (mode == 'd')
        {
            display(ht);
        }
        else if (mode == 'e')
        {
            break;
        }
        getchar();
    }
    free(ht->table);
    free(ht);

    return 0;
}