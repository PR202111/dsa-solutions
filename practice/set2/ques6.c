#include<stdio.h>
#include<stdlib.h>
struct cll{
    int val;
    struct cll* next;
};

struct cll* create(int value){
    struct cll* ptr;
    ptr = (struct cll*)malloc(sizeof(struct cll));
    ptr->val = value;
    ptr->next = NULL;
    return ptr;
}

struct cll* insert_end(struct cll* head,int val){
    struct cll* new = create(val);
    if(head == NULL){
        new->next = new;
        return new;
    }
    struct cll* temp = head;
    temp = temp->next;

    while (temp->next != head)
    {
        temp = temp->next; 
    }
    new->next = head;
    temp->next = new;
    return head;
}
void Display(struct cll* head){
    if (head == NULL)
    {
        printf("Empty");
        return;
    }
    struct cll* temp = head;
    printf("%d",head->val);
    temp = temp->next;
    while (temp != head)
    {
        printf(" %d",temp->val);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    struct cll* head = NULL;
    int mode;
    printf("1->Insert\n2->Exit\n");
    while (1)
    {
        printf("Enter Mode: ");
        scanf("%d",&mode);
        if (mode == 1)
        {
            printf("Enter the Element: ");
            int t;
            scanf("%d",&t);
            head = insert_end(head,t);
            Display(head);
        }
        if (mode == 2)
        {
            break;
        }
        
        
    }
    
    return 0;
}