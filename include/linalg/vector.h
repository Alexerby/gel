#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    int size;
    double *data;
} Vector;

// Create a vector of given size
Vector *vector_create(int size);

// Free vector memory
void vector_free(Vector *v);

// Set i-th element of vector
void vector_set(Vector *v, int i, double val);

// Get i-th element of vector
double vector_get(const Vector *v, int i);

#endif // VECTOR_H
