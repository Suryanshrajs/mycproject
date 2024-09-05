#include "linkedlist.h"
#include <stdlib.h>

void list_init(LinkedList *list) {
    list->head = NULL;
}

void list_append(LinkedList *list, int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void list_free(LinkedList *list) {
    Node *current = list->head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
}
