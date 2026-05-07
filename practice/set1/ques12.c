#include<stdio.h>
#include<string.h>
#include<ctype.h>
char opposite(char c){
    if(c == ')') return '(';
    if(c == '}') return '{';
    return '[';
}
struct stack{
    char arr[100];
    int top;
};
int isEmpty(struct stack* st){
    if(st->top == -1) return 1;
    return 0;
    }
void push(struct stack* st,char c){
    st->arr[++(st->top)] = c;
}
void pop(struct stack* st){
    if(!isEmpty(st)){
        (st->top)--;
    }
    else{
        printf("Empty\n");
    }
}
char front(struct stack* st){
    if(!isEmpty(st)){
        return st->arr[st->top];
    }
    return '\0';
}

int main(){
    struct stack st;
    st.top = -1;
    char expression[100];
    printf("Enter the Expression: ");
    scanf("%[^\n]",expression);
    int i =0;
    char temp;
    while (expression[i] != '\0')
    {
        temp = expression[i];
        if(isspace(temp)||isalnum(temp) || temp == '+' || temp == '-'|| temp == '/'||temp =='*'){
            i++;
            continue;
        }
        else if (temp == '(' || temp == '{' || temp == '[')
        {
            push(&st,temp);
        }
        else if (temp == ')' || temp == '}' || temp == ']'){
            char counter = opposite(temp);
            if(front(&st) == counter){
                pop(&st);
            }
            else{
                printf("NOT VALID\n");
                return 0;
            }
        }
        i++;
        
    }
    if(isEmpty(&st)){
        printf("Valid\n");
    }
    else{
        printf("NOT VALID\n");
    }
    

    return 0;
}