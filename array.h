#ifndef ARRAYS_H
#define ARRAYS_H

int task11(double* array, int size);
int task14(double* array, int size);
int task16(void);

double func(double x);
double* full_elements(double* array_14, int size);
void print_array(double* array, int size);
double sum_array(double* arr, int n);
double find_max_not_A(double* arr, int n, double A);

double* create_random_array(int size);
double find_min_among_three(double a, double b, double c, int* valid_count);
double* create_d_array_min(double* a, int size_a, double* b, int size_b, double* c, int size_c, int* result_size);
void print_array_info(double* array, int size, const char* name);
#endif