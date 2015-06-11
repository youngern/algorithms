/*Implements stack using linked list*/

#include <stdio.h>
#include <stdlib.h>
#include <String.h>
struct stackElem{
  struct stackElem *prev; /*points to the node before this one*/
  int value;         /*value of current stack element*/
};
struct stackElem *stack; //top of stack
struct stackElem *top; //stack pointer

/* initialize stack */
void createStack(){
  stack = NULL;
  top = stack;
}
/* pushes element on top of stack */
void push(int value){
  top = (struct stackElem *)malloc(sizeof(struct stackElem));
  top->prev = stack;
  top->value = value;
  stack = top;
}
/*
   pops element on top of stack and moves pointer down.
   if empty, returns -1
   if successful, returns value of popped element
*/
int pop(){
  if(stack == NULL){
    return -1;
  }
  int result = stack->value;
  top = stack->prev;
  free(stack);
  stack = top;
  return result;

}
/*
   prints stack, top of stack first
*/
void printStack(){
 struct stackElem *ptr = top;
 while(ptr){
   printf("%d\n", ptr->value);
   ptr = ptr->prev;
 } 
}
int main(int argc, char *argv[]) {
  char a;
  printf("Create stack? y/n\n");
  scanf("%c", &a);
  if(a == 'n'){
     return 0;
  }
  createStack();
  printf("Stack created.\n");
  char input;
  printf("<value>, pop, or exit\n");
  scanf("%s", &input);
  while(strcmp(&input, "exit") != 0){
    if(strcmp(&input, "pop") == 0){
       int popValue = pop();
       if(popValue == -1){
         printf("Stack is empty\n");
       }
       else{
         printf("Current Stack: \n");
         printStack();
       }
      printf("<value>, pop, or exit\n");
      scanf("%s", &input);
    } else { 
      int value = input - 48;
      push(value);
      printf("Current Stack: \n");
      printStack();
      printf("<value>, pop, or exit\n");
      scanf("%s", &input);
    }
  }
}
