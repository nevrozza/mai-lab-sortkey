#ifndef SOLUTION_H
#define SOLUTION_H
#include <stddef.h>

// base – массив
// nmemb – кол-во элементов
// size – размер одного элемента
// compar – компаратор для элементов массива
void shell_sort(void *base, size_t nmemb, size_t size,
                int (*compar)(const void *, const void *));

// key – искомый элемент
// base – массив
// nmemb – кол-во элементов в массиве
// size – размер одного элемента
// compar – компаратор для элементов массива
void *binary_search(const void *key, void *base, size_t nmemb, size_t size,
                    int (*compar)(const void *, const void *));

#endif //SOLUTION_H
