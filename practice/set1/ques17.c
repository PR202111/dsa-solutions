#include<stdio.h>

struct stack
{
    int arr[100];
    int top;
};

int SisEmpty(struct stack* st){
    if(st->top == -1){
        return 1;
    }

    return 0;
}

void Spop(struct stack* st){
    if(!SisEmpty(st)){
        (st->top)--;
    }
    else{
        printf("Empty\n");
    }
}
int Sfront(struct stack* st){
    if(!SisEmpty(st)){
        return st->arr[st->top];
    }
    return 0;
}
void Spush(struct stack* st,int c){
    st->arr[++(st->top)] = c;
}

struct queue
{
    int arr[100];
    int top;
    int bottom;
};
int QisEmpty(struct queue* q){
    if((q->top == -1 && q->bottom == -1) || q->bottom > q->top ){
        q->top = -1;
        q->bottom = -1;
        return 1;
    }
    return 0;
} 

void Qpush(struct queue* q,int t){
    if(q->top == -1){
        ++(q->bottom);
    }
    q->arr[++(q->top)] = t; 
}
void Qpop(struct queue* q){
    if(!QisEmpty(q)){
        (q->bottom)++;
    }
}
int Qfront(struct queue* q){
    if(!QisEmpty(q)){
        return q->arr[q->bottom];
    }
    return -1;
}

int main(){
    struct queue q;
    q.bottom = -1;
    q.top = -1;
    struct stack st;
    st.top = -1;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the Elements: ");
    int t;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&t);
        Qpush(&q,t);
    }
    int k;
    printf("Enter the k: ");
    scanf("%d",&k);
    if(n>=k){
        for (int i = 0; i < k; i++)
        {
            Spush(&st,Qfront(&q));
            Qpop(&q);
        }
        while (!SisEmpty(&st))
        {
            Qpush(&q,Sfront(&st));
            Spop(&st);
        }
        for (int i = 0; i < n-k; i++)
        {
           Qpush(&q,Qfront(&q));
           Qpop(&q);
        }
        
        for (int i = q.bottom; i <= q.top; i++)
        {
           printf("%d ",q.arr[i]);
        }
        printf("\n");
            
    }
    else{
        printf("Enter k such that k < n");
    }
}