#include <stdlib.h>
#include "linalg/matrix.h"


int gel_matrix_check_square(const Matrix *m) {
    int is_square;
    is_square = (m->rows == m->cols) ? 1 : 0;
    return is_square;
}


int gel_matrix_check_idempotence(const Matrix *m) {

    if (!m) return 0;

    // Only square matrices can be idempotent
    if (m->rows != m->cols) {
        return 0;
    }

    // Compute A * A
    Matrix *tmp = gel_matrix_mul(m, m);
    if (!tmp) {
        return 0;
    }

    // Compare A*A with A
    int is_idempotent = 1;  // assume true
    double eps = 1e-9;      // tolerance for floating-point comparison

    // Iterate over each row of the matrix
    for (size_t i = 0; i < m->rows && is_idempotent; i++) {

        // Iterate over each column of the matrix
        for (size_t j = 0; j < m->cols; j++) {

            // Compute the difference between (A*A)[i,j] and A[i,j]
            double diff = tmp->data[i * tmp->cols + j] - m->data[i * m->cols + j];

            // If the difference is larger than the tolerance, they are not equal
            if (diff < -eps || diff > eps) {

                // Mark as not idempotent
                is_idempotent = 0;

                // Break out of the inner loop early (no need to keep checking)
                break;
            }
        }
        // Outer loop will break because is_idempotent is false from inner loop
    }

    gel_matrix_free(tmp);
    return is_idempotent;
}
