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

void insert(struct dll *head, int key, int num)
{
    struct dll *temp = head;
    while (temp != NULL)
    {
        if (temp->val == key)
        {
            struct dll *node = create(num);
            node->next = temp->next;
            if (temp->next != NULL)
            {
                (temp->next)->prev = node;
            }
            temp->next = node;
            node->prev = temp;

            temp = head;
            while (temp != NULL)
            {
                printf("%d ", temp->val);
                temp = temp->next;
            }
            printf("\n");
            return;
        }
        temp = temp->next;
    }
    printf("No such Key Exist\n");
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
    int key, num, mode;
    printf("1->Insert\n2->Exit\n");
    while (1)
    {
        scanf("%d", &mode);
        if (mode == 1)
        {
            printf("Enter the Key and Num: ");
            scanf("%d%d", &key, &num);
            insert(head, key, num);
        }
        if (mode == 2)
        {
            break;
        }
    }

    return 0;
}
