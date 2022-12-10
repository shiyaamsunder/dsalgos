#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ll.h"
#pragma warning(disable: 4996) // disable the insecure warnings

int LENGTH = 0;

pNode create_node(int data)
{
  pNode nn = (pNode)(malloc(sizeof(struct node)));
  nn->data = data;
  return nn;
}

void insert_at_start(pNode *head, int data)
{
  pNode nn = create_node(data);
  if (*head == NULL)
  {
    nn->next = NULL;
    *head = nn;
  }
  else{
    nn->next = *head;
    *head = nn;
  }

  LENGTH++;
  printf("Inserted!\n");
}

void insert_at_end(pNode *head, int data)
{
  pNode nn = create_node(data);
  nn->next = NULL;

  if (*head == NULL)
  {
    *head = nn;
  }
  else
  {
    pNode temp = *head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = nn;
  }
  LENGTH++;
  printf("Inserted!\n");
}

void insert_at_pos(pNode *head, int data, int pos){
  insert_before(head, data, pos);
}

void insert_after(pNode *head, int data, int pos)
{
  pNode nn = create_node(data);
  if (*head == NULL)
  {
    nn->next = NULL;
    *head = nn;
    LENGTH++;
    printf("Inserted!\n");
  }
  else
  {
    if (pos == LENGTH)
    {
      insert_at_end(head, data);
      LENGTH++;
      printf("Inserted!\n");
    }
    else if (pos > LENGTH || pos < 0)
    {
      printf("\nEnter valid position. Size of the list is %d\n", LENGTH);
    }
    else
    {

      pNode temp = *head;
      for (int i = 0; i < pos - 1; i++)
      {
        temp = temp->next;
      }
      nn->next = temp->next;
      temp->next = nn;
      LENGTH++;
      printf("Inserted!\n");
    }
  }
}

void insert_before(pNode *head, int data, int pos)
{
  pNode nn = create_node(data);
  if (*head == NULL)
  {
    *head = nn;
    LENGTH++;
  }

  else
  {
    if (pos == 1)
    {
      insert_at_start(head, data);
    }
    else if (pos > LENGTH || pos < 0)
    {
      printf("\nEnter valid position. Size of the list is %d\n", LENGTH);
      return;
    }
    else
    {
      pNode temp = *head;
      for (int i = 1; i < pos - 1; i++)
      {
        temp = temp->next;
      }
      nn->next = temp->next;
      temp->next = nn;
    }
    printf("Inserted!\n");
  }
  LENGTH++;

}

void delete_at_start(pNode* head){

  if (*head == NULL)
  {
    printf("\nList is Empty\n");
    return;
  }

  pNode temp = *head;
  *head=(*head)->next;
  free(temp);

  LENGTH--;
  printf("Deleted\n");

}

void delete_at_end(pNode* head){
  pNode temp = *head;
  pNode prev;
  if(*head==NULL){
    printf("\nList is Empty\n");
    return;
  }

  if (temp->next == NULL){
    *head = NULL;
    LENGTH--;
    return;
  }
  while (temp->next != NULL)
  {
    prev=temp;
    temp = temp->next;
  }

  prev->next = NULL;
  free(temp);
  LENGTH--;
  printf("Deleted\n");
}

void delete_at_pos(pNode *head, int pos)
{
  if (*head == NULL)
  {
    printf("\nList is Empty\n");
  }
  else
  {
    if (pos == LENGTH)
    {
      printf("There is no element after position %d\n", pos);
    }
    else if (pos > LENGTH || pos < 0)
    {
      printf("\nEnter valid position. Size of the list is %d\n", LENGTH);
    }
    else
    {

      pNode temp = *head;
      pNode prev;
      for (int i = 0; i < pos - 1; i++)
      {
        prev = temp;
        temp = temp->next;
      }

      prev->next = temp->next;
      free(temp);
      LENGTH--;
      printf("Deleted!\n");
    }
  }
}

void delete_after(pNode* head, int pos){
  if (*head == NULL)
  {
    printf("\nList is Empty\n");
  }
  else
  {
    if (pos == LENGTH)
    {
      printf("There is no element after position %d\n", pos);
    }
    else if (pos > LENGTH || pos < 0)
    {
      printf("\nEnter valid position. Size of the list is %d\n", LENGTH);
    }
    else
    {

      pNode temp = *head;
      pNode prev;
      for (int i = 0; i < pos; i++)
      {
        prev=temp;
        temp = temp->next;
      }

      prev->next = temp->next;
      free(temp);
      LENGTH--;
      printf("Deleted!\n");
    }
  }

}

void delete_before(pNode* head, int pos){
  if(*head == NULL){
    printf("\nList is empty\n");
    return;
  }
  else{
    if(pos == 1){
      printf("\nThere is no element before position 1. Please enter valid position\n");
    }
    else if(pos == 2){
      delete_at_start(head);
    }
    else if (pos > LENGTH || pos < 0)
    {
      printf("\nEnter valid position. Size of the list is %d\n", LENGTH);
    }
    else{
      pNode temp = *head;
      pNode prev;

      for(int i=0; i<pos-2; i++){
        prev=temp;
        temp=temp->next;
      }
      prev->next=temp->next;
      free(temp);
      LENGTH--;
      printf("Deleted!\n");
    }
  }


}

void search(pNode * head, int data){
  pNode temp = *head;

  int i=1;
  bool found=false;
  while(temp!= NULL){
    if(data==temp->data){
      printf("Element found at position %d\n", i);
      found=true; 
      break;
    }

    temp=temp->next;
    i++;
  }
  if(found==false){
    printf("Element not found\n");
  }
} 

void print_list(pNode *head)
{
  if (*head == NULL)
    printf("\nList is empty\n");

  else
  {
    pNode temp = *head;
    printf("\n");
    while (temp->next != NULL)
    {
      printf("| %d | -> ", temp->data);
      temp = temp->next;
    }
    printf("| %d | ->  NULL\n", temp->data);
  }
}
