#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <bst.h>


int main(){
  system("cls");
  node_ptr root = NULL;
  int c;
  do
  {
    printf("\n1. Insert");
    printf("\n2. Search");
    printf("\n3. Print the elements");
    printf("\n4. Delete a node.");
    printf("\n\nEnter '0' to quit.");
    printf("\n\nEnter choice: ");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
      {
        int ele;
        printf("Enter element: ");
        scanf("%d", &ele);
        insert(&root, ele);
        break;
      }
    case 2:
      {
        int ele;
        printf("Enter element: ");
        scanf("%d", &ele);
        node_ptr n = search(&root, ele);
        if(n!=NULL){
          printf("Element found!\n");
        }
        else{
          printf("Element not found\n");
        }
        break;
      }
    case 3:
      print_preorder(root);
      break;
    case 4:
    {

      int ele;
      printf("Enter a node to be deleted: ");
      scanf("%d", &ele);
      del_node(root, ele);
      break;
    }
    default:
      break;
    }
  }
  while(c!=0);
}
