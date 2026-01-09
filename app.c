#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

#define SIZE 100

int main() {
    setlocale(LC_CTYPE, "");
    srand(time(NULL));

    double array[SIZE];

    int num;
    int size;

    do {
        printf("\n============ МЕНЮ ============\n");
        printf("1 - Лабораторная работа 11 \n");
        printf("2 - Лабораторная работа 14 \n");
        printf("3 - Лабораторная работа 16\n");
        printf("4 - Лабораторная работа 17 \n");
        printf("0  - Выход\n");
        printf("==============================\n");
        printf("Выберите работу: ");

        if (scanf("%d", &num) != 1) {
            while (getchar() != '\n');
            num = -1;
        }

        switch (num) {
        case 1:
            printf("\n>>> Лабораторная работа 11 <<<\n");
            printf("Введите размер массива (максимум %d): ", SIZE);
            scanf("%d", &size);

            if (size > 0 && size <= SIZE) {
                task11(array, size);
            }
            else {
                printf("Ошибка: Размер должен быть от 1 до %d.\n", SIZE);
            }
            break;

        case 2:
            printf("\n>>> Лабораторная работа 14 <<<\n");
            printf("Введите размер массива (максимум %d): ", SIZE);
            scanf("%d", &size);

            if (size > 0 && size <= SIZE) {
                task14(array, size);
            }
            else {
                printf("Ошибка: Размер должен быть от 1 до %d.\n", SIZE);
            }
            break;

        case 3:
            printf("\n>>> Лабораторная работа 16 <<<\n");
            task16();
            break;

        case 4:
            printf("\n>>> Лабораторная работа 17 <<<\n");
            printf("Введите размер массива для сортировки (рекомендуется > 1000): ");
            scanf("%d", &size);

            if (size > 0) {
                task17(size);
            }
            else {
                printf("Ошибка: Размер должен быть больше 0.\n");
            }
            break;

        case 0:
            printf("Выход из программы...\n");
            break;

        default:
            printf("Неверный пункт меню. Попробуйте снова.\n");
        }

    } while (num != 0);

    return 0;
}


int task11(double* array, int size) {
    double sum = 0;
    int count = 0;
    printf("Введите %d целых чисел:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%lf", &array[i]);

        if (array[i] != 0) {
            sum += array[i];
            count++;
        }
    }

    if (count == 0) {
        printf("В массиве нет ненулевых элементов\n");
    }
    else {
        double avg = sum / count;
        printf("Среднее арифметическое (без нулевых элементов): %.2f\n", avg);
    }
    return 0;
}


int task14(double* array, int size) {

    // Задание 1. Заполнение массива
    double array_14[SIZE];
    full_elements(array_14, size);
    printf("\nМассив, заполненный функцией f(x) = x^2 - 2x + 1:\n");
    print_array(array_14, size);

    // Задание 2. Преобразование массива
    double sum = sum_array(array_14, size);
    printf("\nСумма элементов: %.2f\n\n", sum);

    // 9. Поиск максимального по модулю значения, не равного заданному А.
    double A = 1.0;
    double result = find_max_not_A(array_14, size, A);
    printf("Максимальное значение, не равное %.2f: %.2f\n", A, result);
    return 0;
}

int task16(void) {
    // Генерация случайных размеров массивов от 10 до 50
    int size_a = rand() % 41 + 10;  
    int size_b = rand() % 41 + 10;
    int size_c = rand() % 41 + 10;

    printf("Размеры массивов:\n");
    printf(" Массив a: %d элементов\n", size_a);
    printf(" Массив b: %d элементов\n", size_b);
    printf(" Массив c: %d элементов\n", size_c);

    double* a = create_random_array(size_a);
    double* b = create_random_array(size_b);
    double* c = create_random_array(size_c);

    if (a == NULL || b == NULL || c == NULL) {
        printf("Ошибка создания массивов!\n");
        free(a); free(b); free(c);
        return 1;
    }

    print_array_info(a, size_a, "a");
    print_array_info(b, size_b, "b");
    print_array_info(c, size_c, "c");

    // Создание массива d 
    int size_d;
    double* d = create_d_array_min(a, size_a, b, size_b, c, size_c, &size_d);

    if (d != NULL && size_d > 0) {
        print_array_info(d, size_d, "d (результат)");
    }
    else {
        printf("\nМассив d пуст! Нет общих индексов во всех трёх массивах.\n");
    }

    free(a);
    free(b);
    free(c);
    free(d);

    printf("\nПамять освобождена.\n");
    return 0;
}

int task17(int size) {
    printf("\nТестирование сортировок на массиве из %d элементов.\n", size);

    int* source = (int*)malloc(size * sizeof(int));
    int* temp = (int*)malloc(size * sizeof(int));

    if (!source || !temp) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    full_array(source, size);
    printf("Исходный массив (первые элементы): ");
    put_array(source, size);

    clock_t start, end;
    double time_used;

    // 1. Пузырьковая сортировка
    copy_int_array(source, temp, size);
    start = clock();
    sort_bubble(temp, size);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nПузырьковая сортировка:    %.10f с\n", time_used);

    // 2. Шейкерная сортировка
    copy_int_array(source, temp, size);
    start = clock();
    sort_kokteil(temp, size);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Шейкерная сортировка:    %.10f с\n", time_used);

    // 3. Сортировка простым выбором
    copy_int_array(source, temp, size);
    start = clock();
    sort_select(temp, size);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Сортировка простым выбором: %.10f с\n", time_used);

    // 4. Сортировка вставками
    copy_int_array(source, temp, size);
    start = clock();
    sort_insert(temp, size);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Сортировка вставками: %.10f с\n", time_used);

    // Вывод результата последней сортировки
    printf("\nОтсортированный массив: ");
    put_array(temp, size);

    free(source);
    free(temp);
    return 0;
}