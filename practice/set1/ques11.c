#include<stdio.h>
#include<string.h>
struct stack
{
    char arr[100][30];
    int top;
};

void push(struct stack* st,char t[]){
    strcpy(st->arr[++(st->top)],t);
}
int isEmpty(struct stack* st){
    if(st->top == -1) return 1;
    return 0;
}
void delete_text(struct stack* st,struct stack* un){
    if(!isEmpty(st)){
        push(un,st->arr[(st->top)--]);
    }
    else{
        printf("The text is Empty\n");
    }
}
void undo(struct stack* st,struct stack* un){
    if(!isEmpty(un)){
        delete_text(un,st);
    }
    else{
        printf("Noting to undo\n");
    }
}
void print(struct stack* st){
    if(!isEmpty(st)){
        for(int i=0;i<=st->top;i++){
            printf("%s",st->arr[i]);
        }
        printf("\n");
    }
    else{
        printf("The text is Empty\n");
    }
}


int main(){
    struct stack st; 
    struct stack un;
    st.top = -1; 
    un.top = -1;
    printf("Enter \n1 -> Insert\n2 -> Delete\n3 -> Undo\n4 -> Print\n5 -> exit\n");
    int temp;
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&temp);
        getchar();
        if(temp == 1){
            char t[30];
            printf("Enter your text: ");
            scanf("%[^\n]",t);
            push(&st,t);
        }
        if(temp == 2){
            delete_text(&st,&un);
        }
        if(temp == 3){
            undo(&st,&un);
        }
        if(temp == 4){
            print(&st);
        }
        if(temp == 5){
            break;
        }
    } 

    return 0;
}