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

struct dll* reverse_head(struct dll *head)
{
    if(head == NULL) return NULL;
    
    struct dll* temp = NULL;
    struct dll* curr = head;
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    return temp->prev;

}

void Display(struct dll* head){
    if(head == NULL){
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

int main()
{
    int n;
    printf("Enter the initial size of double linked list: ");
    scanf("%d", &n);
    struct dll dummy;
    struct dll *dummy_ptr = &dummy;
    int temp;
    printf("Enter the elemnts: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        struct dll *new = create(temp);
        dummy_ptr->next = new;
        new->prev = dummy_ptr;
        dummy_ptr = dummy_ptr->next;
    }
    struct dll *head = dummy.next;
    head->prev = NULL;
    printf("Normal Linked List: ");
    Display(head);
    head = reverse_head(head);
    printf("Reversed Linked List: ");
    Display(head);
    return 0;
}
