#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

typedef struct Stack Stack;

Stack* create_stack(unsigned capacity){
    Stack* stack
        = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array
        = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int is_full(Stack* stack){
    return stack->top == stack->capacity -1;
}

int is_empty(Stack* stack){
    return stack->top == -1;
}

void push(Stack* stack, char c){
    if(is_full(stack))
        return;
    stack->array[++stack->top] = c;
}

int pop(Stack* stack){
    if(is_empty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

void reverse(char* str){
    int n = strlen(str);

    Stack* stack = create_stack(n);

    int i;
    for(i=0; i<n; i++)
        push(stack, str[i]);

    for(i=0; i<n; i++)
        str[i] = pop(stack);
}


int main(){

    printf("Enter a string: ");

    char str[MAX];

    fgets(str, MAX, stdin);
    reverse(str);
    printf("Reversed: %s\n", str);
}
