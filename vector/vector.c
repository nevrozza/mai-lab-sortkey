#include "vector.h"
#include "../utils/utils.h"
#define INITIAL_CAPACITY  4

#include <stdlib.h>

struct vector {
    int size;
    int capacity;
    Item *items;
};

vector *init() {
    vector *v = malloc(sizeof(vector));
    Item *items = malloc(INITIAL_CAPACITY * sizeof(Item));
    if (v == nullptr || items == nullptr) {
        memory_error();
        return nullptr; // suppress IDE
    }
    v->size = 0;
    v->capacity = INITIAL_CAPACITY;
    v->items = items;
    return v;
}

void destroy(vector *v) {
    if (!v || !v->items) return;
    free(v->items);
    free(v);
}

int size(const vector *v) {
    return v->size;
}

void resize(vector *v, const int new_capacity) {
    if (new_capacity < v->capacity) {
        return;
    }
    Item *new_items = realloc(v->items, new_capacity * sizeof(Item));
    if (new_items == nullptr) {
        memory_error();
        return;
    }
    v->items = new_items;
    v->capacity = new_capacity;
}

Item *get(const vector *v, const int index) {
    if (index < 0 || index >= v->size) fatal_error("Index out of range");
    return &v->items[index];
}

void *get_raw_array(const vector *v) {
    if (v == NULL) {
        return NULL;
    }
    return v->items;
}

void set(vector *v, const int index, Item item) {
    v->items[index] = item;
}

void push(vector *v, Item item) {
    if (v->size >= v->capacity) {
        resize(v, v->capacity * 2);
    }
    v->items[v->size++] = item;
}

void clear(vector *v) {
    while (size(v) > 0) {
        pop(v);
    }
}

Item pop(vector *v) {
    if (v->size == 0) fatal_error("Can't pop from empty vector");
    return v->items[--v->size];
}
