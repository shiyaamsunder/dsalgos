
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>


#define INTEGER int
#define CHARACTER char
#define MIN_ELEMENT_SIZE (5)
#define EMPTY_TOS (-1)

/**
  Structure for a integer type Stack
*/
struct stack_record {
  INTEGER capacity;
  INTEGER topOfStack;
  INTEGER *arr;
};


/**
  Structure for a char type Stack
*/
struct stack_record_c {
  INTEGER capacity;
  INTEGER topOfStack;
  CHARACTER *arr;
};

/** 
  Pointer to a integer type stack_record
*/
typedef struct stack_record *Stack;
/** 
  Pointer to a char type stack_record
*/
typedef struct stack_record_c *StackC;


/** 
  Returns TRUE if the stack is empty.
*/
bool is_empty(Stack s);
/** 
  Returns TRUE if the stack is empty.
*/
bool is_empty_c(StackC s);

/**
  Returns TRUE if the stack is full.
*/
bool is_full(Stack s);
/**
  Returns TRUE if the stack is full.
*/
bool is_full_c(StackC s);

/**
  Deallocates stack from memory.
*/
void dispose_stack(Stack s);
/**
  Deallocates stack from memory.
*/
void dispose_stack_c(StackC s);

/** Function to initialize a stack ADT by allocating needed memory.
    Accepts int as input.
*/
Stack create_stack(int max);

/** Function to initialize a stack ADT by allocating needed memory.
    Accepts char as input.
*/
StackC create_stack_c(int max);

/**
  makes a stack empty by resetting the top value to -1.
*/
void make_empty(Stack s);
/**
  makes a stack empty by resetting the top value to -1.
*/
void make_empty_c(StackC s);

/**
  Push a int type element on to the stack.
*/
void push(Stack s, INTEGER element);
/**
  Push a char type element on to the stack.
*/
void push_c(StackC s, CHARACTER element);

/**
  Pop a int type element from the stack and return the element.
  Returns -1 and prints a message if the stack is empty
*/
INTEGER pop(Stack s);
/**
  Pop a char type element from the stack and return the element.
  Returns '!' and prints a message if the stack is empty
*/
CHARACTER pop_c(StackC s);

/**
  Prints the top element of the stack.
*/
void top(Stack s);
/**
  Prints the top element of the stack.
*/
void top_c(StackC s);

/**
  Removes the top element and prints it.
*/
void pop_print(Stack s);
/**
  Removes the top element and prints a success message.
*/
void pop_print_c(StackC s);

/**
  Removes the top element and prints a success message.
*/
void top_print(Stack s);
/**
  Just prints the top element of the stack.
*/
void top_print_c(StackC s);

/**
  Pop a char type element from the stack and return the element.
*/
void top_pop_print(Stack s);
/**
  Pop a char type element from the stack and return the element.
*/
void top_pop_print_c(StackC s);

#endif
