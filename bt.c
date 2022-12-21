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
node_ptr delete(node_ptr root, int data);
int height(node_ptr root);
node_ptr min_val_node(node_ptr node);


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
      int ele;
      printf("Enter the value to be deleted: ");
      scanf("%d", &ele);
      delete(root,ele);
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


node_ptr delete(node_ptr root, int data){
  if(root==NULL) return NULL;

  if(root->data==data){
    if(root->right == NULL && root->left == NULL){
      free(root);
      return NULL;
    }
    else if(root->left == NULL){
      node_ptr temp = root;
      temp=root->right;
      free(root);
      return temp;
    }
    else if(root->right == NULL){
      node_ptr temp = root;
      temp=root->left;
      free(root);
      return temp;
    }
    else{
      node_ptr temp = min_val_node(root);
      root->data = temp->data;
      root->right = delete(root->right, temp->data);
      free(temp);
    }
  }
  root->left = delete(root->left, data);
	root->right = delete(root->right, data);
	return root;

}
node_ptr min_val_node(node_ptr node)
{
    node_ptr current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
