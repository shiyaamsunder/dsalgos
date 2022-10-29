#include <stdio.h>
#include <string.h>
#include "stack.h"



void Stack();

void infixToPostfix();

int main(){
  Stack();
  return 0;
}




void Stack(){

  int c;
  pStack pStack=NULL;

  printf("\n=================== STACK IMPLEMENTATION USING ARRAYS ============================");
  if(pStack==NULL){
    printf("\nCreate a new Stack with n elements.");
    int max;
    printf("\nEnter the maximum elements to be initialized with: ");
    scanf("%d", &max);

    pStack = create_stack(max);
  }
  do{


    printf("\n===================================================================================");
    printf("\n1. Push a new element on to the stack.");
    printf("\n2. Pop the top element off.");
    printf("\n3. Print the top of stack.");
    printf("\n4. Pop and print the top element.");

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
          push(pStack, ele);
          break;

        }

      case 2:
        pop_print(pStack);
        break;
      case 3:
        top_print(pStack);
        break;
      case 4:
        top_pop_print(pStack);
        break;
    }

  }

  while(c!=0);


  if(pStack == NULL) return;
  printf("\nDeleting the stack from memory!");
  dispose_stack(pStack);
  printf("\nDeleted Stack. Exiting program\n"); 
}

