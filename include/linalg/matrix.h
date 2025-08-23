#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>


typedef struct {
    size_t rows;
    size_t cols;
    double *data;
} Matrix;

#define MAT_AT(m, i, j) ((m)->data[(i)*(m)->cols + (j)])

/* core.c */
Matrix *gel_matrix_create(size_t rows, size_t cols);
void gel_matrix_free(Matrix *m);
int gel_matrix_get(const Matrix *m, size_t row_index, size_t col_index, double *out);
int gel_matrix_set(Matrix *m, size_t row_index, size_t col_index, double val);


/* algebra.c */
Matrix *gel_matrix_add(const Matrix *a, const Matrix *b);
Matrix *gel_matrix_mul(const Matrix *a, const Matrix *b);
Matrix *gel_matrix_transpose(const Matrix *a);


/* properties.c */
int gel_matrix_check_square(const Matrix *m);
int gel_matrix_check_idempotence(const Matrix *m);


/* inv.c */
double gel_matrix_det(const Matrix *m);
Matrix gel_matrix_minor(const Matrix *m, size_t row, size_t col);


/* io.c */
void gel_matrix_stdout(const Matrix *m);

#endif // MATRIX_H
