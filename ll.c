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

void init(linkedlist **l) { *l = NULL; }

void insert(linkedlist **l, int val) {
  if (*l == NULL) {
    *l = malloc(sizeof(linkedlist));
    node *temp = malloc(sizeof(node));
    temp->val = val;
    temp->next = NULL;
    (*l)->head = temp;
    (*l)->size = 1;
  } else {
    node *temp = malloc(sizeof(node));

    while ((*l)->head->next != NULL) {
      (*l)->head = (*l)->head->next;
    }
  }
}

int main() { return 0; }
