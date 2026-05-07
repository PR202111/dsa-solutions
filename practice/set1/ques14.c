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

int size_stack(struct stack* st){
    return (st->top + 1);
}
void sort(struct stack *s1,struct stack *s2){
    int temp;
    while(!isEmpty(s1)){
        temp = front(s1);
        pop(s1);
        while (!isEmpty(s2) && temp < front(s2))
        {
            push(s1,front(s2));
            pop(s2);
        }
        push(s2,temp);
    }
    while (!isEmpty(s2))
    {
        push(s1,front(s2));
        pop(s2);
    }
    printf("Sorted Stack: ");
    for (int i = 0; i <= s1->top; i++)
    {
        printf("%d ",s1->arr[i]);
    }
    printf("\n");
    
}
int main(){
    struct stack s1;
    struct stack s2;
    s1.top = -1;
    s2.top = -1;
    int n;
    printf("Enter the Size of Stack: ");
    scanf("%d",&n);
    int t;
    printf("Enter the Elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        push(&s1,t);
    }
    sort(&s1,&s2);
    return 0;
}
