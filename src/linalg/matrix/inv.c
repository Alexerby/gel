#include "linalg/matrix.h"
#include <stdlib.h>

Matrix gel_matrix_minor(const Matrix *m, size_t row, size_t col) {
    Matrix result;
    result.rows = m->rows - 1;
    result.cols = m->cols - 1;
    result.data = malloc(result.rows * result.cols * sizeof(double));

    if (!result.data) {
        result.rows = result.cols = 0;
        return result; // allocation failure -> "empty" matrix
    }

    size_t r = 0, c = 0;
    for (size_t i = 0; i < m->rows; i++) {
        if (i == row) continue;   // skip chosen row
        c = 0;
        for (size_t j = 0; j < m->cols; j++) {
            if (j == col) continue; // skip chosen column
            result.data[r * result.cols + c] = m->data[i * m->cols + j];
            c++;
        }
        r++;
    }

    return result;  // returns matrix with its own allocated block
}

