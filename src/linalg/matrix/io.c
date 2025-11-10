#include <stdio.h>
#include <string.h>
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
    if (!src || !src->data) return NULL;

    Matrix *copy = gel_matrix_create(src->rows, src->cols);
    if (!copy) return NULL;

    memcpy(copy->data, src->data, sizeof(double) * src->rows * src->cols);
    return copy;
}
