
#include <stdio.h>
#include <string.h>
#include "queue.h"




int main(){
  int c;
  printf("\n=================== QUEUE IMPLEMENTATION USING ARRAYS ============================");
  do{


    printf("\n===================================================================================");
    printf("\n1. Enqueue");
    printf("\n2. Dequeue");
    printf("\n3. Display");

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
          enqueue(ele);
          break;

        }
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
    }

  }

  while(c!=0);


  return 0;
}
