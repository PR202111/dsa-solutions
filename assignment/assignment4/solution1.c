#include<stdio.h>
#include<stdlib.h>
#define INF 9999
struct node
{
    int value;
    int weight;
};

struct PQ{
    struct node* data;
    int size;
    int capacity;
};

struct PQ* create_pq(int capacity){
    struct PQ* pq = (struct PQ*)malloc(sizeof(struct PQ));
    pq->data = (struct node*)malloc(sizeof(struct node)*capacity);
    pq->size = 0;

    return pq;
}
void swap(struct node *a,struct node *b){
    struct node temp = *a;
    *a = *b;
    *b = temp;
}
void heapify_up(struct PQ* pq,int idx){
    while (idx > 0)
    {
        int parent = (idx - 1)/2;
        if (pq->data[parent].weight > pq->data[idx].weight)
        {
            swap(&pq->data[parent],&pq->data[idx]);
            idx = parent;
        }
        else break;
        
    }
    
}

void heapify_down(struct PQ* pq,int idx){
    while (1)
    {
        int smallest = idx;
        int left = 2*smallest + 1;
        int right = 2*smallest +2;

        if (left < pq->size && pq->data[left].weight < pq->data[smallest].weight)
        {
            smallest = left;
        }
        if (right < pq->size && pq->data[right].weight < pq->data[smallest].weight)
        {
            smallest = right;
        }
        if (smallest != idx)
        {
            swap(&pq->data[smallest],&pq->data[idx]);
            idx = smallest;
        }
        else break;
        
    }
    
}

void push(struct PQ* pq,int value,int weight){
    pq->data[pq->size].value =  value;
    pq->data[pq->size].weight =  weight;
    heapify_up(pq,pq->size);
    (pq->size)++;
}

void pop(struct PQ* pq){
    if(pq->size == 0) return;
    pq->data[0] = pq->data[pq->size - 1];
    (pq->size)--;
    heapify_down(pq,0);
}

struct node top(struct PQ* pq){
    return pq->data[0];
}

int isEmpty(struct PQ* pq){
    if(pq->size == 0) return 1;

    return 0;
}
int printmst(int n,int mat[][n],int parent[],int start){
    int t_cost = 0;
    for (int i = 0; i < n; i++)
    {
        if(parent[i] == -1) continue;
        printf("%d %d (%d) ",parent[i],i,mat[i][parent[i]]);
        t_cost += mat[i][parent[i]];
    }
    printf("\n");
    return t_cost;
}
void print_path_x_y(int n,int parent[],int x,int y){
    int pY = y;
    int lenY = 0;
    int lenX = 0;
    int ancY[n];
    int ancX[n];
    while (pY != -1)
    {
        ancY[lenY++] = pY;
        
        pY = parent[pY];
        
    }
    
    
    int pX = x;
    int lca = -1;
    while (pX != -1)
    {
        ancX[lenX++] = pX;
        
        pX = parent[pX];
    }

    for (int i = 0; i < lenX && lca == -1; i++)
    {
        printf("%d ",ancX[i]);
       
        for (int j = 0; j < lenY; j++)
        {
            if(ancX[i] == ancY[j]){
                lca = j;
                break;
            }
        }    
    }
   
    for (int i = lca-1; i>=0; i--)
    {
        printf("%d ",ancY[i]);
    }
    printf("\n");
    
}
int PrimMst(int n,int mat[][n],int parent[],int start){
    int t_cost = 0;
    int key[n];
    int inMst[n];
    for(int i=0;i<n;i++){ 
        inMst[i] = 0;
        key[i] = INF;
    }
    struct PQ* pq = create_pq(n*n);
    key[start] = 0;
   
    push(pq,start,key[start]);
    while (!isEmpty(pq))
    {
        struct node u = top(pq);
        pop(pq);
        
        if(inMst[u.value]) continue;
        if (parent[u.value] != -1)
        {
               printf("%d %d (%d) ",parent[u.value],u.value,mat[u.value][parent[u.value]]);
               t_cost += mat[u.value][parent[u.value]];
        }
        
        inMst[u.value] = 1;
        for (int i = 0; i < n; i++)
        {
            if (mat[u.value][i] && !inMst[i] && mat[u.value][i] < key[i])
            {
                key[i] = mat[u.value][i];
                parent[i] = u.value;
                push(pq,i,key[i]);
            } 
        } 
    }

    return t_cost;
    
}
int main(){
    int n,cost = INF,t,x,y;
    scanf("%d",&n);
    int mat[n][n];
    int parent[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&mat[i][j]);
        }
        parent[i] = -1;
        
    }
    char sel;
    while (1)
    {
        scanf("%c",&sel);
        if (sel == 's')
        {
            scanf("%d",&t);
            cost = PrimMst(n,mat,parent,t);
            //cost = printmst(n,mat,parent,t);
            printf("\n");
        }
        else if (sel == 'b')
        {
            printf("%d\n",cost);
        }
        else if (sel == 'c')
        {
            scanf("%d %d",&x,&y);
            print_path_x_y(n,parent,x,y);
        }
        else if (sel == 'e')
        {
            break;
        }  
    }
    return 0;
}