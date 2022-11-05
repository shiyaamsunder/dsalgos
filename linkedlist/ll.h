#ifndef LL_H
#define LL_H

#include <stdio.h>
struct Node {
  int data;
  struct Node* next;
};
typedef struct Node *pNode;


pNode createNode(int data);

void insertAtStart(int data);
void insertAtEnd(int data);
void insertAtPosition(int data, int pos);

void deleteAtStart();
void deleteAtEnd();
void deleteAtPosition(int pos);

void printLinkedList();





#endif
