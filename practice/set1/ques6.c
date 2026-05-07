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

struct sll* revere(struct sll* start,struct sll* end){
    struct sll* prev = NULL;
    struct sll* curr = start;
    struct sll* next = NULL;
    struct sll* stop = end->next;
    while (curr != stop)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    start->next = stop;
    
    return end;

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
    int k;
    printf("Enter the GroupSize to be reversed: ");
    scanf("%d",&k);
    if(k > 1){
        struct sll* prev_grp_end = &dummy;
        struct sll* grp_start = dummy.next;
        struct sll* grp_end = dummy.next;
        
        while(1){
        
            for(int i=0;i<k-1 && grp_end != NULL;i++){
                grp_end =  grp_end->next;
            }
            if(grp_end == NULL){
                break;
            }
            else{
                struct sll* next_grp_start = grp_end->next;
                struct sll* new_grp_head = revere(grp_start,grp_end);
                prev_grp_end->next = new_grp_head;
                prev_grp_end = grp_start;
                grp_start = prev_grp_end->next;
                grp_end = prev_grp_end->next;

            } 
        }
    }
    dummy_ptr = &dummy;
    dummy_ptr = dummy_ptr->next;
    for(int i =0;i <n && dummy_ptr != NULL;i++){
        printf("%d ",dummy_ptr->val);
        dummy_ptr = dummy_ptr->next;
    }
    printf("\n");

    return 0;
}