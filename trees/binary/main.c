#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <binary.h>

int main(){
  system("cls");
  node_ptr root = NULL;
  int c;
  do
  {
    printf("\n1. Insert");
    printf("\n2. Print in inorder");
    printf("\n3. Print in preorder");
    printf("\n4. Print in postorder");
    printf("\n5. Delete a node.");
    printf("\n6. Height of the tree");
    printf("\n\nEnter '0' to quit.");
    printf("\n\nEnter choice: ");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
      {
        root = create();
        break;
      }
    case 2:
      inorder(root);
      break;
    case 3:
      preorder(root);
      break;
    case 4:
      postorder(root);
      break;
    case 5:
      printf("\nTO BE IMPLEMENTED\n");
      int ele;
      printf("Enter the value to be deleted: ");
      scanf("%d", &ele);
      delete(root,ele);
      break;

    case 6:
      printf("Height of the tree is: %d", height(root));
      break;
    default:
      printf("\nEnter a valid option\n");
      break;
    }
  }
  while(c!=0);
  return 0;
}
