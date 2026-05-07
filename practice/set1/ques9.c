#include<stdio.h>
#include<stdlib.h>
struct sll
{
    int val;
    struct sll* next;
};
struct sll* create(int value){
    struct sll* ptr;
    ptr = (struct sll*)malloc(sizeof(struct sll));
    ptr->val = value;
    ptr->next = NULL;

    return ptr;
}

struct sll* partition(struct sll* head,int x){
    struct sll less;
    less.next = NULL;
    struct sll grt;
    grt.next = NULL;
    struct sll* less_ptr = &less;
    struct sll* grt_ptr = &grt;
    while (head != NULL)
    {
        if(head->val < x){
            less_ptr->next = head;
            less_ptr = less_ptr->next;
        }
        else{
            grt_ptr->next = head;
            grt_ptr = grt_ptr->next;
        }
        head = head->next;
    }
    less_ptr->next = grt.next;
    return less.next;
    
}

int main(){
    int n;
    printf("Enter the size of Linnked List: ");
    scanf("%d",&n);
    printf("Enter the elements of Linked List:\n");
    int temp;
    struct sll dummy;
    dummy.next = NULL;
    struct sll* dummy_ptr;
    dummy_ptr = &dummy; 
    for(int i =0;i<n;i++){
        scanf("%d",&temp);
        dummy_ptr->next = create(temp);
        dummy_ptr = dummy_ptr->next;
    }
    int m;
    printf("Enter the partioned number: ");
    scanf("%d",&m);
    struct sll* head = partition(dummy.next,m);
    while(head != NULL){
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n");
    return 0;
}