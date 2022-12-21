#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <binary.h>

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
