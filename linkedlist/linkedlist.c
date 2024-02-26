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
  assert(l != NULL && *l != NULL);

  *l = malloc(sizeof(linkedlist));
  (*l)->head = NULL;
  (*l)->size = 0;
}

void insert(linkedlist **l, int val) {
  node *temp = malloc(sizeof(node));
  temp->val = val;
  temp->next = NULL;

  if ((*l)->head == NULL) {
    (*l)->head = temp;
    (*l)->size = 1;
  } else {
    node *current = (*l)->head;
    while (current->next != NULL)
      current = current->next;

    current->next = temp;
    (*l)->size++;
  }
}

void printList(linkedlist *l) {
  assert(l->head != NULL && l != NULL);

  node *current = l->head;

  while (current != NULL) {
    printf("Current val number: %d\n", current->val);
    current = current->next;
  }
}

void deleteList(linkedlist **l) {
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

int SearchByIndex(linkedlist *l, int index) {
  assert(l->size > index && index > 0 && l != NULL);

  node *current = l->head;

  while (index > 0) {
    current = current->next;
    index--;
  }

  return current->val;
}

void extend(linkedlist **l, int index, int val) {
  assert(l != NULL && (*l)->size >= index && index >= 0);

  node *first = (*l)->head;

  if (index == 0) {
    node *extend = malloc(sizeof(node));
    extend->val = val;
    extend->next = first;
    (*l)->head = extend;
    (*l)->size++;
  } else {
    while (index > 1) {
      first = first->next;
      index--;
    }

    node *extend = malloc(sizeof(node));
    extend->val = val;
    extend->next = first->next;
    first->next = extend;
    (*l)->size++;
  }
}

void delet_at(linkedlist **l, int index) {
  assert(index >= 0 && index < (*l)->size);

  if (index == 0) {
    node *next = (*l)->head->next;
    free((*l)->head);
    (*l)->head = next;

  } else {
    node *current = (*l)->head;

    while (index > 1) {
      current = current->next;
      index--;
    }

    node *del = current->next;
    node *next = del->next;
    free(del);
    current->next = next;
  }

  (*l)->size--;
}

void delet_last(linkedlist **l) {
  assert(l != NULL && *l != NULL && (*l)->head != NULL);

  if ((*l)->head->next == NULL) {
    free((*l)->head);
    (*l)->head = NULL;
    (*l)->size = 0;
  } else {
    node *current = (*l)->head;
    node *previus;
    while (current->next != NULL) {
      previus = current;
      current = current->next;
    }

    free(current);
    current = NULL;
    previus->next = NULL;
    (*l)->size--;
  }
}

int main() {
  linkedlist *l;
  init(&l);
  insert(&l, 1);
  insert(&l, 3);
  extend(&l, 1, 2);
  extend(&l, 3, 4);
  extend(&l, 4, 5);
  insert(&l, 6);
  extend(&l, 6, 7);
  insert(&l, 8);
  extend(&l, 8, 9);
  printList(l);
  deleteList(&l);
  return 0;
}
