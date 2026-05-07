#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

int height(struct Node *root)
{
    if (root == NULL)
        return 0;
    int left_h = height(root->left);
    int right_h = height(root->right);
    return 1 + (left_h > right_h ? left_h : right_h);
}

int getBalance(struct Node *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *temp = x->right;

    x->right = y;
    y->left = temp;

    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *temp = y->left;

    y->left = x;
    x->right = temp;

    return y;
}

struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->key = key;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    if (balance > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    if (balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void printTree(struct Node *root)
{
    if (root == NULL)
    {
        printf("()");
        return;
    }
    printf("(%d", root->key);
    printTree(root->left);
    printTree(root->right);
    printf(")");
}
int find_paranthesis(char tree[], int i)
{
    int n = len(tree);
    int j = i + 1;
    int count = 1;
    while (j < n)
    {
        if (tree[j] == '(')
        {
            count++;
        }
        else if (tree[j] == ')')
        {
            count--;
            if (count == 0)
            {
                break;
            }
        }
        j++;
    }

    return j;
}
struct Node *bulid_tree(char tree[], int start, int end)
{
    if (end - start == 1 || end < start)
        return NULL;

    int i = start + 1;
    int num = 0;
    while (isdigit(tree[i]))
    {
        num = num * 10 + (tree[i] - '0');
        i++;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->key = num;

    new_node->left = bulid_tree(tree,i,find_paranthesis(tree,i));
    int new_start = find_paranthesis(tree,i)+1;
    new_node->right = bulid_tree(tree,new_start,find_paranthesis(tree,new_start));

    return new_node;
}
struct Node *Successor(struct Node *node)
{
    struct Node *temp = node;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
struct Node* delete_node(struct Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->key)
        root->left = delete_node(root->left, key);
    else if (key > root->key)
        root->right = delete_node(root->right, key);
    else {
        
        if (root->left == NULL || root->right == NULL) {
            struct Node* temp = root->left ? root->left : root->right;

            
            if (temp == NULL) {
                free(root);
                root = NULL;
            }
            else {

                *root = *temp;  
                free(temp);
            }
        }
        else {
            
            struct Node* temp = Successor(root->right);
            root->key = temp->key; // Copy inorder successor's value
            root->right = delete_node(root->right, temp->key);
        }
    }

    // If the tree had only one node
    if (root == NULL)
        return root;

    // Step 2: Update balance and fix rotations
    int balance = getBalance(root);

    // Left Left
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main()
{
    struct Node *root = NULL;
    char c;
    int key;

    while (1)
    {
        scanf(" %c", &c);
        if (c == 'i')
        {
            scanf("%d", &key);
            root = insert(root, key);
        }
        else if (c == 's')
        {
            scanf("%d", &key);
            if (search(root, key) == NULL)
                printf("FALSE\n");
            else
                printf("TRUE\n");
        }
        else if (c == 'b')
        {
            scanf("%d", &key);
            struct Node *hello = search(root, key);
            if (hello == NULL)
                printf("FALSE\n");
            else
                printf("%d\n", getBalance(hello));
        }
        else if (c == 'p')
        {
            printTree(root);
            printf("\n");
        }
        else if (c == 'e')
        {
            break;
        }
    }
    return 0;
}
