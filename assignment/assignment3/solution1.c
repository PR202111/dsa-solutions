#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

struct list
{
    int value;
    int weight;
    struct list *next;
};
struct list *create(int val)
{
    struct list *ptr;
    ptr = (struct list *)malloc(sizeof(struct list));
    ptr->value = val;
    ptr->weight = 0;
    ptr->next = NULL;

    return ptr;
}
void insert(struct list *adj[], int vertex, int node)
{
    struct list *ptr = create(node);
    if (adj[vertex] == NULL)
    {
        adj[vertex] = ptr;
    }
    else
    {
        struct list *temp = adj[vertex];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = ptr;
    }
}
struct PQnode{
    int value;
    int priority;
};
struct PriorityQueue
{
    struct PQnode* data;
    int capacity;
    int size;
};
void swap(struct PQnode* a,struct PQnode* b){
    struct PQnode temp = *a;
    *a = *b;
    *b = temp;
}
void heapify_up(struct PriorityQueue* pq,int idx){
    while (idx > 0)
    {
        int parent = (idx-1)/2;
        if (pq->data[parent].priority > pq->data[idx].priority)
        {
            swap(&pq->data[parent],&pq->data[idx]);
            idx = parent;
        }
        else break;
    }
    
}
void heapify_down(struct PriorityQueue* pq,int idx){
    while (1)
    {
        int left = 2*idx + 1;
        int right = 2*idx + 2;
        int smallest = idx;
        if (left < pq->size && pq->data[smallest].priority > pq->data[left].priority)
        {
            smallest = left;
        }
        if (right < pq->size && pq->data[smallest].priority > pq->data[right].priority)
        {
            smallest = right;
        }

        if (smallest != idx)
        {
            swap(&pq->data[smallest],&pq->data[idx]);
            idx = smallest;
        }
        else{
            break;
        }  
    }
}
struct PriorityQueue* create_PQ(int capacity){
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->data = (struct PQnode*)malloc(sizeof(struct PQnode)* (2 * capacity));
    pq->capacity = capacity;
    pq->size = 0;

    return pq;
}

struct PQnode top(struct PriorityQueue* pq){
    return pq->data[0]; 
}
void pop(struct PriorityQueue* pq){
    if(pq->size == 0) return;
    pq->data[0] = pq->data[pq->size - 1];
    (pq->size)--;
    heapify_down(pq,0);
}
void push(struct PriorityQueue* pq,int vertex,int distance){
    pq->data[pq->size].priority = distance;
    pq->data[pq->size].value = vertex;
    heapify_up(pq,pq->size);
    (pq->size)++;

}
int isEmpty(struct PriorityQueue* pq){
    if (pq->size == 0)
    {
        return 1;
    }
    return 0;
    
}
void dijkastras(int n,struct list* a[],int src){
    struct PriorityQueue* pq = create_PQ(n);
    int dist[n];
    int parent[n];
    for(int i=0;i<n;i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[src] = 0;
    push(pq,src,0);

    while (!isEmpty(pq))
    {
        struct PQnode node = top(pq);
        pop(pq);
        int u = node.value;
        int d = node.priority;
        if (d > dist[u])
        {
            continue;
        }
        struct list* adj = a[u];
        while (adj != NULL)
        {
            int v = adj->value;
            int weight = adj->weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                push(pq,v,dist[v]);
                parent[v] = u;
            }
            adj = adj->next;
            
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
        {
            printf("-1 ");
        }
        else{
            printf("%d ",dist[i]);
        }
        
    }
    printf("\n");
}

int main()
{
    char temp[100];
    int n;
    scanf("%d", &n);
    struct list *adj[n];
    for (int i = 0; i < n; i++)
    {
        adj[i] = NULL;
    }
    getchar();

    for (int i = 0; i < n; i++)
    {
        scanf("%[^\n]", temp);
        int j = 0;
        int vertex = -1;
        while (isdigit(temp[j]))
        {
            if (vertex == -1)
                vertex = 0;
            vertex = vertex * 10 + (temp[j] - '0');
            j++;
        }

        while (temp[j] != '\0')
        {
            if (isdigit(temp[j]))
            {
                int val = 0;
                while (isdigit(temp[j]))
                {
                    val = val * 10 + (temp[j] - '0');
                    j++;
                }
                insert(adj, vertex - 1, val - 1);
            }
            else
            {
                j++;
            }
        }
        getchar();
    }
    
    for (int i = 0; i < n; i++)
    {
        scanf("%[^\n]", temp);
        int j = 0;
        int vertex = -1;
        while (isdigit(temp[j]))
        {
            if (vertex == -1)
                vertex = 0;
            vertex = vertex * 10 + (temp[j] - '0');
            j++;
        }
        struct list *curr_node = adj[vertex - 1];
        while (temp[j] != '\0')
        {
            if (isdigit(temp[j]))
            {
                int val = 0;
                while (isdigit(temp[j]))
                {
                    val = val * 10 + (temp[j] - '0');
                    j++;
                }

                if (curr_node != NULL)
                {
                    curr_node->weight = val;
                    curr_node = curr_node->next;
                }
            }
            else
            {
                j++;
            }
        }
        getchar();
    }
    int src;
    scanf("%d",&src);
    dijkastras(n,adj,src-1);
    
}