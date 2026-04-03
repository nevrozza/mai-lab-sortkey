#include "vector.h"
#include "../utils/utils.h"
#define INITIAL_CAPACITY  4

#include <stdlib.h>

struct vector {
    int size;
    int capacity;
    Item **items;
};

vector *init() {
    vector *v = malloc(sizeof(vector));
    Item **items = malloc(INITIAL_CAPACITY * sizeof(Item *));
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
    for (int i = 0; i < v->size; i++) {
        free(v->items[i]);
    }
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
    Item **new_items = realloc(v->items, new_capacity * sizeof(Item *));
    if (new_items == nullptr) {
        memory_error();
        return;
    }
    v->items = new_items;
    v->capacity = new_capacity;
}

Item *get(const vector *v, const int index) {
    if (index < 0 || index >= v->size) return nullptr;
    return v->items[index];
}

void set(vector *v, const int index, Item *client) {
    v->items[index] = client;
}

void push(vector *v, Item *client) {
    if (v->size >= v->capacity) {
        resize(v, v->capacity * 2);
    }
    v->items[v->size++] = client;
}

Item *pop(vector *v) {
    if (v->size == 0) return nullptr;
    return v->items[--v->size];
}
