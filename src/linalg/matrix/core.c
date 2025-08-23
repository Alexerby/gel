#include "linalg/matrix.h"
#include <stdlib.h>
#include <stdio.h>

// Create a new matrix
Matrix *gel_matrix_create(size_t rows, size_t cols) {
    Matrix *m = malloc(sizeof(Matrix));
    if (!m) return NULL;

    m->rows = rows;
    m->cols = cols;
    m->data = malloc(sizeof(double) * rows * cols);

    if (!m->data) {
        free(m);
        return NULL;
    }

    return m;
}

// Free a matrix's memory
void gel_matrix_free(Matrix *m) {
    if (m && m->data) {
        free(m->data);
        m->data = NULL;
        m->rows = m->cols = 0;
    }
}

// Get a value from the matrix
int gel_matrix_get(const Matrix *m, size_t row_index, size_t col_index, double *out) {
    if (!m || !out || row_index >= m->rows || col_index >= m->cols) {
        return -1; // invalid indices
    }
    *out = MAT_AT(m, row_index, col_index);
    return 0;
}

// Set a value in the matrix
int gel_matrix_set(Matrix *m, size_t row_index, size_t col_index, double val) {
    if (!m || row_index >= m->rows || col_index >= m->cols) {
        return -1; // invalid indices
    }
    MAT_AT(m, row_index, col_index) = val;
    return 0;
}

// Print the matrix to stdout
void gel_matrix_stdout(const Matrix *m) {
    if (!m) return;

    for (size_t i = 0; i < m->rows; i++) {
        for (size_t j = 0; j < m->cols; j++) {
            printf("%8.3f ", MAT_AT(m, i, j));  // use macro
        }
        printf("\n");
    }
}
