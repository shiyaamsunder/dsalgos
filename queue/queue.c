#include <stdio.h>
#include "queue.h"

INTEGER queue[MAX_ELEMENT_SIZE];
CHARACTER queue_c[MAX_ELEMENT_SIZE];

int front = -1, rear = -1;

void enqueue(INTEGER data){
  if(is_full()) {
    printf("\nQueue is full. Can't enqueue\n");
    return;
  }
  if(is_empty()){
    front = 0;
  }
  queue[++rear]=data;
}

void dequeue(){
  if(is_empty()) {
    printf("\nQueue is empty. Can't dequeue\n");
    return;
  }
  front++;
  if(front==rear) make_empty();
}


int is_empty(){
  if(front==-1 && rear==-1) return 1;
  return 0;
}
int is_full(){
  if(rear==MAX_ELEMENT_SIZE) return 1;
  return 0;
}

void make_empty(){
  front=rear=-1;
}

void display(){
 if(rear == -1){
      printf("\nQueue is Empty!!!\n");
      return;
 }
  for(int i = rear; i>=front; i--){
    printf("| %d |", queue[i]);
  }
}
