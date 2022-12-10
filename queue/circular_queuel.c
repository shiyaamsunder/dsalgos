#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node
{

  int data;
  struct _node* next;

}node;


typedef node* pNode;

pNode front = NULL;
pNode rear = NULL;

#define MAX_QUEUE_LENGTH 5

void enqueue(int);
void dequeue();
void display();
void search(int);
bool is_empty();
bool is_full();

pNode create_node(int);

int LENGTH = 0;
int main(){
  system("cls");
  int choice;

  do{
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    // printf("4. Search\n");
    printf("Enter choice: (1/2/3/4): ");

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
      // case 4:
      // {
      //   int ele;
      //   printf("Enter element: ");
      //   scanf("%d", &ele);
      //   search(ele);
      //   break;
      // }
      case 0:
        exit(0);
        break;
      default:
        printf("Enter the default option\n");

    }

  }while(choice!=0);
  return 0;
}

void enqueue(int data){
  if(is_full())
  {
    printf("Queue is full\n");
    return;
  }

  pNode nn = create_node(data);
  if(is_empty()){
    front = rear = nn;
    rear->next=front;
  }
  else{
    rear->next = nn;
    rear=nn;
    nn->next=front;
  }
  LENGTH++;
  printf("Enqueued!\n");
}

void dequeue(){
  if(is_empty()){
    printf("Queue is empty\n");
    return;
  }

  pNode temp=front;
  if(front==rear){
    front = rear =NULL;
    free(temp);
  }else{
    front = front->next;
    rear->next = front;
    free(temp);
  }
  LENGTH--;
  printf("Dequeued!\n");
}

bool is_empty(){
  return (front == NULL) && (rear == NULL);
}


bool is_full(){
  return (LENGTH == MAX_QUEUE_LENGTH);
}
void display(){
  if(is_empty())
  {
    printf("Queue is empty\n");
    return;
  }

  pNode temp = front;
  int i=LENGTH;
  while(i>0){
    printf("%d ", temp->data);
    temp=temp->next;
    i--;
  }
  printf("\n");

}


pNode create_node(int data){
  pNode nn = (pNode)malloc(sizeof(node));
  nn->data=data;
  return nn;
}

// void search(int data){
//   if(is_empty())
//   {
//     printf("Queue is empty\n");
//     return;
//   }
//   bool found = false;
//   pNode temp=front;
//   int pos=LENGTH;
//   while(pos > 0){
//     if(temp->data == data){
//       printf("Element found at position at %d\n", pos);
//       found=true;
//       break;
//     }
//     temp=temp->next;
//     pos--;
//   }

//   if(!found){
//     printf("Element not found\n");
//   }
// }