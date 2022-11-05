#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

pNode HEAD;
int length=0;
pNode createNode(int data){
  return (pNode)(malloc(sizeof(pNode)));
}


void insertAtEnd(int data){
  pNode nn;
  nn = createNode(data);
  nn->data=data;
  nn->next=NULL;
  if(HEAD==NULL){
    HEAD=nn;
  }
  else {
    pNode temp=HEAD;
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=nn;
  }

  length++;
  printf("\nInsertion at end successfull!\n");
}


void insertAtPosition(int data, int pos){
  
  pNode nn;
  nn=createNode(data);

  if(HEAD==NULL){
    printf("\nThe list is empty can't insert in position %d.\nInserting at the start\n", pos);
    return;
  }

  if(pos > length || pos <= 0){
    printf("\nEnter valid position\nLength of the list %d\n", length);
    return;
  }

  if(pos==1){
    insertAtStart(data);
    return;
  }

  int tempLength=1;
  pNode temp=HEAD->next;
  pNode prev=HEAD;
  nn->data=data;
  while(++tempLength<pos){
    prev=prev->next;
    temp=temp->next;
  }

  prev->next=nn;
  nn->next=temp;
  printf("\nInsertion at position %d successfull!\n", pos);

}

void insertAtStart(int data){
  pNode nn;
  nn = createNode(data);
  nn->data=data;
  if(HEAD==NULL){
    nn->next=NULL;
    HEAD=nn;
  }else{
    nn->next = HEAD;
    HEAD=nn;
  }
  
  length++;
  printf("\nInsertion at start successfull!\n");

}


void deleteAtStart(){
  if(HEAD==NULL){
    printf("The list is empty\n");
    return;
  }

  pNode temp=HEAD;
  HEAD=HEAD->next;
  free(temp);
  length--;

  printf("\nDeletion at start successfull!\n");
}

void deleteAtEnd(){
  if(HEAD==NULL){
    printf("The list is empty\n");
    return;
  }

  pNode temp=HEAD->next;
  pNode prev=HEAD;
  while(temp->next!=NULL){
    prev=temp;
    temp=temp->next;
  }

  prev->next=NULL;
  free(temp);
  length--;
  printf("\nDeletion at end successfull!\n");


}

void deleteAtPosition(int pos){

  if(pos > length || pos <= 0){
    printf("\nEnter valid position\nLength of the list %d\n", length);
    return;
  }
  if(pos==1){
    deleteAtStart();
    return;
  }

  int tempLength=1;
  pNode temp=HEAD->next;
  pNode prev=HEAD;
  while(++tempLength<pos){
    prev=prev->next;
    temp=temp->next;
  }

  prev->next=temp->next;
  temp->next=NULL;
  length--;
  free(temp);


  printf("\nDeletion at position %d successfull!\n", pos);
}

void printLinkedList(){


  if(HEAD==NULL) printf("\nList is empty\n");

  else {
  pNode temp=HEAD;
    printf("\n");
    while(temp->next != NULL){
      printf("| %d | -> ", temp->data);
      temp=temp->next;
    }
      printf("| %d | ->  NULL\n", temp->data);
  }
}
