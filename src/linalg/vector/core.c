#include "linalg/vector.h"
#include <stdlib.h>
#include <stdio.h>

/** @copydoc gel_vector_create */
Vector *gel_vector_create(size_t size) {
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

/** @copydoc gel_vector_free */
void gel_vector_free(Vector *v) {
    if (v) {
        free(v->data);
        v->data = NULL;
        v->size = 0;
        free(v);
    }
}

/** @copydoc gel_vector_get */
int gel_vector_get(const Vector *v, size_t i, double *out) {
    if (!v || !out || i >= v->size) return -1;
    *out = v->data[i];
    return 0;
}

/** @copydoc gel_vector_set */
int gel_vector_set(Vector *v, size_t i, double val) {
    if (!v || i >= v->size) return -1;
    v->data[i] = val;
    return 0;
}

/** @copydoc gel_vector_stdout */
void gel_vector_stdout(const Vector *v) {
    if (!v) return;

    for (size_t i = 0; i < v->size; i++) {
        printf("%8.3f ", v->data[i]);
    }
    printf("\n");
}
