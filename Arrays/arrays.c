#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "array.h"

// ================== ÔÓÍÊÖÈÈ ÄËß ËÀÁÎÐÀÒÎÐÍÎÉ 14 ==================
// Ôóíêöèÿ äëÿ âû÷èñëåíèÿ f(x)
double func(double x) {
    return x * x - 2 * x + 1;
}

// 1. Çàïîëíåíèå ìàññèâà çíà÷åíèÿìè ÷åðåç func()
double* full_elements(double* array_14, int size) {
    if (array_14 == NULL || size <= 0) {
        printf("Îøèáêà: íåêîððåêòíûå ïàðàìåòðû â full_elements()\n");
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        double x = (double)i; 
        array_14[i] = func(x);
    }

    return array_14;
}
// 2. Ïå÷àòü ìàññèâà
void print_array(double* array_14, int size) {
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %.2f\n", i, array_14[i]);
    }
}

// 3. Ñóììà ýëåìåíòîâ
double sum_array(double* array_14, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += array_14[i];
    }
    return sum;
}

// 4. Ïóíêò 9: Ìàêñèìàëüíîå çíà÷åíèå, íå ðàâíîå A
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
        printf("Âñå ýëåìåíòû ðàâíû A èëè ìàññèâ ïóñò!\n");
        return 0;
    }
    return max_val;
}


// ================== ÔÓÍÊÖÈÈ ÄËß ËÀÁÎÐÀÒÎÐÍÎÉ 16 ==================
// 1. Ñîçäàíèå ìàññèâà ñî ñëó÷àéíûìè ÷èñëàìè îò -1.0 äî 1.0
double* create_random_array(int size) {
    if (size <= 0) return NULL;

    double* array = (double*)malloc(size * sizeof(double));
    if (array == NULL) {
        printf("Îøèáêà âûäåëåíèÿ ïàìÿòè!\n");
        return NULL;
    }

    // Èíèöèàëèçàöèÿ ÃÑ×
    static int seeded = 0;
    if (!seeded) {
        srand(time(NULL));
        seeded = 1;
    }

    // Çàïîëíåíèå ñëó÷àéíûìè ÷èñëàìè îò -1.0 äî 1.0
    for (int i = 0; i < size; i++) {
        // Ãåíåðàöèÿ ÷èñëà îò -1.0 äî 1.0
        array[i] = (rand() / (double)RAND_MAX) * 2.0 - 1.0;
    }
    return array;
}

// 2. Íàõîæäåíèå ìèíèìàëüíîãî ñðåäè òð¸õ çíà÷åíèé ñ ó÷¸òîì "îòñóòñòâóþùèõ ïàð"
double find_min_among_three(double a, double b, double c, int* valid_count) {
    double min_val;
    *valid_count = 0;

    // Ïðîâåðÿåì, êàêèå çíà÷åíèÿ "âàëèäíû" (ïðåäñòàâëåíû)
    double values[3];
    int count = 0;
    values[count++] = a;
    *valid_count = 1;
    min_val = a; 

    if (b < min_val) min_val = b;
    if (c < min_val) min_val = c;

    return min_val;
}

// 3. Ñîçäàíèå ìàññèâà d ïî ïðàâèëó d[i] = min(a[i], b[i], c[i])
double* create_d_array_min(double* a, int size_a, double* b, int size_b, double* c, int size_c, int* result_size) {
    // Íàõîäèì ìàêñèìàëüíóþ äëèíó èç òð¸õ ìàññèâîâ
    int max_size = size_a;
    if (size_b > max_size) max_size = size_b;
    if (size_c > max_size) max_size = size_c;

    // Ñîçäà¸ì ðåçóëüòèðóþùèé ìàññèâ
    double* d = (double*)malloc(max_size * sizeof(double));
    if (d == NULL) {
        printf("Îøèáêà âûäåëåíèÿ ïàìÿòè äëÿ ìàññèâà d!\n");
        *result_size = 0;
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
    *result_size = d_index;  // ðåàëüíûé ðàçìåð ìàññèâà d

    // Åñëè ìàññèâ ïóñòîé, îñâîáîæäàåì ïàìÿòü
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

// 4. Ïå÷àòü èíôîðìàöèè î ìàññèâå
void print_array_info(double* array, int size, const char* name) {
    if (array == NULL || size <= 0) {
        printf("Ìàññèâ %s: ïóñò èëè íå ñóùåñòâóåò\n", name);
        return;
    }

    printf("\n=== Ìàññèâ %s (%d ýëåìåíòîâ) ===\n", name, size);
    for (int i = 0; i < size && i < 15; i++) {  // âûâîäèì íå áîëåå 15 ýëåìåíòîâ
        printf("%s[%2d] = %8.4f", name, i, array[i]);
        if ((i + 1) % 3 == 0) printf("\n");
        else printf("\t");
    }
    if (size > 15) {
        printf("... (ïîêàçàíî 15 èç %d ýëåìåíòîâ)\n", size);
    }
    else {
        printf("\n");
    }

}
