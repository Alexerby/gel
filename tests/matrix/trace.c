#include <stdio.h>
#include <assert.h>
#include "linalg/matrix.h"
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


    int a = gel_matrix_trace(m);
    printf("%d\n", a);

    gel_matrix_free(m);
    return 0;
}
