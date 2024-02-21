#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
} node;

typedef struct linkedlist {
  int size;
  node *head;
} linkedlist;

void init(linkedlist **l) {
  *l = malloc(sizeof(linkedlist));
  (*l)->head = NULL;
  (*l)->size = 0;
}

void insert(linkedlist **l, int val) {
  node *temp = malloc(sizeof(node));
  temp->val = val;
  temp->next = NULL;

  if ((*l)->head == NULL)
    (*l)->head = temp;
  else {
    while ((*l)->head->next != NULL)
      (*l)->head = (*l)->head->next;

    (*l)->head->next = temp;
    (*l)->size++;
  }
}

void printList(linkedlist *l) {
  assert(l != NULL);

  node *current = l->head;

  while (current != NULL) {
    printf("%d\n", current->val);
    current = current->next;
  }
}

void deleteList(linkedlist **l) {
  while ((*l)->head != NULL) {
    node *temp = (*l)->head->next;
    free((*l)->head);
    (*l)->head = temp;
  }
  (*l)->size = 0;
  free(*l);
}

bool IsOnTheList(linkedlist *l, int val) {
  assert(l != NULL);
  node *temp = l->head;

  while (temp != NULL) {
    if (temp->val == val)
      return true;
    temp = temp->next;
  }

  return false;
}

int main() {
  linkedlist *l;
  init(&l);
  insert(&l, 3);
  insert(&l, 5);
  printList(l);
  deleteList(&l);
  return 0;
}
