#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stddef.h>

typedef struct HashNode {
    char *key;
    int value;
    struct HashNode *next;
} HashNode;

typedef struct {
    HashNode **buckets;
    size_t size;
} HashTable;

void hash_table_init(HashTable *table, size_t size);
void hash_table_insert(HashTable *table, const char *key, int value);
int hash_table_get(HashTable *table, const char *key);
void hash_table_free(HashTable *table);

#endif
