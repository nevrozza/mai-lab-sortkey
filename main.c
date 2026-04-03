#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "solution/cli.h"
#include "solution/solution.h"
#include "vector/vector.h"

int main(void) {

    srand(time(NULL));
    vector *v = init();
    int choice;

    while (1) {
        printf("Выберите режим:\n1 - Ввести данные вручную\n2 - Автоматические тесты (3 случая)\n> ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            clear(v);
            printf("Введите данные (Ключ Значение). Для выхода введите буквы в ключе:\n");

            Item temp;
            while (1) {
                printf("> ");
                if (scanf("%lf", &temp.key) != 1) {
                    scanf("%*s");
                    break;
                }
                if (scanf("%49s", temp.value) != 1) {
                    break;
                }

                push(v, temp);
            }

            if (size(v) > 0) {
                run_sort_test(v, "Ручной ввод");
            } else {
                printf("Таблица пуста.\n");
            }
        } else if (choice == 2) {
            int n;
            printf("Введите N: ");
            scanf("%d", &n);

            if (n <= 0) {
                printf("Таблица пуста\n");
                continue;
            }

            clear(v);
            for (int i = 1; i <= n; i++) {
                Item item = {(double) i, ""};
                sprintf(item.value, "Sorted_%d", i);
                push(v, item);
            }
            run_sort_test(v, "Упорядочены");

            clear(v);
            for (int i = 0; i < n; i++) {
                Item item = {(double) (n - i), ""};
                sprintf(item.value, "Reverse_%d", n - i);
                push(v, item);
            }
            run_sort_test(v, "Обратный порядок");

            clear(v);
            for (int i = 0; i < n; i++) {
                Item item = {(double) (rand() % 1000), ""};
                sprintf(item.value, "Random_%d", (int) item.key);
                push(v, item);
            }
            run_sort_test(v, "Рандом");
        }


        if (size(v) > 0) {
            printf("\n--- Бинарный поиск по ключу ---\n");
            printf("Введите ключи для поиска (буквы для завершения поиска):\n> ");
            double s_key;
            while (scanf("%lf", &s_key) == 1) {
                Item *found = binary_search(&s_key, get_raw_array(v), size(v), sizeof(Item), item_key_compare);
                if (found) printf("Найдено: [%8.4f] -> %s\n", found->key, found->value);
                else printf("Ключ %8.4f не найден\n", s_key);
                printf("> ");
            }
        }

        // sry..
        clearerr(stdin);
        char dummy[100];
        fgets(dummy, sizeof(dummy), stdin);
    }

    return 0;
}
