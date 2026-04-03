# include "item.h"


int item_compare_item(const void *item_a, const void *item_b) {
    const Item *x = item_a;
    const Item *y = item_b;

    if (x->key < y->key) return -1;
    if (x->key > y->key) return 1;
    return 0;
}

int item_key_compare(const void *key, const void *b) {
    const double *search_key = key;
    const Item *item = b;

    if (*search_key < item->key) return -1;
    if (*search_key > item->key) return 1;
    return 0;
}
