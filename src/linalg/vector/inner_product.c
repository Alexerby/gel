#include <stdio.h>
#include "linalg/vector.h"


double vector_dot(const Vector *v1, const Vector *v2) {
    printf("%zu\n", v1->size);
    printf("%zu\n", v2->size);
    if (v1->size != v2->size) {
        fprintf(stderr, "Error: Vectors must be of same size for dot product\n");
        return 0.0;
    }
    double sum = 0.0;
    for (size_t i = 0; i < v1->size; i++) {
        sum += v1->data[i] * v2->data[i];
    }
    return sum;
}
