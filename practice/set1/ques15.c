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

int main(){
    int max = -1;
    struct stack st;
    st.top = -1;
    int n;
    printf("Enter the size of Array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the Elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        while (!isEmpty(&st) && front(&st)<=a[i]){
            pop(&st);
        }
        if(isEmpty(&st)){
            printf("-1 ");
        }
        else{
            printf("%d ",front(&st));
        }
        push(&st,a[i]);
        
    }
    printf("\n");
    


    return 0;
}