#include "hashmap.h"

unsigned int hash(const char *key) {
    unsigned long int val = 5381;
    unsigned int i = 0;
    while (key[i] != '\0') {
        val = ((val << 5) + val) + key[i];
        i++;
    }
    return val % TABLE_SIZE;
}

void insert(HashMap *map, const char *key, void *value) {
    unsigned int bucket_index = hash(key);
    Node *current = map -> buckets[bucket_index];

    while (current != NULL) {
        if (strcmp(current -> key, key) == 0) {
            current -> value = value;
            return;
        }
        current = current -> next;
    }

    Node *new_node = malloc(sizeof(Node));
    new_node -> key = strdup(key);
    new_node -> value = value;

    new_node -> next = map -> buckets[bucket_index];
    map -> buckets[bucket_index] = new_node;
}

HashMap* create_table() {
    HashMap *map = malloc(sizeof(HashMap));
    for (int i = 0; i < TABLE_SIZE; i++) {
        map -> buckets[i] = NULL;
    }
    return map;
}

void* get_value(HashMap *map, const char *key) {
    unsigned int bucket_index = hash(key);
    Node *current = map -> buckets[bucket_index];

    while (current != NULL) {
        if (strcmp(current -> key, key) == 0) {
            return current -> value;
        }
        current = current -> next;
    }

    return NULL;
}