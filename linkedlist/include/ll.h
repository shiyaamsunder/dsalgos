#ifndef LL_H
#define LL_H
typedef struct node
{
  int data;
  struct node *next;
} node;

typedef struct node *pNode;


void insert_at_start(pNode *, int);
void insert_at_end(pNode *, int);
void insert_at_pos(pNode *, int, int);
void insert_after(pNode *, int, int);
void insert_before(pNode *, int, int);

void delete_at_start(pNode *);
void delete_at_end(pNode *);
void delete_at_pos(pNode *, int);
void delete_after(pNode *, int);
void delete_before(pNode *, int);

void search(pNode *, int);
void print_list(pNode *);

pNode create_node(int);
#endif
