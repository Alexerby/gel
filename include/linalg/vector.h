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
 */
typedef struct {
    size_t size;    /**< Number of elements in the vector */
    double *data;   /**< Pointer to the vector data */
} Vector;

/* ===== Core functions ===== */
Vector *gel_vector_create(size_t size);
void gel_vector_free(Vector *v);
int gel_vector_set(Vector *v, size_t i, double val);
int gel_vector_get(const Vector *v, size_t i, double *out);
void gel_vector_stdout(const Vector *v);

/* ===== Statistics functions ===== */
double gel_vector_mean(const Vector *v);
double gel_vector_variance(const Vector *v, int ddof);
double gel_vector_stddev(const Vector *v);

#endif // GEL_VECTOR_H
