#include <stdlib.h>
#include "linalg/vector.h"

Vector *vector_create(int size) {
    Vector *v = malloc(sizeof(Vector));
    if (!v) return NULL;
    v->size = size;
    v->data = malloc(sizeof(double) * size);
    if (!v->data) {
        free(v);
        return NULL;
    }
    return v;
}

void vector_free(Vector *v) {
    if (v) {
        free(v->data);
        free(v);
    }
}

/**
 * @brief Sets the value at the specified index in the vector.
 * 
 * @param v Pointer to the Vector instance.
 * @param i Index of the element to set (must be between 0 and v->size - 1).
 * @param val The value to assign at the specified index.
 */
void vector_set(Vector *v, int i, double val) {
    if (i >= 0 && i < v->size) {
        v->data[i] = val;
    }
}


/**
 * @brief Gets the value at the specified index in the vector.
 * 
 * @param v Pointer to the constant Vector instance.
 * @param i Index of the element to retrieve (must be between 0 and v->size - 1).
 * @return The value at the specified index, or 0.0 if the index is out of bounds.
 */
double vector_get(const Vector *v, int i) {
    if (i >= 0 && i < v->size) {
        return v->data[i];
    }
    return 0.0; // or handle error
}
