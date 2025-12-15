#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "array.h"

#define SIZE 100

int main() {
    setlocale(LC_CTYPE, "");
    puts("Лабораторные работы 11, 14, 16: Работа с массивами ===\n");

    int size;
    puts("Укажите размер массива");
    scanf("%d", &size);

    if (size > SIZE || size <= 0) {
        printf("Некорректный размер массива\n");
        return 1;
    }

    double array[SIZE];

    task11(array, size);

    task14(array, size); // для всех заданий лаб. 14

    task16();// для всех заданий лаб. 16

    return 0;
}

int task11(double* array, int size) {
   
    double sum = 0;
    int count = 0;
    puts("\n================== Лабораторная 11 ==================");
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
    puts("\n================== Лабораторная 14 ==================");

    // Задание 1. Заполнение массива
    double array_14[SIZE];
    full_elements(array_14, size);
    printf("Массив, заполненный функцие func(x):\n");
    print_array(array_14, size);

    // Задание 2. Преобразование массива
    double sum = sum_array(array_14, size);
    printf("\nСумма элементов: %.2f\n\n", sum);

    // 9. Поиск максимального по модулю значения, не равного заданному А.
    double A = 1.0; // заданное значение A
    double result = find_max_not_A(array_14, size, A);
    printf("Максимальное значение, не равное %.2f: %.2f\n", A, result);
}

int task16(void) {
    puts("\n================== Лабораторная 16==================");
    srand(time(NULL));
    // Генерация случайных размеров массивов (от 10 до 50)
    int size_a = rand() % 41 + 10;  // 10-50
    int size_b = rand() % 41 + 10;
    int size_c = rand() % 41 + 10;

    printf("Размеры массивов:\n");
    printf(" Массив a: %d элементов\n", size_a);
    printf(" Массив b: %d элементов\n", size_b);
    printf(" Массив c: %d элементов\n", size_c);

    // Создание трёх массивов со случайными числами
    double* a = create_random_array(size_a);
    double* b = create_random_array(size_b);
    double* c = create_random_array(size_c);

    if (a == NULL || b == NULL || c == NULL) {
        printf("Ошибка создания массивов!\n");
        free(a); free(b); free(c);
        return 1;
    }

    // Вывод исходных массивов
    print_array_info(a, size_a, "a");
    print_array_info(b, size_b, "b");
    print_array_info(c, size_c, "c");

    // Создание массива d 
    int size_d;
    double* d = create_d_array_min(a, size_a, b, size_b, c, size_c, &size_d);

    // Вывод массива d
    if (d != NULL && size_d > 0) {
        print_array_info(d, size_d, "d (результат)");
    }
    else {
        printf("\nМассив d пуст! Нет общих индексов во всех трёх массивах.\n");
    }

    // Очистка памяти
    free(a);
    free(b);
    free(c);
    free(d);

    printf("\nПамять освобождена.\n");
    return 0;
}
