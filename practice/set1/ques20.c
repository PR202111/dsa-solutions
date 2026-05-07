#include<stdio.h>
struct queue
{
    int arr[100];
    int top;
    int bottom;
};
int isEmpty(struct queue* q){
    if((q->top == -1 && q->bottom == -1) || q->bottom > q->top ){
        q->top = -1;
        q->bottom = -1;
        return 1;
    }
    return 0;
} 

void push(struct queue* q,int t){
    if(q->top == -1){
        ++(q->bottom);
    }
    q->arr[++(q->top)] = t; 
}
void pop(struct queue* q){
    if(!isEmpty(q)){
        (q->bottom)++;
    }
}
int front(struct queue* q){
    if(!isEmpty(q)){
        return q->arr[q->bottom];
    }
    return -1;
}
int main(){
    struct queue q;
    q.bottom = -1;
    q.top = -1;
    int n;
    printf("Enter the Number: ");
    scanf("%d",&n);
    while (n)
    {
        push(&q,n%2);
        n /= 2;
    }
    printf("Binary form: ");
    for (int i = q.top; i >= q.bottom; i--)
    {
        printf("%d",q.arr[i]);
    }
    printf("\n");
    
    

    return 0;
}
