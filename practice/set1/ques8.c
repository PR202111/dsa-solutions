#include <stdio.h>
#include <stdlib.h>
struct sll
{
    int val;
    struct sll *next;
};
struct sll *create(int value)
{
    struct sll *ptr;
    ptr = (struct sll *)malloc(sizeof(struct sll));
    ptr->val = value;
    ptr->next = NULL;

    return ptr;
}
void reverse(struct sll *head)
{
    if (head != NULL)
    {

        reverse(head->next);
        printf("%d", head->val);
    }
}
struct sll *add(struct sll *head1, struct sll *head2)
{
    struct sll dummy1;
    dummy1.next = NULL;
    struct sll *dummy_ptr = &dummy1;
    int sum = 0;
    int carry = 0;
    while (head1 != NULL || head2 != NULL || carry)
    {
        sum = (head1 != NULL ? head1->val : 0) + (head2 != NULL ? head2->val : 0) + carry;
        carry = sum / 10;
        dummy_ptr->next = create(sum % 10);
        dummy_ptr = dummy_ptr->next;
        head1 = head1 != NULL ? head1->next : NULL;
        head2 = head2 != NULL ? head2->next : NULL;
    }
    return dummy1.next;
}

int main()
{
    struct sll dummy1;
    dummy1.next = NULL;
    struct sll *dummy1_ptr = &dummy1;
    struct sll dummy2;
    dummy2.next = NULL;
    struct sll *dummy2_ptr = &dummy2;
    printf("Enter Two Numbers: ");
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    while (n1)
    {
        dummy1_ptr->next = create(n1 % 10);
        dummy1_ptr = dummy1_ptr->next;
        n1 /= 10;
    }
    while (n2)
    {
        dummy2_ptr->next = create(n2 % 10);
        dummy2_ptr = dummy2_ptr->next;
        n2 /= 10;
    }
    struct sll *add_head = add(dummy1.next, dummy2.next);
    reverse(add_head);
    printf("\n");

    return 0;
}