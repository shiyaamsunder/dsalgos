#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <binary.h>


int main()
{

    system("cls");
    int c;
    node_ptr root = NULL;
    root = create();

    do
    {

        printf("\n1. Print in Inorder");
        printf("\n2. Print in Preorder");
        printf("\n3. Print in Postorder");

        printf("\n\nEnter '0' to quit.");
        printf("\n\nEnter choice: ");
        scanf("%d", &c);


        switch (c) {
            case 1:
                inorder(root);
            case 2:
                preorder(root);
            case 3:
                postorder(root);
            default:
                break;
        }
    }
    while(c!=0);

}
