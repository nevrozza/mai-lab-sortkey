#include "solution.h"

#include <stdlib.h>
#include <string.h>


void shell_sort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)) {
    char *array = base;

    char *temp = malloc(size);

    for (size_t gap = nmemb / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < nmemb; i++) {
            // temp = array[i]
            memcpy(temp, array + (i * size), size);
            size_t j = i;
            while (j >= gap && compar(array + (j - gap) * size, temp) > 0) {
                // array[j] = array[j - gap]
                memcpy(array + (j * size), array + (j - gap) * size, size);
                j -= gap;
            }
            // array[j] = temp
            memcpy(array + (j * size), temp, size);
        }
    }
    free(temp);
}


void *binary_search(const void *key, void *base, size_t nmemb, size_t size,
                    int (*compar)(const void *, const void *)) {
    size_t l = 0;
    size_t r = nmemb;

    char *array = base;

    while (l < r) {
        const size_t m = l + (r - l) / 2;
        void *mid_ptr = array + (m * size);

        const int res = compar(key, mid_ptr);

        if (res == 0) {
            return mid_ptr;
        } else if (res > 0) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    return NULL;
}
