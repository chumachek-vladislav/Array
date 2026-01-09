#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "array.h"

// ================== ФУНКЦИИ ДЛЯ ЛАБОРАТОРНОЙ 14 ==================
// Функция для вычисления f(x)
double func(double x) {
    return x * x - 2 * x + 1;
}

// 1. Заполнение массива значениями через func()
double* full_elements(double* array_14, int size) {
    if (array_14 == NULL || size <= 0) {
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        double x = (double)i; 
        array_14[i] = func(x);
    }

    return array_14;
}
// 2. Печать массива
void print_array(double* array_14, int size) {
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %.2f\n", i, array_14[i]);
    }
}

// 3. Сумма элементов
double sum_array(double* array_14, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += array_14[i];
    }
    return sum;
}

// 4. Пункт 9: Максимальное значение, не равное A
double find_max_not_A(double* array_14, int n, double A) {
    double max_val = -1e9;
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (array_14[i] != A) {
            if (!found || array_14[i] > max_val) {
                max_val = array_14[i];
                found = 1;
            }
        }
    }
    if (!found) {
        return NAN;
    }
    return max_val;
}

// ================== ФУНКЦИИ ДЛЯ ЛАБОРАТОРНОЙ 16 ==================
// 1. Создание массива со случайными числами от -1.0 до 1.0
double* create_random_array(int size) {
    if (size <= 0) {
        return NULL;
    }
    double* array = (double*)malloc(size * sizeof(double));
    if (array == NULL) {
        return NULL;
    }

    // Инициализация ГСЧ
    static int seeded = 0;
    if (!seeded) {
        srand(time(NULL));
        seeded = 1;
    }

    // Заполнение случайными числами от -1.0 до 1.0
    for (int i = 0; i < size; i++) {
        // Генерация числа от -1.0 до 1.0
        array[i] = (rand() / (double)RAND_MAX) * 2.0 - 1.0;
    }
    return array;
}

// 2. Нахождение минимального среди трёх значений с учётом "отсутствующих пар"
double find_min_among_three(double a, double b, double c, int* valid_count) {
    double min_val;
    *valid_count = 0;

    double values[3];
    int count = 0;
    values[count++] = a;
    *valid_count = 1;
    min_val = a; 

    if (b < min_val) min_val = b;
    if (c < min_val) min_val = c;

    return min_val;
}

// 3. Создание массива d по правилу d[i] = min(a[i], b[i], c[i])
double* create_d_array_min(double* a, int size_a, double* b, int size_b, double* c, int size_c, int* result_size) {
    // Находим максимальную длину из трёх массивов
    int max_size = size_a;
    if (size_b > max_size) max_size = size_b;
    if (size_c > max_size) max_size = size_c;

    // Создаём результирующий массив
    double* d = (double*)malloc(max_size * sizeof(double));
    if (d == NULL) {
        if (result_size != NULL) {
            *result_size = 0;
        }
        return NULL;
    }

    int d_index = 0;
    for (int i = 0; i < max_size; i++) {
        if (i < size_a && i < size_b && i < size_c) {
            double min_val = a[i];
            if (b[i] < min_val) min_val = b[i];
            if (c[i] < min_val) min_val = c[i];

            d[d_index++] = min_val;
        }
    }
    *result_size = d_index;  // размер массива d

    if (d_index == 0) {
        free(d);
        return NULL;
    }

    if (d_index < max_size) {
        double* temp = (double*)realloc(d, d_index * sizeof(double));
        if (temp != NULL) {
            d = temp;
        }
    }

    return d;
}

// 4. Печать информации о массиве
void print_array_info(double* array, int size, const char* name) {
    if (array == NULL || size <= 0) {
        return;
    }

    printf("\n=== Массив %s (%d элементов) ===\n", name, size);
    for (int i = 0; i < size && i < 15; i++) { 
        printf("%s[%2d] = %8.4f", name, i, array[i]);
        if ((i + 1) % 3 == 0) printf("\n");
        else printf("\t");
    }
    if (size > 15) {
        printf("... (показано 15 из %d элементов)\n", size);
    }
    else {
        printf("\n");
    }
}

// ================== ФУНКЦИИ ДЛЯ ЛАБОРАТОРНОЙ 17 ==================
// а) Пузырьковая сортировка
void sort_bubble(int* ptrarr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ptrarr[j] > ptrarr[j + 1]) {
                int temp = ptrarr[j];
                ptrarr[j] = ptrarr[j + 1];
                ptrarr[j + 1] = temp;
            }
        }
    }
}

// б) Шейкерная сортировка
void sort_kokteil(int* ptrarr, int n) {
    int left = 0;
    int right = n - 1;
    int swapped = 1;
    while (left < right&& swapped) {
        swapped = 0;
        for (int i = left; i < right; i++) {
            if (ptrarr[i] > ptrarr[i + 1]) {
                int temp = ptrarr[i]; ptrarr[i] = ptrarr[i + 1]; ptrarr[i + 1] = temp;
                swapped = 1;
            }
        }
        right--;
        if (!swapped) break;
        swapped = 0;
        for (int i = right; i > left; i--) {
            if (ptrarr[i] < ptrarr[i - 1]) {
                int temp = ptrarr[i]; ptrarr[i] = ptrarr[i - 1]; ptrarr[i - 1] = temp;
                swapped = 1;
            }
        }
        left++;
    }
}

// в) Сортировка выбором
void sort_select(int* ptrarr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int i_min = i;
        for (int j = i + 1; j < n; j++) {
            if (ptrarr[j] < ptrarr[i_min]) {
                i_min = j;
            }
        }
        if (i_min != i) {
            int temp = ptrarr[i];
            ptrarr[i] = ptrarr[i_min];
            ptrarr[i_min] = temp;
        }
    }
}

// г) Сортировка вставками
void sort_insert(int* ptrarr, int n) {
    for (int i = 1; i < n; i++) {
        int temp = ptrarr[i];
        int j = i;
        while (j > 0 && ptrarr[j - 1] > temp) {
            ptrarr[j] = ptrarr[j - 1];
            j--;
        }
        ptrarr[j] = temp;
    }
}

// Заполнение массива, используя rand()
int* full_array(int* ptrarr, int n) {
    for (int i = 0; i < n; i++) {
        ptrarr[i] = rand() % 1000;
    }
    return ptrarr;
}

// Печать массива int
int put_array(int* ptrarr, int n) {
    printf("[ ");
    int limit = (n > 20) ? 20 : n;
    for (int i = 0; i < limit; i++) {
        printf("%d ", ptrarr[i]);
    }
    if (n > 20) printf("... ");
    printf("]\n");
    return n;
}

// Вспомогательная функция копирования для сортировки одних и тех же данных
void copy_int_array(const int* src, int* dest, int n) {
    for (int i = 0; i < n; i++) 
        dest[i] = src[i];
}