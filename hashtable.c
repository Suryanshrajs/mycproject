#include "hashtable.h"
#include <stdlib.h>
#include <string.h>

static unsigned long hash_function(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

void hash_table_init(HashTable *table, size_t size) {
    table->size = size;
    table->buckets = (HashNode**)calloc(table->size, sizeof(HashNode*));
}

void hash_table_insert(HashTable *table, const char *key, int value) {
    unsigned long hash = hash_function(key);
    size_t index = hash % table->size;

    HashNode *new_node = (HashNode*)malloc(sizeof(HashNode));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}

int hash_table_get(HashTable *table, const char *key) {
    unsigned long hash = hash_function(key);
    size_t index = hash % table->size;

    HashNode *current = table->buckets[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Key not found
}

void hash_table_free(HashTable *table) {
    for (size_t i = 0; i < table->size; i++) {
        HashNode *current = table->buckets[i];
        while (current != NULL) {
            HashNode *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(table->buckets);
}
