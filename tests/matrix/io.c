#include <stdio.h>
#include <assert.h>
#include "linalg/matrix.h"

int main(void) {
    // Create and fill original matrix
    size_t rows = 5, cols = 5;
    Matrix *m = gel_matrix_create(rows, cols);
    if (!m) {
        fprintf(stderr, "Failed to create matrix\n");
        return 1;
    }

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            gel_matrix_set(m, i, j, (double)(i * cols + j));
        }
    }

    // Print original matrix
    printf("Original matrix:\n");
    gel_matrix_stdout(m);

    // Copy the matrix
    Matrix *copy = gel_matrix_copy(m);
    if (!copy) {
        fprintf(stderr, "Failed to copy matrix\n");
        gel_matrix_free(m);
        return 1;
    }

    // Print copied matrix
    printf("\nCopied matrix:\n");
    gel_matrix_stdout(copy);

    // Verify that copy matches original
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            double orig_val, copy_val;
            int rc1 = gel_matrix_get(m, i, j, &orig_val);
            int rc2 = gel_matrix_get(copy, i, j, &copy_val);
            assert(rc1 == 0 && rc2 == 0);
            assert(orig_val == copy_val);
        }
    }

    printf("\nMatrix copy verified successfully!\n");

    // Free memory
    gel_matrix_free(m);
    gel_matrix_free(copy);

    return 0;
}
