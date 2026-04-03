#ifndef ITEM_H
#define ITEM_H

#define MAX_STR 100

typedef struct Item {
    double key;
    char value[MAX_STR];
} Item;

int item_compare_item(const void *item_a, const void *item_b);

int item_key_compare(const void *key, const void *b);

#endif //ITEM_H
