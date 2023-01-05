#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "ctype.h"

#define MAX_STACK 100

char stack[MAX_STACK];
int top = -1;
int size;

bool is_full(int size)
{
  return top == size - 1;
}

bool is_empty()
{
  return top == -1;
}

int push(char data, char* s, int size)
{
  if (is_full(size))
  {
    fprintf(stderr, "ERROR: Stack is full\n");
    return -1;
  }
  if (isalpha(data) != 2)
  {
    fprintf(stderr, "ERROR: Only char data type is allowed\n");
    return -1;
  }
  else
  {
  }
  if (s[top] == data)
  {
    fprintf(stderr, "ERROR: Consecutive duplicate values not allowed\n");
    return -1;
  }
  s[++top] = data;
  return 0;
}

char pop(char* s)
{
  if (is_empty())
  {
    fprintf(stderr, "ERROR: Stack is empty\n");
    return -1;
  }

  char top_val = s[top];
  top--;
  return top_val;
}

int find_occurences(char* s, char c, int size){
  int count = 0;

  for(int i=0; i<size; i++){
    if(s[i]==c){
      count++;
    }
  }

  return count;
}
int main()
{
  int c;
  system("cls");
  printf("Enter stack size max(100): ");
  scanf("%d", &size);
  do
  {
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Number of occurences of a char\n");
    printf("0. Exit\n");

    printf("Enter choice: ");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
    {
      char ele;
      printf("\nEnter character: ");
      scanf(" %c", &ele);
      if(push(ele, stack, size)!=-1){
        printf("Pushed\n");
      }
      printf("\n");
    }
    break;
    case 2:
    {
      char val = pop(stack);
      if(val!=-1){
        printf("Popped value: %c\n", val);
      }
      printf("\n");
    }
    break;

    case 3:
    {
      char ele;
      printf("\nEnter character: ");
      scanf(" %c", &ele);
      int count = find_occurences(stack, ele, size);
      if(count){
        printf("%c occurs %d times\n", ele, count);
      }
      else{
        printf("%c is not present in the stack\n", ele);
      }
    }
    break;

    default:
      break;
    }

  } while (c != 0);
  return 0;
}