#include <stdlib.h>
#include "linalg/matrix.h"


Matrix *gel_matrix_add(const Matrix *a, const Matrix *b) {
    if (!a || !b) return NULL;
    if (a->rows != b->rows || a->cols != b->cols) return NULL;

    Matrix *c = gel_matrix_create(a->rows, a->cols);
    if (!c) return NULL;

    for (size_t i = 0; i < a->rows; i++) {
        for (size_t j = 0; j < a->cols; j++) {
            double aVal = a->data[i * a->cols + j];
            double bVal = b->data[i * b->cols + j];
            c->data[i * c->cols + j] = aVal + bVal;
        }
    }

    return c;
}


Matrix *gel_matrix_mul(const Matrix *a, const Matrix *b) {
    if (!a || !b) {
        return NULL;
    }

    // Check dimension compatibility: a.cols must equal b.rows
    if (a->cols != b->rows) {
        return NULL;
    }

    // Create result matrix with shape (a.rows x b.cols)
    Matrix *c = gel_matrix_create(a->rows, b->cols);
    if (!c) return NULL;

    // Standard matrix multiplication:
    for (size_t i = 0; i < a->rows; i++) {              // iterate over rows of A
        for (size_t j = 0; j < b->cols; j++) {          // iterate over columns of B
            double sum = 0.0;
            for (size_t k = 0; k < a->cols; k++) {      // iterate over shared dimension (this loop is the dot product)
                double aVal = a->data[i * a->cols + k]; // element from row i of A
                double bVal = b->data[k * b->cols + j]; // element from column j of B
                sum += aVal * bVal;
            }
            c->data[i * c->cols + j] = sum;             // store result in C(i,j)
        }
    }

    return c;
}


Matrix *gel_matrix_transpose(const Matrix *a) {

    Matrix *t = gel_matrix_create(a->cols, a->rows); 

    if (!t) return NULL;

    for (size_t i = 0; i < a->rows; i++) {
        for (size_t j = 0; j < a->cols; j++) {
            t->data[j * t->cols + i] = a->data[i * a->cols + j];
        }
    }

    return t;
}



