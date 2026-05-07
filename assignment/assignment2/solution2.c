#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<limits.h>
#include<stdlib.h>

struct list
{
    int value;
    struct list* next;
};

struct list* create(int val){
    struct list* ptr;
    ptr = (struct list*)malloc(sizeof(struct list));
    ptr->value = val;
    ptr->next = NULL;

    return ptr;
}

void insert(struct list* a[],int vertex,int val){
    struct list* ptr = create(val);
    if(a[vertex] == NULL){
        a[vertex] = ptr;
        return;
    }
    struct list* temp = a[vertex];
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    
}

struct queue{
    int arr[100];
    int top;
    int bottom;
};
int isEmpty(struct queue* q){
    if (q->bottom == -1 && q->top == -1 || q->bottom > q->top)
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
int front(struct queue* q){
    return q->arr[q->bottom];
}
void push(struct queue* q,int value){
    if (q->bottom == -1 && q->top == -1)
    {
        (q->bottom)++;
    }
    (q->top)++;
    q->arr[q->top] = value;
    
}
void LevelOrder(int n, struct list* adj[], int start) {
    struct queue q;
    q.top = -1;
    q.bottom = -1;
    int vis[n];
    for (int i = 0; i < n; i++) vis[i] = 0;

    push(&q, start);
    vis[start] = 1;
    int lvl = 0;

    while (!isEmpty(&q)) {
        int levelSize = q.top - q.bottom + 1; 
        printf("Level %d: ", lvl++);

        while (levelSize--) {
            int node = front(&q);
            pop(&q);
            printf("%d ", node);

            struct list* temp = adj[node];
            while (temp != NULL)
            {
                if (!vis[temp->value])
                {
                    push(&q,temp->value);
                    vis[temp->value] = 1;
                }
                temp = temp->next;
            }
            
        }
        printf("\n");
    }
}
void isEulerGraph(int n,struct list* adj[]){
    int flag = 1;
    int degree = 0;
    printf("Degrees: ");
    for (int i = 0; i < n; i++)
    {
        struct list* temp = adj[i];
        degree = 0;
        while (temp != NULL)
        {
            degree++;
            temp = temp->next;
        }
        
        if (i == n-1)
        {
            printf("%d:%d ",i,degree);
        }
        else{
            printf("%d:%d, ",i,degree);
        }
        
        if (degree % 2 != 0)
        {
            flag = 0;
        }  
    }
    if (flag)
    {
        printf("1\n");
    }
    else{
        printf("-1\n");
    }
    
}
int hasCycle(int n,struct list* adj[]){
    struct queue q;
    int vis[n];
    int parent[n];
    for (int i = 0; i < n; i++){
        vis[i] = 0;
        parent[i] = -1;
    } 
    for (int start = 0; start < n; start++)
    {
        if (!vis[start])
        {
            q.bottom = -1;
            q.top = -1;
            push(&q,start);
            vis[start] = 1;

            while (!isEmpty(&q))
            {
                int node = front(&q);
                pop(&q);
                struct list* temp = adj[node];
                while (temp != NULL)
                {
                    if (!vis[temp->value])
                    {
                        push(&q,temp->value);
                        vis[temp->value] = 1;
                        parent[temp->value] = node;
                    }
                    else if (parent[node] != temp->value)
                    {
                        return 1;
                    }
                    temp = temp->next;
                }   
            }
                
        }    
    }
   return 0; 
}
int NoOfConnected(int n,struct list* adj[]){
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
                struct list* temp = adj[node];
                while (temp != NULL)
                {
                    if (!vis[temp->value]) {
                        push(&q, temp->value);
                        vis[temp->value] = 1;
                    }
                    temp = temp->next;
                }  
            }
            count++;
        }
        i++;  
    }
    return count;
}
void isTree(int n,struct list* g[]){
    if (NoOfConnected(n,g) == 1 && !hasCycle(n,g))
    {
        printf("1\n");
    }
    else{
        printf("-1\n");
    }
    
}

int main(){
    int n,start;
    scanf("%d ",&n);
    struct list* adj[n];
    for (int i = 0; i < n; i++)
    {
        adj[i] = NULL;
        
    }
    char temp[100];
    for (int i = 0; i < n; i++)
    {
        scanf("%[^\n]",temp);
        int j = 0;
        int vertex = -1;
        while (isdigit(temp[j]))
        {
            if(vertex == -1) vertex = 0;
            vertex = vertex*10 + temp[j]-'0';
            j++;
        }
        while (temp[j] != '\0')
        {
            if (isdigit(temp[j]))
            {
               int val = 0;
               while (isdigit(temp[j]))
               {
                    val = val*10 + temp[j]-'0';
                    j++;
               }
               insert(adj,vertex,val);
               
            }
            else{
                j++;
            }   
        }
        getchar();    
    }
    char mode;
    while (1)
    {
        scanf(" %c",&mode);
        if (mode == 'a')
        {
            scanf("%d",&start);
            LevelOrder(n,adj,start);
        }
        if (mode == 'b')
        {
            isEulerGraph(n,adj);
        }
        if (mode == 'c')
        {
            if(hasCycle(n,adj)){
                printf("1\n");
            }
            else{
                printf("-1\n");
            }
        }
        if (mode == 'd')
        {
            isTree(n,adj);
        }
        
        if (mode == 'x')
        {
            break;
        }
        getchar();
    }
    return 0;
}