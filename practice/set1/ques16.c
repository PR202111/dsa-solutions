#include<stdio.h>
#include<string.h>
struct queue{

char arr[100][50];
int top ;
int bottom;
};
void enque(struct queue* q){
    char name[50];
    scanf("%s",name);
    if(q->top == -1 && q->bottom == -1) (q->bottom)++;
    strcpy(q->arr[++(q->top)],name);
}
void dequqe(struct queue* q){
   if((q->top == -1 && q->bottom == -1) || q->top < q->bottom){
      q->top = -1;
      q->bottom = -1;
    }
    else if(q->top == 0 && q->bottom == 0){
    (q->top)--;
    (q->bottom)--;
    }
    else{
    (q->bottom)++;
    }
}
void print(struct queue* q){
    if((q->top == -1 && q->bottom == -1) || q->top < q->bottom){
      q->top = -1;
      q->bottom = -1;
      printf("Empty\n");
    }
    else{
      for(int i = q->bottom ;i <= q->top;i++){
      printf("%s\n",q->arr[i]);
      }
    }
}


int main(){
  struct queue q;
  q.top = -1;
  q.bottom = -1;
  int flag = 1;
  int sr_no;
  printf("1 -> Enqueue\n2 -> Dequeue\n3 -> Exit\n");
  while(flag){
    printf("Enter an Operaton Code: ");
    scanf("%d",&sr_no);
    if(sr_no == 1){
      printf("Enter thr Name: ");
      enque(&q);
    }
    else if(sr_no == 2){
      dequqe(&q);
    }
    else if(sr_no == 3){
      break;
    }
    print(&q);
  }

  return 0;
}
