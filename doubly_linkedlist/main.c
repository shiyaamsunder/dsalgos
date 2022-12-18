#define _CRT_SECURE_NO_WARNINGS // disable the scanf unsecure warnings
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "doubly_linkedlist.h"

int main()
{
    system("cls");
    int c;

    node_ptr HEAD = NULL;

    do
    {
        printf("\n1. Insert at start.");
        printf("\n2. Insert at end.");
        printf("\n3. Insert at a specific position.");
        printf("\n4. Insert after a specific position.");
        printf("\n5. Insert before a specific position.");
        printf("\n6. Delete at start.");
        printf("\n7. Delete at end.");
        printf("\n8. Delete at a specific position.");
        printf("\n9. Delete after a specific position.");
        printf("\n10. Delete before a specific position.");
        printf("\n11. Search");
        printf("\n12. Print");

        printf("\n\nEnter '0' to quit.");
        printf("\n\nEnter choice: ");
        scanf("%d", &c);

        switch (c)
        {
            case 1:
                {
                    int ele;
                    printf("Enter the element: ");
                    scanf("%d", &ele);
                    insert_at_start(&HEAD, ele);
                    break;
                }

            case 2:
                {
                    int ele;
                    printf("Enter the element: ");
                    scanf("%d", &ele);
                    insert_at_end(&HEAD, ele);
                    break;
                }

            case 3:
                {
                    int ele, pos;
                    printf("Enter the element: ");
                    scanf("%d", &ele);
                    printf("Enter the position: ");
                    scanf("%d", &pos);
                    insert_at_pos(&HEAD, ele, pos);
                    break;
                }

            case 4:
                {
                    int ele, pos;
                    printf("Enter the element: ");
                    scanf("%d", &ele);
                    printf("Enter the postion: ");
                    scanf("%d", &pos);
                    insert_after(&HEAD, ele, pos);
                    break;
                }
            case 5:
                {
                    int ele, pos;
                    printf("Enter the element: ");
                    scanf("%d", &ele);
                    printf("Enter the postion: ");
                    scanf("%d", &pos);
                    insert_before(&HEAD, ele, pos);
                    break;
                }
            case 6:
                delete_at_start(&HEAD);
                break;
            case 7:
                delete_at_end(&HEAD);
                break;

            case 8:
                {
                    int pos;
                    printf("Enter the position: ");
                    scanf("%d", &pos);
                    delete_at_pos(&HEAD, pos);
                    break;
                }
            case 9:
                {
                    int pos;
                    printf("Enter the postion: ");
                    scanf("%d", &pos);
                    delete_after(&HEAD, pos);
                    break;
                }

            case 10:
                {
                    int pos;
                    printf("Enter the postion: ");
                    scanf("%d", &pos);
                    delete_before(&HEAD, pos);
                    break;
                }

            case 11:
                {
                    int ele;
                    printf("Enter the element: ");
                    scanf("%d", &ele);
                    search(&HEAD, ele);
                    break;
                }
            case 12:
                print_list(&HEAD);
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("\nEnter valid option\n");
        }

    } while (c != 0);
    return 0;
}
