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

int isPalindrome(struct dll *head)
{
    if(head == NULL || head->next == NULL) return 1;
    int i =1;
    struct dll* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }
    for(int j =0; j< i/2;j++){
        if(head->val != temp->val) return 0;
        head = head->next;
        temp = temp->prev;
    }

    return 1;
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
    if (isPalindrome(head))
    {
        printf("Palindrome\n");
    }
    else{
        printf("Not a Palindrome\n");
    }
    
    return 0;
}
