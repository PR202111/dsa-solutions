#include<stdio.h>
struct queue{
    int arr[100];
    int top;
    int bottom;
};
int front(struct queue* q){
    
    return q->arr[q->bottom];
}
int isEmpty(struct queue* q){
    if ((q->top == -1 && q->bottom == -1) || (q->bottom > q->top))
    {
        q->bottom = -1;
        q->top = -1;
       return 1;
    }
    return 0;
}
void pop(struct queue* q){
    if (!isEmpty(q))
    {
        (q->bottom)++;
    }
    
}
void push(struct queue* q,int n){
    if (q->top == -1 && q->bottom == -1)
    {
        (q->bottom)++;
        (q->top)++;
        q->arr[q->top] = n;
        return;
    }
    (q->top)++;
    q->arr[q->top]=n;
    
}
void dfs(int start,int n,int g[][n],int vis[]){
    vis[start] = 1;
    printf("%d ",start+1);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && g[start][i] == 1)
        {
            dfs(i,n,g,vis);
        }
        
    }
    
}
void bfs(int mat[100][100],int n,int start){
    int vis[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }
    
    int queue[100];
    int top = -1,bottom = -1;
    queue[++top] = start;
    vis[start] = 1;
    while (top > bottom)
    {
        int node = queue[++bottom];
        printf("%d ");
        for (int i = 0; i < n; i++)
        {
            if (mat[node][i] && !vis[i])
            {
                queue[++top] = i;
                vis[i] = 1;
            }
            
        }
        
    }
    printf("\n");
    
}
void SizeOfConnectedComponents(int n,int g[][n]){
    struct queue q;
    int vis[n];
    int size;
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }
    int s[n];
    int track = 0;
    for (int start = 0; start < n; start++)
    {
        size = 0;
        if (!vis[start])
        {
            q.bottom = -1;
            q.top = -1;
            push(&q,start);
            vis[start]=1;
            while (!isEmpty(&q))
            {
                int node = front(&q);
                pop(&q);
                size++;
                for (int i = 0; i < n; i++)
                {
                    if (!vis[i] && g[node][i]==1)
                    {
                        push(&q,i);
                        vis[i]=1;
                    }
                    
                }
                
            }
            s[track++] = size;

        }
        
    }
    for (int i = 0; i < track-1; i++)
    {
        for (int j = i+1; j < track; j++)
        {
            if (s[i]>s[j])
            {
                int temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
            
        }
        
    }

    for (int i = 0; i < track; i++)
    {
        printf("%d ",s[i]);
    }
    printf("\n");
}
void NoOfConnected(int n,int g[][n]){
    struct queue q;
    int count = 0;
    int vis[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }
    int i =0;
    while (i<n)
    {
        if (!vis[i])
        {
            int start = i;
            q.top = -1;
            q.bottom = -1;
            push(&q,start);
            vis[start] = 1;
            while (!isEmpty(&q))
            {
                int node = front(&q);
                pop(&q);
                for (int j = 0; j < n; j++)
                {
                    if (!vis[j] && g[node][j] == 1) {
                        push(&q, j);
                        vis[j] = 1;
                    }
                }
                
            }
            count++;
        }
        i++;  
    }
    printf("%d\n",count);
}

void traversalOrder(int n,int g[][n]){
    int vis[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }
    int i =0;
    while (i<n)
    {
        if (!vis[i])
        {
            dfs(i,n,g,vis);
            printf("\n");
            
        }
        i++;  
    }
}
void VertexReachability(int n,int g[][n],int vertex){
     struct queue q;
     q.top = -1;
     q.bottom = -1;
    int vis[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }
     push(&q,vertex);
     vis[vertex] = 1;
    printf("%d ",vertex+1);
     while (!isEmpty(&q))
     {
        int node = front(&q);
        pop(&q);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && g[node][i] == 1)
            {
                push(&q,i);
                vis[i] = 1;
                printf("%d ",i+1);
            }
            
        }
        
     }
     printf("\n");
     
}
void findShotestPath(int n,int g[][n],int start,int end){
    struct queue q;
    q.bottom = -1;
    q.top = -1;
    int parent[n];
    int vis[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        parent[i] = -1;
    }
    push(&q,start);
    vis[start] = 1;
    while (!isEmpty(&q))
    {
        int node = front(&q);
        pop(&q);
        if (node == end)
        {
             break;
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && g[node][i]==1)
            {
                push(&q,i);
                vis[i] = 1;
                parent[i] = node;
            }
            
        }
        
    }
    if (!vis[end])
    {
        printf("No Path Exist\n");
        return;
    }
    
    int path[n];
    int length = 0;
    for (int v = end; v != -1; v = parent[v])
    {
        path[length++] = v;
    }
    for (int i = length-1; i >= 0; i--)
    {
       printf("%d ",path[i]+1);
    }
    printf("\n");
}
int main(){
    int n,start,end;
    char mode;
    scanf("%d",&n);
    int g[n][n];
    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < n; j++)
       {
            scanf("%d",&g[i][j]);
       }
       
    }
    while (1)
    {
        scanf(" %c",&mode);
        if (mode == 'a')
        {
            NoOfConnected(n,g);
        }
        if (mode == 'b')
        {
            traversalOrder(n,g);
        }
        if (mode == 'c')
        {
            SizeOfConnectedComponents(n,g);
        }
        if (mode == 'd')
        {
            scanf("%d",&start);
            VertexReachability(n,g,start-1);
        }
        if (mode == 'e')
        {
            scanf("%d%d",&start,&end);
            findShotestPath(n,g,start-1,end-1);
        }
        if (mode == 'x')
        {
            break;
        }
        getchar();
    }
    

return 0;
}