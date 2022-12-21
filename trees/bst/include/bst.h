#pragma once

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

