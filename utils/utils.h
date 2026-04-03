#ifndef UTILS_H
#define UTILS_H

void fatal_error(char msg[]);

void memory_error();

int item_compare_item(const void *item_a, const void *item_b);

int key_compare_item(const void *key, const void *item);

#endif //UTILS_H
