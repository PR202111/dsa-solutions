#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bst
{
    int model_num;
    char model_name[100];
    int price;
    struct bst* left;
    struct bst* right;
    struct bst* parent;
};

struct bst* create(int model_num,char model_name[],int price){
    struct bst* ptr;
    ptr = (struct bst*)malloc(sizeof(struct bst));
    ptr->model_num = model_num;
    strcpy(ptr->model_name,model_name);
    ptr->price = price;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->parent = NULL;

    return ptr;
}

struct bst* add(struct bst* root,struct bst* new){
    if (root == NULL)
    {
        return new;
    }
    if (root->model_num > new->model_num)
    {
        if (root->left == NULL)
        {
            root->left = new;
            new->parent = root;
        }
        else{
            root->left = add(root->left,new);
        }
    }
    else{
        if (root->right == NULL)
        {
            root->right = new;
            new->parent = root;
        }
        else{
        root->right = add(root->right,new);
        }
    }

    return root;
}
struct bst* search(struct bst* root,int model_num){
    struct bst* temp = root;
    while (temp != NULL && temp->model_num != model_num)
    {
        if (temp->model_num > model_num)
        {
           temp = temp->left;
        }
        else{
            temp = temp->right;
        }
        
    }
    
    return temp;
    
}
struct bst* minValueNode(struct bst* node) {
    struct bst* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct bst* deleteNode(struct bst* root, int model_num) {
    struct bst* find = search(root, model_num);
    if (find == NULL) {
        printf("-1\n");
        return root;
    }
    printf("%d %s %d\n",find->model_num,find->model_name,find->price);
    if (find->left != NULL && find->right != NULL) {
        struct bst* successor = minValueNode(find->right);
        find->model_num = successor->model_num;
        strcpy(find->model_name, successor->model_name);
        find->price = successor->price;
        root = deleteNode(root, successor->model_num);
        return root;
    }


    struct bst* child = (find->left != NULL) ? find->left : find->right;

    if (find->parent == NULL) {
        return child;
    }


    if (find->parent->left == find)
        find->parent->left = child;
    else
        find->parent->right = child;

    if (child != NULL)
        child->parent = find->parent;

    return root;
}


void inorder(struct bst* root){
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d %s %d\n",root->model_num,root->model_name,root->price);
        inorder(root->right);
    }
    
}
void preorder(struct bst* root){
    if (root != NULL)
    {
        printf("%d %s %d\n",root->model_num,root->model_name,root->price);
        preorder(root->left);
        preorder(root->right);
    }
    
}
void postorder(struct bst* root){
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d %s %d\n",root->model_num,root->model_name,root->price);
    }
    
}

int main(){
    char mode;
    int t_model_num;
    int t_price;
    char t_model_name[100];
    struct bst* root = NULL;
    while (1)
    {
        scanf("%c",&mode);
        if (mode == 'a')
        {
            scanf("%d %s %d",&t_model_num,t_model_name,&t_price);
            struct bst* new = create(t_model_num,t_model_name,t_price);
            root = add(root,new);
        }
        else if (mode == 'd')
        {
            scanf("%d",&t_model_num);
            root = deleteNode(root,t_model_num);
        }
        else if (mode == 's')
        {
            scanf("%d",&t_model_num);
            struct bst* find = search(root,t_model_num);
            if (find != NULL)
            {
                printf("%d %s %d\n",find->model_num,find->model_name,find->price);

            }
            else{
                printf("-1\n");
            }
            
        }
        else if (mode == 'i')
        {
            inorder(root);
        }
        else if (mode == 'p')
        {
            preorder(root);
        }
        else if (mode == 't')
        {
            postorder(root);
        }
        else if (mode == 'm')
        {
            scanf("%d %d",&t_model_num,&t_price);
            struct bst* find = search(root,t_model_num);
            if (find != NULL)
            {
                find->price = t_price;
            }
            else{
                printf("-1\n");
            }
        }
        else if (mode == 'e')
        {
            break;
        }
        getchar();
    }

    return 0;
}