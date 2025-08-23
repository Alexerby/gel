#ifndef GEL_MATRIX_H
#define GEL_MATRIX_H

#include <stddef.h>

/**
 * @file matrix.h
 * @brief Matrix operations for the GEL library.
 *
 * Provides functions for creating, manipulating, and inspecting matrices,
 * including arithmetic, properties, I/O, and minor/determinant calculations.
 */

/**
 * @struct Matrix
 * @brief Represents a 2D matrix.
 *
 * The matrix data is stored in **row-major order**.
 */
typedef struct {
    size_t rows;    /**< Number of rows */
    size_t cols;    /**< Number of columns */
    double *data;   /**< Pointer to the matrix data */
} Matrix;

/** Macro to access a matrix element at (i, j) */
#define MAT_AT(m, i, j) ((m)->data[(i)*(m)->cols + (j)])


/* ===== Core functions (core.c) ===== */

/**
 * @brief Allocates a new matrix with the given dimensions.
 * @param rows Number of rows.
 * @param cols Number of columns.
 * @return Pointer to the newly allocated matrix, or NULL on failure.
 */
Matrix *gel_matrix_create(size_t rows, size_t cols);


/**
 * @brief Sets a value in the matrix.
 * @param m Pointer to the matrix.
 * @param row_index Row index (0-based).
 * @param col_index Column index (0-based).
 * @param val Value to set.
 * @return 0 on success, non-zero if indices are out of bounds.
 */
int gel_matrix_set(Matrix *m, size_t row_index, size_t col_index, double val);


/**
 * @brief Retrieves a value from the matrix.
 * @param m Pointer to the matrix.
 * @param row_index Row index (0-based).
 * @param col_index Column index (0-based).
 * @param out Pointer to a double to store the result.
 * @return 0 on success, non-zero if indices are out of bounds.
 */
int gel_matrix_get(const Matrix *m, size_t row_index, size_t col_index, double *out);


/**
 * @brief Frees a previously allocated matrix.
 * @param m Pointer to the matrix to free.
 */
void gel_matrix_free(Matrix *m);


/* ===== Algebra functions (algebra.c) ===== */

/**
 * @brief Adds two matrices.
 * @param a First matrix.
 * @param b Second matrix.
 * @return Newly allocated matrix with the sum, or NULL if dimensions mismatch.
 */
Matrix *gel_matrix_add(const Matrix *a, const Matrix *b);

/**
 * @brief Multiplies two matrices.
 * @param a Left-hand side matrix.
 * @param b Right-hand side matrix.
 * @return Newly allocated matrix with the product, or NULL if dimensions mismatch.
 */
Matrix *gel_matrix_mul(const Matrix *a, const Matrix *b);

/**
 * @brief Computes the transpose of a matrix.
 * @param a Input matrix.
 * @return Newly allocated transposed matrix.
 */
Matrix *gel_matrix_transpose(const Matrix *a);


/* ===== Property check functions (properties.c) ===== */

/**
 * @brief Checks if a matrix is square.
 * @param m Pointer to the matrix.
 * @return 1 if square, 0 otherwise.
 */
int gel_matrix_check_square(const Matrix *m);

/**
 * @brief Checks if a matrix is idempotent (A * A == A).
 * @param m Pointer to the matrix.
 * @return 1 if idempotent, 0 otherwise.
 */
int gel_matrix_check_idempotence(const Matrix *m);


/* ===== Inversion functions (inv.c) ===== */

/**
 * @brief Computes the determinant of a matrix.
 * @param m Pointer to the matrix.
 * @return Determinant value.
 */
double gel_matrix_det(const Matrix *m);

/**
 * @brief Computes the minor of a matrix at the specified row and column.
 * @param m Pointer to the matrix.
 * @param row Row index to remove.
 * @param col Column index to remove.
 * @return Minor matrix (by value).
 */
Matrix gel_matrix_minor(const Matrix *m, size_t row, size_t col);


/* ===== I/O functions (io.c) ===== */

/**
 * @brief Prints the matrix to stdout.
 * @param m Pointer to the matrix.
 */
void gel_matrix_stdout(const Matrix *m);

#endif // GEL_MATRIX_H
