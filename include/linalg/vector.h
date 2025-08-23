#ifndef GEL_VECTOR_H
#define GEL_VECTOR_H

#include <stddef.h>

/**
 * @file vector.h
 * @brief Vector operations for the GEL library.
 *
 * Provides functions for creating, manipulating, and inspecting vectors,
 * including element access, memory management, I/O, and basic statistics.
 */

/**
 * @struct Vector
 * @brief Represents a 1D numerical vector.
 *
 * A vector is a one-dimensional array of doubles.
 * The size field stores the number of elements, and the data pointer
 * refers to the dynamically allocated memory holding the values.
 */
typedef struct {
    size_t size;    /**< Number of elements in the vector */
    double *data;   /**< Pointer to the vector data */
} Vector;

/** @defgroup vector_core Core functions
 *  Functions for creating, freeing, and accessing vector elements.
 *  @{
 */

/**
 * @brief Create a new vector.
 *
 * Allocates memory for a vector of the given size. Elements are initialized
 * to zero.
 *
 * @param size Number of elements in the vector.
 * @return Pointer to the newly allocated vector, or NULL if allocation fails.
 */
Vector *gel_vector_create(size_t size);

/**
 * @brief Free a vector.
 *
 * Releases the memory associated with the vector and its data.
 *
 * @param v Pointer to the vector to free. Safe to call with NULL.
 */
void gel_vector_free(Vector *v);

/**
 * @brief Set the value of an element in a vector.
 *
 * @param v Pointer to the vector.
 * @param i Index of the element to set (0-based).
 * @param val Value to assign to the element.
 * @return 0 on success, non-zero if index is out of bounds.
 */
int gel_vector_set(Vector *v, size_t i, double val);

/**
 * @brief Get the value of an element in a vector.
 *
 * @param v Pointer to the vector.
 * @param i Index of the element to get (0-based).
 * @param out Pointer to a double where the value will be stored.
 * @return 0 on success, non-zero if index is out of bounds.
 */
int gel_vector_get(const Vector *v, size_t i, double *out);

/**
 * @brief Print a vector to stdout.
 *
 * Prints the elements of the vector in a single row, separated by spaces.
 *
 * @param v Pointer to the vector.
 */
void gel_vector_stdout(const Vector *v);

/** @} */ // end of vector_core


/** @defgroup vector_stats Statistics functions
 *  Functions for computing statistical properties of vectors.
 *  @{
 */

/**
 * @brief Compute the mean of a vector.
 *
 * @param v Pointer to the vector.
 * @return Mean value of the vector, or NaN if the vector is empty.
 */
double gel_vector_mean(const Vector *v);

/**
 * @brief Compute the variance of a vector.
 *
 * Variance is defined as:
 * \f[
 *   \mathrm{Var}(x) = \frac{1}{N - \mathrm{ddof}} \sum_{i=1}^{N} (x_i - \bar{x})^2
 * \f]
 *
 * @param v Pointer to the vector.
 * @param ddof Delta degrees of freedom (0 for population variance, 1 for sample variance).
 * @return Variance of the vector, or NaN if size is 0 or invalid ddof.
 */
double gel_vector_variance(const Vector *v, int ddof);

/**
 * @brief Compute the standard deviation of a vector.
 *
 * Standard deviation is the square root of the variance.
 *
 * @param v Pointer to the vector.
 * @return Standard deviation of the vector, or NaN if size is 0.
 */
double gel_vector_stddev(const Vector *v);

/** @} */ // end of vector_stats

#endif // GEL_VECTOR_H
