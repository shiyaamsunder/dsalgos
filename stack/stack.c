#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "stack.h"

Stack create_stack(int max)
{

  if(max<MIN_ELEMENT_SIZE){
    printf("\nThe size is too small, minimum size is %d\n", MIN_ELEMENT_SIZE);
    return 0;
  }



  Stack s = (Stack)malloc(sizeof (Stack));
  if(s == NULL){
    printf("\nError: OUT OF SPACE!!\n");
  }

  s->arr = (INTEGER *)malloc(sizeof(INTEGER) * max);

  if(s->arr == NULL){
    printf("\nError: OUT OF SPACE!!\n");
    return 0;
  }

  s->capacity = max;

  make_empty(s);

  return s;
}

StackC create_stack_c(int max)
{

  if(max<MIN_ELEMENT_SIZE){
    printf("\nThe size is too small, minimum size is %d\n", MIN_ELEMENT_SIZE);
    return 0;
  }

  StackC s = (StackC)malloc(sizeof (StackC));
  if(s == NULL){
    printf("\nError: OUT OF SPACE!!\n");
  }

  if(s->arr == NULL){
    printf("\nError: OUT OF SPACE!!\n");
    return 0;
  }

  s->capacity = max;

  make_empty_c(s);

  return s;
}
void dispose_stack(Stack s)
{
  if(s!=NULL)
  {
    free(s->arr);
    free(s);
  }
}

void make_empty(Stack s){
  s->topOfStack = EMPTY_TOS;
}

void make_empty_c(StackC s){
  s->topOfStack = EMPTY_TOS;
}
bool is_empty(Stack s){
  return s->topOfStack == EMPTY_TOS;
}

bool is_empty_c(StackC s){
  return s->topOfStack == EMPTY_TOS;
}
bool is_full(Stack s){
  return s->topOfStack == s->capacity-1;
}

bool is_full_c(StackC s){
  return s->topOfStack == s->capacity-1;
}
void push(Stack s, INTEGER element){
  if(is_full(s)){
    printf("\nSTACK_OVERFLOW!!, no space for new elements\n");
  }
  else {
    s->arr[++s->topOfStack]=element;
  }
}

void push_c(StackC s, CHARACTER element){
  if(is_full_c(s)){
    printf("\nSTACK_OVERFLOW!!, no space for new elements\n");
  }
  else {
    s->arr[++s->topOfStack]=element;
  }
}
INTEGER pop(Stack s)
{
  if(is_empty(s))
  {
    printf("\nSTACK_UNDERFLOW!!, there are no elements to pop\n");
    return -1;
  }
  else {
    return s->arr[s->topOfStack--];
  }
}


CHARACTER pop_c(StackC s)
{
  if(is_empty_c(s))
  {
    printf("\nSTACK_UNDERFLOW!!, there are no elements to pop\n");
    return '!';
  }
  else {
    return s->arr[s->topOfStack--];
  }
}
void pop_print(Stack s)
{
  if(is_empty(s))
  {
    printf("\nSTACK_UNDERFLOW!!, there are no elements to pop\n");
  }
  else {
    s->topOfStack--;
    printf("\nPop successfull\n"); 
  }
}

void pop_print_c(StackC s)
{
  if(is_empty_c(s))
  {
    printf("\nSTACK_UNDERFLOW!!, there are no elements to pop\n");
  }
  else {
    s->topOfStack--;
    printf("\nPop successfull\n"); 
  }
}
void top_print(Stack s){
  if(!is_empty (s))
  {
      printf("\nTop Element: %d\n", s->arr[s->topOfStack]);
      return;
  }
  printf("\nEmpty Stack\n");
}

void top_print_c(StackC s){
  if(!is_empty_c(s))
  {
      printf("\nTop Element: %c\n", s->arr[s->topOfStack]);
      return;
  }
  printf("\nEmpty Stack\n");
}

void top_pop_print(Stack s) {
  if(!is_empty(s))
  { 
      printf("\nPopped value: %d\n", s->arr[s->topOfStack--]);
  }
  else{
    printf("\nSTACK_UNDERFLOW!!, there are no elements to pop\n");
  }
}
void top_pop_print_c(StackC s) {
  if(!is_empty_c(s))
  { 
      printf("\nPopped value: %c\n", s->arr[s->topOfStack--]);
  }
  else{
    printf("\nSTACK_UNDERFLOW!!, there are no elements to pop\n");
  }
}
