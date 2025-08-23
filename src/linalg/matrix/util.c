#include <stdlib.h>
#include <string.h>
#include "linalg/matrix.h"

Matrix *gel_matrix_clone(const Matrix *m) {

    if (!m) return NULL;

    Matrix *copy = malloc(sizeof(Matrix));
    if (!copy) return NULL; // really necessary?
    
    copy->rows = m->rows;
    copy->cols = m->cols;
    copy->data = malloc(m->rows * m->cols * sizeof(double));

    if (!copy->data) {
        free(copy);
        return NULL;
    }

    memcpy(copy->data, m->data, m->rows * m->cols * sizeof(double));
    return copy;

}

