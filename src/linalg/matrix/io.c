#include <stdio.h>
#include "linalg/matrix.h"


void gel_matrix_stdout(const Matrix *m) {
    for (size_t i = 0; i < m->rows; i++) {
        for (size_t j = 0; j < m->cols; j++) {
            double val;
            gel_matrix_get(m, i, j, &val); 
            printf("%5.1f ", val);
        }
        printf("\n");
    }
}
