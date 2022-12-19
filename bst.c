#include <stdio.h>
#include <stdlib.h>

typedef struct _node node;
typedef node* node_ptr;
struct _node
{
    int data;
    node_ptr left;
    node_ptr right;
};


node_ptr create_node(int data);
void insert(node_ptr* tree, int data);
void del_tree(node_ptr tree);
node_ptr del_node(node_ptr root, int data);
node_ptr search(node_ptr* tree, int data);
void print_preorder(node_ptr tree);
node_ptr min_val_node(node_ptr node);

int main(){
  system("cls");
  node_ptr root = NULL;
  int c;
  do
  {
    printf("\n1. Insert");
    printf("\n2. Search");
    printf("\n3. Print the elements");
    printf("\n4. Delete a node.");
    printf("\n\nEnter '0' to quit.");
    printf("\n\nEnter choice: ");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
      {
        int ele;
        printf("Enter element: ");
        scanf("%d", &ele);
        insert(&root, ele);
        break;
      }
    case 2:
      {
        int ele;
        printf("Enter element: ");
        scanf("%d", &ele);
        node_ptr n = search(&root, ele);
        if(n!=NULL){
          printf("Element found!\n");
        }
        else{
          printf("Element not found\n");
        }
        break;
      }
    case 3:
      print_preorder(root);
      break;
    case 4:
    {

      int ele;
      printf("Enter a node to be deleted: ");
      scanf("%d", &ele);
      del_node(root, ele);
      break;
    }
    default:
      break;
    }
  }
  while(c!=0);
}

node_ptr create_node(int data){
  node_ptr nn = malloc(sizeof(node)); 
  nn->left=NULL;
  nn->right=NULL;
  nn->data=data;
  return nn;
}

void insert(node_ptr* tree, int data)
{
  node_ptr temp = NULL;
  if(!(*tree)){
    temp = create_node(data);
    *tree=temp;
    printf("Inserted\n");
    return;
  }

  if(data < (*tree)->data){
    insert(&(*tree)->left, data);
  }else if (data > (*tree)->data){
    insert(&(*tree)->right, data);
  }
}

node_ptr search(node_ptr* tree, int data){
  if(!(*tree)){
    return NULL;
  }

  if(data == (*tree)->data){
    return *tree;
  }else if(data < (*tree)->data){
    search(&(*tree)->left, data);
  }else if (data > (*tree)->data){
    search(&(*tree)->right, data);
  }
}
void print_preorder(node_ptr tree)
{
  if (tree)
  {
    printf("%d\n", tree->data);
    print_preorder(tree->left);
    print_preorder(tree->right);
  }
}

void del_tree(node_ptr tree){
  if(tree){
    tree->left=NULL;
    tree->right=NULL;
    free(tree);
  }
}
node_ptr min_val_node(node_ptr node)
{
    node_ptr current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}


node_ptr del_node(node_ptr root, int data){
  if(root==NULL)return root;

  if(data < root->data){
    root->left = del_node(root->left, data);
  }
  else if(data > root->data){
    root->right = del_node(root->right, data);
  }
  else{
      if (root->left == NULL) {
            node_ptr temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            node_ptr temp = root->left;
            free(root);
            return temp;
        }
        node_ptr temp = min_val_node(root->right);
        root->data = temp->data;
        root->right = del_node(root->right, temp->data);
    }
    return root;  
}
