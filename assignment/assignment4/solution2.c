#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct list
{
    int value;
    int weight;
    struct list *next;
};
struct list *create_node(int digit)
{
    struct list *ptr = (struct list *)malloc(sizeof(struct list));
    ptr->value = digit;
    ptr->weight = 0;
    ptr->next = NULL;

    return ptr;
}
void insert(struct list *l[], int vertex, int digit)
{
    struct list *node = create_node(digit);
    if (l[vertex] == NULL)
    {
        l[vertex] = node;
        return;
    }
    struct list *temp = l[vertex];
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
}
struct edge
{
    int u;
    int v;
    int weight;
};
void merge(struct edge E[], int left, int mid, int right)
{
    int l = mid - left + 1;
    int r = right - mid;
    struct edge L[l], R[r];
    for (int i = 0; i < l; i++)
    {
        L[i] = E[left + i];
    }
    for (int i = 0; i < r; i++)
    {
        R[i] = E[mid + i + 1];
    }

    
    int i=0,j=0,k=left;
    while (i<l && j <r)
    {
        if (L[i].weight <= R[j].weight)
        {
            E[k++] = L[i++];
        }
        else{
            E[k++] = R[j++];
        }
        
    }
    while(i < l) E[k++] = L[i++];
    while(j<r) E[k++] = R[j++];
    
}
void mergeSort(struct edge E[], int left, int right)
{
    if (right > left)
    {
        int mid = left + (right - left) / 2;
        mergeSort(E, left, mid);
        mergeSort(E, mid + 1, right);
        merge(E, left, mid, right);
    }
}
void makeSet(int n,int parent[],int rank[]){
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    
}

int findUP(int u,int parent[]){
    if (parent[u] == u)
    {
        return u;
    }
    else{
        parent[u] = findUP(parent[u],parent);
    }
    return parent[u];
    
}
void UnionByRank(int u,int v,int parent[],int rank[]){
    int ancU = findUP(u,parent);
    int ancV = findUP(v,parent);
    if(ancU == ancV) return;

    if (rank[ancU] < rank[ancV])
    {
        parent[ancU] = ancV;
    }
    else if (rank[ancV] < rank[ancU])
    {
        parent[ancV] = ancU;
    }
    else{
        parent[ancV] = ancU;
        rank[ancU]++;
    }
}
void kruskals(int n,struct list* l[]){
    struct edge *E = (struct edge*)malloc(n * n * sizeof(struct edge));
    int EdgeCount = 0;
    for (int i = 0; i < n; i++)
    {
        struct list* temp = l[i];
        while (temp != NULL)
        {
            if (temp->value > i)
            {
                E[EdgeCount].u = i;
                E[EdgeCount].v = temp->value;
                E[EdgeCount].weight = temp->weight;
                EdgeCount++;
            }
            temp = temp->next;
            
        }
        
    }
    mergeSort(E,0,EdgeCount-1);
    int parent[n],rank[n];
    makeSet(n,parent,rank);
    int mstWeight =0;
    for (int i = 0; i < EdgeCount; i++)
    {
        int u = E[i].u;
        int v = E[i].v;
        int w = E[i].weight;

        if (findUP(u,parent) != findUP(v,parent))
        {
            UnionByRank(u,v,parent,rank);
            mstWeight += w;
            printf("%d %d\n",u,v);

        };
        
    }
    printf("%d\n",mstWeight);
    
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
                insert(adj, vertex, val);
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
        struct list *curr_node = adj[vertex];
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
    kruskals(n,adj);
    return 0;
}