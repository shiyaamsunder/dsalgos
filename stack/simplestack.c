#include <stdio.h>

#define MAX 50
#define EMPTY_TOS -1


void push(int data);
void pop();
void peek();
void peekAndPop();
void display();
int isEmpty();
int isFull();


int top=EMPTY_TOS;
int stack[MAX];

int main(){
  int c;
  do{
    printf("\n===================================================================================");
    printf("\n1. Push a new element on to the stack.");
    printf("\n2. Pop the top element off.");
    printf("\n3. Print the top of stack.");
    printf("\n4. Pop and print the top element.");
    printf("\n5. Display the stack.");

    printf("\n\nEnter '0' to quit.");
    printf("\n===================================================================================");
    printf("\n\nEnter choice: ");
    scanf("%d", &c);


    switch(c){
      case 1:
        {
          int ele;
          printf("Enter the element: ");
          scanf("%d", &ele);
          push(ele);
          break;

        }

      case 2:
        pop();
        break;

      case 3:
        peek();
        break;

      case 4:
        peekAndPop();
        break;

      case 5:
        display();
        break;

      case 0:
        break;
      default:
        printf("\nWrong option. Select again\n");

    }
  }

  while(c!=0);

  return 0;
}


void push(int data){
  if(isFull()) {
    printf("Stack over flow, no space for new elements\n");
    return;
  }
  else{
    stack[++top] = data;
  }
}

void pop(){
  if(isEmpty()){
    printf("Stack underflow, the stack is empty\n");
    return;
  }
  else{
    top--;
  }
}

int isFull(){
  return top==MAX-1;
}

int isEmpty(){
  return top==EMPTY_TOS;
}

void peek(){
  if(isEmpty()){
    printf("Stack is empty\n");
    return;
  }
  printf("\nTop of the element is: %d\n", stack[top]);

}

void peekAndPop(){
  peek();
  pop();
}


void display(){
  for(int i=top; i>=0; i--)
  {
    if(i==0) {
      printf("| %d |\n", stack[i]);
      printf("'----'");
    }
    else printf("| %d |\n", stack[i]);
  }
}
