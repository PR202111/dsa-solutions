#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct bst{
    int value;
    struct bst* left;
    struct bst* right;
};
struct bst* create(int val){
    struct bst* ptr;
    ptr = (struct bst*)malloc(sizeof(struct bst));
    ptr->value = val;
    ptr->right = NULL;
    ptr->left = NULL;

    return ptr;
}
struct bst* buildTree(char tr[],int* idx){
    if (tr[(*idx)] == '\0' || tr[(*idx)]==')')
    {
        return NULL;
    }
    int temp = 0;
    while (isdigit(tr[(*idx)]))
    {
        temp = temp*10 + tr[(*idx)] - '0';
        (*idx)++;
    }
    struct bst* root = create(temp);

    if (tr[(*idx)] == '(')
    {
        (*idx)++;
        root->left = buildTree(tr,idx);
        if (tr[(*idx)] == ')')
        {
            (*idx)++;
        }
        
    }
    if (tr[(*idx)] == '(')
    {
        (*idx)++;
        root->right = buildTree(tr,idx);
        if (tr[(*idx)] == ')')
        {
            (*idx)++;
        }
        
    }
    return root;
}
struct bst* build_tree(char tr[],int* idx){
    if (tr[(*idx)] == '\0' ||tr[(*idx)]==')' || tr[(*idx)] == ',')
    {
        return NULL;
    }

    int t = 0;
    while (isdigit(tr[(*idx)]))
    {
        t = t*10 + tr[(*idx)] - '0';
        (*idx)++;
    }
    struct bst* root = create(t);
    if (tr[(*idx)]=='(')
    {
        (*idx)++;
        root->left = build_tree(tr,idx);
        if (tr[(*idx)] == ',')
        {
            (*idx)++;
            root->right = build_tree(tr,idx);
        }
        if (tr[(*idx)] == ')')
        {
            (*idx)++;
        }
        
    }
    return root;
    
}
int count_node_at_k(struct bst* root,int k){
    int lvl = 0;
    struct bst* curr_lvl[100];
    int back_curr = -1;
    struct bst* nxt_lvl[100];
    int back_nxt = -1;
    curr_lvl[++back_curr] = root;
    while (back_curr>=0)
    {
        if (lvl == k)
        {
            for (int i = 0; i <= back_curr; i++)
            {
                printf("%d ",curr_lvl[i]->value);
            }
            return back_curr+1;
            
        }
        
        struct bst* node = curr_lvl[back_curr--];
        if (root->left != NULL)
        {
            nxt_lvl[++back_nxt] = root->left;
        }
        if (root->right != NULL)
        {
            nxt_lvl[++back_nxt] = root->right;
        }
        if (back_curr == -1)
        {
            for (int i = 0; i <= back_nxt; i++)
            {
                curr_lvl[i] = nxt_lvl[i];
            }
            lvl++;
            back_curr = back_nxt;
            back_nxt = -1;
            
        }
        
    }
    printf("No Nodes found at lvl k\n");

}
int main(){


    return 0;
}