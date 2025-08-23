#ifndef GEL_VECTOR_H
#define GEL_VECTOR_H

#include <stddef.h>

/**
 * @file vector.h
 * @brief Vector operations for the GEL library.
 *
 * Provides functions for creating, manipulating, and inspecting vectors,
 * including element access, memory management, and basic statistics.
 */

/**
 * @struct Vector
 * @brief Represents a 1D numerical vector.
 */
typedef struct {
    size_t size;    /**< Number of elements in the vector */
    double *data;   /**< Pointer to the vector data */
} Vector;


/* ===== Core functions (core.c) ===== */

/**
 * @brief Allocates a new vector of the given size.
 * @param size Number of elements.
 * @return Pointer to the newly allocated vector, or NULL on failure.
 */
Vector *gel_vector_create(size_t size);

/**
 * @brief Frees a previously allocated vector.
 * @param v Pointer to the vector to free.
 */
void gel_vector_free(Vector *v);

/**
 * @brief Sets a value in the vector.
 * @param v Pointer to the vector.
 * @param i Index (0-based).
 * @param val Value to set.
 * @return 0 on success, non-zero if index is out of bounds.
 */
int gel_vector_set(Vector *v, size_t i, double val);

/**
 * @brief Retrieves a value from the vector.
 * @param v Pointer to the vector.
 * @param i Index (0-based).
 * @param out Pointer to a double to store the result.
 * @return 0 on success, non-zero if index is out of bounds.
 */
int gel_vector_get(const Vector *v, size_t i, double *out);


/* ===== I/O functions (io.c) ===== */

/**
 * @brief Prints the vector to stdout.
 * @param v Pointer to the vector.
 */
void gel_vector_stdout(const Vector *v);


/* ===== Statistics functions (stats.c) ===== */

/**
 * @brief Computes the mean of the vector elements.
 * @param v Pointer to the vector.
 * @return Mean value, or NAN if the vector is empty.
 */
double gel_vector_mean(const Vector *v);

/**
 * @brief Computes the variance of the vector elements.
 * @param v Pointer to the vector.
 * @return Variance, or NAN if the vector is empty.
 */
double gel_vector_variance(const Vector *v);

/**
 * @brief Computes the standard deviation of the vector elements.
 * @param v Pointer to the vector.
 * @return Standard deviation, or NAN if the vector is empty.
 */
double gel_vector_stddev(const Vector *v);

#endif // GEL_VECTOR_H
