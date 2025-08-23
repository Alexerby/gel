#include <stdio.h>
#include <assert.h>
#include "linalg/matrix.h"

int main(void) {
    Matrix *m = gel_matrix_create(10, 10);
    if (!m) {
        fprintf(stderr, "Failed to create matrix\n");
        return 1;
    }

    // Fill matrix with known values
    for (size_t i = 0; i < m->rows; i++) {
        for (size_t j = 0; j < m->cols; j++) {
            gel_matrix_set(m, i, j, (double)(i * m->cols + j));
        }
    }

    printf("Matrix filled. Verifying values...\n");

    // Verify values using gel_matrix_get and print a small visual check
    for (size_t i = 0; i < m->rows; i++) {
        printf("Row %zu: ", i);
        for (size_t j = 0; j < m->cols; j++) {
            double val;
            int rc = gel_matrix_get(m, i, j, &val);
            if (rc != 0) {
                fprintf(stderr, "\nFailed to get value at (%zu,%zu)\n", i, j);
                gel_matrix_free(m);
                return 1;
            }

            // Assert correctness
            assert(val == (double)(i * m->cols + j));

            // Print a few sample values for visual verification
            if (j < 5 || j == m->cols - 1) {
                printf("%.1f ", val);
                if (j == 4 && m->cols > 6) printf("... "); // indicate skipped columns
            }
        }
        printf("\n");
    }

    printf("\nAll matrix values verified successfully.\n");

    gel_matrix_free(m);
    return 0;
}
