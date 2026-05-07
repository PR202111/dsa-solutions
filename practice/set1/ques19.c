#include<stdio.h>

struct stack
{
    int arr[100];
    int top;
};

int isEmpty(struct stack* st){
    if(st->top == -1){
        return 1;
    }

    return 0;
}

void pop(struct stack* st){
    if(!isEmpty(st)){
        (st->top)--;
    }
    else{
        printf("Empty\n");
    }
}
int front(struct stack* st){
    if(!isEmpty(st)){
        return st->arr[st->top];
    }
    return 0;
}
void push(struct stack* st,int c){
    st->arr[++(st->top)] = c;
}
int Stack_size(struct stack* st){
    return (st->top + 1);
}
void enqueue(struct stack* st1,int t){
    push(st1,t);
}
void dequeue(struct stack* st1,struct stack* st2){
    while (Stack_size(st1)>1)
    {
        push(st2,front(st1));
        pop(st1);
    }
    printf("%d\n",front(st1));
    pop(st1);
    while (!isEmpty(st2))
    {
        push(st1,front(st2));
        pop(st2);
    }
}
void Display(struct stack* st1){
    for (int i = 0; i <= st1->top; i++)
    {
        printf("%d ",st1->arr[i]);
    }
    printf("\n");

}
int main(){
    struct stack st1;
    struct stack st2;
    st1.top = -1;
    st2.top = -1;
    printf("1->Enqueue\n2->Dequeue\n3->Display\n4->Exit\n");
    int mode;
    while (1)
    {
        printf("Enter Mode: ");
        scanf("%d",&mode);
        if (mode == 1)
        {
            int temp;
            scanf("%d",&temp);
            enqueue(&st1,temp);
        }
        if (mode == 2)
        {
            dequeue(&st1,&st2);
        }
        if (mode == 3)
        {
            Display(&st1);
        }
        if (mode == 4)
        {
            break;
        }
        
    }
    

}