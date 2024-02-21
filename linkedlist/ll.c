#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist {
  int val;
  struct linkedlist *next;
} linkedlist;

void init(linkedlist **l) { *l = NULL; }

void insert(linkedlist **l, int val) {
  if (*l == 0) {
    *l = malloc(sizeof(linkedlist));
    (*l)->val = val;
    (*l)->next = 0;
  } else {
    linkedlist *temp = malloc(sizeof(linkedlist));
    temp->val = val;
    temp->next = *l;
    *l = temp;
  }
}

void destroy(linkedlist **l) {
  linkedlist *temp;

  while (*l != 0) {
    temp = (*l)->next;
    free(*l);
    *l = temp;
  }
}

bool verify(linkedlist *l, int val) {
  if (l == 0)
    return false;

  while (l != 0) {
    if (l->val == val)
      return true;
    l = l->next;
  }
  return false;
}

void printList(linkedlist *l) {
  if (l == 0)
    printf("vazio\n");
  while (l != 0) {
    printf("Valor = %d\n", l->val);
    printf("Proximo = %p\n", l->next);
    l = l->next;
  }
}

int main() {
  linkedlist *a;
  init(&a);
  insert(&a, 4);
  insert(&a, 5);
  destroy(&a);
  printList(a);
  return 0;
}
