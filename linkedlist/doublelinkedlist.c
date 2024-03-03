#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
  struct node *previous;
} node;

typedef struct linkedlist {
  int size;
  node *head;
} linkedlist;

void init(linkedlist **l) {
  assert(l != NULL && *l != NULL);

  *l = malloc(sizeof(linkedlist));
  (*l)->head = NULL;
  (*l)->size = 0;
}

void insert(linkedlist **l, int val) {
  assert(l != NULL && *l != NULL);

  node *temp = malloc(sizeof(node));
  temp->val = val;
  temp->next = NULL;
  temp->previous = NULL;

  if ((*l)->head == NULL) {
    (*l)->head = temp;
    (*l)->size = 1;
  } else {
    node *current = (*l)->head;
    while (current->next != NULL) {
      current = current->next;
    }

    current->next = temp;
    temp->previous = current;
    (*l)->size++;
  }
}

void printList(linkedlist *l) {
  assert(l != NULL && l->head != NULL);

  node *current = l->head;
  while (current != NULL) {
    printf("current val number: %d\n", current->val);
    if (current->previous != NULL) {
      printf("Previous val number: %d\n", current->previous->val);
    } else {
      printf("Previous val: NULL\n");
    }
    if (current->next != NULL) {
      printf("Next val number: %d\n", current->next->val);
    } else {
      printf("Next val: NULL\n");
    }
    printf("\n");
    current = current->next;
  }
}

void deletList(linkedlist **l) {
  assert(l != NULL && *l != NULL && (*l)->head != NULL);

  if ((*l)->head == NULL) {
    free(*l);
    *l = NULL;
    return;
  }

  node *temp;
  while ((*l)->head != NULL) {
    temp = (*l)->head->next;
    free((*l)->head);
    (*l)->head = temp;
  }
  free(*l);
  *l = NULL;
}

void extend_at(linkedlist **l, int index, int val) {
  assert(l != NULL && (*l)->size >= index && index >= 0);

  if (index == 0) {
    node *temp = malloc(sizeof(node));
    temp->val = val;
    temp->next = (*l)->head;
    temp->previous = NULL;

    if ((*l)->head != NULL) {
      (*l)->head->previous = temp;
    }

    (*l)->head = temp;
    (*l)->size++;
  } else {
    node *current = (*l)->head;
    node *previous = NULL;

    while (index > 0) {
      previous = current;
      current = current->next;
      index--;
    }

    node *extend = malloc(sizeof(node));
    extend->val = val;
    extend->next = current;
    extend->previous = previous;

    if (previous != NULL) {
      previous->next = extend;
    }

    if (current != NULL) {
      current->previous = extend;
    }

    (*l)->size++;
  }
}
int main() {
  linkedlist *l;
  init(&l);
  insert(&l, 1);
  insert(&l, 2);
  extend_at(&l, 2, 3);
  insert(&l, 4);
  extend_at(&l, 4, 5);
  printList(l);
  deletList(&l);

  return 0;
}
