/**
 * arrays.h - Заголовочный файл для работы с массивами
 * Функции для работы с одномерными массивами double
 */;

#include <stdio.h>
#ifndef ARRAYS_H
#define ARRAYS_H

 /**
  * Лабораторная работа 11
  * @param array указатель на массив
  * @param size размер массива
  * @return 0 при успехе, 1 при ошибке
  */
int task11(double* array, int size);

/**
 * Лабораторная работа 14
 * @param array указатель на массив
 * @param size размер массива
 * @return 0 при успехе, 1 при ошибке
 */
int task14(double* array, int size);

/**
 * Лабораторная работа 16
 * @return 0 при успехе, 1 при ошибке
 */
int task16(void);

double func(double x); // функция для получения значений как в работе 8

/**
 * Заполнение массива значениями через функцию func(x)
 * @param array_14 указатель на массив
 * @param size размер массива
 * @return указатель на заполненный массив
 */
double* full_elements(double* array_14, int size);

/**
 * Печать элементов массива
 * @param array_14 указатель на массив
 * @param size размер массива
 * @return количество выведенных элементов
 */
void print_array(double* array_14, int size);

/**
 * Вычисление суммы элементов массива
 * @param array_14 указатель на массив
 * @param size размер массива
 * @return сумма элементов массива
 */
double sum_array(double* array_14, int size);

/**
 * Поиск максимального значения, не равного заданному A (вариант 9)
 * @param array_14 указатель на массив
 * @param size размер массива
 * @param A значение для исключения из поиска
 * @return максимальное значение, не равное A
 */
double find_max_not_A(double* array_14, int size, double A);


/**
 * Создание массива со случайными вещественными числами
 * @param size размер создаваемого массива
 * @return указатель на созданный массив
 */
double* create_random_array(int size);

/**
 * Нахождение минимального значения среди трёх чисел
 * @param a первое значение
 * @param b второе значение
 * @param c третье значение
 * @param valid_count указатель на счётчик валидных значений
 * @return минимальное значение среди трёх
 */
double find_min_among_three(double a, double b, double c, int* valid_count);

/**
 * Создание массива d по правилу d[i] = min(a[i], b[i], c[i])
 * @param a указатель на первый массив
 * @param size_a размер первого массива
 * @param b указатель на второй массив
 * @param size_b размер второго массива
 * @param c указатель на третий массив
 * @param size_c размер третьего массива
 * @param result_size указатель на переменную для размера результирующего массива
 * @return указатель на созданный массив d
 */
double* create_d_array_min(double* a, int size_a, double* b, int size_b, double* c, int size_c, int* result_size);

/**
 * Вывод информации о массиве
 * @param array указатель на массив
 * @param size размер массива
 * @param name имя массива для вывода
 */
void print_array_info(double* array, int size, const char* name);

#endif
