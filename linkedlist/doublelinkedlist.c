#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
  struct node *previus;
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
  temp->previus = NULL;

  if ((*l)->head == NULL) {
    (*l)->head = temp;
    (*l)->size = 1;
  } else {
    node *current = (*l)->head;
    while (current->next != NULL) {
      current = current->next;
    }

    current->next = temp;
    temp->previus = current;
    (*l)->size++;
  }
}

void printList(linkedlist *l) {
  assert(l != NULL && l->head != NULL);

  node *current = l->head;
  while (current != NULL) {
    printf("current val number: %d\n", current->val);
    if (current->previus != NULL) {
      printf("Previous val number: %d\n", current->previus->val);
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

// void extend_at(linkedlist **l, int index, int val) {
//   assert(l != NULL && (*l)->size >= index && index >= 0);
//
//   if (index == 0) {
//     node *temp = malloc(sizeof(node));
//     temp->val = val;
//     temp->next = (*l)->head;
//     temp->previus = NULL;
//     (*l)->head->previus = temp;
//     (*l)->head = temp;
//     (*l)->size++;
//   } else {
//     node *first = (*l)->head;
//
//     while (index > 1) {
//       first = first->next;
//     }
//
//     node *temp = malloc(sizeof(node));
//     temp->val = val;
//   }
// }

int main() {
  linkedlist *l;
  init(&l);
  insert(&l, 1);
  insert(&l, 2);
  insert(&l, 3);
  // extend_at(&l, 0, 100);
  printList(l);
  deletList(&l);

  return 0;
}
