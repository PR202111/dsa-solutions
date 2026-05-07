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

struct dll* del(struct dll *head, int key)
{
    if(head == NULL){
        printf("Nothing to Delete\n");
        return NULL;
    }
    struct dll *temp = head;
    struct dll *head_new = head;
    while (temp != NULL)
    {
        if (temp->val == key)
        {
            if (temp->prev != NULL)
            {
                (temp->prev)->next = temp->next;
            }
            else{
                head_new = temp->next;
            }
            if (temp->next != NULL)
            {
                (temp->next)->prev = temp->prev;
            }
        }
        temp = temp->next;
    }
    temp = head_new;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
    return head_new;
}

int main()
{
    int n;
    printf("Enter the initial double linked list: ");
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
    int key, mode;
    printf("1->Delete\n2->Exit\n");
    while (1)
    {
        scanf("%d", &mode);
        if (mode == 1)
        {
            printf("Enter the Key to Delete: ");
            scanf("%d", &key);
            head = del(head, key);
        }
        if (mode == 2)
        {
            break;
        }
    }

    return 0;
}
