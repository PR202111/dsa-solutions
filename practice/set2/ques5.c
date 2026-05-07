#include <stdio.h>
#include <stdlib.h>

struct dll
{
    int val;
    struct dll *next;
    struct dll *prev;
};

struct dll *create(int value)
{
    struct dll *ptr;
    ptr = (struct dll *)malloc(sizeof(struct dll));
    ptr->val = value;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}
struct dll* merge(struct dll* head1,struct dll* head2){
    struct dll dummy;
    dummy.next = NULL;
    dummy.prev= NULL;
    struct dll* dummy_ptr = &dummy;
    while (head1 != NULL && head2 != NULL)
    {
        if(head1->val < head2->val){
            dummy_ptr->next = head1;
            head1->prev = dummy_ptr;
            head1 = head1->next;
        }
        else{
            dummy_ptr->next = head2;
            head2->prev = dummy_ptr;
            head2 = head2->next;
        }
        dummy_ptr = dummy_ptr->next;
    }
    
    if(head1 == NULL){
        while (head2 != NULL)
        {
            dummy_ptr->next = head2;
            head2->prev = dummy_ptr;
            head2 = head2->next;
            dummy_ptr = dummy_ptr->next;
        }
        
    }
    else{
        while (head1 != NULL)
        {
            dummy_ptr->next = head1;
            head1->prev = dummy_ptr;
            head1 = head1->next;
            dummy_ptr = dummy_ptr->next;
        }
        
    }
    struct dll* new_head = dummy.next;
    new_head->prev = NULL;
    return new_head;
}
void Display(struct dll* head){
    if(head == NULL){
        printf("Empty\n");
        return;
    }
    struct dll* temp = head;
    while (temp->next != NULL)
    {
        printf("%d ",temp->val);
        temp = temp->next;
    }
    printf("%d\n",temp->val);
    while (temp->prev != NULL)
    {
        printf("%d ",temp->val);
        temp = temp->prev;
    }
    printf("%d\n",temp->val);
    
}

int main()
{
    int n1;
    printf("Enter the initial size 1st doubly linked list: ");
    scanf("%d", &n1);
    struct dll dummy1;
    struct dll *dummy_ptr1 = &dummy1;
    int temp;
    printf("Enter the elemnts for 1st linked list: ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &temp);
        struct dll *new = create(temp);
        dummy_ptr1->next = new;
        new->prev = dummy_ptr1;
        dummy_ptr1 = dummy_ptr1->next;
    }
    struct dll *head1 = dummy1.next;
    head1->prev = NULL;

    int n2;
    printf("Enter the initial size of 2nd doubly linked list: ");
    scanf("%d", &n2);
    struct dll dummy2;
    struct dll *dummy_ptr2 = &dummy2;
    printf("Enter the elemnts for 2nd linked list: ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &temp);
        struct dll *new = create(temp);
        dummy_ptr2->next = new;
        new->prev = dummy_ptr2;
        dummy_ptr2 = dummy_ptr2->next;
    }
    struct dll *head2 = dummy2.next;
    head2->prev = NULL;
    struct dll* new_head = merge(head1,head2);
    Display(new_head);
    return 0;
}
