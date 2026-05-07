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

struct cll* insert(struct cll* head,int val){
    struct cll* new = create(val);
    if(head == NULL){
        new->next = new;
        return new;
    }
    struct cll* tail = head;
    tail = tail->next;
    struct cll* temp = head;

    while (temp->next != head)
    {
        temp = temp->next; 
    }
    new->next = temp->next;
    temp->next = new;
    return head;
}
struct dll{
    int val;
    struct dll* next;
    struct dll* prev;
};
struct dll* sll_to_dll(struct cll* head){
    if(head == NULL) return NULL;
    struct dll dummy;
    struct dll* dummy_ptr = &dummy;
    dummy.next = NULL;
    dummy.prev = NULL;
    while (head != NULL)
    {
        struct dll* ptr;
        ptr = (struct dll*)malloc(sizeof(struct dll));
        ptr->val = head->val;
        ptr->next= NULL;
        ptr->prev= NULL;
        dummy_ptr->next = ptr;
        ptr->prev = dummy_ptr;
        dummy_ptr = dummy_ptr->next;
        head = head->next;
    }
    
    struct dll* new_head = dummy.next;
    new_head->prev = NULL;
    return new_head;
}
void Display(struct dll* head){
    if (head == NULL)
    {
        printf("Empty\n");
        return;
    }
    struct dll* temp = head;
    while (temp != NULL)
    {
        printf("%d ",temp->val);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter the size of CLL: ");
    scanf("%d",&n);
    struct cll* head = NULL;
    printf("Enter the Element: ");
    int t;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&t);
        head = insert(head,t);       
    }
    if (head == NULL)
    {
        printf("Empty\n");
    }
    
    else if (head->next == head){
        head->next = NULL;  
        struct dll* dll_head = sll_to_dll(head);
        printf("First Part: ");
        Display(dll_head);
        printf("Second Part: Empty\n");
    }
    else{
    
        struct cll* fast = head;
        struct cll* slow = head;
        while (fast->next != head && fast->next->next != head)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        struct cll* second_head = slow->next;
        slow->next = NULL;
        struct cll* temp = second_head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        struct dll* head1 = sll_to_dll(head);
        struct dll* head2 = sll_to_dll(second_head);
        printf("First Part: ");
        Display(head1);
        printf("Second Part: ");
        Display(head2);
    }
    
    
    
    return 0;
}