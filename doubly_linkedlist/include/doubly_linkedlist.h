#pragma once

typedef struct node* node_ptr;
typedef struct node
{
  node_ptr prev;
  int data;
  node_ptr next;
} node;


void insert_at_start(node_ptr*, int);
void insert_at_end(node_ptr*, int);
void insert_at_pos(node_ptr*, int, int);
void insert_after(node_ptr*, int, int);
void insert_before(node_ptr*, int, int);

void delete_at_start(node_ptr*);
void delete_at_end(node_ptr*);
void delete_at_pos(node_ptr*, int);
void delete_after(node_ptr*, int);
void delete_before(node_ptr*, int);

void search(node_ptr*, int);
void print_list(node_ptr*);

node_ptr create_node(int);
