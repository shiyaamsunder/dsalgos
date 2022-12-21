#pragma once

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
