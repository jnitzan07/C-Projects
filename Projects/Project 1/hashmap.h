#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef EE200_HASHMAP_H
#define EE200_HASHMAP_H

#define TABLE_SIZE 1000

typedef struct Node {
    char *key;
    void *value;
    struct Node *next;
} Node;

typedef struct {
    Node *buckets[TABLE_SIZE];
} HashMap;

unsigned int hash(const char* key);

void insert(HashMap *map, const char *key, void *value);

void* get_value(HashMap *map, const char *key);

HashMap* create_table();

#endif //EE200_HASHMAP_H
