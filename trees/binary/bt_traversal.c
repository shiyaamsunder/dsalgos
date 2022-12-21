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
node_ptr search(node_ptr* tree, int data);
void print_preorder(node_ptr tree);
void print_postorder(node_ptr tree);
void print_inorder(node_ptr tree);

int main(){
  system("cls");
  node_ptr root = NULL;
  int c;
  do
  {
    printf("\n1. Insert");
    printf("\n2. Search");
    printf("\n3. Print the elements in pre order");
    printf("\n4. Print the elements in post order");
    printf("\n5. Print the elements in in order");
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
      print_postorder(root);
      break;
    case 5:
      print_inorder(root);
      break;
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

void print_inorder(node_ptr tree){
  if(tree){
    print_inorder(tree->left);
    printf("%d\n", tree->data);
    print_inorder(tree->right);
  }
}

void print_postorder(node_ptr tree){
  if(tree){
    print_postorder(tree->left);
    print_postorder(tree->right);
    printf("%d\n", tree->data);
  }
}

void del_tree(node_ptr tree){
  if(tree){
    tree->left=NULL;
    tree->right=NULL;
    free(tree);
  }
}
