#ifndef VECTOR_H
#define VECTOR_H

#define MAX_STR 100

typedef struct {
    double key;
    char value[MAX_STR];
} Item;

typedef struct vector vector;

vector *init();

void destroy(vector *v);

int size(const vector *v);

void resize(vector *v, int new_capacity);

Item *get(const vector *v, int index);

void set(vector *v, int index, Item *client);

void push(vector *v, Item *client);

Item *pop(vector *v);

#endif //VECTOR_H
