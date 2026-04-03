#include "cli.h"

#include <stdio.h>

#include "solution.h"

void print_table(const vector *v, const char *title) {
    printf("------------ %s ------------\n", title);
    for (int i = 0; i < size(v); i++) {
        Item *it = get(v, i);
        printf("%8.4f | %s\n", it->key, it->value);
    }
}

void run_sort_test(vector *v, const char *msg) {
    printf("\n>> %s\n", msg);
    print_table(v, "БЫЛО");
    shell_sort(get_raw_array(v), size(v), sizeof(Item), item_compare_item);
    print_table(v, "СТАЛО");
    printf("-------------------------------\n");
}
