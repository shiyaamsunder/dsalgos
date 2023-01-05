#include <stdio.h>
#include <stdlib.h>
#include <linear_probing.h>

int main(){
    int size, c;

    printf("Enter hash table size: ");

    scanf_s("%d", &size);

    int* h_table = create_hash_table(size);

    do{
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print\n");

        printf("Enter choice: ");
        scanf_s("%d", &c);
        switch (c) {

            case 1: 
                {
                    int ele;
                    printf("Enter a value: ");
                    scanf_s("%d", &ele);

                    if(insert(ele, 11, h_table, size)>0){
                        printf("Inserted\n\n");
                    }
                    else{
                        fprintf(stderr, "ERROR: Cannot insert the value\n\n" );
                    }
                }
                break;

            case 2: 
                {
                    int ele;
                    printf("Enter a value: ");
                    scanf_s("%d", &ele);

                    if(delete(ele, 11, h_table, size)>0){
                        printf("Deleted\n\n");
                    }
                    else{
                        fprintf(stderr, "ERROR: Value not found\n\n" );
                    }
                }
                break;
            case 3:
                print_table(h_table, size);
                break;
            case 0:
                exit(0);
            default:
                    fprintf(stderr,"Input ERROR: Enter valid option\n\n");

        }
    }

    while(c!=0);
}
