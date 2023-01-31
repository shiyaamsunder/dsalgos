/*
   AVL TREE
*/

#include <stdio.h>
#include <stdlib.h>


struct node;
typedef struct node node;

struct node{
    int data;
    int ht;
    node* left;
    node* right;
};

node* create(int);
node* insert(node*, int);
node* rotate_left(node*);
node* rotate_right(node*);
node* delete(node*, int);
node* search(node*, int);
int height(node*);
int balance_factor(node*);

void preorder(node*);
void postorder(node*);
void inorder(node*);
void print2d(node*);
void print2d_util(node*, int);


node* root = NULL;

int main(){
    int choice, data;
    // node for search
    node* result = NULL;

    system("cls");
    printf("Hello World!\n");

    while(choice !=0){
        printf("\n\n----------------- AVL TREE -----------------\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Preorder\n");
        printf("5. Postorder\n");
        printf("6. Inorder\n");
        printf("7. Print 2D\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
            case 0:
                printf("\n\nExiting Program\n\n");
                free(root);
                return 0;
            case 1:
                printf("\nEnter data: ");
                scanf_s("%d", &data);

                root = insert(root, data);
                if(root==NULL)
                {
                    printf("\nError: Cannot insert\n");
                    return 1;
                }
                else{
                    printf("\n\nInserted a node\n");
                }
                break;
            case 2:
                printf("\nEnter element to delete: ");
                scanf_s("%d", &data);

                root =  delete(root, data);
                printf("Deleted\n");
                break;
            case 7:
                printf("\n-------------------------------------\n");
                print2d(root);
                printf("\n-------------------------------------\n");
                break;
            default:
                
                break;
        }
    }
}

node* create(int data){
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        printf("\nCannot create a new node. No free memory\n");
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* rotate_left(node* root){
    node* right_child = root->right;
    root->right = right_child->left;
    right_child->left = root;

    // handle height updates

    root->ht = height(root);
    right_child->ht = height(right_child);

    return right_child;
}

node* rotate_right(node* root){
    node* left_child = root->left;
    root->left = left_child->right;
    left_child->right = root;

    // handle height updates

    root->ht = height(root);
    left_child->ht = height(left_child);

    return left_child;
}

int balance_factor(node* root){

    int lh, rh;

    if(root== NULL){
        return 0;
    }

    if(root->left==NULL){
        lh = 0;
    }
    else{
        lh = 1 + root->left->ht;
    }

    if(root->right == NULL){
        rh = 0;
    }
    else {
        rh = 1 + root->right->ht;
    }
    return (lh-rh);
}

int height(node* root){

    int lh, rh;

    if(root== NULL){
        return 0;
    }

    if(root->left==NULL){
        lh = 0;
    }
    else{
        lh = 1 + root->left->ht;
    }

    if(root->right == NULL){
        rh = 0;
    }
    else {
        rh = 1 + root->right->ht;
    }

    if(lh>rh) return lh;
    else return rh;
}

node* insert(node* root, int data){
    node* new_node = create(data);

    if(root==NULL){
        if(new_node == NULL){
            return NULL;
        }
        root = new_node;
    }
    else if (data > root->data){
        root->right = insert(root->right, data);
        
        if(balance_factor(root) == -2){
            
            if(data > root->right->data){
                root = rotate_left(root);
            }
            else{
                root->right = rotate_right(root->right);
                root = rotate_left(root);
            }
        }

    }

    else{
        root->left = insert(root->left,data);

        if(balance_factor(root) == 2){
            if(data < root->left->data){
                root = rotate_right(root);
            }
            else{
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    }

    root->ht = height(root);
    return root;
}

void print2d_util(node* root, int space){
    if(root==NULL){
        return;
    }

    space+=3;

    print2d_util(root->right, space);
    printf("\n");
    for(int i=3; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    print2d_util(root->left, space);
}

void print2d(node* root){
    print2d_util(root,0);
}

struct node * delete(struct node *root, int x)
{
    struct node * temp = NULL;
 
    if (root == NULL)
    {
        return NULL;
    } 
 
    if (x > root->data)
    {
        root->right = delete(root->right, x);
        if (balance_factor(root) == 2)
        {
            if (balance_factor(root->left) >= 0)
            {
                root = rotate_right(root);
            }
            else
            {
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    }
    else if (x < root->data)
    {
        root->left = delete(root->left, x);
        if (balance_factor(root) == -2)
        {
            if (balance_factor(root->right) <= 0)
            {
                root = rotate_left(root);
            }
            else
            {
                root->right = rotate_right(root->right);
                root = rotate_left(root);
            }
        }
    }
    else
    {
        if (root->right != NULL)
        { 
            temp = root->left;
            while (temp->right != NULL)
                temp = temp->right;
 
            root->data = temp->data;
            root->left = delete(root->left, temp->data);
            if (balance_factor(root) == 2)
            {
                if (balance_factor(root->left) >= 0)
                {
                    root = rotate_right(root);
                }
                else
                {
                    root->left = rotate_left(root->left);
                    root = rotate_right(root);
                }
            }
        }
        else
        {
            return (root->left);
        }
    }
    root->ht = height(root);
    return (root);
}
