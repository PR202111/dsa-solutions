#include<stdio.h>
#include<ctype.h>
float char_to_num(char c){
    if(c == '0') return 0.0;
    if(c == '1') return 1.0;
    if(c == '2') return 2.0;
    if(c == '3') return 3.0;
    if(c == '4') return 4.0;
    if(c == '5') return 5.0;
    if(c == '6') return 6.0;
    if(c == '7') return 7.0;
    if(c == '8') return 8.0;
    return 9.0;
}
float eval(int num1,int num2,char operator){
    if(operator == '+') return num1+num2;
    
    if(operator == '-') return num1-num2;
    
    if(operator == '*') return num1*num2;
    
    return num1/num2;
    
    }
struct stack
{
    float arr[100];
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
float front(struct stack* st){
    if(!isEmpty(st)){
        return st->arr[st->top];
    }
    return 0;
}
void push(struct stack* st,float c){
    st->arr[++(st->top)] = c;
}


int main(){
    struct stack st;
    st.top = -1;
    char exp[100];
    printf("Enter the Postfix Expression: ");
    scanf("%[^\n]",exp);
    int i = 0;
    while (exp[i] != '\0')
    {
        if(isspace(exp[i])){
            i++;
            continue;
        }
        if(isdigit(exp[i])){
            push(&st,char_to_num(exp[i]));
        }
        if(exp[i] == '+' || exp[i] == '*' || exp[i] == '-'|| exp[i] == '/'){
            float num2 = front(&st);
            pop(&st);
            float num1 = front(&st);
            pop(&st);
            push(&st,eval(num1,num2,exp[i]));
        }
        i++;
    }
    printf("Output = %.2f\n",front(&st));


    return 0;
}