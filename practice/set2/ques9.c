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
int check(int val,int a[],int j){
    for (int i = 0; i <= j; i++)
    {
        if(a[i] == val) return 1;
    }
    return 0;
    
}
int traverse(struct cll* head,int a[]){
    if (head == NULL)
    {
        return 0;
    }
    if(head->next == head) return 1;
    
    int i =0;
    struct cll* temp = head;
    while (temp->next != head)
    {
        if (!check(temp->val,a,i-1))
        {
            a[i] = temp->val;
            i++;
        }
        temp = temp->next;
    }
    if (!check(temp->val,a,i-1))
    {
        a[i] = head->val;
        i++;
    }
    return i;
    
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
    int arr[n];
    printf("No of Unique values: %d\n",traverse(head,arr));   
        
    
    
    return 0;
}