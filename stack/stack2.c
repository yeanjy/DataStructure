#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
} node;

typedef struct stack {
  node *top;
} stack;

void initStack(stack **s) {
  *s = malloc(sizeof(stack));
  (*s)->top = NULL;
}

void push(stack **s, int val) {
  node *newtop = malloc(sizeof(node));
  newtop->val = val;
  newtop->next = (*s)->top;
  (*s)->top = newtop;
}

int pop(stack **s) {
  int result = (*s)->top->val;
  node *temp = (*s)->top;
  (*s)->top = (*s)->top->next;
  free(temp);
  printf("%d\n", result);
  return result;
}

int main() {
  stack *s;
  initStack(&s);
  push(&s, 4);
  push(&s, 122);
  push(&s, 7);
  push(&s, 100);
  pop(&s);
  pop(&s);
  pop(&s);

  return 0;
}
