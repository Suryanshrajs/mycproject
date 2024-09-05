#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} LinkedList;

void list_init(LinkedList *list);
void list_append(LinkedList *list, int value);
void list_free(LinkedList *list);

#endif
