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

struct sll* revere(struct sll* start){
    struct sll* prev = NULL;
    struct sll* curr = start;
    struct sll* next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;

}

int isPlaindrome(struct sll* head){
    struct sll* slow = head;
    struct sll* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    struct sll* SecondHalf = revere(slow->next);
    while (SecondHalf != NULL)
    {
        if(head->val != SecondHalf->val){
            return 0;
        }
        head = head->next;
        SecondHalf = SecondHalf->next;
    }
    return 1;
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
    if(isPlaindrome(dummy.next)){
        printf("It is Palindrome\n");
    }
    else{
        printf("NOT a Palindrome\n");
    }
}