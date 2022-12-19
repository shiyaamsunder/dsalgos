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

node_ptr create();
void inorder(node_ptr root);
void preorder(node_ptr root);
void postorder(node_ptr root);
void levelorder(node_ptr root);
void delete(int data);
int height(node_ptr root);


int main(){
  system("cls");
  node_ptr root = NULL;
  int c;
  do
  {
    printf("\n1. Insert");
    printf("\n2. Print in inorder");
    printf("\n3. Print in preorder");
    printf("\n4. Print in postorder");
    printf("\n5. Delete a node.");
    printf("\n6. Height of the tree");
    printf("\n\nEnter '0' to quit.");
    printf("\n\nEnter choice: ");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
      {
        root = create();
        break;
      }
    case 2:
      inorder(root);
      break;
    case 3:
      preorder(root);
      break;
    case 4:
      postorder(root);
      break;
    case 5:
      printf("\nTO BE IMPLEMENTED\n");
      // TODO: Implement delete a node
      // delete(int data);
      break;

    case 6:
      printf("Height of the tree is: %d", height(root));
      break;
    default:
      printf("\nEnter a valid option\n");
      break;
    }
  }
  while(c!=0);
  return 0;
}

node_ptr create(){
  int value;
  node_ptr nn = malloc(sizeof(node));
  scanf("%d", &value);
  nn->data=value;
  if(value==-1) return 0;
  printf("Enter the value for the left child of %d: ", value);
  nn->left = create();
  printf("Enter the value for the right child of %d: ", value);
  nn->right = create();
  return nn;
}


void inorder(node_ptr root){
  if(root==NULL) return;
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

void postorder(node_ptr root){
  if(root==NULL) return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}

void preorder(node_ptr root){
  if(root==NULL) return;
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void levelorder(node_ptr root){
  if(root==NULL) return;
  printf("%d ", root->data);
}

int height(node_ptr root){
  if(root==NULL) return 0;
  int lheight = height(root->left);
  int rheight = height(root->right);

  if(lheight > rheight){
    return (lheight + 1);
  }else
  {
    return (rheight + 1);
  }

}
