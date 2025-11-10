#include <stdio.h>
#include <assert.h>
#include "linalg/matrix.h"

int main(void) {
    Matrix *m = gel_matrix_create(5, 5);
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

    printf("Original matrix:\n");
    gel_matrix_stdout(m);

    int a = gel_matrix_trace(m);
    printf("The trace %d.\n", a);


    Matrix *identity_matrix = gel_matrix_identity(5);

    printf("Identity matrix example:\n");
    gel_matrix_stdout(identity_matrix);

    gel_matrix_free(m);
    gel_matrix_free(identity_matrix);
    return 0;
}
