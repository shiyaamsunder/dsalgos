#pragma warning(disable:4996)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_QUEUE_LENGTH 50

typedef struct node{
  int data;
  struct node* next;
} node;


typedef node* pNode;

pNode front = NULL;
pNode rear = NULL;

void enqueue(int);
void dequeue();
void display();
bool is_empty();
bool is_full();

pNode create_node(int);

int LENGTH=0;

int main(){
  system("cls");
  int choice;

  do{
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("Enter choice: (1/2/3): ");

    scanf("%d", &choice);

    switch(choice)
    {

      case 1:
        {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        enqueue(data);
        }
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 0:
        exit(0);
        break;
      default:
        printf("Enter the default option\n");

    }

  }while(choice!=0);
  return 0;
}


pNode create_node(int data){
  pNode nn = (pNode)malloc(sizeof(node));
  nn->data=data;
  return nn;
}
void enqueue(int data){
  if(is_full())
  {
    printf("Queue is full\n");
    return;
  }

  pNode nn = create_node(data);
  nn->next=NULL;

  if(front == NULL)
  {
    front=rear=nn;
  }
  else{
    rear->next=nn;
    rear=nn;
  }

  LENGTH++;
  printf("Queued!\n");
}

void dequeue()
{
  if(is_empty()){
    printf("Queue is empty\n");
    return;
  }

  if(front == rear){
    front=rear=NULL;
    return;
  }

  pNode temp = front;
  front = front->next;
  free(temp);
  LENGTH--;
  printf("Dequeued!\n");
}

bool is_empty(){
  return (front == NULL) && (rear == NULL); 
}

bool is_full(){
  return (LENGTH - 1 == MAX_QUEUE_LENGTH);
}

void display(){
  if(is_empty())
  {
    printf("Queue is empty\n");
    return;
  }

  pNode temp = front;
  while(temp->next != NULL){
    printf("%d ", temp->data);
    temp=temp->next;
  }
  printf("%d \n", temp->data);

}
