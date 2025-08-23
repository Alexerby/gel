#include <stdio.h>
#include "linalg/matrix.h"


void gel_matrix_stdout(const Matrix *m) {
    int width = 10; // width for printf() in loop
    int precision = 2;

    for (size_t i = 0; i < m->rows; i++) {
        for (size_t j = 0; j < m->cols; j++) {
            double val;
            gel_matrix_get(m, i, j, &val);
            printf("%*.*f ", width, precision, val);
        }
        printf("\n");
    }
}


Matrix *gel_matrix_copy(const Matrix *src) {
    if (!src) return NULL;

    Matrix *copy = gel_matrix_create(src->rows, src->cols);
    if (!copy) return NULL;

    for (size_t i = 0; i < src->rows; i++) {
        for (size_t j = 0; j < src->cols; j++) {
            double val;
            if (gel_matrix_get(src, i, j, &val) != 0) {
                gel_matrix_free(copy);
                return NULL;
            }
            gel_matrix_set(copy, i, j, val);
        }
    }

    return copy;
}
