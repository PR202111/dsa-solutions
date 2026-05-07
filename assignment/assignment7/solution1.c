#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct Node
{
    int id;
    int urgency;
    int degree;
    struct Node* parent;
    struct Node* child;
    struct Node* sibling;
};

struct Node* create_node(int id,int urgency){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->degree = 0;
    node->id = id;
    node->urgency = urgency;
    node->child =NULL;
    node->parent = NULL;
    node->sibling = NULL;

    return node;
}

void binomial_link(struct Node* child,struct Node* parent){
   child->parent = parent;
   child->sibling = parent->child;
   parent->child = child;
   (parent->degree)++;
}

struct Node* merge_root_list(struct Node* heap1,struct Node* heap2){
    if(heap1 == NULL) return heap2;
    if(heap2 == NULL) return heap1;
    struct Node dummy;
    struct Node* dummy_ptr = &dummy;
    while (heap1 != NULL && heap2 != NULL)
    {
        if(heap1->degree <= heap2->degree){
            dummy_ptr->sibling = heap1;
            heap1 = heap1->sibling;
        }
        else{
            dummy_ptr->sibling = heap2;
            heap2 = heap2->sibling;
        }
        dummy_ptr = dummy_ptr->sibling;
    }

    dummy_ptr->sibling = heap1 != NULL ? heap1 : heap2;

    return dummy.sibling;
}

struct Node* union_heaps(struct Node* heap1,struct Node* heap2){
    struct Node* new_heap = merge_root_list(heap1,heap2);

    struct Node* prev = NULL;
    struct Node* x = new_heap;
    struct Node* next = x->sibling;

    while (next != NULL)
    {
        if ((x->degree != next->degree) || (next->sibling && next->sibling->degree == x->degree)){
            prev = x;
            x = next;
        }
        else{
            if(x->urgency <= next->urgency){
                x->sibling = next->sibling;
                binomial_link(next,x);
            }
            else{
                if(prev == NULL){
                    new_heap = next;
                }
                else{
                    prev->sibling = next;
                }
                binomial_link(x,next);
                x = next;
            }
        }
        next = x->sibling;
    }

    return new_heap;
}

struct Node* insert(struct Node* heap,int id,int urgency){
    struct Node* new_heap = create_node(id,urgency);
    return union_heaps(heap,new_heap);
}

struct Node* reverse_list(struct Node* node){
    struct Node* prev = NULL;
    struct Node* next;
    while (node != NULL)
    {
        next = node->sibling;
        node->sibling = prev;
        node->parent = NULL;
        prev = node;
        node = next;
    }
    return prev;
}

struct Node* extractMin(struct Node* heap){
    if(heap == NULL){
        printf("FALSE\n");
        return NULL;
    }

    struct Node* min_prev = NULL,*min_node = heap;
    struct Node* prev = NULL,*curr = heap;
    int min_key = min_node->urgency;
    while (curr != NULL)
    {
        if(curr->urgency < min_key){
            min_key = curr->urgency;
            min_prev = prev;
            min_node = curr;
        }
        prev = curr;
        curr = curr->sibling;
    }

    if(min_prev){
        min_prev->sibling = min_node->sibling;
    }
    else{
        heap = min_node->sibling;
    }

    struct Node* child_heap = reverse_list(min_node->child);

    heap = union_heaps(heap,child_heap);

    printf("%d\n", min_node->id); // print taskId as per question
    free(min_node);

    return heap;
}

struct Node* search(struct Node* heap,int id){
    if(heap == NULL) return NULL;

    if(heap->id == id) return heap;

    struct Node* child_search = search(heap->child,id);
    if (child_search != NULL) return child_search;

    return search(heap->sibling,id);
}

void decreaseUrgency(struct Node* heap,int id,int new_urgency){
    struct Node* node = search(heap,id);
    if(node == NULL){
        printf("FALSE\n");
        return;
    }
    if(new_urgency > node->urgency){
        printf("New urgency must be smaller\n");
        return;
    }

    node->urgency = new_urgency;
    struct Node* y = node;
    struct Node* z = node->parent;

    while ((z != NULL) && (y->urgency < z->urgency))
    {
        int temp_id = y->id;
        int temp_urg = y->urgency;
        y->id = z->id;
        y->urgency = z->urgency;

        z->id = temp_id;
        z->urgency = temp_urg;

        y = z;
        z = z->parent;
    }
}

void display(struct Node* heap) {
    while (heap != NULL) {
        struct Node* queue[100];
        int front = -1, rear = -1;

        printf("Tree rooted at %d: ", heap->id);

        queue[++rear] = heap;


        while (front < rear) {
            struct Node* current = queue[++front];
            printf("%d ", current->id);

            struct Node* child = current->child;
            while (child != NULL) {
                queue[++rear] = child;
                child = child->sibling;
            }
        }

        
        heap = heap->sibling; 
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    char c;
    int id, urgency;
    while (1)
    {
        scanf(" %c", &c);
        if (c == 'i')
        {
            scanf("%d %d", &id, &urgency);
            head = insert(head, id, urgency);
        }
        else if (c == 'e')
        {
            head = extractMin(head);
        }
        else if (c == 's')
        {
            scanf("%d", &id);
            if (search(head, id) == NULL)
                printf("FALSE\n");
            else
                printf("TRUE\n");
        }
        else if (c == 'd')
        {
            scanf("%d %d", &id, &urgency);
            decreaseUrgency(head, id, urgency);
        }
        else if (c == 'p')
        {
            if (head != NULL)
                display(head);
            else
                printf("FALSE\n");
        }
        else if(c == 'x'){
            break;
        }
    }
    return 0;
}
