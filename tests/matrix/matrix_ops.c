#include <stdio.h>
#include <assert.h>
#include "linalg/matrix.h"

int main(void) {
    Matrix *a = gel_matrix_create(10, 10);
    if (!a) {
        fprintf(stderr, "Failed to create matrix\n");
        return 1;
    }

    // Fill matrix with values
    for (size_t i = 0; i < a->rows; i++) {
        for (size_t j = 0; j < a->cols; j++) {
            gel_matrix_set(a, i, j, (double)(i * a->cols + j));
        }
    }

    // Multiply matrix by itself
    Matrix *b = gel_matrix_mul(a, a);
    if (!b) {
        fprintf(stderr, "Matrix multiplication failed\n");
        gel_matrix_free(a);
        return 1;
    }

    printf("\nOriginal matrix:\n");
    gel_matrix_stdout(a);
    printf("\nPost multiplication:\n");
    gel_matrix_stdout(b);

    // Verify multiplication result
    for (size_t i = 0; i < b->rows; i++) {
        for (size_t j = 0; j < b->cols; j++) {
            double expected = 0.0;

            for (size_t k = 0; k < a->cols; k++) {
                double aval, bval;
                gel_matrix_get(a, i, k, &aval);
                gel_matrix_get(a, k, j, &bval);
                expected += aval * bval;
            }

            double actual;
            gel_matrix_get(b, i, j, &actual);
            assert(actual == expected);  // test fails if mismatch
        }
    }

    printf("\nMatrix multiplication verified successfully!\n");

    gel_matrix_free(a);
    gel_matrix_free(b);
    return 0;
}
