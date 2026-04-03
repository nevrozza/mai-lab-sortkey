#ifndef VECTOR_H
#define VECTOR_H
#include "item.h"

typedef struct vector vector;

vector *init();

void destroy(vector *v);

int size(const vector *v);

void resize(vector *v, int new_capacity);

Item *get(const vector *v, int index);

void *get_raw_array(const vector *v);

void set(vector *v, int index, Item item);

void push(vector *v, Item item);

Item pop(vector *v);

#endif //VECTOR_H
