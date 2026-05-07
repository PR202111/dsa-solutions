#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct heap
{
    int *data;
    int capacity;
    int size;
};
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
struct heap *heap_init(int capacity)
{
    struct heap *hp = (struct heap *)malloc(sizeof(struct heap));
    hp->data = (int *)malloc(sizeof(int) * capacity);
    hp->capacity = capacity;
    hp->size = 0;

    return hp;
}

void heapify_up(struct heap *hp, int idx)
{
    while (idx > 0)
    {
        int parent = (idx - 1) / 2;

        if (hp->data[parent] < hp->data[idx])
        {
            swap(&hp->data[parent], &hp->data[idx]);
            idx = parent;
        }
        else
            break;
    }
}

void heapify_down(struct heap *hp, int idx)
{
    while (1)
    {
        int largest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < hp->size && hp->data[largest] < hp->data[left])
        {
            largest = left;
        }
        if (right < hp->size && hp->data[largest] < hp->data[right])
        {
            largest = right;
        }

        if (largest != idx)
        {
            swap(&hp->data[idx], &hp->data[largest]);
            idx = largest;
        }
        else
            break;
    }
}

void insert(struct heap *hp, int key)
{
    hp->data[hp->size] = key;
    heapify_up(hp, hp->size);
    (hp->size)++;
} 

int findmax(struct heap *hp)
{
    if (hp->size > 0)
        return hp->data[0];

    return -1;
}

void extractmax(struct heap *hp)
{
    if (hp->size <= 0)
        return;

    hp->data[0] = hp->data[hp->size - 1];
    (hp->size)--;
    heapify_down(hp, 0);
}

void kth_largest(struct heap *hp, int k)
{
    if (hp->size < k)
    {
        printf("-1\n");
        return;
    }

    int temp[k];
    for (int i = 0; i < k; i++)
    {
        temp[i] = findmax(hp);
        extractmax(hp);
    }
    printf("%d\n", temp[k - 1]);
    for (int i = 0; i < k; i++)
    {
        insert(hp, temp[i]);
    }
}
void print_lvl_order(struct heap *hp)
{
    int front = 0, rear = 0;
    int queue[hp->capacity];
    queue[rear++] = 0;

    while (front < rear)
    {
        int node = queue[front++];
        printf("%d ", hp->data[node]);

        int left = 2 * node + 1;
        int right = 2 * node + 2;

        if (left < hp->size) queue[rear++] = left;
        if (right < hp->size) queue[rear++] = right;
    }
    printf("\n");
}
void delete_key(struct heap *hp, int key)
{
    if (hp->size == 1 && findmax(hp) == key)
    {
        printf("0\n");
        extractmax(hp);
        return;
    }
    int idx = -1;
    for (int i = 0; i < hp->size; i++)
    {
        if (hp->data[i] == key)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        printf("-1\n");
        return;
    }
    hp->data[idx] = INT_MAX;
    heapify_up(hp, idx);
    extractmax(hp);
    print_lvl_order(hp);
}


void replace(struct heap *hp, int old_key, int new_key)
{
    int idx = -1;
    for (int i = 0; i < hp->size; i++)
    {
        if (hp->data[i] == old_key)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        printf("%d\n", abs(old_key - new_key));
        return;
    }
    hp->data[idx] = new_key;
    if (old_key < new_key)
        heapify_up(hp, idx);
    else if (old_key > new_key)
        heapify_down(hp, idx);

    print_lvl_order(hp);
}
int main()
{
    struct heap* hp = heap_init(100);
    char mode;
    int temp1,temp2;
    while (1)
    {
        scanf(" %c",&mode);
        if (mode == 'a')
        {
            scanf("%d",&temp1);
            insert(hp,temp1);
        }
        else if (mode == 'b')
        {
            printf("%d\n",findmax(hp));
        }
        else if (mode == 'c')
        {
            printf("%d\n",findmax(hp));
            extractmax(hp);
            if(hp->size == 0) printf("-1\n");
            else {
                print_lvl_order(hp);
            }
        }
        else if (mode == 'd')
        {
            scanf("%d",&temp1);
            kth_largest(hp,temp1);
        }
        else if (mode == 'e')
        {
            scanf("%d",&temp1);
            delete_key(hp,temp1);
        }
        else if (mode == 'f')
        {
            scanf("%d %d",&temp1,&temp2);
            replace(hp,temp1,temp2);
        }
        else if (mode == 'g')
        {
            break;
        }   
    }
    return 0;
}