#include <stdio.h>
#include <stdlib.h>

#include "ll.h"


int main(){
  int c;

  printf("\n=================== LINKED LIST ============================");

  do{


    printf("\n===================================================================================");
    printf("\n1. Insert at start.");
    printf("\n2. Insert at end.");
    printf("\n3. Insert at specific position.");
    printf("\n4. Delete at start.");
    printf("\n5. Delete at end.");
    printf("\n6. Delete at specific position.");
    printf("\n7. Print");

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
          insertAtStart(ele);
          break;

        }

      case 2:
        {
          int ele;
          printf("Enter the element: ");
          scanf("%d", &ele);
          insertAtEnd(ele);
          break;

        }

      case 3:
        {
          int ele, pos;
          printf("Enter the element: ");
          scanf("%d", &ele);
          printf("Enter the postion: ");
          scanf("%d", &pos);
          insertAtPosition(ele,pos);
          break;

        }
      case 4:
        deleteAtStart();
        break;
      case 5:
        deleteAtEnd();
        break;
      case 6:
        {
          int pos;
          printf("Enter the postion: ");
          scanf("%d", &pos);
          deleteAtPosition(pos);
        }
        break;

      case 7:
        printLinkedList();
        break;
    }

  }

  while(c!=0);

}
