#include<stdio.h>
#include<stdlib.h>

struct bst{
    int val;
    struct bst* firstChild;
    struct bst* nextSibling;
};
int char_to_value(char c){
   return c - '0';
}
int count_leafs(struct bst* root){
    if(root == NULL) return 0;
    if(root->firstChild == NULL){
        return 1 + count_leafs(root->nextSibling);
    }
    return count_leafs(root->firstChild) + count_leafs(root->nextSibling);
}
struct bst* create(int value){
    struct bst* ptr;
    ptr = (struct bst*)malloc(sizeof(struct bst));
    ptr->val = value;
    ptr->firstChild = NULL;
    ptr->nextSibling = NULL;

    return ptr;
}

struct bst* buildTree(char tr[],int *index){
    if(tr[*(index)] == '\0') return NULL;
    int val = 0;
    while (tr[*index] != '\0' && tr[*index] != '(' && tr[*index] != ')') {
        val = val * 10 + char_to_value(tr[*index]);
        (*index)++;
    }
    
    struct bst* root = create(val);
   
    struct bst* PrevChild = NULL;

    while (tr[*(index)] == '(')
    {
        (*index)++;

        struct bst* child = buildTree(tr,index);

        if (PrevChild == NULL)
        {
            root->firstChild = child;
        }
        else{
            PrevChild->nextSibling = child;
        }
        PrevChild = child;
        if(tr[(*index)] == ')') (*index)++;
        
    }

    return root;
}



int main(){

    char tree[100];
    printf("Enter the Paranthesis representation od tree: ");
    scanf("%s",tree);
    int i = 0;
    struct bst* root = buildTree(tree,&i);
    printf("Number of leaves: %d\n",count_leafs(root));

    return 0;
}