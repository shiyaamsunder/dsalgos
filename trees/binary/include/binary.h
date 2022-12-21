#pragma once

typedef struct _node node;
typedef node* node_ptr;
struct _node {
    int data;
    node_ptr left;
    node_ptr right;
};

node_ptr create_node(int data);
node_ptr create();

node_ptr insert_root(int data);
node_ptr insert_left(node_ptr tree, int data);
node_ptr insert_right(node_ptr tree, int data);

void inorder(node_ptr tree);
void postorder(node_ptr tree);
void preorder(node_ptr tree);
