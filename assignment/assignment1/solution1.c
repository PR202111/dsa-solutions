#include<stdio.h>
#include<stdlib.h>

struct bst{
    int val;
    struct bst* left;
    struct bst* right;
};
void zigzag(struct bst* root,int n){
    if (root == NULL)
    {
        printf("Empty\n");
        return;
    }

    struct bst* current_lvl[100];
    struct bst* nxt_lvl[100];
    int top_curr = -1,top_next = -1;
    int left_to_rgt = 0;
    current_lvl[++top_curr] = root;
    while (top_curr >=0)
    {
        struct bst* node = current_lvl[top_curr--];
        printf("%d ",node->val);
        if (left_to_rgt)
        {
            if (node->left != NULL)
            {
                nxt_lvl[++top_next] = node->left;
            }
            if (node->right != NULL)
            {
                nxt_lvl[++top_next] = node->right;
            }
            
        }
        else{
            if (node->right != NULL)
            {
                nxt_lvl[++top_next] = node->right;
            }
            if (node->left != NULL)
            {
                nxt_lvl[++top_next] = node->left;
            }
        }

        if (top_curr == -1)
        {
            left_to_rgt = !left_to_rgt;

            for (int i = 0; i <= top_next; i++)
            {
                current_lvl[i] = nxt_lvl[i];

            }
            top_curr = top_next;
            top_next = -1;
        }   
        
    }
    
    printf("\n");
}
void lvl_max(struct bst* root,int a[],int lvl){
    if (a[lvl]<root->val)
    {
        a[lvl] = root->val;
    }
    if (root->left != NULL)
    {
        lvl_max(root->left,a,lvl+1);
    }
    
    if (root->right != NULL)
    {
        lvl_max(root->right,a,lvl+1);
    }
    
    
}
struct bst* create(int value){
    struct bst* ptr;
    ptr = (struct bst*)malloc(sizeof(struct bst));
    ptr->val = value;
    ptr->right= NULL;
    ptr->left = NULL;

    return ptr;
}
void postorder(struct bst* root){
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->val);
    }
    
}
struct bst* buildTree(int In[],int pre[],int i_In,int j_In,int* idx_pre,int n){
    if (i_In > j_In)
    {
        return NULL;
    }
    int find_root = i_In;
    for (int i = i_In; i <= j_In; i++)
    {
        if (In[i] == pre[(*idx_pre)])
        {
            find_root = i;
            break;
        }
        
    }
    struct bst* root = create(pre[(*idx_pre)]);
    (*idx_pre)++;
    
    root->left = buildTree(In,pre,i_In,find_root-1,idx_pre,n);
    root->right = buildTree(In,pre,find_root+1,j_In,idx_pre,n);
   
    
    return root;
    
}
int main(){

    int n;
    //printf("Enter the Number of Nodes: ");
    scanf("%d",&n);
    //printf("Enter the Inorder: ");
    int pre[n];
    int In[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&In[i]);
    }
    //printf("Enter the Preorder: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&pre[i]);
    }
    struct bst *root = NULL;
    int idx_pre = 0;

    root = buildTree(In,pre,0,n-1,&idx_pre,n);
    char mode;
    getchar();
    while (1)
    {
        //printf("Enter Mode: ");
        scanf("%c",&mode);
        if (mode == 'p')
        {
            postorder(root);
            printf("\n");
        }
        else if (mode == 'z')
        {
            zigzag(root,n);
        }
        else if (mode == 'm')
        {
            int a[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = 0;
            }
            
            lvl_max(root,a,0);
            for (int i = 0; i < n && a[i] != 0; i++)
            {
                printf("%d ",a[i]);
            }
            printf("\n");
        }
        else if (mode == 'e')
        {
            break;
        }
           
        getchar();
    }
    
    return 0;
}