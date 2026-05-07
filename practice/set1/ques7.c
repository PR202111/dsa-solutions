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

struct sll* reverse_m_n(struct sll* head_dummy,int m,int n){
    struct sll* node_m = head_dummy;
    struct sll* node_n = head_dummy;
    struct sll* prev_grp = NULL;
    struct sll* next_grp = NULL;
    for(int i=0;i<m && node_m != NULL;i++){
        prev_grp = node_m;
        node_m = node_m->next;
    }
    for(int i=0;i<n && node_n != NULL;i++){
        node_n = node_n->next;
    }
    next_grp = node_n->next;
    if(node_n != NULL && node_m != NULL){
        struct sll* curr = node_m;
        struct sll* next = NULL;
        struct sll* stop = next_grp;
        struct sll* previous = NULL;
        while(curr != stop){
            next = curr->next;
            curr->next = previous;
            previous = curr;
            curr = next;
        }
        node_m->next = next_grp;
        prev_grp->next = node_n;
    }
    return head_dummy->next;
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
    int M,N;
    printf("Enter m and n: ");
    scanf("%d %d",&M,&N);
    struct sll* head;
    head = reverse_m_n(&dummy,M,N);
    while(head != NULL){
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n");
    return 0;
}