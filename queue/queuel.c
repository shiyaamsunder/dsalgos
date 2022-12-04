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


void enqueue(pNode* head, int data);
void dequeue(pNode* head);
void display(pNode*);
bool is_empty();
bool is_full();


int LENGTH=0;
int main(){
  int choice;
  pNode head = (pNode)malloc(sizeof(node));

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
        enqueue(&head, data);
        }
        break;
      case 2:
        dequeue(&head);
        break;
      case 3:
        display(&head);
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


void enqueue(pNode* head, int data)
{
  if(is_full())
  {
    printf("Queue is full!\n");
    return;
  }
  pNode nn = (pNode)malloc(sizeof(struct node));
  nn->data = data;

  if(is_empty()){
    nn->next = NULL;
    LENGTH=1;
    *head=nn;
    return;
  }
  nn->next = *head;
  *head=nn;
  LENGTH++;
  printf("Enqueued\n");
}

void dequeue(pNode* head){
  if(is_empty())
  {
    printf("Queue is empty!\n");
    return;
  }

  if(LENGTH==1){
    LENGTH=0;
    return;
  }
  pNode temp=*head;
  pNode prev;
  while(temp->next!=NULL){
    prev=temp;
    temp=temp->next;
  }
  prev->next=NULL;
  free(temp);
  LENGTH--;
  printf("Dequeued\n");
}

void display(pNode* head){
  if(is_empty())
  {
    printf("Queue is empty\n");
    return;
  }
  pNode temp=*head;
  int i=1;
  while(i<=LENGTH)
  {
    printf("%d ", temp->data);
    temp=temp->next;
    i++;
  }
  printf("\n");
}

bool is_full(){
  return LENGTH==MAX_QUEUE_LENGTH;
}

bool is_empty(){
  return LENGTH==0;
}
