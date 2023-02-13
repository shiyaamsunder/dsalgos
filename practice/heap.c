#include <stdio.h>
void heapify(int a[], int n){
    for(int i = (n-2) -1; i>=0; i--){
        
        //Left child for i
        int j = 2  * i + 1;

        while(j < n-1){
        
            // compare left and right child
            if(a[j] < a[j+1]){
                j = j+1;
            }

            // compare parent and largest child
            if(a[i] < a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;

                i = j;
                j = 2 * i + 1;
            }
            else {
                break;
            }
        }
    }
}

int delete(int a[], int n){
    int x = a[0];
    a[0] = a[n-1];
    int i =0;
    int j = 2 * i + 1;

    while(j < n-1){

        // compare left and right child
        if(a[j] < a[j+1]){
            j = j+1;
        }

        // compare parent and largest child
        if(a[i] < a[j]){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            i = j;
            j = 2 * i + 1;
        }
        else {
            break;
        }
    }

    return x;

}

int main(){
    int a[] = {5, 10, 30, 20, 35, 40, 15};

    heapify(a, sizeof(a)/sizeof(a[0]));


    for(int i=0; i< sizeof(a)/sizeof(a[0]); i++){
        printf("%d ", a[i]);    
    }

    printf("\n");
    delete(a, sizeof(a)/sizeof(a[0]));

    for(int i=0; i< sizeof(a)/sizeof(a[0] - 1); i++){
        printf("%d ", a[i]);    
    }
}
