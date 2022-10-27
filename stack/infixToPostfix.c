#include <stdio.h>
#include <ctype.h>
#include "stack.h"


int precedence(char c);

void *infixToPostfix(char *c);

int main(){
  printf("Infix to Postfix\n");

  char exp[100];

  char *c;
  printf("Enter the expression: ");
  scanf("%s", exp);

  c=exp;

  StackC s=NULL; 
  char x;
  s=create_stack_c(100);
  while(*c != '\0'){
    if(isalnum(*c))
      printf("%c ", *c);
    else if(*c == '(')
      push_c(s, *c);
    else if(*c == ')')
    {
      while((x=pop_c(s) != '('))
        printf("%c ", x);

    }
    else 
    {
      while(precedence(s->arr[s->topOfStack]) >= precedence(*c))
        printf("%c ", pop_c(s));
      push_c(s, *c);
    }
    c++;

  }

  while(s->topOfStack !=-1)
  {
    printf("%c ", pop_c(s));
  }
  return 0;
}


int precedence(char c){
  if(c=='^')
    return 3;
  if(c == '-' || c == '/')
    return 2;
  if(c == '+' || c == '*')
    return 1;
  return 0;
}

