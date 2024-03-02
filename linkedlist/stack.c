#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
} node;

typedef struct linkedlist {
  int size;
  node *head;
  node *tail;
} linkedlist;

void init(linkedlist **l) {
  assert(l != NULL && *l != NULL);

  *l = malloc(sizeof(linkedlist));
  (*l)->tail = NULL;
  (*l)->head = NULL;
  (*l)->size = 0;
}

void printList(linkedlist *l) {
  assert(l->head != NULL && l != NULL);

  node *current = l->head;

  while (current != NULL) {
    printf("Current val number: %d\n", current->val);
    current = current->next;
  }
}

void push(linkedlist **l, int val) {
  node *temp = malloc((sizeof(node)));
  temp->val = val;
  temp->next = NULL;

  if ((*l)->head == NULL) {
    (*l)->head = temp;
    (*l)->tail = temp;
    (*l)->size = 1;
  } else {
    (*l)->tail->next = temp;
    (*l)->tail = (*l)->tail->next;
    (*l)->size++;
  }
}

void pop(linkedlist **l) {

  if ((*l)->head == (*l)->tail) {
    free((*l)->head);
    (*l)->head = (*l)->tail = NULL;
    (*l)->size = 0;
    return;
  }

  node *current = (*l)->head;
  while (current->next != (*l)->tail) {
    current = current->next;
  }

  free((*l)->tail);
  (*l)->tail = current;
  (*l)->tail->next = NULL;
  (*l)->size--;
}
int main() {
  linkedlist *l;
  init(&l);
  push(&l, 1);
  push(&l, 2);
  push(&l, 3);
  pop(&l);
  printList(l);
  return 0;
}
